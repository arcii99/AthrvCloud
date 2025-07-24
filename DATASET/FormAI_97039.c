//FormAI DATASET v1.0 Category: Checkers Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];
int turn;

void init_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) board[i][j] = -1;
                else if (i > 4) board[i][j] = 1;
                else board[i][j] = 0;
            } else {
                board[i][j] = 0;
            }
        }
    }
}

void draw_board() {
    int i, j;
    printf("  0 1 2 3 4 5 6 7\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) printf(" -");
            else if (board[i][j] == 1) printf(" B");
            else if (board[i][j] == 2) printf(" W");
            else if (board[i][j] == 3) printf(" b");
            else if (board[i][j] == 4) printf(" w");
        }
        printf("\n");
    }
}

int valid_move(int x, int y, int nx, int ny) {
    int dx = nx - x;
    int dy = ny - y;
    if (board[nx][ny] != 0) return 0;
    if (turn == 1) {
        if (dx != 1 || (dy != 1 && dy != -1)) return 0;
        if (ny == y) return 0;
        return 1;
    } else {
        if (dx != -1 || (dy != 1 && dy != -1)) return 0;
        if (ny == y) return 0;
        return 1;
    }
}

int valid_jump(int x, int y, int nx, int ny) {
    int dx = nx - x;
    int dy = ny - y;
    int sx = x + dx / 2;
    int sy = y + dy / 2;
    if (board[sx][sy] == 0 || board[nx][ny] != 0) return 0;
    if (turn == 1) {
        if (dx != 2 || (dy != 2 && dy != -2)) return 0;
        if (ny == y + 2 && board[x+1][y+1] != 2) return 0;
        if (ny == y - 2 && board[x+1][y-1] != 2) return 0;
        return 1;
    } else {
        if (dx != -2 || (dy != 2 && dy != -2)) return 0;
        if (ny == y + 2 && board[x-1][y+1] != 1) return 0;
        if (ny == y - 2 && board[x-1][y-1] != 1) return 0;
        return 1;
    }
}

int check_jump(int x, int y) {
    if (turn == 1) {
        if (x + 2 < BOARD_SIZE && y + 2 < BOARD_SIZE && valid_jump(x, y, x+2, y+2)) return 1;
        if (x + 2 < BOARD_SIZE && y - 2 >= 0 && valid_jump(x, y, x+2, y-2)) return 1;
    } else {
        if (x - 2 >= 0 && y + 2 < BOARD_SIZE && valid_jump(x, y, x-2, y+2)) return 1;
        if (x - 2 >= 0 && y - 2 >= 0 && valid_jump(x, y, x-2, y-2)) return 1;
    }
    return 0;
}

int check_move(int x, int y) {
    if (turn == 1) {
        if (x + 1 < BOARD_SIZE && y + 1 < BOARD_SIZE && valid_move(x, y, x+1, y+1)) return 1;
        if (x + 1 < BOARD_SIZE && y - 1 >= 0 && valid_move(x, y, x+1, y-1)) return 1;
    } else {
        if (x - 1 >= 0 && y + 1 < BOARD_SIZE && valid_move(x, y, x-1, y+1)) return 1;
        if (x - 1 >= 0 && y - 1 >= 0 && valid_move(x, y, x-1, y-1)) return 1;
    }
    return 0;
}

int check_terminal() {
    int i, j, bcount = 0, wcount = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 1 || board[i][j] == 3) bcount++;
            if (board[i][j] == 2 || board[i][j] == 4) wcount++;
            if (bcount > 0 && wcount > 0) return 0;
        }
    }
    if (bcount == 0) return 2;
    if (wcount == 0) return 1;
    return 0;
}

