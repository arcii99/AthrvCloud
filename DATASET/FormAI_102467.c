//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main() {

    // Initialize the random number generator
    srand(time(NULL));
    
    // Generate the bingo card
    int bingoCard[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // For the middle square, leave it empty
            if (i == 2 && j == 2) {
                bingoCard[i][j] = -1;
            } else {
                // Generate a random number between 1 and 75
                bingoCard[i][j] = (rand() % 75) + 1;
                // Ensure that the number does not repeat in the same row or column
                for (int k = i; k >= 0; k--) {
                    if (bingoCard[k][j] == bingoCard[i][j] && k != i) {
                        bingoCard[i][j] = (rand() % 75) + 1;
                        k = i; // Start from the top again
                    }
                }
                for (int k = j; k >= 0; k--) {
                    if (bingoCard[i][k] == bingoCard[i][j] && k != j) {
                        bingoCard[i][j] = (rand() % 75) + 1;
                        k = j; // Start from the left again
                    }
                }
            }
        }
    }
    
    // Display the bingo card
    printf("B   I   N   G   O\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (bingoCard[i][j] != -1) {
                printf("%-3d ", bingoCard[i][j]);
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
    
    // Simulate the bingo game
    int bingoNumbers[75];
    for (int i = 0; i < 75; i++) {
        bingoNumbers[i] = i+1;
    }
    int bingoNumberIndex = 0;
    while (bingoNumberIndex < 75) {
        int randomNumber = bingoNumbers[bingoNumberIndex];
        printf("The next number is: %d\n", randomNumber);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (bingoCard[i][j] == randomNumber) {
                    // Mark the number on the card
                    bingoCard[i][j] = -1;
                    // Check if there is a bingo
                    int b = 0, i = 0, n = 0, g = 0, o = 0;
                    int diagonal1 = 0, diagonal2 = 0;
                    for (int k = 0; k < ROWS; k++) {
                        if (bingoCard[k][0] == -1 && bingoCard[k][1] == -1 && bingoCard[k][2] == -1 && bingoCard[k][3] == -1 && bingoCard[k][4] == -1) {
                            b = 1;
                        }
                        if (bingoCard[0][k] == -1 && bingoCard[1][k] == -1 && bingoCard[2][k] == -1 && bingoCard[3][k] == -1 && bingoCard[4][k] == -1) {
                            if (k == 0) {
                                i = 1;
                            } else if (k == 1) {
                                n = 1;
                            } else if (k == 2) {
                                g = 1;
                            } else if (k == 3) {
                                o = 1;
                            }
                        }
                        if (bingoCard[k][k] == -1) {
                            diagonal1 = 1;
                        }
                        if (bingoCard[k][COLS-k-1] == -1) {
                            diagonal2 = 1;
                        }
                    }
                    if (b || i+n+g+o == 4 || diagonal1 == 1 || diagonal2 == 1) {
                        printf("BINGO!!!\n");
                        exit(0);
                    }
                }
            }
        }
        bingoNumberIndex++;
    }
    
    // If the program is still running, then there was no bingo
    printf("Sorry, no one won!\n");
    return 0;
}