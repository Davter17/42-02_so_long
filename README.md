# so_long - 42 School Project

A simple 2D game in C using minilibx, where the player must collect items and reach the exit.

## Overview

This project implements a basic 2D game that displays a map, allows the player to move a character, collect items, and reach an exit. It's part of the 42 school curriculum and demonstrates understanding of graphics programming, event handling, and memory management.

## Features

### Game Mechanics
- Move player character with WASD keys
- Collect all collectibles before reaching the exit
- Wall collision detection
- Movement counter display
- Window close button and ESC key to exit

### Map Validation
- File extension check (.ber)
- Rectangular map validation
- Closed borders (walls on all edges)
- Character validation (exactly one player, one exit, at least one collectible)
- Path reachability check (flood fill algorithm)

### Graphics
- Sprite-based rendering using XPM files
- Smooth movement and rendering
- Proper resource cleanup on exit

## Project Structure

```
soLong/
├── src/                    # Source files
│   ├── main.c             # Entry point and game initialization
│   ├── map_reader.c       # Map file reading and parsing
│   ├── map_validate.c     # Map validation (dimensions, borders, characters)
│   ├── map_checker.c      # Path reachability verification
│   ├── sprites_load.c     # Image loading
│   ├── game_render.c      # Map rendering
│   └── player_moves.c     # Player movement and input handling
├── inc/                    # Header files
│   └── so_long.h          # Main declarations
├── maps/                   # Map files
│   ├── example.ber        # Example map
│   ├── shortmap.ber       # Small test map
│   └── longmap.ber        # Large test map
├── textures/               # Sprite files
│   ├── player.xpm         # Player sprite
│   ├── wall.xpm           # Wall sprite
│   ├── floor.xpm          # Floor sprite
│   ├── collectable.xpm    # Collectible sprite
│   └── exit.xpm           # Exit sprite
├── obj/                    # Compiled objects (generated)
├── .deps/                  # Dependencies (generated)
├── Makefile               # Build configuration
└── so_long                # Executable (generated)
```

## Dependencies

This project depends on:
- [libraryC](https://github.com/Davter17/MyLibrary.git) - Custom library with libft, ft_printf, and get_next_line
- [minilibx-linux](https://github.com/42Paris/minilibx-linux.git) - Simple graphics library

Both are automatically cloned during compilation.

## Compilation

### Basic compilation
```bash
make
```
Clones dependencies (if needed) and compiles the game.

### Clean build
```bash
make re
```
Removes all compiled files and recompiles everything.

### Cleaning
```bash
make clean    # Removes obj/ directory
make fclean   # Removes obj/, .deps/, and so_long binary
```

## Usage

```bash
./so_long <map_file>
```

### Map Format

Maps must have the `.ber` extension and contain:
- `1` - Wall
- `0` - Empty space
- `P` - Player start position (exactly one)
- `C` - Collectible (at least one)
- `E` - Exit (exactly one)

### Examples

```bash
# Play with example map
./so_long example.ber

# Play with custom map
./so_long maps/mymap.ber
```

### Controls
- `W` - Move up
- `A` - Move left
- `S` - Move down
- `D` - Move right
- `ESC` - Exit game
- Close button (X) - Exit game

## Implementation Details

### Map Reading
- Uses get_next_line to read map files
- Normalizes line endings
- Validates file extension before processing

### Map Validation
- Checks rectangular shape
- Verifies all borders are walls
- Validates character set (1, 0, P, C, E)
- Ensures exactly one player and exit
- Confirms at least one collectible exists

### Path Finding
- Flood fill algorithm to verify reachability
- Checks that all collectibles and exit are accessible from player start
- Creates a copy of the map to avoid modifying the original

### Memory Management
- Careful allocation and deallocation
- No memory leaks (verified with Valgrind)
- Proper cleanup on errors and exit
- Safe image and window destruction

## Code Quality

- Complies with 42 school's norminette standards
- No memory leaks (verified with Valgrind)
- Handles edge cases and error conditions
- Clean separation of concerns
- Proper resource management

## Requirements

- GCC compiler
- Make
- X11 development libraries (`libx11-dev`, `libxext-dev`)
- Unix-like environment (Linux, macOS, or WSL)

## Map Examples

### Simple map (example.ber)
```
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```

## Authors

- **Mario Pico** (@Davter17)

## License

This project is part of the 42 school curriculum and follows its academic guidelines.
