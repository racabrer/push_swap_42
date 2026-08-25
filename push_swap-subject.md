# Push_swap

> Porque Swap_push no suena tan natural

**Resumen:** En este proyecto se deberan ordenar datos en un stack, con un conjunto limitado de instrucciones y utilizando el menor numero posible de acciones. Para conseguirlo, se deben utilizar varios algoritmos y elegir la solucion mas apropiada (de entre muchas posibles) para conseguir ordenar los datos de la forma mas optimizada.

**Este es un proyecto en grupo y debe ser realizado por dos personas.**

*Version: 1.0*

---

## I. Prologo

Big-O es la notacion que nos ayuda a hablar de como escalan los algoritmos. Una estrategia brillante de O(n log n) siempre sobrevivira a una O(n^2) cuando el tamano de la entrada crece.

**Ordena con cabeza, no con fuerza bruta.**

---

## II. Instrucciones generales

- El proyecto debera estar escrito en **C**.
- El proyecto debe estar escrito siguiendo la **Norma**. Si tienes archivos o funciones adicionales, estas deberan ser incluidas en la verificacion de la Norma y tendras un 0 si hay algun error de norma en cualquiera de ellos.
- Las funciones no deben terminar de forma inesperada (segfault, bus error, double free, etc), excepto en el caso de comportamientos indefinidos. Si esto sucede, el proyecto sera considerado no funcional y recibiras un 0 durante la evaluacion.
- Toda la memoria asignada en la pila (heap) debera liberarse adecuadamente cuando sea necesario. No se permitiran leaks de memoria.
- Si el enunciado lo requiere, se debera entregar un **Makefile** que compilara tus archivos fuente a la salida requerida con las flags `-Wall`, `-Werror` y `-Wextra`. Tambien se debera utilizar `cc` y, por supuesto, el Makefile no debe hacer relink.
- El **Makefile** entregado debe contener al menos las normas `$(NAME)`, `all`, `clean`, `fclean` y `re`.
- Para entregar los bonus del proyecto se debera incluir una regla **bonus** en el Makefile, en la que se anadiran todos los headers, librerias o funciones que esten prohibidas en la parte principal del proyecto. Los bonus deben estar en archivos distintos `*_bonus.{c/h}`. La parte obligatoria y los bonus se evaluan por separado.
- Si el proyecto permite el uso de la **libft**, se debera copiar su fuente y sus Makefile asociados en un directorio `libft` con su correspondiente Makefile. El Makefile del proyecto debe compilar primero la libreria utilizando su Makefile, y despues compilar el proyecto.
- Es recomendable crear programas de prueba para el proyecto, aunque este trabajo **no sera entregado ni evaluado**.
- Entrega el trabajo en el repositorio Git asignado. Solo el trabajo de tu repositorio Git sera evaluado.

---

## III. Instrucciones sobre la IA

### Contexto

Durante tu proceso de aprendizaje, la IA puede ayudarte con muchas tareas diferentes. Sin embargo, siempre debes abordarlas con precaucion y evaluar de forma critica los resultados.

### Mensaje principal:

- Utiliza la IA para reducir las tareas repetitivas o tediosas.
- Desarrolla habilidades de prompting.
- Aprende como funcionan los sistemas de IA para anticipar de forma eficiente y evitar los riesgos comunes, sesgos y problemas eticos.
- Sigue trabajando con tus companeros para desarrollar tanto habilidades tecnicas como transversales.
- Utiliza unicamente contenido generado por IA que entiendas completamente y del cual puedas responsabilizarte.

### Reglas para estudiantes:

- Debes tomarte el tiempo necesario para explorar las herramientas de IA y comprender como funcionan.
- Debes reflexionar sobre tu problema antes de dar instrucciones a la IA.
- Debes desarrollar el habito de revisar, cuestionar y probar sistematicamente cualquier contenido generado por la IA.
- Debes buscar siempre la revision de otras personas.

---

## IV. Introduccion

El proyecto **Push_Swap** es un proyecto simple, pero con un reto algoritmico muy concreto: tienes que ordenar datos.

Para esto, tendras a tu disposicion una lista de valores enteros, 2 stacks y un conjunto de instrucciones que usaras para manipular ambos stacks.

Tu objetivo en este proyecto es escribir un programa llamado `push_swap` que calcule y muestre por pantalla la secuencia de instrucciones mas corta que necesitarias para ordenar la lista de enteros recibida.

