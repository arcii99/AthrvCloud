//FormAI DATASET v1.0 Category: Chess engine ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];
int whitesTurn = 1;

void initBoard() {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(i == 0 || i == 7) {
                if(j == 0 || j == 7) {
                    board[i][j] = 2;
                } else if(j == 1 || j == 6) {
                    board[i][j] = 3;
                } else if(j == 2 || j == 5) {
                    board[i][j] = 4;
                } else if(j == 3) {
                    board[i][j] = 5;
                } else {
                    board[i][j] = 6;
                }
            } else if(i == 1 || i == 6) {
                board[i][j] = 1;
            } else {
                board[i][j] = 0;
            }
        }
    }
}

void printBoard() {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(int startRow, int startCol, int endRow, int endCol) {
    if(startRow != endRow && startCol != endCol) {
        return 0;
    }
    
    if(board[startRow][startCol] == 0) {
        return 0;
    }
    
    if(board[startRow][startCol] == 1) {
        if(whitesTurn && startRow != 1 && (endRow - startRow != -1 || abs(endCol - startCol) != 0)) {
            return 0;
        } else if(!whitesTurn && startRow != 6 && (endRow - startRow != 1 || abs(endCol - startCol) != 0)) {
            return 0;
        }
    }
    
    if(board[endRow][endCol] != 0 && (board[startRow][startCol] > 0) == (board[endRow][endCol] > 0)) {
        return 0;
    }
    
    if(board[startRow][startCol] > 0 && board[endRow][endCol] < 0 && board[startRow][startCol] != 1) {
        return 0;
    }
    
    if(board[startRow][startCol] < 0 && board[endRow][endCol] > 0 && board[startRow][startCol] != -1) {
        return 0;
    }
    
    if(board[startRow][startCol] == 1 && board[endRow][endCol] != 0 && abs(endCol - startCol) == 1 && abs(endRow - startRow) == 1) {
        return 1;
    }
    
    if(board[startRow][startCol] == 1 && (endRow - startRow != -1 || abs(endCol - startCol) != 0)) {
        return 0;
    }
    
    if(board[startRow][startCol] == -1 && board[endRow][endCol] != 0 && abs(endCol - startCol) == 1 && abs(endRow - startRow) == 1) {
        return 1;
    }
    
    if(board[startRow][startCol] == -1 && (endRow - startRow != 1 || abs(endCol - startCol) != 0)) {
        return 0;
    }
    
    if(board[startRow][startCol] == 2 || board[startRow][startCol] == -2) {
        if(startRow != endRow && startCol != endCol) {
            return 0;
        }
        
        int i, j;
        if(startCol == endCol) {
            if(startRow < endRow) {
                for(i = startRow + 1; i < endRow; i++) {
                    if(board[i][startCol] != 0) {
                        return 0;
                    }
                }
            } else {
                for(i = endRow + 1; i < startRow; i++) {
                    if(board[i][startCol] != 0) {
                        return 0;
                    }
                }
            }
        } else {
            if(startCol < endCol) {
                for(j = startCol + 1; j < endCol; j++) {
                    if(board[startRow][j] != 0) {
                        return 0;
                    }
                }
            } else {
                for(j = endCol + 1; j < startCol; j++) {
                    if(board[startRow][j] != 0) {
                        return 0;
                    }
                }
            }
        }
    }
    
    if(board[startRow][startCol] == 3 || board[startRow][startCol] == -3) {
        if(startRow != endRow && startCol != endCol) {
            return 0;
        }
        
        if(abs(endRow - startRow) > 2 || abs(endCol - startCol) > 2) {
            return 0;
        }
        
        if(abs(endRow - startRow) == 2 || abs(endCol - startCol) == 2) {
            if(board[startRow + (endRow - startRow) / 2][startCol + (endCol - startCol) / 2] == 0) {
                return 0;
            }
        }
    }
    
    if(board[startRow][startCol] == 4 || board[startRow][startCol] == -4) {
        if(abs(endRow - startRow) != abs(endCol - startCol)) {
            return 0;
        }
        
        int i, j;
        if(endRow > startRow) {
            if(endCol > startCol) {
                for(i = startRow + 1, j = startCol + 1; i < endRow && j < endCol; i++, j++) {
                    if(board[i][j] != 0) {
                        return 0;
                    }
                }
            } else {
                for(i = startRow + 1, j = startCol - 1; i < endRow && j > endCol; i++, j--) {
                    if(board[i][j] != 0) {
                        return 0;
                    }
                }
            }
        } else {
            if(endCol > startCol) {
                for(i = startRow - 1, j = startCol + 1; i > endRow && j < endCol; i--, j++) {
                    if(board[i][j] != 0) {
                        return 0;
                    }
                }
            } else {
                for(i = startRow - 1, j = startCol - 1; i > endRow && j > endCol; i--, j--) {
                    if(board[i][j] != 0) {
                        return 0;
                    }
                }
            }
        }
    }
    
    if(board[startRow][startCol] == 5 || board[startRow][startCol] == -5) {
        if(abs(endRow - startRow) > 1 || abs(endCol - startCol) > 1) {
            return 0;
        }
    }
    
    if(board[startRow][startCol] == 6 || board[startRow][startCol] == -6) {
        if(abs(endRow - startRow) > 1 || abs(endCol - startCol) > 1) {
            return 0;
        }
        
        if(abs(endRow - startRow) == 1 && abs(endCol - startCol) == 1 && board[endRow][endCol] == 0) {
            /* en passant move */
            if(whitesTurn && endRow != 2) {
                return 0;
            } else if(!whitesTurn && endRow != 5) {
                return 0;
            }
            
            if(whitesTurn) {
                if(endCol == 0) {
                    if(board[3][endCol + 1] != -1) {
                        return 0;
                    }
                } else if(endCol == BOARD_SIZE - 1) {
                    if(board[3][endCol - 1] != -1) {
                        return 0;
                    }
                } else {
                    if(board[3][endCol + 1] != -1 && board[3][endCol - 1] != -1) {
                        return 0;
                    }
                }
            } else {
                if(endCol == 0) {
                    if(board[4][endCol + 1] != 1) {
                        return 0;
                    }
                } else if(endCol == BOARD_SIZE - 1) {
                    if(board[4][endCol - 1] != 1) {
                        return 0;
                    }
                } else {
                    if(board[4][endCol + 1] != 1 && board[4][endCol - 1] != 1) {
                        return 0;
                    }
                }
            }
        }
        
        if(abs(endRow - startRow) == 1 && abs(endCol - startCol) == 0 && board[endRow][endCol] != 0) {
            return 0;
        }
    }
    
    return 1;
}

void move(int startRow, int startCol, int endRow, int endCol) {
    if(board[startRow][startCol] == 1 && endRow == 0) {
        board[endRow][endCol] = 5;
    } else if(board[startRow][startCol] == -1 && endRow == 7) {
        board[endRow][endCol] = -5;
    } else {
        board[endRow][endCol] = board[startRow][startCol];
    }
    
    board[startRow][startCol] = 0;
    whitesTurn = !whitesTurn;
}

int main() {
    initBoard();
    printBoard();
    
    while(1) {
        int startRow, startCol, endRow, endCol;
        printf("%d's turn\n", whitesTurn ? 1 : -1);
        printf("Enter start row: ");
        scanf("%d", &startRow);
        printf("Enter start col: ");
        scanf("%d", &startCol);
        printf("Enter end row: ");
        scanf("%d", &endRow);
        printf("Enter end col: ");
        scanf("%d", &endCol);
        
        if(!isValidMove(startRow, startCol, endRow, endCol)) {
            printf("Invalid move.\n");
        } else {
            move(startRow, startCol, endRow, endCol);
            printBoard();
        }
    }
    
    return 0;
}