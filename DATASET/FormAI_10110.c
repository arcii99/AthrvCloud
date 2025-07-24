//FormAI DATASET v1.0 Category: Chess AI ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10

int evaluate_board(char board[][MAXSIZE], char turn) {
    int i, j, score = 0;
    int pawn_value = 1, knight_value = 3, bishop_value = 3, rook_value = 5, queen_value = 9;

    for (i = 0; i < MAXSIZE; i++) {
        for (j = 0; j < MAXSIZE; j++) {
            if (turn == 'w') {
                if (board[i][j] == 'P') score += pawn_value;
                else if (board[i][j] == 'N') score += knight_value;
                else if (board[i][j] == 'B') score += bishop_value;
                else if (board[i][j] == 'R') score += rook_value;
                else if (board[i][j] == 'Q') score += queen_value;
            } else {
                if (board[i][j] == 'p') score -= pawn_value;
                else if (board[i][j] == 'n') score -= knight_value;
                else if (board[i][j] == 'b') score -= bishop_value;
                else if (board[i][j] == 'r') score -= rook_value;
                else if (board[i][j] == 'q') score -= queen_value;
            }
        }
    }
    return score;
}

/* Function to generate all possible moves */
int generate_moves(int movelist[][2], char board[][MAXSIZE], int turn) {
    int i, j, n = 0;
    char piece = turn == 0 ? 'P' : 'p';

    for (i = 0; i < MAXSIZE; i++) {
        for (j = 0; j < MAXSIZE; j++) {
            if (board[i][j] == piece) {
                if (turn == 0 && i-1 >= 0 && board[i-1][j] == ' ') {
                    movelist[n][0] = i;
                    movelist[n][1] = j;
                    n++;
                } else if (turn == 1 && i+1 < MAXSIZE && board[i+1][j] == ' ') {
                    movelist[n][0] = i;
                    movelist[n][1] = j;
                    n++;
                }
            }
        }
    }
    return n;
}

/* Function to perform a move and return the score */
int make_move(int move[], char board[][MAXSIZE], char turn) {
    int score = 0;
    int old_row = move[0], old_col = move[1];
    int new_row = move[2], new_col = move[3];

    if (turn == 'w') { // white's turn
        score = evaluate_board(board, turn);
        board[new_row][new_col] = board[old_row][old_col];
        board[old_row][old_col] = ' ';
        score = evaluate_board(board, turn);
    } else { // black's turn
        score = evaluate_board(board, turn);
        board[new_row][new_col] = board[old_row][old_col];
        board[old_row][old_col] = ' ';
        score = evaluate_board(board, turn);
    }
    return score;
}

int minimax(char board[][MAXSIZE], int depth, char turn, int alpha, int beta) {
    int i, best_score, current_score, n_moves;
    int best_move[4], movelist[MAXSIZE*MAXSIZE][2];
    char new_board[MAXSIZE][MAXSIZE];

    if (depth == 0) {
        return evaluate_board(board, turn);
    }

    n_moves = generate_moves(movelist, board, turn);

    if (n_moves == 0) {
        return -1000000;
    }

    if (turn == 'w') {
        best_score = -1000000;
        for (i = 0; i < n_moves; i++) {
            memcpy(new_board, board, MAXSIZE*MAXSIZE);
            current_score = make_move(&(movelist[i]), new_board, 'w');
            current_score += minimax(new_board, depth-1, 'b', alpha, beta);

            if (current_score > best_score) {
                best_score = current_score;
                memcpy(best_move, movelist[i], 4*sizeof(int));
            }

            if (best_score > alpha) {
                alpha = best_score;
            }

            if (beta <= alpha) {
                break;
            }
        }
    } else {
        best_score = 1000000;
        for (i = 0; i < n_moves; i++) {
            memcpy(new_board, board, MAXSIZE*MAXSIZE);
            current_score = make_move(&(movelist[i]), new_board, 'b');
            current_score += minimax(new_board, depth-1, 'w', alpha, beta);

            if (current_score < best_score) {
                best_score = current_score;
                memcpy(best_move, movelist[i], 4*sizeof(int));
            }

            if (best_score < beta) {
                beta = best_score;
            }

            if (beta <= alpha) {
                break;
            }
        }
    }

    if (depth == 2) {
        printf("Best Move: %c%d %c%d\n", 'a'+best_move[1], 8-best_move[0], 'a'+best_move[3], 8-best_move[2]);
    }

    return best_score;
}

int main() {
    char board[MAXSIZE][MAXSIZE] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };

    printf("Initial Board:\n");
    for (int i = 0; i < MAXSIZE; i++) {
        for (int j = 0; j < MAXSIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    minimax(board, 2, 'w', -1000000, 1000000);
    return 0;
}