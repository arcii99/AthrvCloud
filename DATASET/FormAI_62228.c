//FormAI DATASET v1.0 Category: Chess AI ; Style: retro
#include <stdio.h>

char board[8][8] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

int evaluate() {
    int i, j, score = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (board[i][j] == 'P') {
                score += 1;
            } else if (board[i][j] == 'N') {
                score += 3;
            } else if (board[i][j] == 'B') {
                score += 3;
            } else if (board[i][j] == 'R') {
                score += 5;
            } else if (board[i][j] == 'Q') {
                score += 9;
            } else if (board[i][j] == 'p') {
                score -= 1;
            } else if (board[i][j] == 'n') {
                score -= 3;
            } else if (board[i][j] == 'b') {
                score -= 3;
            } else if (board[i][j] == 'r') {
                score -= 5;
            } else if (board[i][j] == 'q') {
                score -= 9;
            }
        }
    }
    return score;
}

int alpha_beta_pruning(int alpha, int beta, int depth, int max_player) {
    if (depth == 0) {
        return evaluate();
    }

    // Check if checkmate has been reached
    if (max_player) {
        int i, j, k, l, best_score = -1000;
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (board[i][j] == 'P') {
                    // Check moves for pawn
                    if (i != 0 && board[i - 1][j + 1] && board[i - 1][j + 1] != ' ') {
                        int temp = board[i - 1][j + 1];
                        board[i - 1][j + 1] = 'P';
                        board[i][j] = ' ';
                        int score = alpha_beta_pruning(alpha, beta, depth - 1, 0);
                        board[i - 1][j + 1] = temp;
                        board[i][j] = 'P';
                        if (score > best_score) {
                            best_score = score;
                        }
                        if (score > alpha) {
                            alpha = score;
                        }
                        if (alpha >= beta) {
                            return alpha;
                        }
                    }
                    if (board[i - 1][j] == ' ') {
                        board[i - 1][j] = 'P';
                        board[i][j] = ' ';
                        int score = alpha_beta_pruning(alpha, beta, depth - 1, 0);
                        board[i - 1][j] = ' ';
                        board[i][j] = 'P';
                        if (score > best_score) {
                            best_score = score;
                        }
                        if (score > alpha) {
                            alpha = score;
                        }
                        if (alpha >= beta) {
                            return alpha;
                        }
                    }
                }
            }
        }
        return best_score;
    } else {
        int i, j, best_score = 1000;
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (board[i][j] == 'p') {
                    // Check moves for pawn
                    if (i != 7 && board[i + 1][j + 1] && board[i + 1][j + 1] != ' ') {
                        int temp = board[i + 1][j + 1];
                        board[i + 1][j + 1] = 'p';
                        board[i][j] = ' ';
                        int score = alpha_beta_pruning(alpha, beta, depth - 1, 1);
                        board[i + 1][j + 1] = temp;
                        board[i][j] = 'p';
                        if (score < best_score) {
                            best_score = score;
                        }
                        if (score < beta) {
                            beta = score;
                        }
                        if (alpha >= beta) {
                            return beta;
                        }
                    }
                    if (board[i + 1][j] == ' ') {
                        board[i + 1][j] = 'p';
                        board[i][j] = ' ';
                        int score = alpha_beta_pruning(alpha, beta, depth - 1, 1);
                        board[i + 1][j] = ' ';
                        board[i][j] = 'p';
                        if (score < best_score) {
                            best_score = score;
                        }
                        if (score < beta) {
                            beta = score;
                        }
                        if (alpha >= beta) {
                            return beta;
                        }
                    }
                }
            }
        }
        return best_score;
    }
}

void print_board() {
    int i, j;
    printf("\n   a b c d e f g h\n");
    for (i = 0; i < 8; i++) {
        printf("%d  ", 8 - i);
        for (j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", 8 - i);
    }
    printf("   a b c d e f g h\n");
}

int main() {
    char input[10];
    print_board();

    while (1) {
        int best_move[2] = {-1, -1}, i, j, best_score = -1000;
        printf("\nYour Move (Ex. E2E4):\n");
        scanf("%s", input);
        if (input[0] == 'q') break;
        int start_i = 8 - (input[1] - '0');
        int start_j = input[0] - 'a';
        int end_i = 8 - (input[3] - '0');
        int end_j = input[2] - 'a';
        int temp = board[end_i][end_j];
        board[end_i][end_j] = board[start_i][start_j];
        board[start_i][start_j] = ' ';
        int score = alpha_beta_pruning(-1000, 1000, 2, 0);
        board[start_i][start_j] = board[end_i][end_j];
        board[end_i][end_j] = temp;
        printf("Score: %d\n", score);
        print_board();
    }
    return 0;
}