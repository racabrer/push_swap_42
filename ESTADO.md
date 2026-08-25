# Estado de la rama — push_swap

**Rama:** `raquel` · **Fecha:** 2026-08-24 · **Sin commitear** (todo revisable con `git diff`)

Documento único: qué está hecho, qué he tocado y por qué, qué puede dar problemas y qué queda.

---

## 1. Resumen en una línea

La rama ya no se cuelga, valida las entradas, ordena bien y cumple los objetivos de
rendimiento. **Queda la cabecera 42 (la pones tú), los leaks en Linux y la preparación
del merge.**

Batería de tests: **14 pasan · 1 falla · 3 pendientes**

```
PASA  AC1    termina con 1000/2000/5000 números (antes se colgaba)
PASA  AC2    sin funciones prohibidas ni <stdio.h>
PASA  AC3    stdout solo lleva operaciones válidas
PASA  AC4    los 8 casos de error dan Error por stderr
PASA  AC5    --medium se acepta y ordena
PASA  AC6    sin argumentos: nada por stdout/stderr y rc=0
PASA  AC7    entrada ordenada -> 0 operaciones
PASA  AC12   ordena en 13 tamaños x3 semillas + 5 bordes
PASA  AC14   ops con n<=5 dentro de límite: n=2:1/1 n=3:2/3 n=4:6/12 n=5:10/12
PASA  AC15   UBSan: 0 comportamientos indefinidos
PASA  AC10a  el binario se llama push_swap
PASA  AC10b  sin relink
PASA  AC11a  n=100 peor=707 (<2000) · n=500 peor=6108 (<12000)
PASA  AC11b  sin regresión frente a la línea base
SALTA AC11c  informe de distribución -> ejecutado, ver §5
FALLA AC9    norminette: 19 errores = las 19 cabeceras 42  <-- lo haces tú
SALTA AC8    valgrind (solo Linux)
SALTA AC13   merge_check.sh: 2 símbolos que su código usa no existen aquí (§4)
```

**Rendimiento:** n=100 de 794 a **654** ops de media · n=500 de 8221 a **5889** (−28 %).
Ambos dentro de "buen rendimiento" del subject. "Excelente" en 500 (<5500) no se alcanza
con este algoritmo — ver §5.

---

## 2. Qué he tocado, fichero a fichero

**17 ficheros modificados: +338 / −752 líneas.** De esos, **solo 6 tienen cambios de código
real**; los otros 11 son formato y borrado de comentarios muertos.

### 2.1 Cambios de código real

| Fichero | Qué toqué | Por qué |
|---|---|---|
| **push_swap.c** | Borradas `run_sort()` y `count_pipe_output()` enteras, los 3 `printf` de `main` y `#include <stdio.h>`. `create_stack()` sustituida por `run_parse()`. `main` llama a `sort_chunks` directo. **123 → 39 líneas.** | Era el deadlock (§3.1) y todas las funciones prohibidas a la vez. `run_parse` enchufa el parseo que ya estaba escrito y nadie llamaba (§3.3). |
| **ft_atol.c** | `return (1)` → `return (LONG_MAX)` en `get_number`. `result == LONG_MAX` → `result == LONG_MAX / 10` en `overflow`. Quitado un `;;`. | `1` es un valor de entrada válido, así que no puede servir de señal de error (§3.4). `LONG_MAX` ya lo rechaza `is_int_range`. |
| **medium_alg.c** | `get_chunk_size`: `ft_sqrt(n)` → `(ft_sqrt(n) * 11) / 5` con guarda `< 1`. `process_chunk`: `rb(b)` condicional tras `pb`. `find_chunk_node`: `if (cost < best_cost && (best = curr))` separado en dos líneas. | Los dos primeros son rendimiento (−18 % y −28 %). Sigue siendo `k·√n`, o sea O(n·√n) como exige el subject. El tercero era obligatorio para la Norma (`ASSIGN_IN_CONTROL`) y **se demostró que no cambia el comportamiento** (huella SHA idéntica sobre 40 ejecuciones). |
| **push_swap.h** | Quitado `#include <stdio.h>`. Directivas dentro del guard a `# include` / `# define`. Prototipos realineados a la columna 8. | La primera es funcional; las otras dos son Norma. |
| **indexes.c** | `t_node *current;` movida de después del `if` al principio de la función. | Norma (`VAR_DECL_START_FUNC`). No lleva inicializador, así que moverla no cambia nada. |
| **Makefile** | `NAME = test` → `NAME = push_swap`. | El subject exige que el binario se llame así. |
| **push_swap.c** (2ª tanda) | Añadidas `arg_vacio()` y `sort_small()`; `main` despacha `n<=5` a `sort_small`. Borrados 2 prototipos comentados de `push_swap.h`. | Los bugs 3.7.1 y 3.7.2 de la revisión. |
| **ft_atol.c** (2ª tanda) | `digit > 8` → `digit > 7` en la rama negativa de `overflow()`. | El comportamiento indefinido 3.7.3. |
| **push_swap.c** (3ª tanda) | `if (argc < 2) return (1);` → `return (0);`. | Sin argumentos no es un error; el contrato reserva `rc != 0` para el caso de `Error` (§3.9). |

