//FormAI DATASET v1.0 Category: Chess engine ; Style: future-proof
#include<stdio.h>
#include<string.h>

#define MAX_DEPTH 5
#define BOARD_SIZE 8

int evaluateBoard(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    int score = 0;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == player) {
                score += 10;
                if((i == 0 && j == 0) || (i == 0 && j == BOARD_SIZE-1) || (i == BOARD_SIZE-1 && j == 0) || (i == BOARD_SIZE-1 && j == BOARD_SIZE-1)) {
                    score += 20;
                }
            } else if(board[i][j] != '-') {
                score -= 10;
            }
        }
    }
    return score;
}

int minimax(char board[BOARD_SIZE][BOARD_SIZE], int depth, int alpha, int beta, char player) {
    if(depth == MAX_DEPTH) {
        return evaluateBoard(board, player);
    }

    int bestScore;
    if(player == 'X') {
        bestScore = -10000;
        for(int i = 0; i < BOARD_SIZE; i++) {
            for(int j = 0; j < BOARD_SIZE; j++) {
                if(board[i][j] == '-') {
                    board[i][j] = 'X';
                    int score = minimax(board, depth+1, alpha, beta, 'O');
                    board[i][j] = '-';
                    if(score > bestScore) {
                        bestScore = score;
                    }
                    if(bestScore > alpha) {
                        alpha = bestScore;
                    }
                    if(alpha >= beta) {
                        return bestScore;
                    }
                }
            }
        }
    } else {
        bestScore = 10000;
        for(int i = 0; i < BOARD_SIZE; i++) {
            for(int j = 0; j < BOARD_SIZE; j++) {
                if(board[i][j] == '-') {
                    board[i][j] = 'O';
                    int score = minimax(board, depth+1, alpha, beta, 'X');
                    board[i][j] = '-';
                    if(score < bestScore) {
                        bestScore = score;
                    }
                    if(bestScore < beta) {
                        beta = bestScore;
                    }
                    if(beta <= alpha) {
                        return bestScore;
                    }
                }
            }
        }
    }

    return bestScore;
}

void computerMove(char board[BOARD_SIZE][BOARD_SIZE]) {
    int bestScore = -10000;
    int bestI, bestJ;

    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == '-') {
                board[i][j] = 'X';
                int score = minimax(board, 0, -10000, 10000, 'O');
                board[i][j] = '-';
                if(score > bestScore) {
                    bestScore = score;
                    bestI = i;
                    bestJ = j;
                }
            }
        }
    }

    board[bestI][bestJ] = 'X';
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];

    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }

    while(1) {
        printf("Enter row and column (starting from 0) separated by a space: ");
        int row, col;
        scanf("%d %d", &row, &col);

        if(board[row][col] != '-') {
            printf("Position already occupied, try again.\n");
            continue;
        }

        board[row][col] = 'O';

        computerMove(board);

        printf("\nBoard:\n");
        for(int i = 0; i < BOARD_SIZE; i++) {
            for(int j = 0; j < BOARD_SIZE; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        int score = evaluateBoard(board, 'X');

        if(score >= 100) {
            printf("You Lost!\n");
            break;
        } else if(score <= -100) {
            printf("You Won!\n");
            break;
        }

        int emptyCells = 0;
        for(int i = 0; i < BOARD_SIZE; i++) {
            for(int j = 0; j < BOARD_SIZE; j++) {
                if(board[i][j] == '-') {
                    emptyCells++;
                }
            }
        }

        if(emptyCells == 0) {
            printf("Draw!\n");
            break;
        }
    }

    return 0;
}