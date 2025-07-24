//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define COLS 10
#define ROWS 10

// Global Variables
int maze[ROWS][COLS];
bool visited[ROWS][COLS] = { false };

int directionX[4] = {0, 1, 0, -1};
int directionY[4] = {-1, 0, 1, 0};

// Function Prototypes
void generateMaze(int, int);
bool isValidMove(int, int);
bool allVisited();

// Function Definitions
int main() {
    srand(time(NULL));
    generateMaze(0, 0);

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(maze[i][j] == 0) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    return 0;
}

void generateMaze(int x, int y) {
    maze[y][x] = 0;
    visited[y][x] = true;

    while(!allVisited()) {
        int direction = rand() % 4;
        int newX = x + directionX[direction];
        int newY = y + directionY[direction];

        if(isValidMove(newX, newY) && !visited[newY][newX]) {
            maze[((newY + y) / 2)][((newX + x) / 2)] = 0;
            generateMaze(newX, newY);
        }

        visited[newY][newX] = true;
    }
}

bool isValidMove(int x, int y) {
    if(x >= COLS || x < 0 || y >= ROWS || y < 0) {
        return false;
    }

    if(visited[y][x]) {
        return false;
    }

    return true;
}

bool allVisited() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(!visited[i][j]) {
                return false;
            }
        }
    }
    return true;
}