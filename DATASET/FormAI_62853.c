//FormAI DATASET v1.0 Category: Checkers Game ; Style: interoperable
#include <stdio.h>

// Define board size
#define BOARD_SIZE 8

// Define player type
typedef enum {
    BLACK,
    WHITE
} player_type;

// Define piece type
typedef enum {
    EMPTY,
    BLACK_PIECE,
    BLACK_KING,
    WHITE_PIECE,
    WHITE_KING
} piece_type;

// Define board
int board[BOARD_SIZE][BOARD_SIZE];

// Define function to display board
void display_board() {
    printf("\n   1  2  3  4  5  6  7  8\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d  ", i+1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case EMPTY:
                    printf(".  ");
                    break;
                case BLACK_PIECE:
                    printf("x  ");
                    break;
                case BLACK_KING:
                    printf("X  ");
                    break;
                case WHITE_PIECE:
                    printf("o  ");
                    break;
                case WHITE_KING:
                    printf("O  ");
                    break;
                default:
                    break;
            }
        }
        printf("\n");
    }
}

// Define function to initialize board
void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i % 2 != j % 2) {
                if (i < 3) {
                    board[i][j] = BLACK_PIECE;
                } else if (i > 4) {
                    board[i][j] = WHITE_PIECE;
                } else {
                    board[i][j] = EMPTY;
                }
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

// Define function to check if move is valid
int is_valid_move(int px, int py, int qx, int qy, player_type player) {
    int dx, dy;
    piece_type piece = (player == BLACK) ? BLACK_PIECE : WHITE_PIECE;
    piece_type king = (player == BLACK) ? BLACK_KING : WHITE_KING;
    if (board[qx][qy] != EMPTY) {
        return 0;
    }
    if (player == BLACK && board[px][py] != BLACK_PIECE && board[px][py] != BLACK_KING) {
        return 0;
    }
    if (player == WHITE && board[px][py] != WHITE_PIECE && board[px][py] != WHITE_KING) {
        return 0;
    }
    if (px == qx || py == qy) {
        return 0;
    }
    dx = qx - px;
    dy = qy - py;
    if (player == BLACK) {
        if (dy < 0) {
            return 0;
        }
        if (board[px][py] == BLACK_PIECE && dy > 1) {
            return 0;
        }
        if (dy == 1 && (dx == 1 || dx == -1)) {
            return 1;
        }
        if (dy == 2 && (dx == 2 || dx == -2) && board[px + dx/2][py + dy/2] != piece && board[px + dx/2][py + dy/2] != king) {
            return 1;
        }
        if (board[px][py] == BLACK_KING && dy < 0) {
            if (dy == -1 && (dx == 1 || dx == -1)) {
                return 1;
            }
            if (dy == -2 && (dx == 2 || dx == -2) && board[px + dx/2][py + dy/2] != piece && board[px + dx/2][py + dy/2] != king) {
                return 1;
            }
        }
    } else {
        if (dy > 0) {
            return 0;
        }
        if (board[px][py] == WHITE_PIECE && dy < -1) {
            return 0;
        }
        if (dy == -1 && (dx == 1 || dx == -1)) {
            return 1;
        }
        if (dy == -2 && (dx == 2 || dx == -2) && board[px + dx/2][py + dy/2] != piece && board[px + dx/2][py + dy/2] != king) {
            return 1;
        }
        if (board[px][py] == WHITE_KING && dy > 0) {
            if (dy == 1 && (dx == 1 || dx == -1)) {
                return 1;
            }
            if (dy == 2 && (dx == 2 || dx == -2) && board[px + dx/2][py + dy/2] != piece && board[px + dx/2][py + dy/2] != king) {
                return 1;
            }
        }
    }
    return 0;
}

// Define function to get input move
void get_input_move(int *px, int *py, int *qx, int *qy, player_type player) {
    while (1) {
        printf("\n%s's move:\n", (player == BLACK) ? "BLACK" : "WHITE");
        printf("Enter piece position (row, column): ");
        scanf("%d,%d", px, py);
        *px = *px - 1;
        *py = *py - 1;
        printf("Enter move position (row, column): ");
        scanf("%d,%d", qx, qy);
        *qx = *qx - 1;
        *qy = *qy - 1;
        if (*px >= 0 && *px < BOARD_SIZE && *py >= 0 && *py < BOARD_SIZE && *qx >= 0 && *qx < BOARD_SIZE && *qy >= 0 && *qy < BOARD_SIZE) {
            if (is_valid_move(*px, *py, *qx, *qy, player)) {
                return;
            }
        }
        printf("Invalid move. Try again!\n");
    }
}

// Define function to perform move
void perform_move(int px, int py, int qx, int qy, player_type player) {
    piece_type piece = (player == BLACK) ? BLACK_PIECE : WHITE_PIECE;
    piece_type king = (player == BLACK) ? BLACK_KING : WHITE_KING;
    int dx = qx - px;
    int dy = qy - py;
    board[qx][qy] = (board[px][py] == king) ? king : piece;
    board[px][py] = EMPTY;
    if (dx == 2 || dx == -2) {
        board[px + dx/2][py + dy/2] = EMPTY;
    }
    if (qx == (player == BLACK ? 7 : 0) && board[qx][qy] == piece) {
        board[qx][qy] = king;
    }
}

// Define function to check if game is over
int is_game_over(player_type player) {
    piece_type piece = (player == BLACK) ? BLACK_PIECE : WHITE_PIECE;
    piece_type king = (player == BLACK) ? BLACK_KING : WHITE_KING;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == piece || board[i][j] == king) {
                for (int k = -2; k <= 2; k++) {
                    for (int l = -2; l <= 2; l++) {
                        if (i+k >= 0 && i+k < BOARD_SIZE && j+l >= 0 && j+l < BOARD_SIZE && is_valid_move(i, j, i+k, j+l, player)) {
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 1;
}

// Define main function
int main() {
    player_type player = BLACK;
    int px, py, qx, qy;
    initialize_board();
    while (!is_game_over(player)) {
        display_board();
        get_input_move(&px, &py, &qx, &qy, player);
        perform_move(px, py, qx, qy, player);
        player = (player == BLACK) ? WHITE : BLACK;
    }
    display_board();
    printf("\nGAME OVER!\n");
    return 0;
}