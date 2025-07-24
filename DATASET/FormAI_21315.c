//FormAI DATASET v1.0 Category: Chess engine ; Style: Claude Shannon
#include <stdio.h>
#define MAX_DEPTH 3
#define MIN_EVAL -9999999
#define MAX_EVAL 9999999

// Chess board representation
int board[8][8] = {{-1, -2, -3, -4, -5, -3, -2, -1},
                   {-6, -6, -6, -6, -6, -6, -6, -6},
                   {0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0},
                   {6, 6, 6, 6, 6, 6, 6, 6},
                   {1, 2, 3, 4, 5, 3, 2, 1}};

// Piece values
int piece_values[7] = {100, 300, 350, 500, 900, 1000, 0};

// Evaluate board position
int evaluate() {
    int i, j, score = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (board[i][j] > 0) {
                score += piece_values[board[i][j]-1];
            } else if (board[i][j] < 0) {
                score -= piece_values[-board[i][j]-1];
            }
        }
    }
    return score;
}

// Check if move is valid
int is_valid_move(int x1, int y1, int x2, int y2, int player) {
    if (x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7 || x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7) {
        return 0;
    }
    if (board[x1][y1] * player <= 0 || board[x1][y1] == 6 || board[x1][y1] == -6) {
        return 0;
    }
    if (board[x2][y2] * player > 0) {
        return 0;
    }
    int dx = x2 - x1;
    int dy = y2 - y1;
    if (board[x1][y1] == 1 && dx*player <= 0) {
        return 0;
    }
    if (board[x1][y1] == -1 && dx*player >= 0) {
        return 0;
    }
    if (dx*player < -2 || dx*player > 2 || dy < -2 || dy > 2) {
        return 0;
    }
    if (board[x1][y1] == 1 || board[x1][y1] == -1) {
        if (dx*player == 2 && (x1 != 1 && x1 != 6)) {
            return 0;
        }
        if (dy == 0 && board[x2][y2] != 0) {
            return 0;
        }
        if (dy != 0 && (board[x2][y2] * player <= 0 || dy*player > 1)) {
            return 0;
        }
    }
    if (board[x1][y1] == 2 || board[x1][y1] == -2) {
        if ((dx*player != 0 && dy*player != 0) || !is_path_clear(x1, y1, x2, y2)) {
            return 0;
        }
    }
    if (board[x1][y1] == 3 || board[x1][y1] == -3) {
        if ((dx*player != 0 && dy*player != 0) || !is_path_clear(x1, y1, x2, y2) || abs(dx) != abs(dy)) {
            return 0;
        }
    }
    if (board[x1][y1] == 4 || board[x1][y1] == -4) {
        if ((dx*player != 0 && dy*player != 0) || !is_path_clear(x1, y1, x2, y2) || abs(dx) > 1 || abs(dy) > 1) {
            return 0;
        }
    }
    if (board[x1][y1] == 5 || board[x1][y1] == -5) {
        if ((dx*player != 0 && dy*player != 0) || !is_path_clear(x1, y1, x2, y2) || (abs(dx) != 1 && dx != 0) || (abs(dy) != 1 && dy != 0)) {
            return 0;
        }
    }
    return 1;
}

// Check if path is clear for bishop, rook, and queen
int is_path_clear(int x1, int y1, int x2, int y2) {
    int i, j, dx = x2 - x1, dy = y2 - y1;
    if (dx != 0) {
        dx /= abs(dx);
    }
    if (dy != 0) {
        dy /= abs(dy);
    }
    for (i = x1+dx, j = y1+dy; i != x2 || j != y2; i += dx, j += dy) {
        if (board[i][j] != 0) {
            return 0;
        }
    }
    return 1;
}

// Make a move
void make_move(int x1, int y1, int x2, int y2, int player) {
    int temp = board[x2][y2];
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = 0;
    if (abs(temp) == 6 && abs(y2-y1) == 2) {
        board[x2][y2 - (y2-y1)/2] = player == 1 ? -1 : 1;
    }
    if (abs(board[x2][y2]) == 1 && (x2 == 0 || x2 == 7)) {
        board[x2][y2] *= 5;
    }
}

// Undo a move
void undo_move(int x1, int y1, int x2, int y2, int player, int temp) {
    board[x1][y1] = board[x2][y2];
    board[x2][y2] = temp;
    if (abs(temp) == 6 && abs(y2-y1) == 2) {
        board[x2][y2 - (y2-y1)/2] = 0;
    }
    if (abs(board[x1][y1]) == 5 && (x1 == 0 || x1 == 7)) {
        board[x1][y1] /= 5;
    }
}

// Check if game is over
int is_game_over() {
    int i, j, king_counter = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (board[i][j] == 6 || board[i][j] == -6) {
                king_counter++;
            }
        }
    }
    return king_counter < 2;
}

// Minimax algorithm
int minimax(int depth, int alpha, int beta, int player) {
    if (depth == MAX_DEPTH || is_game_over()) {
        return evaluate();
    }
    int i, j, temp, max_eval = MIN_EVAL, min_eval = MAX_EVAL;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (board[i][j] * player > 0) {
                int x, y;
                for (x = 0; x < 8; x++) {
                    for (y = 0; y < 8; y++) {
                        if (is_valid_move(i, j, x, y, player)) {
                            temp = board[x][y];
                            make_move(i, j, x, y, player);
                            int eval = minimax(depth+1, alpha, beta, -player);
                            undo_move(i, j, x, y, player, temp);
                            if (player == 1) {
                                if (eval > max_eval) {
                                    max_eval = eval;
                                    if (depth == 0) {
                                        printf("%c%d%c%d", j+'a', 8-i, y+'a', 8-x);
                                    }
                                }
                                alpha = alpha > eval ? alpha : eval;
                                if (beta <= alpha) {
                                    return max_eval;
                                }
                            } else {
                                if (eval < min_eval) {
                                    min_eval = eval;
                                }
                                beta = beta < eval ? beta : eval;
                                if (beta <= alpha) {
                                    return min_eval;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return player == 1 ? max_eval : min_eval;
}

int main() {
    minimax(0, MIN_EVAL, MAX_EVAL, 1);
    return 0;
}