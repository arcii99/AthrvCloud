//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

// Function to check if a given number is already present in the bingo board
int checkDuplicate(int num, int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == num) {
                return 1;   // Number already present in board
            }
        }
    }
    return 0;   // Number not present in board
}

/* Main function */
int main() {

    // Initializing bingo board
    int board[ROWS][COLS] = {0};

    // Seeding random generator with current time
    srand(time(NULL));

    // Generating random numbers for the bingo board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int num = rand() % MAX_NUM + 1; // Random number between 1 and 75
            while (checkDuplicate(num, board)) { // Checking for duplicates
                num = rand() % MAX_NUM + 1; // Generating another random number
            }
            board[i][j] = num;
        }
    }

    // Displaying the bingo board
    printf("---------------------------------------------------\n");
    printf("| B  | I  | N  | G  | O  |\n");
    printf("|----|----|----|----|----|\n");
    for (int i = 0; i < ROWS; i++) {
        printf("| %2d | %2d | %2d | %2d | %2d |\n",
            board[i][0], board[i][1], board[i][2], board[i][3], board[i][4]);
        printf("|----|----|----|----|----|\n");
    }
    printf("---------------------------------------------------\n");

    return 0;
}