//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int board[5][5];
    int num, row, col, i, j;
    char playAgain = 'y';
    srand(time(NULL)); // initialize random seed

    while (playAgain == 'y' || playAgain == 'Y') {
        printf("\n***Welcome to the Bingo Simulator!***\n");

        // generate random numbers for the bingo board
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (i == 2 && j == 2) {
                    board[i][j] = -1; // free space in the center
                } else {
                    num = rand() % 15 + j * 15 + 1;
                    board[i][j] = num;
                }
            }
        }

        // print out the generated board
        printf("\nHere is your bingo board:\n\n");
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                printf("%d\t", board[i][j]);
            }
            printf("\n");
        }

        // play the game until someone wins
        int winner = 0;
        while (!winner) {
            printf("\nEnter a number between 1 and 75: ");
            scanf("%d", &num);

            // check if the number is on the board
            for (i = 0; i < 5; i++) {
                for (j = 0; j < 5; j++) {
                    if (board[i][j] == num) {
                        board[i][j] = -1; // mark the number as found
                    }
                }
            }

            // print out the updated board
            printf("\nHere is the updated board:\n\n");
            for (i = 0; i < 5; i++) {
                for (j = 0; j < 5; j++) {
                    printf("%d\t", board[i][j]);
                }
                printf("\n");
            }

            // check for a winner
            for (i = 0; i < 5; i++) {
                row = 0;
                col = 0;
                for (j = 0; j < 5; j++) {
                    if (board[i][j] == -1) {
                        row++;
                    }
                    if (board[j][i] == -1) {
                        col++;
                    }
                }
                if (row == 5 || col == 5) {
                    winner = 1;
                    break; // we have a winner!
                }
            }
        }

        printf("\n***Congratulations! You have won the game!***\n\n");
        printf("Would you like to play again? (y/n): ");
        scanf(" %c", &playAgain); // space before %c to skip newline
    }

    return 0;
}