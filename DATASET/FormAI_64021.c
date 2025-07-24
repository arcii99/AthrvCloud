//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define FREE_SPACE 12

int main() {
    srand(time(NULL)); // seed the random number generator with current time
    
    int bingo[ROWS][COLS]; // create 2D array to hold bingo card
    int num, numsDrawn = 0; // initialize variables for number and numbers drawn
    int row, col, win = 0; // initialize variables for row, column, and win
    
    // Populate bingo card with random numbers
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            if (row == 2 && col == 2) { // add free space in the middle
                bingo[row][col] = FREE_SPACE;
            } else { // add random number between 1-75
                num = rand() % 75 + 1;
                // check if number has already been added
                while (numsDrawn < 24) { // 24 = total number of spaces on bingo card
                    if (num == bingo[row][0] || num == bingo[row][1] || num == bingo[row][2] ||
                        num == bingo[row][3] || num == bingo[row][4]) {
                        num = rand() % 75 + 1; // generate new random number
                    } else {
                        break;
                    }
                }
                bingo[row][col] = num; // add random number to bingo card
                numsDrawn++;
            }
        }
    }
    
    // Display bingo card to player
    printf("Welcome to C Bingo Simulator!\n\n");
    printf("*********************\n");
    printf("* B   I   N   G   O *\n");
    printf("*********************\n");
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            if (bingo[row][col] < 10) {
                printf("* %d  ", bingo[row][col]);
            } else {
                printf("* %d ", bingo[row][col]);
            }
        }
        printf("*\n");
    }
    printf("*********************\n\n");
    
    // Play bingo game
    while (win == 0) {
        printf("Press enter to draw a number...\n");
        getchar(); // pause game until player presses enter
        num = rand() % 75 + 1; // generate random number between 1-75
        printf("The next number is: %d\n\n", num);
        for (row = 0; row < ROWS; row++) {
            for (col = 0; col < COLS; col++) {
                if (bingo[row][col] == num) { // mark number on bingo card
                    bingo[row][col] = -1;
                    break;
                }
            }
        }
        
        // Check for a winning combination
        // Check rows
        for (row = 0; row < ROWS; row++) {
            if (bingo[row][0] == -1 && bingo[row][1] == -1 && bingo[row][2] == -1 &&
                bingo[row][3] == -1 && bingo[row][4] == -1) {
                printf("BINGO! You won on row %d!\n", row+1);
                win = 1;
                break;
            }
        }
        // Check columns
        for (col = 0; col < COLS; col++) {
            if (bingo[0][col] == -1 && bingo[1][col] == -1 && bingo[2][col] == -1 &&
                bingo[3][col] == -1 && bingo[4][col] == -1) {
                printf("BINGO! You won on column %d!\n", col+1);
                win = 1;
                break;
            }
        }
        // Check diagonal
        if (bingo[0][0] == -1 && bingo[1][1] == -1 && bingo[2][2] == -1 &&
            bingo[3][3] == -1 && bingo[4][4] == -1) {
            printf("BINGO! You won on the diagonal!\n");
            win = 1;
        }
        if (bingo[0][4] == -1 && bingo[1][3] == -1 && bingo[2][2] == -1 &&
            bingo[3][1] == -1 && bingo[4][0] == -1) {
            printf("BINGO! You won on the diagonal!\n");
            win = 1;
        }
    }
    printf("\nCongratulations! Thanks for playing C Bingo Simulator!\n");
    return 0;
}