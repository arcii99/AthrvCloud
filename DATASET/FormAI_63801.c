//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get a random number within a range
int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to check if a number already exists in the array
int num_exists(int num, int *arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return 1;
        }
    }
    return 0;
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the array to keep track of the called numbers
    int called_numbers[75] = {0};
    int called_count = 0;

    // Initialize the card with all zeros
    int card[5][5] = {{0}};

    // Fill the card with random numbers
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int num;
            
            // The center square is always marked
            if (i == 2 && j == 2) {
                card[i][j] = -1;
            } else {
                // Get a random number within the appropriate range
                switch (j) {
                    case 0:
                        num = get_random_number(1, 15);
                        break;
                    case 1:
                        num = get_random_number(16, 30);
                        break;
                    case 2:
                        num = get_random_number(31, 45);
                        break;
                    case 3:
                        num = get_random_number(46, 60);
                        break;
                    case 4:
                        num = get_random_number(61, 75);
                        break;
                }

                // Check if the number already exists in the card
                while (num_exists(num, (int *)card, 25)) {
                    switch (j) {
                        case 0:
                            num = get_random_number(1, 15);
                            break;
                        case 1:
                            num = get_random_number(16, 30);
                            break;
                        case 2:
                            num = get_random_number(31, 45);
                            break;
                        case 3:
                            num = get_random_number(46, 60);
                            break;
                        case 4:
                            num = get_random_number(61, 75);
                            break;
                    }
                }

                // Mark the number in the card
                card[i][j] = num;
            }
        }
    }

    // Print the card
    printf("      B   I   N   G   O\n");
    for (int i = 0; i < 5; i++) {
        printf("   ---------------------\n");
        for (int j = 0; j < 5; j++) {
            if (j == 0) {
                printf("%c | ", 'A' + i);
            }
            if (card[i][j] == -1) {
                printf("X  | ");
            } else {
                printf("%-2d | ", card[i][j]);
            }
        }
        printf("\n");
    }
    printf("   ---------------------\n");

    // Call numbers until someone wins
    while (1) {
        // Get a random number within the appropriate range
        int num = get_random_number(1, 75);

        // Check if the number has already been called
        if (num_exists(num, called_numbers, called_count)) {
            continue;
        }

        // Mark the number as called and increment the called count
        called_numbers[called_count++] = num;

        // Print the called number
        printf("\nCalled number: %d\n", num);

        // Check if the number is on any player's card
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (card[i][j] == num) {
                    // Mark the number on the card
                    card[i][j] = -1;

                    // Print the updated card
                    printf("      B   I   N   G   O\n");
                    for (int k = 0; k < 5; k++) {
                        printf("   ---------------------\n");
                        for (int l = 0; l < 5; l++) {
                            if (l == 0) {
                                printf("%c | ", 'A' + k);
                            }
                            if (card[k][l] == -1) {
                                printf("X  | ");
                            } else {
                                printf("%-2d | ", card[k][l]);
                            }
                        }
                        printf("\n");
                    }
                    printf("   ---------------------\n");

                    // Check if the player has won
                    int row_sum, col_sum, diagonal_sum1, diagonal_sum2;
                    row_sum = col_sum = diagonal_sum1 = diagonal_sum2 = 0;

                    // Check row
                    for (int k = 0; k < 5; k++) {
                        if (card[i][k] == -1) {
                            row_sum++;
                        }
                    }

                    // Check column
                    for (int k = 0; k < 5; k++) {
                        if (card[k][j] == -1) {
                            col_sum++;
                        }
                    }

                    // Check diagonal
                    if (i == j) {
                        for (int k = 0; k < 5; k++) {
                            if (card[k][k] == -1) {
                                diagonal_sum1++;
                            }
                        }
                    }
                    if (i + j == 4) {
                        for (int k = 0; k < 5; k++) {
                            if (card[k][4-k] == -1) {
                                diagonal_sum2++;
                            }
                        }
                    }

                    // Check if any of the sums are 5
                    if (row_sum == 5 || col_sum == 5 || diagonal_sum1 == 5 || diagonal_sum2 == 5) {
                        printf("\n\nBINGO! Player %c has won!\n", 'A' + i);
                        return 0;
                    }

                    // Wait for input before continuing
                    printf("\nPress any key to continue.\n");
                    getchar();
                }
            }
        }
    }
}