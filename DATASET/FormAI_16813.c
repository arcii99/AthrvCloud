//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create an array for the bingo board
    int board[5][5];

    // Initialize the board with random numbers
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Generate a random number between 1 and 25
            board[i][j] = rand() % 25 + 1;

            // Check for duplicates and replace with a new number
            for (int k = 0; k < i; k++) {
                for (int l = 0; l < j; l++) {
                    if (board[i][j] == board[k][l]) {
                        board[i][j] = rand() % 25 + 1;
                        k = l = 0;
                    }
                }
            }
        }
    }

    // Print out the bingo board
    printf("Let the Bingo game begin!\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 && j == 2) {
                // Print out a free space in the center of the board
                printf(" %2c ", 'X');
            } else {
                printf(" %2d ", board[i][j]);
            }
        }
        printf("\n");
    }

    // Generate a random order for calling out the numbers
    int order[25];
    for (int i = 0; i < 25; i++) {
        order[i] = i + 1;
    }
    for (int i = 0; i < 25; i++) {
        int j = rand() % 25;
        int temp = order[i];
        order[i] = order[j];
        order[j] = temp;
    }

    // Call out the numbers in random order
    for (int i = 0; i < 25; i++) {
        printf("\nNumber %d: %d\n", i+1, order[i]);

        // Check if the number is on the board and replace it with an X
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (board[j][k] == order[i]) {
                    board[j][k] = -1;
                    break;
                }
            }
        }

        // Print out the updated board
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (j == 2 && k == 2) {
                    // Print out a free space in the center of the board
                    printf(" %2c ", 'X');
                } else if (board[j][k] == -1) {
                    printf(" %2c ", 'X');
                } else {
                    printf(" %2d ", board[j][k]);
                }
            }
            printf("\n");
        }

        // Check for a winning combination
        int bingo = 0;
        // Check for horizontal bingo
        for (int j = 0; j < 5; j++) {
            if (board[j][0] == -1 && board[j][1] == -1 && board[j][2] == -1 && board[j][3] == -1 && board[j][4] == -1) {
                bingo = 1;
                break;
            }
        }
        // Check for vertical bingo
        for (int j = 0; j < 5; j++) {
            if (board[0][j] == -1 && board[1][j] == -1 && board[2][j] == -1 && board[3][j] == -1 && board[4][j] == -1) {
                bingo = 1;
                break;
            }
        }
        // Check for diagonal bingo
        if (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1) {
            bingo = 1;
        }
        if (board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1) {
            bingo = 1;
        }
        // Check if there is a bingo
        if (bingo) {
            printf("\nBingo! You win!\n");
            break;
        }
    }

    // End the game
    printf("\nThanks for playing!\n");
    return 0;
}