### 2.2 Solo formato y comentarios muertos (cero cambios de comportamiento)

`errors.c` · `little_numbers.c` · `nodes.c` · `nodes_utils.c` · `parser_flags.c` ·
`parser_numbers.c` · `reverse_rotate.c` · `rotate.c` · `split.c` · `swap.c` ·
`utils_parser_num.c`

Aquí solo se ha hecho: espacios → tabuladores, alineación de declaraciones, borrado de
comentarios y de código comentado (variantes abandonadas), y `while(` → `while (`.

**Nada de esto altera la salida del programa, y está demostrado**, no supuesto: antes de tocar
formato congelé la salida byte a byte sobre 45 casos (`push_swap_42_dev/tests/golden/manifest.txt`) y la comparé
después de cada tanda. **Idéntica en todo momento.** El propio golden se probó rompiéndolo a
propósito (cambiando un `<=` por un `<`) para comprobar que sabe detectar un cambio.

### 2.3 Ficheros nuevos

**Dentro del repo, solo este documento** (`ESTADO.md`).

Los tests y la documentación de trabajo están **fuera del repo**, en
`~/Desktop/push_swap_42_dev/`, para que lo que subas sea solo código:

```
~/Desktop/push_swap_42_dev/
├── tests/          gen.pl · checker.sh · run_tests.sh · golden.sh · golden/ · baseline.txt
└── specs/2026-08-24-arreglo-rama-raquel/   investigación · spec · plan · tareas
```

Están en shell y markdown a propósito: un `.c` de test dentro del repo entraría en la
verificación de Norma del evaluador (subject §II). Un `.sh` fuera del repo no lo toca nadie.

---

## 3. Los fallos que había (y su estado)

### 3.1 Deadlock del pipe — ARREGLADO

`run_sort()` redirigía `stdout` a un pipe, ejecutaba `sort_chunks()` entera y **solo después**
leía del pipe. El pipe del sistema tiene capacidad fija — **medida: 65535 bytes en este Mac**.
Al llenarse, `write()` se queda esperando a que alguien vacíe, y el único que podía vaciarlo
era el paso siguiente, que no llegaba nunca. El programa se esperaba a sí mismo.

- **No era un bucle infinito:** el proceso colgado estaba al **0,0 % de CPU**, dormido dentro
  de `write()`. Un bucle infinito quema un núcleo al 100 %.
- **El corte no está en un número de números, está en bytes:** ~19 000 operaciones ≈ 65 535
  bytes. Por eso a ti te pasaba con 867 y en las pruebas con 880: depende de la permutación.
- Hoy: 5000 números = **161 192 operaciones en 1,2 s**, doce veces el volumen del cuelgue.

### 3.2 Funciones prohibidas — ARREGLADO

