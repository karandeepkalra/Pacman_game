#Pacman Game
Welcome to the Pacman game! This project is a simple implementation of the classic Pacman game using the C programming language. The game features a maze where Pacman navigates to collect items while avoiding ghosts.

#Overview
In this game:

Pacman is represented by @.
Objectives are represented by ^.
Ghosts are represented by &.
Walls are represented by *.
The goal is to collect all the objectives while avoiding the ghosts. If Pacman touches a ghost, the game ends.

#Files
pacman.c: The main source code file containing the game's logic and implementation.
my_lib.h: The header file declaring the functions used in the game.
my_lib.c: The implementation of the functions declared in my_lib.h.

#Controls
w: Move up
s: Move down
a: Move left
d: Move right
q: Quit the game


#How to Play
Start the game by compiling and running the pacman binary.
Use the controls to move Pacman around the maze.
Collect all the ^ objectives while avoiding the & ghosts.
The game ends when Pacman touches a ghost or all objectives are collected.


#Game Functions
update_screen: Clears the console and prints the current state of the maze.
ghost_add_col: Moves a ghost to the right if possible.
ghost_min_col: Moves a ghost to the left if possible.
ghost_add_row: Moves a ghost down if possible.
ghost_min_row: Moves a ghost up if possible.

#Notes
The game is designed to be run in a console environment.
The system("cls") command is used to clear the console screen on Windows. For other operating systems, you might need to replace this with the appropriate command (e.g., system("clear") for Unix-like systems).


#This project is created by Karandeep Kaur

#Cloning the Repository
To clone this repository to your local machine, use the following command:
https://github.com/karandeepkalra/Pacman_game.git

