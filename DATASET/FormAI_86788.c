//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: paranoid
#include <stdio.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

int main() {
    int bingo_board[ROWS][COLS] = {0};
    int num_calls = 0;

    // Populate board with random numbers
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            bingo_board[i][j] = rand() % 75 + 1;
        }
    }
    
    // Print initial bingo board
    printf("Welcome to paranoid bingo simulator! Here is your board:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", bingo_board[i][j]);
        }
        printf("\n");
    }
    
    // Start calling numbers
    while (true) {
        int call = rand() % 75 + 1;
        bool found = false;
        
        // Check if call is on board
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (bingo_board[i][j] == call) {
                    bingo_board[i][j] = 0;
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        
        // Print call and updated board
        printf("The caller says: %d\n", call);
        printf("Here is your updated board:\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%2d ", bingo_board[i][j]);
            }
            printf("\n");
        }
        
        // Check for bingo
        bool bingo = false;
        
        // Check rows
        for (int i = 0; i < ROWS; i++) {
            bool row_bingo = true;
            for (int j = 0; j < COLS; j++) {
                if (bingo_board[i][j] != 0) {
                    row_bingo = false;
                    break;
                }
            }
            if (row_bingo) {
                bingo = true;
                break;
            }
        }
        
        // Check columns
        for (int j = 0; j < COLS; j++) {
            bool col_bingo = true;
            for (int i = 0; i < ROWS; i++) {
                if (bingo_board[i][j] != 0) {
                    col_bingo = false;
                    break;
                }
            }
            if (col_bingo) {
                bingo = true;
                break;
            }
        }
        
        // Check diagonals
        if (bingo_board[0][0] == 0 && bingo_board[1][1] == 0 && bingo_board[2][2] == 0 && bingo_board[3][3] == 0 && bingo_board[4][4] == 0) {
            bingo = true;
        }
        if (bingo_board[4][0] == 0 && bingo_board[3][1] == 0 && bingo_board[2][2] == 0 && bingo_board[1][3] == 0 && bingo_board[0][4] == 0) {
            bingo = true;
        }
        
        // Print bingo message and exit loop
        if (bingo) {
            printf("Congratulations, you have achieved paranoid bingo!\n");
            break;
        }
        
        num_calls++;
        if (num_calls >= 100) {
            printf("Too many calls, aborting paranoid bingo.\n");
            break;
        }
    }
    
    return 0;
}