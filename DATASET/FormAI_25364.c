//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void generateMaze(int[][SIZE]);
void printMaze(int[][SIZE]);

int main(void) {
    int maze[SIZE][SIZE];

    srand(time(NULL)); // set seed to current time

    generateMaze(maze);
    printMaze(maze);

    return 0;
}

void generateMaze(int maze[][SIZE]) {
    int i, j;

    // set all cells to 1 (visited) initially
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            maze[i][j] = 1;
        }
    }

    // randomly set starting position
    int current_row = rand() % SIZE;
    int current_col = rand() % SIZE;
    maze[current_row][current_col] = 0; // mark as visited

    // randomly generate maze
    while (1) {
        int direction = rand() % 4; // 0: north, 1: east, 2: south, 3: west
        
        if (direction == 0 && current_row > 0) { // move north if possible
            current_row--;
            if (maze[current_row][current_col] == 1) { // if new cell not visited
                maze[current_row][current_col] = 0; // mark as visited
                current_row++;
            }
        } else if (direction == 1 && current_col < SIZE - 1) { // move east if possible
            current_col++;
            if (maze[current_row][current_col] == 1) { // if new cell not visited
                maze[current_row][current_col] = 0; // mark as visited
                current_col--;
            }
        } else if (direction == 2 && current_row < SIZE - 1) { // move south if possible
            current_row++;
            if (maze[current_row][current_col] == 1) { // if new cell not visited
                maze[current_row][current_col] = 0; // mark as visited
                current_row--;
            }
        } else if (direction == 3 && current_col > 0) { // move west if possible
            current_col--;
            if (maze[current_row][current_col] == 1) { // if new cell not visited
                maze[current_row][current_col] = 0; // mark as visited
                current_col++;
            }
        }

        // if no possible moves in all directions, end maze generation
        if (maze[current_row-1][current_col] == 0 && maze[current_row+1][current_col] == 0 && maze[current_row][current_col-1] == 0 && maze[current_row][current_col+1] == 0) {
            break;
        }
    }
}

void printMaze(int maze[][SIZE]) {
    int i, j;

    printf(" ");
    for (i = 0; i < SIZE; i++) {
        printf("__");
    }
    printf("\n");

    for (i = 0; i < SIZE; i++) {
        printf("|");

        for (j = 0; j < SIZE; j++) {

            if (maze[i][j] == 1) {
                printf("##");
            } else {
                printf("  ");
            }
            printf("|");
        }
        printf("\n");

        if (i == SIZE - 1) {
            printf(" ");
            for (j = 0; j < SIZE; j++) {
                printf("__");
            }
            printf("\n");
        }
    }
}