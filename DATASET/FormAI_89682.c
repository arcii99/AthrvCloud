//FormAI DATASET v1.0 Category: Checkers Game ; Style: protected
#include <stdio.h>

// Macro to define dimensions of the checkers board
#define BOARD_SIZE 8

// Enum to define color of pieces on the board
enum piece_color {
    EMPTY,
    RED,
    BLACK
};

// Struct to define a position on the board
struct position {
    int row;
    int col;
};

// Struct to hold information about a game piece
struct piece {
    enum piece_color color;
    int is_king;
};

// Function to initialize the board with initial game configuration
void initialize_board(struct piece* board) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) {
                    board[i * BOARD_SIZE + j].color = BLACK;
                    board[i * BOARD_SIZE + j].is_king = 0;
                }
                else if (i > 4) {
                    board[i * BOARD_SIZE + j].color = RED;
                    board[i * BOARD_SIZE + j].is_king = 0;
                }
                else {
                    board[i * BOARD_SIZE + j].color = EMPTY;
                    board[i * BOARD_SIZE + j].is_king = 0;
                }
            }
        }
    }
}

// Function to print the board with the current game configuration
void print_board(struct piece* board) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d| ", BOARD_SIZE - i);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i * BOARD_SIZE + j].color == EMPTY) {
                printf("  ");
            }
            else if (board[i * BOARD_SIZE + j].color == RED) {
                if (board[i * BOARD_SIZE + j].is_king) {
                    printf("R+");
                }
                else {
                    printf("R ");
                }
            }
            else {
                if (board[i * BOARD_SIZE + j].is_king) {
                    printf("B+");
                }
                else {
                    printf("B ");
                }
            }
        }
        printf("|\n");
    }
    printf("  -----------------\n");
    printf("   A B C D E F G H\n");
}

// Function to check if a given position is a valid position on the board
int is_valid_position(struct position pos) {
    if (pos.row < 0 || pos.row >= BOARD_SIZE || pos.col < 0 || pos.col >= BOARD_SIZE) {
        return 0;
    }
    else {
        return 1;
    }
}

// Function to check if a piece can move to a given position on the board
int can_piece_move(struct piece* board, struct position start, struct position end, enum piece_color color) {
    if (!is_valid_position(start) || !is_valid_position(end)) {
        return 0;
    }
    if (start.row == end.row || start.col == end.col) {
        return 0;
    }
    if (board[end.row * BOARD_SIZE + end.col].color != EMPTY) {
        return 0;
    }
    if (board[start.row * BOARD_SIZE + start.col].color != color) {
        return 0;
    }
    if (color == RED) {
        if (end.row >= start.row) {
            return 0;
        }
        if (start.row - end.row == 1 && abs(start.col - end.col) == 1) {
            return 1;
        }
        if (start.row - end.row == 2 && abs(start.col - end.col) == 2) {
            if (board[(start.row + end.row) / 2 * BOARD_SIZE + (start.col + end.col) / 2].color == BLACK) {
                return 1;
            }
        }
    }
    else {
        if (end.row <= start.row) {
            return 0;
        }
        if (end.row - start.row == 1 && abs(start.col - end.col) == 1) {
            return 1;
        }
        if (end.row - start.row == 2 && abs(start.col - end.col) == 2) {
            if (board[(start.row + end.row) / 2 * BOARD_SIZE + (start.col + end.col) / 2].color == RED) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if a given player has any valid moves
int can_player_move(struct piece* board, enum piece_color color) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i * BOARD_SIZE + j].color == color) {
                if (can_piece_move(board, (struct position){i, j}, (struct position){i - 1, j - 1}, color)
                    || can_piece_move(board, (struct position){i, j}, (struct position){i - 1, j + 1}, color)
                    || can_piece_move(board, (struct position){i, j}, (struct position){i + 1, j - 1}, color)
                    || can_piece_move(board, (struct position){i, j}, (struct position){i + 1, j + 1}, color)) {
                        return 1;
                }
            }
        }
    }
    return 0;
}

// Function to make move on the board, returns 1 if move is successful, 0 otherwise
int make_move(struct piece* board, struct position start, struct position end, enum piece_color color) {
    if (!can_piece_move(board, start, end, color)) {
        return 0;
    }
    int jump = 0;
    if (abs(start.row - end.row) == 2) {
        jump = 1;
    }
    board[end.row * BOARD_SIZE + end.col].color = board[start.row * BOARD_SIZE + start.col].color;
    board[end.row * BOARD_SIZE + end.col].is_king = board[start.row * BOARD_SIZE + start.col].is_king;
    board[start.row * BOARD_SIZE + start.col].color = EMPTY;
    board[start.row * BOARD_SIZE + start.col].is_king = 0;
    if (jump) {
        board[(start.row + end.row) / 2 * BOARD_SIZE + (start.col + end.col) / 2].color = EMPTY;
        board[(start.row + end.row) / 2 * BOARD_SIZE + (start.col + end.col) / 2].is_king = 0;
    }
    if (end.row == 0 && board[end.row * BOARD_SIZE + end.col].color == RED) {
        board[end.row * BOARD_SIZE + end.col].is_king = 1;
    }
    if (end.row == BOARD_SIZE - 1 && board[end.row * BOARD_SIZE + end.col].color == BLACK) {
        board[end.row * BOARD_SIZE + end.col].is_king = 1;
    }
    return 1;
}

int main() {
    struct piece board[BOARD_SIZE * BOARD_SIZE];
    enum piece_color turn = RED;
    int game_running = 1;

    initialize_board(board);

    while (game_running) {
        printf("\n");
        print_board(board);
        printf("\n");
        if (turn == RED) {
            printf("Red's turn.\n");
        }
        else {
            printf("Black's turn.\n");
        }
        if (!can_player_move(board, turn)) {
            printf("No valid moves for current player, Game over.\n");
            game_running = 0;
            continue;
        }
        char start_col, end_col;
        int start_row, end_row;
        printf("Enter the starting position of the piece (e.g. 'A3'): ");
        scanf(" %c%d", &start_col, &start_row);
        printf("Enter the ending position of the piece (e.g. 'B4'): ");
        scanf(" %c%d", &end_col, &end_row);
        struct position start = {BOARD_SIZE - start_row, start_col - 'A'};
        struct position end = {BOARD_SIZE - end_row, end_col - 'A'};
        if (!make_move(board, start, end, turn)) {
            printf("Invalid move, try again.\n");
            continue;
        }
        if (turn == RED) {
            turn = BLACK;
        }
        else {
            turn = RED;
        }
    }
    return 0;
}