int choose_move() {
    int i, j, k, l;
    int max_score = -1000000;
    int max_score_moves[3][4][2];
    int num_max_score_moves = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((turn == 1 && board[i][j] != 1 && board[i][j] != 3) ||
                (turn == 2 && board[i][j] != 2 && board[i][j] != 4)) continue;
            if (check_jump(i, j)) {
                for (k = 0; k < BOARD_SIZE; k++) {
                    for (l = 0; l < BOARD_SIZE; l++) {
                        if (valid_jump(i, j, k, l)) {
                            int temp_board[BOARD_SIZE][BOARD_SIZE];
                            memcpy(temp_board, board, sizeof(temp_board));
                            int score = do_jump(i, j, k, l);
                            if (score > max_score) {
                                max_score = score;
                                num_max_score_moves = 1;
                                max_score_moves[0][0][0] = i;
                                max_score_moves[0][0][1] = j;
                                max_score_moves[0][1][0] = k;
                                max_score_moves[0][1][1] = l;
                            } else if (score == max_score) {
                                max_score_moves[num_max_score_moves][0][0] = i;
                                max_score_moves[num_max_score_moves][0][1] = j;
                                max_score_moves[num_max_score_moves][1][0] = k;
                                max_score_moves[num_max_score_moves][1][1] = l;
                                num_max_score_moves++;
                            }
                            memcpy(board, temp_board, sizeof(temp_board));
                        }
                    }
                }
            } else if (check_move(i, j)) {
                for (k = 0; k < BOARD_SIZE; k++) {
                    for (l = 0; l < BOARD_SIZE; l++) {
                        if (valid_move(i, j, k, l)) {
                            int temp_board[BOARD_SIZE][BOARD_SIZE];
                            memcpy(temp_board, board, sizeof(temp_board));
                            int score = do_move(i, j, k, l);
                            if (score > max_score) {
                                max_score = score;
                                num_max_score_moves = 1;
                                max_score_moves[0][0][0] = i;
                                max_score_moves[0][0][1] = j;
                                max_score_moves[0][1][0] = k;
                                max_score_moves[0][1][1] = l;
                            } else if (score == max_score) {
                                max_score_moves[num_max_score_moves][0][0] = i;
                                max_score_moves[num_max_score_moves][0][1] = j;
                                max_score_moves[num_max_score_moves][1][0] = k;
                                max_score_moves[num_max_score_moves][1][1] = l;
                                num_max_score_moves++;
                            }
                            memcpy(board, temp_board, sizeof(temp_board));
                        }
                    }
                }
            }
        }
    }
    if (num_max_score_moves > 0) {
        int move = rand() % num_max_score_moves;
        do_move(max_score_moves[move][0][0], max_score_moves[move][0][1],
            max_score_moves[move][1][0], max_score_moves[move][1][1]);
        return 1;
    }
    return 0;
}

int do_move(int x, int y, int nx, int ny) {
    if (!valid_move(x, y, nx, ny)) return 0;
    if (nx == 0 || nx == BOARD_SIZE-1) board[nx][ny] += 2;
    board[nx][ny] = board[x][y];
    board[x][y] = 0;
    turn = (turn == 1) ? 2 : 1;
    return 1;
}

int do_jump(int x, int y, int nx, int ny) {
    if (!valid_jump(x, y, nx, ny)) return 0;
    int dx = nx - x;
    int dy = ny - y;
    int sx = x + dx / 2;
    int sy = y + dy / 2;
    int score = (turn == 1) ? dx : -dx;
    if (nx == 0 || nx == BOARD_SIZE-1) board[nx][ny] += 2;
    board[nx][ny] = board[x][y];
    board[sx][sy] = 0;
    board[x][y] = 0;
    turn = (turn == 1) ? 2 : 1;
    if (check_jump(nx, ny)) {
        int i, j;
        int max_score = -1000000;
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                if (valid_jump(nx, ny, i, j)) {
                    int temp_board[BOARD_SIZE][BOARD_SIZE];
                    memcpy(temp_board, board, sizeof(temp_board));
                    int s = do_jump(nx, ny, i, j);
                    if (s > max_score) max_score = s;
                    memcpy(board, temp_board, sizeof(temp_board));
                }
            }
        }
        score += max_score;
    }
    return score;
}

int main() {
    init_board();
    draw_board();
    turn = 1;
    while (1) {
        if (check_terminal() > 0) break;
        if (turn == 1) {
            printf("Black's turn\n");
            int x, y, nx, ny;
            printf("Enter move: ");
            scanf("%d %d %d %d", &x, &y, &nx, &ny);
            if (do_jump(x, y, nx, ny)) {
                draw_board();
                printf("Black jumped from (%d, %d) to (%d, %d)\n", x, y, nx, ny);
            } else if (do_move(x, y, nx, ny)) {
                draw_board();
                printf("Black moved from (%d, %d) to (%d, %d)\n", x, y, nx, ny);
            } else {
                printf("Invalid move\n");
            }
        } else {
            printf("White's turn\n");
            choose_move();
            draw_board();
        }
        turn = (turn == 1) ? 2 : 1;
    }
    int winner = check_terminal();
    if (winner == 1) printf("Black wins!\n");
    else if (winner == 2) printf("White wins!\n");
    else printf("Tie game!\n");
    return 0;
}