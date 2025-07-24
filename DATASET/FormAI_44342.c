//FormAI DATASET v1.0 Category: Checkers Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define BLACK 'B'
#define WHITE 'W'
#define EMPTY ' '
#define VALIDMOVE '-'

typedef struct {
    char board[SIZE][SIZE];
    char currentPlayer;
} Checkers;

void initBoard(Checkers *game) {
    int i, j;
    
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if((i + j) % 2 == 0 && i < 3) {
                game->board[i][j] = WHITE;
            } else if((i + j) % 2 == 0 && i > 4) {
                game->board[i][j] = BLACK;
            } else {
                game->board[i][j] = EMPTY;
            }
        }
    }
}

void printBoard(Checkers *game) {
    int i, j;
    
    printf("\n   ");
    for(i = 0; i < SIZE; i++) {
        printf("%2d", i+1);
    }
    
    printf("\n  +");
    for(i = 0; i < SIZE; i++) {
        printf("--");
    }
    printf("+\n");
    
    for(i = 0; i < SIZE; i++) {
        printf("%c |", i+65);
        for(j = 0; j < SIZE; j++) {
            printf("%c ", game->board[i][j] == EMPTY ? ' ' : game->board[i][j]);
        }
        printf("|\n");
    }
    
    printf("  +");
    for(i = 0; i < SIZE; i++) {
        printf("--");
    }
    printf("+\n");
    
    printf("Current Player: %c\n", game->currentPlayer);
}

int isMoveValid(Checkers *game, int rowFrom, int colFrom, int rowTo, int colTo) {
    int i;
    char enemy, king;
    
    if(game->currentPlayer == BLACK) {
        enemy = WHITE;
        king = 'K';
    } else {
        enemy = BLACK;
        king = 'k';
    }
    
    if(game->board[rowTo][colTo] != EMPTY) {
        return 0;
    }
    
    if(game->board[rowFrom][colFrom] == enemy || game->board[rowFrom][colFrom] == king) {
        if(rowTo == rowFrom - 1 || rowTo == rowFrom + 1) {
            if(colTo == colFrom - 1 || colTo == colFrom + 1) {
                return 1;
            }
        }
        
        if(rowTo == rowFrom - 2 && colTo == colFrom - 2) {
            if(game->board[rowFrom-1][colFrom-1] == enemy || game->board[rowFrom-1][colFrom-1] == king) {
                return 2;
            }
        }
        
        if(rowTo == rowFrom - 2 && colTo == colFrom + 2) {
            if(game->board[rowFrom-1][colFrom+1] == enemy || game->board[rowFrom-1][colFrom+1] == king) {
                return 3;
            }
        }
        
        if(rowTo == rowFrom + 2 && colTo == colFrom - 2) {
            if(game->board[rowFrom+1][colFrom-1] == enemy || game->board[rowFrom+1][colFrom-1] == king) {
                return 4;
            }
        }
        
        if(rowTo == rowFrom + 2 && colTo == colFrom + 2) {
            if(game->board[rowFrom+1][colFrom+1] == enemy || game->board[rowFrom+1][colFrom+1] == king) {
                return 5;
            }
        }
    }
    
    if(game->board[rowFrom][colFrom] == game->currentPlayer) {
        if(rowTo == rowFrom - 1 || rowTo == rowFrom + 1) {
            if(colTo == colFrom - 1 || colTo == colFrom + 1) {
                return 1;
            }
        }
        
        if(rowTo == rowFrom - 2 && colTo == colFrom - 2) {
            if(game->board[rowFrom-1][colFrom-1] == enemy) {
                return 2;
            }
        }
        
        if(rowTo == rowFrom - 2 && colTo == colFrom + 2) {
            if(game->board[rowFrom-1][colFrom+1] == enemy) {
                return 3;
            }
        }
        
        if(rowTo == rowFrom + 2 && colTo == colFrom - 2) {
            if(game->board[rowFrom+1][colFrom-1] == enemy) {
                return 4;
            }
        }
        
        if(rowTo == rowFrom + 2 && colTo == colFrom + 2) {
            if(game->board[rowFrom+1][colFrom+1] == enemy) {
                return 5;
            }
        }
    }
    
    return 0;
}

