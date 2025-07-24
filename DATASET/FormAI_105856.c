//FormAI DATASET v1.0 Category: Chess AI ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 8
#define MAX_DEPTH 4
#define MAX_SCORE 1000

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int x;
    int y;
    int value;
} Move;

int board[BOARD_SIZE][BOARD_SIZE] = {
    {-1, -1, -1, -1, -1, -1, -1, -1},
    {-1,  0,  0,  0,  0,  0,  0, -1},
    {-1,  0,  0,  0,  0,  0,  0, -1},
    {-1,  0,  0,  0,  0,  0,  0, -1},
    {-1,  0,  0,  0,  0,  0,  0, -1},
    {-1,  0,  0,  0,  0,  0,  0, -1},
    {-1,  0,  0,  0,  0,  0,  0, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1}
};

const int pieceValues[7] = {0, 1, 3, 3, 5, 9, 100};

const Point directions[8] = {
    {1, 0}, {1, 1}, {0, 1}, {-1, 1},
    {-1, 0}, {-1, -1}, {0, -1}, {1, -1}
};

bool isInBounds(Point point) {
    return point.x >= 0 && point.x < BOARD_SIZE && point.y >= 0 && point.y < BOARD_SIZE;
}

int getPieceValue(int piece) {
    if (piece == 0) {
        return 0;
    }
    
    int value = pieceValues[abs(piece)];
    
    if (piece < 0) {
        value *= -1;
    }
    
    return value;
}

int evaluateBoard() {
    int totalValue = 0;
    
    for (int x = 0; x < BOARD_SIZE; x++) {
        for (int y = 0; y < BOARD_SIZE; y++) {
            totalValue += getPieceValue(board[x][y]);
        }
    }
    
    return totalValue;
}

Move getBestMove(int depth, int alpha, int beta) {
    Move bestMove = {0, 0, 0};
    int bestScore;
    
    if (depth == 0) {
        bestMove.value = evaluateBoard();
        return bestMove;
    }
    
    if (depth % 2 == 0) {
        bestScore = -MAX_SCORE;
        
        for (int x = 0; x < BOARD_SIZE; x++) {
            for (int y = 0; y < BOARD_SIZE; y++) {
                if (board[x][y] <= 0) {
                    continue;
                }
                
                for (int i = 0; i < 8; i++) {
                    Point point = {x + directions[i].x, y + directions[i].y};
                    
                    if (!isInBounds(point)) {
                        continue;
                    }
                    
                    if (board[point.x][point.y] >= 0) {
                        continue;
                    }
                    
                    int tempPiece = board[x][y];
                    board[x][y] = 0;
                    int tempCapture = board[point.x][point.y];
                    board[point.x][point.y] = tempPiece;
                    
                    int score = getBestMove(depth - 1, alpha, beta).value;
                    
                    if (score > alpha) {
                        alpha = score;
                        bestMove.x = x;
                        bestMove.y = y;
                        bestMove.value = score;
                    }
                    
                    board[x][y] = tempPiece;
                    board[point.x][point.y] = tempCapture;
                    
                    if (alpha >= beta) {
                        return bestMove;
                    }
                }
            }
        }
    } else {
        bestScore = MAX_SCORE;
        
        for (int x = 0; x < BOARD_SIZE; x++) {
            for (int y = 0; y < BOARD_SIZE; y++) {
                if (board[x][y] >= 0) {
                    continue;
                }
                
                for (int i = 0; i < 8; i++) {
                    Point point = {x + directions[i].x, y + directions[i].y};
                    
                    if (!isInBounds(point)) {
                        continue;
                    }
                    
                    if (board[point.x][point.y] <= 0) {
                        continue;
                    }
                    
                    int tempPiece = board[x][y];
                    board[x][y] = 0;
                    int tempCapture = board[point.x][point.y];
                    board[point.x][point.y] = tempPiece;
                    
                    int score = getBestMove(depth - 1, alpha, beta).value;
                    
                    if (score < beta) {
                        beta = score;
                        bestMove.x = x;
                        bestMove.y = y;
                        bestMove.value = score;
                    }
                    
                    board[x][y] = tempPiece;
                    board[point.x][point.y] = tempCapture;
                    
                    if (alpha >= beta) {
                        return bestMove;
                    }
                }
            }
        }
    }
    
    return bestMove;
}

void printBoard() {
    printf("\n");
    
    for (int y = BOARD_SIZE - 1; y >= 0; y--) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            int piece = board[x][y];
            
            if (piece >= 0) {
                printf(" ");
            }
            
            printf("%d ", piece);
        }
        
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int depth = 4;
    
    while (true) {
        printBoard();
        
        if (evaluateBoard() >= MAX_SCORE) {
            printf("You win!\n");
            return 0;
        }
        
        Move move = getBestMove(depth, -MAX_SCORE, MAX_SCORE);
        
        printf("AI move: (%d, %d) to (%d, %d) with value %d\n", move.x, move.y, move.x + 1, move.y + 1, move.value);
        board[move.x][move.y] = 0;
        board[move.x + 1][move.y + 1] = 1;
        
        printBoard();
        
        if (evaluateBoard() <= -MAX_SCORE) {
            printf("AI wins!\n");
            return 0;
        }
        
        int x, y;
        printf("Enter move x: ");
        scanf("%d", &x);
        printf("Enter move y: ");
        scanf("%d", &y);
        
        board[x - 1][y - 1] = -1;
        board[x][y] = 1;
    }
    
    return 0;
}