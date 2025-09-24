<!-- ===================== BANNER ===================== -->
<p align="center">
  <img src="https://raw.githubusercontent.com/NanoHtz/Assets/main/push_swap/banner.svg" alt="push_swap banner">
</p>

<p align="center"><i>🧩 push_swap — Ordena una pila de enteros con un conjunto mínimo de operaciones sobre dos pilas <b>a</b> y <b>b</b>. Bonus: <code>checker</code> para validar secuencias.</i></p>

<p align="center">
  <img src="https://raw.githubusercontent.com/NanoHtz/Assets/main/100.png" alt="push_swap nota" height="120">
</p>

## Índice
- [Resumen](#resumen)
- [¿Para qué?](#para-que)
- [Explicación](#explicacion)
- [Compilación](#compilacion)

---
<a id="resumen"></a>
## ✅ Resumen del proyecto<br>

**push_swap** genera una **secuencia óptima** de operaciones para ordenar una pila de enteros.  
Solo puedes usar operaciones sobre dos pilas (**a** y **b**): swaps, pushes y rotaciones.  

**Operaciones permitidas**
- **Swap**: `sa` (a), `sb` (b), `ss` (a & b)
- **Push**: `pa` (b→a), `pb` (a→b)
- **Rotate**: `ra` (a), `rb` (b), `rr` (a & b)
- **Reverse rotate**: `rra` (a), `rrb` (b), `rrr` (a & b)

**Entradas inválidas** → imprimir `Error` en **stderr** y salir con código ≠ 0:
- No numérico, overflow/underflow de `int`, duplicados, argumentos vacíos o mal formateados.

> Este proyecto sigue la **Norma oficial de 42** para estilo en C (Norminette).
> En todos los proyectos de 42, el uso de la gran mayoria de bibliotecas esta prohibido, siendo nuestro propio desarrollo libft el sustituto de las funciones básicas. 
> - Código legible.  
> - Funciones pequeñas (<25 líneas),
> - 4 parámetros por función,
> - Nombres claros en `snake_case` y en inglés.
> - 1 responsabilidad por función.
>  - Variables declaradas al inicio del bloque(maximo 4 por función). 

---

<a id="para-que"></a>
## 🧩 ¿Para qué?

**¿Qué se aprende?**
- **Estructuras de datos**: pilas enlazadas/arrays, índices y mapeos.
- **Algoritmia práctica**: *tiny sorts* (≤5), *radix sort* por bits, *chunking*, **LIS** (subsecuencia creciente más larga).
- **Optimización** de movimientos: rotaciones combinadas, coste mínimo de inserción, elegir `ra` vs `rra`.
- **Parsing robusto**: validación, normalización, manejo de errores y liberación de memoria.
---

<a id="explicacion"></a>
  <summary><h3>📝 Explicación</h3></summary>


### 🧠 Ideas clave del algoritmo

**Normalización (indexado)**
- Mapea cada valor a su **rango ordenado** `[0..n-1]`: evita overflow y simplifica comparaciones.
- Útil para **radix** y para comparar con LIS.

**Tiny sorts (≤5)**
- **2**: `sa` si están invertidos.  
- **3**: tabla de 5 casos (`sa`, `ra`, `rra` mínimo).  
- **4–5**: empuja el/los mínimos a `b`, ordena `a` (3-elem) y `pa` de vuelta en posición.

**Radix por bits (base 2) — sencillo y fiable**
- Mientras haya bits en `max_index`:  
  - Recorre `a`, si bit=0 → `pb`, si bit=1 → `ra`.  
  - Vuelca todo `b` a `a` con `pa`.  
- Complejidad: `O(n * log2 n)` con número de operaciones **predecible**.

**LIS (Subsecuencia Creciente Más Larga) — menos movimientos**
- Encuentra en `a` la LIS (indices crecientes).  
- **Mantén** la LIS en `a` y **empuja el resto** a `b`.  
- Inserta cada elem de `b` en **su lugar óptimo en `a`**:
  - Calcula el **coste** para llevar `a` y `b` a las posiciones destino (considera `ra`/`rra` y `rb`/`rrb`).  
  - Elige la combinación con **menos movimientos** (`rr`/`rrr` para solapar giros).  
  - Ejecuta rotaciones combinadas → `pa`.  
- Al final, **ajusta `a`** para que el **mínimo** quede arriba (`ra` vs `rra`).

**Optimización de rotaciones**
- Si ambos requieren girar hacia arriba → usa `rr`.  
- Si ambos hacia abajo → usa `rrr`.  
- Si en sentidos opuestos → rota por separado y **minimiza** pasos.

### 🔍 Validación y errores
- Rechaza:
  - **Duplicados**
  - Cadenas vacías o separadores extraños
  - Valores fuera de **int32** (`<-2147483648` o `>2147483647`)
  - No numéricos (maneja `+/-`, espacios, etc.)
- En error: **imprime `Error` en stderr**, libera memoria y **exit != 0**.

### 📏 Criterios de evaluación habituales (42)
- **100 números**:  
  `≤ 700` → ⭐⭐⭐⭐⭐ · `≤ 900` → ⭐⭐⭐⭐ · `≤ 1100` → ⭐⭐⭐ · `≤ 1300` → ⭐⭐ · `≤ 1500` → ⭐
- **500 números**:  
  `≤ 5500` → ⭐⭐⭐⭐⭐ · `≤ 7000` → ⭐⭐⭐⭐ · `≤ 8500` → ⭐⭐⭐ · `≤ 10000` → ⭐⭐ · `≤ 11500` → ⭐

*(Tus resultados dependerán de la estrategia, la heurística de costes y los casos borde.)*

### 🧼 Memoria y fugas
- Sin leaks ni *dangling pointers*.  
- Liberar pilas y buffers en **todas** las rutas (incluyendo errores de parseo).  
- `valgrind --leak-check=full --show-leak-kinds=all ./push_swap ...`


---

<a id="compilacion"></a>
## 🛠️ Compilación
⬇️ Descarga
```bash
git clone https://github.com/NanoHtz/push_swap.git
```
🏗️ Makefile
```bash
make          # compila ./push_swap
make clean    # borra .o
make fclean   # borra .o y binarios
make re       # recompila desde cero
```
🏗️ Pruebas
<br>
Recomiendo el uso del siguiente tester:
</br>
```bash 
https://github.com/gemartin99/Push-Swap-Tester
```