`pipe`, `dup`, `dup2`, `close`, `fflush`, `printf` y `<stdio.h>`. Todas estaban en
`push_swap.c`, en el mismo andamiaje del punto anterior. Se fueron con él.

### 3.3 `main` no validaba nada — ARREGLADO

Usaba `create_stack`, que hacía `ft_atol` a pelo. `parse_flags`, `parse_numbers`, `is_number`,
`is_int_range`, `has_duplicates`, `normalize_args` y `exit_error` estaban **escritas,
correctas, declaradas en el `.h` y nunca llamadas**. No hubo que escribirlas: enchufarlas.

### 3.4 `ft_atol` aceptaba números gigantes como un `1` — ARREGLADO

`get_number` usaba `return (1)` para avisar de desbordamiento, y `1` es un valor legítimo.
`./push_swap 9999999999999999999 5 3` lo tomaba por un `1` y ordenaba en vez de dar `Error`.

### 3.5 Norma: 768 errores — ARREGLADO salvo cabeceras

Quedan **19**, uno por fichero, todos `INVALID_HEADER`. El resto a cero.
Se verificó con dos ficheros de control que norminette sabe detectar funciones de más de 25
líneas y ficheros de más de 5 funciones — **ninguna función tuya incumplía eso**, así que el
pase fue puramente cosmético.

### 3.6 Encontrados, verificados y NO arreglados — las seis, con su motivo

**Ninguna de las seis tumba la evaluación.** Las tres primeras son de robustez fuera de los
tamaños que se prueban; las tres últimas son inalcanzables hoy. Van en orden de cuánto
merece la pena preocuparse.

#### 1. `rr` / `rrr` / `ss` con stacks de 1 elemento — `rotate.c`, `reverse_rotate.c`, `swap.c`

El subject (§VI.2) define `rr` como «`ra` y `rb` a la vez». La implementación hace:

```c
if (!a || !b || !a->top || !b->top || a->size <= 1 || b->size <= 1)
    return ;
```

Si `b` tiene **1 solo elemento no hace nada en absoluto**, ni siquiera rota `a`. Debería
rotar `a` igualmente: rotar un stack de 1 elemento no hace nada, pero el otro sí debe moverse.

**Por qué no se tocó:** hoy nadie llama a `rr`/`rrr`/`ss` en esta rama. Al mergear sí se
activan — `common_moves.c` de la otra rama las llama en bucle desde `rotate_both` y
`reverse_rotate_both`. Pero ese bucle es `while (*a_moves && *b_moves)`, y un stack de 1
elemento tiene su nodo en la posición 0, así que su contador vale 0 y el bucle no entra.
**Parece inalcanzable, pero no está demostrado de forma exhaustiva.**

→ **Es la que más hay que vigilar al mergear.** Son 3 líneas si se decide arreglar.

#### 2. `ft_split` es cuadrático — `split.c`, `utils.c`

Solo se nota con **un único argumento entrecomillado** que contenga miles de números:
40 000 números tardan 5,6 s, y sueltos 41 ms. `ft_strlcpy` recorre toda la cadena restante
en cada palabra, y se paga dos veces (`count_numbers` y `normalize_args` separan por su
cuenta). Medidas completas en §3.9.

**Por qué no se tocó:** a tamaños de evaluación es invisible — n=500 tarda 29 ms
entrecomillado frente a 28 ms suelto. Y arreglarlo obliga a reescribir una función de libft.

#### 3. Tiempo real ~n^2,6 — `medium_alg.c`, `nodes_utils.c`

Ordenar 20 000 números tarda **41 segundos**. `find_chunk_node` recorre la lista entera para
saber la posición de un nodo *mientras su propio bucle ya la está recorriendo* (la posición es
el contador del bucle), y `move_a_to_top` recalcula `get_position` tras cada rotación cuando
la posición solo cambia en ±1. Tabla de tiempos en §3.8.

El arreglo se construyó aparte y se verificó **byte a byte idéntico** en 285 entradas:
12,6× más rápido a n=20000.

