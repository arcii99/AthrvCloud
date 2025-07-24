//FormAI DATASET v1.0 Category: Chess AI ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board[8][8]; // the chess board
int scoreBoard[8][8] = { // the scoring system for each square on the board (higher value = more desirable)
    {5, 4, 3, 3, 3, 3, 4, 5},
    {4, 2, 2, 2, 2, 2, 2, 4},
    {3, 2, 1, 1, 1, 1, 2, 3},
    {3, 2, 1, 1, 1, 1, 2, 3},
    {3, 2, 1, 1, 1, 1, 2, 3},
    {3, 2, 1, 1, 1, 1, 2, 3},
    {4, 2, 2, 2, 2, 2, 2, 4},
    {5, 4, 3, 3, 3, 3, 4, 5}
};
bool isWhiteTurn = true; // keep track of whose turn it is

int getPieceValue(char piece) { // get the value of a chess piece
    if (piece == 'P') {
        return 1;
    } else if (piece == 'N') {
        return 3;
    } else if (piece == 'B') {
        return 3;
    } else if (piece == 'R') {
        return 5;
    } else if (piece == 'Q') {
        return 9;
    } else if (piece == 'K') {
        return 10;
    } else {
        return 0;
    }
}

bool isPieceWhite(char piece) { // check if a chess piece is white or black
    return piece >= 'A' && piece <= 'Z';
}

bool isValid(int x, int y) { // check if coordinates are within the board
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

bool canMovePiece(int fromX, int fromY, int toX, int toY) { // check if a piece can be moved from one square to another
    char piece = board[fromX][fromY];
    if (piece == 'P') { // pawn rules
        if (fromY == toY) { // moving forwards
            if (isWhiteTurn && toX == fromX+1 && board[toX][toY] == ' ') { // white pawn can move one square up if unoccupied
                return true;
            } else if (!isWhiteTurn && toX == fromX-1 && board[toX][toY] == ' ') { // black pawn can move one square down if unoccupied
                return true; 
            }
            return false;
        } else { // capturing a piece diagonally
            if (abs(fromY-toY) != 1) { // can only move one square diagonally
                return false;
            }
            if (isWhiteTurn && toX == fromX+1 && isPieceWhite(board[toX][toY])) { // can capture a black piece diagonally up right
                return true;
            } else if (!isWhiteTurn && toX == fromX-1 && !isPieceWhite(board[toX][toY])) { // can capture a white piece diagonally down left
                return true; 
            }
            return false;
        }
    } else { // all other piece rules
        int dx = abs(fromX-toX);
        int dy = abs(fromY-toY);
        int x, y;
        if (piece == 'N') { // knight rules
            if (dx == 2 && dy == 1 || dx == 1 && dy == 2) { // shaped like L
                return true;
            }
            return false;
        } else if (piece == 'B') { // bishop rules
            if (dx != dy) { // diagonals only
                return false;
            }
            x = toX > fromX ? fromX+1 : fromX-1;
            y = toY > fromY ? fromY+1 : fromY-1;
            while (x != toX) { // check if there are any pieces blocking the diagonal path
                if (board[x][y] != ' ') {
                    return false;
                }
                x += toX > fromX ? 1 : -1;
                y += toY > fromY ? 1 : -1;
            }
            if (board[toX][toY] != ' ' && isPieceWhite(piece) == isPieceWhite(board[toX][toY])) { // pieces cannot capture their own color
                return false;
            }
            return true;
        } else if (piece == 'R') { // rook rules
            if (dx != 0 && dy != 0) { // horizontal or vertical only
                return false;
            }
            x = dx > 0 ? fromX+1 : fromX-1;
            y = dy > 0 ? fromY+1 : fromY-1;
            while (x != toX || y != toY) { // check if there are any pieces blocking the horizontal/vertical path
                if (board[x][y] != ' ') {
                    return false;
                }
                if (dx == 0) {
                    y += toY > fromY ? 1 : -1;
                } else {
                    x += toX > fromX ? 1 : -1;
                }
            }
            if (board[toX][toY] != ' ' && isPieceWhite(piece) == isPieceWhite(board[toX][toY])) { 
                return false;
            }
            return true;
        } else if (piece == 'Q') { // queen rules
            if (dx == dy) { // bishop movement
                x = toX > fromX ? fromX+1 : fromX-1;
                y = toY > fromY ? fromY+1 : fromY-1;
                while (x != toX) {
                    if (board[x][y] != ' ') {
                        return false;
                    }
                    x += toX > fromX ? 1 : -1;
                    y += toY > fromY ? 1 : -1;
                }
            } else if (dx == 0 || dy == 0) { // rook movement
                x = dx > 0 ? fromX+1 : fromX-1;
                y = dy > 0 ? fromY+1 : fromY-1;
                while (x != toX || y != toY) {
                    if (board[x][y] != ' ') {
                        return false;
                    }
                    if (dx == 0) {
                        y += toY > fromY ? 1 : -1;
                    } else {
                        x += toX > fromX ? 1 : -1;
                    }
                }
            } else { // not diagonal or horizontal/vertical
                return false;
            }
            if (board[toX][toY] != ' ' && isPieceWhite(piece) == isPieceWhite(board[toX][toY])) { 
                return false;
            }
            return true;
        } else { // king rules
            if (dx > 1 || dy > 1 || (dx+y == 0)) { // can only move one square in any direction, or capture one square diagonally
                return false;
            }
            if (board[toX][toY] != ' ' && isPieceWhite(piece) == isPieceWhite(board[toX][toY])) { 
                return false;
            }
            return true;
        }
    }
}

char getPromotionPiece() { // get the piece the pawn will promote to
    printf("Enter the piece you would like to promote your pawn to (Q, R, B, or N): ");
    char piece = getchar();
    while (piece != 'Q' && piece != 'R' && piece != 'B' && piece != 'N') { // keep asking for input until valid
        printf("Invalid input. Please enter Q, R, B, or N: ");
        piece = getchar();
    }
    return piece;
}

void promotePawn(int x, int y) { // promote a pawn to a different piece when it reaches the other side of the board
    char piece = getPromotionPiece();
    board[x][y] = piece;
}

void movePiece(int fromX, int fromY, int toX, int toY) { // move a piece from one square to another
    board[toX][toY] = board[fromX][fromY];
    board[fromX][fromY] = ' ';
    if (board[toX][toY] == 'P' && (toX == 0 || toX == 7)) { // promote pawn if it reaches the other side of the board
        promotePawn(toX, toY);
    }
    isWhiteTurn = !isWhiteTurn; // switch turns
}

void printBoard() { // print the current state of the board
    printf("   A  B  C  D  E  F  G  H\n");
    for (int x = 0; x < 8; x++) {
        printf("%d ", x+1);
        for (int y = 0; y < 8; y++) {
            printf("|%c ", board[x][y]);
        }
        printf("|\n");
    }
}

int getPieceScore(int x, int y) { // get the score of a chess piece based on its current position on the board
    char piece = board[x][y];
    int value = getPieceValue(piece) * (isPieceWhite(piece) ? 1 : -1);
    int score = scoreBoard[x][y] * value;
    if ((piece == 'P' && isPieceWhite(piece) && x == 1) || (piece == 'P' && !isPieceWhite(piece) && x == 6)) { // pawns have an extra value if they are close to promoting
        score += 3 * value;
    }
    return score;
}

int getBoardScore() { // get the total score of the board for the current player
    int score = 0;
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (board[x][y] != ' ') {
                score += getPieceScore(x, y);
            }
        }
    }
    return score;
}

