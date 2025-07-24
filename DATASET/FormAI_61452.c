//FormAI DATASET v1.0 Category: Chess engine ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROWS 8
#define COLUMNS 8

typedef enum { false, true } bool;

typedef struct {
    char name;
    int x;
    int y;
    bool is_alive;
} Piece;

Piece board[COLUMNS][ROWS];
char current_player;

void initialize_board() {
    for (int i = 0; i < COLUMNS; i++) {
        for (int j = 0; j < ROWS; j++) {
            board[i][j].name = '-';
            board[i][j].is_alive = false;
        }
    }

    // Initializing White Pieces
    board[0][0].name = 'R';
    board[0][1].name = 'N';
    board[0][2].name = 'B';
    board[0][3].name = 'Q';
    board[0][4].name = 'K';
    board[0][5].name = 'B';
    board[0][6].name = 'N';
    board[0][7].name = 'R';

    for (int i = 0; i < ROWS; i++) {
        board[1][i].name = 'P';
    }

    // Initializing Black Pieces
    board[7][0].name = 'r';
    board[7][1].name = 'n';
    board[7][2].name = 'b';
    board[7][3].name = 'q';
    board[7][4].name = 'k';
    board[7][5].name = 'b';
    board[7][6].name = 'n';
    board[7][7].name = 'r';

    for (int i = 0; i < ROWS; i++) {
        board[6][i].name = 'p';
    }

    current_player = 'w';
}

void print_board() {
    for (int i = 0; i < COLUMNS; i++) {
        printf("%d\t", (COLUMNS - i));
        for (int j = 0; j < ROWS; j++) {
            printf("%c ", board[i][j].name);
        }
        printf("\n");
    }

    printf("\n\t");
    for (int i = 0; i < COLUMNS; i++) {
        printf("%c ", 'a' + i);
    }
    printf("\n\n");
}

void move_piece(int from_x, int from_y, int to_x, int to_y) {
    board[to_x][to_y].name = board[from_x][from_y].name;
    board[to_x][to_y].is_alive = true;
    board[to_x][to_y].x = to_x;
    board[to_x][to_y].y = to_y;
    board[from_x][from_y].name = '-';
    board[from_x][from_y].is_alive = false;
    board[from_x][from_y].x = -1;
    board[from_x][from_y].y = -1;

    if (current_player == 'w') {
        current_player = 'b';
    } else {
        current_player = 'w';
    }
}

bool is_valid_move(int from_x, int from_y, int to_x, int to_y) {
    if (from_x < 0 || from_x > (ROWS - 1) || from_y < 0 || from_y > (COLUMNS - 1) ||
        to_x < 0 || to_x > (ROWS - 1) || to_y < 0 || to_y > (COLUMNS - 1)) {
        return false;
    }

    if (board[from_x][from_y].name == '-') {
        return false;
    }

    int dx = abs(to_x - from_x);
    int dy = abs(to_y - from_y);

    if (dx == 0 && dy == 0) {
        return false;
    }

    if (board[to_x][to_y].is_alive && board[from_x][from_y].name != board[to_x][to_y].name) {
        // It's a capture move
        if (board[from_x][from_y].name == 'p') {
            // If it's a pawn, it can only capture diagonally
            if ((board[from_x][from_y].name == 'w' && to_x != (from_x - 1)) ||
                (board[from_x][from_y].name == 'b' && to_x != (from_x + 1)) ||
                abs(to_y - from_y) != 1) {
                return false;
            }
        } else {
            // It's not a pawn, it can capture in any direction
            return true;
        }
    } else {
        // It's not a capture move
        if (board[from_x][from_y].name == 'p') {
            // If it's a pawn, it can only move forward by one or two squares
            if ((board[from_x][from_y].name == 'w' && to_x != (from_x - 1)) ||
                (board[from_x][from_y].name == 'b' && to_x != (from_x + 1)) ||
                dy > 1 || (dy == 1 && !board[to_x][to_y].is_alive)) {
                return false;
            }
        } else {
            // It's not a pawn, it can move in any direction
            return true;
        }
    }

    return false;
}

bool has_moves(char player) {
    for (int i = 0; i < COLUMNS; i++) {
        for (int j = 0; j < ROWS; j++) {
            if (board[i][j].is_alive && board[i][j].name >= 'A' && board[i][j].name <= 'Z' &&
                player == 'w') {
                // It's a white piece
                for (int k = 0; k < COLUMNS; k++) {
                    for (int l = 0; l < ROWS; l++) {
                        if (is_valid_move(i, j, k, l)) {
                            return true;
                        }
                    }
                }
            } else if (board[i][j].is_alive && board[i][j].name >= 'a' && board[i][j].name <= 'z' &&
                       player == 'b') {
                // It's a black piece
                for (int k = 0; k < COLUMNS; k++) {
                    for (int l = 0; l < ROWS; l++) {
                        if (is_valid_move(i, j, k, l)) {
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    initialize_board();

    while (true) {
        printf("\n%s's turn:\n", (current_player == 'w' ? "White" : "Black"));

        print_board();

        char from[3], to[3];

        printf("Enter piece to move (e.g. e2): ");
        scanf("%s", from);

        int from_x = ROWS - (from[1] - '0');
        int from_y = from[0] - 'a';

        if (from_x < 0 || from_x >= ROWS || from_y < 0 || from_y >= COLUMNS ||
            board[from_x][from_y].name == '-') {
            printf("Invalid piece selected\n");
            continue;
        }

        if ((current_player == 'w' && board[from_x][from_y].name >= 'a' &&
             board[from_x][from_y].name <= 'z') ||
            (current_player == 'b' && board[from_x][from_y].name >= 'A' &&
             board[from_x][from_y].name <= 'Z')) {
            printf("That is not your piece\n");
            continue;
        }

        printf("Enter square to move to (e.g. e4): ");
        scanf("%s", to);

        int to_x = ROWS - (to[1] - '0');
        int to_y = to[0] - 'a';

        if (to_x < 0 || to_x >= ROWS || to_y < 0 || to_y >= COLUMNS) {
            printf("Invalid move\n");
            continue;
        }

        if (!is_valid_move(from_x, from_y, to_x, to_y)) {
            printf("Invalid move\n");
            continue;
        }

        move_piece(from_x, from_y, to_x, to_y);

        if (!has_moves(current_player)) {
            printf("%s has no valid moves left. Game over!\n", (current_player == 'w' ? "White" : "Black"));
            break;
        }
    }

    return 0;
}