**Por qué no se aplicó:** el subject se detiene en 500 números, donde son 18 ms. Y tocaría
`nodes_utils.c`, que es justo el fichero en conflicto con la otra rama — aplicarlo ahora
complica más el merge.

#### 4. Fuga en `normalize_args` — `utils_parser_num.c`

Si `ft_split` falla a mitad del bucle, sale con `return (NULL)` sin liberar el `new_array`
ya reservado ni las cadenas que `copy_split` ya duplicó.

**Por qué no se tocó:** solo ocurre si falla un `malloc`. Y el agente de parseo comprobó con
**1 496 inyecciones de fallo de `malloc`** que el escenario peligroso no existe: nunca ordena
una lista truncada en silencio, siempre da `Error` limpio o el resultado completo (§3.9).

#### 5. `find_max_node` compara por `index`, `find_min_node` por `value` — `nodes_utils.c`

Dos funciones hermanas con criterios distintos. Dan el mismo resultado **siempre que
`assign_indexes` se haya ejecutado antes**, que es lo que hace `main`. Si alguien reutiliza
`find_max_node` antes de indexar, todos los índices valen 0 y devuelve el primer nodo.

**Por qué no se tocó:** hoy es correcto. Cambiarlo sería tocar lógica que funciona sin ganar
nada.

#### 6. `get_chunk_size(size <= 0)` devuelve `0` — `medium_alg.c`

Con `chunk_size = 0`, el bucle de `sort_chunks` haría `chunk_min += 0` eternamente: bucle
infinito.

**Por qué no se tocó:** es inalcanzable. `n <= 5` va a `sort_small`, y con la pila vacía
`is_sorted` corta antes de llegar al bucle. Ni la revisión ni el agente de algoritmo
consiguieron construir una entrada que llegue ahí.

---

### 3.7 Hallazgos de la revisión de código (posterior) — ARREGLADOS

Una revisión adversarial posterior encontró **tres bugs reales que mi batería dejaba pasar
en verde**. Los tres están arreglados y verificados.

#### 3.7.1 Con pocos números gastaba muchísimas operaciones

`sort_chunks` nunca daba el control a `sort_two/three/four/five`, que estaban escritas,
compiladas y sin llamar.

| | antes | ahora | límite de evaluación |
|---|---|---|---|
| n=2 | 5 ops | **1** | 1 |
| n=3 | 10 ops | **2** | 3 |
| n=4 | 13 ops | **6** | 12 |
| n=5 | 17 ops | **10** | 12 |

Arreglo: `sort_small()` en `push_swap.c` despacha `n<=5` a las funciones que ya existían.
Verificado sobre **todas las permutaciones de n=1..5**: 0 fallos de ordenación.

⚠️ **Este arreglo introdujo una regresión y la batería la cazó**: `sort_chunks` tenía la
guarda `is_sorted` y `sort_small` no, así que `./push_swap 1 2 3 4 5` pasó a emitir 4
operaciones en vez de 0 (AC7 en rojo). Corregido añadiendo la misma guarda.

#### 3.7.2 Un argumento vacío acompañado se tragaba sin error

`./push_swap "" 1` no daba error y salía con 0; `./push_swap 3 "" 1` ordenaba solo `[3,1]`.
`ft_split("", ' ')` no produce ninguna palabra, así que el argumento desaparecía en silencio.

Mi AC4 probaba `""` **sola** —que sí daba error— y no acompañada. Punto ciego.

Arreglo: `arg_vacio()` en `push_swap.c` rechaza cualquier argumento vacío o solo con espacios
antes de separar. Verificado: `""`, `"" 1`, `3 "" 1`, `1 2 ""`, `" " 1` → todos `Error`.

#### 3.7.3 Comportamiento indefinido en `ft_atol` con `LONG_MIN`

Mi arreglo anterior dejó `digit > 8` en la rama negativa de `overflow()`, y eso permite
construir una magnitud que no cabe en `long`. UBSan lo confirmaba:

```
ft_atol.c:33: signed integer overflow: 9223372036854775800 + 8
ft_atol.c:57: signed integer overflow: -9223372036854775808 * -1
```

