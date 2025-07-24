//FormAI DATASET v1.0 Category: Chess AI ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

typedef enum { EMPTY, WHITE_PAWN, WHITE_ROOK, WHITE_KNIGHT, WHITE_BISHOP, WHITE_QUEEN, WHITE_KING, 
    BLACK_PAWN, BLACK_ROOK, BLACK_KNIGHT, BLACK_BISHOP, BLACK_QUEEN, BLACK_KING } piece;

typedef struct {
    int x;
    int y;
} point;

piece board[BOARD_HEIGHT][BOARD_WIDTH];
bool black_to_move;

point find_king(piece p) {
    point king_pos = {0, 0};
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (board[i][j] == p) {
                king_pos.x = i;
                king_pos.y = j;
            }
        }
    }
    return king_pos;
}

bool is_blocked(int x, int y) {
    return (x < 0 || x > BOARD_HEIGHT - 1 || y < 0 || y > BOARD_WIDTH - 1 || board[x][y] != EMPTY);
}

bool is_move_valid(int x, int y, int new_x, int new_y) {
    if (is_blocked(new_x, new_y)) {
        return false;
    }
    int dx = abs(new_x - x);
    int dy = abs(new_y - y);
    switch (board[x][y]) {
        case WHITE_PAWN:
            if (dx == 1 && dy == 1 && board[new_x][new_y] != EMPTY) {
                return true;
            }
            if (dx != 1 || dy != 0 || board[new_x][new_y] != EMPTY) {
                return false;
            }
            if (black_to_move && new_x - x == -1) {
                return true;
            }
            if (!black_to_move && new_x - x == 1) {
                return true;
            }
            return false;
            break;
        case WHITE_ROOK:
        case BLACK_ROOK:
            if (dx > 0 && dy > 0) {
                return false;
            }
            if (dx == 0) {
                for (int i = 0; i < dy; i++) {
                    if (is_blocked(x, y + i * (new_y - y) / dy)) {
                        return false;
                    }
                }
                return true;
            }
            if (dy == 0) {
                for (int i = 0; i < dx; i++) {
                    if (is_blocked(x + i * (new_x - x) / dx, y)) {
                        return false;
                    }
                }
                return true;
            }
            break;
        case WHITE_KNIGHT:
        case BLACK_KNIGHT:
            if ((dx == 1 && dy == 2) || (dx == 2 && dy == 1)) {
                return true;
            }
            return false;
            break;
        case WHITE_BISHOP:
        case BLACK_BISHOP:
            if (dx != dy) {
                return false;
            }
            for (int i = 0; i < dx; i++) {
                if (is_blocked(x + i * (new_x - x) / dx, y + i * (new_y - y) / dy)) {
                    return false;
                }
            }
            return true;
            break;
        case WHITE_QUEEN:
        case BLACK_QUEEN:
            if ((dx > 0 && dy > 0) && dx != dy) {
                return false;
            }
            if (dx == 0) {
                for (int i = 0; i < dy; i++) {
                    if (is_blocked(x, y + i * (new_y - y) / dy)) {
                        return false;
                    }
                }
                return true;
            }
            if (dy == 0) {
                for (int i = 0; i < dx; i++) {
                    if (is_blocked(x + i * (new_x - x) / dx, y)) {
                        return false;
                    }
                }
                return true;
            }
            for (int i = 0; i < dx; i++) {
                if (is_blocked(x + i * (new_x - x) / dx, y + i * (new_y - y) / dy)) {
                    return false;
                }
            }
            return true;
            break;
        case WHITE_KING:
        case BLACK_KING:
            if (dx > 1 || dy > 1) {
                return false;
            }
            return true;
            break;
        default:
            return false;
            break;
    }
    return false;
}

void move_piece(int x, int y, int new_x, int new_y) {
    board[new_x][new_y] = board[x][y];
    board[x][y] = EMPTY;
}

bool is_king_in_check() {
    point king_pos;
    if (black_to_move) {
        king_pos = find_king(BLACK_KING);
    } else {
        king_pos = find_king(WHITE_KING);
    }
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (is_move_valid(i, j, king_pos.x, king_pos.y)) {
                return true;
            }
        }
    }
    return false;
}

