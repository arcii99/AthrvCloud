//FormAI DATASET v1.0 Category: Chess engine ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants for board size and maximum number of moves
#define BOARD_SIZE 8
#define MAX_MOVES 50

// Struct to represent a single move
typedef struct {
    int from_row;
    int from_col;
    int to_row;
    int to_col;
} Move;

// Board represented as a 2D array of integers, where each integer
// represents a piece or an empty square (0 means empty, 1 means white piece, 
// 2 means black piece)
int board[BOARD_SIZE][BOARD_SIZE];

// Array to keep track of all the moves made in the game
Move moves[MAX_MOVES];

// Index of the current move in the moves array
int current_move = 0;

// Variables to keep track of the current player and whether the game is over
int current_player = 1;
bool game_over = false;

// Function to initialize the board
void init_board() {
    // Set all squares to 0 (empty)
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    // Set up starting position for white pieces
    board[0][0] = 1;
    board[0][1] = 1;
    board[0][2] = 1;
    board[0][3] = 1;
    board[0][4] = 1;
    board[0][5] = 1;
    board[0][6] = 1;
    board[0][7] = 1;
    board[1][0] = 1;
    board[1][1] = 1;
    board[1][2] = 1;
    board[1][3] = 1;
    board[1][4] = 1;
    board[1][5] = 1;
    board[1][6] = 1;
    board[1][7] = 1;

    // Set up starting position for black pieces
    board[7][0] = 2;
    board[7][1] = 2;
    board[7][2] = 2;
    board[7][3] = 2;
    board[7][4] = 2;
    board[7][5] = 2;
    board[7][6] = 2;
    board[7][7] = 2;
    board[6][0] = 2;
    board[6][1] = 2;
    board[6][2] = 2;
    board[6][3] = 2;
    board[6][4] = 2;
    board[6][5] = 2;
    board[6][6] = 2;
    board[6][7] = 2;
}

// Function to print the board
void print_board() {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'a' + i);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                printf(". ");
            } else if (board[i][j] == 1) {
                printf("w ");
            } else {
                printf("b ");
            }
        }
        printf("%d", BOARD_SIZE - i);
        printf("\n");
    }

    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'a' + i);
    }
    printf("\n");
}

// Function to check if a move is valid
bool is_valid_move(int from_row, int from_col, int to_row, int to_col) {
    // First make sure the starting square contains a piece belonging to the
    // current player
    if (board[from_row][from_col] != current_player) {
        return false;
    }

    // Make sure the destination is an empty square or contains an opponent's piece
    if (board[to_row][to_col] != 0 && board[to_row][to_col] == current_player) {
        return false;
    }

    // Make sure the move is legal for the piece being moved
    if (current_player == 1) {
        // Check legal moves for white pieces
        if (board[from_row][from_col] == 1) {
            if ((to_col == from_col && to_row == from_row - 1 && board[to_row][to_col] == 0) ||
                (to_col == from_col - 1 && to_row == from_row - 1 && board[to_row][to_col] == 2) ||
                (to_col == from_col + 1 && to_row == from_row - 1 && board[to_row][to_col] == 2)) {
                return true;
            }
        } else if (board[from_row][from_col] == 2) {
            // Check legal moves for white kings
            if ((to_col == from_col && to_row == from_row - 1 && board[to_row][to_col] == 0) ||
                (to_col == from_col - 1 && to_row == from_row - 1 && board[to_row][to_col] == 2) ||
                (to_col == from_col + 1 && to_row == from_row - 1 && board[to_row][to_col] == 2) ||
                (to_col == from_col && to_row == from_row + 1 && board[to_row][to_col] == 0) ||
                (to_col == from_col - 1 && to_row == from_row + 1 && board[to_row][to_col] == 2) ||
                (to_col == from_col + 1 && to_row == from_row + 1 && board[to_row][to_col] == 2)) {
                return true;
            }
        }
    } else {
        // Check legal moves for black pieces
        if (board[from_row][from_col] == 2) {
            if ((to_col == from_col && to_row == from_row + 1 && board[to_row][to_col] == 0) ||
                (to_col == from_col - 1 && to_row == from_row + 1 && board[to_row][to_col] == 1) ||
                (to_col == from_col + 1 && to_row == from_row + 1 && board[to_row][to_col] == 1)) {
                return true;
            }
        } else if (board[from_row][from_col] == 4) {
            // Check legal moves for black kings
            if ((to_col == from_col && to_row == from_row - 1 && board[to_row][to_col] == 0) ||
                (to_col == from_col - 1 && to_row == from_row - 1 && board[to_row][to_col] == 1) ||
                (to_col == from_col + 1 && to_row == from_row - 1 && board[to_row][to_col] == 1) ||
                (to_col == from_col && to_row == from_row + 1 && board[to_row][to_col] == 0) ||
                (to_col == from_col - 1 && to_row == from_row + 1 && board[to_row][to_col] == 1) ||
                (to_col == from_col + 1 && to_row == from_row + 1 && board[to_row][to_col] == 1)) {
                return true;
            }
        }
    }

    return false;
}

