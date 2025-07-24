//FormAI DATASET v1.0 Category: Chess engine ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLACK 0
#define WHITE 1

#define KING 0
#define QUEEN 1
#define BISHOP 2
#define KNIGHT 3
#define ROOK 4
#define PAWN 5

char board[8][8]; // Global board array to hold current state of the chess board

void printBoard() {
    printf("\n---------------\n");
    for(int i=0;i<8;i++) {
        printf("|");
        for(int j=0;j<8;j++) {
            printf("%c|",board[i][j]);
        }
        printf("\n---------------\n");
    }
}

void initializeBoard() {
    // Initialize black pieces
    board[0][0]='r';
    board[0][1]='n';
    board[0][2]='b';
    board[0][3]='q';
    board[0][4]='k';
    board[0][5]='b';
    board[0][6]='n';
    board[0][7]='r';
    for(int i=0;i<8;i++) {
        board[1][i]='p';
    }
    // Initialize white pieces
    board[7][0]='R';
    board[7][1]='N';
    board[7][2]='B';
    board[7][3]='Q';
    board[7][4]='K';
    board[7][5]='B';
    board[7][6]='N';
    board[7][7]='R';
    for(int i=0;i<8;i++) {
        board[6][i]='P';
    }
    // Initialize empty squares
    for(int i=2;i<6;i++) {
        for(int j=0;j<8;j++) {
            board[i][j]=' ';
        }
    }
}

int getPieceType(char piece) {
    if(piece=='k' || piece=='K') {
        return KING;
    } else if(piece=='q' || piece=='Q') {
        return QUEEN;
    } else if(piece=='b' || piece=='B') {
        return BISHOP;
    } else if(piece=='n' || piece=='N') {
        return KNIGHT;
    } else if(piece=='r' || piece=='R') {
        return ROOK;
    } else if(piece=='p' || piece=='P') {
        return PAWN;
    } else {
        return -1;
    }
}

int isPiece(char c) {
    return (c>='a' && c<='z') || (c>='A' && c<='Z');
}

int isLower(char c) {
    return (c>='a' && c<='z');
}

int isUpper(char c) {
    return (c>='A' && c<='Z');
}

int isDifferentColor(char a, char b) {
    if(isLower(a) && isUpper(b)) {
        return 1;
    } else if(isUpper(a) && isLower(b)) {
        return 1;
    } else {
        return 0;
    }
}

int isMoveValid(int from_x, int from_y, int to_x, int to_y, int color) {
    // Check if the move is within bounds of the board
    if(from_x<0 || from_x>7 || from_y<0 || from_y>7 || to_x<0 || to_x>7 || to_y<0 || to_y>7) {
        return 0;
    }
    // Check if the piece at (from_x, from_y) is valid
    if(!isPiece(board[from_x][from_y])) {
        return 0;
    }
    // Check if the piece at (from_x, from_y) is of the correct color
    if(isLower(board[from_x][from_y]) && color==WHITE) {
        return 0;
    }
    if(isUpper(board[from_x][from_y]) && color==BLACK) {
        return 0;
    }
    // Check if the piece at (to_x, to_y) is of a different color than the piece at (from_x, from_y)
    if(isPiece(board[to_x][to_y]) && !isDifferentColor(board[from_x][from_y],board[to_x][to_y])) {
        return 0;
    }
    // Get the type of piece at (from_x, from_y)
    int pieceType=getPieceType(board[from_x][from_y]);
    switch(pieceType) {
        case KING:
            // Check if the move is valid for the king
            if(to_x-from_x<=1 && to_x-from_x>=-1 && to_y-from_y<=1 && to_y-from_y>=-1) {
                return 1;
            } else {
                return 0;
            }
            break;
        case QUEEN:
            // Check if the move is valid for the queen
            if(from_x==to_x || from_y==to_y || abs(to_x-from_x)==abs(to_y-from_y)) {
                return 1;
            } else {
                return 0;
            }
            break;
        case BISHOP:
            // Check if the move is valid for the bishop
            if(abs(to_x-from_x)==abs(to_y-from_y)) {
                return 1;
            } else {
                return 0;
            }
            break;
        case KNIGHT:
            // Check if the move is valid for the knight
            if((abs(to_x-from_x)==1 && abs(to_y-from_y)==2) || (abs(to_x-from_x)==2 && abs(to_y-from_y)==1)) {
                return 1;
            } else {
                return 0;
            }
            break;
        case ROOK:
            // Check if the move is valid for the rook
            if(from_x==to_x || from_y==to_y) {
                return 1;
            } else {
                return 0;
            }
            break;
        case PAWN:
            // Check if the move is valid for the pawn
            if(color==WHITE && from_x==1 && to_x==3 && from_y==to_y && !isPiece(board[2][from_y]) && !isPiece(board[3][from_y])) {
                return 1;
            }
            if(color==BLACK && from_x==6 && to_x==4 && from_y==to_y && !isPiece(board[5][from_y]) && !isPiece(board[4][from_y])) {
                return 1;
            }
            if(color==WHITE && to_x==from_x+1 && from_y==to_y && !isPiece(board[to_x][to_y])) {
                return 1;
            }
            if(color==BLACK && to_x==from_x-1 && from_y==to_y && !isPiece(board[to_x][to_y])) {
                return 1;
            }
            if(color==WHITE && to_x==from_x+1 && abs(to_y-from_y)==1 && isDifferentColor(board[from_x][from_y],board[to_x][to_y])) {
                return 1;
            }
            if(color==BLACK && to_x==from_x-1 && abs(to_y-from_y)==1 && isDifferentColor(board[from_x][from_y],board[to_x][to_y])) {
                return 1;
            }
            return 0;
            break;
        default:
            return 0;
    }
}

int makeMove(int from_x, int from_y, int to_x, int to_y) {
    if(isMoveValid(from_x,from_y,to_x,to_y,0)) { // Check if move is valid for black
        board[to_x][to_y]=board[from_x][from_y];
        board[from_x][from_y]=' ';
        return 1;
    } else if(isMoveValid(from_x,from_y,to_x,to_y,1)) { // Check if move is valid for white
        board[to_x][to_y]=board[from_x][from_y];
        board[from_x][from_y]=' ';
        return 1;
    } else {
        return 0;
    }
}

int main() {
    initializeBoard();
    printBoard();
    makeMove(1,0,3,0);
    printBoard();
    makeMove(6,0,4,0);
    printBoard();
    makeMove(0,1,2,0);
    printBoard();
    makeMove(7,1,5,0);
    printBoard();
    return 0;
}