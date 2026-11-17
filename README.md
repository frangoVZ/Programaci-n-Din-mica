
# Programación Dinámica

## Descripción
Este proyecto implementa dos problemas utilizando la estrategia de Programación Dinámica en C++.

Los problemas desarrollados son:

1. **Escaleras:** calcula cuántas formas diferentes existen para llegar a una escalera de N escalones, avanzando uno o dos escalones.
2. **Cambio mínimo de monedas:** calcula la menor cantidad de monedas necesarias para formar una cantidad exacta de dinero.

## Tecnologías utilizadas
- Lenguaje: C++
- Bibliotecas: iostream y vector
- Compilador: g++ (C++11 o superior).

## Estructura del proyecto

```text
ProgramacionDinamica/
├── programacion_dinamica.cpp
└── README.md
```

## Cómo ejecutar el programa

1. Descargar o clonar el repositorio.
2. Abrir una terminal en la carpeta del proyecto.
3. Compilar el programa:

```bash
g++ -std=c++11 programacion_dinamica.cpp -o programa
```

4. Ejecutar el programa.

En Windows:

```bash
programa.exe
```

En Linux:

```bash
./programa
```

## Uso del programa

Al iniciar, aparece un menú con las siguientes opciones:

1. Problema de escaleras.
2. Cambio mínimo de monedas.
3. Salir.

El usuario selecciona el problema que desea ejecutar e ingresa los datos solicitados.

## Ejemplos de ejecución

### Problema 1: Escaleras

Entrada: N = 5

Salida:

```text
Formas posibles: 8
Tabla DP:
[1, 1, 2, 3, 5, 8]
```

### Problema 2: Cambio mínimo de monedas

Entrada:
- Monedas: [1, 3, 4]
- Cantidad: 6

Salida:

```text
Cantidad minima de monedas: 2
Combinacion: 3 + 3
Tabla DP:
[0, 1, 2, 1, 1, 2, 2]
```

## Análisis de complejidad

### Escaleras
- Estado DP: dp[i] representa las formas de llegar al escalón i.
- Casos base: dp[0] = 1 y dp[1] = 1.
- Recurrencia: dp[i] = dp[i-1] + dp[i-2].
- Complejidad temporal: O(N).
- Complejidad espacial: O(N).

### Cambio mínimo de monedas
- Estado DP: dp[i] representa la cantidad mínima de monedas para formar i.
- Caso base: dp[0] = 0.
- Recurrencia: dp[i] = min(dp[i], dp[i-moneda] + 1).
- Complejidad temporal: O(A × M).
- Complejidad espacial: O(A).

Donde A es la cantidad objetivo y M es el número de denominaciones disponibles.

## Autor
Estudiante de Ingeniería de Software.
