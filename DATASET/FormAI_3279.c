//FormAI DATASET v1.0 Category: Checkers Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

int board[SIZE][SIZE] = {0};
//initializing the board with zeros

void printBoard() {
    //function to print the board
    printf("  0 1 2 3 4 5 6 7 \n");
    for(int i=0; i<SIZE; i++) {
        printf("%d", i);
        for(int j=0; j<SIZE; j++) {
            if(board[i][j]==0) printf(" .");
            else if(board[i][j]==1) printf(" r");
            else if(board[i][j]==-1) printf(" b");
        }
        printf("\n");
    }
}

int movePiece(int x, int y, int newX, int newY, int player) {
    //function to move a piece from (x,y) position to (newX,newY) position
    if(board[x][y]==0) return 0; //if there is no piece at (x,y) then return 0
    if(newX<0 || newY<0 || newX>=SIZE || newY>=SIZE) return 0; //if the new position is outside the board then return 0

    int dx = newX-x;
    int dy = newY-y;
    if(abs(dx) != abs(dy)) return 0; //if the move is not diagonal then return 0
    
    int moveDir = dy/abs(dy);
    
    if(abs(dx)==1) { //if it's a normal move
        if(board[newX][newY]==0) {
            board[newX][newY] = player;
            board[x][y] = 0;
            return 1; //successful move
        }
        else return 0; //if there is a piece in the new position then return 0
    }
    else if(abs(dx)==2) { //if it's a jump move
        if(board[newX][newY]!=0) return 0; //if there is a piece in the new position then return 0
        else if(board[x+moveDir][y+moveDir]==-player) {
            board[newX][newY] = player;
            board[x][y] = 0;
            board[x+moveDir][y+moveDir] = 0;
            return 2; //successful jump move
        }
        else return 0; //if there is no opponent piece to jump over then return 0
    }
    else return 0; //if the move is not 1 step or 2 steps then return 0
}

int hasWon(int player) {
    //function to check if the given player has won
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(board[i][j]==-player) return 0; //if there is still opponent piece then the player has not won yet
        }
    }
    return 1; //if there is no opponent piece then the player has won
}

int main() {
    int player = 1; //player 1: red, player -1: black
    int moveType;
    int moveResult;
    int movesCount = 0;
    while(1) {
        printf("\n\n");
        printBoard();
        if(player==1) printf("\nPlayer 1 (RED), ");
        else printf("\nPlayer 2 (BLACK), ");
        printf("Enter Move (ex. 0,0 1,1): ");
        int x,y,newX,newY;
        scanf("%d,%d %d,%d", &x, &y, &newX, &newY);
        moveResult = movePiece(x,y,newX,newY,player);
        if(moveResult==0) printf("Invalid Move");
        else {
            movesCount++;
            if(moveResult==2) printf("Jump Move");            
            if(hasWon(player)) {
                printBoard(); //print the final board state
                printf("\n\nPlayer %d (", player==1? 1:-1);
                printf(player==1? "RED":"BLACK");
                printf(") has won in %d moves", movesCount);
                break; //exit the loop and end the game
            }
            else {
                player = -player; //switch to the other player's turn
            }
        }
    }
    return 0;
}