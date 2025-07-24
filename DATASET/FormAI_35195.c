//FormAI DATASET v1.0 Category: Chess AI ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 8
#define MAX_DEPTH 5

typedef struct {
    int row;
    int col;
} pos;

typedef struct {
    int val;
    pos move_from;
    pos move_to;
} move_val;

int board[BOARD_SIZE][BOARD_SIZE];
int human_player = 1;
int ai_player = -1;
move_val best_move;

int get_random_num(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int evaluate_board() {
    int score = 0;

    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            int piece = board[row][col];
            if (piece != 0) {
                int piece_value = abs(piece);
                score += piece_value * (piece / piece_value);
                // Add bonus for center control
                if (row == 3 || row == 4) {
                    score += (piece_value * 0.1) * (piece / piece_value);
                }
                if (col == 3 || col == 4) {
                    score += (piece_value * 0.1) * (piece / piece_value);
                }
            }
        }
    }

    return score;
}

int minimax(int depth, int alpha, int beta, int player) {
    if (depth == MAX_DEPTH || alpha >= beta) {
        return evaluate_board();
    }

    int score;
    if (player == ai_player) {
        score = -1000000;

        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++) {
                int piece = board[row][col];
                if (piece == ai_player) {
                    // Check all possible moves for piece
                    int start_row = (ai_player == -1) ? 0 : BOARD_SIZE - 1;
                    for (int offset = -1; offset < 2; offset++) {
                        if (col + offset < 0 || col + offset >= BOARD_SIZE) {
                            continue;
                        }
                        if (board[row - ai_player][col + offset] == 0) {
                            // Move piece forward
                            int tmp = board[row - ai_player][col + offset];
                            board[row - ai_player][col + offset] = ai_player;
                            board[row][col] = 0;

                            int tmp_score = minimax(depth + 1, alpha, beta, human_player);

                            if (tmp_score > score) {
                                score = tmp_score;
                                if (depth == 0) {
                                    best_move.move_from.row = row;
                                    best_move.move_from.col = col;
                                    best_move.move_to.row = row - ai_player;
                                    best_move.move_to.col = col + offset;
                                }
                            }

                            board[row - ai_player][col + offset] = tmp;
                            board[row][col] = ai_player;

                            if (score > alpha) {
                                alpha = score;
                            }
                            if (alpha >= beta) {
                                break;
                            }
                        }
                    }
                }
            }
        }

        return score;
    } else {
        score = 1000000;

        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++) {
                int piece = board[row][col];
                if (piece == human_player) {
                    // Check all possible moves for piece
                    int start_row = (human_player == -1) ? 0 : BOARD_SIZE - 1;
                    for (int offset = -1; offset < 2; offset++) {
                        if (col + offset < 0 || col + offset >= BOARD_SIZE) {
                            continue;
                        }
                        if (board[row - human_player][col + offset] == 0) {
                            // Move piece forward
                            int tmp = board[row - human_player][col + offset];
                            board[row - human_player][col + offset] = human_player;
                            board[row][col] = 0;

                            int tmp_score = minimax(depth + 1, alpha, beta, ai_player);

                            if (tmp_score < score) {
                                score = tmp_score;
                            }

                            board[row - human_player][col + offset] = tmp;
                            board[row][col] = human_player;

                            if (score < beta) {
                                beta = score;
                            }
                            if (beta <= alpha) {
                                break;
                            }
                        }
                    }
                }
            }
        }

        return score;
    }
}

void make_move(int player) {
    if (player == ai_player) {
        minimax(0, -1000000, 1000000, ai_player);
        printf("AI move: %c%d-%c%d\n", 'a' + best_move.move_from.col, best_move.move_from.row + 1,
               'a' + best_move.move_to.col, best_move.move_to.row + 1);
        board[best_move.move_to.row][best_move.move_to.col] = ai_player;
        board[best_move.move_from.row][best_move.move_from.col] = 0;
    } else {
        printf("Enter human move (e.g. a2-a3): ");
        char input[10];
        fgets(input, 10, stdin);

        char from_col_char = input[0];
        char from_row_char = input[1];
        char to_col_char = input[3];
        char to_row_char = input[4];

        int from_row = from_row_char - '0' - 1;
        int from_col = from_col_char - 'a';
        int to_row = to_row_char - '0' - 1;
        int to_col = to_col_char - 'a';

        board[to_row][to_col] = human_player;
        board[from_row][from_col] = 0;
    }
}

void print_board() {
    printf("\n  a b c d e f g h\n");
    for (int r = 0; r < BOARD_SIZE; r++) {
        printf("%d ", r + 1);

        for (int c = 0; c < BOARD_SIZE; c++) {
            if (board[r][c] == human_player) {
                printf("x ");
            } else if (board[r][c] == ai_player) {
                printf("o ");
            } else {
                printf("- ");
            }
        }
        printf("%d", r + 1);
        printf("\n");
    }
    printf("  a b c d e f g h\n\n");
}

int main() {
    // Initialize board
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            if (r == 1) {
                // Add human pieces
                board[r][c] = human_player;
            } else if (r == BOARD_SIZE - 2) {
                // Add AI pieces
                board[r][c] = ai_player;
            } else {
                board[r][c] = 0;
            }
        }
    }

    srand(time(NULL));

    while (1) {
        print_board();
        make_move(human_player);
        print_board();
        make_move(ai_player);
    }
}