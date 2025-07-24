//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int maze[SIZE][SIZE];
int start = 0, finish = 9;

void makeMaze() {

    int i, j;
    
    // Initialize maze to all walls
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            maze[i][j] = 1;
        }
    }
    
    // Random starting point
    srand(time(NULL));
    int randRow = rand() % SIZE;
    maze[randRow][start] = 0;
    int currCol = start;
    
    // Carve path through maze
    while(currCol != finish) {
        int randNum = rand() % 3;
        if(randNum == 0 && (currCol < SIZE - 1) && (maze[randRow][currCol+1] == 1)) { // Move right
            maze[randRow][currCol+1] = 0;
            currCol++;
        }
        else if(randNum == 1 && (randRow > 0) && (maze[randRow-1][currCol] == 1)) { // Move up
            maze[randRow-1][currCol] = 0;
            randRow--;
        }
        else if(randNum == 2 && (randRow < SIZE - 1) && (maze[randRow+1][currCol] == 1)) { // Move down
            maze[randRow+1][currCol] = 0;
            randRow++;
        }
    }
    
    // Add entrance and exit
    maze[randRow][currCol] = 0;
    maze[rand() % SIZE][finish] = 0;
}

void printMaze() {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(start == j && finish == i) printf("*");
            else if(maze[i][j] == 0) printf(" ");
            else printf("X");
        }
        printf("\n");
    }
}

int main() {
    makeMaze();
    printMaze();
    return 0;
}