---

## V. Objetivos

**El objetivo de este proyecto** es que descubras la complejidad algoritmica de una manera muy concreta.

Ordenar numeros es facil; ordenarlos *rapido* usando solo dos stacks y con un punado de movimientos permitidos es otra historia.

---

## VI. Parte obligatoria

### VI.1. Requisitos de proyectos en grupo

- Este proyecto debe ser completado por dos estudiantes trabajando de manera conjunta.
- Ambos estudiantes deben contribuir significativamente al proyecto y entender correctamente todos los algoritmos implementados.
- El repositorio de entrega debe indicar claramente en el archivo README.md las contribuciones de cada estudiante.
- Durante la evaluacion, ambos estudiantes deben ser capaces de explicar cualquier parte del codigo.
- El proyecto entregado debe incluir los "logins" de ambas personas estudiantes en el repositorio.

### VI.2. Las reglas

- Teneis 2 **stacks**, llamados `a` y `b`.
- Para empezar:
  - El stack `a` contiene una cantidad aleatoria de numeros positivos y/o negativos.
  - El stack `b` esta vacio.
- El objetivo es ordenar los numeros del stack `a` en orden ascendente. Para hacerlo estan disponibles las siguientes operaciones:

| Operacion | Descripcion |
|-----------|-------------|
| `sa` | (swap a): Intercambia los dos primeros elementos del stack a. No hace nada si hay solo uno o ningun elemento. |
| `sb` | (swap b): Intercambia los dos primeros elementos del stack b. No hace nada si hay solo uno o ningun elemento. |
| `ss` | `sa` y `sb` a la vez. |
| `pa` | (push a): Toma el primer elemento del stack b y lo coloca el primero en el stack a. No hace nada si b esta vacio. |
| `pb` | (push b): Toma el primer elemento del stack a y lo coloca el primero en el stack b. No hace nada si a esta vacio. |
| `ra` | (rotate a): Desplaza hacia arriba todos los elementos del stack a una posicion, convirtiendo el primer elemento en el ultimo. |
| `rb` | (rotate b): Desplaza hacia arriba todos los elementos del stack b una posicion, convirtiendo el primer elemento en el ultimo. |
| `rr` | `ra` y `rb` a la vez. |
| `rra` | (reverse rotate a): Desplaza hacia abajo todos los elementos del stack a una posicion, convirtiendo el ultimo elemento en el primero. |
| `rrb` | (reverse rotate b): Desplaza hacia abajo todos los elementos del stack b una posicion, convirtiendo el ultimo elemento en el primero. |
| `rrr` | `rra` y `rrb` a la vez. |

### VI.3. Requisitos del algoritmo

Se deben implementar **cuatro estrategias de ordenacion distintas** e integrarlas todas en el programa `push_swap`. El programa debe ser capaz de seleccionar una estrategia u otra durante la ejecucion, en funcion de la configuracion de entrada.

#### VI.3.1. Modelo de complejidad y restricciones

Todas las estrategias deben ser implementadas en C y deben generar secuencias de operaciones de Push_swap para ordenar los elementos. Esto significa que:

- Los algoritmos en C analizan la entrada y generan la secuencia adecuada de operaciones para ordenarla: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.
- La salida por consola de esta estrategia debera ser la secuencia de operaciones necesarias para ordenar el stack.
- Al expresar la complejidad, debe medirse en funcion del **numero de operaciones de Push_swap que el programa produce**, y no en base a la complejidad teorica de un algoritmo tradicional sobre arrays.

#### VI.3.2. Indice de desorden (obligatorio)

En este proyecto, el **desorden** corresponde a un numero entre 0 y 1 que refleja lo lejos que el stack a se encuentra de estar ordenado al comienzo del programa.

- Si todos los numeros estan en orden, el indice de desorden sera **0**.
- Si los numeros estan lo mas desordenados posibles, el indice de desorden sera **1**.

Para calcular el indice de desorden, se observan todos los pares posibles de numeros en el stack. Cada vez que un numero mayor aparece antes que uno menor, se considera que hay un *error* en el orden.

```
function compute_disorder(stack a):
    mistakes = 0
    total_pairs = 0
    for i from 0 to size(a)-1:
        for j from i+1 to size(a)-1:
            total_pairs += 1
            if a[i] > a[j]:
                mistakes += 1
    return mistakes / total_pairs
```

