//FormAI DATASET v1.0 Category: Chess AI ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define BOARD_SIZE 8
#define MAX_DEPTH 3

int board[BOARD_SIZE][BOARD_SIZE] = {
    {-1,-2,-3,-4,-5,-3,-2,-1},
    {-6,-6,-6,-6,-6,-6,-6,-6},
    {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    {6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 },
    {1 ,2 ,3 ,4 ,5 ,3 ,2 ,1 },
};

typedef struct {
    int x;
    int y;
} Move;

typedef struct {
    int alpha;
    int beta;
    Move bestMove;
} BestMove;

void printBoard() {
    int i,j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}

int evaluatePosition() {
    int i,j;
    int score = 0;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            int piece = board[i][j];
            if(piece == 0) {
                continue;
            }
            if(piece < 0) {
                score += piece;
            } else {
                score -= piece;
            }
        }
    }
    return score;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int isPositionValid(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

int isPieceNull(int piece) {
    return piece == 0;
}

int isPieceMySide(int mySide, int piece) {
    return mySide * piece > 0;
}

int isPieceOpponentSide(int mySide, int piece) {
    return mySide * piece < 0;
}

void getValidMoves(Move validMoves[], int *size, int x, int y) {
    int piece = board[x][y];
    if(piece == 0) {
        *size = 0;
        return;
    }
    int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
    int i,j;
    *size = 0;
    for(i = 0; i < 8; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(isPositionValid(xx, yy) && 
           (isPieceNull(board[xx][yy]) || isPieceOpponentSide(piece, board[xx][yy]))) {
            validMoves[*size].x = xx;
            validMoves[*size].y = yy;
            (*size)++;
        }
    }
}

BestMove alphaBeta(int player, int depth, int alpha, int beta) {
    if(depth == MAX_DEPTH || evaluatePosition() == 0) {
        BestMove result = {evaluatePosition(), -1, -1};
        return result;
    }
    int i,j;
    int bestScore = player * -99;
    BestMove bestMove;
    int size = 0;
    Move moves[100];
    int opponent = player == 1 ? -1 : 1;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(isPieceMySide(player, board[i][j])) {
                getValidMoves(moves, &size, i, j);
                int k;
                for(k = 0; k < size; k++) {
                    int nextX = moves[k].x;
                    int nextY = moves[k].y;
                    int prevVal = board[nextX][nextY];
                    board[nextX][nextY] = board[i][j];
                    board[i][j] = 0;
                    BestMove result = alphaBeta(opponent, depth + 1, alpha, beta);
                    board[i][j] = board[nextX][nextY];
                    board[nextX][nextY] = prevVal;
                    int score = player * result.alpha;
                    if(score > bestScore) {
                        bestScore = score;
                        bestMove.bestMove.x = nextX;
                        bestMove.bestMove.y = nextY;
                    }
                    alpha = max(alpha, score);
                    if(alpha >= beta) {
                        break;
                    }
                }
            }
            if(alpha >= beta) {
                break;
            }
        }
    }
    bestMove.alpha = bestScore;
    bestMove.beta = alpha;
    return bestMove;
}

int main() {
    printBoard();
    BestMove result = alphaBeta(1, 0, -99, 99);
    printf("Best Move %d %d with score %d\n", result.bestMove.x, result.bestMove.y, result.alpha);
    return 0;
}