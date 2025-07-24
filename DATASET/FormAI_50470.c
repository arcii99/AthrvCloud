//FormAI DATASET v1.0 Category: Table Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defining the board size
#define ROWS 6
#define COLS 6

// Global variables
int board[ROWS][COLS];
int player_turn = 1;

// Function to print the board
void print_board() {
    printf("\n   |");
    for(int i=0; i<COLS; i++) {
        printf(" %d |", i+1);
    }
    printf("\n");

    printf("---+");
    for(int i=0; i<COLS; i++) {
        printf("---+");
    }
    printf("\n");

    for(int i=0; i<ROWS; i++) {
        printf(" %d |", i+1);
        for(int j=0; j<COLS; j++) {
            printf(" %d |", board[i][j]);
        }
        printf("\n");

        printf("---+");
        for(int j=0; j<COLS; j++) {
            printf("---+");
        }
        printf("\n");
    }
}

// Function to check if a move is valid
int is_valid_move(int row, int col) {
    if(row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0; // Out of bounds
    }
    if(board[row][col] != 0) {
        return 0; // Cell already occupied
    }
    return 1;
}

// Function to check if all the cells are filled
int is_board_full() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to check if any player has won
int is_game_over() {
    // Check rows
    for(int i=0; i<ROWS; i++) {
        int count = 0;
        int current = 0;
        for(int j=0; j<COLS; j++) {
            if(board[i][j] == current) {
                count++;
            } else {
                count = 1;
                current = board[i][j];
            }
            if(count == 4 && current != 0) {
                return current;
            }
        }
    }

    // Check columns
    for(int j=0; j<COLS; j++) {
        int count = 0;
        int current = 0;
        for(int i=0; i<ROWS; i++) {
            if(board[i][j] == current) {
                count++;
            } else {
                count = 1;
                current = board[i][j];
            }
            if(count == 4 && current != 0) {
                return current;
            }
        }
    }

    // Check diagonals
    for(int i=0; i<ROWS-3; i++) {
        for(int j=0; j<COLS-3; j++) {
            if(board[i][j] != 0 && board[i][j] == board[i+1][j+1] && 
               board[i][j] == board[i+2][j+2] && board[i][j] == board[i+3][j+3]) {
                return board[i][j];
            }
        }
    }
    for(int i=0; i<ROWS-3; i++) {
        for(int j=3; j<COLS; j++) {
            if(board[i][j] != 0 && board[i][j] == board[i+1][j-1] &&
               board[i][j] == board[i+2][j-2] && board[i][j] == board[i+3][j-3]) {
                return board[i][j];
            }
        }
    }

    // If all cells are filled, declare a tie
    if(is_board_full()) {
        return 3;
    }

    // Game is not over yet
    return 0;
}

// Function to make a move
void make_move(int row, int col) {
    if(is_valid_move(row, col)) {
        board[row][col] = player_turn;
        player_turn = (player_turn == 1) ? 2 : 1;
    } else {
        printf("Invalid move!\n");
    }
}

// Main function
int main() {
    // Setting up the board
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = 0;
        }
    }

    // Printing the initial board
    print_board();

    // Game loop
    while(1) {
        // Checking if game is over
        int game_result = is_game_over();
        if(game_result == 1) {
            printf("Player 1 wins!\n");
            break;
        } else if(game_result == 2) {
            printf("Player 2 wins!\n");
            break;
        } else if(game_result == 3) {
            printf("It's a tie!\n");
            break;
        }

        // Making a move
        int row, col;
        printf("Player %d: Enter row and column (e.g. 3 4): ", player_turn);
        scanf("%d %d", &row, &col);
        make_move(row-1, col-1);

        // Printing the board
        print_board();
    }

    return 0;
}