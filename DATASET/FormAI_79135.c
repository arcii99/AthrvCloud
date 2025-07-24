//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function prototypes
void initialize_board(int (*board)[COLS], int num_elements);
void print_board(int (*board)[COLS], int num_elements);
void generate_number(int *num, int (*board)[COLS], int num_elements);
int check_bingo(int (*board)[COLS], int num_elements);

int main() {
    // Seed the random number generator 
    srand(time(NULL));
    
    // Declare and initialize the game board
    int board[ROWS][COLS];
    initialize_board(board, ROWS * COLS);
    
    // Print the initial board
    printf("Welcome to Bingo Simulator\n");
    printf("Here is your game board:\n");
    print_board(board, ROWS * COLS);
    
    // Play the game
    int number;
    int bingo = 0;
    while (!bingo) {
        // Generate a new number
        generate_number(&number, board, ROWS * COLS);
        printf("New number is %d\n", number);
        
        // Check for Bingo
        bingo = check_bingo(board, ROWS * COLS);
    }
    
    // Print final board
    printf("Congratulations, you got a bingo!\n");
    print_board(board, ROWS * COLS);
    
    return 0;
}

void initialize_board(int (*board)[COLS], int num_elements) {
    // Initialize all elements to -1
    for (int i = 0; i < num_elements; i++) {
        *(*(board + i/COLS) + i%COLS) = -1;
    }
}

void print_board(int (*board)[COLS], int num_elements) {
    // Print board in a nice format
    for (int i = 0; i < num_elements; i++) {
        int value = *(*(board + i/COLS) + i%COLS);
        if (value == -1) {
            printf("   ");
        } else {
            printf("%2d ", value);
        }
        if (i % COLS == COLS - 1) {
            printf("\n");
        }
    }
}

void generate_number(int *num, int (*board)[COLS], int num_elements) {
    // Generate a new number that is not already on the board
    int value;
    do {
        value = rand() % (num_elements) + 1;
    } while (check_bingo(board, num_elements) && (*num = value) && value == -1);
    
    // Mark the number on the board
    for (int i = 0; i < num_elements; i++) {
        if (*(*(board + i/COLS) + i%COLS) == value) {
            *(*(board + i/COLS) + i%COLS) = -1;
        }
    }
}

int check_bingo(int (*board)[COLS], int num_elements) {
    // Check for bingo in rows
    for (int i = 0; i < num_elements; i += COLS) {
        int bingo = 1;
        for (int j = 0; j < COLS; j++) {
            if (*(*(board + i/COLS) + j) != -1) {
                bingo = 0;
            }
        }
        if (bingo) {
            return 1;
        }
    }
    
    // Check for bingo in columns
    for (int i = 0; i < COLS; i++) {
        int bingo = 1;
        for (int j = 0; j < num_elements; j += COLS) {
            if (*(*(board + j/COLS) + i) != -1) {
                bingo = 0;
            }
        }
        if (bingo) {
            return 1;
        }
    }
    
    // Check for diagonal bingos
    int diagonal_bingo_1 = 1;
    int diagonal_bingo_2 = 1;
    for (int i = 0; i < num_elements; i += COLS + 1) {
        if (*(*(board + i/COLS) + i%COLS) != -1) {
            diagonal_bingo_1 = 0;
        }
    }
    for (int i = COLS - 1; i < num_elements - 1; i += COLS - 1) {
        if (*(*(board + i/COLS) + i%COLS) != -1) {
            diagonal_bingo_2 = 0;
        }
    }
    if (diagonal_bingo_1 || diagonal_bingo_2) {
        return 1;
    }
    
    // If no bingos, return 0
    return 0;
}