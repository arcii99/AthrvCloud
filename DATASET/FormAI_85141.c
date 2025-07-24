//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: modular
/* 
*  C Bingo Simulator Example Program
*  Written by: [Your Name]
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

/* Function to generate a random number within a given range */
int random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/* Function to check if a number is already present in the given array */
int check_duplicate(int num, int arr[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

/* Function to print the current state of the bingo board */
void print_board(int board[ROWS][COLS]) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/* Function to check if a bingo has been achieved */
int check_bingo(int board[ROWS][COLS]) {
    int count = 0;
    
    // Check rows for bingo
    for (int i = 0; i < ROWS; i++) {
        int row_count = 0;
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                row_count++;
            }
        }
        if (row_count == COLS) {
            count++;
        }
    }
    
    // Check columns for bingo
    for (int i = 0; i < ROWS; i++) {
        int col_count = 0;
        for (int j = 0; j < COLS; j++) {
            if (board[j][i] == -1) {
                col_count++;
            }
        }
        if (col_count == ROWS) {
            count++;
        }
    }
    
    // Check diagonals for bingo
    if (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1) {
        count++;
    }
    if (board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1) {
        count++;
    }
    
    return count;
}

int main() {
    // Initialize board to all zeros
    int board[ROWS][COLS] = {0};
    
    // Seed random number generator
    srand(time(NULL));
    
    // Fill in board with random numbers from 1 to 25
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int num;
            do {
                num = random_int(1, 25);
            } while (check_duplicate(num, board));
            board[i][j] = num;
        }
    }
    
    // Replace center number with -1 (free space)
    board[2][2] = -1;
    
    // Print initial state of board
    print_board(board);
    
    // Keep generating random numbers until bingo is achieved
    int count = 0;
    while (count < ROWS + COLS + 2) {
        int num;
        do {
            num = random_int(1, 25);
        } while (check_duplicate(num, board));
        
        // Mark cell with -1 if number is found
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == num) {
                    board[i][j] = -1;
                    break;
                }
            }
        }
        
        // Print current state of board
        print_board(board);
        
        // Check for bingo
        int bingo_count = check_bingo(board);
        if (bingo_count > count) {
            printf("Bingo!\n");
            count = bingo_count;
        }
        
        // Pause for a second before generating next number
        sleep(1);
    }
    
    return 0;
}