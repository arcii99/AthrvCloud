//FormAI DATASET v1.0 Category: Chess engine ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

/* Definition of Chess Pieces */
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

/* Definition of Chess Board and Pieces */
typedef struct ChessPiece {
    int type;
    char color;
} ChessPiece;

typedef struct ChessBoard {
    ChessPiece board[8][8]; 
    char turn; 
} ChessBoard;

/* Function to initialize Chess Board */
void initializeBoard(ChessBoard *ptr) {
    int i, j;
    
    /* Initialization of Board */
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            ptr->board[i][j].type = 0;
            ptr->board[i][j].color = ' ';
        }
    }
    
    /* Initialization of White Pieces */
    ptr->board[0][0].type = ROOK;
    ptr->board[0][0].color = 'W';
    ptr->board[0][1].type = KNIGHT;
    ptr->board[0][1].color = 'W';
    ptr->board[0][2].type = BISHOP;
    ptr->board[0][2].color = 'W';
    ptr->board[0][3].type = QUEEN;
    ptr->board[0][3].color = 'W';
    ptr->board[0][4].type = KING;
    ptr->board[0][4].color = 'W';
    ptr->board[0][5].type = BISHOP;
    ptr->board[0][5].color = 'W';
    ptr->board[0][6].type = KNIGHT;
    ptr->board[0][6].color = 'W';
    ptr->board[0][7].type = ROOK;
    ptr->board[0][7].color = 'W';
    for (i = 0; i < 8; i++) {
        ptr->board[1][i].type = PAWN;
        ptr->board[1][i].color = 'W';
    }
    
    /* Initialization of Black Pieces */
    ptr->board[7][0].type = ROOK;
    ptr->board[7][0].color = 'B';
    ptr->board[7][1].type = KNIGHT;
    ptr->board[7][1].color = 'B';
    ptr->board[7][2].type = BISHOP;
    ptr->board[7][2].color = 'B';
    ptr->board[7][3].type = QUEEN;
    ptr->board[7][3].color = 'B';
    ptr->board[7][4].type = KING;
    ptr->board[7][4].color = 'B';
    ptr->board[7][5].type = BISHOP;
    ptr->board[7][5].color = 'B';
    ptr->board[7][6].type = KNIGHT;
    ptr->board[7][6].color = 'B';
    ptr->board[7][7].type = ROOK;
    ptr->board[7][7].color = 'B';
    for (i = 0; i < 8; i++) {
        ptr->board[6][i].type = PAWN;
        ptr->board[6][i].color = 'B';
    }
    
    /* Initialization of Turn */
    ptr->turn = 'W';
}

/* Print Board Function */
void printBoard(ChessBoard ptr) {
    int i, j;
    
    /* Print Board to Output Console */
    printf("-------------------------\n");
    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++) {
            printf("| %c%d ", ptr.board[i][j].color, ptr.board[i][j].type);
        }
        printf("|\n-------------------------\n");
    }
    printf("Turn: %c\n", ptr.turn);
}

/* Function to check if the move is valid */
int isValidMove(int xi,int yi,int xf,int yf) {

    /* Check if the move is within board limits */
    if(xi<0 || yi<0 || xf>7 || yf>7) {
        return 0;
    }
    if(xi==xf && yi==yf) {
        return 0;
    }
    return 1;
}

