//FormAI DATASET v1.0 Category: Checkers Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
#define RED 1
#define BLUE 2

int board[8][8];

void initializeBoard() {
    int i, j;

    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++) {
            if((i + j) % 2 == 0) {
                if(i < 3) {
                    board[i][j] = BLUE;
                } else if(i > 4) {
                    board[i][j] = RED;
                } else {
                    board[i][j] = EMPTY;
                }
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

void printBoard() {
    int i, j;

    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++) {
            if(board[i][j] == EMPTY) {
                printf("-");
            } else if(board[i][j] == BLUE) {
                printf("B");
            } else {
                printf("R");
            }
            printf(" ");
        }
        printf("\n");
    }
}

int isCaptureMove(int player, int fromRow, int fromCol, int toRow, int toCol) {
    int i, j;

    if(toRow < 0 || toRow >= 8 || toCol < 0 || toCol >= 8 || board[toRow][toCol] != EMPTY) {
        return 0;
    }

    if(player == RED) {
        if(toRow > fromRow) {
            return 0;
        }

        if(toRow == fromRow - 2 && toCol == fromCol - 2 && board[fromRow-1][fromCol-1] == BLUE) {
            return 1;
        }

        if(toRow == fromRow - 2 && toCol == fromCol + 2 && board[fromRow-1][fromCol+1] == BLUE) {
            return 1;
        }

        if(toRow == fromRow - 1 && toCol == fromCol - 1 && board[fromRow-1][fromCol-1] == BLUE) {
            return 1;
        }

        if(toRow == fromRow - 1 && toCol == fromCol + 1 && board[fromRow-1][fromCol+1] == BLUE) {
            return 1;
        }
    } else {
        if(toRow < fromRow) {
            return 0;
        }

        if(toRow == fromRow + 2 && toCol == fromCol - 2 && board[fromRow+1][fromCol-1] == RED) {
            return 1;
        }

        if(toRow == fromRow + 2 && toCol == fromCol + 2 && board[fromRow+1][fromCol+1] == RED) {
            return 1;
        }

        if(toRow == fromRow + 1 && toCol == fromCol - 1 && board[fromRow+1][fromCol-1] == RED) {
            return 1;
        }

        if(toRow == fromRow + 1 && toCol == fromCol + 1 && board[fromRow+1][fromCol+1] == RED) {
            return 1;
        }
    }

    return 0;
}

int makeMove(int player, int fromRow, int fromCol, int toRow, int toCol) {
    int isCapture = isCaptureMove(player, fromRow, fromCol, toRow, toCol);

    if(isCapture) {
        board[fromRow][fromCol] = EMPTY;
        board[toRow][toCol] = player;

        if(player == RED) {
            if(toRow == 0) {
                board[toRow][toCol] = RED + 2;
            }

            if(toRow == fromRow - 2 && toCol == fromCol - 2) {
                board[fromRow-1][fromCol-1] = EMPTY;
            }

            if(toRow == fromRow - 2 && toCol == fromCol + 2) {
                board[fromRow-1][fromCol+1] = EMPTY;
            }
        } else {
            if(toRow == 7) {
                board[toRow][toCol] = BLUE + 2;
            }

            if(toRow == fromRow + 2 && toCol == fromCol - 2) {
                board[fromRow+1][fromCol-1] = EMPTY;
            }

            if(toRow == fromRow + 2 && toCol == fromCol + 2) {
                board[fromRow+1][fromCol+1] = EMPTY;
            }
        }
    } else {
        int tmp = board[fromRow][fromCol];
        board[fromRow][fromCol] = EMPTY;
        board[toRow][toCol] = tmp;

        if(player == RED && toRow == 0) {
            board[toRow][toCol] = RED + 2;
        }

        if(player == BLUE && toRow == 7) {
            board[toRow][toCol] = BLUE + 2;
        }
    }

    return isCapture;
}

int canPlayerMove(int player) {
    int i, j;

    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++) {
            if(board[i][j] == player || board[i][j] == player + 2) {
                if(isCaptureMove(player, i, j, i+1, j+1) || isCaptureMove(player, i, j, i+1, j-1)
                   || isCaptureMove(player, i, j, i-1, j+1) || isCaptureMove(player, i, j, i-1, j-1)) {
                    return 1;
                }

                if(board[i][j] == player + 2) {
                    if(isCaptureMove(player, i, j, i+1, j+1) || isCaptureMove(player, i, j, i+1, j-1)
                    || isCaptureMove(player, i, j, i-1, j+1) || isCaptureMove(player, i, j, i-1, j-1)) {
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}

int getMove(int player) {
    int fromRow, fromCol, toRow, toCol;

    printf("Player %d, enter your move: ", player);
    scanf("%d%d%d%d", &fromRow, &fromCol, &toRow, &toCol);

    if(fromRow < 0 || fromRow >= 8 || fromCol < 0 || fromCol >= 8 || board[fromRow][fromCol] != player
       || toRow < 0 || toRow >= 8 || toCol < 0 || toCol >= 8 || board[toRow][toCol] != EMPTY) {
        return 0;
    }

    if(isCaptureMove(player, fromRow, fromCol, toRow, toCol)) {
        return makeMove(player, fromRow, fromCol, toRow, toCol);
    } else {
        int tmp = board[fromRow][fromCol];
        board[fromRow][fromCol] = EMPTY;
        board[toRow][toCol] = tmp;

        if(player == RED && toRow == 0) {
            board[toRow][toCol] = RED + 2;
        }

        if(player == BLUE && toRow == 7) {
            board[toRow][toCol] = BLUE + 2;
        }
    }

    return 0;
}

int main() {
    int player = RED;

    initializeBoard();
    printBoard();

    while(1) {
        if(!canPlayerMove(player)) {
            printf("Player %d has no moves left. Player %d wins!\n", player, player == RED ? BLUE : RED);
            break;
        }

        int isCapture = getMove(player);

        if(isCapture) {
            printf("Good move! You get to move again.\n");
        } else {
            player = player == RED ? BLUE : RED;
        }

        printBoard();
    }

    return 0;
}