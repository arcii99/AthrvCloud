//FormAI DATASET v1.0 Category: Table Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define NUM_ROWS 3
#define NUM_COLS 3
#define EMPTY_CELL ' '
#define PLAYER1 'X'
#define PLAYER2 'O'

// Function declarations
void display_board(char board[NUM_ROWS][NUM_COLS]);
char get_winner(char board[NUM_ROWS][NUM_COLS]);
int game_over(char board[NUM_ROWS][NUM_COLS]);
int valid_move(char board[NUM_ROWS][NUM_COLS], int row, int col);
void play_game(char board[NUM_ROWS][NUM_COLS]);

// Main function
int main() {
    char board[NUM_ROWS][NUM_COLS] = {
        {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
        {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
        {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
    };
    
    // Seed random number generator
    srand(time(NULL));
    
    // Play the game
    play_game(board);
    
    return 0;
}

// Display the game board
void display_board(char board[NUM_ROWS][NUM_COLS]) {
    printf("   1   2   3  \n");
    printf("  ---|---|---\n");
    printf("1| %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
    printf("  ---|---|---\n");
    printf("2| %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
    printf("  ---|---|---\n");
    printf("3| %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
    printf("  ---|---|---\n");
}

// Determine if there is a winner
char get_winner(char board[NUM_ROWS][NUM_COLS]) {
    // Check rows
    for (int row = 0; row < NUM_ROWS; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            return board[row][0];
        }
    }
    
    // Check columns
    for (int col = 0; col < NUM_COLS; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            return board[0][col];
        }
    }
    
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    
    // No winner
    return EMPTY_CELL;
}

// Determine if the game is over
int game_over(char board[NUM_ROWS][NUM_COLS]) {
    // Check if there is a winner
    char winner = get_winner(board);
    if (winner != EMPTY_CELL) {
        printf("%c wins!\n", winner);
        return 1;
    }
    
    // Check for a tie
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            if (board[row][col] == EMPTY_CELL) {
                // Game is not over
                return 0;
            }
        }
    }
    
    // Game is a tie
    printf("Game is a tie!\n");
    return 1;
}

// Determine if a move is valid
int valid_move(char board[NUM_ROWS][NUM_COLS], int row, int col) {
    if (row < 0 || row >= NUM_ROWS || col < 0 || col >= NUM_COLS) {
        // Out of bounds
        return 0;
    }
    
    if (board[row][col] != EMPTY_CELL) {
        // Cell is not empty
        return 0;
    }
    
    // Move is valid
    return 1;
}

// Play the game
void play_game(char board[NUM_ROWS][NUM_COLS]) {
    char current_player = PLAYER1;
    
    while (!game_over(board)) {
        printf("Current player: %c\n", current_player);
        display_board(board);
        
        int row, col;
        do {
            // Get user input
            printf("Enter row (1-3): ");
            scanf("%d", &row);
            row--;  // Convert to 0-based index
            
            printf("Enter column (1-3): ");
            scanf("%d", &col);
            col--;  // Convert to 0-based index
            
            // Check if move is valid
            if (!valid_move(board, row, col)) {
                printf("Invalid move!\n");
            }
        } while (!valid_move(board, row, col));
        
        // Make the move
        board[row][col] = current_player;
        
        // Switch players
        if (current_player == PLAYER1) {
            current_player = PLAYER2;
        } else {
            current_player = PLAYER1;
        }
    }
    
    // Display final board
    display_board(board);
}