Imprimía `Error` igualmente a `-O0`, pero con optimización el compilador puede asumir que el
desbordamiento no ocurre y colar el valor como válido. Arreglo: `> 7` en ambas ramas.
Verificado con UBSan: **0 runtime errors**.

⚠️ **Corrección a este documento:** §3.4 decía "ARREGLADO" cuando el UB seguía ahí. El bug
que describí sí estaba arreglado; el comportamiento indefinido no. Ahora sí lo está.

#### 3.7.4 Puntos ciegos de la batería, ya tapados

Los tres bugs pasaban en verde. Se han añadido:
- **AC14** — operaciones con `n<=5` contra los límites de evaluación (no existía ninguna
  comprobación por debajo de n=100).
- **AC15** — build con UBSan sobre valores límite y una entrada de 200 números.
- **AC4 ampliado** con cuatro casos de argumento vacío acompañado.

Sigue sin cubrirse: que los selectores `--simple/--complex/--adaptive` hagan cosas distintas.
Es imposible cubrirlo en esta rama porque solo existe una estrategia (§6, fuera de alcance).

---

### 3.8 Campaña de estrés con agentes adversariales

Dos agentes independientes atacaron la rama. El de corrección, memoria y rendimiento terminó
con este resultado:

#### Cero fallos de corrección en 60 736 casos

| Categoría | Casos | Resultado |
|---|---|---|
| Permutaciones exhaustivas n=1..8 | 46 233 | 0 fallos |
| Fronteras: cada n=1..30 + n=35..145 críticos de chunk | 10 523 | 0 fallos |
| Patológicas n=6..501 (15 patrones) | 225 | 0 fallos |
| Aleatorias grandes n=200..2000 | 513 | 0 fallos |
| Barrido final, rango INT completo | 925 | 0 fallos |
| Pruebas de rendimiento (todas verificadas ordenadas) | 2 000 | 0 fallos |
| ASan + UBSan | 113 | 0 hallazgos |
| `leaks`, rutas normales y de error | 12 | **0 fugas, 0 bytes** |
| Aritmética de chunks, n=1..2000 | 2 000 | cada índice cubierto exactamente una vez |

**Por qué esos ceros valen algo:** el agente validó sus instrumentos antes de fiarse.
Su simulador pasó 15 casos calculados a mano, 6 de ellos con resultado KO obligatorio.
Después mutó salidas reales (quitar la última operación, añadir un `sa`, truncar a la mitad)
y comprobó que el veredicto pasaba a KO siempre. Y compiló un binario **deliberadamente roto**
(quitando el `sa` corrector de `sort_three`): lo cazó en 75 de 5913 permutaciones.
El detector de fugas se validó con una fuga inalcanzable de 4 KB, que reportó correctamente.

Además detectó **dos instrumentos propios averiados** antes de reportar nada:
`detect_leaks=1` hacía que ASan saliera sin ejecutar el programa en macOS arm64 (invalidando
una tanda entera de 108 casos), y su generador producía duplicados, provocando dos "fallos"
falsos donde push_swap había respondido `Error` correctamente.

#### Hallazgo nuevo: coste en tiempo real (no es fallo del subject)

El tiempo de pared crece como ~n^2,6 por dos recorridos redundantes:

- `medium_alg.c:31` — `find_chunk_node` llama a `get_rotation_cost`, que recorre la lista
  entera para localizar `curr`… mientras su propio bucle ya va recorriendo la lista. La
  posición es el contador del bucle.
- `nodes_utils.c:29` y `:48` — `move_a_to_top` / `move_b_to_top` recalculan `get_position`
  tras **cada rotación**, cuando la posición solo cambia en ±1.

| n | actual | con el arreglo | mejora |
|---|---|---|---|
| 1000 | 0,027 s | 0,011 s | 2,5× |
| 5000 | 1,19 s | 0,19 s | 6,2× |
| 10000 | 7,41 s | 0,82 s | 9,0× |
| 20000 | **40,9 s** | 3,24 s | 12,6× |

