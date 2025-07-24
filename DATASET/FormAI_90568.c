//FormAI DATASET v1.0 Category: Checkers Game ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

#define SIZE 8 //Size of the checkers board

/* Function to print the board */
void printboard(int board[][SIZE]){
    printf("\n---------------------------------\n");
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            printf("| %d ",board[i][j]);
        }
        printf("|\n---------------------------------\n");
    }
}

/* Function to initialize the board */
void initializeboard(int board[][SIZE]){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(i<3 && (i+j)%2==0)
                board[i][j]=1; //Player 1 will have pieces marked as 1
            else if(i>4 && (i+j)%2==0)
                board[i][j]=-1; //Player 2 will have pieces marked as -1
            else
                board[i][j]=0; //Spaces with 0 denotes empty spots
        }
    }
}

/* Function to move the pieces */
void movedraw(int board[][SIZE],int x,int y,int new_x,int new_y,int player){
    board[new_x][new_y]=player; //Update new position with player's piece
    board[x][y]=0; //Remove piece from old position
}

/* Function to check if a move is valid */
int validmove(int board[][SIZE], int x, int y, int new_x, int new_y, int player){

    if(board[x][y]!=player || board[new_x][new_y]!=0)
        return 0; //Return false if piece does not belong to the player or the new position is not empty

    int diff_x=new_x-x;
    int diff_y=new_y-y;
    if(abs(diff_x)!=abs(diff_y))
        return 0; //Return false if the move is not diagonal

    int num_moves=abs(diff_x);
    int direction_x=diff_x/num_moves;
    int direction_y=diff_y/num_moves;

    for(int i=1;i<num_moves;i++){
        if(board[x+i*direction_x][y+i*direction_y]!=0)
            return 0; //Return false if there is a piece blocking the path
    }

    if(num_moves>2)
        return 0; //Return false if there are more than two jumps

    if(num_moves==2){
        int middle_x=(x+new_x)/2;
        int middle_y=(y+new_y)/2;
        if(board[middle_x][middle_y]==0 || board[middle_x][middle_y]==player)
            return 0; //Return false if there is no piece in between or the piece in the middle belongs to the player
        else
            board[middle_x][middle_y]=0; //Remove enemy's piece
    }

    return 1; //The move is valid
}

/* Function to check if there are still pieces of both players on the board */
int gameover(int board[][SIZE]){
    int player1=0,player2=0;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(board[i][j]==1)
                player1++;
            else if(board[i][j]==-1)
                player2++;
            if(player1>0 && player2>0)
                return 0; //Return false if both players have at least one piece left
        }
    }
    return 1; //Return true if one of the players has no pieces left
}

int main(){
    int board[SIZE][SIZE];
    int player=1;
    int x,y,new_x,new_y;
    int valid;

    initializeboard(board);

    printf("\nWELCOME TO THE CHECKERS GAME!\n");
    printf("Player 1 will be represented by pieces marked with number 1\n");
    printf("Player 2 will be represented by pieces marked with number -1\n");
    printf("Empty spaces will be represented by number 0\n");
    printf("\nHere is the initial state of the board:\n");
    printboard(board);

    while(!gameover(board)){
        printf("\nPLAYER %d's TURN\n",player);
        printf("Enter the position of the piece to be moved (x y): ");
        scanf("%d %d",&x,&y);
        printf("Enter the new position of the piece (x y): ");
        scanf("%d %d",&new_x,&new_y);

        valid=validmove(board,x,y,new_x,new_y,player);

        if(valid){
            movedraw(board,x,y,new_x,new_y,player);
            printf("\nThe move is valid!\n");
            printboard(board);
            player=-player; //Switch players
        }
        else{
            printf("\nThe move is invalid!\n");
        }
    }

    printf("\nGAME OVER!\n");
    if(player==1)
        printf("Congratulations Player 2 wins!\n");
    else
        printf("Congratulations Player 1 wins!\n");

    return 0;
}