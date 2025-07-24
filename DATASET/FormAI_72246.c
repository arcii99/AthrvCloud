//FormAI DATASET v1.0 Category: Chess engine ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define MAX_DEPTH 4

#define KING 'K'
#define QUEEN 'Q'
#define BISHOP 'B'
#define KNIGHT 'N'
#define ROOK 'R'
#define PAWN 'P'

#define WHITE 0
#define BLACK 1

char board[BOARD_SIZE][BOARD_SIZE] = {
    {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK},
    {PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
    {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK}
};

int king_pos[2][2] = {{7, 4}, {0, 4}};

int evaluate(int color) {
    int score = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') continue;
            int value;
            switch(board[i][j]) {
                case PAWN:
                    value = 1;
                    break;
                case KNIGHT:
                    value = 3;
                    break;
                case BISHOP:
                    value = 3;
                    break;
                case ROOK:
                    value = 5;
                    break;
                case QUEEN:
                    value = 9;
                    break;
                case KING:
                    value = 500;
                    break;
            }
            if (('a' + j) % 2 == i % 2) value += 0.1;
            if (color == BLACK) value *= -1;
            score += value;
        }
    }
    return score;
}

int is_checkmate(int color) {
    // TODO: Implement checkmate detection
    return 0;
}

int minimax(int depth, int alpha, int beta, int color) {
    if (depth == 0 || is_checkmate(color)) {
        return evaluate(color);
    }

    int max_score = -1000;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') continue;
            int new_score = 0;
            char captured_piece = board[i][j];
            if (color == WHITE) {
                if (isupper(captured_piece)) continue;
            } else {
                if (islower(captured_piece)) continue;
            }
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 && l == 0) continue;
                    int new_i = i + k;
                    int new_j = j + l;
                    if (new_i < 0 || new_i >= BOARD_SIZE || new_j < 0 || new_j >= BOARD_SIZE) continue;
                    char moved_piece = board[new_i][new_j];
                    board[new_i][new_j] = board[i][j];
                    board[i][j] = ' ';
                    if (color == WHITE) {
                        new_score = minimax(depth - 1, alpha, beta, BLACK);
                        if (new_score > max_score) max_score = new_score;
                        alpha = alpha > new_score ? alpha : new_score;
                    } else {
                        new_score = minimax(depth - 1, alpha, beta, WHITE);
                        if (new_score < max_score) max_score = new_score;
                        beta = beta < new_score ? beta : new_score;
                    }
                    board[i][j] = board[new_i][new_j];
                    board[new_i][new_j] = moved_piece;
                    if (alpha >= beta) break;
                }
                if (alpha >= beta) break;              
            }
        }
    }
    return max_score;
}

void make_move(int row_from, int col_from, int row_to, int col_to) {
    board[row_to][col_to] = board[row_from][col_from];
    board[row_from][col_from] = ' ';
}

int main() {
    int cur_color = WHITE;
    int depth = MAX_DEPTH;
    while (!is_checkmate(cur_color)) {
        int best_score = -1000;
        int best_move[4];
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') continue;
                if (cur_color == WHITE && isupper(board[i][j])) continue;
                if (cur_color == BLACK && islower(board[i][j])) continue;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        int new_i = i + k;
                        int new_j = j + l;
                        if (new_i < 0 || new_i >= BOARD_SIZE || new_j < 0 || new_j >= BOARD_SIZE) continue;
                        if (cur_color == WHITE && isupper(board[new_i][new_j])) continue;
                        if (cur_color == BLACK && islower(board[new_i][new_j])) continue;
                        int new_score = 0;
                        char captured_piece = board[new_i][new_j];
                        char moved_piece = board[i][j];
                        board[new_i][new_j] = moved_piece;
                        board[i][j] = ' ';
                        new_score = minimax(depth, -1000, 1000, cur_color == WHITE ? BLACK : WHITE);
                        board[i][j] = moved_piece;
                        board[new_i][new_j] = captured_piece;
                        if (new_score > best_score) {
                            best_score = new_score;
                            best_move[0] = i;
                            best_move[1] = j;
                            best_move[2] = new_i;
                            best_move[3] = new_j;
                        }
                    }
                }
            }
        }
        make_move(best_move[0], best_move[1], best_move[2], best_move[3]);
        printf("%c%d to %c%d\n", 'a' + best_move[1], best_move[0] + 1, 'a' + best_move[3], best_move[2] + 1);
        cur_color = cur_color == WHITE ? BLACK : WHITE;
    }
    return 0;
}