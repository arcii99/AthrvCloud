//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 15
#define COL 15

void generateMaze(int maze[][COL]);
void printMaze(int maze[][COL]);

int main(void) {
    int maze[ROW][COL];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}

void generateMaze(int maze[][COL]) {
    // Initialize maze to all walls
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            maze[i][j] = 1;
        }
    }
    // Randomly generate entrance and exit
    int entrance = rand() % COL;
    maze[0][entrance] = 0;
    int exit = rand() % COL;
    maze[ROW-1][exit] = 0;
    // Randomly generate maze paths
    srand(time(NULL));
    for (int i = 1; i < ROW-1; i++) {
        for (int j = 1; j < COL-1; j++) {
            if (i % 2 == 1 && j % 2 == 1) { // Only consider odd indices for path
                if (rand() % 2 == 1) { // 50% chance of breaking wall horizontally
                    maze[i][j+1] = 0;
                } else { // 50% chance of breaking wall vertically
                    maze[i+1][j] = 0;
                }
            }
        }
    }
}

void printMaze(int maze[][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (maze[i][j] == 1) { // Wall
                printf("█");
            } else { // Path
                printf(" ");
            }
        }
        printf("\n");
    }
}