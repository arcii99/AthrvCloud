//FormAI DATASET v1.0 Category: Chess engine ; Style: careful
#include <stdio.h>

// Constants for chess board size
#define BOARD_SIZE 8

// Constants for piece types
#define EMPTY 0
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

// Structure for board coordinate
typedef struct {
    int x;
    int y;
} Coordinate;

// Structure for chess piece
typedef struct {
    int type;
    int color; // 0 for white, 1 for black
    int hasMoved; // to be used to check if pawn can do two steps or not, and rook and king can castle or not
} Piece;

// Global 2D array for chess board
Piece board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize chess board
void initializeBoard() {
    // Initialize pawns
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i].type = PAWN;
        board[1][i].color = 1;
        board[1][i].hasMoved = 0;

        board[6][i].type = PAWN;
        board[6][i].color = 0;
        board[6][i].hasMoved = 0;
    }

    // Initialize knights
    board[0][1].type = KNIGHT;
    board[0][1].color = 1;
    board[0][6].type = KNIGHT;
    board[0][6].color = 1;

    board[7][1].type = KNIGHT;
    board[7][1].color = 0;
    board[7][6].type = KNIGHT;
    board[7][6].color = 0;

    // Initialize bishops
    board[0][2].type = BISHOP;
    board[0][2].color = 1;
    board[0][5].type = BISHOP;
    board[0][5].color = 1;

    board[7][2].type = BISHOP;
    board[7][2].color = 0;
    board[7][5].type = BISHOP;
    board[7][5].color = 0;

    // Initialize rooks
    board[0][0].type = ROOK;
    board[0][0].color = 1;
    board[0][7].type = ROOK;
    board[0][7].color = 1;

    board[7][0].type = ROOK;
    board[7][0].color = 0;
    board[7][7].type = ROOK;
    board[7][7].color = 0;

    // Initialize queens and kings
    board[0][3].type = QUEEN;
    board[0][3].color = 1;
    board[0][4].type = KING;
    board[0][4].color = 1;

    board[7][3].type = QUEEN;
    board[7][3].color = 0;
    board[7][4].type = KING;
    board[7][4].color = 0;

    // Initialize remaining squares as empty
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].type = EMPTY;
            board[i][j].color = -1;
            board[i][j].hasMoved = 0;
        }
    }
}

// Function to print the chess board
void printBoard() {
    printf("  a b c d e f g h\n");
    printf(" +----------------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].type == EMPTY) {
                printf("  ");
            } else if (board[i][j].color == 0) {
                switch (board[i][j].type) {
                    case PAWN:
                        printf("\u2659 ");
                        break;
                    case KNIGHT:
                        printf("\u2658 ");
                        break;
                    case BISHOP:
                        printf("\u2657 ");
                        break;
                    case ROOK:
                        printf("\u2656 ");
                        break;
                    case QUEEN:
                        printf("\u2655 ");
                        break;
                    case KING:
                        printf("\u2654 ");
                        break;
                }
            } else if (board[i][j].color == 1) {
                switch (board[i][j].type) {
                    case PAWN:
                        printf("\u265F ");
                        break;
                    case KNIGHT:
                        printf("\u265E ");
                        break;
                    case BISHOP:
                        printf("\u265D ");
                        break;
                    case ROOK:
                        printf("\u265C ");
                        break;
                    case QUEEN:
                        printf("\u265B ");
                        break;
                    case KING:
                        printf("\u265A ");
                        break;
                }
            }
        }
        printf("|%d\n", BOARD_SIZE - i);
    }
    printf(" +----------------+\n");
    printf("  a b c d e f g h\n");
}

// Function to get possible moves for a pawn
void getPawnMoves(Coordinate position, Coordinate *moves, int *count) {
    int x = position.x;
    int y = position.y;

    if (board[x][y].color == 0) {
        // Possible moves for white pawns
        if (x == 6 && board[x - 1][y].type == EMPTY && board[x - 2][y].type == EMPTY) {
            moves[*count].x = x - 2;
            moves[*count].y = y;
            (*count)++;
        }
        if (x > 0 && board[x - 1][y].type == EMPTY) {
            moves[*count].x = x - 1;
            moves[*count].y = y;
            (*count)++;
        }
        if (x > 0 && y > 0 && board[x - 1][y - 1].type != EMPTY && board[x - 1][y - 1].color != board[x][y].color) {
            moves[*count].x = x - 1;
            moves[*count].y = y - 1;
            (*count)++;
        }
        if (x > 0 && y < BOARD_SIZE - 1 && board[x - 1][y + 1].type != EMPTY && board[x - 1][y + 1].color != board[x][y].color) {
            moves[*count].x = x - 1;
            moves[*count].y = y + 1;
            (*count)++;
        }
    } else if (board[x][y].color == 1) {
        // Possible moves for black pawns
        if (x == 1 && board[x + 1][y].type == EMPTY && board[x + 2][y].type == EMPTY) {
            moves[*count].x = x + 2;
            moves[*count].y = y;
            (*count)++;
        }
        if (x < BOARD_SIZE - 1 && board[x + 1][y].type == EMPTY) {
            moves[*count].x = x + 1;
            moves[*count].y = y;
            (*count)++;
        }
        if (x < BOARD_SIZE - 1 && y > 0 && board[x + 1][y - 1].type != EMPTY && board[x + 1][y - 1].color != board[x][y].color) {
            moves[*count].x = x + 1;
            moves[*count].y = y - 1;
            (*count)++;
        }
        if (x < BOARD_SIZE - 1 && y < BOARD_SIZE - 1 && board[x + 1][y + 1].type != EMPTY && board[x + 1][y + 1].color != board[x][y].color) {
            moves[*count].x = x + 1;
            moves[*count].y = y + 1;
            (*count)++;
        }
    }
}

int main() {
    initializeBoard();
    printBoard();

    // Example usage of getPawnMoves function
    Coordinate pawnPos = {1, 2};
    Coordinate possibleMoves[4];
    int moveCount = 0;
    getPawnMoves(pawnPos, possibleMoves, &moveCount);

    printf("Possible moves for pawn at (%d, %d):\n", pawnPos.x, pawnPos.y);
    for (int i = 0; i < moveCount; i++) {
        printf("(%d, %d)\n", possibleMoves[i].x, possibleMoves[i].y);
    }

    return 0;
}