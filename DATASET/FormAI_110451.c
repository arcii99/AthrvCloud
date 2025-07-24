//FormAI DATASET v1.0 Category: Table Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Seed for random number generator
    int array[5][5]; // 5x5 C Table
    int i, j, num, row, col, sum_row, sum_col, sum_diag, count_spaces = 0;
    char choice;

    // Initialize C Table and set all values to 0
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            array[i][j] = 0;
        }
    }

    // Display C Table and menu to user
    printf("------------------------------\n");
    printf("|     C TABLE GAME MENU      |\n");
    printf("------------------------------\n");
    printf("|   1. Display Game Board    |\n");
    printf("|   2. Place a Number        |\n");
    printf("|   3. Sum Rows              |\n");
    printf("|   4. Sum Columns           |\n");
    printf("|   5. Sum Diagonals         |\n");
    printf("|   6. Quit Game             |\n");
    printf("------------------------------\n\n");

    // Loop until user chooses to quit
    do {
        printf("\nEnter Choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            // Display C Table
            case '1':
                printf("\nCurrent Game Board:\n");
                for (i = 0; i < 5; i++) {
                    printf("| ");
                    for (j = 0; j < 5; j++) {
                        printf("%d ", array[i][j]);
                    }
                    printf("|\n");
                }
                break;

            // Place a Number
            case '2':
                do {
                    printf("\nEnter a Number (1 to 25): ");
                    scanf("%d", &num);
                } while (num < 1 || num > 25);

                do {
                    printf("Enter Row (1 to 5): ");
                    scanf("%d", &row);
                    printf("Enter Column (1 to 5): ");
                    scanf("%d", &col);
                } while (row < 1 || row > 5 || col < 1 || col > 5 || array[row - 1][col - 1] != 0);

                array[row - 1][col - 1] = num;
                break;

            // Sum Rows
            case '3':
                for (i = 0; i < 5; i++) {
                    sum_row = 0;
                    for (j = 0; j < 5; j++) {
                        sum_row += array[i][j];
                    }
                    printf("Sum of Row %d: %d\n", i + 1, sum_row);
                }
                break;

            // Sum Columns
            case '4':
                for (i = 0; i < 5; i++) {
                    sum_col = 0;
                    for (j = 0; j < 5; j++) {
                        sum_col += array[j][i];
                    }
                    printf("Sum of Column %d: %d\n", i + 1, sum_col);
                }
                break;

            // Sum Diagonals
            case '5':
                sum_diag = 0;
                for (i = 0; i < 5; i++) {
                    sum_diag += array[i][i];
                }
                printf("Sum of Diagonal (Left to Right): %d\n", sum_diag);

                sum_diag = 0;
                for (i = 0; i < 5; i++) {
                    sum_diag += array[i][4 - i];
                }
                printf("Sum of Diagonal (Right to Left): %d\n", sum_diag);
                break;

            // Quit Game
            case '6':
                printf("\nExiting C Table Game...\n");
                break;

            // Invalid Choice
            default:
                printf("\nInvalid Choice. Please try again.\n");
                break;
        }

        // Count number of spaces left in C Table
        count_spaces = 0;
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (array[i][j] == 0) {
                    count_spaces++;
                }
            }
        }

        // End game if no spaces left
        if (count_spaces == 0) {
            printf("\nNo more spaces left. Game Over!\n");
            choice = '6';
        }

    } while (choice != '6');

    return 0;
}