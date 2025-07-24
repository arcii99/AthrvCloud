//FormAI DATASET v1.0 Category: Chess AI ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

int evaluate(char piece) {
    if (piece == 'K') {
        return 0;
    } else if (piece == 'Q') {
        return 9;
    } else if (piece == 'R') {
        return 5;
    } else if (piece == 'B') {
        return 3;
    } else if (piece == 'N') {
        return 3;
    } else if (piece == 'P') {
        return 1;
    } else if (piece == 'k') {
        return 0;
    } else if (piece == 'q') {
        return -9;
    } else if (piece == 'r') {
        return -5;
    } else if (piece == 'b') {
        return -3;
    } else if (piece == 'n') {
        return -3;
    } else if (piece == 'p') {
        return -1;
    }
}

int evaluate_board() {
    int score = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            score += evaluate(board[i][j]);
        }
    }

    return score;
}

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }

        printf("\n");
    }
}

int minimax(int depth, int alpha, int beta, int maximizing_player) {
    if (depth == 0) {
        return evaluate_board();
    }

    if (maximizing_player) {
        int max_score = -9999;

        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') {
                    continue;
                }

                if (board[i][j] >= 'a' && board[i][j] <= 'z') {
                    continue;
                }

                char saved_piece = board[i][j];
                board[i][j] = ' ';

                for (int r = 0; r < BOARD_SIZE; r++) {
                    for (int c = 0; c < BOARD_SIZE; c++) {
                        if (board[r][c] == ' ') {
                            board[r][c] = saved_piece;

                            int score = minimax(depth - 1, alpha, beta, 0);
                            max_score = score > max_score ? score : max_score;
                            alpha = score > alpha ? score : alpha;

                            board[r][c] = ' ';
                        }
                    }
                }

                board[i][j] = saved_piece;

                if (beta <= alpha) {
                    break;
                }
            }
        }

        return max_score;
    } else {
        int min_score = 9999;

        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') {
                    continue;
                }

                if (board[i][j] >= 'A' && board[i][j] <= 'Z') {
                    continue;
                }

                char saved_piece = board[i][j];
                board[i][j] = ' ';

                for (int r = 0; r < BOARD_SIZE; r++) {
                    for (int c = 0; c < BOARD_SIZE; c++) {
                        if (board[r][c] == ' ') {
                            board[r][c] = saved_piece;

                            int score = minimax(depth - 1, alpha, beta, 1);
                            min_score = score < min_score ? score : min_score;
                            beta = score < beta ? score : beta;

                            board[r][c] = ' ';
                        }
                    }
                }

                board[i][j] = saved_piece;

                if (beta <= alpha) {
                    break;
                }
            }
        }

        return min_score;
    }
}

void make_move(int depth) {
    int max_score = -9999;
    int move_row, move_col;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                continue;
            }

            if (board[i][j] >= 'a' && board[i][j] <= 'z') {
                continue;
            }

            char saved_piece = board[i][j];
            board[i][j] = ' ';

            for (int r = 0; r < BOARD_SIZE; r++) {
                for (int c = 0; c < BOARD_SIZE; c++) {
                    if (board[r][c] == ' ') {
                        board[r][c] = saved_piece;

                        int score = minimax(depth - 1, -10000, 10000, 0);

                        board[r][c] = ' ';

                        if (score > max_score) {
                            max_score = score;
                            move_row = r;
                            move_col = c;
                        }
                    }
                }
            }

            board[i][j] = saved_piece;
        }
    }

    board[move_row][move_col] = board[move_row - 1][move_col];
    board[move_row - 1][move_col] = ' ';
}

int main() {
    // set up initial board
    board[0][0] = 'R';
    board[0][1] = 'N';
    board[0][2] = 'B';
    board[0][3] = 'Q';
    board[0][4] = 'K';
    board[0][5] = 'B';
    board[0][6] = 'N';
    board[0][7] = 'R';

    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = 'P';
        board[BOARD_SIZE - 2][i] = 'p';
    }

    board[BOARD_SIZE - 1][0] = 'r';
    board[BOARD_SIZE - 1][1] = 'n';
    board[BOARD_SIZE - 1][2] = 'b';
    board[BOARD_SIZE - 1][3] = 'q';
    board[BOARD_SIZE - 1][4] = 'k';
    board[BOARD_SIZE - 1][5] = 'b';
    board[BOARD_SIZE - 1][6] = 'n';
    board[BOARD_SIZE - 1][7] = 'r';

    printf("Initial board:\n");
    print_board();
    printf("\n");

    // play game
    for (int i = 0; i < 3; i++) {
        make_move(3);

        printf("Board after move %d:\n", i + 1);
        print_board();
        printf("\n");
    }

    return 0;
}