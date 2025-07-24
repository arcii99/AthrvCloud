//FormAI DATASET v1.0 Category: Game of Life ; Style: Ada Lovelace
#include <stdio.h>

#define ROWS 20
#define COLS 20

void printBoard(int board[ROWS][COLS]);
void nextGen(int board[ROWS][COLS]);

int main() {
    int board[ROWS][COLS] = {0};

    board[8][9] = 1;
    board[9][10] = 1;
    board[10][8] = 1;
    board[10][9] = 1;
    board[10][10] = 1;

    printf("Starting board:\n");
    printBoard(board);
    
    for (int i = 0; i < 100; i++) {
        printf("Generation %d:\n", i+1);
        nextGen(board);
        printBoard(board);
    }

    return 0;
}

void printBoard(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("* ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void nextGen(int board[ROWS][COLS]) {
    int newBoard[ROWS][COLS] = {0};

    for (int i = 1; i < ROWS-1; i++) {
        for (int j = 1; j < COLS-1; j++) {
            int neighbours = 0;

            if (board[i-1][j-1] == 1) neighbours++;
            if (board[i-1][j] == 1) neighbours++;
            if (board[i-1][j+1] == 1) neighbours++;
            if (board[i][j-1] == 1) neighbours++;
            if (board[i][j+1] == 1) neighbours++;
            if (board[i+1][j-1] == 1) neighbours++;
            if (board[i+1][j] == 1) neighbours++;
            if (board[i+1][j+1] == 1) neighbours++;

            if (board[i][j] == 1 && (neighbours == 2 || neighbours == 3)) {
                newBoard[i][j] = 1;
            } else if (board[i][j] == 0 && neighbours == 3) {
                newBoard[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}