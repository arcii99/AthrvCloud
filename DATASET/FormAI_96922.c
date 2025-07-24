//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function that checks if a number already exists in the board
int is_unique(int board[][COLS], int num) {
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// Function that generates a random number from 1 to 75
int generate_num() {
    return (rand() % 75) + 1;
}

// Function that checks if a player's board has a Bingo
int check_bingo(int board[][COLS]) {
    int i, j, k;
    // Check rows
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            if (board[i][j] != -1) {
                break;
            }
        }
        if (j == COLS) {
            return 1;
        }
    }
    // Check columns
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            if (board[j][i] != -1) {
                break;
            }
        }
        if (j == ROWS) {
            return 1;
        }
    }
    // Check diagonals
    for (i=0, j=0; i<ROWS && j<COLS; i++, j++) {
        if (board[i][j] != -1) {
            break;
        }
    }
    if (j == ROWS) {
        return 1;
    }
    for (i=ROWS-1, j=0; i>=0 && j<COLS; i--, j++) {
        if (board[i][j] != -1) {
            break;
        }
    }
    if (j == ROWS) {
        return 1;
    }
    return 0;
}

int main() {
    int player1[ROWS][COLS], player2[ROWS][COLS];
    int num, i, j, count;
    char choice;
    srand(time(0));
    printf("Welcome to the Bingo Simulator!\n");
    // Initialize player boards to -1
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            player1[i][j] = -1;
            player2[i][j] = -1;
        }
    }
    // Generate random numbers for player 1 board
    count = 0;
    while (count < 25) {
        num = generate_num();
        if (is_unique(player1, num)) {
            player1[count/COLS][count%COLS] = num;
            count++;
        }
    }
    // Generate random numbers for player 2 board
    count = 0;
    while (count < 25) {
        num = generate_num();
        if (is_unique(player2, num)) {
            player2[count/COLS][count%COLS] = num;
            count++;
        }
    }
    // Main loop for playing the game
    while (1) {
        // Player 1 turn
        printf("Player 1, press enter to generate a random number:");
        getchar();
        num = generate_num();
        printf("The number is: %d\n", num);
        for (i=0; i<ROWS; i++) {
            for (j=0; j<COLS; j++) {
                if (player1[i][j] == num) {
                    player1[i][j] = -1;
                }
            }
        }
        if (check_bingo(player1)) {
            printf("Player 1 has won the game! Congratulations!\n");
            break;
        }
        // Player 2 turn
        printf("Player 2, press enter to generate a random number:");
        getchar();
        num = generate_num();
        printf("The number is: %d\n", num);
        for (i=0; i<ROWS; i++) {
            for (j=0; j<COLS; j++) {
                if (player2[i][j] == num) {
                    player2[i][j] = -1;
                }
            }
        }
        if (check_bingo(player2)) {
            printf("Player 2 has won the game! Congratulations!\n");
            break;
        }
        // Ask players if they want to quit
        printf("Do you want to quit? (y/n):");
        scanf(" %c", &choice);
        if (choice == 'y') {
            break;
        }
    }
    printf("Thanks for playing the Bingo Simulator!\n");
    return 0;
}