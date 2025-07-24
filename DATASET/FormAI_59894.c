//FormAI DATASET v1.0 Category: Chess AI ; Style: funny
#include<stdio.h>

#define BOARD_SIZE 8
#define DEPTH 3

void makeAMove(int *board) {
    // Randomly select a piece and move it one square in a random direction
    int pieceIdx = rand() % BOARD_SIZE;
    int dir = rand() % 8;
    int pieceRow = pieceIdx / BOARD_SIZE;
    int pieceCol = pieceIdx % BOARD_SIZE;

    switch(dir) {
        case 0:
            if(pieceRow > 0) {
                board[pieceIdx] = 0;
                board[pieceIdx - BOARD_SIZE] = 1;
            }
            break;
        
        case 1:
            if(pieceRow > 0 && pieceCol < BOARD_SIZE - 1) {
                board[pieceIdx] = 0;
                board[pieceIdx - BOARD_SIZE + 1] = 1;
           }
           break;
           
        case 2:
            if(pieceCol < BOARD_SIZE - 1) {
                board[pieceIdx] = 0;
                board[pieceIdx + 1] = 1;
            }
            break;
        
        case 3:
            if(pieceRow < BOARD_SIZE - 1 && pieceCol < BOARD_SIZE - 1) {
                board[pieceIdx] = 0;
                board[pieceIdx + BOARD_SIZE + 1] = 1;
            }
            break;
            
        case 4:
            if(pieceRow < BOARD_SIZE - 1) {
                board[pieceIdx] = 0;
                board[pieceIdx + BOARD_SIZE] = 1;
            }
            break;
        
        case 5:
            if(pieceRow < BOARD_SIZE - 1 && pieceCol > 0) {
                board[pieceIdx] = 0;
                board[pieceIdx + BOARD_SIZE - 1] = 1;
            }
            break;
        
        case 6:
            if(pieceCol > 0) {
                board[pieceIdx] = 0;
                board[pieceIdx - 1] = 1;
            }
            break;
            
        case 7:
            if(pieceRow > 0 && pieceCol > 0) {
                board[pieceIdx] = 0;
                board[pieceIdx - BOARD_SIZE - 1] = 1;
            }
            break;
    }
}

void printBoard(int *board) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i*BOARD_SIZE + j]);
        }
        printf("\n");
    }
}

int evaluateBoard(int *board) {
    // Count number of pieces on the board
    int count = 0;
    for(int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++) {
        if(board[i] == 1) {
            count++;
        }
    }
    return count;
}

int minimax(int *board, int depth, int alpha, int beta, int maximizingPlayer) {
    if(depth == 0) {
        return evaluateBoard(board);
    }

    if(maximizingPlayer) {
        int maxEval = -1000000000;
        for(int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++) {
            if(board[i] == 1) {
                int tmpBoard[BOARD_SIZE*BOARD_SIZE];
                for(int j = 0; j < BOARD_SIZE*BOARD_SIZE; j++) {
                    tmpBoard[j] = board[j];
                }
                int tmpIdx = i + BOARD_SIZE;
                if(tmpIdx < BOARD_SIZE*BOARD_SIZE && board[tmpIdx] == 0) {
                    tmpBoard[i] = 0;
                    tmpBoard[tmpIdx] = 1;
                }
                int eval = minimax(tmpBoard, depth-1, alpha, beta, 0);
                if(eval > maxEval) {
                    maxEval = eval;
                }
                if(maxEval >= beta) {
                    return maxEval;
                }
                if(maxEval > alpha) {
                    alpha = maxEval;
                }
            }
        }
        return maxEval;
    }
    else {
        int minEval = 1000000000;
        for(int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++) {
            if(board[i] == 1) {
                int tmpBoard[BOARD_SIZE*BOARD_SIZE];
                for(int j = 0; j < BOARD_SIZE*BOARD_SIZE; j++) {
                    tmpBoard[j] = board[j];
                }
                int tmpIdx = i - BOARD_SIZE;
                if(tmpIdx > 0 && board[tmpIdx] == 0) {
                    tmpBoard[i] = 0;
                    tmpBoard[tmpIdx] = 1;
                }
                int eval = minimax(tmpBoard, depth-1, alpha, beta, 1);
                if(eval < minEval) {
                    minEval = eval;
                }
                if(minEval <= alpha) {
                    return minEval;
                }
                if(minEval < beta) {
                    beta = minEval;
                }
            }
        }
        return minEval;
    }
}

int findBestMove(int *board) {
    int bestMoveIdx = -1;
    int maxEval = -1000000000;
    for(int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++) {
        if(board[i] == 1) {
            int tmpBoard[BOARD_SIZE*BOARD_SIZE];
            for(int j = 0; j < BOARD_SIZE*BOARD_SIZE; j++) {
                tmpBoard[j] = board[j];
            }
            int tmpIdx = i + BOARD_SIZE;
            if(tmpIdx < BOARD_SIZE*BOARD_SIZE && board[tmpIdx] == 0) {
                tmpBoard[i] = 0;
                tmpBoard[tmpIdx] = 1;
            }
            int eval = minimax(tmpBoard, DEPTH-1, -1000000000, 1000000000, 0);
            if(eval > maxEval) {
                maxEval = eval;
                bestMoveIdx = i;
            }
        }
    }
    return bestMoveIdx;
}

int main() {
    int board[BOARD_SIZE*BOARD_SIZE] = {0};
    board[3*BOARD_SIZE+4] = 1;
    printBoard(board);
    while(1) {
        makeAMove(board);
        makeAMove(board);
        int bestMoveIdx = findBestMove(board);
        board[bestMoveIdx + BOARD_SIZE] = 1;
        printBoard(board);
    }
    return 0;
}