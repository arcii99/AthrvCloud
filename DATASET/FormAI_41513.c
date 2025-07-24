//FormAI DATASET v1.0 Category: Chess AI ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];
int pieceValue[6][2] = {{1, 10}, {3, 30}, {3, 30}, {5, 50}, {9, 90}, {1000, 0}};

void initBoard() {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if (i == 0 || i == 1 || i == 6 || i == 7) {
                if (j == 0 || j == 7) {
                    board[i][j] = 1; //rook
                } else if (j == 1 || j == 6) {
                    board[i][j] = 2; //knight
                } else if (j == 2 || j == 5) {
                    board[i][j] = 3; //bishop
                } else if (j == 3) {
                    board[i][j] = 4; //queen
                } else {
                    board[i][j] = 5; //king
                }
            } else {
                board[i][j] = 0;
            }
        }
    }
}

bool isSafe(int row, int col, int type) {
    int i, j;
    int x, y;
    int dx[8] = {1,1,0,-1,-1,-1,0,1};
    int dy[8] = {0,1,1,1,0,-1,-1,-1};
    for (i=0; i<8; i++) {
        x = row + dx[i];
        y = col + dy[i];
        if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] > 0) {
            if (pieceValue[board[x][y]-1][1] > pieceValue[type-1][1]) {
                return false;
            }
        }
    }
    return true;
}

int evaluate() {
    int i, j;
    int score = 0;
    for (i=0; i<BOARD_SIZE; i++) {
        for (j=0; j<BOARD_SIZE; j++) {
            if (board[i][j] > 0) {
                score += pieceValue[board[i][j]-1][0];
                if (board[i][j] == 5) {
                    if ((i == 0 || i == 1) && (j == 2 || j == 3 || j == 4)) {
                        score -= 20;
                    } else if ((i == 6 || i == 7) && (j == 2 || j == 3 || j == 4)) {
                        score += 20;
                    } else {
                        score -= 10*(i-3);
                    }
                }
            }
        }
    }
    return score;
}

int minMax(int depth, int alpha, int beta, bool isMax) {
    if (depth == 0) {
        return evaluate();
    }

    if (isMax) {
        int i, j;
        int value = -9999;
        for (i=0; i<BOARD_SIZE; i++) {
            for (j=0; j<BOARD_SIZE; j++) {
                if (board[i][j] > 0 && board[i][j] < 7) {
                    int temp = board[i][j];
                    int k;
                    for (k=0; k<BOARD_SIZE; k++) {
                        if (isSafe(i, j, temp)) {
                            int old = board[i][j];
                            int old2 = board[k][j];
                            board[k][j] = board[i][j];
                            board[i][j] = 0;
                            int val = minMax(depth-1, alpha, beta, !isMax);
                            board[i][j] = temp;
                            board[k][j] = old2;
                            if (val > value) {
                                value = val;
                            }
                            if (value > alpha) {
                                alpha = value;
                            }
                            if (alpha >= beta) {
                                break;
                            }
                        }
                    }
                }
            }
        }
        return value;
    } else {
        int i, j;
        int value = 9999;
        for (i=0; i<BOARD_SIZE; i++) {
            for (j=0; j<BOARD_SIZE; j++) {
                if (board[i][j] > 0 && board[i][j] < 7) {
                    int temp = board[i][j];
                    int k;
                    for (k=0; k<BOARD_SIZE; k++) {
                        if (isSafe(i, j, temp)) {
                            int old = board[i][j];
                            int old2 = board[k][j];
                            board[k][j] = board[i][j];
                            board[i][j] = 0;
                            int val = minMax(depth-1, alpha, beta, !isMax);
                            board[i][j] = temp;
                            board[k][j] = old2;
                            if (val < value) {
                                value = val;
                            }
                            if (value < beta) {
                                beta = value;
                            }
                            if (alpha >= beta) {
                                break;
                            }
                        }
                    }
                }
            }
        }
        return value;
    }
}

void printBoard() {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initBoard();
    printf("Starting Board:\n");
    printBoard();
    int score = evaluate();
    printf("\nEvaluation Score: %d\n", score);
    printf("\nNext Best Move:\n");
    minMax(2, -9999, 9999, true);
    printBoard();
    score = evaluate();
    printf("\nEvaluation Score: %d\n", score);
    return 0;
}