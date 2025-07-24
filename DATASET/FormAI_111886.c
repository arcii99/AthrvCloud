//FormAI DATASET v1.0 Category: Game of Life ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 10
#define COL 10

void initializeGrid(int grid[ROW][COL]) {
    int i, j;
    for(i=0; i<ROW; i++) {
        for(j=0; j<COL; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void printGrid(int grid[ROW][COL]) {
    int i, j;
    for(i=0; i<ROW; i++) {
        for(j=0; j<COL; j++) {
            if(grid[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("------------------------\n");
}

int checkNeighbours(int grid[ROW][COL], int x, int y) {
    int aliveNeighbours = 0;
    int i, j;
    for(i=x-1; i<=x+1; i++) {
        for(j=y-1; j<=y+1; j++) {
            if(i<0 || j<0 || i>=ROW || j>=COL) {
                continue;
            }
            if(i==x && j==y) {
                continue;
            }
            if(grid[i][j]) {
                aliveNeighbours++;
            } 
        }
    }
    return aliveNeighbours;
}

void playGame(int grid[ROW][COL]) {
    int newGrid[ROW][COL];
    int i, j, aliveNeighbours;
    for(i=0; i<ROW; i++) {
        for(j=0; j<COL; j++) {
            aliveNeighbours = checkNeighbours(grid, i, j);
            if(grid[i][j]) {
                if(aliveNeighbours < 2 || aliveNeighbours > 3) {
                    newGrid[i][j] = 0;
                } else {
                    newGrid[i][j] = 1;
                }
            } else {
                if(aliveNeighbours == 3) {
                    newGrid[i][j] = 1;
                } else {
                    newGrid[i][j] = 0;
                }
            }
        }
    }
    for(i=0; i<ROW; i++) {
        for(j=0; j<COL; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    int grid[ROW][COL];
    srand(time(NULL));
    initializeGrid(grid);
    while(1) {
        system("clear");
        printGrid(grid);
        playGame(grid);
    }
    return 0;
}