El indice de desorden se calculara **antes** de hacer ningun movimiento.

#### VI.3.3. Estrategias requeridas

1. **Algoritmo simple (O(n^2)):**
   Implementa al menos un algoritmo base perteneciente a la clase de complejidad O(n^2). Por ejemplo:
   - Adaptacion del orden por insercion
   - Adaptacion del orden por seleccion
   - Adaptacion del orden burbuja
   - Metodos simples de extraccion del minimo/maximo

2. **Algoritmo intermedio (O(n*sqrt(n))):**
   Implementa al menos un algoritmo perteneciente a la clase de complejidad O(n*sqrt(n)). Por ejemplo:
   - Orden basado en chunks (dividiendo en sqrt(n) chunks)
   - Metodos de particion basados en bloques
   - Adaptaciones del orden por buckets con sqrt(n) buckets
   - Estrategias de orden basadas en rangos

3. **Algoritmo complejo (O(n log n)):**
   Implementa al menos un algoritmo perteneciente a la clase de complejidad O(n log n). Por ejemplo:
   - Adaptacion del orden radix (LSD o MSD)
   - Adaptacion del orden por fusion utilizando dos stacks
   - Adaptacion del orden rapido con particion por stacks
   - Adaptacion del orden por monticulos
   - Algoritmos de arbol binario indexado

4. **Algoritmo adaptativo personalizado (disenado por el estudiantado):**
   Debe disenarse una estrategia **adaptativa** que seleccione distintos metodos internos segun el **indice de desorden**. No existe ninguna limitacion en cuanto a algoritmos especificos, las tecnicas internas quedan totalmente a eleccion vuestra. Sin embargo, el diseno debe respetar los siguientes **objetivos de complejidad** para cada regimen (segun el modelo de operaciones de Push_swap):

   - **Indice de desorden bajo:** Si desorden < 0,2, el metodo elegido debe ejecutarse en O(n).
   - **Indice de desorden medio:** Si 0,2 <= desorden < 0,5, el metodo elegido debe ejecutarse en O(n*sqrt(n)).
   - **Indice de desorden alto:** Si desorden >= 0,5, el metodo elegido debe ejecutarse en O(n log n).

   Debera quedar documentado en el repositorio (por ejemplo, en el archivo `README.md`) la justificacion de los valores limite (umbrales) que definen cada nivel de desorden, una descripcion de las tecnicas internas empleadas en cada caso y un breve analisis de complejidad -indicando las cotas superiores de espacio y tiempo- dentro del modelo de Push_swap.

### VI.4. Ejemplos

Para entender mejor los efectos de algunos de los movimientos, vamos a ver como se ordenaria una lista de numeros aleatoria. En este ejemplo, consideraremos que ambos stacks crecen desde la derecha.

```
Init a and b:
2 1 3 6 5 8
_ _
a b

Exec sa:
1 2 3 6 5 8
_ _
a b

Exec pb pb pb:
6 3
5 2
8 1
_ _
a b

Exec ra rb (equiv. to rr):
5 2
8 1
6 3
_ _
a b

Exec rra rrb (equiv. to rrr):
6 3
5 2
8 1
_ _
a b

Exec sa:
5 3
6 2
8 1
_ _
a b

Exec pa pa pa:
1 2 3 5 6 8
_ _
a b
```

Los enteros del stack `a` se han ordenado en 12 movimientos. Se puede hacer mejor?

### VI.5. El programa push_swap

| Campo | Valor |
|-------|-------|
| Nombre de programa | `push_swap` |
| Archivos a entregar | Makefile, *.h, *.c |
| Makefile | NAME, all, clean, fclean, re |
| Argumentos | stack a: una lista de enteros |
| Funciones autorizadas | `read`, `write`, `malloc`, `free`, `exit`, `ft_printf` y cualquier funcion equivalente que se haya creado |
| Se permite usar libft | Si |
| Descripcion | Ordena stacks |

Tu programa debera cumplir las siguientes normas:

