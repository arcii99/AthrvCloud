//FormAI DATASET v1.0 Category: Game of Life ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

void initialize(int board[][COLS]);
void printBoard(int board[][COLS]);
void nextGeneration(int board[][COLS]);

int main()
{
    int board[ROWS][COLS];
    srand(time(0));
    initialize(board);
    printf("Welcome to the Game of Life!\n");
    printf("Press enter to start.\n\n");
    getchar();
    while (1) {
        system("cls");
        printBoard(board);
        printf("\nPress enter to see next generation (press q to quit).\n\n");
        char c = getchar();
        if (c == 'q') 
            break;
        nextGeneration(board);
    }
    return 0;
}

void initialize(int board[][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void printBoard(int board[][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}

void nextGeneration(int board[][COLS])
{
    int newBoard[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int liveNeighbours = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    int row = (i + x + ROWS) % ROWS;
                    int col = (j + y + COLS) % COLS;
                    liveNeighbours += board[row][col];
                }
            }
            liveNeighbours -= board[i][j];
            if (board[i][j] == 1) {
                if (liveNeighbours < 2 || liveNeighbours > 3) {
                    newBoard[i][j] = 0;
                }
                else {
                    newBoard[i][j] = 1;
                }
            }
            else {
                if (liveNeighbours == 3) {
                    newBoard[i][j] = 1;
                }
                else {
                    newBoard[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}