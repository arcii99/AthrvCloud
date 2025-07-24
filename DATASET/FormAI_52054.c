//FormAI DATASET v1.0 Category: Chess engine ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants used for board representation and moves
#define EMPTY 0
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

// Constants used for board size
#define BOARD_SIZE 8

// Constants used for player color
#define WHITE 0
#define BLACK 1

// Constants used for move legality checking
#define LEGAL_MOVE 1
#define ILLEGAL_MOVE 0

// Struct used to represent a move
typedef struct {
    int from_row;
    int from_col;
    int to_row;
    int to_col;
} Move;

// Function to print the board
void print_board(int board[][BOARD_SIZE])
{
    int i, j;
    for (i = BOARD_SIZE - 1; i >= 0; i--) {
        printf("%d |", i + 1);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                printf("  ");
            } else if (board[i][j] == PAWN) {
                printf("P ");
            } else if (board[i][j] == KNIGHT) {
                printf("N ");
            } else if (board[i][j] == BISHOP) {
                printf("B ");
            } else if (board[i][j] == ROOK) {
                printf("R ");
            } else if (board[i][j] == QUEEN) {
                printf("Q ");
            } else if (board[i][j] == KING) {
                printf("K ");
            }
        }
        printf("|\n");
    }
    printf("   -----------------\n");
    printf("    a b c d e f g h\n");
}

// Function to initialize the board
void init_board(int board[][BOARD_SIZE])
{
    int i, j;

    // Initialize all squares to empty
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }

    // Initialize white pieces
    board[0][0] = ROOK;
    board[0][1] = KNIGHT;
    board[0][2] = BISHOP;
    board[0][3] = QUEEN;
    board[0][4] = KING;
    board[0][5] = BISHOP;
    board[0][6] = KNIGHT;
    board[0][7] = ROOK;
    for (i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = PAWN;
    }

    // Initialize black pieces
    board[7][0] = ROOK;
    board[7][1] = KNIGHT;
    board[7][2] = BISHOP;
    board[7][3] = QUEEN;
    board[7][4] = KING;
    board[7][5] = BISHOP;
    board[7][6] = KNIGHT;
    board[7][7] = ROOK;
    for (i = 0; i < BOARD_SIZE; i++) {
        board[6][i] = PAWN;
    }
}

