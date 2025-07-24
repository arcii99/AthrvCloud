//FormAI DATASET v1.0 Category: Chess AI ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BOARD_SIZE 8
#define MAX_DEPTH 6

char board[8][8] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

const int pawn_value = 1;
const int knight_value = 3;
const int bishop_value = 3;
const int rook_value = 5;
const int queen_value = 9;
const int king_value = 1000;

int search_depth = 0;

int evaluate_position()
{

    int white = 0;
    int black = 0;

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            switch (board[i][j]) {
                case 'P':
                    white += pawn_value;
                    break;
                case 'p':
                    black += pawn_value;
                    break;
                case 'N':
                    white += knight_value;
                    break;
                case 'n':
                    black += knight_value;
                    break;
                case 'B':
                    white += bishop_value;
                    break;
                case 'b':
                    black += bishop_value;
                    break;
                case 'R':
                    white += rook_value;
                    break;
                case 'r':
                    black += rook_value;
                    break;
                case 'Q':
                    white += queen_value;
                    break;
                case 'q':
                    black += queen_value;
                    break;
                case 'K':
                    white += king_value;
                    break;
                case 'k':
                    black += king_value;
                    break;
            }
        }
    }

    return white - black;
}

int minmax_with_alpha_beta_pruning(int depth, int alpha, int beta, char player) {

    if (depth == 0) {
        return evaluate_position();
    }

    search_depth++;

    if (player == 'W') {

        int best_score = -10000;

        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] >= 'A' && board[i][j] <= 'Z') {
                    for (int k = 0; k < BOARD_SIZE; ++k) {
                        for (int l = 0; l < BOARD_SIZE; ++l) {

                            if (board[i][j] == 'P') {

                                if (board[k][l] == ' ') {
                                    if (i == k + 1 && (j == l + 1 || j == l - 1)) {
                                        char temp = board[i][j];
                                        board[i][j] = ' ';
                                        board[k][l] = temp;
                                        int score = minmax_with_alpha_beta_pruning(depth - 1, alpha, beta, 'B');
                                        if (score > best_score) {
                                            best_score = score;
                                        }
                                        alpha = alpha > score ? alpha : score;
                                        board[k][l] = ' ';
                                        board[i][j] = temp;
                                        if (beta <= alpha) {
                                            return best_score;
                                        }
                                    }
                                }
                            } else {

                                if (board[k][l] == ' ' || (board[k][l] >= 'a' && board[k][l] <= 'z')) {

                                    char temp = board[i][j];
                                    board[i][j] = ' ';
                                    board[k][l] = temp;
                                    int score = minmax_with_alpha_beta_pruning(depth - 1, alpha, beta, 'B');
                                    if (score > best_score) {
                                        best_score = score;
                                    }
                                    alpha = alpha > score ? alpha : score;
                                    board[k][l] = ' ';
                                    board[i][j] = temp;
                                    if (beta <= alpha) {
                                        return best_score;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        return best_score;

    } else {

        int best_score = 10000;

        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] >= 'a' && board[i][j] <= 'z') {
                    for (int k = 0; k < BOARD_SIZE; ++k) {
                        for (int l = 0; l < BOARD_SIZE; ++l) {

                            if (board[i][j] == 'p') {

                                if (board[k][l] == ' ') {
                                    if (i == k - 1 && (j == l + 1 || j == l - 1)) {
                                        char temp = board[i][j];
                                        board[i][j] = ' ';
                                        board[k][l] = temp;
                                        int score = minmax_with_alpha_beta_pruning(depth - 1, alpha, beta, 'W');
                                        if (score < best_score) {
                                            best_score = score;
                                        }
                                        beta = beta < score ? beta : score;
                                        board[k][l] = ' ';
                                        board[i][j] = temp;
                                        if (beta <= alpha) {
                                            return best_score;
                                        }
                                    }
                                }

                            } else {

                                if (board[k][l] == ' ' || (board[k][l] >= 'A' && board[k][l] <= 'Z')) {

                                    char temp = board[i][j];
                                    board[i][j] = ' ';
                                    board[k][l] = temp;
                                    int score = minmax_with_alpha_beta_pruning(depth - 1, alpha, beta, 'W');
                                    if (score < best_score) {
                                        best_score = score;
                                    }
                                    beta = beta < score ? beta : score;
                                    board[k][l] = ' ';
                                    board[i][j] = temp;
                                    if (beta <= alpha) {
                                        return best_score;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        return best_score;
    }
}

int main() {

    printf("Welcome to the Cyberpunk Chess AI!\n\n");

    srand(time(0));

    char player = 'W';

    while (1) {

        search_depth = 0;

        printf("Current board:\n\n");

        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        if (player == 'W' || player == 'w') {

            printf("\nYour move (in the format e2e4): ");
            char move[5];
            scanf("%s", move);

            int x1 = move[0] - 'a';
            int y1 = BOARD_SIZE - (move[1] - '0');
            int x2 = move[2] - 'a';
            int y2 = BOARD_SIZE - (move[3] - '0');

            char piece = board[y1][x1];
            board[y1][x1] = ' ';
            board[y2][x2] = piece;

            player = 'B';

        } else {

            int best_score = -10000;
            int best_x1, best_y1, best_x2, best_y2;

            for (int i = 0; i < BOARD_SIZE; ++i) {
                for (int j = 0; j < BOARD_SIZE; ++j) {
                    if (board[i][j] >= 'A' && board[i][j] <= 'Z') {
                        for (int k = 0; k < BOARD_SIZE; ++k) {
                            for (int l = 0; l < BOARD_SIZE; ++l) {

                                if (board[i][j] == 'P') {

                                    if (board[k][l] == ' ') {
                                        if (i == k + 1 && (j == l + 1 || j == l - 1)) {
                                            char temp = board[i][j];
                                            board[i][j] = ' ';
                                            board[k][l] = temp;
                                            int score = minmax_with_alpha_beta_pruning(MAX_DEPTH, -10000, 10000, 'B');
                                            if (score > best_score) {
                                                best_score = score;
                                                best_x1 = j;
                                                best_y1 = i;
                                                best_x2 = l;
                                                best_y2 = k;
                                            }
                                            board[k][l] = ' ';
                                            board[i][j] = temp;
                                        }
                                    }
                                } else {

                                    if (board[k][l] == ' ' || (board[k][l] >= 'a' && board[k][l] <= 'z')) {

                                        char temp = board[i][j];
                                        board[i][j] = ' ';
                                        board[k][l] = temp;
                                        int score = minmax_with_alpha_beta_pruning(MAX_DEPTH, -10000, 10000, 'B');
                                        if (score > best_score) {
                                            best_score = score;
                                            best_x1 = j;
                                            best_y1 = i;
                                            best_x2 = l;
                                            best_y2 = k;
                                        }
                                        board[k][l] = ' ';
                                        board[i][j] = temp;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            board[best_y1][best_x1] = ' ';
            board[best_y2][best_x2] = 'P';

            printf("\nCyberpunk Chess AI moved from %c%d to %c%d\n", 'a' + best_x1, BOARD_SIZE - best_y1, 'a' + best_x2, BOARD_SIZE - best_y2);

            player = 'W';

        }

        int score = evaluate_position();

        printf("\nScore: %d", score);

        if (score == 1000) {
            printf("\nCyberpunk Chess AI has won!");
            break;
        } else if (score == -1000) {
            printf("\nYou have won!");
            break;
        }

        if (search_depth == 0) {
            printf("\nStalemate! The game is a draw.");
            break;
        }
    }

    return 0;
}