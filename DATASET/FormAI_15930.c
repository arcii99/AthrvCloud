//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define PERCENTAGE 30
#define SPACING 2
#define WALL '*'
#define PATH ' '
#define ENEMY 'E'
#define PLAYER 'P'
#define ARTIFACT '@'

void printMap(char map[ROWS][COLS], int score, int steps) {
    printf("\n\nScore: %d\tSteps: %d\n", score, steps);
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%*c", SPACING, map[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

int hasUnvisitedNeighbor(char map[ROWS][COLS], int row, int col) {
    if(row > 0 && map[row-1][col] == PATH) return 1;
    if(row < ROWS-1 && map[row+1][col] == PATH) return 1;
    if(col > 0 && map[row][col-1] == PATH) return 1;
    if(col < COLS-1 && map[row][col+1] == PATH) return 1;
    return 0;
}

void fillMap(char map[ROWS][COLS]) {
    int currentRow = ROWS/2, currentCol = COLS/2;
    int visited = 0;
    int score = 0;
    int steps = 0;
    
    while(!visited) {
        map[currentRow][currentCol] = PATH;
        visited = 1;

        while(hasUnvisitedNeighbor(map, currentRow, currentCol)) {
            int direction = rand() % 4;
            if(direction == 0 && currentRow > 0 && map[currentRow-1][currentCol] == WALL) {
                map[currentRow-1][currentCol] = PATH;
                currentRow--;
            } else if(direction == 1 && currentRow < ROWS-1 && map[currentRow+1][currentCol] == WALL) {
                map[currentRow+1][currentCol] = PATH;
                currentRow++;
            } else if(direction == 2 && currentCol > 0 && map[currentRow][currentCol-1] == WALL) {
                map[currentRow][currentCol-1] = PATH;
                currentCol--;
            } else if(direction == 3 && currentCol < COLS-1 && map[currentRow][currentCol+1] == WALL) {
                map[currentRow][currentCol+1] = PATH;
                currentCol++;
            }
            visited = 0;
        }
    }

    while(score < ROWS*COLS*PERCENTAGE/100) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if(map[row][col] == PATH) {
            int type = rand() % 3;
            if(type == 0) {
                map[row][col] = ENEMY;
            } else if(type == 1) {
                map[row][col] = ARTIFACT;
            } else {
                map[row][col] = PATH;
            } 
        }
        score = 0;
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(map[i][j] != WALL) {
                    score++;
                }
            }
        }
    }

    int playerRow = rand() % ROWS;
    int playerCol = rand() % COLS;
    while(map[playerRow][playerCol] != PATH) {
        playerRow = rand() % ROWS;
        playerCol = rand() % COLS;
    }
    map[playerRow][playerCol] = PLAYER;

    printMap(map, score, steps);
}

int main() {
    srand(time(NULL));
    char map[ROWS][COLS];

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(i == 0 || j == 0 || i == ROWS-1 || j == COLS-1) {
                map[i][j] = WALL;
            } else {
                map[i][j] = PATH;
            }
        }
    }

    fillMap(map);

    return 0;
}