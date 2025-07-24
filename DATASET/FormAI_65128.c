//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_calls = 0; // Keep track of the number of calls
    int b_numbers[5][5]; // The array to hold the numbers
    int number_pool[75]; // An array holding all possible numbers
    int i, j, k, l, n; // Counters and random number generator seed

    // Fill the number pool
    for (n = 0; n < 75; n++) {
        number_pool[n] = n+1;
    }

    // Shuffle the number pool using the Fisher-Yates algorithm
    for (n = 74; n > 0; n--) {
        k = rand() % (n+1);
        l = number_pool[k];
        number_pool[k] = number_pool[n];
        number_pool[n] = l;
    }

    // Fill the bingo array with random numbers from the pool
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 2 && j == 2) { // The center of the board is FREE
                b_numbers[i][j] = -1;
            } else { // Fill with numbers from the pool
                b_numbers[i][j] = number_pool[i*5+j];
            }
        }
    }

    // Print out the initial bingo board
    printf("BINGO CARD\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (b_numbers[i][j] == -1) {
                printf("XX "); // FREE space
            } else {
                printf("%02d ", b_numbers[i][j]);
            }
        }
        printf("\n");
    }

    // Start calling numbers until there is a winner
    int winner = 0;
    while (!winner) {
        // Generate a random number from the pool
        int next_number = number_pool[num_calls];
        num_calls++;

        // Mark any matching numbers on the bingo board
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (b_numbers[i][j] == next_number) {
                    b_numbers[i][j] = -1; // Mark it as called
                }
            }
        }

        // Print out the updated bingo board
        printf("NEXT CALL: %02d\n", next_number);
        printf("BINGO CARD\n");
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (b_numbers[i][j] == -1) {
                    printf("XX "); // FREE space
                } else {
                    printf("%02d ", b_numbers[i][j]);
                }
            }
            printf("\n");
        }

        // Check for a winner
        for (i = 0; i < 5; i++) {
            // Check rows
            if (b_numbers[i][0] == -1 && b_numbers[i][1] == -1 && b_numbers[i][2] == -1 && b_numbers[i][3] == -1 && b_numbers[i][4] == -1) {
                printf("WINNER! ROW %d\n", i+1);
                winner = 1;
                break;
            }
            // Check columns
            if (b_numbers[0][i] == -1 && b_numbers[1][i] == -1 && b_numbers[2][i] == -1 && b_numbers[3][i] == -1 && b_numbers[4][i] == -1) {
                printf("WINNER! COLUMN %d\n", i+1);
                winner = 1;
                break;
            }
        }
        // Check diagonals
        if (b_numbers[0][0] == -1 && b_numbers[1][1] == -1 && b_numbers[2][2] == -1 && b_numbers[3][3] == -1 && b_numbers[4][4] == -1) {
            printf("WINNER! DIAGONAL (UPPER-LEFT TO LOWER-RIGHT)\n");
            winner = 1;
        } else if (b_numbers[0][4] == -1 && b_numbers[1][3] == -1 && b_numbers[2][2] == -1 && b_numbers[3][1] == -1 && b_numbers[4][0] == -1) {
            printf("WINNER! DIAGONAL (UPPER-RIGHT TO LOWER-LEFT)\n");
            winner = 1;
        }
    }

    // Print out the final bingo board
    printf("FINAL BINGO CARD\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (b_numbers[i][j] == -1) {
                printf("XX "); // FREE space
            } else {
                printf("%02d ", b_numbers[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}