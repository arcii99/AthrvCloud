//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// Function to generate random number
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print the maze
void printMaze(int maze[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to create the maze
void createMaze(int maze[SIZE][SIZE], int startX, int startY) {
    maze[startX][startY] = 1;
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    srand(time(NULL));
    for (int i = 0; i < 4; i++) {
        int direction = getRandomNumber(0, 3);
        int newX = startX + directions[direction][0];
        int newY = startY + directions[direction][1];
        if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE && maze[newX][newY] == 0) {
            maze[newX][newY] = 1;
            createMaze(maze, newX, newY);
        }
    }
}

int main() {
    int maze[SIZE][SIZE] = {0};
    createMaze(maze, 0, 0);
    printMaze(maze);
    return 0;
}