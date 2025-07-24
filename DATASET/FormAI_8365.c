//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Declare variables
    int i, j, n, num, row, col;
    char play_again = 'y';
    srand(time(0)); // Randomize seed

    while (play_again == 'y') {
        // Set up the game
        printf("Welcome to Bingo Simulator!\n\n");
        printf("Enter the size of your Bingo card (minimum 3): ");
        scanf("%d", &n);
        int card[n][n];
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                card[i][j] = 0;
            }
        }

        // Print out the card
        printf("\nHere is your card:\n");
        printf(" |");
        for (i = 0; i < n; i++) {
            printf(" %d |", i + 1);
        }
        printf("\n");
        for (i = 0; i < n; i++) {
            printf("|");
            for (j = 0; j < n; j++) {
                printf(" %d |", card[i][j]);
            }
            printf(" %d\n", i + 1);
        }
        printf("\n");

        // Play the game
        while (1) {
            // Draw a number
            num = rand() % (n * n) + 1;
            printf("The next number is: %d\n", num);

            // Mark the number on the card
            row = (num - 1) / n;
            col = (num - 1) % n;
            card[row][col] = 1;

            // Print out the updated card
            printf(" |");
            for (i = 0; i < n; i++) {
                printf(" %d |", i + 1);
            }
            printf("\n");
            for (i = 0; i < n; i++) {
                printf("|");
                for (j = 0; j < n; j++) {
                    printf(" %c |", card[i][j] ? 'X' : ' ');
                }
                printf(" %d\n", i + 1);
            }
            printf("\n");

            // Check for a winner
            for (i = 0; i < n; i++) {
                // Check rows and columns
                if (card[i][0] == 1) {
                    for (j = 1; j < n; j++) {
                        if (card[i][j] != 1) {
                            break;
                        }
                    }
                    if (j == n) {
                        printf("Bingo! You win!\n");
                        goto play_again;
                    }
                }
                if (card[0][i] == 1) {
                    for (j = 1; j < n; j++) {
                        if (card[j][i] != 1) {
                            break;
                        }
                    }
                    if (j == n) {
                        printf("Bingo! You win!\n");
                        goto play_again;
                    }
                }
            }
            // Check diagonal
            if (card[0][0] == 1) {
                for (i = 1; i < n; i++) {
                    if (card[i][i] != 1) {
                        break;
                    }
                }
                if (i == n) {
                    printf("Bingo! You win!\n");
                    goto play_again;
                }
            }
            if (card[0][n-1] == 1) {
                for (i = 1; i < n; i++) {
                    if (card[i][n-1-i] != 1) {
                        break;
                    }
                }
                if (i == n) {
                    printf("Bingo! You win!\n");
                    goto play_again;
                }
            }
        }

        play_again:
        printf("Do you want to play again? (y/n)\n");
        scanf(" %c", &play_again);
    }

    return 0;
}