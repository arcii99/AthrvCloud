//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5

void init_board(int board[ROWS][COLUMNS]);
void display_board(int board[ROWS][COLUMNS]);
void generate_numbers(int nums[75]);
int check_bingo(int board[ROWS][COLUMNS]);

int main() {
    int board[ROWS][COLUMNS];
    int nums[75];
    int num_called, row, col, count = 0, bingo = 0;
    char choice;
    
    init_board(board);
    generate_numbers(nums);
    
    while (!bingo) {
        // Randomly select a number
        num_called = nums[rand() % 75];
        printf("Number called: %d\n", num_called);
        
        // Check if number called is on the board
        for (row = 0; row < ROWS; row++) {
            for (col = 0; col < COLUMNS; col++) {
                if (board[row][col] == num_called) {
                    board[row][col] = 0; // Mark number as called
                    count++;
                    break;
                }
            }
        }
        
        // Display current board
        display_board(board);
        
        // Check if there is a bingo
        bingo = check_bingo(board);
        if (bingo) {
            printf("BINGO! You won in %d calls.\n", count);
            break;
        }
        
        // Ask user to continue or quit
        printf("Press enter to continue or q to quit: ");
        scanf(" %c", &choice);
        if (choice == 'q') {
            printf("Thanks for playing.\n");
            break;
        }
    }
    
    return 0;
}

void init_board(int board[ROWS][COLUMNS]) {
    int i, j;
    
    // Initialize board with random numbers
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            board[i][j] = rand() % 75 + 1;
        }
    }
    
    // Mark center as FREE space
    board[ROWS/2][COLUMNS/2] = 0;
}

void display_board(int board[ROWS][COLUMNS]) {
    int i, j;
    
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void generate_numbers(int nums[75]) {
    int i;
    
    // Generate unique numbers 1-75
    for (i = 0; i < 75; i++) {
        nums[i] = i + 1;
    }
    // Shuffle numbers array
    srand(time(NULL));
    for (i = 0; i < 75; i++) {
        int j = rand() % 75;
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

int check_bingo(int board[ROWS][COLUMNS]) {
    int i, j, count;
    
    // Check horizontal lines
    for (i = 0; i < ROWS; i++) {
        count = 0;
        for (j = 0; j < COLUMNS; j++) {
            if (board[i][j] == 0) {
                count++;
            }
        }
        if (count == COLUMNS) {
            return 1; // Bingo found
        }
    }
    
    // Check vertical lines
    for (j = 0; j < COLUMNS; j++) {
        count = 0;
        for (i = 0; i < ROWS; i++) {
            if (board[i][j] == 0) {
                count++;
            }
        }
        if (count == ROWS) {
            return 1; // Bingo found
        }
    }
    
    // Check diagonal lines
    count = 0; // Top-left to bottom-right diagonal
    for (i = 0, j = 0; i < ROWS; i++, j++) {
        if (board[i][j] == 0) {
            count++;
        }
    }
    if (count == ROWS) {
        return 1; // Bingo found
    }
    
    count = 0; // Top-right to bottom-left diagonal
    for (i = 0, j = COLUMNS - 1; i < ROWS; i++, j--) {
        if (board[i][j] == 0) {
            count++;
        }
    }
    if (count == ROWS) {
        return 1; // Bingo found
    }
    
    return 0; // No bingo found
}