int performMove(Checkers *game, int rowFrom, int colFrom, int rowTo, int colTo) {
    int i;
    int validMove = isMoveValid(game, rowFrom, colFrom, rowTo, colTo);
    
    if(validMove) {
        game->board[rowTo][colTo] = game->board[rowFrom][colFrom];
        game->board[rowFrom][colFrom] = EMPTY;
        
        if(validMove >= 2 && validMove <= 5) {
            int enemyRow, enemyCol;
            
            if(validMove == 2) {
                enemyRow = rowFrom - 1;
                enemyCol = colFrom - 1;
            } else if(validMove == 3) {
                enemyRow = rowFrom - 1;
                enemyCol = colFrom + 1;
            } else if(validMove == 4) {
                enemyRow = rowFrom + 1;
                enemyCol = colFrom - 1;
            } else {
                enemyRow = rowFrom + 1;
                enemyCol = colFrom + 1;
            }
            
            game->board[enemyRow][enemyCol] = EMPTY;
        }
        
        if(game->currentPlayer == BLACK && rowTo == 0) {
            game->board[rowTo][colTo] = 'K';
        } else if(game->currentPlayer == WHITE && rowTo == 7) {
            game->board[rowTo][colTo] = 'k';
        }
        
        return 1;
    }
    
    return 0;
}

int hasValidMoves(Checkers *game) {
    int i, j;
    
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(game->board[i][j] == game->currentPlayer || game->board[i][j] == toupper(game->currentPlayer)) {
                if(isMoveValid(game, i, j, i-1, j-1) || isMoveValid(game, i, j, i-1, j+1)
                   || isMoveValid(game, i, j, i-2, j-2) || isMoveValid(game, i, j, i-2, j+2)
                   || isMoveValid(game, i, j, i+1, j-1) || isMoveValid(game, i, j, i+1, j+1)
                   || isMoveValid(game, i, j, i+2, j-2) || isMoveValid(game, i, j, i+2, j+2)) {
                    return 1;
                }
            }
        }
    }
    
    return 0;
}

char getWinner(Checkers *game) {
    int i, j;
    int blackPieces = 0, whitePieces = 0;
    
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(game->board[i][j] == BLACK || game->board[i][j] == 'K') {
                blackPieces++;
            } else if(game->board[i][j] == WHITE || game->board[i][j] == 'k') {
                whitePieces++;
            }
        }
    }
    
    if(blackPieces == 0) {
        return WHITE;
    } else if(whitePieces == 0) {
        return BLACK;
    }
    
    return EMPTY;
}

void switchPlayer(Checkers *game) {
    if(game->currentPlayer == BLACK) {
        game->currentPlayer = WHITE;
    } else {
        game->currentPlayer = BLACK;
    }
}

int main()
{
    int rowFrom, colFrom, rowTo, colTo;
    Checkers game;
    char winner = EMPTY;
    
    initBoard(&game);
    game.currentPlayer = BLACK;
    
    while(winner == EMPTY && hasValidMoves(&game)) {
        printBoard(&game);
        
        printf("\nEnter move in the format 'rowFrom colFrom-rowTo colTo' (e.g. A3-B4): ");
        scanf("%c%d-%c%d", &rowFrom, &colFrom, &rowTo, &colTo);
        fflush(stdin);
        
        if(performMove(&game, rowFrom-65, colFrom-1, rowTo-65, colTo-1)) {
            switchPlayer(&game);
        } else {
            printf("\nInvalid Move");
        }
        
        winner = getWinner(&game);
    }
    
    printBoard(&game);
    
    if(winner == EMPTY) {
        printf("\nDraw");
    } else {
        printf("\n%c wins!", winner);
    }
    
    return 0;
}