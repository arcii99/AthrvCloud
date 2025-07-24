//FormAI DATASET v1.0 Category: Chess engine ; Style: single-threaded
#include <stdio.h>

// define chess board size
#define BOARD_SIZE 8

// define chess pieces
#define EMPTY 0
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

// define player colors
#define WHITE 0
#define BLACK 1

// chess board data structure
struct ChessBoard {
    int board[BOARD_SIZE][BOARD_SIZE]; // holds piece data
    int currentPlayer; // current player to make a move
    int whiteKingFile; // position of white king
    int whiteKingRank;
    int blackKingFile; // position of black king
    int blackKingRank;
};

// function to initialize the board with starting positions
void initializeBoard(struct ChessBoard* board) {
    // empty board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = EMPTY;
        }
    }

    // set up white pieces
    board->board[0][0] = ROOK;
    board->board[0][1] = KNIGHT;
    board->board[0][2] = BISHOP;
    board->board[0][3] = QUEEN;
    board->board[0][4] = KING;
    board->board[0][5] = BISHOP;
    board->board[0][6] = KNIGHT;
    board->board[0][7] = ROOK;
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->board[1][i] = PAWN;
    }

    // set up black pieces
    board->board[7][0] = ROOK;
    board->board[7][1] = KNIGHT;
    board->board[7][2] = BISHOP;
    board->board[7][3] = QUEEN;
    board->board[7][4] = KING;
    board->board[7][5] = BISHOP;
    board->board[7][6] = KNIGHT;
    board->board[7][7] = ROOK;
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->board[6][i] = PAWN;
    }

    // set up kings
    board->whiteKingFile = 4;
    board->whiteKingRank = 0;
    board->blackKingFile = 4;
    board->blackKingRank = 7;

    // set current player to white
    board->currentPlayer = WHITE;
}

// function to print the board to the console
void printBoard(struct ChessBoard* board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board->board[i][j]) {
                case EMPTY:
                    printf(". ");
                    break;
                case PAWN:
                    printf("P ");
                    break;
                case KNIGHT:
                    printf("N ");
                    break;
                case BISHOP:
                    printf("B ");
                    break;
                case ROOK:
                    printf("R ");
                    break;
                case QUEEN:
                    printf("Q ");
                    break;
                case KING:
                    printf("K ");
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

// function to move a piece on the board
void movePiece(struct ChessBoard* board, int startFile, int startRank, int endFile, int endRank) {
    // move the piece
    board->board[endRank][endFile] = board->board[startRank][startFile];
    board->board[startRank][startFile] = EMPTY;

    // update kings' positions if necessary
    if (board->board[endRank][endFile] == KING) {
        if (board->currentPlayer == WHITE) {
            board->whiteKingFile = endFile;
            board->whiteKingRank = endRank;
        } else {
            board->blackKingFile = endFile;
            board->blackKingRank = endRank;
        }
    }

    // switch to other player
    board->currentPlayer = (board->currentPlayer == WHITE) ? BLACK : WHITE;
}

// example usage
int main() {
    struct ChessBoard board;
    initializeBoard(&board);
    printBoard(&board);
    movePiece(&board, 4, 1, 4, 3);
    printBoard(&board);
    movePiece(&board, 4, 6, 4, 4);
    printBoard(&board);
}