/* Function to check if the move is possible */
int isPossibleMove(ChessBoard *ptr, int xi,int yi,int xf,int yf) {
    
    /* Check if the selected position has a piece of the player */
    if(ptr->board[xi][yi].color != ptr->turn) {
        return 0;
    }
    
    /* Check if the final position doesn't have a player piece */
    if(ptr->board[xf][yf].color == ptr->turn) {
        return 0;
    }
    
    /* Check if the move is valid for the selected piece */
    switch(ptr->board[xi][yi].type) {
        case PAWN:
            
            /* Check forward move */
            if(ptr->board[xi][yi].color == 'W') {
                if(xf==xi-1 && yf==yi && ptr->board[xf][yf].color==' ') {
                    return 1;
                } else if(xf==xi-2 && yf==yi && ptr->board[xf][yf].color==' '  && xf==6) {
                    return 1;
                } else {
                    return 0;
                }
            } else if(ptr->board[xi][yi].color == 'B') {
                if(xf==xi+1 && yf==yi && ptr->board[xf][yf].color==' ') {
                    return 1;
                } else if(xf==xi+2 && yf==yi && ptr->board[xf][yf].color==' ' && xf==1) {
                    return 1;
                } else {
                    return 0;
                }
            }
    
        case KNIGHT:
            if((xf==xi-2 && yf==yi+1) || (xf==xi-2 && yf==yi-1) ||
               (xf==xi+2 && yf==yi+1) || (xf==xi+2 && yf==yi-1) ||
               (xf==xi-1 && yf==yi+2) || (xf==xi+1 && yf==yi+2) ||
               (xf==xi-1 && yf==yi-2) || (xf==xi+1 && yf==yi-2)) {
                   return 1;
               } else {
                   return 0;
               }
    
        case BISHOP:
            if(xf==xi || yf==yi) {
                return 0;
            } else if(abs(xf-xi) != abs(yf-yi)) {
                return 0;
            } else {
                int x, y;
                if(xf < xi) x = -1; else x = 1;
                if(yf < yi) y = -1; else y = 1;
                int i;
                for(i = 1; i < abs(xf-xi); i++) {
                    if(ptr->board[xi+i*x][yi+i*y].type != 0) {
                        return 0;
                    }
                }
                return 1;
            }
    
        case ROOK:
            if(xf==xi || yf==yi) {
                int i;
                if(xf==xi) {
                    for(i = 1; i < abs(yf-yi); i++) {
                        if(ptr->board[xi][yi+i*(yf-yi)/abs(yf-yi)].type != 0) {
                            return 0;
                        }
                    }
                    return 1;
                } else if(yf==yi) {
                    for(i = 1; i < abs(xf-xi); i++) {
                        if(ptr->board[xi+i*(xf-xi)/abs(xf-xi)][yi].type != 0) {
                            return 0;
                        }
                    }
                    return 1;
                }
            } else {
                return 0;
            }
    
        case QUEEN:
            if(xf==xi || yf==yi) { /* Rook Move */
                int i;
                if(xf==xi) {
                    for(i = 1; i < abs(yf-yi); i++) {
                        if(ptr->board[xi][yi+i*(yf-yi)/abs(yf-yi)].type != 0) {
                            return 0;
                        }
                    }
                    return 1;
                } else if(yf==yi) {
                    for(i = 1; i < abs(xf-xi); i++) {
                        if(ptr->board[xi+i*(xf-xi)/abs(xf-xi)][yi].type != 0) {
                            return 0;
                        }
                    }
                    return 1;
                }
            } else if(abs(xf-xi) == abs(yf-yi)) { /* Bishop Move */
                int x, y;
                if(xf < xi) x = -1; else x = 1;
                if(yf < yi) y = -1; else y = 1;
                int i;
                for(i = 1; i < abs(xf-xi); i++) {
                    if(ptr->board[xi+i*x][yi+i*y].type != 0) {
                        return 0;
                    }
                }
                return 1;
            } else {
                return 0;
            }
    
        case KING:
            if(abs(xf-xi)<=1 && abs(yf-yi)<=1) {
                return 1;
            } else {
                return 0;
            }
    }
}

/* Move Function */
void move(ChessBoard *ptr,int xi,int yi,int xf,int yf){
    
    /* Check if the move is valid */
    if(!isValidMove(xi,yi,xf,yf)) {
        printf("Invalid Move! Try Again.\n");
        return;
    }
    
    /* Check if the move is possible */
    if(!isPossibleMove(ptr,xi,yi,xf,yf)) {
        printf("Invalid Move! Try Again.\n");
        return;
    }
    
    /* Move the Piece */
    ptr->board[xf][yf] = ptr->board[xi][yi];
    ptr->board[xi][yi].type = 0;
    ptr->board[xi][yi].color = ' ';
    
    /* Change the Turn */
    if(ptr->turn == 'W') ptr->turn = 'B';
    else ptr->turn = 'W';
}

int main() {
    ChessBoard board;
    initializeBoard(&board);
    printBoard(board);
    move(&board, 6, 0, 4, 0);
    printBoard(board);
    move(&board, 1, 4, 3, 4);
    printBoard(board);
    move(&board, 7, 6, 5, 5);
    printBoard(board);
    move(&board, 6, 1, 5, 1);
    printBoard(board);
    return 0;
}