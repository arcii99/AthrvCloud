//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void print_bingo_board(int board[][COLS], int rowChecked, int colChecked) {
    printf("     B   I   N   G   O\n");
    printf("    --- --- --- --- ---\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d | ", i+1);
        for (int j = 0; j < COLS; j++) {
            if (i == rowChecked && j == colChecked) {
                printf("\033[1;31m");
            }
            printf("%2d ", board[i][j]);
            printf("\033[0m");
            printf("| ");
        }
        printf("\n");
        printf("    --- --- --- --- ---\n");
    }
}

int check_bingo(int board[][COLS]) {
    int countRow, countCol, countDiag1, countDiag2;

    // check rows and columns
    for (int i = 0; i < ROWS; i++) {
        countRow = 0;
        countCol = 0;
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                countRow++;
            }
            if (board[j][i] == -1) {
                countCol++;
            }
        }
        if (countRow == ROWS || countCol == ROWS) {
            return 1;
        }
    }

    // check diagonals
    countDiag1 = 0;
    countDiag2 = 0;
    for (int i = 0; i < ROWS; i++) {
        if (board[i][i] == -1) {
            countDiag1++;
        }
        if (board[i][COLS-i-1] == -1) {
            countDiag2++;
        }
    }
    if (countDiag1 == ROWS || countDiag2 == ROWS) {
        return 1;
    }

    return 0;
}

int main() {
    int board[ROWS][COLS];
    int nums[76];
    int rowChecked, colChecked;
    int bingoCount = 0;
    srand(time(NULL));

    // initialize board with -1
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = -1;
        }
    }

    // initialize nums array with 1-75
    for (int i = 0; i < 76; i++) {
        nums[i] = i+1;
    }

    // shuffle nums array
    for (int i = 0; i < 76; i++) {
        int randIndex = rand() % 76;
        int temp = nums[i];
        nums[i] = nums[randIndex];
        nums[randIndex] = temp;
    }

    printf("Welcome to Bingo Simulator!\n\n");

    while (bingoCount < 5) {
        int num = nums[bingoCount];
        printf("Next number: %d\n\n", num);

        // update board
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == num) {
                    board[i][j] = -1;
                    rowChecked = i;
                    colChecked = j;
                    break;
                }
            }
        }

        // print board
        print_bingo_board(board, rowChecked, colChecked);

        // check for bingo
        if (check_bingo(board)) {
            bingoCount++;
            printf("\nBINGO! You have %d bingos!\n\n", bingoCount);
        }

        // wait for user to press enter
        printf("Press enter to continue...");
        getchar();
        system("clear");
    }

    printf("Congratulations! You won Bingo!\n");

    return 0;
}