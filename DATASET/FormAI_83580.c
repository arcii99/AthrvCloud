//FormAI DATASET v1.0 Category: Chess AI ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8
#define MAX_MOVES 100

int board[BOARD_SIZE][BOARD_SIZE];

int piece_values[6] = {1000, 9, 5, 3, 3, 1};

int move_evaluations[MAX_MOVES];

int valid_moves[MAX_MOVES][4];

bool white_to_move = true;

int king_pos[2][2] = {{7, 4}, {0, 4}};

void init_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
    for (i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = 2;
        board[6][i] = -2;
    }

    board[0][0] = 4;
    board[0][1] = 3;
    board[0][2] = 5;
    board[0][3] = 9;
    board[0][4] = 1000;
    board[0][5] = 5;
    board[0][6] = 3;
    board[0][7] = 4;

    board[7][0] = -4;
    board[7][1] = -3;
    board[7][2] = -5;
    board[7][3] = -9;
    board[7][4] = -1000;
    board[7][5] = -5;
    board[7][6] = -3;
    board[7][7] = -4;
}

bool valid(int x, int y, int dx, int dy) {
    if (x + dx < 0 || x + dx >= BOARD_SIZE || y + dy < 0 || y + dy >= BOARD_SIZE) {
        return false;
    }
    if (board[x+dx][y+dy] == -1000 || board[x+dx][y+dy] == 1000) {
        return false;
    }
    if (board[x][y] * board[x+dx][y+dy] > 0) {
        return false;
    }
    return true;
}

bool king_in_check(bool white) {
    int i, j, k, dx, dy, x, y;
    if (white) {
        x = king_pos[0][0];
        y = king_pos[0][1];
    } else {
        x = king_pos[1][0];
        y = king_pos[1][1];
    }
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (valid(x, y, i, j)) {
                if (board[x+i][y+j] * board[x][y] < 0) {
                    continue;
                } else {
                    return true;
                }
            }
        }
    }
    if (board[x][y] == -1000 || board[x][y] == 1000) {
        return true;
    }
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] * board[x][y] < 0 && abs(board[i][j]) != 1000) {
                dx = i - x;
                dy = j - y;
                if (dx == 0 || dy == 0 || abs(dy) == abs(dx)) {
                    if (dx == 0) {
                        k = abs(dy) / dy;
                        for (k; k * dy > 0; k += dy > 0 ? 1 : -1) {
                            if (board[x][j+k] * board[x][y] < 0) {
                                break;
                            } else if (board[x][j+k] != 0) {
                                continue;
                            }
                            if (valid(i, j, k, 0)) {
                                return true;
                            }
                        }
                    } else if (dy == 0) {
                        k = abs(dx) / dx;
                        for (k; k * dx > 0; k += dx > 0 ? 1 : -1) {
                            if (board[i+k][y] * board[x][y] < 0) {
                                break;
                            } else if (board[i+k][y] != 0) {
                                continue;
                            }
                            if (valid(i, j, 0, k)) {
                                return true;
                            }
                        }
                    } else if (abs(dy) == abs(dx)) {
                        k = abs(dx) / dx;
                        int l = abs(dy) / dy;
                        for (k, l; k * dx > 0 && l * dy > 0; k += dx > 0 ? 1 : -1, l += dy > 0 ? 1 : -1) {
                            if (board[i+k][j+l] * board[x][y] < 0) {
                                break;
                            } else if (board[i+k][j+l] != 0) {
                                continue;
                            }
                            if (valid(i, j, k, l)) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

void make_move(int x1, int y1, int x2, int y2) {
    int temp = board[x1][y1];
    board[x1][y1] = 0;
    board[x2][y2] = temp;
    if (temp == 1000 || temp == -1000) {
        if (temp == 1000) {
            king_pos[0][0] = x2;
            king_pos[0][1] = y2;
        } else {
            king_pos[1][0] = x2;
            king_pos[1][1] = y2;
        }
    }
    white_to_move = !white_to_move;
}

int evaluate_board() {
    int i, j, k, value = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            value += piece_values[abs(board[i][j])-1] * board[i][j];
        }
    }
    return value;
}

void print_board() {
    int i, j;
    printf("    a   b   c   d   e   f   g   h  \n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", BOARD_SIZE-i);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                printf("   |");
            } else if (board[i][j] > 0) {
                printf(" %d |", board[i][j]);
            } else {
                printf("%d |", board[i][j]);
            }
        }
        printf(" %d\n", BOARD_SIZE-i);
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
    printf("    a   b   c   d   e   f   g   h  \n");
}

