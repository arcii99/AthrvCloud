//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 25

void generateRandomNumbers(int arr[], int num) {
    int i, j;
    int duplicate;

    srand(time(NULL));

    for (i = 0; i < num; i++) {
        do {
            arr[i] = rand() % MAX_NUM + 1;
            duplicate = 0;

            for (j = 0; j < i; j++) {
                if (arr[j] == arr[i]) {
                    duplicate = 1;
                    break;
                }
            }
        } while (duplicate);
    }
}

void printBingoBoard(int board[ROWS][COLS], int num[]) {
    int i, j;

    printf("    B   I   N   G   O\n");

    for (i = 0; i < ROWS; i++) {
        printf("  +---+---+---+---+---+\n");
        printf("%d ", i + 1);

        for (j = 0; j < COLS; j++) {
            if (board[i][j]) {
                printf("| %2d", num[board[i][j] - 1]);
            }

            else {
                printf("|  X");
            }
        }

        printf("|\n");
    }

    printf("  +---+---+---+---+---+\n");
}

int checkBingo(int board[ROWS][COLS]) {
    int i, j, diag1 = 1, diag2 = 1;

    for (i = 0; i < ROWS; i++) {
        int row = 1, col = 1;

        for (j = 0; j < COLS; j++) {
            row &= board[i][j];
            col &= board[j][i];
        }

        if (row || col) {
            return 1;
        }

        diag1 &= board[i][i];
        diag2 &= board[i][COLS - i - 1];
    }

    if (diag1 || diag2) {
        return 1;
    }

    return 0;
}

int main() {
    int numberList[MAX_NUM];
    int board[ROWS][COLS] = {0};

    generateRandomNumbers(numberList, MAX_NUM);

    printBingoBoard(board, numberList);

    int i, numCalled = 0;

    while (!checkBingo(board)) {
        printf("\nPress enter to generate the next number.\n");
        getchar();

        int num;

        do {
            num = rand() % MAX_NUM + 1;
        } while (numberList[num - 1] == -1);

        printf("The next number is: %d\n", numberList[num - 1]);

        numberList[num - 1] = -1;
        numCalled++;

        for (i = 0; i < ROWS; i++) {
            int j;

            for (j = 0; j < COLS; j++) {
                if (board[i][j] == num) {
                    board[i][j] = 1;
                }
            }
        }

        printBingoBoard(board, numberList);
    }

    printf("\nBingo! It took %d calls to get the winning combination.\n", numCalled);

    return 0;
}