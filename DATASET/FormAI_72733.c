//FormAI DATASET v1.0 Category: Chess engine ; Style: artistic
// A chess engine program that uses a unique approach in evaluating the best move

#include <stdio.h>
#include <stdlib.h>

#define WHITE 1
#define BLACK 0

#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

// This struct holds the information of each chess piece
typedef struct {
    int type;
    int color;
    int x; // x-coordinates
    int y; // y-coordinates
    int value; // value of the piece
} ChessPiece;

// This 2D array holds the current state of the chess board
ChessPiece chessBoard[8][8];

// This function initializes the chess board with pieces
void initializeChessBoard() {
    int i, j;

    // Place White Pieces
    for(i = 0; i < 8; ++i) {
        chessBoard[i][1] = (ChessPiece){PAWN, WHITE, i, 1, 1};
    }

    chessBoard[0][0] = (ChessPiece){ROOK, WHITE, 0, 0, 5};
    chessBoard[7][0] = (ChessPiece){ROOK, WHITE, 7, 0, 5};

    chessBoard[1][0] = (ChessPiece){KNIGHT, WHITE, 1, 0, 3};
    chessBoard[6][0] = (ChessPiece){KNIGHT, WHITE, 6, 0, 3};

    chessBoard[2][0] = (ChessPiece){BISHOP, WHITE, 2, 0, 3};
    chessBoard[5][0] = (ChessPiece){BISHOP, WHITE, 5, 0, 3};

    chessBoard[3][0] = (ChessPiece){QUEEN, WHITE, 3, 0, 9};
    chessBoard[4][0] = (ChessPiece){KING, WHITE, 4, 0, 100};

    // Place Black Pieces
    for(i = 0; i < 8; ++i) {
        chessBoard[i][6] = (ChessPiece){PAWN, BLACK, i, 6, 1};
    }

    chessBoard[0][7] = (ChessPiece){ROOK, BLACK, 0, 7, 5};
    chessBoard[7][7] = (ChessPiece){ROOK, BLACK, 7, 7, 5};

    chessBoard[1][7] = (ChessPiece){KNIGHT, BLACK, 1, 7, 3};
    chessBoard[6][7] = (ChessPiece){KNIGHT, BLACK, 6, 7, 3};

    chessBoard[2][7] = (ChessPiece){BISHOP, BLACK, 2, 7, 3};
    chessBoard[5][7] = (ChessPiece){BISHOP, BLACK, 5, 7, 3};

    chessBoard[3][7] = (ChessPiece){QUEEN, BLACK, 3, 7, 9};
    chessBoard[4][7] = (ChessPiece){KING, BLACK, 4, 7, 100};
}

// This function evaluates the best move for a given player
int evaluateBestMove(int player) {
    int maxVal = -100;
    int i, j, x, y;

    for(i = 0; i < 8; ++i) {
        for(j = 0; j < 8; ++j) {
            if(chessBoard[i][j].color == player) {
                for(x = 0; x < 8; ++x) {
                    for(y = 0; y < 8; ++y) {
                        if(canMove(chessBoard[i][j], x, y)) {
                            ChessPiece temp = chessBoard[x][y];
                            chessBoard[x][y] = chessBoard[i][j];
                            chessBoard[i][j] = (ChessPiece){0, 0, i, j, 0};

                            int val = evaluateBoard(player);
                            if(val > maxVal) {
                                maxVal = val;
                            }

                            chessBoard[i][j] = chessBoard[x][y];
                            chessBoard[x][y] = temp;
                        }
                    }
                }
            }
        }
    }
    return maxVal;
}

// This function evaluates the current status of the board for a given player
int evaluateBoard(int player) {
    int val = 0;
    int i, j;

    for(i = 0; i < 8; ++i) {
        for(j = 0; j < 8; ++j) {
            if(chessBoard[i][j].color == player) {
                val += chessBoard[i][j].value;
            }
        }
    }

    return val;
}

// This function checks if a piece can move to the given coordinates
int canMove(ChessPiece piece, int x, int y) {
    int dx = abs(piece.x - x);
    int dy = abs(piece.y - y);

    if(piece.type == PAWN) {
        return dx == 0 && dy == 1;
    } else if(piece.type == KNIGHT) {
        return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
    } else if(piece.type == BISHOP) {
        return dx == dy;
    } else if(piece.type == ROOK) {
        return dx == 0 || dy == 0;
    } else if(piece.type == QUEEN) {
        return dx == dy || dx == 0 || dy == 0;
    } else if(piece.type == KING) {
        return dx <= 1 && dy <= 1;
    }

    return 0;
}

int main() {
    initializeChessBoard();
    printf("White's best move has a value of %d\n", evaluateBestMove(WHITE));
    printf("Black's best move has a value of %d\n", evaluateBestMove(BLACK));

    return 0;
}