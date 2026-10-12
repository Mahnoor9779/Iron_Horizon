# Iron Horizon

A Windows console action game built in C++. Navigate a character-based maze, fight enemies, shoot moving targets, and avoid lasers and poison while collecting pills.

## Features

- Real-time keyboard controls and character-based graphics.
- A fixed maze with walls, obstacles, and timed laser hazards.
- Three moving enemies, including an enemy that fires projectiles.
- Four vertically moving, destructible boxes with visible health.
- Shooting to the left, right, and downward.
- Randomly placed collectible pills and poison markers.
- Two bonus pill pickups with collection indicators.
- A side panel showing player health, pill count, poison count, enemy health, and an in-game timer.
- Win and game-over screens.

## Controls

| Key | Action |
| --- | --- |
| Arrow keys | Move up, down, left, or right |
| A | Shoot left |
| D | Shoot right |
| S | Shoot downward |
| Esc | Return to the main menu |

## Gameplay

Start with 100 health. Explore the maze, collect pills, and shoot enemies and moving boxes while avoiding hazards. Each regular pill increases the pill count by one. Collecting three poison markers (`x`) or losing all health ends the game.

The intended objective is to defeat all three enemies and destroy all four boxes. The current victory check has a known issue described below.

## Requirements

- Windows: the game uses `windows.h` and Windows console APIs.
- A C++11-compatible compiler or newer, such as MinGW-w64 GCC.
- A console with approximately 210 columns and 48 rows available. A small font helps fit the maze and side panel on screen.

No external game engine or asset files are required.

## Build and Run

With a Windows MinGW-w64 compiler available in Git Bash, open the folder containing the source and run:

```bash
g++ -std=c++11 "Iron_Horizon(1).cpp" -o Iron_Horizon.exe
./Iron_Horizon.exe
```

If your repository uses `Iron_Horizon.cpp` instead, replace the source filename in the build command. Run the executable in a Windows console and enlarge the window before playing.

## Implementation

The game uses procedural C++ functions, a two-dimensional character array for the maze, arrays for projectiles and collectibles, and random-number generation for item placement. Windows console functions handle cursor positioning, keyboard polling, and screen-cell inspection for collision checks.

## Current Limitations

- Windows-specific; Linux and macOS are not supported by the current implementation.
- Menu option 2 has no implemented action.
- The victory condition checks `enemyHealth3` rather than `enemyHealth3 <= 0`, so victory may trigger incorrectly.
- Two laser counters are not initialized before use, which can affect hazard timing.
- Bonus pills currently update collection indicators; they do not restore player health or implement additional abilities.
- Returning to the menu with Esc does not reset the game state.

## Possible Improvements

- Correct victory checking and initialize all laser counters.
- Implement the second menu option with gameplay instructions.
- Add a consistent restart flow and meaningful bonus-pill effects.
- Add difficulty levels, additional maps, sound effects, and persistent high scores.
- Refactor console rendering and game state for easier maintenance and portability.
