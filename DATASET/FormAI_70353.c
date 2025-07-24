//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 21
#define COLS 21

void generateMaze(int maze[ROWS][COLS]);

int main() {
    int maze[ROWS][COLS];
    srand(time(NULL));
    generateMaze(maze);
    printf("Generated Maze:\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(maze[i][j] == 0) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}

void generateMaze(int maze[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(i == 0 || j == 0 || i == ROWS-1 || j == COLS-1) maze[i][j] = 0;
            else maze[i][j] = 1;
        }
    }
    for(int i=2; i<ROWS-1; i+=2) {
        for(int j=2; j<COLS-1; j+=2) {
            maze[i][j] = 0;
            int d = rand()%4;
            if(d == 0 && i > 1) maze[i-1][j] = 0;
            else if(d == 1 && j < COLS-2) maze[i][j+1] = 0;
            else if(d == 2 && i < ROWS-2) maze[i+1][j] = 0;
            else if(d == 3 && j > 1) maze[i][j-1] = 0;
            else continue;
        }
    }
}