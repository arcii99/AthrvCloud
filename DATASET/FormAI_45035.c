//FormAI DATASET v1.0 Category: Checkers Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum { EMPTY, BLACK, RED } Square;

typedef struct {
    Square squares[BOARD_SIZE][BOARD_SIZE];
    int turn;
} Board;

void print_board(Board *board) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board->squares[i][j]) {
                case EMPTY:
                    printf(". ");
                    break;
                case BLACK:
                    printf("B ");
                    break;
                case RED:
                    printf("R ");
                    break;
            }
        }
        printf("%d\n", BOARD_SIZE - i);
    }
    printf("  a b c d e f g h\n");
}

int is_valid_move(Board *board, int from_x, int from_y, int to_x, int to_y) {
    // Check if destination is empty and within bounds
    if (board->squares[to_x][to_y] != EMPTY || to_x < 0 || to_x >= BOARD_SIZE || to_y < 0 || to_y >= BOARD_SIZE) {
        return 0;
    }
    // Check if jump is valid for kings and non-kings
    if (board->squares[from_x][from_y] == BLACK || board->squares[from_x][from_y] == RED) {
        if (abs(from_x - to_x) != 1 || abs(from_y - to_y) != 1) {
            return 0;
        }
    } else {
        if (abs(from_x - to_x) != abs(from_y - to_y)) {
            return 0;
        }
        if (from_x > to_x && from_y > to_y) {
            for (int i = 1; i < from_x - to_x; i++) {
                if (board->squares[from_x - i][from_y - i] != EMPTY) {
                    return 0;
                }
            }
        } else if (from_x > to_x && from_y < to_y) {
            for (int i = 1; i < from_x - to_x; i++) {
                if (board->squares[from_x - i][from_y + i] != EMPTY) {
                    return 0;
                }
            }
        } else if (from_x < to_x && from_y < to_y) {
            for (int i = 1; i < to_x - from_x; i++) {
                if (board->squares[from_x + i][from_y + i] != EMPTY) {
                    return 0;
                }
            }
        } else if (from_x < to_x && from_y > to_y) {
            for (int i = 1; i < to_x - from_x; i++) {
                if (board->squares[from_x + i][from_y - i] != EMPTY) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

void make_move(Board *board, int from_x, int from_y, int to_x, int to_y) {
    // Kings
    if (board->squares[from_x][from_y] == BLACK && to_x == BOARD_SIZE - 1) {
        board->squares[to_x][to_y] = BLACK;
        board->squares[from_x][from_y] = EMPTY;
    } else if (board->squares[from_x][from_y] == RED && to_x == 0) {
        board->squares[to_x][to_y] = RED;
        board->squares[from_x][from_y] = EMPTY;
    } else {
        board->squares[to_x][to_y] = board->squares[from_x][from_y];
        board->squares[from_x][from_y] = EMPTY;
    }
    // Jump
    if (abs(from_x - to_x) == 2 && abs(from_y - to_y) == 2) {
        int jumped_x = from_x > to_x ? from_x - 1 : to_x - 1;
        int jumped_y = from_y > to_y ? from_y - 1 : to_y - 1;
        board->squares[jumped_x][jumped_y] = EMPTY;
    }
}

int has_moves(Board *board, int x, int y) {
    if (board->squares[x][y] == BLACK) {
        if (is_valid_move(board, x, y, x + 1, y + 1) || is_valid_move(board, x, y, x + 1, y - 1) || is_valid_move(board, x, y, x + 2, y + 2) || is_valid_move(board, x, y, x + 2, y - 2)) {
            return 1;
        }
    } else if (board->squares[x][y] == RED) {
        if (is_valid_move(board, x, y, x - 1, y + 1) || is_valid_move(board, x, y, x - 1, y - 1) || is_valid_move(board, x, y, x - 2, y + 2) || is_valid_move(board, x, y, x - 2, y - 2)) {
            return 1;
        }
    } else {
        return 0;
    }
}

int has_valid_moves(Board *board, int player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->squares[i][j] == player && has_moves(board, i, j)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    Board board = {
        .squares = {
            { EMPTY, RED, EMPTY, RED, EMPTY, RED, EMPTY, RED },
            { RED, EMPTY, RED, EMPTY, RED, EMPTY, RED, EMPTY },
            { EMPTY, RED, EMPTY, RED, EMPTY, RED, EMPTY, RED },
            { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
            { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
            { BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY },
            { EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK },
            { BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY }
        },
        .turn = BLACK
    };
    printf("Welcome to the Futuristic Checkers Game!\nEnter positions in the format x,y-z,w (e.g. a,5-b,4)\n");
    while (1) {
        int x, y, z, w;
        char input[10];
        printf("\n");
        print_board(&board);
        if (board.turn == BLACK) {
            printf("\nBlack's turn: ");
        } else {
            printf("\nRed's turn: ");
        }
        scanf("%s", input);
        if (input[0] < 'a' || input[0] > 'h' || input[2] < 'a' || input[2] > 'h' || input[1] < '1' || input[1] > '8' || input[4] < '1' || input[4] > '8' || input[5] != '-') {
            printf("\nInvalid input!\n");
            continue;
        }
        x = BOARD_SIZE - (input[1] - '0');
        y = input[0] - 'a';
        z = BOARD_SIZE - (input[4] - '0');
        w = input[2] - 'a';
        if (!is_valid_move(&board, x, y, z, w)) {
            printf("\nInvalid move!\n");
            continue;
        }
        make_move(&board, x, y, z, w);
        if (board.turn == BLACK && z == BOARD_SIZE - 1 && board.squares[z][w] == BLACK) {
            printf("\nBlack has become a king!\n");
        } else if (board.turn == RED && z == 0 && board.squares[z][w] == RED) {
            printf("\nRed has become a king!\n");
        }
        if (!has_valid_moves(&board, board.turn == BLACK ? RED : BLACK)) {
            printf("\n");
            print_board(&board);
            if (board.turn == BLACK) {
                printf("\nRed has won!\n");
            } else {
                printf("\nBlack has won!\n");
            }
            return 0;
        }
        board.turn = board.turn == BLACK ? RED : BLACK;
    }
    return 0;
}