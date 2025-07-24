//FormAI DATASET v1.0 Category: Chess AI ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int evaluateBoard(char board[8][8]) {
    int i, j, score = 0;
    char piece;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            piece = board[i][j];
            if (piece == 'p') {
                score -= 10;
            } else if (piece == 'P') {
                score += 10;
            } else if (piece == 'n') {
                score -= 30;
            } else if (piece == 'N') {
                score += 30;
            } else if (piece == 'b') {
                score -= 30;
            } else if (piece == 'B') {
                score += 30;
            } else if (piece == 'r') {
                score -= 50;
            } else if (piece == 'R') {
                score += 50;
            } else if (piece == 'q') {
                score -= 90;
            } else if (piece == 'Q') {
                score += 90;
            }
        }
    }
    return score;
}

int evaluateMove(char board[8][8], int startX, int startY, int endX, int endY) {
    int score = 0;
    char piece = board[startX][startY];
    if (piece == 'P') {
        if (endX == 0) {
            score += 500 ;
        } else if (endX == 1) {
            score += 100;
        }
    } else if (piece == 'p') {
        if (endX == 7) {
            score -= 500;
        } else if (endX == 6) {
            score -= 100;
        }
    } else if (piece == 'n') {
        score -= 30;
    } else if (piece == 'N') {
        score += 30;
    } else if (piece == 'b') {
        score -= 30;
    } else if (piece == 'B') {
        score += 30;
    } else if (piece == 'r') {
        score -= 50;
    } else if (piece == 'R') {
        score += 50;
    } else if (piece == 'q') {
        score -= 90;
    } else if (piece == 'Q') {
        score += 90;
    }
    return score;
}

int miniMax(char board[8][8], int depth, int alpha, int beta, int maxPlayer) {
    int i, j, moveScore, currentScore;
    if (depth == 0) {
        return evaluateBoard(board);
    }
    if (maxPlayer == 1) {
        int maxVal = -1000;
        char tempBoard[8][8];
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (board[i][j] != ' ') {
                    if (board[i][j] > 90) {
                        int moves[8] = {1, 1, 1, 0, 0, -1, -1, -1};
                        int moveX, moveY;
                        for (int k = 0; k < 8; k++) {
                            moveX = i + moves[k];
                            moveY = j + moves[(k + 2) % 8];
                            if (moveX < 0 || moveX >= 8 || moveY < 0 || moveY >= 8)
                                continue;
                            if (board[moveX][moveY] == ' ' || board[moveX][moveY] <= 90) {
                                tempBoard[i][j] = ' ';
                                tempBoard[moveX][moveY] = board[i][j];
                                moveScore = miniMax(tempBoard, depth - 1, alpha, beta, 0);
                                if (moveScore > maxVal) {
                                    maxVal = moveScore;
                                }
                                alpha = alpha > moveScore ? alpha : moveScore;
                                if (beta <= alpha) {
                                    break;
                                }
                                tempBoard[i][j] = board[i][j];
                                tempBoard[moveX][moveY] = ' ';
                            }
                        }
                    }
                }
            }
        }
        return maxVal;
    } else {
        int minVal = 1000;
        char tempBoard[8][8];
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (board[i][j] != ' ') {
                    if (board[i][j] < 90) {
                        int moves[8] = {1, 1, 1, 0, 0, -1, -1, -1};
                        int moveX, moveY;
                        for (int k = 0; k < 8; k++) {
                            moveX = i + moves[k];
                            moveY = j + moves[(k + 2) % 8];
                            if (moveX < 0 || moveX >= 8 || moveY < 0 || moveY >= 8)
                                continue;
                            if (board[moveX][moveY] == ' ' || board[moveX][moveY] > 90) {
                                tempBoard[i][j] = ' ';
                                tempBoard[moveX][moveY] = board[i][j];
                                moveScore = miniMax(tempBoard, depth - 1, alpha, beta, 1);
                                if (moveScore < minVal) {
                                    minVal = moveScore;
                                }
                                beta = beta < moveScore ? beta : moveScore;
                                if (beta <= alpha) {
                                    break;
                                }
                                tempBoard[i][j] = board[i][j];
                                tempBoard[moveX][moveY] = ' ';
                            }
                        }
                    }
                }
            }
        }
        return minVal;
    }
}

int main() {
    char board[8][8] = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};
    int i, j, moveScore, bestMoveVal = -1000, bestMove[4];
    char tempBoard[8][8];
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (board[i][j] != ' ') {
                if (board[i][j] > 90) {
                    int moves[8] = {1, 1, 1, 0, 0, -1, -1, -1};
                    int moveX, moveY;
                    for (int k = 0; k < 8; k++) {
                        moveX = i + moves[k];
                        moveY = j + moves[(k + 2) % 8];
                        if (moveX < 0 || moveX >= 8 || moveY < 0 || moveY >= 8)
                            continue;
                        if (board[moveX][moveY] == ' ' || board[moveX][moveY] <= 90) {
                            tempBoard[i][j] = ' ';
                            tempBoard[moveX][moveY] = board[i][j];
                            moveScore = miniMax(tempBoard, 4, -1000, 1000, 0);
                            if (moveScore > bestMoveVal) {
                                bestMoveVal = moveScore;
                                bestMove[0] = i;
                                bestMove[1] = j;
                                bestMove[2] = moveX;
                                bestMove[3] = moveY;
                            }
                            tempBoard[i][j] = board[i][j];
                            tempBoard[moveX][moveY] = ' ';
                        }
                    }
                }
            }
        }
    }
    printf("Best Move: %c%d -> %c%d\n", bestMove[1] + 97, 8 - bestMove[0], bestMove[3] + 97, 8 - bestMove[2]);
    return 0;
}