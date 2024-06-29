# Space-Shooter-console-based-game-in-c++

# Plane Shooter Game

## Overview

Plane Shooter Game is a simple console-based game where the player controls a plane, navigating through the screen, shooting at enemies, and avoiding attacks. The objective is to score points by destroying enemy targets while maintaining the plane's health. The game has two stages, with increasing difficulty and different enemy behaviors.

## Features

- **Player Controls**: Move the plane using `W`, `A`, `S`, `D` keys and shoot using the spacebar.
- **Enemies**: Enemies appear randomly on the screen and attack the player's plane.
- **Stages**: Two stages with varying enemy movement and attack patterns.
- **Scoring**: Points are awarded for destroying enemies, and the game is won by reaching a certain score.
- **Health**: The player has a limited amount of health which decreases when hit by enemies.

## How to Play

1. **Run the Game**: Compile and run the `main.cpp` file using a C++ compiler.
2. **Controls**:
    - `W`: Move up
    - `A`: Move left
    - `S`: Move down
    - `D`: Move right
    - `Spacebar`: Shoot
3. **Objective**: Destroy enemies and avoid getting hit. Reach a score of 30 points to win the game.
4. **Stages**: The game consists of two stages. Stage 2 begins once the player reaches 20 points.

## Code Explanation

### Main Components

- **Global Variables**: Define the game constants, game board, player health, and points.
- **`boarders` Function**: Initializes the game board with borders and the plane's initial position.
- **`frontscreen` Function**: Displays the game board on the console.
- **`planemove` Function**: Handles player movement based on input.
- **`enemyloc` Function**: Checks if there are enemies on the board.
- **`enemies` Function**: Generates enemies at random positions.
- **`enemyattack` Function**: Handles enemy attacks.
- **`fireplacement` Function**: Manages enemy fire movement.
- **`planefiring` Function**: Manages the player's plane firing mechanics.
- **`enemymovement2` Function**: Handles the second stage's enemy movements.
- **`main` Function**: Game loop handling stages, movement, attacks, and rendering.

### Compilation and Execution

Ensure you have a C++ compiler installed. Open your terminal or command prompt and navigate to the directory containing `main.cpp`. Then, compile and run the game using:

```sh
g++ -o PlaneShooterGame main.cpp
./PlaneShooterGame
```

### Dependencies

The game uses the following libraries:
- `<iostream>`: Standard input-output stream.
- `<cstdlib>`: For random number generation.
- `<cmath>`: For mathematical functions.
- `<ctime>`: For seeding the random number generator.
- `<conio.h>`: For `getch` function (Windows only).
- `<windows.h>`: For `system("CLS")` (Windows only).

### Known Issues

- The game is designed for Windows due to the use of `<conio.h>` and `<windows.h>`. Compatibility issues may arise on other operating systems.
- The game screen may flicker due to the use of `system("CLS")` for clearing the screen.

### Future Improvements

- Enhance cross-platform compatibility.
- Improve graphics and UI using a graphical library.
- Add more stages and enemy types.
- Implement sound effects.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

---

Feel free to customize the README file to better fit your needs and add any additional information that might be useful for users or contributors.