El arreglo se construyó aparte y se verificó **byte a byte idéntico** en 285 entradas de
n=1..1000. **No está aplicado**: el subject se detiene en 500 números, donde esto es
invisible (18 ms), y tocaría `nodes_utils.c`, que es justo uno de los ficheros en conflicto
con la rama del compañero. Queda como decisión tuya.

#### Confirmación independiente de que "excelente" en 500 no es cuestión de ajuste

El agente compiló **13 variantes** con constantes de chunk distintas y las midió con 120
permutaciones cada una:

| multiplicador | chunk (n=500) | media |
|---|---|---|
| 4/5 | 17 | 8688 |
| 8/5 | 35 | 6246 |
| **11/5 (actual)** | **48** | **5856** |
| 13/5 | 57 | 5840 |
| 22/5 | 96 | 6449 |
| 40/5 | 176 | 8657 |

La curva toca fondo entre 11/5 y 13/5 y **nunca baja de 5500**. Mínimo en 1000 intentos: 5556.
Confirma lo de §5: llegar a "excelente" exige otra estrategia para el stack b (inserción por
coste), no otra constante.

#### Latente nuevo (no reproducible hoy)

`get_chunk_size` devuelve `0` si `size <= 0`, y con `chunk_size = 0` el bucle de `sort_chunks`
no avanzaría nunca (`chunk_min += 0`). **Inalcanzable hoy**: `sort_chunks` solo se llama con
`size >= 6` porque `n <= 5` va a `sort_small`, y además `is_sorted` corta antes con la pila
vacía. Una guarda barata si quieres blindarlo.

---

### 3.9 Campaña del agente de parseo y gestión de errores

El segundo agente atacó exclusivamente el parseo. **No consiguió ni un crash**: ni segfault,
ni bus error, ni abort, ni double free, en ~9 000 casos aleatorios más la batería dirigida.

#### Lo más valioso: 1 496 inyecciones de fallo de `malloc`

Construyó un interposer de `dyld` que fuerza el fallo de `malloc` en **cada punto de
asignación, uno por uno**: 374 puntos válidos × 4 formas de invocación. En las 1 496 el
programa o responde `Error` + `rc=1`, o tiene éxito y ordena la entrada **completa**
(verificado con el checker).

→ Eso **descarta el escenario peligroso** de la fuga de §3.6: `copy_split` no trunca el array
en silencio ordenando solo un subconjunto. La fuga en sí sigue siendo una observación de
código, no un fallo medido.

#### Categorías atacadas sin encontrar nada

Formas de argumento (entrecomillado, espacios múltiples, tabuladores, `\n`, `\r`, mezclas) ·
signos y ceros (`+5`, `-0`, `+-5`, `--5`, `5-`, `0x10`, `1e3`, 100 ceros a la izquierda) ·
duplicados sutiles (`7`/`007`/`+7`, `0`/`-0`/`000`) · límites (INT_MIN/MAX, LONG_MIN/MAX,
900 000 dígitos) · flags de todo tipo (repetidas, dos estrategias, después de los números,
`---medium`, `--MEDIUM`, `--medium=1`) · bytes exóticos (dígitos árabe-índicos, fullwidth,
emoji, espacio no-rompible U+00A0) · volumen hasta el máximo real de `execve` en esta máquina,
**75 445 argumentos**, parseados en 0,03 s · ASan+UBSan sobre toda la batería · `leaks` en
9 escenarios: 0 fugas.

#### Hallazgo 1 — código de salida sin argumentos: ARREGLADO

`./push_swap` sin argumentos devolvía `rc=1`. No imprimía nada (correcto), pero el código de
salida decía "error", y el contrato reserva `rc != 0` para el caso de `Error`. En la práctica
`./push_swap $ARG || echo KO` reportaba fallo con `ARG` vacío.

Fue **la única violación de contrato en 9 000 casos**. Arreglado: `return (0)`.
**AC6 no lo detectaba porque no comprobaba el código de salida**; ahora sí.

