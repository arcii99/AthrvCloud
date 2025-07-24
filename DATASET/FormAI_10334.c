//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main() {
    int board[ROWS][COLS];
    int numbers[75], call, count = 0;

    srand(time(NULL));

    // Filling the Board with random numbers
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 75 + 1;
        }
    }

    // Generating an array of 75 unique numbers
    for (int i = 0; i < 75; i++) {
        numbers[i] = i + 1;
    }

    // Printing Bingo Board with Numbers
    printf("********** BINGO **********\n\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%3d", board[i][j]);
        }
        printf("\n");
    }
    printf("\n\nPress Enter to Start the Game!\n\n");
    getchar();

    // Starting the Game
    while (count < 25) {
        // Generating a Random Number for Call
        call = numbers[rand() % (75 - count)];
        // Removing the called Number from the Array
        for (int i = 0; i < 75; i++) {
            if (numbers[i] == call) {
                numbers[i] = numbers[74 - count];
                count++;
                break;
            }
        }
        // Printing the Call and the Remaining Numbers
        printf("Call: %d\n", call);
        printf("Remaining Numbers:");
        for (int i = 0; i < 75 - count; i++) {
            printf(" %d", numbers[i]);
        }
        printf("\n\n");

        // Marking the Called Number on the Board
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == call) {
                    board[i][j] = 0;
                }
            }
        }

        // Checking for Winning Combination
        for (int i = 0; i < ROWS; i++) {
            // Checking for Horizontal Wins
            if (board[i][0] == 0 && board[i][1] == 0 && board[i][2] == 0 && board[i][3] == 0 && board[i][4] == 0) {
                printf("You won Bingo Horizontally on Row %d!\n", i + 1);
                return 0;
            }
            // Checking for Vertical Wins
            if (board[0][i] == 0 && board[1][i] == 0 && board[2][i] == 0 && board[3][i] == 0 && board[4][i] == 0) {
                printf("You won Bingo Vertically on Column %d!\n", i + 1);
                return 0;
            }
        }
        // Checking for Diagonal Wins
        if (board[0][0] == 0 && board[1][1] == 0 && board[2][2] == 0 && board[3][3] == 0 && board[4][4] == 0) {
            printf("You won Bingo Diagonally from Top-Left to Bottom-Right!\n");
            return 0;
        }
        if (board[0][4] == 0 && board[1][3] == 0 && board[2][2] == 0 && board[3][1] == 0 && board[4][0] == 0) {
            printf("You won Bingo Diagonally from Top-Right to Bottom-Left!\n");
            return 0;
        }
    }
    printf("It's a Tie! No more calls left.\n");

    return 0;
}