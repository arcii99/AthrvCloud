//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 80

void initializeBoard(char board[][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            board[i][j] = '#';
        }
    }
}

void printBoard(char board[][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void carvePath(char board[][COLS], int startX, int startY, int direction) {
    if(startX < 1 || startY < 1 || startX > ROWS-2 || startY > COLS-2) {
        return;
    }
    if(board[startX][startY] == '.') {
        return;
    }
    board[startX][startY] = '.';
    int r = rand() % 100;
    if(direction == 0) {
        if(r < 50) {
            carvePath(board, startX-1, startY, direction);
        } else {
            carvePath(board, startX+1, startY, direction);
        }
    } else {
        if(r < 50) {
            carvePath(board, startX, startY-1, direction);
        } else {
            carvePath(board, startX, startY+1, direction);
        }
    }
}

void generatePaths(char board[][COLS], int numOfPaths) {
    int i;
    for(i = 0; i < numOfPaths; i++) {
        int startX = rand() % (ROWS-2) + 1;
        int startY = rand() % (COLS-2) + 1;
        int direction = rand() % 2;
        carvePath(board, startX, startY, direction);
    }
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    initializeBoard(board);
    generatePaths(board, 50);
    printBoard(board);
    return 0;
}