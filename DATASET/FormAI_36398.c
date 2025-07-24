//FormAI DATASET v1.0 Category: Checkers Game ; Style: authentic
#include <stdio.h>

enum player {none = 0, player1 = 1, player2 = 2};

enum piece {piece_none = 0, piece_player1 = 1, piece_player2 = 2, 
    piece_player1_king = 3, piece_player2_king = 4};

struct game_board {
    enum player current_player;
    enum piece board[8][8];
};

void init_board(struct game_board *board) {
    board->current_player = player1;
    int i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (i % 2 == j % 2) {
                if (i < 3) {
                    board->board[i][j] = piece_player2;
                } else if (i > 4) {
                    board->board[i][j] = piece_player1;
                } else {
                    board->board[i][j] = piece_none;
                }
            } else {
                board->board[i][j] = piece_none;
            }
        }
    }
}

void print_board(const struct game_board *board) {
    int i, j;
    printf("  0 1 2 3 4 5 6 7\n");
    for (i = 0; i < 8; i++) {
        printf("%d ", i);
        for (j = 0; j < 8; j++) {
            switch (board->board[i][j]) {
                case piece_none:
                    printf(". ");
                    break;
                case piece_player1:
                    printf("o ");
                    break;
                case piece_player2:
                    printf("x ");
                    break;
                case piece_player1_king:
                    printf("O ");
                    break;
                case piece_player2_king:
                    printf("X ");
                    break;
                default:
                    printf("? ");
            }
        }
        printf("%d\n", i);
    }
    printf("  0 1 2 3 4 5 6 7\n");
}

int is_valid_move(const struct game_board *board, int from_y, int from_x, int to_y, int to_x) {
    if (to_x < 0 || to_y < 0 || to_x >= 8 || to_y >= 8) {
        return 0;
    }
    if (board->board[to_y][to_x] != piece_none) {
        return 0;
    }
    int dy = to_y - from_y;
    if (board->current_player == player1) {
        if (board->board[from_y][from_x] == piece_player1) {
            if (dy == 1 && abs(to_x - from_x) == 1) {
                return 1;
            }
        } else if (board->board[from_y][from_x] == piece_player1_king) {
            if (abs(dy) == 1 && abs(to_x - from_x) == 1) {
                return 1;
            }
        }
    } else if (board->current_player == player2) {
        if (board->board[from_y][from_x] == piece_player2) {
            if (dy == -1 && abs(to_x - from_x) == 1) {
                return 1;
            }
        } else if (board->board[from_y][from_x] == piece_player2_king) {
            if (abs(dy) == 1 && abs(to_x - from_x) == 1) {
                return 1;
            }
        }
    }
    return 0;
}

int is_valid_jump(const struct game_board *board, int from_y, int from_x, int to_y, int to_x) {
    if (to_x < 0 || to_y < 0 || to_x >= 8 || to_y >= 8) {
        return 0;
    }
    if (board->board[to_y][to_x] != piece_none) {
        return 0;
    }
    int dy = to_y - from_y;
    if (board->current_player == player1) {
        if (board->board[from_y][from_x] == piece_player1) {
            if (dy == 2 && abs(to_x - from_x) == 2 
                    && board->board[from_y + dy/2][(from_x + to_x)/2] == piece_player2) {
                return 1;
            }
        } else if (board->board[from_y][from_x] == piece_player1_king) {
            if (abs(dy) == 2 && abs(to_x - from_x) == 2 
                    && board->board[from_y + dy/2][(from_x + to_x)/2] == piece_player2) {
                return 1;
            }
        }
    } else if (board->current_player == player2) {
        if (board->board[from_y][from_x] == piece_player2) {
            if (dy == -2 && abs(to_x - from_x) == 2 
                    && board->board[from_y + dy/2][(from_x + to_x)/2] == piece_player1) {
                return 1;
            }
        } else if (board->board[from_y][from_x] == piece_player2_king) {
            if (abs(dy) == 2 && abs(to_x - from_x) == 2 
                    && board->board[from_y + dy/2][(from_x + to_x)/2] == piece_player1) {
                return 1;
            }
        }
    }
    return 0;
}

