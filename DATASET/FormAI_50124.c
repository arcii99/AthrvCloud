//FormAI DATASET v1.0 Category: Checkers Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

enum Piece {EMPTY, RED, BLACK};

void printBoard(enum Piece board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n   A  B  C  D  E  F  G  H\n");
    printf("  +------------------------+\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%d |", i+1);
        for(int j=0; j<BOARD_SIZE; j++) {
            switch(board[i][j]) {
                case EMPTY:
                    printf("   |");
                    break;
                case RED:
                    printf(" O |");
                    break;
                case BLACK:
                    printf(" X |");
                    break;
                default:
                    break;
            }
        }
        printf(" %d\n", i+1);
        printf("  +------------------------+\n");
    }
    printf("   A  B  C  D  E  F  G  H\n\n");
}

void setupBoard(enum Piece board[BOARD_SIZE][BOARD_SIZE]) {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }

    // set up black pieces
    for(int i=0; i<3; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if((i+j)%2 == 1) {
                board[i][j] = BLACK;
            }
        }
    }

    // set up red pieces
    for(int i=BOARD_SIZE-1; i>=BOARD_SIZE-3; i--) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if((i+j)%2 == 1) {
                board[i][j] = RED;
            }
        }
    }
}

int isValidMove(enum Piece board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol, int endRow, int endCol, enum Piece player) {
    // check if ending cell is off board
    if(endRow < 0 || endRow >= BOARD_SIZE || endCol < 0 || endCol >= BOARD_SIZE) {
        return 0;
    }

    // check if player is attempting to move empty cell or enemy piece
    if(board[startRow][startCol] == EMPTY || board[startRow][startCol] != player) {
        return 0;
    }

    // check if ending cell is already occupied
    if(board[endRow][endCol] != EMPTY) {
        return 0;
    }

    // check if move distance is only one cell diagonal
    int rowDelta = endRow-startRow;
    int colDelta = endCol-startCol;
    if(abs(rowDelta) != 1 || abs(colDelta) != 1) {
        return 0;
    }

    // check if player is moving in correct direction (black goes up, red goes down)
    if(player == BLACK && rowDelta > 0) {
        return 0;
    }
    if(player == RED && rowDelta < 0) {
        return 0;
    }

    // check if player is trying to move multiple cells without jumping
    if(abs(rowDelta) > 1 || abs(colDelta) > 1) {
        return 0;
    }

    // all checks passed, move is valid
    return 1;
}

int canJump(enum Piece board[BOARD_SIZE][BOARD_SIZE], int row, int col, int jumpRow, int jumpCol, int endRow, int endCol) {
    // check if ending cell is off board
    if(endRow < 0 || endRow >= BOARD_SIZE || endCol < 0 || endCol >= BOARD_SIZE) {
        return 0;
    }

    // check if jump row and column are exactly 2 cells away from starting row and column
    int rowDelta = jumpRow-row;
    int colDelta = jumpCol-col;
    if(abs(rowDelta) != 2 || abs(colDelta) != 2) {
        return 0;
    }

    // check if cell between starting cell and ending cell contains enemy piece
    int enemyRow = (row+jumpRow)/2;
    int enemyCol = (col+jumpCol)/2;
    if(board[enemyRow][enemyCol] == EMPTY || board[enemyRow][enemyCol] == board[row][col]) {
        return 0;
    }

    // check if ending cell is already occupied
    if(board[endRow][endCol] != EMPTY) {
        return 0;
    }

    // all checks passed, return true
    return 1;
}

int isValidJump(enum Piece board[BOARD_SIZE][BOARD_SIZE], int row, int col, int endRow, int endCol, enum Piece player) {
    // check if player is attempting to move empty cell or enemy piece
    if(board[row][col] == EMPTY || board[row][col] != player) {
        return 0;
    }

    // check if ending cell is already occupied
    if(board[endRow][endCol] != EMPTY) {
        return 0;
    }

    // check if player is moving in correct direction (black goes up, red goes down)
    int rowDelta = endRow-row;
    if(player == BLACK && rowDelta > 0) {
        return 0;
    }
    if(player == RED && rowDelta < 0) {
        return 0;
    }

    // check if there is an available jump
    int jumpAvailable = 0;
    if(canJump(board, row, col, row+1, col+1, endRow, endCol)) {
        jumpAvailable = 1;
    }
    if(canJump(board, row, col, row+1, col-1, endRow, endCol)) {
        jumpAvailable = 1;
    }
    if(canJump(board, row, col, row-1, col+1, endRow, endCol)) {
        jumpAvailable = 1;
    }
    if(canJump(board, row, col, row-1, col-1, endRow, endCol)) {
        jumpAvailable = 1;
    }
    if(!jumpAvailable) {
        return 0;
    }

    // all checks passed, jump is valid
    return 1;
}

