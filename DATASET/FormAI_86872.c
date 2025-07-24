//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Game constants
#define ROWS 10
#define COLUMNS 10
#define SHIP_SIZE 3

// Function prototypes
void clear_board(int board[][COLUMNS]);
void display_board(int board[][COLUMNS]);
void place_ship(int board[][COLUMNS], int row, int col, bool isVertical);
bool is_valid_move(int board[][COLUMNS], int row, int col);
bool is_game_over(int board[][COLUMNS]);

// Main function
int main(void) {
    // Initialize the random seed
    srand(time(NULL));
    
    // Initialize the game board
    int board[ROWS][COLUMNS];
    clear_board(board);
    
    // Place the ship in a random position and orientation
    int row, col;
    bool isVertical;
    do {
        row = rand() % ROWS;
        col = rand() % COLUMNS;
        isVertical = rand() % 2 == 0;
    } while (!is_valid_move(board, row, col));
    place_ship(board, row, col, isVertical);
    
    // Start the game loop
    int shots = 0;
    while (!is_game_over(board)) {
        // Display the game board
        printf("Shots fired: %d\n", shots);
        display_board(board);
        
        // Ask the player for a move
        printf("Enter a row and a column (separated by a space): ");
        scanf("%d %d", &row, &col);
        
        // Check if the move is valid
        if (!is_valid_move(board, row, col)) {
            printf("Invalid move!\n");
            continue;
        }
        
        // Fire a shot
        board[row][col] = -1;
        shots++;
    }
    
    // Display the final score
    printf("Game over! You won in %d shots!\n", shots);
    
    return 0;
}

// Clear the game board
void clear_board(int board[][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = 0;
        }
    }
}

// Display the game board
void display_board(int board[][COLUMNS]) {
    printf("  ");
    for (int j = 0; j < COLUMNS; j++) {
        printf(" %d", j);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i);
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] < 0) {
                printf(" X");
            } else if (board[i][j] > 0) {
                printf(" O");
            } else {
                printf(" .");
            }
        }
        printf("\n");
    }
}

// Place the ship on the game board
void place_ship(int board[][COLUMNS], int row, int col, bool isVertical) {
    for (int i = 0; i < SHIP_SIZE; i++) {
        if (isVertical) {
            board[row + i][col] = 1;
        } else {
            board[row][col + i] = 1;
        }
    }
}

// Check if a move is valid
bool is_valid_move(int board[][COLUMNS], int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLUMNS) {
        return false;
    }
    if (board[row][col] != 0) {
        return false;
    }
    return true;
}

// Check if the game is over
bool is_game_over(int board[][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}