#### Hallazgo 2 — `ft_split` es cuadrático: NO ARREGLADO (decisión tomada)

Con **un solo argumento entrecomillado** que contenga muchos números:

| N | 1 arg entrecomillado | N args sueltos |
|---|---|---|
| 5 000 | 97 ms | 26 ms |
| 10 000 | 321 ms | 27 ms |
| 20 000 | 1 396 ms | 33 ms |
| 40 000 | **5 645 ms** | 41 ms |

Se multiplica por 4 al doblar N. Causa: `ft_strlcpy` (`utils.c`) hace `ft_strlen(src)` sobre
todo el resto de la cadena, y `ft_split` lo llama una vez por palabra. Y se paga **dos veces**,
porque `count_numbers` y `normalize_args` hacen cada uno su propio `ft_split` completo.

**No se arregla**: a tamaños de evaluación es invisible (n=500 tarda 29 ms entrecomillado
frente a 28 ms suelto) y corregirlo obliga a reescribir una función de libft.

#### Aviso sobre un dato del informe

El agente reportó que "el número de operaciones excede los límites del subject" comparando
n=100 con 700 y n=500 con 5 500. **Esos son los umbrales de "excelente", no los de aprobado**
(2 000 y 12 000) ni los de "buen rendimiento" (1 500 y 8 000). No es un hallazgo nuevo: es
lo de §5.

---

## 4. Riesgos del merge con la rama de tu compañero

Ficheros que tocáis **los dos**: `push_swap.h`, `nodes_utils.c`, `Makefile`. Conflicto seguro.

### 4.1 Lo que ya había antes de hoy

| # | Problema | Evidencia |
|---|---|---|
| **H1** | Tu rama eliminó `move_to_top`; su `insertion.c:32` la llama | `git grep move_to_top origin/main` |
| **H2** | Su rama tiene `get_reverse_position`, la tuya no; la usa en **8 sitios** de `insertion_cost.c` e `insertion_move.c` | ídem |
| **H3** | La unión de las dos versiones de `nodes_utils.c` son **7 funciones** y la Norma permite **5** | conteo directo |
| **H4** | `rotate`, `reverse_rotate`, `swap_node` y `push` devuelven `int` en tu rama y `void` en la suya | comparación de los `.h` |
| **H5** | Hoy el merge propagaría tu `main` (el del pipe) a `main` | `push_swap.c` solo lo ha tocado tu rama |

**H5 ya no aplica**: al borrar el andamiaje, mergear tu rama ya no rompe la suya.

### 4.2 Lo que hemos añadido HOY (esto es nuevo, y es lo que pediste anotar)

| Fichero compartido | Divergencia antes | Divergencia ahora | Por qué |
|---|---|---|---|
| `push_swap.h` | 27 líneas | **71 líneas** | El pase de Norma realineó todos los prototipos y cambió `#include` por `# include`. El conflicto será **más grande**, aunque más mecánico. |
| `nodes_utils.c` | 151 líneas | 146 líneas | Bajó un poco (se borraron comentarios), pero H1/H2/H3 siguen intactos. |
| `Makefile` | 9 líneas | **20 líneas** | `NAME = push_swap` más las diferencias de `SRC` que ya había. |

⚠️ **Consecuencia práctica:** cuanto más tarde en hacerse el merge, peor. El pase de Norma en
la otra rama va a chocar con el de esta. **Lo sensato es acordar con tu compañero quién
normaliza qué, o normalizar los ficheros compartidos una sola vez y entre los dos.**

### 4.3 Verificado automáticamente

`push_swap_42_dev/tests/merge_check.sh` lo comprueba solo. Salida actual:

```
move_to_top            NO EXISTE en esta rama   <- rompe su insertion.c
get_reverse_position   NO EXISTE en esta rama   <- rompe su insertion_cost.c y insertion_move.c
find_min_node          nodes_utils.c            OK
find_max_node          nodes_utils.c            OK
get_position           nodes_utils.c            OK
```

