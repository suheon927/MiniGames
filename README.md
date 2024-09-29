# MiniGames

A collection of mini-games implemented in C language. This repository includes various simple games that demonstrate basic programming concepts and provide fun interactions.

## Games Included

### 1. Hangman
- **Description**: A classic word-guessing game where players try to guess a hidden word by suggesting letters within a certain number of attempts.
- **How to Play**: 
  1. The player starts with a certain number of incorrect guesses.
  2. Players guess letters one at a time.
  3. If the letter is in the word, it will be revealed; if not, the player loses an attempt.
- **File**: [Hangman](hangman/hangman.c)

### 2. Tic-Tac-Toe
- **Description**: A simple two-player game where players take turns marking a space in a 3x3 grid with 'X' or 'O'.
- **How to Play**:
  1. Players take turns to place their marks in an empty cell.
  2. The first player to align three of their marks horizontally, vertically, or diagonally wins.
- **File**: [TicTacToe](TicTacToe/tictactoe.c)

### 3. Snake
- **Description**: A simple console-based version of the classic Snake game where players control a snake to eat food and grow longer.
- **How to Play**:
  1. Use the arrow keys to control the direction of the snake.
  2. The snake grows longer each time it eats food.
  3. The game ends if the snake runs into itself or the boundaries.
- **File**: [Snake](Snake/snake.c)

## Getting Started

To compile and run the games, you can use the provided Makefile or compile each game manually using the following commands:

```bash
# Example for Hangman
gcc Hangman/hangman.c -o hangman
./hangman
