*Este proyecto ha sido creado como parte del currículo de 42 por raqcabre, ldiaz-de.*

# push_swap

## Descripción

`push_swap` es un proyecto de algoritmia clásico de 42: ordenar una lista de
números enteros usando únicamente dos stacks (`a` y `b`) y un conjunto muy
limitado de operaciones (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`,
`rra`, `rrb`, `rrr`), minimizando en la medida de lo posible el número de
operaciones necesarias.

El objetivo real del proyecto no es "ordenar" —eso es fácil—, sino entender
la complejidad algorítmica de forma tangible: comparar cómo escalan
distintas estrategias de ordenación cuando el único recurso disponible son
movimientos de pila, y elegir la más adecuada según lo desordenados que
estén los datos de entrada.

El programa implementa **cuatro estrategias** de ordenación distintas,
seleccionables por línea de comandos:

| Estrategia | Flag | Complejidad objetivo | Técnica |
|---|---|---|---|
| Simple | `--simple` | O(n²) | Insertion sort adaptado a dos stacks |
| Intermedia | `--medium` | O(n·√n) | Ordenación por chunks (bloques de tamaño ≈√n) |
| Compleja | `--complex` | O(n log n) | Radix sort (LSD) sobre dos stacks |
| Adaptativa | `--adaptive` (por defecto) | Varía según el desorden | Selecciona una de las tres anteriores en función del índice de desorden |

Además incluye un **modo benchmark** (`--bench`) que, tras ordenar, muestra
por `stderr` el índice de desorden, la estrategia usada, el total de
operaciones y el desglose por tipo de operación.

## Instrucciones

### Compilación

```sh
make        # compila el binario push_swap
make clean  # borra los .o
make fclean # borra los .o y el binario
make re     # fclean + all
```

El `Makefile` usa `cc` con `-Wall -Wextra -Werror` y no hace relink.

### Ejecución

```sh
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <lista de enteros>
```

- Sin argumentos, el programa no imprime nada y termina sin error.
- Si no se indica ninguna estrategia, se usa `--adaptive` por defecto.
- Cada operación generada se imprime por `stdout` en una línea, separada por
  `\n`.
- Ante cualquier entrada inválida (argumentos no numéricos, fuera de rango
  de `int`, números duplicados...), el programa imprime `Error` por
  `stderr` y termina.

Ejemplos:

```sh
$> ./push_swap 2 1 3 6 5 8
ra
pb
rra
...

$> ./push_swap --simple 5 4 3 2 1
rra
pb
...

$> ./push_swap --bench --adaptive 4 67 3 87 23 2> bench.txt
pa
pb
...
$> cat bench.txt
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n*sqrt(n))
[bench] total_ops: 13
[bench] sa: 0 sb: 0 ss: 0 pa: 5 pb: 5
[bench] ra: 2 rb: 1 rr: 0 rra: 0 rrb: 0 rrr: 0
```

## Índice de desorden

El índice de desorden es un valor entre `0` (lista ya ordenada) y `1`
(orden inverso total, el peor caso posible). Se calcula contando, sobre
todos los pares posibles de elementos de `a`, cuántos aparecen en el orden
incorrecto (un valor mayor antes que uno menor), y dividiendo entre el
número total de pares:

```
desorden = nº de pares invertidos / (n·(n-1)/2)
```

Se calcula **antes** de ejecutar ningún movimiento, sobre el stack `a` tal
y como se recibe por argumentos.

### Umbrales elegidos para el modo adaptativo

| Rango de desorden | Estrategia elegida | Complejidad |
|---|---|---|
| `< 0.2` | Insertion sort | O(n) |
| `0.2 ≤ desorden < 0.5` | Ordenación por chunks | O(n·√n) |
| `≥ 0.5` | Radix sort | O(n log n) |

**Justificación:**

- Con desorden bajo (`< 0.2`) el stack ya está casi ordenado: la mayoría de
  los elementos solo necesitan un pequeño ajuste local. El coste de un
  insertion sort en este régimen es casi lineal, porque cada elemento se
  inserta con muy pocos movimientos de rotación.
- Con desorden medio (`0.2`–`0.5`) el insertion sort deja de ser rentable
  (demasiadas inversiones que buscar una a una), pero tampoco hace falta la
  maquinaria de radix sort. Dividir el stack en bloques de tamaño ≈√n y
  procesarlos por rangos de valor da un compromiso O(n·√n) que se adapta
  bien a un desorden parcial.
- Con desorden alto (`≥ 0.5`, entrada cercana al desorden total o inversa)
  el radix sort por bits es la opción más estable: su coste no depende de
  lo desordenada que esté la entrada, siempre recorre `log2(n)` pasadas
  completas sobre el stack, así que garantiza O(n log n) incluso en el peor
  caso.

Estos umbrales (0.2 y 0.5) se fijaron de forma empírica, comprobando con el
modo `--bench` en qué punto el número de operaciones de cada estrategia
empieza a superar al de la siguiente, para distintos tamaños de entrada
generados aleatoriamente.

## Estrategias implementadas

### Simple — Insertion sort adaptado a dos stacks — O(n²)

Se asigna a cada valor de `a` un índice relativo (0..n-1) para trabajar solo
con posiciones. Se pasan todos los elementos a `b`, se ordenan los tres
primeros con un caso especial (`sort_three`), y después se van insertando
uno a uno de vuelta en `a`: en cada iteración se busca en `b` el elemento
cuyo coste de inserción (moverlo hasta la cima de `b` y rotar `a` hasta su
posición correcta, aprovechando siempre el sentido de rotación más barato)
sea el menor, y se hace `pa`. Con `n` elementos y una búsqueda lineal del
más barato en cada uno de los `n` pasos, el coste es O(n²) operaciones.

### Intermedia — Ordenación por chunks — O(n·√n)

El stack se divide conceptualmente en bloques (chunks) de tamaño
`≈ (√n · 11) / 5` según el rango de índices. Se procesan chunk a chunk:
dentro de cada uno se busca repetidamente, con rotación más barata, el
elemento con menor coste de rotación que pertenezca al rango del chunk
actual, se envía a `b` y se rota `b` si su valor pertenece a la mitad alta
del chunk (para mantener cierto orden relativo dentro de `b`). Al terminar
todos los chunks, se devuelven los elementos de `b` a `a` de mayor a menor.
Con `√n` chunks de tamaño `√n`, cada uno procesado en O(√n) por elemento,
el coste total es O(n·√n).

### Compleja — Radix sort (LSD) sobre dos stacks — O(n log n)

Cada valor se sustituye por su índice relativo en el rango `[0, n-1]`
(`assign_indexes`), de forma que ordenar los valores equivale a ordenar sus
índices como enteros positivos de `log2(n)` bits. Para cada bit, de menos a
más significativo, se recorre `a` entero: si el bit vale 0 el elemento se
envía a `b` (`pb`); si vale 1, se rota `a` (`ra`) para dejarlo al final de
la pasada. Al terminar la pasada, se devuelve todo `b` a `a`. Tras procesar
los `log2(n)` bits, `a` queda ordenado. El número de pasadas es
`O(log n)` y cada una recorre los `n` elementos una vez, de ahí O(n log n).

### Adaptativa — selección según el índice de desorden — O(n) / O(n·√n) / O(n log n)

No es un algoritmo nuevo, sino un **selector**: calcula el índice de
desorden de la entrada y delega en una de las tres estrategias anteriores
según los umbrales descritos arriba, garantizando el régimen de
complejidad exigido en cada caso sin necesidad de que quien use el programa
tenga que elegir manualmente.

### Casos pequeños (n ≤ 5)

Para tamaños muy pequeños (2 a 5 elementos) se usan rutinas dedicadas
(`sort_two`, `sort_three`, `sort_four`, `sort_five`) con secuencias de
movimientos fijas y óptimas, independientes de la estrategia seleccionada,
ya que para esos tamaños los algoritmos generales no aportan ninguna
ventaja y generan más operaciones de las necesarias.

## Manejo de errores

El programa considera entrada inválida, entre otros casos: argumentos que
no son números enteros, argumentos fuera del rango de `int`, y valores
duplicados. En cualquiera de estos casos se imprime `Error` seguido de un
salto de línea por `stderr` y el programa termina sin ordenar nada.

## Recursos

- [The Norm (Norminette) — 42](https://github.com/42School/norminette)
- Donald Knuth, *The Art of Computer Programming, Vol. 3: Sorting and
  Searching* — referencia clásica sobre algoritmos de ordenación y su
  complejidad.
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/) — referencia rápida
  sobre clases de complejidad.
- Documentación sobre *radix sort* y *LSD radix sort* para la adaptación a
  dos stacks.
- Documentación sobre *insertion sort* y estrategias de coste mínimo de
  inserción en listas doblemente enlazadas.

### Uso de IA

Se ha utilizado una herramienta de IA (asistente de programación) como
apoyo puntual durante el desarrollo, principalmente para:

- Revisar y depurar errores de compilación y de comportamiento indefinido.
- Discutir y comparar alternativas de diseño para las estrategias de
  ordenación (por ejemplo, el tamaño de chunk óptimo o el criterio de coste
  de inserción) antes de implementarlas.
- Ayudar a redactar y estructurar esta documentación (README).

Todo el código generado con ayuda de IA ha sido revisado, entendido y
probado por ambas personas del grupo antes de integrarlo, y ambas son
capaces de explicar su funcionamiento durante la evaluación.

## Autoría

| Login | Contribución principal |
|---|---|
| `raqcabre` | Parseo de argumentos y errores, estructuras de datos (nodos/stacks), operaciones básicas (`sa`/`sb`/`ss`/`pa`/`pb`/`ra`/`rb`/`rr`/`rra`/`rrb`/`rrr`), casos pequeños (n ≤ 5), algoritmo intermedio (ordenación por chunks) |
| `ldiaz-de` | Cálculo del índice de desorden, algoritmo simple (insertion sort), algoritmo complejo (radix sort), algoritmo adaptativo, modo benchmark |

Ambas personas han revisado el trabajo de la otra y son capaces de explicar
cualquier parte del código durante la evaluación.
