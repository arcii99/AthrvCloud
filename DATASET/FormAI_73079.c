//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define FREE_SPACE 12

int main() {
    srand(time(NULL));

    // 2D array to hold the Bingo card with the free space in the center
    int board[ROWS][COLS] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, FREE_SPACE, 13, 14},
        {15, 16, 17, 18, 19},
        {20, 21, 22, 23, 24}
    };

    int numbers[75]; // array to hold the 75 possible Bingo numbers
    for (int i = 0; i < 75; i++) {
        numbers[i] = i + 1;
    }

    // Shuffle the Bingo numbers
    for (int i = 0; i < 75; i++) {
        int j = rand() % 75;
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    int count = 0; // counter for the number of called Bingo numbers

    printf("Let's play Bingo!\n");

    // Loop until a Bingo is called
    while (1) {
        int index = rand() % 75; // generate a random index for the Bingo number
        int number = numbers[index]; // get the Bingo number at the index

        // Check if the number has already been called
        int already_called = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == number) {
                    board[i][j] = 0; // mark the number as called on the board
                    already_called = 1;
                }
            }
        }

        // If the number has not already been called, print it out
        if (!already_called) {
            printf("The number called is %d\n", number);
        }

        // Check if there is a Bingo
        int bingo = 0;

        // Check rows
        for (int i = 0; i < ROWS; i++) {
            int row_sum = 0;
            for (int j = 0; j < COLS; j++) {
                row_sum += board[i][j];
            }
            if (row_sum == 0) {
                bingo = 1;
            }
        }

        // Check columns
        for (int i = 0; i < COLS; i++) {
            int col_sum = 0;
            for (int j = 0; j < ROWS; j++) {
                col_sum += board[j][i];
            }
            if (col_sum == 0) {
                bingo = 1;
            }
        }

        // Check diagonals
        if (board[0][0] + board[1][1] + board[3][3] + board[4][4] == 0 ||
            board[0][4] + board[1][3] + board[3][1] + board[4][0] == 0) {
            bingo = 1;
        }

        // If there is a Bingo, end the game
        if (bingo) {
            printf("Bingo! You win!\n");
            break;
        }

        count++; // increment the number of called Bingo numbers
    }

    printf("You called %d Bingo numbers.\n", count);

    // Exit the program
    return 0;
}