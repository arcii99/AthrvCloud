//FormAI DATASET v1.0 Category: Chess engine ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define WHITE 1
#define BLACK 0

// Chess board structure
char board[8][8]={
    {'R','N','B','Q','K','B','N','R'},
    {'P','P','P','P','P','P','P','P'},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {'p','p','p','p','p','p','p','p'},
    {'r','n','b','q','k','b','n','r'},
};

int turn = WHITE;
int inplay = 1;

// Function to print the chess board
void printBoard(){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

// Function to get the next move from the player
void getNextMove(){
    char move[5];
    printf("Enter your move: ");
    scanf("%s",move);
    int x1 = move[1] - '0' - 1;
    int y1 = move[0] - 'a';
    int x2 = move[3] - '0' - 1;
    int y2 = move[2] - 'a';
    
    if(board[x1][y1] != ' ' && ((turn == WHITE && islower(board[x1][y1])) || (turn == BLACK && isupper(board[x1][y1])))){
        printf("Invalid move\n");
        getNextMove();
    }
    else{
        board[x2][y2] = board[x1][y1];
        board[x1][y1] = ' ';
    }
}

// Function to check if the king is in check
int isKingInCheck(){
    int kingx, kingy;
    char king = (turn == WHITE) ? 'k' : 'K';
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(board[i][j] == king){
                kingx = i;
                kingy = j;
            }
        }
    }
    // pawns
    int dir = (turn == WHITE) ? 1 : -1;
    if(kingx+dir >= 0 && kingx+dir < 8){
        if(kingy+1 < 8 && board[kingx+dir][kingy+1] == 'P' && turn == WHITE){
            return 1;
        }
        if(kingy-1 >= 0 && board[kingx+dir][kingy-1] == 'P' && turn == WHITE){
            return 1;
        }
        if(kingy+1 < 8 && board[kingx+dir][kingy+1] == 'p' && turn == BLACK){
            return 1;
        }
        if(kingy-1 >= 0 && board[kingx+dir][kingy-1] == 'p' && turn == BLACK){
            return 1;
        }
    }
    // knights
    int dirx[8] = {2,2,1,1,-1,-1,-2,-2};
    int diry[8] = {1,-1,2,-2,2,-2,1,-1};
    for(int i=0; i<8; i++){
        int x = kingx + dirx[i];
        int y = kingy + diry[i];
        if(x >= 0 && x < 8 && y >= 0 && y < 8 && (board[x][y] == 'N' || board[x][y] == 'n')){
            return 1;
        }
    }
    // rook and queen
    int dirxx[4] = {1,0,-1,0};
    int diryy[4] = {0,1,0,-1};
    for(int i=0; i<4; i++){
        int x = kingx;
        int y = kingy;
        while(x+dirxx[i] >= 0 && x+dirxx[i] < 8 && y+diryy[i] >= 0 && y+diryy[i] < 8){
            x += dirxx[i];
            y += diryy[i];
            if(board[x][y] == ' '){
                continue;
            }
            if((board[x][y] == 'R' || board[x][y] == 'Q') && turn == WHITE){
                return 1;
            }
            if((board[x][y] == 'r' || board[x][y] == 'q') && turn == BLACK){
                return 1;
            }
            break;
        }
    }
    // bishop and queen
    int dirxxx[4] = {1,1,-1,-1};
    int diryyy[4] = {1,-1,1,-1};
    for(int i=0; i<4; i++){
        int x = kingx;
        int y = kingy;
        while(x+dirxxx[i] >= 0 && x+dirxxx[i] < 8 && y+diryyy[i] >= 0 && y+diryyy[i] < 8){
            x += dirxxx[i];
            y += diryyy[i];
            if(board[x][y] == ' '){
                continue;
            }
            if((board[x][y] == 'B' || board[x][y] == 'Q') && turn == WHITE){
                return 1;
            }
            if((board[x][y] == 'b' || board[x][y] == 'q') && turn == BLACK){
                return 1;
            }
            break;
        }
    }
    // king
    int dirxxxx[8] = {1,1,0,-1,-1,-1,0,1};
    int diryyyy[8] = {0,1,1,1,0,-1,-1,-1};
    for(int i=0; i<8; i++){
        int x = kingx + dirxxxx[i];
        int y = kingy + diryyyy[i];
        if(x >= 0 && x < 8 && y >= 0 && y < 8 && (board[x][y] == 'K' || board[x][y] == 'k')){
            return 1;
        }
    }
    return 0;
}

int main(){
    printBoard();
    while(inplay){
        getNextMove();
        if(isKingInCheck() == 1){
            printf("Your king is in check!\n");
        }
        printBoard();
        turn = !turn;
    }
    return 0;
}