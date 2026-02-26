# Proyecto SO - Planificación de CPU

Proyecto de Sistemas Operativos para simular la planificación de CPU con cuatro algoritmos de scheduling. Incluye una interfaz gráfica en Qt y un núcleo de simulación con generación de procesos.

## Tabla de contenido

- [Descripción](#descripción)
- [Algoritmos de planificación](#algoritmos-de-planificación)
- [Características](#características)
- [Capturas](#capturas)
- [Requisitos](#requisitos)
- [Instalación](#instalación)
- [Cómo ejecutar](#cómo-ejecutar)
- [Estructura del proyecto](#estructura-del-proyecto)
- [Documentación](#documentación)
- [Notas](#notas)
- [Licencia](#licencia)

## Descripción

El proyecto implementa un conjunto de algoritmos de planificación dentro del núcleo del simulador y expone controles desde la interfaz para configurar procesos, prioridades y tiempos. El objetivo es apoyar el aprendizaje práctico de los conceptos de planificación en sistemas operativos

## Algoritmos de planificación

- FCFS (First Come, First Served): atiende los procesos en el orden de llegada sin desalojo
- SJF (Shortest Job First): prioriza el proceso con menor tiempo de CPU estimado; puede generar inanición en procesos largos
- Prioridades: ejecuta primero los procesos con mayor prioridad; si hay empate, se mantiene el orden de llegada
- Round Robin: asigna un quantum fijo a cada proceso y rota en cola para repartir el CPU de forma justa

## Características

- Simulación de 4 algoritmos de scheduling
- Generación de procesos con parámetros configurables
- Interfaz gráfica en Qt para ejecutar y visualizar la simulación
- Estructura separada entre UI, núcleo y utilidades

## Capturas

Las imágenes del programa se almacenan en la carpeta `imagenes/`
 
- ![Pantalla principal](imagenes/imagen%201.png)
- ![FCFS](imagenes/imagen%202.png)
- ![SSJF](imagenes/imagen%203.png)
- ![Round Robin](imagenes/imagen%204.png)
- ![Prioridades](imagenes/imagen%205.png)


## Requisitos

- Windows con Qt 6 (Qt 6.9.1 MinGW 64-bit)
- CMake 3.20+
- Compilador MinGW compatible con Qt

## Instalación

1. Clona el repositorio
2. Abre el proyecto en Qt Creator o VS Code
3. Configura el kit de Qt y el compilador
4. Ejecuta la configuración de CMake

## Cómo ejecutar

1. Compila el proyecto desde tu IDE o con CMake
2. Ejecuta el binario generado
3. Configura los procesos y selecciona el algoritmo a simular

Comandos CMake principales (desde la raíz del proyecto):

```bash
cmake -S . -B build
cmake --build build
```

## Estructura del proyecto

```
.
├─ Core/
│  ├─ process.cpp
│  ├─ process.h
│  └─ algorithms/
│     ├─ fcfs.*
│     ├─ priority.*
│     ├─ round_robin.*
│     └─ sjf.*
├─ Utils/
│  ├─ process_generator.*
├─ docs/
├─ imagenes/
├─ main.cpp
├─ mainwindow.*
└─ CMakeLists.txt
```

## Documentación

La documentación del proyecto se encuentra en la carpeta `docs/`

## Notas

- Si cambias la ruta de Qt o del compilador, vuelve a configurar CMake

## Licencia

Proyecto desarrollado para uso académico