void makeBestMove() { // calculate the best move based on the current board state
    int bestScore = isWhiteTurn ? -100000 : 100000; // initialize best score to highest/lowest possible value
    int bestFromX, bestFromY, bestToX, bestToY;
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (board[x][y] != ' ' && isPieceWhite(board[x][y]) == isWhiteTurn) { // only consider pieces of the current player
                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8; j++) {
                        if (canMovePiece(x, y, i, j)) { // check if the piece can move to that square
                            char temp = board[i][j]; // temporarily move the piece to that square to see how it affects the board score
                            movePiece(x, y, i, j);
                            int score = getBoardScore();
                            if ((isWhiteTurn && score > bestScore) || (!isWhiteTurn && score < bestScore)) { // update best score and move if necessary
                                bestScore = score;
                                bestFromX = x;
                                bestFromY = y;
                                bestToX = i;
                                bestToY = j;
                            }
                            movePiece(i, j, x, y); // move the piece back to evaluate other moves
                            board[i][j] = temp;
                        }
                    }
                }
            }
        }
    }
    movePiece(bestFromX, bestFromY, bestToX, bestToY); // make the best move
    printf("\n%s moved %c%d to %c%d\n", isWhiteTurn ? "White" : "Black", bestFromY+'A', bestFromX+1, bestToY+'A', bestToX+1);
}

int main() {
    // initialize a standard chess board
    board[0][0] = 'R';
    board[0][1] = 'N';
    board[0][2] = 'B';
    board[0][3] = 'Q';
    board[0][4] = 'K';
    board[0][5] = 'B';
    board[0][6] = 'N';
    board[0][7] = 'R';
    for (int i = 0; i < 8; i++) {
        board[1][i] = 'P';
        board[6][i] = 'p';
    }
    board[7][0] = 'r';
    board[7][1] = 'n';
    board[7][2] = 'b';
    board[7][3] = 'q';
    board[7][4] = 'k';
    board[7][5] = 'b';
    board[7][6] = 'n';
    board[7][7] = 'r';
    // play the game
    printBoard();
    while (true) { // game loop
        makeBestMove();
        printBoard();
    }
    return 0;
}