// Function to make a move
void make_move(int from_row, int from_col, int to_row, int to_col) {
    // Update the board
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = 0;

    // Update the moves array
    moves[current_move].from_row = from_row;
    moves[current_move].from_col = from_col;
    moves[current_move].to_row = to_row;
    moves[current_move].to_col = to_col;

    // Increment the current move index
    current_move++;

    // Check if the game is over
    bool white_found = false;
    bool black_found = false;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 1 || board[i][j] == 2) {
                white_found = true;
            } else if (board[i][j] == 3 || board[i][j] == 4) {
                black_found = true;
            }
        }
    }

    if (!white_found) {
        printf("Black wins!");
        game_over = true;
    } else if (!black_found) {
        printf("White wins!");
        game_over = true;
    }

    // Change the current player
    if (current_player == 1) {
        current_player = 2;
    } else {
        current_player = 1;
    }
}

// Function to undo the last move
void undo_move() {
    // Decrement the current move index
    current_move--;

    // Get the details of the last move
    int from_row = moves[current_move].from_row;
    int from_col = moves[current_move].from_col;
    int to_row = moves[current_move].to_row;
    int to_col = moves[current_move].to_col;

    // Update the board
    board[from_row][from_col] = board[to_row][to_col];
    board[to_row][to_col] = 0;

    // Change the current player
    if (current_player == 1) {
        current_player = 2;
    } else {
        current_player = 1;
    }
}

// Function to get input from the user
void get_input(int* from_row, int* from_col, int* to_row, int* to_col) {
    char from_col_char, to_col_char;
    printf("Enter your move (e.g. a3-b4): ");
    scanf(" %c%d-%c%d", &from_col_char, from_row, &to_col_char, to_row);
    *from_col = from_col_char - 'a';
    *to_col = to_col_char - 'a';
}

int main() {
    printf("Welcome to Shape-Shifting Chess!\n");
    printf("--------------------------------\n");
    printf("\n");

    // Initialize the board
    init_board();

    // Main game loop
    while (!game_over) {
        // Print the current board
        printf("\n");
        print_board();

        // Get input from the user
        int from_row, from_col, to_row, to_col;
        get_input(&from_row, &from_col, &to_row, &to_col);

        // Check if the move is valid and make the move if it is
        if (is_valid_move(from_row, from_col, to_row, to_col)) {
            make_move(from_row, from_col, to_row, to_col);
        } else {
            printf("Invalid move!\n");
        }

        // Check if the user wants to undo the last move
        char undo_choice;
        printf("Do you want to undo the last move (y/n)? ");
        scanf(" %c", &undo_choice);
        if (undo_choice == 'y') {
            undo_move();
        }
    }

    return 0;
}