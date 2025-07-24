//FormAI DATASET v1.0 Category: Chess engine ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Chess board representation with array of chars
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

// Piece value for each type of chess piece
int values[] = {100, 350, 350, 500, 1000, 500, 350, 350, 100};

// Function to print the board
void print_board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to evaluate the board position based on material
int evaluate() {
    int sum = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c = board[i][j];
            if (c == ' ') continue;
            if (c >= 'A' && c <= 'Z') {
                sum += values[c-'A'];
            } else {
                sum -= values[c-'a'];
            }
        }
    }
    return sum;
}

// Function to make a move on the board
void make_move(int r1, int c1, int r2, int c2) {
    board[r2][c2] = board[r1][c1];
    board[r1][c1] = ' ';
}

// Minimax algorithm with alpha-beta pruning to find best move
int minimax(int depth, int alpha, int beta, int maximizing) {
    if (depth == 0) {
        return evaluate();
    }
    if (maximizing) {
        int best_value = -9999;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] >= 'a' && board[i][j] <= 'z') {
                    for (int k = 0; k < 8; k++) {
                        for (int l = 0; l < 8; l++) {
                            if (is_valid_move(i, j, k, l)) {
                                int old_value = board[k][l];
                                make_move(i, j, k, l);
                                int v = minimax(depth-1, alpha, beta, 0);
                                board[k][l] = old_value;
                                if (v > best_value) {
                                    best_value = v;
                                }
                                if (v > alpha) alpha = v;
                                if (beta <= alpha) return best_value;
                            }
                        }
                    }
                }
            }
        }
        return best_value;
    } else {
        int best_value = 9999;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] >= 'A' && board[i][j] <= 'Z') {
                    for (int k = 0; k < 8; k++) {
                        for (int l = 0; l < 8; l++) {
                            if (is_valid_move(i, j, k, l)) {
                                int old_value = board[k][l];
                                make_move(i, j, k, l);
                                int v = minimax(depth-1, alpha, beta, 1);
                                board[k][l] = old_value;
                                if (v < best_value) {
                                    best_value = v;
                                }
                                if (v < beta) beta = v;
                                if (beta <= alpha) return best_value;
                            }
                        }
                    }
                }
            }
        }
        return best_value;
    }
}

