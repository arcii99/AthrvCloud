//FormAI DATASET v1.0 Category: Checkers Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Constants to represent the colors of the pieces
#define EMPTY 0
#define RED 1
#define BLACK 2

// Constants to represent the types of moves
#define MOVE 1
#define CAPTURE 2

// Constants to represent the size of the board
#define BOARD_SIZE 8

// Struct to represent a position on the board
typedef struct {
    int row;
    int col;
} Position;

// Struct to represent a checkers piece
typedef struct {
    int color;
    int type;
} Piece;

// Function to print the board
void print_board(Piece board[BOARD_SIZE][BOARD_SIZE]) {

    // Print the column headings
    printf("  ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%d ", col);
    }
    printf("\n");

    // Print the rows of the board
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d ", row);
        for (int col = 0; col < BOARD_SIZE; col++) {
            switch (board[row][col].color) {
                case EMPTY:
                    printf("- ");
                    break;
                case RED:
                    if (board[row][col].type == 1) {
                        printf("r ");
                    } else {
                        printf("R ");
                    }
                    break;
                case BLACK:
                    if (board[row][col].type == 1) {
                        printf("b ");
                    } else {
                        printf("B ");
                    }
                    break;
            }
        }
        printf("\n");
    }
}

// Function to initialize the board with pieces
void initialize_board(Piece board[BOARD_SIZE][BOARD_SIZE]) {

    // Set all squares to empty
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col].color = EMPTY;
            board[row][col].type = 0;
        }
    }

    // Add red pieces
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if ((row + col) % 2 == 1) {
                board[row][col].color = RED;
                board[row][col].type = 1;
            }
        }
    }

    // Add black pieces
    for (int row = BOARD_SIZE - 3; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if ((row + col) % 2 == 1) {
                board[row][col].color = BLACK;
                board[row][col].type = 1;
            }
        }
    }
}

// Function to get the type of a move
int get_move_type(Position from, Position to) {
    int row_diff = to.row - from.row;
    int col_diff = to.col - from.col;
    if (abs(row_diff) == 1 && abs(col_diff) == 1) {
        return MOVE;
    } else if (abs(row_diff) == 2 && abs(col_diff) == 2) {
        return CAPTURE;
    } else {
        return 0;
    }
}

// Function to validate a move
int is_valid_move(Piece board[BOARD_SIZE][BOARD_SIZE], Piece piece, Position from, Position to) {
   
    // Check if the "to" position is out of bounds
    if (to.row < 0 || to.row >= BOARD_SIZE || to.col < 0 || to.col >= BOARD_SIZE) {
        return 0;
    }

    // Check if the "to" square is already occupied
    if (board[to.row][to.col].color != EMPTY) {
        return 0;
    }

    // Check if the piece is moving in the right direction
    if ((piece.color == RED && from.row >= to.row) || (piece.color == BLACK && from.row <= to.row)) {
        return 0;
    }

    // Get the type of the move
    int move_type = get_move_type(from, to);

    // Check if the move type is valid
    if (move_type == 0) {
        return 0;
    }

    // Check if the move is a capture
    if (move_type == CAPTURE) {

        // Get the position of the piece being captured
        int capture_row = (from.row + to.row) / 2;
        int capture_col = (from.col + to.col) / 2;

        // Check if there is a piece of the opposite color in the capture position
        if (board[capture_row][capture_col].color != 3 - piece.color) {
            return 0;
        }
    }

    // If all checks passed, the move is valid
    return 1;
}

// Function to make a move
void make_move(Piece board[BOARD_SIZE][BOARD_SIZE], Piece piece, Position from, Position to) {

    // Move the piece to the "to" position
    board[to.row][to.col] = piece;

    // Clear the "from" position
    board[from.row][from.col].color = EMPTY;
    board[from.row][from.col].type = 0;

    // Check if the piece should be promoted
    if ((piece.color == RED && to.row == 0) || (piece.color == BLACK && to.row == BOARD_SIZE - 1)) {
        board[to.row][to.col].type = 2;
    }

    // Check if the move was a capture
    int move_type = get_move_type(from, to);
    if (move_type == CAPTURE) {

        // Get the position of the captured piece
        int capture_row = (from.row + to.row) / 2;
        int capture_col = (from.col + to.col) / 2;

        // Clear the capture position
        board[capture_row][capture_col].color = EMPTY;
        board[capture_row][capture_col].type = 0;
    }
}

// Function to get human input for a move
void get_move_input(Position *from, Position *to) {

    // Get the "from" position
    printf("Enter the row and column of the piece you want to move: ");
    scanf("%d %d", &from->row, &from->col);

    // Get the "to" position
    printf("Enter the row and column of the square you want to move to: ");
    scanf("%d %d", &to->row, &to->col);
}

