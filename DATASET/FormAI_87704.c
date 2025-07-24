//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function declarations
void init_board(int board[ROWS][COLS]);
void print_board(int board[ROWS][COLS]);
void play_game(int board[ROWS][COLS], int* nums_called);

// Main function
int main() {
    int board[ROWS][COLS];
    int nums_called[76]; // Keep track of numbers called
    srand(time(NULL)); // Set random seed
    
    // Initialize board and number list
    init_board(board);
    for (int i=0; i<76; i++)
        nums_called[i] = 0;
    
    // Play game
    play_game(board, nums_called);
    
    return 0;
}

// Function to initialize the board
void init_board(int board[ROWS][COLS]) {
    // Fill board with zeros
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            board[i][j] = 0;
        }
    }
    // Fill center square as free space
    board[ROWS/2][COLS/2] = -1;
    // Fill remaining squares with random numbers
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (board[i][j] == 0) {
                int num;
                do {
                    num = rand() % 15 + 1 + j*15; // Generate number in range
                } while (num == board[ROWS/2][COLS/2]); // Ensure not same as free space
                board[i][j] = num;
            }
        }
    }
}

// Function to print the board
void print_board(int board[ROWS][COLS]) {
    printf("B  I  N  G  O\n\n");
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (board[i][j] == -1) {
                printf("   ");
            }
            else {
                printf("%2d ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to play the game
void play_game(int board[ROWS][COLS], int* nums_called) {
    int num_calls = 0; // Keep track of number of calls
    printf("Let's play Bingo!\n\n");
    while (1) {
        int num;
        do {
            num = rand() % 75 + 1; // Generate number in range
        } while (nums_called[num] != 0); // Ensure not already called
        nums_called[num] = 1;
        num_calls++;
        printf("Number called: %d\n", num);
        for (int i=0; i<ROWS; i++) {
            for (int j=0; j<COLS; j++) {
                if (board[i][j] == num) {
                    board[i][j] = -1; // Mark square as called
                    print_board(board);
                    // Check for win
                    if (i == j && board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1) {
                        printf("Bingo! Diagonal from top-left to bottom-right.\n");
                        printf("Number of calls: %d\n", num_calls);
                        return;
                    }
                    else if (i+j == 4 && board[4][0] == -1 && board[3][1] == -1 && board[2][2] == -1 && board[1][3] == -1 && board[0][4] == -1) {
                        printf("Bingo! Diagonal from top-right to bottom-left.\n");
                        printf("Number of calls: %d\n", num_calls);
                        return;
                    }
                    else if (board[i][0] == -1 && board[i][1] == -1 && board[i][2] == -1 && board[i][3] == -1 && board[i][4] == -1) {
                        printf("Bingo! Row %d.\n", i+1);
                        printf("Number of calls: %d\n", num_calls);
                        return;
                    }
                    else if (board[0][j] == -1 && board[1][j] == -1 && board[2][j] == -1 && board[3][j] == -1 && board[4][j] == -1) {
                        printf("Bingo! Column %d.\n", j+1);
                        printf("Number of calls: %d\n", num_calls);
                        return;
                    }
                }
            }
        }
    }
}