//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to check if a number is present in the given (2D) array
int check_number(int num, int arr[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[i][j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to print the current state of the bingo board
void print_board(int arr[5][5]) {
    printf("\nCurrent Board State:\n\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[i][j] == -1) {
                printf("  X ");
            } else {
                printf("%3d ", arr[i][j]);
            }
        }
        printf("\n\n");
    }
}

int main() {
    // Declarations
    int board[5][5];
    int used_nums[75] = {0};
    int calls = 0;
    int done = 0;
    int num;

    // Initialize random number generation
    srand(time(NULL));

    // Initialize board to all -1's (which represent un-marked numbers)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            board[i][j] = -1;
        }
    }

    // Print intro message
    printf("Welcome to the Bingo Simulator!\n\n");

    // Loop until all numbers have been called
    while (!done) {
        // Generate a random number from 1-75 that hasn't been called yet
        do {
            num = rand() % 75 + 1;
        } while (check_number(num, board) || used_nums[num-1]);
        used_nums[num-1] = 1;

        // Increment calls counter
        calls++;

        // Display called number
        printf("Called number: %d\n\n", num);

        // Check if number is present on board and mark it if so
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == num) {
                    board[i][j] = -1;
                } else if (board[i][j] == -1 && ((i == 2 && j == 2) || num == (i*15)+(j+1))) {
                    board[i][j] = num;
                }
            }
        }

        // Print current board state
        print_board(board);

        // Check for winning condition
        int win = 0;
        for (int i = 0; i < 5; i++) {
            int row = 1;
            int col = 1;
            for (int j = 0; j < 5; j++) {
                if (board[i][j] != -1) {
                    row = 0;
                }
                if (board[j][i] != -1) {
                    col = 0;
                }
            }
            if (row || col) {
                win = 1;
            }
        }
        int diag1 = 1;
        int diag2 = 1;
        for (int i = 0; i < 5; i++) {
            if (board[i][i] != -1) {
                diag1 = 0;
            }
            if (board[i][4-i] != -1) {
                diag2 = 0;
            }
        }
        if (diag1 || diag2) {
            win = 1;
        }
        if (win) {
            done = 1;
            printf("Congratulations, you won Bingo!\n");
            printf("It took %d calls.\n", calls);
        }
    }

    return 0;
}