// Function to get the possible moves for a piece
void get_moves(Piece board[BOARD_SIZE][BOARD_SIZE], Piece piece, Position pos, Position moves[], int *num_moves) {
    int index = 0;
    if (piece.type == 1) {

        // Check the forward left diagonal
        Position forward_left = {pos.row + (piece.color == RED ? -1 : 1), pos.col - 1};
        if (is_valid_move(board, piece, pos, forward_left)) {
            moves[index] = forward_left;
            index++;
        }

        // Check the forward right diagonal
        Position forward_right = {pos.row + (piece.color == RED ? -1 : 1), pos.col + 1};
        if (is_valid_move(board, piece, pos, forward_right)) {
            moves[index] = forward_right;
            index++;
        }

        // Check the capture moves
        Position capture_moves[] = {
                {pos.row + (piece.color == RED ? -2 : 2), pos.col - 2},
                {pos.row + (piece.color == RED ? -2 : 2), pos.col + 2}
        };
        for (int i = 0; i < 2; i++) {
            if (is_valid_move(board, piece, pos, capture_moves[i])) {
                moves[index] = capture_moves[i];
                index++;
            }
        }

    } else if (piece.type == 2) {

        // Check all diagonal moves
        Position diagonal_moves[] = {
                {pos.row - 1, pos.col - 1},
                {pos.row - 1, pos.col + 1},
                {pos.row + 1, pos.col - 1},
                {pos.row + 1, pos.col + 1}
        };
        for (int i = 0; i < 4; i++) {
            Position move = diagonal_moves[i];
            while (is_valid_move(board, piece, pos, move)) {
                moves[index] = move;
                index++;
                if (get_move_type(pos, move) == CAPTURE) {
                    break;
                }
                move.row += (pos.row > move.row ? -1 : 1);
                move.col += (pos.col > move.col ? -1 : 1);
            }
        }
    }

    // Set the number of moves
    *num_moves = index;
}

// Function to get the moves for all pieces of a certain color
void get_all_moves(Piece board[BOARD_SIZE][BOARD_SIZE], int color, Position moves[], int *num_moves) {
    int index = 0;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col].color == color) {
                Position pos = {row, col};
                Piece piece = board[row][col];
                Position piece_moves[BOARD_SIZE * BOARD_SIZE];
                int num_piece_moves;
                get_moves(board, piece, pos, piece_moves, &num_piece_moves);
                for (int i = 0; i < num_piece_moves; i++) {
                    moves[index] = pos;
                    moves[index + 1] = piece_moves[i];
                    index += 2;
                }
            }
        }
    }
    *num_moves = index / 2;
}

// Function to get the index of a move in an array
int get_move_index(Position *moves, int num_moves, Position from, Position to) {
    for (int i = 0; i < num_moves; i++) {
        if (moves[2*i].row == from.row && moves[2*i].col == from.col &&
            moves[2*i+1].row == to.row && moves[2*i+1].col == to.col) {
            return i;
        }
    }
    return -1;
}

// Function to get a random move
void get_random_move(Position moves[], int num_moves, Position *from, Position *to) {
    int rand_move = rand() % num_moves;
    *from = moves[2 * rand_move];
    *to = moves[2 * rand_move + 1];
}

// Function to play the game
void play_game() {

    // Initialize the board
    Piece board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    int turn = RED;

    // Loop until the game is over
    while (1) {

        // Print the board
        printf("\n");
        print_board(board);

        // Get the current player's move
        Position from, to;
        Position moves[BOARD_SIZE * BOARD_SIZE * 2];
        int num_moves;
        get_all_moves(board, turn, moves, &num_moves);
        printf("\n%s's turn\n", turn == RED ? "Red" : "Black");
        if (num_moves == 0) {
            printf("No moves found. %s wins!\n", turn == RED ? "Black" : "Red");
            break;
        }
        if (turn == RED) {
            get_move_input(&from, &to);
        } else {
            get_random_move(moves, num_moves, &from, &to);
            printf("Computer moves from (%d,%d) to (%d,%d)\n", from.row, from.col, to.row, to.col);
        }

        // Check if the move is valid
        int move_index = get_move_index(moves, num_moves, from, to);
        if (move_index == -1) {
            printf("Invalid move.\n");
            continue;
        }

        // Make the move
        Piece piece = board[from.row][from.col];
        make_move(board, piece, from, to);

        // Check if the game is over
        int red_pieces = 0;
        int black_pieces = 0;
        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++) {
                if (board[row][col].color == RED) {
                    red_pieces++;
                }
                if (board[row][col].color == BLACK) {
                    black_pieces++;
                }
            }
        }
        if (red_pieces == 0 || black_pieces == 0) {
            printf("\n%s's turn\n", turn == RED ? "Red" : "Black");
            printf("%s wins!\n", turn == RED ? "Black" : "Red");
            break;
        }

        // Switch the turn
        turn = 3 - turn;
    }
}

// Main function
int main() {
    play_game();
    return 0;
}