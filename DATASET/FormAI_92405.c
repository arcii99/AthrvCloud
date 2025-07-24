//FormAI DATASET v1.0 Category: Chess AI ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8
#define MAX_DEPTH 3

// define pieces
#define EMPTY 0
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

// define colors
#define WHITE 0
#define BLACK 1

// define directions
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define UPRIGHT 4
#define UPLEFT 5
#define DOWNLEFT 6
#define DOWNRIGHT 7

int board[BOARD_SIZE][BOARD_SIZE] = {
    {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK},
    {PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
    {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK}
};

int playerTurn = WHITE;

int score[7] = {0, 1, 3, 3, 5, 9, 1000};

/**
 * Returns the piece at the specified row and column.
 *
 * @param row the row of the piece
 * @param col the column of the piece
 * @return the piece at the specified row and column
 */
int getPiece(int row, int col) {
    return board[row][col];
}

/**
 * Returns the color of the piece at the specified row and column.
 *
 * @param row the row of the piece
 * @param col the column of the piece
 * @return the color of the piece at the specified row and column
 */
int getColor(int row, int col) {
    int piece = getPiece(row, col);
    if (piece == EMPTY) {
        return -1;
    }
    return piece < KING ? WHITE : BLACK;
}

/**
 * Updates the board with the specified move.
 *
 * @param oldRow the current row of the piece
 * @param oldCol the current column of the piece
 * @param newRow the new row for the piece
 * @param newCol the new column for the piece
 * @param piece the piece that is being moved
 */
void makeMove(int oldRow, int oldCol, int newRow, int newCol, int piece) {
    board[oldRow][oldCol] = EMPTY;
    board[newRow][newCol] = piece;
}

/**
 * Returns true if the specified row and column are valid positions on the board.
 *
 * @param row the row being checked
 * @param col the column being checked
 * @return true if the specified row and column are valid positions; otherwise, false
 */
bool isValidPosition(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
}

/**
 * Returns true if the piece at the specified row and column can move to the specified position.
 *
 * @param oldRow the current row of the piece
 * @param oldCol the current column of the piece
 * @param newRow the possible row for the piece
 * @param newCol the possible column for the piece
 * @param piece the piece that is being moved
 * @param color the color of the piece
 * @return true if the piece can move to the specified position; otherwise, false
 */
bool canMove(int oldRow, int oldCol, int newRow, int newCol, int piece, int color) {
    if (!isValidPosition(newRow, newCol)) {
        return false;
    }
    if (getColor(newRow, newCol) == color) {
        return false;
    }
    switch (piece) {
        case PAWN:
            // can move 1 or 2 spaces forward on first move
            if (oldCol == newCol) {
                if (color == WHITE && newRow == oldRow - 1) {
                    return true;
                } else if (color == WHITE && newRow == oldRow - 2 && oldRow == 6) {
                    return true;
                } else if (color == BLACK && newRow == oldRow + 1) {
                    return true;
                } else if (color == BLACK && newRow == oldRow + 2 && oldRow == 1) {
                    return true;
                }
            }
            // can move diagonally to take a piece
            if (abs(newCol - oldCol) == 1 && abs(newRow - oldRow) == 1) {
                if (color == WHITE && newRow == oldRow - 1 && getColor(newRow, newCol) == BLACK) {
                    return true;
                } else if (color == BLACK && newRow == oldRow + 1 && getColor(newRow, newCol) == WHITE) {
                    return true;
                }
            }
            return false;
        case KNIGHT:
            // can move in L-shapes (2 spaces vertically, 1 space horizontally or vice versa)
            return (abs(newRow - oldRow) == 2 && abs(newCol - oldCol) == 1) ||
                   (abs(newRow - oldRow) == 1 && abs(newCol - oldCol) == 2);
        case BISHOP:
            // can move diagonally any number of spaces
            if (abs(newRow - oldRow) == abs(newCol - oldCol)) {
                int rowDir = newRow > oldRow ? 1 : -1;
                int colDir = newCol > oldCol ? 1 : -1;
                int r = oldRow + rowDir;
                int c = oldCol + colDir;
                while (isValidPosition(r, c) && r != newRow && c != newCol) {
                    if (getPiece(r, c) != EMPTY) {
                        return false;
                    }
                    r += rowDir;
                    c += colDir;
                }
                return true;
            }
            return false;
        case ROOK:
            // can move vertically or horizontally any number of spaces
            if (oldRow == newRow) {
                int dir = newCol > oldCol ? 1 : -1;
                int col = oldCol + dir;
                while (col != newCol) {
                    if (getPiece(oldRow, col) != EMPTY) {
                        return false;
                    }
                    col += dir;
                }
                return true;
            } else if (oldCol == newCol) {
                int dir = newRow > oldRow ? 1 : -1;
                int row = oldRow + dir;
                while (row != newRow) {
                    if (getPiece(row, oldCol) != EMPTY) {
                        return false;
                    }
                    row += dir;
                }
                return true;
            }
            return false;
        case QUEEN:
            // can move vertically, horizontally, or diagonally any number of spaces
            if (abs(newRow - oldRow) == abs(newCol - oldCol)) {
                return canMove(oldRow, oldCol, newRow, newCol, BISHOP, color);
            } else if (oldRow == newRow || oldCol == newCol) {
                return canMove(oldRow, oldCol, newRow, newCol, ROOK, color);
            }
            return false;
        case KING:
            // can move one space in any direction
            return abs(newRow - oldRow) <= 1 && abs(newCol - oldCol) <= 1;
        default:
            return false;
    }
}

/**
 * Returns the score of the board for the specified color.
 *
 * @param color the color of the player
 * @return the score of the board for the specified color
 */
int evaluate(int color) {
    int totalScore = 0;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            int piece = getPiece(row, col);
            int pieceColor = getColor(row, col);
            if (piece != EMPTY) {
                int pieceScore = score[piece];
                if (pieceColor == color) {
                    totalScore += pieceScore;
                } else {
                    totalScore -= pieceScore;
                }
            }
        }
    }
    return totalScore;
}

