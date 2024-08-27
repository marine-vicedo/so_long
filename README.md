# So Long

## Overview

This project is a simple 2D game designed to help you practice using textures, sprites, and some basic gameplay elements. The goal is to create a game using the MiniLibX library, where the player controls a character that must collect items and reach the exit. The theme and characters are customizable, so feel free to get creative!

## Objectives

- Learn how to manage windows and events.
- Work with colors and textures.
- Gain experience with the MiniLibX library.
- Improve your C programming skills and algorithmic thinking.
- Adhere to coding standards and project requirements.

## Game Rules

- The player must collect all items on the map and then reach the exit using the shortest possible path.
- The character moves using the W, A, S, and D keys (up, left, down, right).
- Movement is restricted to avoid walls.
- Every movement should be counted and displayed in the shell.
- The game is viewed from a 2D perspective (top-down or side view).
- The game does not need to be in real-time.

## Project Requirements

- The program must handle window events such as closing via the ESC key or the window's close button.
- The game must take a map file (with the `.ber` extension) as an argument to define the game layout.

## Map Specifications

- The map consists of walls, collectible items, empty spaces, a starting position, and at least one exit.
- Map symbols:
  - `0` for an empty space
  - `1` for a wall
  - `C` for a collectible item
  - `E` for an exit
  - `P` for the player’s starting position
- The map must be rectangular, enclosed by walls, and contain at least one exit, one item, and one starting position.
- If the map contains duplicates or is not properly configured, an error message should be displayed.


## Getting Started

1. Clone the repository to your local machine.
2. Install the MiniLibX library if not already available on your system.
3. Compile the project using the provided Makefile.
4. Run the game with a `.ber` map file as an argument.

Example command to run the game:
```bash
./so_long path/to/map.ber


