//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 15

void generateMaze(char maze[ROWS][COLS]);
void printMaze(char maze[ROWS][COLS]);

int main() {

    char maze[ROWS][COLS];
    generateMaze(maze);
    printMaze(maze);

    return 0;
}

void generateMaze(char maze[ROWS][COLS]) {

    int i, j;

    // Set all cells as walls
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            maze[i][j] = '#';
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate random start and end points
    int start_row = rand() % ROWS;
    int start_col = rand() % COLS;

    int end_row = rand() % ROWS;
    int end_col = rand() % COLS;

    // Set start and end points
    maze[start_row][start_col] = 'S';
    maze[end_row][end_col] = 'E';

    // Generate random paths until end point is reached
    int current_row = start_row;
    int current_col = start_col;

    while(current_row != end_row || current_col != end_col) {

        // Generate random direction
        int direction = rand() % 4;

        // Move in direction if possible
        switch(direction) {

            // Move up
            case 0:
                if(current_row > 0 && maze[current_row - 1][current_col] == '#') {
                    maze[--current_row][current_col] = ' ';
                }
                break;

            // Move down
            case 1:
                if(current_row < ROWS - 1 && maze[current_row + 1][current_col] == '#') {
                    maze[++current_row][current_col] = ' ';
                }
                break;

            // Move left
            case 2:
                if(current_col > 0 && maze[current_row][current_col - 1] == '#') {
                    maze[current_row][--current_col] = ' ';
                }
                break;

            // Move right
            case 3:
                if(current_col < COLS - 1 && maze[current_row][current_col + 1] == '#') {
                    maze[current_row][++current_col] = ' ';
                }
                break;
        }
    }
}

void printMaze(char maze[ROWS][COLS]) {

    int i, j;

    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(maze[i][j] == '#') {
                printf("█ ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}