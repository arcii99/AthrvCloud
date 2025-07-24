//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 25

char maze[ROWS][COLS];

void initMaze();
void generateMaze();
void printMaze();

int main() {
    srand(time(NULL));
    initMaze();
    generateMaze();
    printMaze();
    return 0;
}

void initMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || j == 0 || i == ROWS - 1 || j == COLS - 1) {
                maze[i][j] = '*';
            } else {
                maze[i][j] = ' ';
            }
        }
    }
}

void generateMaze() {
    int current_row = 2;
    int current_col = 2;
    int direction;
    int new_row;
    int new_col;
    while (1) {
        maze[current_row][current_col] = ' ';
        direction = rand() % 4;
        if (direction == 0) { // up
            new_row = current_row - 1;
            new_col = current_col;
        } else if (direction == 1) { // right
            new_row = current_row;
            new_col = current_col + 1;
        } else if (direction == 2) { // down
            new_row = current_row + 1;
            new_col = current_col;
        } else { // left
            new_row = current_row;
            new_col = current_col - 1;
        }
        if (maze[new_row][new_col] == '*') {
            continue;
        }
        if (new_row == ROWS - 2 && new_col == COLS - 2) {
            break;
        }
        if (maze[new_row - 1][new_col] == ' ' && maze[new_row + 1][new_col] == ' ' && maze[new_row][new_col - 1] == '*' && maze[new_row][new_col + 1] == '*') {
            continue;
        }
        if (maze[new_row - 1][new_col] == '*' && maze[new_row + 1][new_col] == '*' && maze[new_row][new_col - 1] == ' ' && maze[new_row][new_col + 1] == ' ') {
            continue;
        }
        if (maze[new_row][new_col] == ' ') {
            continue;
        }
        if (direction == 0) {
            maze[current_row - 1][current_col] = ' ';
        } else if (direction == 1) {
            maze[current_row][current_col + 1] = ' ';
        } else if (direction == 2) {
            maze[current_row + 1][current_col] = ' ';
        } else {
            maze[current_row][current_col - 1] = ' ';
        }
        current_row = new_row;
        current_col = new_col;
    }
    maze[ROWS - 2][COLS - 2] = ' ';
}

void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}