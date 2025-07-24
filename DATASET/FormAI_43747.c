//FormAI DATASET v1.0 Category: Chess AI ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WHITE 1
#define BLACK -1
#define BOARD_SIZE 8

// define chess board structure
struct chessBoard {
    int board[BOARD_SIZE][BOARD_SIZE];
    int currentPlayer;
};

// define function to initialize the chess board
void initializeBoard(struct chessBoard* board) {
    // set up white pieces
    board->board[0][0] = board->board[0][7] = 2;
    board->board[0][1] = board->board[0][6] = 3;
    board->board[0][2] = board->board[0][5] = 4;
    board->board[0][3] = 5;
    board->board[0][4] = 6;
    for (int i=0; i<BOARD_SIZE; i++) {
        board->board[1][i] = 1;
    }
    // set up black pieces
    board->board[7][0] = board->board[7][7] = -2;
    board->board[7][1] = board->board[7][6] = -3;
    board->board[7][2] = board->board[7][5] = -4;
    board->board[7][3] = -5;
    board->board[7][4] = -6;
    for (int i=0; i<BOARD_SIZE; i++) {
        board->board[6][i] = -1;
    }
    board->currentPlayer = WHITE;
}

// define function to print the chess board
void printBoard(struct chessBoard board) {
    printf("\n   | A | B | C | D | E | F | G | H |\n");
    printf("-----------------------------------\n");
    for (int row=0; row<BOARD_SIZE; row++) {
        printf(" %d |", row+1);
        for (int col=0; col<BOARD_SIZE; col++) {
            int piece = board.board[row][col];
            if (piece == 0) {
                printf("   |");
            } else {
                printf(" %d |", piece);
            }
        }
        printf(" %d\n", row+1);
        printf("-----------------------------------\n");
    }
    printf("   | A | B | C | D | E | F | G | H |\n\n");
}