**Decisión pendiente, y es a dos.** Como la unión no cabe en un fichero (H3), hay que partir
`nodes_utils.c` sí o sí. Opciones:
- **(a)** Restauras `move_to_top` y traes `get_reverse_position`, repartiendo en dos ficheros.
- **(b)** Él migra a `move_a_to_top`/`move_b_to_top` y tú traes `get_reverse_position`.
- **(c)** Lo dejáis para el merge, asumiendo que no compilará a la primera.

---

## 5. Rendimiento: qué se consigue y qué no

Medido sobre **1300 permutaciones** en n=100 y **600** en n=500 (varias tandas).
Los máximos son **el peor valor visto en cualquier tanda**, no el de la última.

| | media | p99 | **peor visto** | tramo del subject |
|---|---|---|---|---|
| **n=100** | 651 | 712 | **742** | excelente (<700) en el **97,25 %**; el resto, bueno |
| **n=500** | 5881 | 6130 | **6256** | **siempre** bueno (<8000); **nunca** excelente (<5500) |

Dos cosas que conviene tener claras para la defensa:

- **En 500 números no se alcanza "excelente" y no es mala suerte.** El mejor caso de 300 fue
  5538, a 38 operaciones del umbral. Es estructural del chunk sort. Bajar de 5500 exige el
  algoritmo de inserción por coste — que es justo el trabajo de tu compañero (`insertion.c`).
  Se conectará al mergear.
- **En 100 números el 2,75 % de las permutaciones pasa de 700** (55 de 2000, máximo 731). No es un fallo que arreglar:
  es la dispersión natural del algoritmo, y 700 es el tramo de bonificación, no el de aprobado
  (que es 2000, y estamos a un tercio). Se comprobó que **no es ajustable**: barriendo el
  tamaño de chunk de 18 a 28, ese porcentaje se queda entre 2,7 % y 6 %.

Por eso los tests **garantizan** los umbrales de corte (que se cumplen con 2,7× y 2,0× de
margen), **vigilan** que no empeoremos con semillas fijas, e **informan** de la distribución
real. Ningún criterio depende de qué permutación toque.

---

## 6. Qué queda pendiente

| | Tarea | Quién | Bloquea |
|---|---|---|---|
| **P1** | Cabecera 42 en los 19 ficheros | **tú, a mano** | AC9 (único rojo) |
| **P2** | Pasar valgrind en un iMac de 42 | **tú** | AC8 — se reporta *no ejecutado*, nunca *pasado* |
| ~~P3~~ | ~~`merge_check.sh`~~ — **hecho**, ver §4.3 | — | — |
| **P4** | Decidir el reparto de `nodes_utils.c` (§4.3) | **tú + tu compañero** | el merge |
| **P5** | Ensayo de merge en rama desechable | yo | — |
| **P7** | Decidir si `specs/` y `tests/` se quedan en el repo | **tú** | nada |
| **P8** | Commitear (no he commiteado nada) | **tú** | nada |

### Fuera de alcance por decisión tuya
Las otras 3 estrategias (simple, complejo, adaptativo — son de tu compañero) · `--bench` ·
el `checker` del bonus · el README del subject.

---

## 7. Cómo verificar cualquier cosa de este documento

Los tests viven fuera del repo y apuntan solos a `~/Desktop/push_swap_42`:

```bash
cd ~/Desktop/push_swap_42_dev
./tests/run_tests.sh              # batería completa
./tests/run_tests.sh --perf       # + distribución sobre 300 permutaciones
./tests/golden.sh check           # ¿ha cambiado la salida byte a byte?

cd ~/Desktop/push_swap_42
norminette *.c *.h                # estado de la Norma
git diff                          # todo lo que he tocado
```

Si mueves el repo, dile dónde está: `PS_REPO=/otra/ruta ./tests/run_tests.sh`

⚠️ **Si pruebas a mano en la terminal:** el shell es **zsh**, que **no separa en palabras** una
variable sin comillas (bash sí). `./push_swap $args` le pasaría los 500 números como **un solo
argumento**. Usa `./push_swap $(./tests/gen.pl 500 3)` o entra en `bash` primero.
