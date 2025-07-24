//FormAI DATASET v1.0 Category: Checkers Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Enumeration of checker colors
typedef enum {
    EMPTY,
    RED,
    WHITE
} CheckerColor;


// Structure representing a checker piece
typedef struct {
    CheckerColor color;
    int isKing;
} Checker;


// Structure representing a checkers board
typedef struct {
    Checker board[BOARD_SIZE][BOARD_SIZE];
} CheckersBoard;


// Function to initialize a checkers board
void InitBoard(CheckersBoard* board) {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(i < 3) {
                if((i + j) % 2 == 0) {
                    board->board[i][j].color = WHITE;
                    board->board[i][j].isKing = 0;
                } else {
                    board->board[i][j].color = EMPTY;
                    board->board[i][j].isKing = 0;
                }
            } else if(i > 4) {
                if((i + j) % 2 == 0) {
                    board->board[i][j].color = RED;
                    board->board[i][j].isKing = 0;
                } else {
                    board->board[i][j].color = EMPTY;
                    board->board[i][j].isKing = 0;
                }
            } else {
                board->board[i][j].color = EMPTY;
                board->board[i][j].isKing = 0;
            }
        }
    }
}


// Function to print a checkers board
void printBoard(CheckersBoard* board) {
    int i, j;
    printf("\n");
    for(i = 0; i < BOARD_SIZE; i++) {
        printf("     ");
        for(j = 0; j < BOARD_SIZE; j++) {
            if(board->board[i][j].color == WHITE) {
                if(board->board[i][j].isKing) {
                    printf("WK ");
                } else {
                    printf("W  ");
                }
            } else if(board->board[i][j].color == RED) {
                if(board->board[i][j].isKing) {
                    printf("RK ");
                } else {
                    printf("R  ");
                }
            } else {
                printf(".  ");
            }
        }
        printf("\n\n");
    }
}


// Function to move a checker piece
int Move(CheckersBoard* board, int fromX, int fromY, int toX, int toY) {
    if(fromX < 0 || fromX >= BOARD_SIZE || fromY < 0 || fromY >= BOARD_SIZE ||
            toX < 0 || toX >= BOARD_SIZE || toY < 0 || toY >= BOARD_SIZE) {
        return 0;
    }

    Checker* from = &board->board[fromX][fromY];
    Checker* to = &board->board[toX][toY];

    if(to->color != EMPTY) {
        return 0;
    }

    if(from->color == WHITE && toX < fromX) {
        return 0;
    }

    if(from->color == RED && toX > fromX) {
        return 0;
    }

    int dx = toX - fromX;
    int dy = toY - fromY;

    if(abs(dx) == 1 && abs(dy) == 1 && !from->isKing) {
        // If a regular checker tries to move more than one square or move diagonally backwards,
        // the move is invalid.
        if((from->color == WHITE && dx > 0) || (from->color == RED && dx < 0)) {
            return 0;
        }

        from->color = EMPTY;
        to->color = from->color;
    } else if(abs(dx) == 2 && abs(dy) == 2) {
        // If a regular checker tries to move more than one square or move diagonally backwards,
        // the move is invalid.
        if((from->color == WHITE && dx > 0) || (from->color == RED && dx < 0)) {
            return 0;
        }

        Checker* jumped = &board->board[fromX + dx/2][fromY + dy/2];

        if(jumped->color == EMPTY || jumped->color == from->color) {
            return 0;
        }

        jumped->color = EMPTY;
        to->color = from->color;
        from->color = EMPTY;

        if(toX == 0 && to->color == WHITE) {
            to->isKing = 1;
        }

        if(toX == BOARD_SIZE-1 && to->color == RED) {
            to->isKing = 1;
        }

        return 1;
    } else {
        return 0;
    }
}


// Main function to play the checkers game
int main() {
    CheckersBoard board;
    int turn = RED;
    int winner = EMPTY;
    int fromX, fromY, toX, toY;
    InitBoard(&board);

    while(winner == EMPTY) {
        printBoard(&board);

        if(turn == RED) {
            printf("Red's turn\n");
        } else {
            printf("White's turn\n");
        }

        printf("Enter coordinates of piece to move (x y): ");
        scanf("%d %d", &fromX, &fromY);

        printf("Enter coordinates of destination (x y): ");
        scanf("%d %d", &toX, &toY);

        if(Move(&board, fromX, fromY, toX, toY)) {
            if(turn == RED) {
                turn = WHITE;
            } else {
                turn = RED;
            }
        }

        // Determine if the game has been won
        int i, j;
        int redCount = 0;
        int whiteCount = 0;

        for(i = 0; i < BOARD_SIZE; i++) {
            for(j = 0; j < BOARD_SIZE; j++) {
                if(board.board[i][j].color == RED) {
                    redCount++;
                } else if(board.board[i][j].color == WHITE) {
                    whiteCount++;
                }
            }
        }

        if(redCount == 0) {
            winner = WHITE;
        } else if(whiteCount == 0) {
            winner = RED;
        }
    }

    printBoard(&board);

    if(winner == RED) {
        printf("Red wins!\n");
    } else {
        printf("White wins!\n");
    }

    return 0;
}