//FormAI DATASET v1.0 Category: Game of Life ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 50
#define COLS 50

void initializeBoard(int board[ROWS][COLS]) {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = rand()%2;
        }
    }
}

void printBoard(int board[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%c", board[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
}

int countNeighbors(int board[ROWS][COLS], int row, int col) {
    int count = 0;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            if(!(i==0 && j==0)) {
                int r = (row+i+ROWS) % ROWS;
                int c = (col+j+COLS) % COLS;
                count += board[r][c];
            }
        }
    }
    return count;
}

void updateBoard(int board[ROWS][COLS]) {
    int nextBoard[ROWS][COLS];
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int neighbors = countNeighbors(board, i, j);
            if(board[i][j] && (neighbors == 2 || neighbors == 3))
                nextBoard[i][j] = 1;
            else if(!board[i][j] && neighbors == 3)
                nextBoard[i][j] = 1;
            else
                nextBoard[i][j] = 0;
        }
    }
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = nextBoard[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS];
    initializeBoard(board);
    while(1) {
        system("clear"); //clear screen on UNIX systems
        printBoard(board);
        updateBoard(board);
        usleep(300000); //pause for 300 milliseconds
    }    
    return 0;
}