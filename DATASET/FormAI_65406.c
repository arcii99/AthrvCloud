//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10

int maze[MAZE_SIZE][MAZE_SIZE];

void generateMaze(int row, int col) {
    maze[row][col] = 1;

    int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int shuffledDirections[4][2] = {{0}};

    for(int i = 0; i < 4; i++) {
        int randDir = rand() % 4;
        int tempRow = row + directions[randDir][0];
        int tempCol = col + directions[randDir][1];

        if(tempRow >= 0 && tempRow < MAZE_SIZE && tempCol >= 0 && tempCol < MAZE_SIZE && maze[tempRow][tempCol] == 0) {
            shuffledDirections[i][0] = tempRow;
            shuffledDirections[i][1] = tempCol;
        } else {
            shuffledDirections[i][0] = -1;
            shuffledDirections[i][1] = -1;
        }
    }

    for(int i = 0; i < 4; i++) {
        if(shuffledDirections[i][0] != -1 && shuffledDirections[i][1] != -1) {
            generateMaze(shuffledDirections[i][0], shuffledDirections[i][1]);
        }
    }
}

void printMaze() {
    printf("Sherlock Holmes is solving the following maze:\n");
    for(int i = 0; i < MAZE_SIZE; i++) {
        for(int j = 0; j < MAZE_SIZE; j++) {
            if(maze[i][j] == 1) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    generateMaze(0, 0);
    printMaze();
    return 0;
}