- Se debe entregar un **Makefile** que compile los archivos fuente. No debe hacer relink.
- Las variables globales estan **prohibidas**.
- Se debe crear un programa llamado `push_swap` que recibira por argumentos:
  - El stack `a` con el formato de una lista de enteros (el primer argumento debe ser el que este encima del stack).
  - Un **selector de estrategia** opcional:
    - `--simple` fuerza el uso del algoritmo O(n^2) seleccionado.
    - `--medium` fuerza el uso del algoritmo O(n*sqrt(n)) seleccionado.
    - `--complex` fuerza el uso del algoritmo O(n log n) seleccionado.
    - `--adaptive` fuerza el uso del algoritmo adaptativo basado en desorden seleccionado. Este sera el comportamiento por defecto si no se indica un selector.
- El programa debe mostrar la lista de operaciones Push_swap mas corta posible necesaria para ordenar el stack `a`, dejando el numero mas pequeno en la cima del stack.
- Las operaciones deben estar separadas por un `\n` y nada mas.
- La clase de complejidad que se declare para cada algoritmo debe ser **valida dentro de este modelo**.
- El selector de estrategia debe funcionar para **todos los inputs validos**. Cualquier flag de seleccion debe de funcionar correctamente, independientemente del tamano de la entrada o del indice de desorden.
- Si no se especifican parametros, el programa no debera mostrar nada y devolver el control al usuario.
- En caso de error, debera mostrar `"Error"` seguido de un `\n` en la salida de error estandar. Algunos de los posibles errores son: argumentos que no son enteros, argumentos superiores a un numero entero, y/o numeros duplicados.
- El binario debe implementar las cuatro estrategias (Simple O(n^2), Intermedia O(n*sqrt(n)), Compleja O(n log n) y Adaptativa). El nombre y la clase de complejidad de la estrategia seleccionada debera estar disponible en el modo `--bench`.
- El modo **benchmark** (`--bench`) es opcional, y mostrara tras la ordenacion lo siguiente:
  - El indice de desorden (% con dos decimales).
  - El nombre de la estrategia usada y su clase de complejidad teorica.
  - El numero total de operaciones empleadas.
  - El numero de operaciones de cada tipo (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`) empleadas durante la ordenacion.

  La salida del modo **benchmark** debe enviarse a la salida `stderr` y solo se mostrara cuando la flag este presente.

### VI.5.1. Ejemplos de uso

```bash
$> ./push_swap 2 1 3 6 5 8
ra
pb
rra
pb
pb
ra
pb
ra
pb
pb
pa
pa
pa
pa
pa
pa
```

Selector de algoritmo por defecto (`--adaptive`) y contador de operaciones:
```bash
$> ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l
13
```

Forzado del uso de la estrategia simple (O(n^2)):
```bash
$> ARG="4 67 3 87 23"; ./push_swap --simple 5 4 3 2 1
rra
pb
rra
pb
rra
pb
ra
pb
pb
pa
pa
pa
pa
pa
```

Forzado del uso de la estrategia compleja (O(n log n)) y verificado con el checker:
```bash
$> ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
OK
```

push_swap con un input largo:
```bash
$> shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | wc -l
6784
```

Ejecucion del programa con el modo benchmark:
```bash
$> shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker_linux $(cat args.txt)
OK
$> cat bench.txt
[bench] disorder: 49.93%
[bench] strategy: Adaptive / O(n*sqrt(n))
[bench] total_ops: 7997
[bench] sa: 0  sb: 0  ss: 0  pa: 500  pb: 500
[bench] ra: 4840  rb: 1098  rr: 0  rra: 0  rrb: 1059  rrr: 0
```

Ejemplos del manejo de errores:
```bash
$> ./push_swap --adaptive 0 one 2 3
Error
$> ./push_swap --simple 3 2 3
Error
```

### VI.6. Prueba de rendimiento

Para superar el proyecto, se deben cumplir ciertos objetivos en cuanto al numero de operaciones empleadas:

- Para **100 numeros aleatorios**, el programa debera usar:
  - menos de **2000 operaciones** para superar el corte (requisito minimo)
  - menos de **1500 operaciones** para un buen rendimiento
  - menos de **700 operaciones** para un rendimiento excelente

- Para **500 numeros aleatorios**, el programa debera usar:
  - menos de **12000 operaciones** para superar el corte (requisito minimo)
  - menos de **8000 operaciones** para un buen rendimiento
  - menos de **5500 operaciones** para un rendimiento excelente

Todo esto sera comprobado durante la evaluacion usando el programa "checker" que se incluye como recurso del proyecto.

---

## VII. Requisitos del Readme

Debe incluirse un archivo `README.md` en la raiz del repositorio Git. Su proposito es permitir que cualquier persona que no este familiarizada con el proyecto pueda entender rapidamente de que trata el proyecto, como ejecutarlo y donde encontrar mas informacion sobre el tema.

El `README.md` debe incluir, como minimo:

- La primera linea debe estar en cursiva y decir: *Este proyecto ha sido creado como parte del curriculo de 42 por <login1>[, <login2>[, <login3>[...]]].* 
- Una seccion de **"Descripcion"** que presente claramente el proyecto, incluyendo su objetivo y una breve vision general.
- Una seccion de **"Instrucciones"** que contenga cualquier informacion relevante sobre compilacion, instalacion y/o ejecucion.
- Una seccion de **"Recursos"** que enumere referencias clasicas relacionadas con el tema (documentacion, articulos, tutoriales, etc.), asi como una descripcion del uso de IA, especificando para que tareas y en que partes del proyecto se ha utilizado.

**Contenido extra requerido:**
- Se debera incluir una explicacion detallada y una justificacion de los algoritmos seleccionados.

---

## VIII. Parte bonus

Este proyecto deja muy poco margen para anadir funcionalidades extra debido a su simplicidad. Sin embargo, que tal seria crear un checker propio?

> Gracias al programa checker, podras probar si la lista de instrucciones generadas por el programa push_swap realmente ordena el stack de forma correcta.

> **AVISO:** La parte bonus no sera evaluada si la parte obligatoria no esta perfecta. Perfecta quiere decir que se ha completado la parte obligatoria y que funciona perfectamente, sin errores. En este proyecto, esto implica validar todas las pruebas de rendimiento sin excepcion.

### VIII.1. El programa checker

| Campo | Valor |
|-------|-------|
| Nombre de programa | `checker` |
| Archivos a entregar | *.h, *.c |
| Makefile | bonus |
| Argumentos | stack a: una lista de numeros enteros |
| Funciones autorizadas | `read`, `write`, `malloc`, `free`, `exit`, `ft_printf` y cualquier funcion equivalente que se haya creado |
| Se permite usar libft | Si |
| Descripcion | Ejecuta las instrucciones de ordenacion |

- Se debera escribir un programa llamado `checker`, que tome como argumento el stack `a` en forma de una lista de enteros. El primer argumento debe estar encima del stack (cuidado con el orden). Si no se da argumento, `checker` termina y no muestra nada.
- Durante la ejecucion de `checker` se esperara y leera una lista de instrucciones, separadas utilizando `'\n'`. Cuando todas las instrucciones se hayan leido, `checker` las ejecutara utilizando el stack recibido como argumento.
- Si tras ejecutar todas las instrucciones, el stack `a` esta ordenado y el stack `b` vacio, entonces el programa `checker` mostrara `"OK"` seguido de un `'\n'` en la **stdout**.
- En cualquier otro caso, debera mostrar `"KO"` seguido de un `'\n'` en la **stdout**.
- En caso de error, se debera mostrar `Error` seguido de un `'\n'` en la **stderr**. Los errores incluyen: argumentos no enteros, argumentos mas grandes que un numero entero, duplicados, una instruccion no exista y/o no tenga el formato correcto.

```bash
$> ./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
$> ./checker 3 2 1 0
sa
rra
pb
KO
$> ./checker 3 2 one 0
Error
$> ./checker "" 1
Error
```

> **AVISO:** No hay que replicar el comportamiento exacto del binario que se entrega. Es obligatorio gestionar errores, pero es decision de cada grupo como gestionar los argumentos.

---

## IX. Entrega y evaluacion

El trabajo debera entregarse en el repositorio git como de costumbre. Solo el trabajo en el repositorio sera evaluado.

### Requisitos para la entrega de proyectos en grupo:

- Todas las personas que compongan el grupo deberan estar mencionadas como colaboradores del proyecto en el repositorio.
- Debera quedar reflejado en el archivo README.md la contribucion de cada persona al proyecto.
- Todas las personas del grupo deberan estar presentes durante la evaluacion del proyecto.
- Cada persona del grupo deberia ser capaz de explicar cualquier parte del codigo.

Durante la evaluacion, es posible que se solicite una ligera **modificacion del proyecto**. Esto puede consistir en ajustar ligeramente el comportamiento, modificar unas cuantas lineas de codigo o incorporar una caracteristica facil de implementar. Este paso sirve para verificar la comprension real de una parte especifica del proyecto.
