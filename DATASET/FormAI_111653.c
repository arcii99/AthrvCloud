//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define NUMBERS 25

int checkBingo(int board[][COLS]);
void printBoard(int board[][COLS]);

int main()
{
    int board[ROWS][COLS] = {0};
    int numbers[NUMBERS];
    int i, j, num, count = 0;

    // Fill the numbers array with unique numbers between 1 and 25
    for (i = 0; i < NUMBERS; i++) {
        numbers[i] = i + 1;
    }

    // Shuffle the numbers
    srand(time(NULL));
    for (i = 0; i < NUMBERS; i++) {
        int r = rand() % NUMBERS;
        int temp = numbers[i];
        numbers[i] = numbers[r];
        numbers[r] = temp;
    }

    printf("Welcome to Bingo Simulator!\n");

    while (1) {
        printf("\n");

        // Print the current board
        printBoard(board);

        // Ask for a number
        printf("Enter a number (between 1 and 25): ");
        scanf("%d", &num);

        // Check if the number is valid and hasn't been called before
        if (num < 1 || num > 25) {
            printf("Invalid number! Please enter a number between 1 and 25.\n");
            continue;
        } else {
            int valid = 1;
            for (i = 0; i < count; i++) {
                if (numbers[i] == num) {
                    valid = 0;
                    break;
                }
            }
            if (!valid) {
                printf("Number %d has already been called! Please enter a different number.\n", num);
                continue;
            }
        }

        // Mark the number on the board
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (board[i][j] == num) {
                    board[i][j] = -1;
                    break;
                }
            }
        }

        // Add the number to the called numbers array
        numbers[count++] = num;

        // Check for Bingo
        int bingo = checkBingo(board);
        if (bingo) {
            printf("\n\nBINGO! You won in %d calls!\n", count);
            break;
        }
    }

    printf("\n\nThank you for playing Bingo Simulator!\n");

    return 0;
}

// Check if there is a Bingo on the current board
int checkBingo(int board[][COLS])
{
    int i, j, sum;

    // Check rows
    for (i = 0; i < ROWS; i++) {
        sum = 0;
        for (j = 0; j < COLS; j++) {
            sum += board[i][j];
        }
        if (sum == -COLS) {
            return 1;
        }
    }

    // Check columns
    for (j = 0; j < COLS; j++) {
        sum = 0;
        for (i = 0; i < ROWS; i++) {
            sum += board[i][j];
        }
        if (sum == -ROWS) {
            return 1;
        }
    }

    // Check diagonals
    sum = 0;
    for (i = 0, j = 0; i < ROWS && j < COLS; i++, j++) {
        sum += board[i][j];
    }
    if (sum == -ROWS) {
        return 1;
    }

    sum = 0;
    for (i = 0, j = COLS - 1; i < ROWS && j >= 0; i++, j--) {
        sum += board[i][j];
    }
    if (sum == -ROWS) {
        return 1;
    }

    return 0;
}

// Print the current board
void printBoard(int board[][COLS])
{
    int i, j;

    printf("   B   I   N   G   O  \n");
    for (i = 0; i < ROWS; i++) {
        printf("---------------------\n");
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                printf("| XX");
            } else if (board[i][j] == 0) {
                printf("|  %d", board[i][j]);
            } else {
                printf("| %2d", board[i][j]);
            }
        }
        printf("|\n");
    }
    printf("---------------------\n");
}