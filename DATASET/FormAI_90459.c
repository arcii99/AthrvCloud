//FormAI DATASET v1.0 Category: Checkers Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// Initialize the board with checkers pieces
void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if ((row + col) % 2 == 0) {
                if (row < 3) {
                    board[row][col] = 'C'; // Cyberpunk checkers represented by "C"
                } else if (row > 4) {
                    board[row][col] = 'H'; // Human checkers represented by "H"
                } else {
                    board[row][col] = ' '; // Empty space on the board
                }
            } else {
                board[row][col] = ' '; // Empty space on the board
            }
        }
    }
}

// Print the current board state
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("---------------------\n");

    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("|");
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf(" %c |", board[row][col]);
        }
        printf("\n---------------------\n");
    }
}

// Validate if a given move is legal
bool validate_move(char board[BOARD_SIZE][BOARD_SIZE], int from_row, int from_col, int to_row, int to_col, char player) {
    if (from_row < 0 || from_row >= BOARD_SIZE
        || from_col < 0 || from_col >= BOARD_SIZE
        || to_row < 0 || to_row >= BOARD_SIZE
        || to_col < 0 || to_col >= BOARD_SIZE) {
        return false; // Out of bounds move
    }

    if (board[to_row][to_col] != ' ' || (to_row + to_col) % 2 == 0) {
        return false; // Not an empty space or not a dark colored square
    }

    int row_diff = to_row - from_row;
    int col_diff = to_col - from_col;

    if (player == 'C') { // Cyberpunk player
        if (row_diff == 1 && (col_diff == -1 || col_diff == 1)) {
            return true; // Regular move
        } else if (row_diff == 2 && (col_diff == -2 || col_diff == 2)) {
            // Check if the player is jumping over an opponent's piece
            int mid_row = (from_row + to_row) / 2;
            int mid_col = (from_col + to_col) / 2;

            if (board[mid_row][mid_col] == 'H') {
                return true; // Legal jump move
            }
        }
    } else { // Human player
        if (row_diff == -1 && (col_diff == -1 || col_diff == 1)) {
            return true; // Regular move
        } else if (row_diff == -2 && (col_diff == -2 || col_diff == 2)) {
            // Check if the player is jumping over an opponent's piece
            int mid_row = (from_row + to_row) / 2;
            int mid_col = (from_col + to_col) / 2;

            if (board[mid_row][mid_col] == 'C') {
                return true; // Legal jump move
            }
        }
    }

    return false; // Invalid move
}

// Execute a given move
void execute_move(char board[BOARD_SIZE][BOARD_SIZE], int from_row, int from_col, int to_row, int to_col) {
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = ' ';
}

// Check if the game has ended
bool game_ended(char board[BOARD_SIZE][BOARD_SIZE]) {
    int cyberpunk_pieces = 0;
    int human_pieces = 0;

    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == 'C') {
                cyberpunk_pieces++;
            } else if (board[row][col] == 'H') {
                human_pieces++;
            }
        }
    }

    return cyberpunk_pieces == 0 || human_pieces == 0;
}

// Main function to play the game
int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);

    char currentPlayer = 'C'; // Cyberpunk player starts first
    char opponentPlayer = 'H';

    while (!game_ended(board)) {
        print_board(board);

        printf("%c player's turn\n", currentPlayer);
        printf("Enter row and column numbers of the piece to move: ");
        int from_row, from_col;
        scanf("%d %d", &from_row, &from_col);

        printf("Enter row and column numbers of the destination: ");
        int to_row, to_col;
        scanf("%d %d", &to_row, &to_col);

        if (validate_move(board, from_row, from_col, to_row, to_col, currentPlayer)) {
            execute_move(board, from_row, from_col, to_row, to_col);

            if (currentPlayer == 'C') { // Cyberpunk player's turn is over
                currentPlayer = 'H';
                opponentPlayer = 'C';
            } else { // Human player's turn is over
                currentPlayer = 'C';
                opponentPlayer = 'H';
            }
        } else {
            printf("Invalid move! Try again.\n");
        }
    }

    print_board(board);

    if (currentPlayer == 'C') { // Human player won
        printf("Congratulations! You have defeated the Cyberpunks!\n");
    } else { // Cyberpunk player won
        printf("Game over! The Cyberpunks have won!\n");
    }

    return 0;
}