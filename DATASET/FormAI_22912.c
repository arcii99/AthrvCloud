//FormAI DATASET v1.0 Category: Chess AI ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];

int max(int a, int b) {
    return a > b ? a : b;
}

void print_board() {
    for(int i=0; i<BOARD_SIZE; i++) {
        printf(" ");
        for(int j=0; j<BOARD_SIZE; j++) {
            printf(" %d", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int get_score() {
    int score = 0;
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == 1) {
                score++;
            } else if(board[i][j] == -1) {
                score--;
            }
        }
    }
    return score;
}

int evaluate(int player) {
    int score = get_score();
    int winner = 0;
    if(score <= -10) {
        winner = -1;
    } else if(score >= 10) {
        winner = 1;
    }
    if(winner == player) {
        return 100;
    } else if(winner == -player) {
        return -100;
    } else {
        return score;
    }
}

int minimax(int depth, int alpha, int beta, int player) {
    int score = evaluate(player);
    if(depth <= 0 || score == 100 || score == -100) {
        return score;
    }
    if(player == 1) {
        int max_score = -1000;
        for(int i=0; i<BOARD_SIZE; i++) {
            for(int j=0; j<BOARD_SIZE; j++) {
                if(board[i][j] == 0) {
                    board[i][j] = player;
                    max_score = max(max_score, minimax(depth-1, alpha, beta, -player));
                    alpha = max(alpha, max_score);
                    board[i][j] = 0;
                    if(beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return max_score;
    } else {
        int min_score = 1000;
        for(int i=0; i<BOARD_SIZE; i++) {
            for(int j=0; j<BOARD_SIZE; j++) {
                if(board[i][j] == 0) {
                    board[i][j] = player;
                    min_score = max(min_score, minimax(depth-1, alpha, beta, -player));
                    beta = max(beta, min_score);
                    board[i][j] = 0;
                    if(beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return min_score;
    }
}

void make_move(int player) {
    int x, y;
    int score = evaluate(player);
    if(score == 100) {
        printf("You win!\n");
        exit(0);
    } else if(score == -100) {
        printf("You lose!\n");
        exit(0);
    }
    printf("Player %d, make your move: ", player);
    scanf("%d %d", &x, &y);
    if(board[x][y] != 0) {
        printf("Invalid move, try again.\n");
        make_move(player);
    } else {
        board[x][y] = player;
    }
}

int main() {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
    while(1) {
        make_move(1);
        print_board();
        minimax(4, -1000, 1000, -1);
        printf("Computer moves: ");
        int best_score = -1000;
        int best_x = -1;
        int best_y = -1;
        for(int i=0; i<BOARD_SIZE; i++) {
            for(int j=0; j<BOARD_SIZE; j++) {
                if(board[i][j] == 0) {
                    board[i][j] = -1;
                    int score = minimax(4, -1000, 1000, 1);
                    if(score > best_score) {
                        best_score = score;
                        best_x = i;
                        best_y = j;
                    }
                    board[i][j] = 0;
                }
            }
        }
        board[best_x][best_y] = -1;
        printf("%d %d\n", best_x, best_y);
        print_board();
    }
}