void performMove(enum Piece board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol, int endRow, int endCol, enum Piece player) {
    // if move is a jump, remove enemy piece from board
    if(abs(endRow-startRow) > 1 || abs(endCol-startCol) > 1) {
        int enemyRow = (startRow+endRow)/2;
        int enemyCol = (startCol+endCol)/2;
        board[enemyRow][enemyCol] = EMPTY;
    }

    // move piece to new location
    board[endRow][endCol] = board[startRow][startCol];
    board[startRow][startCol] = EMPTY;

    // if piece reaches far end of board, promote to king
    if(board[endRow][endCol] == BLACK && endRow == 0) {
        board[endRow][endCol] = BLACK+2;
    }
    if(board[endRow][endCol] == RED && endRow == BOARD_SIZE-1) {
        board[endRow][endCol] = RED+2;
    }
}

int isGameOver(enum Piece board[BOARD_SIZE][BOARD_SIZE], enum Piece player) {
    // check if any pieces remaining for current player
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == player || board[i][j] == player+2) {
                return 0;
            }
        }
    }

    // current player has no pieces remaining, game over
    return 1;
}

void playCheckers() {
    enum Piece board[BOARD_SIZE][BOARD_SIZE];
    setupBoard(board);

    enum Piece currentPlayer = RED;
    int gameOver = 0;
    while(!gameOver) {
        printBoard(board);

        printf("Player %s's turn.\n", (currentPlayer == RED) ? "red" : "black");

        int startRow, startCol, endRow, endCol;
        printf("Enter starting position (e.g. 'A3'): ");
        scanf(" %c%d", &startCol, &startRow);
        startCol -= 'A';
        startRow--;

        printf("Enter ending position (e.g. 'B4'): ");
        scanf(" %c%d", &endCol, &endRow);
        endCol -= 'A';
        endRow--;

        if(isValidJump(board, startRow, startCol, endRow, endCol, currentPlayer)) {
            performMove(board, startRow, startCol, endRow, endCol, currentPlayer);
            while(isValidJump(board, endRow, endCol, endRow-2, endCol-2, currentPlayer) ||
                    isValidJump(board, endRow, endCol, endRow-2, endCol+2, currentPlayer) ||
                    isValidJump(board, endRow, endCol, endRow+2, endCol-2, currentPlayer) ||
                    isValidJump(board, endRow, endCol, endRow+2, endCol+2, currentPlayer)) {
                printf("Jumping again...\n");
                printBoard(board);

                startRow = endRow;
                startCol = endCol;

                int jumpRow, jumpCol;
                if(isValidJump(board, endRow, endCol, endRow-2, endCol-2, currentPlayer)) {
                    jumpRow = endRow-1;
                    jumpCol = endCol-1;
                }
                if(isValidJump(board, endRow, endCol, endRow-2, endCol+2, currentPlayer)) {
                    jumpRow = endRow-1;
                    jumpCol = endCol+1;
                }
                if(isValidJump(board, endRow, endCol, endRow+2, endCol-2, currentPlayer)) {
                    jumpRow = endRow+1;
                    jumpCol = endCol-1;
                }
                if(isValidJump(board, endRow, endCol, endRow+2, endCol+2, currentPlayer)) {
                    jumpRow = endRow+1;
                    jumpCol = endCol+1;
                }

                endRow = jumpRow;
                endCol = jumpCol;

                performMove(board, startRow, startCol, endRow, endCol, currentPlayer);
            }
        }
        else if(isValidMove(board, startRow, startCol, endRow, endCol, currentPlayer)) {
            performMove(board, startRow, startCol, endRow, endCol, currentPlayer);
        }
        else {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        if(isGameOver(board, currentPlayer)) {
            printf("Game over! Player %s wins!\n", (currentPlayer == RED) ? "red" : "black");
            gameOver = 1;
        }
        else {
            currentPlayer = (currentPlayer == RED) ? BLACK : RED;
        }
    }
}

int main() {
    printf("Welcome to C Checkers!\n");
    playCheckers();
    return 0;
}