// Function to check if a move is valid
int is_valid_move(int r1, int c1, int r2, int c2) {
    char p = board[r1][c1];
    if (p == 'P') {
        if (r1 == 1 && r2 == 3 && c1 == c2 && board[2][c2] == ' ') {
            return 1;
        } else if (r2 == r1+1 && c1 == c2 && board[r2][c2] == ' ') {
            return 1;
        } else if (r2 == r1+1 && (c2 == c1+1 || c2 == c1-1) && board[r2][c2] >= 'a' && board[r2][c2] <= 'z') {
            return 1;
        } else {
            return 0;
        }
    } else if (p == 'p') {
        if (r1 == 6 && r2 == 4 && c1 == c2 && board[5][c2] == ' ') {
            return 1;
        } else if (r2 == r1-1 && c1 == c2 && board[r2][c2] == ' ') {
            return 1;
        } else if (r2 == r1-1 && (c2 == c1+1 || c2 == c1-1) && board[r2][c2] >= 'A' && board[r2][c2] <= 'Z') {
            return 1;
        } else {
            return 0;
        }
    } else if (p == 'R' || p == 'r') {
        if (r1 == r2) {
            int c_start = c1 < c2 ? c1+1 : c2+1;
            int c_end = c1 < c2 ? c2 : c1-1;
            for (int i = c_start; i <= c_end; i++) {
                if (board[r1][i] != ' ') {
                    return 0;
                }
            }
            if ((board[r1][c2] >= 'a' && board[r1][c2] <= 'z') == (p == 'R')) {
                return 1;
            } else {
                return 0;
            }
        } else if (c1 == c2) {
            int r_start = r1 < r2 ? r1+1 : r2+1;
            int r_end = r1 < r2 ? r2 : r1-1;
            for (int i = r_start; i <= r_end; i++) {
                if (board[i][c1] != ' ') {
                    return 0;
                }
            }
            if ((board[r2][c2] >= 'a' && board[r2][c2] <= 'z') == (p == 'R')) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else if (p == 'N' || p == 'n') {
        int dr = abs(r2-r1);
        int dc = abs(c2-c1);
        if (dr == 2 && dc == 1 || dr == 1 && dc == 2) {
            if ((board[r2][c2] >= 'a' && board[r2][c2] <= 'z') == (p == 'N')) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else if (p == 'B' || p == 'b') {
        int r_diff = r2-r1;
        int c_diff = c2-c1;
        if (abs(r_diff) != abs(c_diff)) {
            return 0;
        }
        int r_start = r1 < r2 ? r1+1 : r2+1;
        int r_end = r1 < r2 ? r2-1 : r1-1;
        int c_start = c1 < c2 ? c1+1 : c2+1;
        int c_end = c1 < c2 ? c2-1 : c1-1;
        for (int i = r_start, j = c_start; i <= r_end; i++, j++) {
            if (board[i][j] != ' ') {
                return 0;
            }
        }
        if ((board[r2][c2] >= 'a' && board[r2][c2] <= 'z') == (p == 'B')) {
            return 1;
        } else {
            return 0;
        }
    } else if (p == 'Q' || p == 'q') {
        int r_diff = r2-r1;
        int c_diff = c2-c1;
        if (r1 == r2 || c1 == c2 || abs(r_diff) == abs(c_diff)) {
            if (r1 == r2) {
                int c_start = c1 < c2 ? c1+1 : c2+1;
                int c_end = c1 < c2 ? c2 : c1-1;
                for (int i = c_start; i <= c_end; i++) {
                    if (board[r1][i] != ' ') {
                        return 0;
                    }
                }
            } else if (c1 == c2) {
                int r_start = r1 < r2 ? r1+1 : r2+1;
                int r_end = r1 < r2 ? r2 : r1-1;
                for (int i = r_start; i <= r_end; i++) {
                    if (board[i][c1] != ' ') {
                        return 0;
                    }
                }
            } else {
                int r_start = r1 < r2 ? r1+1 : r2+1;
                int r_end = r1 < r2 ? r2-1 : r1-1;
                int c_start = c1 < c2 ? c1+1 : c2+1;
                int c_end = c1 < c2 ? c2-1 : c1-1;
                for (int i = r_start, j = c_start; i <= r_end; i++, j++) {
                    if (board[i][j] != ' ') {
                        return 0;
                    }
                }
            }
            if ((board[r2][c2] >= 'a' && board[r2][c2] <= 'z') == (p == 'Q')) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else if (p == 'K' || p == 'k') {
        int dr = abs(r2-r1);
        int dc = abs(c2-c1);
        if (dr <= 1 && dc <= 1) {
            if ((board[r2][c2] >= 'a' && board[r2][c2] <= 'z') == (p == 'K')) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

// Function to find best move for the AI player
void find_move() {
    int best_value = -9999;
    int best_r1, best_c1, best_r2, best_c2;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] >= 'a' && board[i][j] <= 'z') {
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        if (is_valid_move(i, j, k, l)) {
                            int old_value = board[k][l];
                            make_move(i, j, k, l);
                            int v = minimax(3, -9999, 9999, 0);
                            board[k][l] = old_value;
                            if (v > best_value) {
                                best_value = v;
                                best_r1 = i;
                                best_c1 = j;
                                best_r2 = k;
                                best_c2 = l;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Best move: %c%d to %c%d\n", 'a'+best_c1, 8-best_r1, 'a'+best_c2, 8-best_r2);
}

int main() {
    print_board();
    printf("Evaluation: %d\n", evaluate());
    find_move();
    return 0;
}