// define function to check if a given move is valid
int isValidMove(struct chessBoard board, int startRow, int startCol, int endRow, int endCol) {
    // check if start and end positions are on the board:
    if (startRow < 0 || startRow >= BOARD_SIZE || startCol < 0 || startCol >= BOARD_SIZE
            || endRow < 0 || endRow >= BOARD_SIZE || endCol < 0 || endCol >= BOARD_SIZE) {
        return 0;
    }
    // check if there is a piece at the start position:
    int piece = board.board[startRow][startCol];
    if (piece == 0) {
        return 0;
    }
    // check if the piece at the start position belongs to the current player:
    if (board.currentPlayer == WHITE && piece < 0) {
        return 0;
    }
    if (board.currentPlayer == BLACK && piece > 0) {
        return 0;
    }
    // check if the move is valid for the piece at the start position:
    switch (abs(piece)) {
        case 1: // Pawn
            if (startCol == endCol) { // move forward
                if (abs(endRow-startRow) == 1 && board.board[endRow][endCol] == 0) {
                    return 1;
                } else if (abs(endRow-startRow) == 2 && startRow == 1 && board.board[endRow][endCol] == 0
                        && board.board[startRow+1][startCol] == 0) {
                    return 1;
                }
            } else if (abs(startCol-endCol) == 1 && abs(startRow-endRow) == 1) { // diagonal capture
                int targetPiece = board.board[endRow][endCol];
                if ((board.currentPlayer == WHITE && targetPiece < 0) ||
                        (board.currentPlayer == BLACK && targetPiece > 0)) {
                    return 1;
                }
            }
            break;
        case 2: // Knight
            if (abs(startRow-endRow) == 2 && abs(startCol-endCol) == 1) {
                return 1;
            } else if (abs(startRow-endRow) == 1 && abs(startCol-endCol) == 2) {
                return 1;
            }
            break;
        case 3: // Bishop
            if (abs(startRow-endRow) == abs(startCol-endCol)) {
                int rowInc = (endRow > startRow) ? 1 : -1;
                int colInc = (endCol > startCol) ? 1 : -1;
                int row = startRow + rowInc;
                int col = startCol + colInc;
                while (row != endRow && col != endCol) {
                    if (board.board[row][col] != 0) {
                        return 0;
                    }
                    row += rowInc;
                    col += colInc;
                }
                int targetPiece = board.board[endRow][endCol];
                if ((board.currentPlayer == WHITE && targetPiece <= 0) ||
                        (board.currentPlayer == BLACK && targetPiece >= 0)) {
                    return 1;
                }
            }
            break;
        case 4: // Rook
            if (startRow == endRow) {
                int colInc = (endCol > startCol) ? 1 : -1;
                int col = startCol + colInc;
                while (col != endCol) {
                    if (board.board[startRow][col] != 0) {
                        return 0;
                    }
                    col += colInc;
                }
                int targetPiece = board.board[endRow][endCol];
                if ((board.currentPlayer == WHITE && targetPiece <= 0) ||
                        (board.currentPlayer == BLACK && targetPiece >= 0)) {
                    return 1;
                }
            } else if (startCol == endCol) {
                int rowInc = (endRow > startRow) ? 1 : -1;
                int row = startRow + rowInc;
                while (row != endRow) {
                    if (board.board[row][startCol] != 0) {
                        return 0;
                    }
                    row += rowInc;
                }
                int targetPiece = board.board[endRow][endCol];
                if ((board.currentPlayer == WHITE && targetPiece <= 0) ||
                        (board.currentPlayer == BLACK && targetPiece >= 0)) {
                    return 1;
                }
            }
            break;
        case 5: // Queen (can move like rook or bishop)
            if (abs(startRow-endRow) == abs(startCol-endCol)) { // bishop move
                int rowInc = (endRow > startRow) ? 1 : -1;
                int colInc = (endCol > startCol) ? 1 : -1;
                int row = startRow + rowInc;
                int col = startCol + colInc;
                while (row != endRow && col != endCol) {
                    if (board.board[row][col] != 0) {
                        return 0;
                    }
                    row += rowInc;
                    col += colInc;
                }
                int targetPiece = board.board[endRow][endCol];
                if ((board.currentPlayer == WHITE && targetPiece <= 0) ||
                        (board.currentPlayer == BLACK && targetPiece >= 0)) {
                    return 1;
                }
            } else if (startRow == endRow || startCol == endCol) { // rook move
                if (startRow == endRow) {
                    int colInc = (endCol > startCol) ? 1 : -1;
                    int col = startCol + colInc;
                    while (col != endCol) {
                        if (board.board[startRow][col] != 0) {
                            return 0;
                        }
                        col += colInc;
                    }
                } else {
                    int rowInc = (endRow > startRow) ? 1 : -1;
                    int row = startRow + rowInc;
                    while (row != endRow) {
                        if (board.board[row][startCol] != 0) {
                            return 0;
                        }
                        row += rowInc;
                    }
                }
                int targetPiece = board.board[endRow][endCol];
                if ((board.currentPlayer == WHITE && targetPiece <= 0) ||
                        (board.currentPlayer == BLACK && targetPiece >= 0)) {
                    return 1;
                }
            }
            break;
        case 6: // King
            if (abs(startRow-endRow) <= 1 && abs(startCol-endCol) <= 1) {
                int targetPiece = board.board[endRow][endCol];
                if ((board.currentPlayer == WHITE && targetPiece <= 0) ||
                        (board.currentPlayer == BLACK && targetPiece >= 0)) {
                    return 1;
                }
            }
            break;
    }
    return 0;
}

// define function to make a move on the chess board
int makeMove(struct chessBoard* board, int startRow, int startCol, int endRow, int endCol) {
    if (isValidMove(*board, startRow, startCol, endRow, endCol)) {
        int piece = board->board[startRow][startCol];
        board->board[startRow][startCol] = 0;
        board->board[endRow][endCol] = piece;
        board->currentPlayer = -board->currentPlayer;
        return 1;
    } else {
        printf("Invalid move!\n");
        return 0;
    }
}

// main function
int main() {
    struct chessBoard board;
    initializeBoard(&board);
    printBoard(board);
    printf("Enter moves using the format 'startRow startCol endRow endCol' (e.g. '2 1 4 1')\n");
    while (1) {
        int startRow, startCol, endRow, endCol;
        printf("Player %d's move: ", board.currentPlayer);
        scanf("%d %d %d %d", &startRow, &startCol, &endRow, &endCol);
        if (makeMove(&board, startRow-1, startCol-'A', endRow-1, endCol-'A')) { // subtracting 1 from row, and converting column to int
            printBoard(board);
        }
    }
    return 0;
}