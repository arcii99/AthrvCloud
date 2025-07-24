//FormAI DATASET v1.0 Category: Checkers Game ; Style: enthusiastic
#include <stdio.h>
#include<stdlib.h>

#define EMPTY 0
#define RED 1
#define BLACK 2

#define CROWNED 8

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];
/* board[row][col]
|
| --> x ++
v   y ++
*/

int currPlayer;
int numRedPieces;
int numBlackPieces;

void initBoard(); 
void displayBoard();
void movePiece(int startX, int startY, int endX, int endY);
void updateCrownedPieces();
void checkForWin();


int main() {
    initBoard();
    displayBoard();

    currPlayer = RED; // red player starts
    int x1, y1, x2, y2;
    printf("Red player's turn\n");
    while(1) {
        printf("Enter start coordinates: ");
        scanf("%d%d", &x1, &y1);
        printf("Enter end coordinates: ");
        scanf("%d%d", &x2, &y2);

        movePiece(x1, y1, x2, y2);

        updateCrownedPieces();
        checkForWin();

        displayBoard();
        printf("Next player's turn!\n");
        currPlayer = currPlayer == RED ? BLACK : RED;
    }

    return 0;
}

void initBoard() {
    // initialize the board with empty spaces,
    // red pieces and black pieces

    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if((i + j) % 2 == 0) {
                board[i][j] = EMPTY; // empty spaces
            }
            else if(i < 3) {
                board[i][j] = BLACK; // black pieces
                numBlackPieces++;
            }
            else if(i > 4) {
                board[i][j] = RED; // red pieces
                numRedPieces++;
            }
            else {
                board[i][j] = EMPTY; // empty spaces
            }
        }
    }
}

void displayBoard() {
    printf("  ");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf(" %d ", i);
    }
    printf("\n");

    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == EMPTY) {
                printf("[ ]");
            }
            else if(board[i][j] == RED) {
                printf("[R]");
            }
            else if(board[i][j] == BLACK) {
                printf("[B]");
            }
            else if(board[i][j] == RED + CROWNED) {
                printf("[R*]");
            }
            else if(board[i][j] == BLACK + CROWNED) {
                printf("[B*]");
            }
        }
        printf("\n");
    }
}

void movePiece(int startX, int startY, int endX, int endY) {
    // check if move is valid
    if(board[startX][startY] != currPlayer || board[endX][endY] != EMPTY) {
        printf("Invalid move! Try again.\n");
        printf("Red player's turn\n" && currPlayer == BLACK);
        printf("Black player's turn\n" && currPlayer == RED);
        return;
    }

    int deltaX = endX - startX;
    int deltaY = endY - startY;

    // check if move is diagonal
    if(abs(deltaX) != abs(deltaY)) {
        printf("Invalid move! Try again.\n");
        printf("Red player's turn\n" && currPlayer == BLACK);
        printf("Black player's turn\n" && currPlayer == RED);
        return;
    }

    // check if move is allowed distance based on piece status
    if(board[startX][startY] == RED && deltaY < 0) {
        printf("Invalid move! Try again.\n");
        printf("Red player's turn\n" && currPlayer == BLACK);
        printf("Black player's turn\n" && currPlayer == RED);
        return;
    }
    else if(board[startX][startY] == BLACK && deltaY > 0) {
        printf("Invalid move! Try again.\n");
        printf("Red player's turn\n" && currPlayer == BLACK);
        printf("Black player's turn\n" && currPlayer == RED);
        return;
    }
    else if(abs(deltaX) == 1 && abs(deltaY) == 1) { // move is one step diagonally
        board[endX][endY] = board[startX][startY];
        board[startX][startY] = EMPTY;
    }
    else if(abs(deltaX) == 2 && abs(deltaY) == 2) { // move is two steps diagonally (jump move)
        int midX = (startX + endX) / 2;
        int midY = (startY + endY) / 2;

        if(board[midX][midY] == EMPTY || board[midX][midY] == currPlayer) {
            printf("Invalid move! Try again.\n");
            printf("Red player's turn\n" && currPlayer == BLACK);
            printf("Black player's turn\n" && currPlayer == RED);
            return;
        }

        // capture opponent's piece
        if(currPlayer == RED) {
            numBlackPieces--;
        }
        else {
            numRedPieces--;
        }
        board[endX][endY] = board[startX][startY];
        board[midX][midY] = EMPTY;
        board[startX][startY] = EMPTY;
    }
    else {
        printf("Invalid move! Try again.\n");
        printf("Red player's turn\n" && currPlayer == BLACK);
        printf("Black player's turn\n" && currPlayer == RED);
        return;
    }

    // check if piece is crowned
    updateCrownedPieces();
}

void updateCrownedPieces() {
    // check which pieces should become crowned
    for(int i = 0; i < BOARD_SIZE; i++) {
        if(board[0][i] == BLACK) {
            board[0][i] = BLACK + CROWNED;
        }
        if(board[BOARD_SIZE - 1][i] == RED) {
            board[BOARD_SIZE - 1][i] = RED + CROWNED;
        }
    }
}

void checkForWin() {
    // check if either player won
    if(numRedPieces == 0) {
        printf("BLACK WINS!\n");
        exit(0);
    }
    else if(numBlackPieces == 0) {
        printf("RED WINS!\n");
        exit(0);
    }

    // check if either player cannot make a move
    int canRedMove = 0;
    int canBlackMove = 0;

    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == RED || board[i][j] == RED + CROWNED) {
                if(i > 0) {
                    if(j > 0 && board[i-1][j-1] == EMPTY) {
                        canRedMove = 1;
                    }
                    if(j < BOARD_SIZE - 1 && board[i-1][j+1] == EMPTY) {
                        canRedMove = 1;
                    }
                }
                if(board[i][j] == RED + CROWNED) {
                    if(i < BOARD_SIZE - 1) {
                        if(j > 0 && board[i+1][j-1] == EMPTY) {
                            canRedMove = 1;
                        }
                        if(j < BOARD_SIZE - 1 && board[i+1][j+1] == EMPTY) {
                            canRedMove = 1;
                        }
                    }
                }
            }
            else if(board[i][j] == BLACK || board[i][j] == BLACK + CROWNED) {
                if(i < BOARD_SIZE - 1) {
                    if(j > 0 && board[i+1][j-1] == EMPTY) {
                        canBlackMove = 1;
                    }
                    if(j < BOARD_SIZE - 1 && board[i+1][j+1] == EMPTY) {
                        canBlackMove = 1;
                    }
                }
                if(board[i][j] == BLACK + CROWNED) {
                    if(i > 0) {
                        if(j > 0 && board[i-1][j-1] == EMPTY) {
                            canBlackMove = 1;
                        }
                        if(j < BOARD_SIZE - 1 && board[i-1][j+1] == EMPTY) {
                            canBlackMove = 1;
                        }
                    }
                }
            }
        }
    }

    if(!canRedMove) {
        printf("BLACK WINS!\n");
        exit(0);
    }
    if(!canBlackMove) {
        printf("RED WINS!\n");
        exit(0);
    }
}