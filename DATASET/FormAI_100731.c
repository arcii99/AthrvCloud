//FormAI DATASET v1.0 Category: Checkers Game ; Style: dynamic
#include <stdio.h>
#include <stdbool.h>

// Define the size of the checkers board
#define BOARD_SIZE 8

// Define constants for player pieces
#define PLAYER_1 'o'
#define PLAYER_1_KING 'O'
#define PLAYER_2 'x'
#define PLAYER_2_KING 'X'
#define EMPTY ' '

// Define struct to hold position on board
typedef struct {
    int row;
    int col;
} Position;

// This function initializes the board with player pieces in their respective starting positions
void initialize_board(char board[][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (i < 3) {
                if ((i + j) % 2 == 0) {
                    board[i][j] = PLAYER_2;
                } else {
                    board[i][j] = EMPTY;
                }
            } else if (i > 4) {
                if ((i + j) % 2 == 0) {
                    board[i][j] = PLAYER_1;
                } else {
                    board[i][j] = EMPTY;
                }
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

// This function prints the board with newlines after each row
void print_board(char board[][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// This function gets the move input from the player
void get_move(char board[][BOARD_SIZE],
              Position *from,
              Position *to,
              char player) {
    int from_row, from_col, to_row, to_col;
    printf("\n%s's turn.\n", (player == PLAYER_1 || player == PLAYER_1_KING) ? "Player 1" : "Player 2");
    printf("Enter the row number of the piece you want to move: ");
    scanf("%d", &from_row);
    printf("Enter the column number of the piece you want to move: ");
    scanf("%d", &from_col);
    printf("Enter the row number of the position you want to move to: ");
    scanf("%d", &to_row);
    printf("Enter the column number of the position you want to move to: ");
    scanf("%d", &to_col);

    // Set position structs with user input
    from->row = from_row - 1;
    from->col = from_col - 1;
    to->row = to_row - 1;
    to->col = to_col - 1;
}

// This function checks if the move is valid
bool is_move_valid(char board[][BOARD_SIZE],
                   Position from,
                   Position to,
                   char player) {
    // Check that the 'from' position has a checker of the appropriate player
    if (player == PLAYER_1) {
        if (board[from.row][from.col] != PLAYER_1) {
            printf("Invalid move: you can only move your own pieces.\n");
            return false;
        }
    } else if (player == PLAYER_2) {
        if (board[from.row][from.col] != PLAYER_2) {
            printf("Invalid move: you can only move your own pieces.\n");
            return false;
        }
    }

    // Check that the 'to' position is empty
    if (board[to.row][to.col] != EMPTY) {
        printf("Invalid move: the destination is not empty.\n");
        return false;
    }

    // Check that the move is diagonal
    if (from.row == to.row || from.col == to.col) {
        printf("Invalid move: you can only move diagonally.\n");
        return false;
    }
    int row_diff = to.row - from.row;
    int col_diff = to.col - from.col;
    if (row_diff != col_diff && row_diff != -col_diff) {
        printf("Invalid move: you can only move diagonally.\n");
        return false;
    }

    // Check that the move is only one space
    if (row_diff > 1 || row_diff < -1 || col_diff > 1 || col_diff < -1) {
        printf("Invalid move: you can only move one space.\n");
        return false;
    }

    // Check that the move is in the forward direction for non-kings
    if ((player == PLAYER_1 && row_diff < 0) || (player == PLAYER_2 && row_diff > 0)) {
        printf("Invalid move: you can only move forward.\n");
        return false;
    }

    // Check that the piece is not trying to move over another piece
    if (row_diff == 2 || row_diff == -2) {
        int mid_row = (from.row + to.row) / 2;
        int mid_col = (from.col + to.col) / 2;
        if (board[mid_row][mid_col] == EMPTY) {
            printf("Invalid move: you can only jump over an opponent's piece.\n");
            return false;
        }
        char opponent = (player == PLAYER_1) ? PLAYER_2 : PLAYER_1;
        if (board[mid_row][mid_col] != opponent && board[mid_row][mid_col] != opponent + 'A' - 'a') {
            printf("Invalid move: you can only jump over an opponent's piece.\n");
            return false;
        }
    }

    // If the piece is not a king and reaches the opposite end of the board, it becomes a king
    if (player == PLAYER_1 && to.row == 0) {
        board[from.row][from.col] = EMPTY;
        board[to.row][to.col] = PLAYER_1_KING;
        printf("Player 1's piece becomes a king!\n");
    } else if (player == PLAYER_2 && to.row == BOARD_SIZE - 1) {
        board[from.row][from.col] = EMPTY;
        board[to.row][to.col] = PLAYER_2_KING;
        printf("Player 2's piece becomes a king!\n");
    }

    return true;
}

// This function executes the move
void execute_move(char board[][BOARD_SIZE],
                  Position from,
                  Position to,
                  char player) {
    board[to.row][to.col] = board[from.row][from.col];
    board[from.row][from.col] = EMPTY;

    // If the move is a jump, remove the opponent's piece from the board
    int row_diff = to.row - from.row;
    int col_diff = to.col - from.col;
    if (row_diff == 2 || row_diff == -2) {
        int mid_row = (from.row + to.row) / 2;
        int mid_col = (from.col + to.col) / 2;
        board[mid_row][mid_col] = EMPTY;
        printf("Jump successful!\n");
    }
}

// This function checks if there are any available jumps
bool has_available_jumps(char board[][BOARD_SIZE],
                         Position pos,
                         char player) {
    int row, col;
    int jump_row, jump_col;
    int opponent, king_opponent;
    if (player == PLAYER_1 || player == PLAYER_1_KING) {
        opponent = PLAYER_2;
        king_opponent = PLAYER_2_KING;
    } else {
        opponent = PLAYER_1;
        king_opponent = PLAYER_1_KING;
    }

    // Check for diagonal jumps
    row = pos.row;
    col = pos.col;
    jump_row = row + 2;
    jump_col = col + 2;
    if (jump_row < BOARD_SIZE && jump_col < BOARD_SIZE
            && board[jump_row][jump_col] == EMPTY
            && (board[row + 1][col + 1] == opponent || board[row + 1][col + 1] == king_opponent)) {
        return true;
    }
    jump_row = row + 2;
    jump_col = col - 2;
    if (jump_row < BOARD_SIZE && jump_col >= 0
            && board[jump_row][jump_col] == EMPTY
            && (board[row + 1][col - 1] == opponent || board[row + 1][col - 1] == king_opponent)) {
        return true;
    }
    jump_row = row - 2;
    jump_col = col + 2;
    if (jump_row >= 0 && jump_col < BOARD_SIZE
            && board[jump_row][jump_col] == EMPTY
            && (board[row - 1][col + 1] == opponent || board[row - 1][col + 1] == king_opponent)) {
        return true;
    }
    jump_row = row - 2;
    jump_col = col - 2;
    if (jump_row >= 0 && jump_col >= 0
            && board[jump_row][jump_col] == EMPTY
            && (board[row - 1][col - 1] == opponent || board[row - 1][col - 1] == king_opponent)) {
        return true;
    }

    return false;
}

// This function checks if the player can make any moves
bool can_player_move(char board[][BOARD_SIZE],
                     char player) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player) {
                Position pos = {i, j};
                int row = pos.row;
                int col = pos.col;
                int row_diff = (player == PLAYER_1 || player == PLAYER_1_KING) ? -1 : 1;
                if (row > 0 && col > 0 && board[row + row_diff][col - 1] == EMPTY) {
                    return true;
                }
                if (row > 0 && col < BOARD_SIZE - 1 && board[row + row_diff][col + 1] == EMPTY) {
                    return true;
                }
                if (board[row + row_diff][col - 1] == PLAYER_2 || board[row + row_diff][col - 1] == PLAYER_2_KING) {
                    if (row > 1 && col > 1 && board[row + row_diff * 2][col - 2] == EMPTY) {
                        return true;
                    }
                }
                if (board[row + row_diff][col + 1] == PLAYER_2 || board[row + row_diff][col + 1] == PLAYER_2_KING) {
                    if (row > 1 && col < BOARD_SIZE - 2 && board[row + row_diff * 2][col + 2] == EMPTY) {
                        return true;
                    }
                }
                if (board[row + row_diff][col - 1] == PLAYER_2_KING || board[row + row_diff][col - 1] == PLAYER_2_KING) {
                    if (row < BOARD_SIZE - 2 && col > 1 && board[row - row_diff * 2][col - 2] == EMPTY) {
                        return true;
                    }
                }
                if (board[row + row_diff][col + 1] == PLAYER_2_KING || board[row + row_diff][col + 1] == PLAYER_2_KING) {
                    if (row < BOARD_SIZE - 2 && col < BOARD_SIZE - 2 && board[row - row_diff * 2][col + 2] == EMPTY) {
                        return true;
                    }
                }
            } else if (board[i][j] == player + 'A' - 'a') { // player king
                Position pos = {i, j};
                int row = pos.row;
                int col = pos.col;
                if (row > 0 && col > 0 && board[row - 1][col - 1] == EMPTY) {
                    return true;
                }
                if (row > 0 && col < BOARD_SIZE - 1 && board[row - 1][col + 1] == EMPTY) {
                    return true;
                }
                if (row < BOARD_SIZE - 1 && col > 0 && board[row + 1][col - 1] == EMPTY) {
                    return true;
                }
                if (row < BOARD_SIZE - 1 && col < BOARD_SIZE - 1 && board[row + 1][col + 1] == EMPTY) {
                    return true;
                }
                if (has_available_jumps(board, pos, player)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    Position from, to;
    char player = PLAYER_1;
    initialize_board(board);
    while (true) {
        print_board(board);
        if (!can_player_move(board, player)) {
            printf("No moves available for %s. %s wins!", (player == PLAYER_1 || player == PLAYER_1_KING) ? "Player 1" : "Player 2", (player == PLAYER_1 || player == PLAYER_1_KING) ? "Player 2" : "Player 1");
            break;
        }
        do {
            get_move(board, &from, &to, player);
        } while (!is_move_valid(board, from, to, player));
        execute_move(board, from, to, player);
        player = (player == PLAYER_1 || player == PLAYER_1_KING) ? PLAYER_2 : PLAYER_1;
    }
    return 0;
}