/**
 * The recursive function for the minimax algorithm.
 *
 * @param depth the current depth of the algorithm
 * @param alpha the current alpha value
 * @param beta the current beta value
 * @param color the color of the player
 * @return the score of the best move
 */
int minimax(int depth, int alpha, int beta, int color) {
    if (depth == 0) {
        return evaluate(color);
    }
    int bestMoveScore = color == playerTurn ? -999 : 999;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            int piece = getPiece(row, col);
            int pieceColor = getColor(row, col);
            if (piece != EMPTY && pieceColor == color) {
                for (int dir = 0; dir < 8; dir++) {
                    int newRow = row;
                    int newCol = col;
                    switch (dir) {
                        case UP:
                            newRow--;
                            break;
                        case DOWN:
                            newRow++;
                            break;
                        case LEFT:
                            newCol--;
                            break;
                        case RIGHT:
                            newCol++;
                            break;
                        case UPRIGHT:
                            newRow--;
                            newCol++;
                            break;
                        case UPLEFT:
                            newRow--;
                            newCol--;
                            break;
                        case DOWNLEFT:
                            newRow++;
                            newCol--;
                            break;
                        case DOWNRIGHT:
                            newRow++;
                            newCol++;
                            break;
                    }
                    if (canMove(row, col, newRow, newCol, piece, color)) {
                        int temp = getPiece(newRow, newCol);
                        makeMove(row, col, newRow, newCol, piece);
                        int moveScore = minimax(depth - 1, alpha, beta, 1 - color);
                        if (color == playerTurn) {
                            if (moveScore > bestMoveScore) {
                                bestMoveScore = moveScore;
                            }
                            alpha = alpha > bestMoveScore ? alpha : bestMoveScore;
                        } else {
                            if (moveScore < bestMoveScore) {
                                bestMoveScore = moveScore;
                            }
                            beta = beta < bestMoveScore ? beta : bestMoveScore;
                        }
                        makeMove(newRow, newCol, row, col, piece);
                        board[newRow][newCol] = temp;
                        if (beta <= alpha) {
                            return bestMoveScore;
                        }
                    }
                }
            }
        }
    }
    return bestMoveScore;
}

/**
 * Makes a move for the AI
 */
void makeAIMove() {
    int bestMoveScore = -999;
    int currentScore = evaluate(playerTurn);
    int bestRow = -1;
    int bestCol = -1;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            int piece = getPiece(row, col);
            int pieceColor = getColor(row, col);
            if (piece != EMPTY && pieceColor == playerTurn) {
                for (int dir = 0; dir < 8; dir++) {
                    int newRow = row;
                    int newCol = col;
                    switch (dir) {
                        case UP:
                            newRow--;
                            break;
                        case DOWN:
                            newRow++;
                            break;
                        case LEFT:
                            newCol--;
                            break;
                        case RIGHT:
                            newCol++;
                            break;
                        case UPRIGHT:
                            newRow--;
                            newCol++;
                            break;
                        case UPLEFT:
                            newRow--;
                            newCol--;
                            break;
                        case DOWNLEFT:
                            newRow++;
                            newCol--;
                            break;
                        case DOWNRIGHT:
                            newRow++;
                            newCol++;
                            break;
                    }
                    if (canMove(row, col, newRow, newCol, piece, playerTurn)) {
                        int temp = getPiece(newRow, newCol);
                        makeMove(row, col, newRow, newCol, piece);
                        int moveScore = minimax(MAX_DEPTH, -999, 999, 1 - playerTurn);
                        makeMove(newRow, newCol, row, col, piece);
                        board[newRow][newCol] = temp;
                        if (moveScore > bestMoveScore || (moveScore == bestMoveScore && rand() % 2 == 0)) {
                            bestMoveScore = moveScore;
                            bestRow = row;
                            bestCol = col;
                        }
                    }
                }
            }
        }
    }
    if (bestRow != -1 && bestCol != -1) {
        int newRow, newCol;
        do {
            newRow = bestRow + (rand() % 3) - 1;
            newCol = bestCol + (rand() % 3) - 1;
        } while (!isValidPosition(newRow, newCol) || !canMove(bestRow, bestCol, newRow, newCol,
                                                            getPiece(bestRow, bestCol), playerTurn));
        makeMove(bestRow, bestCol, newRow, newCol, getPiece(bestRow, bestCol));
        printf("AI moved from (%d,%d) to (%d,%d)\n", bestRow, bestCol, newRow, newCol);
        playerTurn = 1 - playerTurn;
    } else {
        printf("AI could not find valid move; skipping turn.\n");
    }
}

int main() {
    int gameOver = 0;
    while (!gameOver) {
        makeAIMove();
        // TODO: Implement player turn
    }
    return 0;
}