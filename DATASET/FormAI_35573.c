//FormAI DATASET v1.0 Category: Checkers Game ; Style: safe
#include <stdbool.h>
#include <stdio.h>
#define BOARD_SIZE 8  // Size of the checkers board.

// Enum to represent the different color pieces on the board.
enum Color {BLACK, RED};

// Enum to represent the different types of pieces on the board.
enum Type {NONE, MAN, KING};

// Struct to represent a square on the board.
struct Square {
    enum Color color;
    enum Type type;
};

// Struct to represent the game board.
struct Board {
    struct Square squares[BOARD_SIZE][BOARD_SIZE];
};

// Struct to represent a move that can be made on the board.
struct Move {
    int from_row;
    int from_col;
    int to_row;
    int to_col;
};

// Function to initialize the board to its starting state.
void initialize_board(struct Board* board) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (row < 3) {  // Black pieces
                if ((row + col) % 2 != 0) {
                    board->squares[row][col].color = BLACK;
                    board->squares[row][col].type = MAN;
                }
            }
            else if (row > 4) {  // Red pieces
                if ((row + col) % 2 != 0) {
                    board->squares[row][col].color = RED;
                    board->squares[row][col].type = MAN;
                }
            }
        }
    }
}

// Function to print the board to the console.
void print_board(struct Board* board) {
    printf("  ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%d ", col);
    }
    printf("\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d ", row);
        for (int col = 0; col < BOARD_SIZE; col++) {
            switch (board->squares[row][col].type) {
                case MAN:
                    printf("%c ", board->squares[row][col].color == BLACK ? 'b' : 'r');
                    break;
                case KING:
                    printf("%c ", board->squares[row][col].color == BLACK ? 'B' : 'R');
                    break;
                default:
                    printf("- ");
                    break;
            }
        }
        printf("\n");
    }
}

// Function to check if a move is valid.
bool is_valid_move(struct Board* board, struct Move* move) {
    // Check that the move stays on the board.
    if (move->from_row < 0 || move->from_row >= BOARD_SIZE ||
        move->from_col < 0 || move->from_col >= BOARD_SIZE ||
        move->to_row < 0 || move->to_row >= BOARD_SIZE ||
        move->to_col < 0 || move->to_col >= BOARD_SIZE) {
        return false;
    }
    // Check that the move is only one space diagonally.
    if (abs(move->from_row - move->to_row) != 1 ||
        abs(move->from_col - move->to_col) != 1) {
        return false;
    }
    // Check that there is a piece to move.
    if (board->squares[move->from_row][move->from_col].type == NONE) {
        return false;
    }
    // Check that the piece being moved belongs to the correct player.
    if (board->squares[move->from_row][move->from_col].color !=
        board->squares[move->to_row][move->to_col].color) {
        return false;
    }
    return true;
}

// Function to make a move on the board.
void make_move(struct Board* board, struct Move* move) {
    board->squares[move->to_row][move->to_col].color =
        board->squares[move->from_row][move->from_col].color;
    board->squares[move->to_row][move->to_col].type =
        board->squares[move->from_row][move->from_col].type;
    board->squares[move->from_row][move->from_col].color = NONE;
    board->squares[move->from_row][move->from_col].type = NONE;
}

int main() {
    struct Board board;
    initialize_board(&board);
    print_board(&board);
    return 0;
}