//FormAI DATASET v1.0 Category: Checkers Game ; Style: rigorous
#include <stdio.h>

#define BOARD_SIZE 8
#define BLACK 'B'
#define WHITE 'W'
#define EMPTY ' '

enum Direction { UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT };

typedef struct {
    char color;
    int is_king;
} Square;

Square board[BOARD_SIZE][BOARD_SIZE];

void init_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = (Square){EMPTY, 0};
            } else if (i < 3) {
                board[i][j] = (Square){BLACK, 0};
            } else if (i > 4) {
                board[i][j] = (Square){WHITE, 0};
            } else {
                board[i][j] = (Square){EMPTY, 0};
            }
        }
    }
}

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("| %c ", board[i][j].color);
        }
        printf("|\n");
    }
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("---");
    }
    printf("\n   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %c ", 'a' + i);
    }
    printf("\n");
}

int is_valid_move(int start_y, int start_x, int end_y, int end_x, int player) {
    int diff_y = end_y - start_y;
    int diff_x = end_x - start_x;

    // Check if move is within bounds of the board
    if (end_y < 0 || end_y >= BOARD_SIZE || end_x < 0 || end_x >= BOARD_SIZE) {
        return 0;
    }

    // Check if end position is empty
    if (board[end_y][end_x].color != EMPTY) {
        return 0;
    }

    // Check direction of move based on player color
    if (board[start_y][start_x].color == BLACK) {
        if (player == BLACK && diff_y < 0) {
            return 0;
        }
        if (board[start_y][start_x].is_king && abs(diff_x) != abs(diff_y)) {
            return 0;
        }
        if (diff_y != -1 || abs(diff_x) != 1) {
            return 0;
        }
    } else if (board[start_y][start_x].color == WHITE) {
        if (player == WHITE && diff_y > 0) {
            return 0;
        }
        if (board[start_y][start_x].is_king && abs(diff_x) != abs(diff_y)) {
            return 0;
        }
        if (diff_y != 1 || abs(diff_x) != 1) {
            return 0;
        }
    } else {
        return 0;
    }

    return 1;
}

int is_valid_capture(int start_y, int start_x, int end_y, int end_x, int player) {
    int diff_y = end_y - start_y;
    int diff_x = end_x - start_x;

    // Check if capturing move is within bounds of the board
    if (end_y < 0 || end_y >= BOARD_SIZE || end_x < 0 || end_x >= BOARD_SIZE) {
        return 0;
    }

    // Check if end position is empty or marked by same color
    if (board[end_y][end_x].color != EMPTY && board[end_y][end_x].color == board[start_y][start_x].color) {
        return 0;
    }

    // Check if captured piece is one color higher
    char captured_color;
    if (board[start_y][start_x].color == BLACK) {
        if (player == BLACK && diff_y < 0) {
            return 0;
        }
        if (diff_y != -2 || abs(diff_x) != 2) {
            return 0;
        }
        captured_color = WHITE;
    } else if (board[start_y][start_x].color == WHITE) {
        if (player == WHITE && diff_y > 0) {
            return 0;
        }
        if (diff_y != 2 || abs(diff_x) != 2) {
            return 0;
        }
        captured_color = BLACK;
    } else {
        return 0;
    }

    // Check if there is a piece to be captured
    int captured_y = (start_y + end_y) / 2;
    int captured_x = (start_x + end_x) / 2;
    if (board[captured_y][captured_x].color != captured_color) {
        return 0;
    }

    return 1;
}

int has_valid_capture(int y, int x, int player) {
    char color = board[y][x].color;
    int is_king = board[y][x].is_king;

    int capture_directions[4][2];
    if (color == BLACK || is_king) {
        capture_directions[0][0] = UP_LEFT;
        capture_directions[0][1] = UP_RIGHT;
    } else {
        capture_directions[0][0] = UP_RIGHT;
        capture_directions[0][1] = DOWN_RIGHT;
    }

    if (color == WHITE || is_king) {
        capture_directions[1][0] = DOWN_LEFT;
        capture_directions[1][1] = DOWN_RIGHT;
    } else {
        capture_directions[1][0] = UP_LEFT;
        capture_directions[1][1] = DOWN_LEFT;
    }

    int has_capture = 0;
    for (int i = 0; i < 2; i++) {
        int dir1 = capture_directions[i][0];
        int dir2 = capture_directions[i][1];

        int y1 = y + ((dir1 == UP_LEFT || dir1 == UP_RIGHT) ? -2 : 2);
        int x1 = x + ((dir1 == UP_LEFT || dir1 == DOWN_LEFT) ? -2 : 2);
        int y2 = y + ((dir2 == UP_LEFT || dir2 == UP_RIGHT) ? -2 : 2);
        int x2 = x + ((dir2 == UP_LEFT || dir2 == DOWN_LEFT) ? -2 : 2);

        if (is_valid_capture(y, x, y1, x1, player)) {
            has_capture = 1;
        }
        if (is_valid_capture(y, x, y2, x2, player)) {
            has_capture = 1;
        }
    }

    return has_capture;
}

