# so_long - Proyecto de 42 School

Un juego 2D simple en C usando minilibx, donde el jugador debe recoger objetos y llegar a la salida.

## Descripción General

Este proyecto implementa un juego 2D básico que muestra un mapa, permite al jugador mover un personaje, recoger objetos y llegar a una salida. Forma parte del plan de estudios de 42 school y demuestra la comprensión de programación gráfica, manejo de eventos y gestión de memoria.

## Características

### Mecánicas del Juego
- Mover el personaje del jugador con las teclas WASD
- Recoger todos los coleccionables antes de llegar a la salida
- Detección de colisión con muros
- Contador de movimientos
- Botón de cerrar ventana y tecla ESC para salir

### Validación del Mapa
- Verificación de extensión de archivo (.ber)
- Validación de mapa rectangular
- Bordes cerrados (muros en todos los bordes)
- Validación de caracteres (exactamente un jugador, una salida, al menos un coleccionable)
- Verificación de alcanzabilidad de caminos (algoritmo flood fill)

### Gráficos
- Renderizado basado en sprites usando archivos XPM
- Movimiento y renderizado suave
- Limpieza adecuada de recursos al salir

## Estructura del Proyecto

```
soLong/
├── src/                    # Archivos fuente
│   ├── main.c             # Punto de entrada e inicialización del juego
│   ├── map_reader.c       # Lectura y análisis de archivos de mapa
│   ├── map_validate.c     # Validación del mapa (dimensiones, bordes, caracteres)
│   ├── map_checker.c      # Verificación de alcanzabilidad de caminos
│   ├── sprites_load.c     # Carga de imágenes
│   ├── game_render.c      # Renderizado del mapa
│   └── player_moves.c     # Movimiento del jugador y manejo de entrada
├── inc/                    # Archivos de cabecera
│   └── so_long.h          # Declaraciones principales
├── maps/                   # Archivos de mapa
│   ├── example.ber        # Mapa de ejemplo
│   ├── shortmap.ber       # Mapa de prueba pequeño
│   └── longmap.ber        # Mapa de prueba grande
├── textures/               # Archivos de sprites
│   ├── player.xpm         # Sprite del jugador
│   ├── wall.xpm           # Sprite del muro
│   ├── floor.xpm          # Sprite del suelo
│   ├── collectable.xpm    # Sprite del coleccionable
│   └── exit.xpm           # Sprite de la salida
├── obj/                    # Objetos compilados (generados)
├── .deps/                  # Dependencias (generadas)
├── Makefile               # Configuración de compilación
└── so_long                # Ejecutable (generado)
```

## Dependencias

Este proyecto depende de:
- [libraryC](https://github.com/Davter17/MyLibrary.git) - Librería personalizada con libft, ft_printf y get_next_line
- [minilibx-linux](https://github.com/42Paris/minilibx-linux.git) - Librería gráfica simple

Ambas se clonan automáticamente durante la compilación.

## Compilación

### Compilación básica
```bash
make
```
Clona dependencias (si es necesario) y compila el juego.

### Compilación limpia
```bash
make re
```
Elimina todos los archivos compilados y recompila todo.

### Limpieza
```bash
make clean    # Elimina el directorio obj/
make fclean   # Elimina obj/, .deps/ y el binario so_long
```

## Uso

```bash
./so_long <archivo_mapa>
```

### Formato del Mapa

Los mapas deben tener la extensión `.ber` y contener:
- `1` - Muro
- `0` - Espacio vacío
- `P` - Posición inicial del jugador (exactamente uno)
- `C` - Coleccionable (al menos uno)
- `E` - Salida (exactamente una)

### Ejemplos

```bash
# Jugar con el mapa de ejemplo
./so_long example.ber

# Jugar con un mapa personalizado
./so_long maps/mimapa.ber
```

### Controles
- `W` - Mover arriba
- `A` - Mover izquierda
- `S` - Mover abajo
- `D` - Mover derecha
- `ESC` - Salir del juego
- Botón cerrar (X) - Salir del juego

## Detalles de Implementación

### Lectura del Mapa
- Usa get_next_line para leer archivos de mapa
- Normaliza finales de línea
- Valida la extensión del archivo antes de procesar

### Validación del Mapa
- Verifica forma rectangular
- Comprueba que todos los bordes son muros
- Valida el conjunto de caracteres (1, 0, P, C, E)
- Asegura exactamente un jugador y una salida
- Confirma al menos un coleccionable existe

### Búsqueda de Caminos
- Algoritmo flood fill para verificar alcanzabilidad
- Comprueba que todos los coleccionables y la salida son accesibles desde el inicio del jugador
- Crea una copia del mapa para evitar modificar el original

### Gestión de Memoria
- Asignación y liberación cuidadosa
- Sin fugas de memoria (verificado con Valgrind)
- Limpieza adecuada en errores y al salir
- Destrucción segura de imágenes y ventanas

## Calidad del Código

- Cumple con los estándares de norminette de 42 school
- Sin fugas de memoria (verificado con Valgrind)
- Maneja casos extremos y condiciones de error
- Separación limpia de responsabilidades
- Gestión adecuada de recursos

## Requisitos

- Compilador GCC
- Make
- Librerías de desarrollo X11 (`libx11-dev`, `libxext-dev`)
- Entorno tipo Unix (Linux, macOS o WSL)

## Ejemplos de Mapas

### Mapa simple (example.ber)
```
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```

## Autores

- **Mario Pico** (@Davter17)

## Licencia

Este proyecto forma parte del plan de estudios de 42 school y sigue sus directrices académicas.
