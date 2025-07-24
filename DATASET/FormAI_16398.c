//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void generateMaze(int maze[ROWS][COLS]) {
    // Set the borders of the maze
    for (int i = 0; i < ROWS; i++) {
        maze[i][0] = 1;
        maze[i][COLS-1] = 1;
    }
    for (int i = 0; i < COLS; i++) {
        maze[0][i] = 1;
        maze[ROWS-1][i] = 1;
    }
    
    // Set the rest of the maze randomly
    for (int i = 1; i < ROWS-1; i++) {
        for (int j = 1; j < COLS-1; j++) {
            maze[i][j] = rand()%2;
        }
    }
}

void printMaze(int maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf("X ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int maze[ROWS][COLS];
    
    generateMaze(maze);
    printMaze(maze);
    
    return 0;
}