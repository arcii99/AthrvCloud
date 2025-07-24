//FormAI DATASET v1.0 Category: Game of Life ; Style: careful
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROW 20
#define COL 40

void printBoard(int board[ROW][COL]) {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            if(board[i][j] == 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int countLivingNeighbors(int board[ROW][COL], int row, int col) {
    int count = 0;
    for(int i=row-1; i<=row+1; i++) {
        for(int j=col-1; j<=col+1; j++) {
            if(i<0 || j<0 || i>=ROW || j>=COL || (i==row && j==col))
                continue;
            if(board[i][j] == 1)
                count++;
        }
    }
    return count;
}

void updateBoard(int board[ROW][COL]) {
    int newBoard[ROW][COL];
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            int livingNeighbors = countLivingNeighbors(board, i, j);
            if(board[i][j] == 1 && (livingNeighbors<2 || livingNeighbors>3))
                newBoard[i][j] = 0;
            else if(board[i][j] == 0 && livingNeighbors == 3)
                newBoard[i][j] = 1;
            else
                newBoard[i][j] = board[i][j];
        }
    }
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main() {
    int board[ROW][COL];
    srand(time(NULL));
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            board[i][j] = rand()%2;
        }
    }
    while(1) {
        printBoard(board);
        updateBoard(board);
        usleep(100000);
    }
    return 0;
}