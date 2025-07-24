//FormAI DATASET v1.0 Category: Chess AI ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

int piece_values[] = {0, 1, 3, 3, 5, 9, 0, 0, -1, -3, -3, -5, -9, 0, 0};
int is_black[14] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0};

int score_board() {
    int score = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            char piece = board[i][j];
            if (piece == ' ') {
                continue;
            }
            int index = piece - 'A';
            if (index > 5) {
                index -= 6;
            }
            if (is_black[index]) {
                score -= piece_values[index];
            } else {
                score += piece_values[index];
            }
        }
    }
    return score;
}

void print_board() {
    printf("  A B C D E F G H\n");
    printf("  ___________________\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i+1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("  --------------------\n");
}

int safe_move(int from_i, int from_j, int to_i, int to_j) {
    char piece = board[from_i][from_j];
    if (piece == 'P') {
        if (from_j == to_j && board[to_i][to_j] == ' ') {
            if (from_i - to_i == 1) {
                return 1;
            } else if (from_i - to_i == 2 && from_i == 6) {
                return 1;
            }
        } else if (abs(from_j - to_j) == 1 && from_i - to_i == 1 && board[to_i][to_j] != ' ') {
            return 1;
        }
    } else if (piece == 'p') {
        if (from_j == to_j && board[to_i][to_j] == ' ') {
            if (to_i - from_i == 1) {
                return 1;
            } else if (to_i - from_i == 2 && from_i == 1) {
                return 1;
            }
        } else if (abs(from_j - to_j) == 1 && to_i - from_i == 1 && board[to_i][to_j] != ' ') {
            return 1;
        }
    } else if (piece == 'N' || piece == 'n') {
        int diff_i = abs(from_i - to_i);
        int diff_j = abs(from_j - to_j);
        if ((diff_i == 2 && diff_j == 1) || (diff_i == 1 && diff_j == 2)) {
            return 1;
        }
    } else if (piece == 'B' || piece == 'b') {
        if (abs(from_i - to_i) == abs(from_j - to_j)) {
            int i_dir = from_i < to_i ? 1 : -1;
            int j_dir = from_j < to_j ? 1 : -1;
            int i = from_i + i_dir;
            int j = from_j + j_dir;
            while (i != to_i) {
                if (board[i][j] != ' ') {
                    return 0;
                }
                i += i_dir;
                j += j_dir;
            }
            return 1;
        }
    } else if (piece == 'R' || piece == 'r') {
        if (from_i == to_i) {
            int j_dir = from_j < to_j ? 1 : -1;
            for (int j = from_j + j_dir; j != to_j; j += j_dir) {
                if (board[from_i][j] != ' ') {
                    return 0;
                }
            }
            return 1;
        } else if (from_j == to_j) {
            int i_dir = from_i < to_i ? 1 : -1;
            for (int i = from_i + i_dir; i != to_i; i += i_dir) {
                if (board[i][from_j] != ' ') {
                    return 0;
                }
            }
            return 1;
        }
    } else if (piece == 'Q' || piece == 'q') {
        return safe_move(from_i, from_j, to_i, to_j) && safe_move_castle(from_i, from_j, to_i, to_j);
    } else if (piece == 'K' || piece == 'k') {
        int diff_i = abs(from_i - to_i);
        int diff_j = abs(from_j - to_j);
        if (diff_i <= 1 && diff_j <= 1) {
            return 1;
        } else {
            return safe_move_castle(from_i, from_j, to_i, to_j);
        }
    }
    return 0;
}

int safe_move_castle(int from_i, int from_j, int to_i, int to_j) {
    char piece = board[from_i][from_j];
    if (piece == 'K') {
        if (from_j - to_j == 2 && from_i == to_i) {
            if (board[to_i][to_j-1] == ' ' && board[to_i][to_j-2] == ' ' && board[to_i][to_j-3] == 'R') {
                return 1;
            }
        } else if (to_j - from_j == 2 && from_i == to_i) {
            if (board[to_i][to_j+1] == ' ' && board[to_i][to_j+2] == ' ' && board[to_i][to_j+3] == 'r') {
                return 1;
            }
        }
    }
    return 0;
}

void make_move(int from_i, int from_j, int to_i, int to_j) {
    char piece = board[from_i][from_j];
    board[from_i][from_j] = ' ';
    board[to_i][to_j] = piece;
}

int evaluate(int depth, int alpha, int beta, int maximizing) {
    if (depth == 0) {
        return score_board();
    }
    if (maximizing) {
        int max_score = -100000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (is_black[board[i][j]-'A'] == 0) {
                    for (int m = 0; m < BOARD_SIZE; m++) {
                        for (int n = 0; n < BOARD_SIZE; n++) {
                            if (safe_move(i, j, m, n)) {
                                char temp = board[m][n];
                                make_move(i, j, m, n);
                                int score = evaluate(depth-1, alpha, beta, 0);
                                board[m][n] = temp;
                                board[i][j] = 'K';
                                max_score = score > max_score ? score : max_score;
                                alpha = alpha > max_score ? alpha : max_score;
                                if (beta <= alpha) {
                                    return max_score;
                                }
                            }
                        }
                    }
                }
            }
        }
        return max_score;
    } else {
        int min_score = 100000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (is_black[board[i][j]-'A'] == 1) {
                    for (int m = 0; m < BOARD_SIZE; m++) {
                        for (int n = 0; n < BOARD_SIZE; n++) {
                            if (safe_move(i, j, m, n)) {
                                char temp = board[m][n];
                                make_move(i, j, m, n);
                                int score = evaluate(depth-1, alpha, beta, 1);
                                board[m][n] = temp;
                                board[i][j] = 'k';
                                min_score = score < min_score ? score : min_score;
                                beta = beta < min_score ? beta : min_score;
                                if (beta <= alpha) {
                                    return min_score;
                                }
                            }
                        }
                    }
                }
            }
        }
        return min_score;
    }
}

void computer_move() {
    int max_score = -100000;
    int from_i, from_j, to_i, to_j;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (is_black[board[i][j]-'A'] == 0) {
                for (int m = 0; m < BOARD_SIZE; m++) {
                    for (int n = 0; n < BOARD_SIZE; n++) {
                        if (safe_move(i, j, m, n)) {
                            char temp = board[m][n];
                            make_move(i, j, m, n);
                            int score = evaluate(3, -1000000, 1000000, 0);
                            board[m][n] = temp;
                            board[i][j] = 'K';
                            if (score > max_score) {
                                max_score = score;
                                from_i = i;
                                from_j = j;
                                to_i = m;
                                to_j = n;
                            }
                        }
                    }
                }
            }
        }
    }
    make_move(from_i, from_j, to_i, to_j);
}

int main() {
    print_board();
    while (1) {
        printf("Your move:\n");
        char move[5];
        scanf("%s", move);
        int from_i = move[1] - '1';
        int from_j = move[0] - 'a';
        int to_i = move[3] - '1';
        int to_j = move[2] - 'a';
        if (safe_move(from_i, from_j, to_i, to_j)) {
            make_move(from_i, from_j, to_i, to_j);
            computer_move();
            print_board();
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    return 0;
}