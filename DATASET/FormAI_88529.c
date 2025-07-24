//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

enum direction { UP, DOWN, LEFT, RIGHT };

int grid[ROWS][COLS];

void printMaze() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(grid[i][j] == 1) {
                printf(" ");
            } else {
                printf("█");
            }
        }
        printf("\n");
    }
}

int isValidMove(int x, int y, enum direction dir) {
    switch(dir) {
        case UP:
            if(x-2 <= 0 || grid[x-2][y] == 0) return 0;
            break;
        case DOWN:
            if(x+2 >= ROWS-1 || grid[x+2][y] == 0) return 0;
            break;
        case LEFT:
            if(y-2 <= 0 || grid[x][y-2] == 0) return 0;
            break;
        case RIGHT:
            if(y+2 >= COLS-1 || grid[x][y+2] == 0) return 0;
            break;
    }
    
    return 1;
}

int countValidMoves(int x, int y) {
    int count = 0;
    
    if(isValidMove(x, y, UP)) count++;
    if(isValidMove(x, y, DOWN)) count++;
    if(isValidMove(x, y, LEFT)) count++;
    if(isValidMove(x, y, RIGHT)) count++;
    
    return count;
}

void digTunnel(int x, int y) {
    grid[x][y] = 1;
    int moves[4] = {0, 1, 2, 3};
    srand(time(NULL));
    
    for(int i=0; i<4; i++) {
        int r = rand() % 4;
        int temp = moves[r];
        moves[r] = moves[i];
        moves[i] = temp;
    }
    
    for(int i=0; i<4; i++) {
        int direction = moves[i];
        if(isValidMove(x, y, direction)) {
            switch(direction) {
                case UP:
                    grid[x-1][y] = 1;
                    digTunnel(x-2, y);
                    break;
                case DOWN:
                    grid[x+1][y] = 1;
                    digTunnel(x+2, y);
                    break;
                case LEFT:
                    grid[x][y-1] = 1;
                    digTunnel(x, y-2);
                    break;
                case RIGHT:
                    grid[x][y+1] = 1;
                    digTunnel(x, y+2);
                    break;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int startX = rand() % ROWS;
    startX = startX | 0x01;
    int startY = rand() % COLS;
    startY = startY | 0x01;
    
    digTunnel(startX, startY);
    printMaze();
    
    return 0;
}