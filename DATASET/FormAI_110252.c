//FormAI DATASET v1.0 Category: Chess AI ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef char Board[BOARD_SIZE][BOARD_SIZE];

const int pawnValue = 1;
const int knightValue = 3;
const int bishopValue = 3;
const int rookValue = 5;
const int queenValue = 9;
const int kingValue = 100;

const int pawnTable[BOARD_SIZE][BOARD_SIZE] = {
    {0,  0,  0,  0,  0,  0,  0,  0},
    {50, 50, 50, 50, 50, 50, 50, 50},
    {10, 10, 20, 30, 30, 20, 10, 10},
    {5,  5, 10, 25, 25, 10,  5,  5},
    {0,  0,  0, 20, 20,  0,  0,  0},
    {5, -5,-10,  0,  0,-10, -5,  5},
    {5, 10, 10,-20,-20, 10, 10,  5},
    {0,  0,  0,  0,  0,  0,  0,  0}
};

const int knightTable[BOARD_SIZE][BOARD_SIZE] = {
    {-50,-40,-30,-30,-30,-30,-40,-50},
    {-40,-20,  0,  0,  0,  0,-20,-40},
    {-30,  0, 10, 15, 15, 10,  0,-30},
    {-30,  5, 15, 20, 20, 15,  5,-30},
    {-30,  0, 15, 20, 20, 15,  0,-30},
    {-30,  5, 10, 15, 15, 10,  5,-30},
    {-40,-20,  0,  5,  5,  0,-20,-40},
    {-50,-40,-30,-30,-30,-30,-40,-50}
};

const int bishopTable[BOARD_SIZE][BOARD_SIZE] = {
    {-20,-10,-10,-10,-10,-10,-10,-20},
    {-10,  0,  0,  0,  0,  0,  0,-10},
    {-10,  0,  5, 10, 10,  5,  0,-10},
    {-10,  5,  5, 10, 10,  5,  5,-10},
    {-10,  0, 10, 10, 10, 10,  0,-10},
    {-10, 10, 10, 10, 10, 10, 10,-10},
    {-10,  5,  0,  0,  0,  0,  5,-10},
    {-20,-10,-10,-10,-10,-10,-10,-20}
};

const int rookTable[BOARD_SIZE][BOARD_SIZE] = {
    {0,  0,  0,  5,  5,  0,  0,  0},
    {-5,  0,  0,  0,  0,  0,  0, -5},
    {-5,  0,  0,  0,  0,  0,  0, -5},
    {-5,  0,  0,  0,  0,  0,  0, -5},
    {-5,  0,  0,  0,  0,  0,  0, -5},
    {-5,  0,  0,  0,  0,  0,  0, -5},
    {5, 10, 10, 10, 10, 10, 10,  5},
    {0,  0,  0,  0,  0,  0,  0,  0}
};

const int queenTable[BOARD_SIZE][BOARD_SIZE] = {
    {-20,-10,-10, -5, -5,-10,-10,-20},
    {-10,  0,  0,  0,  0,  0,  0,-10},
    {-10,  0,  5,  5,  5,  5,  0,-10},
    {-5,  0,  5,  5,  5,  5,  0, -5},
    {0,  0,  5,  5,  5,  5,  0, -5},
    {-10,  5,  5,  5,  5,  5,  0,-10},
    {-10,  0,  5,  0,  0,  0,  0,-10},
    {-20,-10,-10, -5, -5,-10,-10,-20}
};

const int kingTable[BOARD_SIZE][BOARD_SIZE] = {
    {-30,-40,-40,-50,-50,-40,-40,-30},
    {-30,-40,-40,-50,-50,-40,-40,-30},
    {-30,-40,-40,-50,-50,-40,-40,-30},
    {-30,-40,-40,-50,-50,-40,-40,-30},
    {-20,-30,-30,-40,-40,-30,-30,-20},
    {-10,-20,-20,-20,-20,-20,-20,-10},
    {20, 20,  0,  0,  0,  0, 20, 20},
    {20, 30, 10,  0,  0, 10, 30, 20}
};

int evaluate(Board board, int player) {
    int i, j, value = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            int piece = board[i][j];
            if (piece == 0) continue;  // empty square
            int pieceValue = 0;
            switch (piece) {
                case 'p': case 'P': pieceValue = pawnValue; break;
                case 'n': case 'N': pieceValue = knightValue; break;
                case 'b': case 'B': pieceValue = bishopValue; break;
                case 'r': case 'R': pieceValue = rookValue; break;
                case 'q': case 'Q': pieceValue = queenValue; break;
                case 'k': case 'K': pieceValue = kingValue; break;
            }
            if (pieceValue == 0) {
                printf("Error: Invalid piece\n");
                exit(1);
            }
            int sign = (piece > 'Z' ? -1 : 1);
            value += pieceValue * sign;
            switch (piece) {
                case 'p': pieceValue += pawnTable[i][j]; break;
                case 'n': pieceValue += knightTable[i][j]; break;
                case 'b': pieceValue += bishopTable[i][j]; break;
                case 'r': pieceValue += rookTable[i][j]; break;
                case 'q': pieceValue += queenTable[i][j]; break;
                case 'k': pieceValue += kingTable[i][j]; break;
            }
            value += pieceValue * sign;
        }
    }
    return value * (player == 'b' ? -1 : 1);
}

void printBoard(Board board) {
    int i, j;
    printf("\n");
    for (i = BOARD_SIZE - 1; i >= 0; i--) {
        printf("%d ", i + 1);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n\n");
}

int main() {
    Board board = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };
    int player = 'w';
    printBoard(board);
    while (1) {
        int value = evaluate(board, player);
        if (value > 0) {
            printf("White is winning by %d points.\n", value);
        } else if (value < 0) {
            printf("Black is winning by %d points.\n", -value);
        } else {
            printf("The game is tied.\n");
        }
        break;
    }
    return 0;
}