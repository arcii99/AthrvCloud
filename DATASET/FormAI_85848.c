//FormAI DATASET v1.0 Category: Game of Life ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ROWS 40
#define COLS 100

void printBoard(int board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] == 1) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void updateBoard(int board[ROWS][COLS]) {
    int newBoard[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int neighbors = 0;
            for(int x = -1; x <= 1; x++) {
                for(int y = -1; y <= 1; y++) {
                    if(!(x == 0 && y == 0) && i + x >= 0 && i + x < ROWS && j + y >= 0 && j + y < COLS) {
                        if(board[i+x][j+y] == 1) {
                            neighbors++;
                        }
                    }
                }
            }

            if(board[i][j] == 1 && neighbors < 2) {
                newBoard[i][j] = 0;
            }
            else if(board[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                newBoard[i][j] = 1;
            }
            else if(board[i][j] == 1 && neighbors > 3) {
                newBoard[i][j] = 0;
            }
            else if(board[i][j] == 0 && neighbors == 3) {
                newBoard[i][j] = 1;
            }
            else {
                newBoard[i][j] = board[i][j];
            }
        }
    }

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS] = {0};
    srand(time(NULL));

    // Seed a few random cells
    for(int i = 0; i < 500; i++) {
        int x = rand() % ROWS;
        int y = rand() % COLS;
        board[x][y] = 1;
    }

    while(1) {
        printBoard(board);
        updateBoard(board);
        usleep(100000);
        system("clear");
    }

    return 0;
}