// Function to check if a move is legal
int is_legal_move(int board[][BOARD_SIZE], Move move, int player)
{
    if (board[move.from_row][move.from_col] == EMPTY ||
        (player == WHITE && board[move.from_row][move.from_col] > 0) ||
        (player == BLACK && board[move.from_row][move.from_col] < 0)) { // Check if there is a piece in the "from" square and if it belongs to the current player
        return ILLEGAL_MOVE;
    }

    int piece = abs(board[move.from_row][move.from_col]); // Determine the type of the piece being moved
    int dir = (board[move.from_row][move.from_col] > 0) ? 1 : -1; // Determine the direction the piece is moving based on player color

    if (piece == PAWN) {
        if (move.to_col == move.from_col) { // Moving straight ahead
            if (move.to_row - move.from_row == dir && board[move.to_row][move.to_col] == EMPTY) { // One square forward is empty
                return LEGAL_MOVE;
            } else if (move.to_row - move.from_row == 2 * dir && move.from_row == (player == WHITE ? 1 : 6) && board[move.from_row + dir][move.from_col] == EMPTY && board[move.to_row][move.to_col] == EMPTY) { // Two squares forward from start position is empty
                return LEGAL_MOVE;
            }
        } else if (abs(move.to_col - move.from_col) == 1 && move.to_row - move.from_row == dir && abs(board[move.to_row][move.to_col]) != KING) { // Moving diagonally to capture
            return LEGAL_MOVE;
        }
    } else if (piece == KNIGHT) {
        if ((abs(move.to_row - move.from_row) == 2 && abs(move.to_col - move.from_col) == 1) || (abs(move.to_row - move.from_row) == 1 && abs(move.to_col - move.from_col) == 2)) { // Moving in an L-shape
            if (board[move.to_row][move.to_col] * dir <= 0) { // Not capturing a piece of the same color
                return LEGAL_MOVE;
            }
        }
    } else if (piece == BISHOP) {
        int i, j;
        if (abs(move.to_row - move.from_row) == abs(move.to_col - move.from_col)) { // Moving diagonally
            int row_dir = (move.to_row > move.from_row) ? 1 : -1;
            int col_dir = (move.to_col > move.from_col) ? 1 : -1;
            for (i = move.from_row + row_dir, j = move.from_col + col_dir; i != move.to_row; i += row_dir, j += col_dir) { // Check if the path to the destination is clear
                if (board[i][j] != EMPTY) {
                    return ILLEGAL_MOVE;
                }
            }
            if (board[move.to_row][move.to_col] * dir <= 0) { // Not capturing a piece of the same color
                return LEGAL_MOVE;
            }
        }
    } else if (piece == ROOK) {
        int i, j;
        if (move.to_row == move.from_row) { // Moving horizontally
            int col_dir = (move.to_col > move.from_col) ? 1 : -1;
            for (j = move.from_col + col_dir; j != move.to_col; j += col_dir) { // Check if the path to the destination is clear
                if (board[move.from_row][j] != EMPTY) {
                    return ILLEGAL_MOVE;
                }
            }
            if (board[move.to_row][move.to_col] * dir <= 0) { // Not capturing a piece of the same color
                return LEGAL_MOVE;
            }
        } else if (move.to_col == move.from_col) { // Moving vertically
            int row_dir = (move.to_row > move.from_row) ? 1 : -1;
            for (i = move.from_row + row_dir; i != move.to_row; i += row_dir) { // Check if the path to the destination is clear
                if (board[i][move.from_col] != EMPTY) {
                    return ILLEGAL_MOVE;
                }
            }
            if (board[move.to_row][move.to_col] * dir <= 0) { // Not capturing a piece of the same color
                return LEGAL_MOVE;
            }
        }
    } else if (piece == QUEEN) {
        int i, j;
        if (abs(move.to_row - move.from_row) == abs(move.to_col - move.from_col)) { // Moving diagonally
            int row_dir = (move.to_row > move.from_row) ? 1 : -1;
            int col_dir = (move.to_col > move.from_col) ? 1 : -1;
            for (i = move.from_row + row_dir, j = move.from_col + col_dir; i != move.to_row; i += row_dir, j += col_dir) { // Check if the path to the destination is clear
                if (board[i][j] != EMPTY) {
                    return ILLEGAL_MOVE;
                }
            }
        } else if (move.to_row == move.from_row) { // Moving horizontally
            int col_dir = (move.to_col > move.from_col) ? 1 : -1;
            for (j = move.from_col + col_dir; j != move.to_col; j += col_dir) { // Check if the path to the destination is clear
                if (board[move.from_row][j] != EMPTY) {
                    return ILLEGAL_MOVE;
                }
            }
        } else if (move.to_col == move.from_col) { // Moving vertically
            int row_dir = (move.to_row > move.from_row) ? 1 : -1;
            for (i = move.from_row + row_dir; i != move.to_row; i += row_dir) { // Check if the path to the destination is clear
                if (board[i][move.from_col] != EMPTY) {
                    return ILLEGAL_MOVE;
                }
            }
        }
        if (board[move.to_row][move.to_col] * dir <= 0) { // Not capturing a piece of the same color
            return LEGAL_MOVE;
        }
    } else if (piece == KING) {
        if (abs(move.to_row - move.from_row) <= 1 && abs(move.to_col - move.from_col) <= 1) { // Moving one square in any direction
            if (board[move.to_row][move.to_col] * dir <= 0) { // Not capturing a piece of the same color
                return LEGAL_MOVE;
            }
        } else if (move.from_row == (player == WHITE ? 0 : 7) && move.from_col == 4 && move.to_col == 2) { // Castling queen side
            if (board[move.from_row][move.from_col - 1] == EMPTY && board[move.from_row][move.from_col - 2] == EMPTY && board[move.from_row][move.from_col - 3] == EMPTY &&
                board[move.from_row][move.from_col - 4] == ROOK && board[move.from_row][move.from_col - 4] * dir < 0) { // The path is clear and the rook belongs to the same player
                return LEGAL_MOVE;
            }
        } else if (move.from_row == (player == WHITE ? 0 : 7) && move.from_col == 4 && move.to_col == 6) { // Castling king side
            if (board[move.from_row][move.from_col + 1] == EMPTY && board[move.from_row][move.from_col + 2] == EMPTY &&
                board[move.from_row][move.from_col + 3] == ROOK && board[move.from_row][move.from_col + 3] * dir < 0) { // The path is clear and the rook belongs to the same player
                return LEGAL_MOVE;
            }
        }
    }

    return ILLEGAL_MOVE;
}