bool is_checkmate() {
    if (!is_king_in_check()) {
        return false;
    }
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (board[i][j] == EMPTY) {
                continue;
            }
            if ((board[i][j] <= WHITE_KING && !black_to_move) || (board[i][j] > WHITE_KING && black_to_move)) {
                continue;
            }
            for (int k = 0; k < BOARD_HEIGHT; k++) {
                for (int l = 0; l < BOARD_WIDTH; l++) {
                    if (is_move_valid(i, j, k, l)) {
                        piece moving_piece = board[i][j];
                        piece captured_piece = board[k][l];
                        move_piece(i, j, k, l);
                        if (!is_king_in_check()) {
                            board[i][j] = moving_piece;
                            board[k][l] = captured_piece;
                            return false;
                        }
                        board[i][j] = moving_piece;
                        board[k][l] = captured_piece;
                    }
                }
            }
        }
    }
    return true;
}

void render_board() {
    printf("\n   A  B  C  D  E  F  G  H\n");
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        printf(" %d ", BOARD_HEIGHT - i);
        for (int j = 0; j < BOARD_WIDTH; j++) {
            char symbol;
            switch (board[i][j]) {
                case EMPTY:
                    symbol = ' ';
                    break;
                case WHITE_PAWN:
                    symbol = 'P';
                    break;
                case WHITE_ROOK:
                    symbol = 'R';
                    break;
                case WHITE_KNIGHT:
                    symbol = 'N';
                    break;
                case WHITE_BISHOP:
                    symbol = 'B';
                    break;
                case WHITE_QUEEN:
                    symbol = 'Q';
                    break;
                case WHITE_KING:
                    symbol = 'K';
                    break;
                case BLACK_PAWN:
                    symbol = 'p';
                    break;
                case BLACK_ROOK:
                    symbol = 'r';
                    break;
                case BLACK_KNIGHT:
                    symbol = 'n';
                    break;
                case BLACK_BISHOP:
                    symbol = 'b';
                    break;
                case BLACK_QUEEN:
                    symbol = 'q';
                    break;
                case BLACK_KING:
                    symbol = 'k';
                    break;
                default:
                    symbol = '?';
                    break;
            }
            printf("|%c ", symbol);
        }
        printf("| %d\n", BOARD_HEIGHT - i);
    }
    printf("   A  B  C  D  E  F  G  H\n");
}

void get_move(int *x, int *y, int *new_x, int *new_y) {
    char input[10];
    printf("Enter move (ex: e2-e4): ");
    fgets(input, 10, stdin);
    *x = input[0] - 'a';
    *y = BOARD_HEIGHT - (input[1] - '0');
    *new_x = input[3] - 'a';
    *new_y = BOARD_HEIGHT - (input[4] - '0');
}

int main() {
    // initialize board
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (i == 1) {
                board[i][j] = WHITE_PAWN;
            } else if (i == 6) {
                board[i][j] = BLACK_PAWN;
            } else if (i == 0) {
                switch (j) {
                    case 0:
                    case 7:
                        board[i][j] = WHITE_ROOK;
                        break;
                    case 1:
                    case 6:
                        board[i][j] = WHITE_KNIGHT;
                        break;
                    case 2:
                    case 5:
                        board[i][j] = WHITE_BISHOP;
                        break;
                    case 3:
                        board[i][j] = WHITE_QUEEN;
                        break;
                    case 4:
                        board[i][j] = WHITE_KING;
                        break;
                }
            } else if (i == 7) {
                switch (j) {
                    case 0:
                    case 7:
                        board[i][j] = BLACK_ROOK;
                        break;
                    case 1:
                    case 6:
                        board[i][j] = BLACK_KNIGHT;
                        break;
                    case 2:
                    case 5:
                        board[i][j] = BLACK_BISHOP;
                        break;
                    case 3:
                        board[i][j] = BLACK_QUEEN;
                        break;
                    case 4:
                        board[i][j] = BLACK_KING;
                        break;
                }
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
    black_to_move = false;
    int x, y, new_x, new_y;
    while (!is_checkmate()) {
        render_board();
        printf("%s to move.\n", black_to_move ? "Black" : "White");
        while (true) {
            get_move(&x, &y, &new_x, &new_y);
            if (is_move_valid(x, y, new_x, new_y)) {
                break;
            } else {
                printf("Invalid move.\n");
            }
        }
        move_piece(x, y, new_x, new_y);
        black_to_move = !black_to_move;
    }
    render_board();
    printf("%s wins!", black_to_move ? "Black" : "White");
    return 0;
}