int can_jump(const struct game_board *board, int player, int y, int x) {
    if (board->board[y][x] == piece_player1) {
        if (is_valid_jump(board, y, x, y+2, x-2) 
                || is_valid_jump(board, y, x, y+2, x+2)) {
            return 1;
        }
    } else if (board->board[y][x] == piece_player2) {
        if (is_valid_jump(board, y, x, y-2, x-2) 
                || is_valid_jump(board, y, x, y-2, x+2)) {
            return 1;
        }
    } else if (board->board[y][x] == piece_player1_king
            || board->board[y][x] == piece_player2_king) {
        if (is_valid_jump(board, y, x, y+2, x-2) 
                || is_valid_jump(board, y, x, y+2, x+2)
                || is_valid_jump(board, y, x, y-2, x-2) 
                || is_valid_jump(board, y, x, y-2, x+2)) {
            return 1;
        }
    }
    return 0;
}

int can_move(const struct game_board *board, int player, int y, int x) {
    if (board->board[y][x] == piece_player1) {
        if (is_valid_move(board, y, x, y+1, x-1) 
                || is_valid_move(board, y, x, y+1, x+1)) {
            return 1;
        }
    } else if (board->board[y][x] == piece_player2) {
        if (is_valid_move(board, y, x, y-1, x-1) 
                || is_valid_move(board, y, x, y-1, x+1)) {
            return 1;
        }
    } else if (board->board[y][x] == piece_player1_king
            || board->board[y][x] == piece_player2_king) {
        if (is_valid_move(board, y, x, y+1, x-1) 
                || is_valid_move(board, y, x, y+1, x+1)
                || is_valid_move(board, y, x, y-1, x-1) 
                || is_valid_move(board, y, x, y-1, x+1)) {
            return 1;
        }
    }
    return 0;
}

void make_move(struct game_board *board, int from_y, int from_x, int to_y, int to_x) {
    int dy = to_y - from_y;
    int king_row;

    if (board->current_player == player1) {
        king_row = 7;
    } else {
        king_row = 0;
    }

    if (is_valid_jump(board, from_y, from_x, to_y, to_x)) {
        board->board[to_y][to_x] = board->board[from_y][from_x];
        board->board[from_y][from_x] = piece_none;
        board->board[(from_y+to_y)/2][(from_x+to_x)/2] = piece_none;

        // check for additional jumps
        if (can_jump(board, board->current_player, to_y, to_x)) {
            return;
        }
        // promote to king if necessary
        if (board->board[to_y][to_x] == piece_player1 && to_y == king_row) {
            board->board[to_y][to_x] = piece_player1_king;
        }
        board->current_player = (board->current_player == player1 ? player2 : player1);
    } else if (is_valid_move(board, from_y, from_x, to_y, to_x)) {
        board->board[to_y][to_x] = board->board[from_y][from_x];
        board->board[from_y][from_x] = piece_none;
        if (board->board[to_y][to_x] == piece_player1 && to_y == king_row) {
            board->board[to_y][to_x] = piece_player1_king;
        } else if (board->board[to_y][to_x] == piece_player2 && to_y == king_row) {
            board->board[to_y][to_x] = piece_player2_king;
        }
        board->current_player = (board->current_player == player1 ? player2 : player1);
    }
}

int main() {
    struct game_board board;
    init_board(&board);

    while (1) {
        print_board(&board);

        // check for winner
        int player1_pieces = 0, player2_pieces = 0;
        int i, j;
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (board.board[i][j] == piece_player1 
                        || board.board[i][j] == piece_player1_king) {
                    player1_pieces++;
                } else if (board.board[i][j] == piece_player2 
                        || board.board[i][j] == piece_player2_king) {
                    player2_pieces++;
                }
            }
        }
        if (player1_pieces == 0) {
            printf("Player 2 wins!\n");
            break;
        } else if (player2_pieces == 0) {
            printf("Player 1 wins!\n");
            break;
        }

        int from_x, from_y, to_x, to_y;
        printf("Player %d's turn:\n", board.current_player);
        printf("Enter starting row and column (e.g. 3 4): ");
        scanf("%d %d", &from_y, &from_x);
        printf("Enter ending row and column (e.g. 2 5): ");
        scanf("%d %d", &to_y, &to_x);

        if (can_jump(&board, board.current_player, from_y, from_x)) {
            if (is_valid_jump(&board, from_y, from_x, to_y, to_x)) {
                make_move(&board, from_y, from_x, to_y, to_x);
            } else {
                printf("Invalid jump.\n");
            }
        } else {
            if (is_valid_move(&board, from_y, from_x, to_y, to_x)) {
                make_move(&board, from_y, from_x, to_y, to_x);
            } else {
                printf("Invalid move.\n");
            }
        }
    }

    return 0;
}