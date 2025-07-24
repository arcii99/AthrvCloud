//FormAI DATASET v1.0 Category: Checkers Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

enum Player {
    BLACK,
    WHITE
} current_player;

void init_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) {
                    board[i][j] = 'B';
                } else if (i > 4) {
                    board[i][j] = 'W';
                } else {
                    board[i][j] = ' ';
                }
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

void print_board() {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", i);
    }
    printf("  0 1 2 3 4 5 6 7\n");
}

bool is_valid_move(int x1, int y1, int x2, int y2) {
    if (x2 < 0 || y2 < 0 || x2 >= BOARD_SIZE || y2 >= BOARD_SIZE || board[x2][y2] != ' ') {
        return false;
    }

    if (current_player == BLACK) {
        if (x2 != x1 + 1) {
            return false;
        }
        if (y2 != y1 - 1 && y2 != y1 + 1) {
            return false;
        }
        return true;
    } else {
        if (x2 != x1 - 1) {
            return false;
        }
        if (y2 != y1 - 1 && y2 != y1 + 1) {
            return false;
        }
        return true;
    }
}

bool is_valid_capture(int x1, int y1, int x2, int y2) {
    if (x2 < 0 || y2 < 0 || x2 >= BOARD_SIZE || y2 >= BOARD_SIZE || board[x2][y2] != ' ') {
        return false;
    }

    if (current_player == BLACK) {
        if (x2 != x1 + 2) {
            return false;
        }
        if (y2 != y1 - 2 && y2 != y1 + 2) {
            return false;
        }
        int x_mid = (x1 + x2) / 2;
        int y_mid = (y1 + y2) / 2;
        if (board[x_mid][y_mid] != 'W' && board[x_mid][y_mid] != 'w') {
            return false;
        }
        return true;
    } else {
        if (x2 != x1 - 2) {
            return false;
        }
        if (y2 != y1 - 2 && y2 != y1 + 2) {
            return false;
        }
        int x_mid = (x1 + x2) / 2;
        int y_mid = (y1 + y2) / 2;
        if (board[x_mid][y_mid] != 'B' && board[x_mid][y_mid] != 'b') {
            return false;
        }
        return true;
    }
}

void make_move(int x1, int y1, int x2, int y2) {
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = ' ';

    if (current_player == BLACK && x2 == BOARD_SIZE - 1) {
        board[x2][y2] = 'B';
    } else if (current_player == WHITE && x2 == 0) {
        board[x2][y2] = 'W';
    }

    if (is_valid_capture(x2, y2, x2 + 1, y2 - 1)) {
        board[x2 + 1][y2 - 1] = ' ';
    }
    if (is_valid_capture(x2, y2, x2 + 1, y2 + 1)) {
        board[x2 + 1][y2 + 1] = ' ';
    }
    if (is_valid_capture(x2, y2, x2 - 1, y2 - 1)) {
        board[x2 - 1][y2 - 1] = ' ';
    }
    if (is_valid_capture(x2, y2, x2 - 1, y2 + 1)) {
        board[x2 - 1][y2 + 1] = ' ';
    }
}

bool has_valid_moves() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 'b' || board[i][j] == 'B') {
                if (is_valid_move(i, j, i + 1, j - 1) || is_valid_move(i, j, i + 1, j + 1) || is_valid_capture(i, j, i + 2, j - 2)
                    || is_valid_capture(i, j, i + 2, j + 2)) {
                    return true;
                }
            } else if (board[i][j] == 'w' || board[i][j] == 'W') {
                if (is_valid_move(i, j, i - 1, j - 1) || is_valid_move(i, j, i - 1, j + 1) || is_valid_capture(i, j, i - 2, j - 2)
                    || is_valid_capture(i, j, i - 2, j + 2)) {
                    return true;
                }
            }
        }
    }
    return false;
}

void switch_player() {
    if (current_player == BLACK) {
        current_player = WHITE;
    } else {
        current_player = BLACK;
    }
}

int main() {
    init_board();
    current_player = BLACK;

    printf("Welcome to Linus Checkers Game!\n"
           "Type the coordinates of two squares so that you can move your piece.\n"
           "The coordinates should be in the format 'x1 y1 x2 y2'.\n"
           "For example, '1 2 2 3' moves the piece from (1, 2) to (2, 3).\n"
           "Let's get started!\n");

    int x1, y1, x2, y2;
    while (true) {
        print_board();

        if (!has_valid_moves()) {
            if (current_player == BLACK) {
                printf("Black player has no valid moves left. White player wins!\n");
            } else {
                printf("White player has no valid moves left. Black player wins!\n");
            }
            return 0;
        }

        printf("%c player's turn. Enter your move: ", current_player == BLACK ? 'B' : 'W');
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        if (is_valid_move(x1, y1, x2, y2)) {
            make_move(x1, y1, x2, y2);
            switch_player();
        } else if (is_valid_capture(x1, y1, x2, y2)) {
            make_move(x1, y1, x2, y2);
            if (is_valid_capture(x2, y2, x2 + 2, y2 - 2) || is_valid_capture(x2, y2, x2 + 2, y2 + 2)
                || is_valid_capture(x2, y2, x2 - 2, y2 - 2) || is_valid_capture(x2, y2, x2 - 2, y2 + 2)) {
                printf("You can capture again by entering the next move: ");
            } else {
                switch_player();
            }
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }

    return 0;
}