//FormAI DATASET v1.0 Category: Checkers Game ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 8
#define EMPTY_SPACE '.'
#define BLACK_PIECE 'B'
#define RED_PIECE 'R'
#define BLANK_PIECE " "
#define VALID_MOVE "Can move"
#define INVALID_MOVE "Cannot move"

typedef struct {
    char piece;
    bool is_king;
} Square;

Square board[BOARD_SIZE][BOARD_SIZE];

// Initialize the game board
void initialize_board() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if ((row + col) % 2 == 0) {
                if (row < 3) {
                    board[row][col].piece = BLACK_PIECE;
                } else if (row > 4) {
                    board[row][col].piece = RED_PIECE;
                } else {
                    board[row][col].piece = EMPTY_SPACE;
                }
                board[row][col].is_king = false;
            } else {
                board[row][col].piece = BLANK_PIECE;
                board[row][col].is_king = false;
            }
        }
    }
}

// Check if the move is valid or not
bool is_valid_move(int start_row, int start_col, int end_row, int end_col, bool is_king) {
    if (start_row < 0 || start_row >= BOARD_SIZE || start_col < 0 || start_col >= BOARD_SIZE ||
        end_row < 0 || end_row >= BOARD_SIZE || end_col < 0 || end_col >= BOARD_SIZE) {
        return false;
    }

    if (board[end_row][end_col].piece != EMPTY_SPACE) {
        return false;
    }

    if (is_king) {
        if (abs(end_row - start_row) != 1 || abs(end_col - start_col) != 1) {
            return false;
        }
    } else {
        if ((end_row - start_row == 1 && abs(end_col - start_col) == 1) ||
            (end_row - start_row == -1 && abs(end_col - start_col) == 1)) {
            return true;
        }
        if (abs(start_row - end_row) == 2 && abs(start_col - end_col) == 2) {
            int middle_row = (start_row + end_row) / 2;
            int middle_col = (start_col + end_col) / 2;
            if (board[middle_row][middle_col].piece == BLANK_PIECE) {
                return false;
            }
            if (board[middle_row][middle_col].piece == BLACK_PIECE ||
                board[middle_row][middle_col].is_king != is_king) {
                return false;
            }
            return true;
        }
        return false;
    }
}

// Make the move
void make_move(int start_row, int start_col, int end_row, int end_col, bool is_king) {
    board[end_row][end_col] = board[start_row][start_col];
    board[start_row][start_col].piece = BLANK_PIECE;
    if (!is_king && end_row == 0) {
        board[end_row][end_col].is_king = true;
    }
}

// Print the current state of the game board
void print_board() {
    printf("  1 2 3 4 5 6 7 8\n");
    printf(" +-+-+-+-+-+-+-+-+\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d|", row + 1);
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%c|", board[row][col].piece);
        }
        printf("%d\n", row + 1);
    }
    printf(" +-+-+-+-+-+-+-+-+\n");
    printf("  1 2 3 4 5 6 7 8\n");
}

int main() {
    initialize_board();

    int turn = 0;
    int move_number = 1;
    int start_row, start_col, end_row, end_col;
    bool is_king = false;

    while (true) {
        printf("\nMove #%d\n", move_number);
        print_board();
        if (turn % 2 == 0) {
            printf("Black's turn (B)\n");
            printf("Enter starting row and column: ");
            scanf("%d %d", &start_row, &start_col);
            printf("Enter ending row and column: ");
            scanf("%d %d", &end_row, &end_col);
            if (board[start_row - 1][start_col - 1].piece != BLACK_PIECE) {
                printf("You can only move black pieces (B)\n");
                continue;
            }
            if (!board[start_row - 1][start_col - 1].is_king) {
                is_king = false;
            } else {
                is_king = true;
            }
            if (!is_valid_move(start_row - 1, start_col - 1, end_row - 1, end_col - 1, is_king)) {
                printf("%s\n", INVALID_MOVE);
                continue;
            }
            make_move(start_row - 1, start_col - 1, end_row - 1, end_col - 1, is_king);
        } else {
            printf("Red's turn (R)\n");
            printf("Enter starting row and column: ");
            scanf("%d %d", &start_row, &start_col);
            printf("Enter ending row and column: ");
            scanf("%d %d", &end_row, &end_col);
            if (board[start_row - 1][start_col - 1].piece != RED_PIECE) {
                printf("You can only move red pieces (R)\n");
                continue;
            }
            if (!board[start_row - 1][start_col - 1].is_king) {
                is_king = false;
            } else {
                is_king = true;
            }
            if (!is_valid_move(start_row - 1, start_col - 1, end_row - 1, end_col - 1, is_king)) {
                printf("%s\n", INVALID_MOVE);
                continue;
            }
            make_move(start_row - 1, start_col - 1, end_row - 1, end_col - 1, is_king);
        }
        turn++;
        move_number++;
    }
    return 0;
}