//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int bingo[5][5] = {}; // Initialize all elements to 0
    int i, j, ball;
    srand(time(0)); // Seed for random number generator
    
    printf("Welcome to Bingo Simulator!\n");
    printf("Generating a random 5x5 Bingo card...\n");
    
    // Populate the Bingo card
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 2 && j == 2) { // Free space
                bingo[i][j] = -1;
            } else {
                bingo[i][j] = rand() % 75 + 1; // Generate a random number between 1-75
            }
        }
    }
    
    // Print the Bingo card
    printf("\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (bingo[i][j] == -1) {
                printf("|  F  |");
            } else {
                printf("| %2d  |", bingo[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
    
    // Play the game
    printf("Starting the game!\n");
    for (i = 1; i <= 75; i++) {
        printf("\nBall %d:", i);
        ball = rand() % 75 + 1;
        printf(" %d\n\n", ball);
        
        // Check if ball number matches with Bingo card numbers
        for (j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (bingo[j][k] == ball) {
                    bingo[j][k] = -1; // Mark the number as found
                }
            }
        }
        
        // Print the updated Bingo card
        for (j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (bingo[j][k] == -1) {
                    printf("|  F  |");
                } else {
                    printf("| %2d  |", bingo[j][k]);
                }
            }
            printf("\n");
        }
        printf("\n");
        
        // Check if Bingo has been achieved
        int bingo_count = 0;
        for (j = 0; j < 5; j++) {
            int row_count = 0, col_count = 0;
            for (int k = 0; k < 5; k++) {
                if (bingo[j][k] == -1) row_count++;
                if (bingo[k][j] == -1) col_count++;
            }
            if (row_count == 5) bingo_count++;
            if (col_count == 5) bingo_count++;
        }
        int diagonal_count = 0;
        if (bingo[0][0] == -1 && bingo[1][1] == -1 && bingo[2][2] == -1 && bingo[3][3] == -1 && bingo[4][4] == -1) diagonal_count++;
        if (bingo[0][4] == -1 && bingo[1][3] == -1 && bingo[2][2] == -1 && bingo[3][1] == -1 && bingo[4][0] == -1) diagonal_count++;
        if (bingo_count + diagonal_count >= 5) {
            printf("BINGO!\n");
            break;
        }
        printf("Keep playing!\n");
    }
    
    printf("Thanks for playing Bingo Simulator!\n");
    return 0;
}