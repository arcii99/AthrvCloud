//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Size of the bingo card
#define ROWS 5
#define COLS 5

// Function to initialize the bingo card
void init_board(int board[][COLS]) {
    // Randomly generate the numbers for the bingo card
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Skip the center square
            if (i == 2 && j == 2) {
                continue;
            }
            // Generate a random number between 1 and 75
            int num = rand() % 75 + 1;
            // Check if the number is already on the card
            bool duplicate;
            do {
                duplicate = false;
                for (int k = 0; k < i; k++) {
                    for (int l = 0; l < COLS; l++) {
                        if (board[k][l] == num) {
                            duplicate = true;
                            num = rand() % 75 + 1;
                            break;
                        }
                    }
                    if (duplicate) {
                        break;
                    }
                }
            } while (duplicate);
            // Add the number to the card
            board[i][j] = num;
        }
    }
}

// Function to print the current state of the bingo card
void print_board(int board[][COLS], bool marked[][COLS]) {
    printf("\n  B  I  N  G  O\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf(" %2d ", board[i][j]);
            if (marked[i][j]) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to check if the player has won
bool check_win(bool marked[][COLS]) {
    // Check horizontal rows
    for (int i = 0; i < ROWS; i++) {
        if (marked[i][0] && marked[i][1] && marked[i][2] && marked[i][3] && marked[i][4]) {
            return true;
        }
    }
    // Check vertical columns
    for (int j = 0; j < COLS; j++) {
        if (marked[0][j] && marked[1][j] && marked[2][j] && marked[3][j] && marked[4][j]) {
            return true;
        }
    }
    // Check diagonal
    if (marked[0][0] && marked[1][1] && marked[2][2] && marked[3][3] && marked[4][4]) {
        return true;
    }
    if (marked[0][4] && marked[1][3] && marked[2][2] && marked[3][1] && marked[4][0]) {
        return true;
    }
    // No win
    return false;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    // Initialize the bingo card and marker array
    int board[ROWS][COLS];
    bool marked[ROWS][COLS] = {false};
    init_board(board);
    // Game loop
    while (true) {
        // Print the current state of the bingo card
        print_board(board, marked);
        // Prompt the user for the next number
        int num;
        printf("\nEnter the next number (1-75): ");
        scanf("%d", &num);
        // Mark the number as found on the card
        bool found = false;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == num) {
                    marked[i][j] = true;
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        // Check if the player has won
        if (check_win(marked)) {
            printf("\nBINGO! You have won!\n");
            break;
        }
    }
    return 0;
}