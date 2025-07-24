//FormAI DATASET v1.0 Category: Chess AI ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define HUMAN 0
#define COMPUTER 1
#define SIZE 8

char board[SIZE][SIZE] = {
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

int score_board(char piece) {
    switch (piece) {
        case 'K': return 9999;
        case 'Q': return 9;
        case 'R': return 5;
        case 'B': return 3;
        case 'N': return 3;
        case 'P': return 1;
        case 'k': return -9999;
        case 'q': return -9;
        case 'r': return -5;
        case 'b': return -3;
        case 'n': return -3;
        case 'p': return -1;
        default: return 0;
    }
}

int evaluate_board() {
    int score = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            score += score_board(board[i][j]);
        }
    }

    return score;
}

int minimax(int depth, int alpha, int beta, int player) {
    if (depth == 0) {
        return evaluate_board();
    }

    if (player == COMPUTER) {
        int max_score = -9999;

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] != ' ' && board[i][j] >= 'a' && board[i][j] <= 'z') {
                    for (int k = 0; k < SIZE; k++) {
                        for (int l = 0; l < SIZE; l++) {
                            char temp = board[k][l];
                            board[k][l] = board[i][j];
                            board[i][j] = ' ';

                            int score = minimax(depth-1, alpha, beta, HUMAN);
                            if (score > max_score) {
                                max_score = score;
                            }

                            board[i][j] = board[k][l];
                            board[k][l] = temp;

                            alpha = alpha > max_score ? alpha : max_score;
                            if (beta <= alpha) {
                                break;
                            }
                        }
                    }
                }
            }
        }

        return max_score;
    } else {
        int min_score = 9999;

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] != ' ' && board[i][j] >= 'A' && board[i][j] <= 'Z') {
                    for (int k = 0; k < SIZE; k++) {
                        for (int l = 0; l < SIZE; l++) {
                            char temp = board[k][l];
                            board[k][l] = board[i][j];
                            board[i][j] = ' ';

                            int score = minimax(depth-1, alpha, beta, COMPUTER);
                            if (score < min_score) {
                                min_score = score;
                            }

                            board[i][j] = board[k][l];
                            board[k][l] = temp;

                            beta = beta < min_score ? beta : min_score;
                            if (beta <= alpha) {
                                break;
                            }
                        }
                    }
                }
            }
        }

        return min_score;
    }
}

void computer_move(int depth) {
    int max_score = -9999;
    int move_i, move_j, move_k, move_l;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != ' ' && board[i][j] >= 'a' && board[i][j] <= 'z') {
                for (int k = 0; k < SIZE; k++) {
                    for (int l = 0; l < SIZE; l++) {
                        char temp = board[k][l];
                        board[k][l] = board[i][j];
                        board[i][j] = ' ';

                        int score = minimax(depth-1, -9999, 9999, HUMAN);

                        board[i][j] = board[k][l];
                        board[k][l] = temp;

                        if (score > max_score) {
                            max_score = score;
                            move_i = i;
                            move_j = j;
                            move_k = k;
                            move_l = l;
                        }
                    }
                }
            }
        }
    }

    char piece = board[move_i][move_j];
    board[move_k][move_l] = piece;
    board[move_i][move_j] = ' ';

    printf("\nComputer moves %c from %c%d to %c%d\n", piece, 'a'+move_j, move_i+1, 'a'+move_l, move_k+1);
}

void print_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("\nStarting game...\n\n");
    print_board();

    for (int i = 0; i < 10; i++) {
        printf("\n");

        computer_move(3);
        print_board();

        printf("\n");

        char move[5];
        printf("Enter move (ex: e2e4): ");
        scanf("%s", move);

        int move_i = move[1] - '0' - 1;
        int move_j = move[0] - 'a';
        int move_k = move[3] - '0' - 1;
        int move_l = move[2] - 'a';

        char piece = board[move_i][move_j];
        board[move_k][move_l] = piece;
        board[move_i][move_j] = ' ';

        print_board();
    }

    return 0;
}