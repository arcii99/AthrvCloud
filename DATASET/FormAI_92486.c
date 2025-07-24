//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function prototypes
void generateBoard(int board[][5]);
int generateNumber(int usedNumbers[]);
int checkLine(int board[][5], int line[], int row);
void printBoard(int board[][5]);

int main() {
    // seed random number generator
    srand(time(NULL));

    // declare and initialize variables
    int board[5][5], usedNumbers[75], winner = 0;

    // initialize board and usedNumbers
    generateBoard(board);
    memset(usedNumbers, 0, sizeof(usedNumbers));

    // main game loop
    while (!winner) {
        // generate a new random number
        int num = generateNumber(usedNumbers);

        // check if number exists in board
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == num) {
                    // mark number as used
                    usedNumbers[num] = 1;

                    // update board
                    board[i][j] = 0;

                    // check if player has completed a line
                    int line[5] = { 1, 1, 1, 1, 1 };
                    if (checkLine(board, line, i) || checkLine(board, line, j)) {
                        printf("Bingo! You Win!\n");
                        winner = 1;
                        break;
                    }
                }
            }

            if (winner) {
                break;
            }
        }
    }

    // print final board
    printf("Final Board:\n");
    printBoard(board);

    return 0;
}

// function definition to generate board
void generateBoard(int board[][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int num = (j * 15) + rand() % 15 + 1;

            // check if number exists in board
            for (int k = 0; k < j; k++) {
                if (board[i][k] == num) {
                    num = (j * 15) + rand() % 15 + 1;
                    k = -1;
                }
            }

            board[i][j] = num;
        }
    }

    // mark middle square as free space
    board[2][2] = 0;
}

// function definition to generate a new random number
int generateNumber(int usedNumbers[]) {
    int num = rand() % 75 + 1;

    while (usedNumbers[num]) {
        num = rand() % 75 + 1;
    }

    return num;
}

// function definition to check if player has completed a line
int checkLine(int board[][5], int line[], int row) {
    for (int i = 0; i < 5; i++) {
        if (board[row][i] != 0) {
            line[i] = 0;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (line[i]) {
            return 0;
        }
    }

    return 1;
}

// function definition to print out board
void printBoard(int board[][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}