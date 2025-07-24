//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void mark_bingo(char bingo_board[ROWS][COLS], int num);
bool check_bingo(char bingo_board[ROWS][COLS]);

int main() {
    char bingo_board[ROWS][COLS] = {0};
    int count = 1;

    // Randomize seed
    srand(time(NULL));

    printf("Welcome to the Bingo Simulator game!\n");
    printf("Press enter to start the game!");
    getchar();

    // Game starts
    while (true) {
        int num = rand() % 75 + 1;

        // Mark the number on the bingo board
        mark_bingo(bingo_board, num);

        // Print out the bingo board
        printf("\n==========================\n");
        printf("Current Number: %d\n\n", num);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%d\t", bingo_board[i][j]);
            }
            printf("\n");
        }
        printf("==========================\n");

        // Check if any player has a bingo
        if (check_bingo(bingo_board)) {
            printf("\n\nCongratulations! We have a winner!\n");
            break;
        }

        // Increase count
        count++;

        // Ask player to continue or quit
        printf("\n\nCurrent count: %d\n", count);
        printf("Press enter to continue or q to quit: ");
        char input = getchar();
        if (input == 'q') {
            printf("\n\nYou have quit the game!");
            break;
        }
    }

    // End of game
    printf("\n\nThanks for playing the Bingo Simulator game!\n");

    return 0;
}

void mark_bingo(char bingo_board[ROWS][COLS], int num) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (bingo_board[i][j] == num) {
                bingo_board[i][j] = 'X';
            }
        }
    }
}

bool check_bingo(char bingo_board[ROWS][COLS]) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        int count = 0;
        for (int j = 0; j < COLS; j++) {
            if (bingo_board[i][j] == 'X') {
                count++;
            }
            if (count == COLS) {
                return true;
            }
        }
    }

    // Check columns
    for (int j = 0; j < COLS; j++) {
        int count = 0;
        for (int i = 0; i < ROWS; i++) {
            if (bingo_board[i][j] == 'X') {
                count++;
            }
            if (count == ROWS) {
                return true;
            }
        }
    }

    // Check diagonals
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < ROWS; i++) {
        if (bingo_board[i][i] == 'X') {
            count1++;
        }
        if (bingo_board[i][ROWS-1-i] == 'X') {
            count2++;
        }
    }
    if (count1 == ROWS || count2 == ROWS) {
        return true;
    }

    // No bingo found
    return false;
}