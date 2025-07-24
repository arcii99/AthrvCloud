//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW_SIZE 20
#define COL_SIZE 40

// Function to initialize the maze with random obstacles
void initializeMaze(char maze[][COL_SIZE]) {
    srand(time(NULL));

    for(int i=0; i<ROW_SIZE; i++) {
        for(int j=0; j<COL_SIZE; j++) {
            int randNum = rand() % 100;
            if(randNum < 30) {
                maze[i][j] = 'X';
            } else {
                maze[i][j] = '-';
            }
        }
    }
}

// Function to print the maze on the screen
void printMaze(char maze[][COL_SIZE]) {
    for(int i=0; i<ROW_SIZE; i++) {
        for(int j=0; j<COL_SIZE; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Recursive function to find route to the target
void findRoute(char maze[][COL_SIZE], int row, int col, int destRow, int destCol, int visited[][COL_SIZE]) {
    if(row == destRow && col == destCol) {
        maze[row][col] = '*';
        return;
    }

    if(row<0 || row>=ROW_SIZE || col<0 || col>=COL_SIZE || maze[row][col]=='X' || visited[row][col]) {
        return;
    }

    visited[row][col] = 1;

    maze[row][col] = '*';

    findRoute(maze, row+1, col, destRow, destCol, visited);
    findRoute(maze, row-1, col, destRow, destCol, visited);
    findRoute(maze, row, col+1, destRow, destCol, visited);
    findRoute(maze, row, col-1, destRow, destCol, visited);

    if(maze[destRow][destCol] != '*') {
        maze[row][col] = '-';
    }
}

int main() {
    char maze[ROW_SIZE][COL_SIZE];
    int visited[ROW_SIZE][COL_SIZE] = {0};
    initializeMaze(maze);
    int startX = rand() % ROW_SIZE, startY = rand() % COL_SIZE;
    int destX = rand() % ROW_SIZE, destY = rand() % COL_SIZE;

    printf("Starting point: (%d,%d)\n", startX, startY);
    printf("Destination point: (%d,%d)\n\n", destX, destY);

    maze[startX][startY] = 'S';
    maze[destX][destY] = 'D';

    printMaze(maze);

    printf("\nFinding route...\n\n");

    findRoute(maze, startX, startY, destX, destY, visited);

    printMaze(maze);

    return 0;
}