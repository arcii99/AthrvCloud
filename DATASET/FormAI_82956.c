//FormAI DATASET v1.0 Category: Game of Life ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 30
#define GENERATIONS 30

void initializeBoard(int board[ROWS][COLS]) {
    int i, j;

    srand(time(NULL));

    for(i=0;i<ROWS;i++) {
        for(j=0;j<COLS;j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void printBoard(int board[ROWS][COLS], int generation) {
    int i, j;

    printf("=== GENERATION %d ===\n", generation);

    for(i=0;i<ROWS;i++) {
        for(j=0;j<COLS;j++) {
            if(board[i][j]) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int countLiveNeighbors(int board[ROWS][COLS], int row, int col) {
    int i, j, count=0;

    for(i=row-1;i<=row+1;i++) {
        for(j=col-1;j<=col+1;j++) {
            if(i<0 || i>=ROWS || j<0 || j>=COLS || (i==row && j==col)) {
                continue;
            }

            if(board[i][j]) {
                count++;
            }
        }
    }

    return count;
}

void advanceGeneration(int board[ROWS][COLS]) {
    int i, j;
    int liveNeighbors;

    int newBoard[ROWS][COLS];

    for(i=0;i<ROWS;i++) {
        for(j=0;j<COLS;j++) {
            liveNeighbors = countLiveNeighbors(board, i, j);

            if(board[i][j] && (liveNeighbors==2 || liveNeighbors==3)) {
                newBoard[i][j] = 1;
            } else if(!board[i][j] && liveNeighbors==3) {
                newBoard[i][j] = 1;
            } else {
                newBoard[i][j] = 0;
            }
        }
    }

    for(i=0;i<ROWS;i++) {
        for(j=0;j<COLS;j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS];
    int i;

    initializeBoard(board);

    printBoard(board, 0);

    for(i=1;i<=GENERATIONS;i++) {
        advanceGeneration(board);
        printBoard(board, i);
    }

    return 0;
}