//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    // Initialize random seed
    srand(time(0));

    int card[5][5]; // Bingo card
    int used_nums[25]; // Array to keep track of already called numbers
    int num_called = 0; // Number of called numbers

    // Generate a random Bingo card
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 && j == 2) { // Free space in the middle
                card[i][j] = 0;
            } else {
                int min, max;
                if (j == 2) { // Center column
                    min = 16 + i * 15;
                    max = 30 + i * 15;
                } else {
                    min = j * 15 + 1;
                    max = (j + 1) * 15;
                }
                card[i][j] = rand_num(min, max);
            }
        }
    }

    // Display the Bingo card
    printf("Bingo Card:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%2d ", card[i][j]);
        }
        printf("\n");
    }

    // Game loop
    while (num_called < 75) {
        int num = rand_num(1, 75); // Generate a random number
        int already_called = 0; // Flag to check if the number has already been called
        for (int i = 0; i < num_called; i++) {
            if (num == used_nums[i]) {
                already_called = 1;
                break;
            }
        }
        if (!already_called) { // If the number has not been called before
            printf("Number called: %d\n", num);
            used_nums[num_called] = num;
            num_called++;

            // Check if the number is present in the Bingo card
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (card[i][j] == num) {
                        card[i][j] = 0; // Mark the number as called on the Bingo card
                    }
                }
            }

            // Check if any row, column, or diagonal has been completed
            for (int i = 0; i < 5; i++) {
                int row_complete = 1;
                int col_complete = 1;
                for (int j = 0; j < 5; j++) {
                    if (card[i][j] != 0) {
                        row_complete = 0;
                    }
                    if (card[j][i] != 0) {
                        col_complete = 0;
                    }
                }
                if (row_complete) {
                    printf("Row %d completed!\n", i+1);
                }
                if (col_complete) {
                    printf("Column %d completed!\n", i+1);
                }
            }
            int diag1_complete = 1;
            int diag2_complete = 1;
            for (int i = 0; i < 5; i++) { // Check diagonals
                if (card[i][i] != 0) {
                    diag1_complete = 0;
                }
                if (card[i][4-i] != 0) {
                    diag2_complete = 0;
                }
            }
            if (diag1_complete) {
                printf("Diagonal from top-left to bottom-right completed!\n");
            }
            if (diag2_complete) {
                printf("Diagonal from top-right to bottom-left completed!\n");
            }

            // Check if all numbers have been called
            if (num_called == 75) {
                printf("All numbers have been called. Game over!\n");
                break;
            }
        }
    }

    return 0;
}