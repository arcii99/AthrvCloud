//FormAI DATASET v1.0 Category: Game of Life ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40
#define ALIVE '*'
#define DEAD ' '

void initBoard(int board[][COLS]);
void printBoard(int board[][COLS]);
void updateBoard(int board[][COLS]);

int main()
{
    int board[ROWS][COLS];
    srand(time(NULL)); // set seed for randomization

    initBoard(board);
    printBoard(board);

    for (int i = 0; i < 10; i++) {
        system("clear"); // clear terminal window
        updateBoard(board);
        printBoard(board);
    }

    return 0;
}

void initBoard(int board[][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int randNum = rand() % 2; // generate random number (0 or 1)
            board[i][j] = randNum;
        }
    }
}

void printBoard(int board[][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("%c ", ALIVE);
            } else {
                printf("%c ", DEAD);
            }
        }
        printf("\n");
    }
}

void updateBoard(int board[][COLS])
{
    int tempBoard[ROWS][COLS] = {0}; // temporary board to store updated values
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int aliveNeighbors = 0;
            // check neighbors
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) { // skip cell itself
                        continue;
                    }
                    int row = i + x;
                    int col = j + y;
                    // check if neighbor is inside board and alive
                    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == 1) {
                        aliveNeighbors++;
                    }
                }
            }
            // apply rules of Game of Life
            if (board[i][j] == 1 && (aliveNeighbors == 2 || aliveNeighbors == 3)) {
                tempBoard[i][j] = 1; // cell stays alive
            } else if (board[i][j] == 0 && aliveNeighbors == 3) {
                tempBoard[i][j] = 1; // cell becomes alive
            }
        }
    }
    // copy updated values to original board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = tempBoard[i][j];
        }
    }
}