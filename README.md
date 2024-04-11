# Noughts and Crosses Game (COMP1711 Coursework 2)

This repository contains my coursework submission for COMP1711, implementing a scalable version of the classic game Noughts and Crosses (also known as Tic-Tac-Toe).

## Description

The project is a console-based C application that allows two players to play Noughts and Crosses on a grid that can range from 3x3 to 8x8. The game supports custom winning line lengths, making it a more versatile and challenging version of the traditional 3x3 game.

### Features

- Playable on grids ranging from 3x3 to 8x8.
- Configurable winning line length from 3 up to the grid size.
- Developed to be compiled and run on the school's Linux network using a predefined `Makefile`.

## Installation

To run this game, you need a C compiler and `make` installed on your system. This project was developed to be compatible with the school's Linux network environment.

1. Clone the repository to your local machine.
2. Navigate to the project directory.
3. Compile the project using `make`.

```bash
make
```

## Usage
To start the game, run the compiled executable with optional command-line arguments for grid size and winning line length (defaults to 3x3 grid if no arguments are provided).
```bash
./tictactoe [grid size] [winning line length]
```
For example
```bash
./tictactoe 6 4
```

##Testing

You can test your build using the provided input and output files (game.in and game.out). Compare your program's output with the expected output to ensure accuracy.
```bash
./tictactoe < game.in > myout.txt
diff -y myout.txt game.out
```
##Contributing

This project is part of an academic coursework assignment. Therefore it is not fully mine.
