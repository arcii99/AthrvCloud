//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(0));
    int card[5][5];
    char markings[5][5];

    printf("Welcome to the Bingo Simulator!\n\n");
    printf("Generating your bingo card...\n");

    // Generate Bingo card and initialize markings
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card[i][j] = (j * 15) + rand() % 15 + 1; // Generate a number for the box
            markings[i][j] = 'X'; // Initialize the marking as X
        }
    }

    // Mark the center box as free space
    markings[2][2] = ' ';

    // Print the Bingo card
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("+----+----+----+----+----+\n");
        for (int j = 0; j < 5; j++) {
            if (card[i][j] < 10) {
                printf("|  %d |", card[i][j]);
            } else {
                printf("| %d |", card[i][j]);
            }
        }
        printf("\n|    |    |    |    |    |\n");
        for (int j = 0; j < 5; j++) {
            printf("|  %c |", markings[i][j]);
        }
        printf("\n");
    }
    printf("+----+----+----+----+----+\n\n");

    printf("Let's start the game!\n");

    // Mark the randomly generated numbers and check for a win
    int count = 0;
    while (count < 25) {
        int number = (rand() % 75) + 1;
        printf("\nNumber: %d\n", number);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (card[i][j] == number) {
                    markings[i][j] = ' '; // Mark the box as visited
                    count++; // Increment the counter
                }
            }
        }

        // Print the updated Bingo card
        printf("\n");
        for (int i = 0; i < 5; i++) {
            printf("+----+----+----+----+----+\n");
            for (int j = 0; j < 5; j++) {
                if (card[i][j] < 10) {
                    printf("|  %d |", card[i][j]);
                } else {
                    printf("| %d |", card[i][j]);
                }
            }
            printf("\n|    |    |    |    |    |\n");
            for (int j = 0; j < 5; j++) {
                printf("|  %c |", markings[i][j]);
            }
            printf("\n");
        }
        printf("+----+----+----+----+----+\n\n");

        // Check for a win
        int row_win = 0, col_win = 0, diag_win = 0;
        for (int i = 0; i < 5; i++) {
            int row_count = 0, col_count = 0;
            for (int j = 0; j < 5; j++) {
                if (markings[i][j] == ' ') {
                    row_count++; // Increment the row count if the box is marked
                }
                if (markings[j][i] == ' ') {
                    col_count++; // Increment the column count if the box is marked
                }
            }
            if (row_count == 5) {
                row_win = 1; // If there are 5 marked boxes in a row, set row_win as 1
            }
            if (col_count == 5) {
                col_win = 1; // If there are 5 marked boxes in a column, set col_win as 1
            }
            if (markings[i][i] == ' ') {
                diag_win++; // Count the marked boxes in the diagonal
            }
        }
        if (diag_win == 5 || markings[0][4] == ' ' && markings[1][3] == ' ' && markings[2][2] == ' ' && markings[3][1] == ' ' && markings[4][0] == ' ') {
            // If there are 5 marked boxes in the diagonal or in the reverse diagonal, set diag_win as 1
            printf("You have won the game with a diagonal!\n");
            break; // Exit the loop if there is a diagonal win
        } else if (row_win == 1) {
            printf("You have won the game with a row!\n");
            break; // Exit the loop if there is a row win
        } else if (col_win == 1) {
            printf("You have won the game with a column!\n");
            break; // Exit the loop if there is a column win
        }
    }

    printf("\nThanks for playing the Bingo Simulator!\n\n");

    return 0;
}