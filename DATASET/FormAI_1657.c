//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main() {
    int i, j, k, l, m, n, num, check, counter;
    int bingo[ROWS][COLS] = {0};
    int drawn[ROWS*COLS] = {0};
    srand(time(NULL));
    
    printf("Welcome to the Bingo Simulator!\n\n");
    
    // Generate random numbers and fill bingo card
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            num = rand() % 15 + (j * 15) + 1;
            if (j == 2 && i == 2) {
                bingo[i][j] = 0; // Free space
            } else {
                bingo[i][j] = num;
            }
        }
    }
    
    // Display bingo card
    printf("Here is your bingo card:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d\t", bingo[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Play bingo
    counter = 0;
    while (counter < ROWS*COLS) {
        // Draw a random number
        num = rand() % 75 + 1;
        
        // Check if number has already been drawn
        check = 0;
        for (k = 0; k < ROWS*COLS; k++) {
            if (num == drawn[k]) {
                check = 1;
                break;
            }
        }
        if (check == 1) {
            continue; // Number has already been drawn
        }
        
        // Mark number on bingo card
        for (l = 0; l < ROWS; l++) {
            for (m = 0; m < COLS; m++) {
                if (bingo[l][m] == num) {
                    bingo[l][m] = 0;
                    counter++;
                    printf("Number drawn: %d\n", num);
                    break;
                }
            }
        }
        
        // Add drawn number to array
        for (n = 0; n < ROWS*COLS; n++) {
            if (drawn[n] == 0) {
                drawn[n] = num;
                break;
            }
        }
        
        // Check for bingo
        if (bingo[0][0] == 0 && bingo[0][1] == 0 && bingo[0][2] == 0 && bingo[0][3] == 0 && bingo[0][4] == 0) {
            printf("Bingo! Top row\n");
            break;
        } else if (bingo[1][0] == 0 && bingo[1][1] == 0 && bingo[1][2] == 0 && bingo[1][3] == 0 && bingo[1][4] == 0) {
            printf("Bingo! Second row\n");
            break;
        } else if (bingo[2][0] == 0 && bingo[2][1] == 0 && bingo[2][3] == 0 && bingo[2][3] == 0 && bingo[2][4] == 0) {
            printf("Bingo! Third row\n");
            break;
        } else if (bingo[3][0] == 0 && bingo[3][1] == 0 && bingo[3][2] == 0 && bingo[3][3] == 0 && bingo[3][4] == 0) {
            printf("Bingo! Fourth row\n");
            break;
        } else if (bingo[4][0] == 0 && bingo[4][1] == 0 && bingo[4][2] == 0 && bingo[4][3] == 0 && bingo[4][4] == 0) {
            printf("Bingo! Bottom row\n");
            break;
        } else if (bingo[0][0] == 0 && bingo[1][0] == 0 && bingo[2][0] == 0 && bingo[3][0] == 0 && bingo[4][0] == 0) {
            printf("Bingo! Left column\n");
            break;
        } else if (bingo[0][1] == 0 && bingo[1][1] == 0 && bingo[2][1] == 0 && bingo[3][1] == 0 && bingo[4][1] == 0) {
            printf("Bingo! Second column\n");
            break;
        } else if (bingo[0][2] == 0 && bingo[1][2] == 0 && bingo[2][2] == 0 && bingo[3][2] == 0 && bingo[4][2] == 0) {
            printf("Bingo! Third column\n");
            break;
        } else if (bingo[0][3] == 0 && bingo[1][3] == 0 && bingo[2][3] == 0 && bingo[3][3] == 0 && bingo[4][3] == 0) {
            printf("Bingo! Fourth column\n");
            break;
        } else if (bingo[0][4] == 0 && bingo[1][4] == 0 && bingo[2][4] == 0 && bingo[3][4] == 0 && bingo[4][4] == 0)  {
            printf("Bingo! Right column\n");
            break;
        } else if (bingo[0][0] == 0 && bingo[1][1] == 0 && bingo[3][3] == 0 && bingo[4][4] == 0) {
            printf("Bingo! Diagonal\n");
            break;
        } else if (bingo[0][4] == 0 && bingo[1][3] == 0 && bingo[2][2] == 0 && bingo[3][1] == 0 && bingo[4][0] == 0) {
            printf("Bingo! Diagonal\n");
            break;
        }
    }
    printf("\n");
    printf("Thanks for playing!\n");
    return 0;
}