void make_king(int y, int x) {
    board[y][x].is_king = 1;
}

void move_piece(int start_y, int start_x, int end_y, int end_x) {
    board[end_y][end_x] = board[start_y][start_x];
    board[start_y][start_x] = (Square){EMPTY, 0};
    if (end_y == 0 && board[end_y][end_x].color == BLACK) {
        make_king(end_y, end_x);
    }
    if (end_y == BOARD_SIZE - 1 && board[end_y][end_x].color == WHITE) {
        make_king(end_y, end_x);
    }
}

void capture_piece(int start_y, int start_x, int end_y, int end_x) {
    int captured_y = (start_y + end_y) / 2;
    int captured_x = (start_x + end_x) / 2;
    board[captured_y][captured_x] = (Square){EMPTY, 0};
    move_piece(start_y, start_x, end_y, end_x);
}

int perform_move(int start_y, int start_x, int end_y, int end_x, int player) {
    if (is_valid_capture(start_y, start_x, end_y, end_x, player)) {
        capture_piece(start_y, start_x, end_y, end_x);
        if (has_valid_capture(end_y, end_x, player)) {
            return 1;
        } else {
            return 0;
        }
    } else if (is_valid_move(start_y, start_x, end_y, end_x, player)) {
        move_piece(start_y, start_x, end_y, end_x);
        return 0;
    } else {
        return -1;
    }
}

int main() {
    init_board();
    print_board();

    int player = 1;
    int has_capture = 0;

    while (1) {
        printf("Player %d, enter a move (e.g. a3-b4): ", player);
        char input[6];
        scanf("%s", input);

        int start_x = input[0] - 'a';
        int start_y = BOARD_SIZE - (input[1] - '0');
        int end_x = input[3] - 'a';
        int end_y = BOARD_SIZE - (input[4] - '0');

        int has_valid_move = has_valid_capture(start_y, start_x, player);
        if (!has_valid_move && !is_valid_move(start_y, start_x, end_y, end_x, player)) {
            printf("Invalid move.\n");
            continue;
        }

        int has_multiple_capture = 0;
        while (has_valid_capture(start_y, start_x, player)) {
            has_capture = 1;
            has_multiple_capture = 1;

            printf("Capture available. Enter move (e.g. a3-c5): ");
            scanf("%s", input);

            int new_end_x = input[3] - 'a';
            int new_end_y = BOARD_SIZE - (input[4] - '0');

            int capture_result = perform_move(start_y, start_x, new_end_y, new_end_x, player);
            if (capture_result == -1) {
                printf("Invalid move.\n");
                continue;
            }
            if (capture_result == 1) {
                start_x = new_end_x;
                start_y = new_end_y;
                continue;
            }

            if (has_valid_move) {
                printf("Invalid move. A capture is available.\n");
                continue;
            }

            if (player == 1 && new_end_y == 0 && !board[new_end_y][new_end_x].is_king) {
                make_king(new_end_y, new_end_x);
            }
            if (player == 2 && new_end_y == BOARD_SIZE - 1 && !board[new_end_y][new_end_x].is_king) {
                make_king(new_end_y, new_end_x);
            }

            print_board();
            player = player == 1 ? 2 : 1;
            break;
        }

        if (!has_multiple_capture) {
            int move_result = perform_move(start_y, start_x, end_y, end_x, player);
            if (move_result == -1) {
                printf("Invalid move.\n");
                continue;
            }
            if (move_result == 1) {
                has_capture = 1;
            }

            if (has_valid_capture(end_y, end_x, player)) {
                printf("Invalid move. A capture is available.\n");
                continue;
            }

            if (player == 1 && end_y == 0 && !board[end_y][end_x].is_king) {
                make_king(end_y, end_x);
            }
            if (player == 2 && end_y == BOARD_SIZE - 1 && !board[end_y][end_x].is_king) {
                make_king(end_y, end_x);
            }

            print_board();
            player = player == 1 ? 2 : 1;
            has_capture = 0;
        }

        if (player == 1 && has_capture && !has_valid_capture(end_y, end_x, player)) {
            printf("Player 1's turn again. ");
            continue;
        }
        if (player == 2 && has_capture && !has_valid_capture(end_y, end_x, player)) {
            printf("Player 2's turn again. ");
            continue;
        }

        if (has_capture) {
            printf("Capture is mandatory. ");
        } else {
            printf("Player %d's turn. ", player);
        }
    }

    return 0;
}