//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define ROWS 21
#define COLS 35

char gameBoard[ROWS][COLS] = {
  "###############################",
  "#0..............##...........#",
  "#.##.####.#####.##.#####.##.#",
  "#.##.####.#####.##.#####.##.#",
  "#......##....##.##.##....##.#",
  "####.######.##.##.##.######.#",
  "####.######.##.##.##.######.#",
  "#......##....##.##.##....##.#",
  "#.####.#######.##.#######.#.#",
  "#.####.#######.##.#######.#.#",
  "#....##........##........#.##",
  "########.##.########.##.####",
  "########.##.########.##.####",
  "......##.##....##....##.....#",
  "######.#.#####.##.#####.####",
  "######.#.#####.##.#####.####",
  "#.....##.#..##.##.##..#.###.#",
  "#.########.#.#.#.#.#.#.#.#.#",
  "#.########.#.#.#.#.#.#.#.#.#",
  "#.......##.................#",
  "###############################"
};

// Save cursor position and move cursor to row, col location
void gotoxy(int row, int col) {
    printf("\033[%d;%dH", row, col);
}

void init() {
    printf("\e[?25l"); // hide cursor
    printf("\e[2J"); // clear screen
}

// Render gameboard
void render() {
  for(int i = 0; i < ROWS; i++) {
    gotoxy(i+1,1); // goto row i, column 1
    printf("%s", gameBoard[i]);
  }
}

int main() {
  init();
  render();
  return 0;
}