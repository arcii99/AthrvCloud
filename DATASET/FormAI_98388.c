//FormAI DATASET v1.0 Category: Chess AI ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

int getPieceValue(char piece){
    //return the value of each piece according to chess rules
    switch(piece) {
        case 'Q':
            return 9;
        case 'R':
            return 5;
        case 'B':
        case 'N':
            return 3;
        case 'P':
            return 1;
        default:
            return 0;
    }
}

int evaluateBoard(char board[8][8]) {
    int score = 0;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            //evaluate each piece on the board
            char piece = board[i][j];
            if (piece == ' ') {
                continue; //skip blanks
            }
            int pieceValue = getPieceValue(piece);
            if (pieceValue == 0) {
                continue; //skip kings
            }
            if (piece == 'P') {
                //give bonus for pawns on center of the board
                if (i == 3 || i == 4) {
                    score += 1;
                }
            }
            if (islower(piece)) {
                pieceValue = -pieceValue; //invert score for opponents pieces
            }
            score += pieceValue;
        }
    }
    return score;
}

int alphaBeta(char board[8][8], int depth, int alpha, int beta, int maximizingPlayer) {
    if (depth == 0) {
        return evaluateBoard(board);
    }
    if (maximizingPlayer) {
        int maxValue = INT_MIN;
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                //look for available moves
                char piece = board[i][j];
                if (piece == ' ') {
                    continue;
                }
                if (islower(piece)) {
                    continue; //skip opponents pieces
                }
                //make a copy of the board to test the move
                char newBoard[8][8];
                for(int ii=0; ii<8; ii++) {
                    for(int jj=0; jj<8; jj++) {
                        newBoard[ii][jj] = board[ii][jj];
                    }
                }
                //simulate a move and evaluate the resulting board
                for(int ii=0; ii<8; ii++) {
                    for(int jj=0; jj<8; jj++) {
                        if (newBoard[ii][jj] == piece) {
                            newBoard[ii][jj] = ' ';
                            newBoard[i][j] = piece;
                            int value = alphaBeta(newBoard, depth-1, alpha, beta, 0);
                            maxValue = fmax(maxValue, value);
                            alpha = fmax(alpha, value);
                            if (beta <= alpha) {
                                return maxValue;
                            }
                        }
                    }
                }
            }
        }
        return maxValue;
    }
    else {
        int minValue = INT_MAX;
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                char piece = board[i][j];
                if (piece == ' ') {
                    continue;
                }
                if (isupper(piece)) {
                    continue;
                }
                char newBoard[8][8];
                for(int ii=0; ii<8; ii++) {
                    for(int jj=0; jj<8; jj++) {
                        newBoard[ii][jj] = board[ii][jj];
                    }
                }
                for(int ii=0; ii<8; ii++) {
                    for(int jj=0; jj<8; jj++) {
                        if (newBoard[ii][jj] == piece) {
                            newBoard[ii][jj] = ' ';
                            newBoard[i][j] = piece;
                            int value = alphaBeta(newBoard, depth-1, alpha, beta, 1);
                            minValue = fmin(minValue, value);
                            beta = fmin(beta, value);
                            if (beta <= alpha) {
                                return minValue;
                            }
                        }
                    }
                }
            }
        }
        return minValue;
    }
}

void aiMove(char board[8][8], int depth) {
    int maxValue = INT_MIN;
    int maxI = -1;
    int maxJ = -1;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            char piece = board[i][j];
            if (piece == ' ') {
                continue;
            }
            if (islower(piece)) {
                continue;
            }
            char newBoard[8][8];
            for(int ii=0; ii<8; ii++) {
                for(int jj=0; jj<8; jj++) {
                    newBoard[ii][jj] = board[ii][jj];
                }
            }
            for(int ii=0; ii<8; ii++) {
                for(int jj=0; jj<8; jj++) {
                    if (newBoard[ii][jj] == piece) {
                        newBoard[ii][jj] = ' ';
                        newBoard[i][j] = piece;
                        int value = alphaBeta(newBoard, depth-1, INT_MIN, INT_MAX, 0);
                        if (value > maxValue) {
                            maxValue = value;
                            maxI = i;
                            maxJ = j;
                        }
                    }
                }
            }
        }
    }
    printf("AI moves from %c%d to %c%d\n", 
        (char)maxJ+'A', 8-maxI, (char)maxJ+'A', 8-maxI-1);
    char temp = board[maxI][maxJ];
    board[maxI][maxJ] = ' ';
    board[maxI-1][maxJ] = temp;
}

int main() {
    char board[8][8] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };
    printf("Initial position:\n");
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    aiMove(board, 3);
    printf("Position after AI move:\n");
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}