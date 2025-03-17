# Tic-Tac-Toe Game

## Description
This project is a simple **Tic-Tac-Toe game** implemented in C, designed for two players to play against each other on a 3x3 board. The game tracks the score of each player and allows replaying multiple rounds.

## Features
- Two-player game with alternating turns (Player X and Player O).
- Continuous score tracking for both players.
- Detection of win, loss, and draw conditions.
- Option to replay the game as many times as desired.
- User-friendly console-based interface.

## How to Play
1. The game starts with an empty 3x3 board.
2. Players take turns entering the row and column number (1 to 3) where they want to place their mark (X or O).
3. The board updates after every valid move.
4. The game declares a winner if a player aligns three of their marks horizontally, vertically, or diagonally.
5. The game declares a draw if all cells are filled without any winner.
6. Players are prompted to play again or exit after each game.

## Compilation and Execution
Compile the code using the following command:
```
gcc -o TicTacToe TicTacToe.c
```
Run the executable:
```
./TicTacToe
```

## Example Gameplay
```
Current Board:
   X │ O │ X
  ═══╪═══╪═══
   O │ X │ O
  ═══╪═══╪═══
   X │   │ O

Player X wins!
```

## Future Improvements
- Implementing AI for single-player mode.
- Enhancing the UI for a better visual experience.
- Adding input validation and move hints.