void generate_moves() {
    int i, j, k, dx, dy;
    int move_count = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] * (white_to_move ? 1 : -1) > 0 && board[i][j] != 1000 && board[i][j] != -1000) {
                for (dx = -1; dx <= 1; dx++) {
                    for (dy = -1; dy <= 1; dy++) {
                        if (dx != 0 || dy != 0) {
                            if (valid(i, j, dx, dy)) {
                                valid_moves[move_count][0] = i;
                                valid_moves[move_count][1] = j;
                                valid_moves[move_count][2] = dx;
                                valid_moves[move_count][3] = dy;
                                move_count++;
                            }
                        }
                    }
                }
                if (board[i][j] == 1 || board[i][j] == -1) {
                    for (k = 0; k < 2; k++) {
                        if (valid(i, j, k == 0 ? 1 : -1, white_to_move ? 1 : -1)) {
                            valid_moves[move_count][0] = i;
                            valid_moves[move_count][1] = j;
                            valid_moves[move_count][2] = k == 0 ? 1 : -1;
                            valid_moves[move_count][3] = white_to_move ? 1 : -1;
                            move_count++;
                        }
                    }
                }
                if (board[i][j] == 9 || board[i][j] == -9) {
                    for (dx = -1; dx <= 1; dx++) {
                        for (dy = -1; dy <= 1; dy++) {
                            if (dx != 0 || dy != 0) {
                                if (valid(i, j, dx, dy)) {
                                    valid_moves[move_count][0] = i;
                                    valid_moves[move_count][1] = j;
                                    valid_moves[move_count][2] = dx;
                                    valid_moves[move_count][3] = dy;
                                    move_count++;
                                }
                            }
                        }
                    }
                }
                if (board[i][j] == 3 || board[i][j] == -3) {
                    for (dx = -2; dx <= 2; dx++) {
                        for (dy = -2; dy <= 2; dy++) {
                            if (dx != 0 && dy != 0 && abs(dx) != abs(dy)) {
                                if (valid(i, j, dx, dy)) {
                                    valid_moves[move_count][0] = i;
                                    valid_moves[move_count][1] = j;
                                    valid_moves[move_count][2] = dx;
                                    valid_moves[move_count][3] = dy;
                                    move_count++;
                                }
                            }
                        }
                    }
                }
                if (board[i][j] == 5 || board[i][j] == -5) {
                    for (dx = -1; dx <= 1; dx++) {
                        for (dy = -1; dy <= 1; dy++) {
                            if (dx != 0 && dy != 0 && abs(dx) != abs(dy)) {
                                if (valid(i, j, dx, dy)) {
                                    valid_moves[move_count][0] = i;
                                    valid_moves[move_count][1] = j;
                                    valid_moves[move_count][2] = dx;
                                    valid_moves[move_count][3] = dy;
                                    move_count++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void evaluate_moves() {
    int i;
    for (i = 0; i < MAX_MOVES; i++) {
        move_evaluations[i] = 0;
    }
    int current_value = evaluate_board();
    int j;
    for (i = 0; i < MAX_MOVES; i++) {
        if (valid_moves[i][0] != -1) {
            make_move(valid_moves[i][0], valid_moves[i][1], valid_moves[i][0] + valid_moves[i][2], valid_moves[i][1] + valid_moves[i][3]);
            move_evaluations[i] = evaluate_board() - current_value;
            make_move(valid_moves[i][0] + valid_moves[i][2], valid_moves[i][1] + valid_moves[i][3], valid_moves[i][0], valid_moves[i][1]);
        }
    }
}

int choose_move() {
    int i, best_move = 0, best_evaluation = -2147483647;
    for (i = 0; i < MAX_MOVES; i++) {
        if (move_evaluations[i] > best_evaluation) {
            best_evaluation = move_evaluations[i];
            best_move = i;
        }
    }
    return best_move;
}

int main() {
    init_board();
    char c[1024];
    while (true) {
        print_board();
        generate_moves();
        if (king_in_check(white_to_move)) {
            printf("%s is in check!\n", white_to_move ? "White" : "Black");
        }
        evaluate_moves();
        int move = choose_move();
        char start[2];
        start[0] = 'a' + valid_moves[move][1];
        start[1] = BOARD_SIZE - valid_moves[move][0] + '0';
        char end[2];
        end[0] = 'a' + valid_moves[move][1] + valid_moves[move][3];
        end[1] = BOARD_SIZE - valid_moves[move][0] - valid_moves[move][2] + '0';
        printf("%s to move: %c%c to %c%c\n", white_to_move ? "White" : "Black", start[0], start[1], end[0], end[1]);
        make_move(valid_moves[move][0], valid_moves[move][1], valid_moves[move][0] + valid_moves[move][2], valid_moves[move][1] + valid_moves[move][3]);
        if (king_in_check(white_to_move)) {
            printf("%s is in check!\n", white_to_move ? "White" : "Black");
        }
        if (evaluate_board() > 10000) {
            printf("White wins!\n");
            break;
        } else if (evaluate_board() < -10000) {
            printf("Black wins!\n");
            break;
        }
    }
    return 0;
}