// Function to update the board after a move has been made
void make_move(int board[][BOARD_SIZE], Move move)
{
    board[move.to_row][move.to_col] = board[move.from_row][move.from_col];
    board[move.from_row][move.from_col] = EMPTY;
    if (move.from_row == 0 && move.from_col == 4 && move.to_col == 2) { // Castling queen side
        board[0][3] = ROOK;
        board[0][0] = EMPTY;
    } else if (move.from_row == 0 && move.from_col == 4 && move.to_col == 6) { // Castling king side
        board[0][5] = ROOK;
        board[0][7] = EMPTY;
    } else if (move.from_row == 7 && move.from_col == 4 && move.to_col == 2) { // Castling queen side
        board[7][3] = -ROOK;
        board[7][0] = EMPTY;
    } else if (move.from_row == 7 && move.from_col == 4 && move.to_col == 6) { // Castling king side
        board[7][5] = -ROOK;
        board[7][7] = EMPTY;
    }
}

// Function to make the computer player's move (random move)
void make_computer_move(int board[][BOARD_SIZE], int player)
{
    Move move;
    int legal_move = ILLEGAL_MOVE;
    while (legal_move == ILLEGAL_MOVE) { // Keep generating moves until a legal move is found
        move.from_row = rand() % BOARD_SIZE;
        move.from_col = rand() % BOARD_SIZE;
        move.to_row = rand() % BOARD_SIZE;
        move.to_col = rand() % BOARD_SIZE;
        legal_move = is_legal_move(board, move, player);
    }
    printf("Computer's move from %c%d to %c%d\n", move.from_col + 'a', move.from_row + 1, move.to_col + 'a', move.to_row + 1);
    make_move(board, move);
}

// Function to make the human player's move
void make_human_move(int board[][BOARD_SIZE], int player)
{
    char input[6];
    Move move;
    int legal_move = ILLEGAL_MOVE;
    while (legal_move == ILLEGAL_MOVE) { // Keep asking for input until a legal move is entered
        printf("Enter your move (e.g. e2e4): ");
        fgets(input, sizeof(input), stdin);
        move.from_col = input[0] - 'a';
        move.from_row = input[1] - '1';
        move.to_col = input[2] - 'a';
        move.to_row = input[3] - '1';
        legal_move = is_legal_move(board, move, player);
        if (legal_move == ILLEGAL_MOVE) {
            printf("Illegal move, try again.\n");
        }
    }
    make_move(board, move);
}

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    int player = WHITE;

    srand(time(NULL));

    init_board(board);

    while (1) {
        print_board(board);
        if (player == WHITE) {
            make_human_move(board, player);
        } else {
            make_computer_move(board, player);
        }
        player = !player; // Switch player after each move
        printf("\n");
    }
}