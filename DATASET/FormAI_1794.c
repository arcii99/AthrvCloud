//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 22
#define COLS 19

int row, col;
int score = 0;

char maze[ROWS][COLS] = {
    {"###################"},
    {"#...........#.....#"},
    {"#.###.#####.#.###.#"},
    {"#.#...#...#...#...#"},
    {"#.#.###.#.#.#.#.#.#"},
    {"#.#.#...#...#...#.#"},
    {"#.....#.#.#.#.#.#.#"},
    {"#.###.#.#.#.#.#.#.#"},
    {"#...#.#.#.#.#.#.#.#"},
    {"###.#.#.#.#.#.#.#.#"},
    {"#...#.#.#.#.#.#...#"},
    {"#.#.#.#.#.#.#.#.#.#"},
    {"#.#...#.#.#.#...#.#"},
    {"#.#.#.#.#.#.#.#.#.#"},
    {"#...#.#...#...#.#.#"},
    {"#.#.#.#.#.#.#.#.#.#"},
    {"#.#...#...#...#.#.#"},
    {"#.#.#.#.#.#.#.#.#.#"},
    {"#...#.#.#.#.#.#...#"},
    {"#.#.#.#.#.#.#.#.#.#"},
    {"#.................#"},
    {"###################"}
};

void displayMaze() {
    system("clear");
    printf("\nYour Score: %d\n", score);
  for (row = 0; row < ROWS; row++) {
    for (col = 0; col < COLS; col++) {
        printf("%c", maze[row][col]);
    }
    printf("\n");
  }
}

void move(char input) {
    switch(input) {
        case 'a': //move left
            if (maze[row][col-1] != '#') {
                if (maze[row][col-1] == '.') {
                    score += 10;
                }
                maze[row][col] = ' ';
                col--;
                maze[row][col] = 'C';
            }
            break;

        case 'w': //move up
            if (maze[row-1][col] != '#') {
                if (maze[row-1][col] == '.') {
                score += 10;
                }
                maze[row][col] = ' ';
                row--;
                maze[row][col] = 'C';
            }
            break;

        case 'd': //move right
            if (maze[row][col+1] != '#') {
                if (maze[row][col+1] == '.') {
                    score += 10;
                }
                maze[row][col] = ' ';
                col++;
                maze[row][col] = 'C';
            }
        break;

        case 's': //move down
            if (maze[row+1][col] != '#') {
                if (maze[row+1][col] == '.') {
                    score += 10;
                }
                maze[row][col] = ' ';
                row++;
                maze[row][col] = 'C';
            }
        break;
    }   
    displayMaze();
}

void initialize() { //initialize the game by placing the player in the maze
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            if (maze[row][col] == 'C') {
                maze[row][col] = ' ';
            }
            else if (maze[row][col] == '.') {
                score += 10;
            }
        }
    }
    row = 10;
    col = 9;
    maze[row][col] = 'C';
    displayMaze();
}

int main() {
    char input;

    initialize();

    while (1) {
        input = getchar();
        move(input);
    }
}