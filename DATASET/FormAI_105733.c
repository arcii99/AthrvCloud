//FormAI DATASET v1.0 Category: Checkers Game ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>

#define BOARD_SIZE 8
#define EMPTY 0
#define BLACK 1
#define WHITE 2
#define KING 4

// function to initialize the board
void initialize_board(int board[][BOARD_SIZE]){
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            // setting empty squares
            board[i][j]=EMPTY;
        }
    }
    // setting black pieces
    for(int i=0;i<3;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            if((i+j)%2==0){
                board[i][j]=BLACK;
            }
        }
    }
    // setting white pieces
    for(int i=BOARD_SIZE-3;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            if((i+j)%2==0){
                board[i][j]=WHITE;
            }
        }
    }
}

// function to display the board
void display_board(int board[][BOARD_SIZE]){
    printf("\n   ");
    for(int i=0;i<BOARD_SIZE;i++){
        printf("%d ",i);
    }
    printf("\n\n");
    for(int i=0;i<BOARD_SIZE;i++){
        printf("%d  ",i);
        for(int j=0;j<BOARD_SIZE;j++){
            switch(board[i][j]){
                case EMPTY: printf(". "); break;
                case BLACK: printf("b "); break;
                case WHITE: printf("w "); break;
                case BLACK|KING: printf("B "); break;
                case WHITE|KING: printf("W "); break;
            }
        }
        printf(" %d\n",i);
    }
    printf("\n   ");
    for(int i=0;i<BOARD_SIZE;i++){
        printf("%d ",i);
    }
    printf("\n");
}

// function to make a move
void make_move(int board[][BOARD_SIZE], int x1, int y1, int x2, int y2){
    board[x2][y2]=board[x1][y1];
    board[x1][y1]=EMPTY;
    // checking if the piece has reached the other end to become a king
    if(x2==0 && board[x2][y2]==BLACK){
        board[x2][y2]=BLACK|KING;
    }
    if(x2==BOARD_SIZE-1 && board[x2][y2]==WHITE){
        board[x2][y2]=WHITE|KING;
    }
}

// function to check if the move is valid
int is_valid_move(int board[][BOARD_SIZE], int player, int x1, int y1, int x2, int y2){

    // check if the destination spot is not an empty space
    if(board[x2][y2]!=EMPTY){
        return 0;
    }

    // check if the piece belongs to the correct player
    if((player==BLACK && board[x1][y1]!=BLACK && board[x1][y1]!=BLACK|KING) ||
            (player==WHITE && board[x1][y1]!=WHITE && board[x1][y1]!=WHITE|KING)){
        return 0;
    }

    // check if the move is diagonal and not a jump
    if(abs(x2-x1)!=abs(y2-y1) || abs(x2-x1)>2){
        return 0;
    }

    // check if the move is not a jump and the destination is empty
    if(abs(x2-x1)==1 && board[x2][y2]!=EMPTY){
        return 0;
    }

    // check if the move is a jump
    if(abs(x2-x1)==2){
        // check if the piece being jumped over belongs to the other player
        int x_mid=(x1+x2)/2;
        int y_mid=(y1+y2)/2;
        if(player==BLACK && (board[x_mid][y_mid]!=WHITE && board[x_mid][y_mid]!=WHITE|KING)){
            return 0;
        }
        if(player==WHITE && (board[x_mid][y_mid]!=BLACK && board[x_mid][y_mid]!=BLACK|KING)){
            return 0;
        }
    }

    // check if the piece has become a king and it moves backwards
    if(board[x1][y1]==BLACK && x2>x1){
        return 0;
    }
    if(board[x1][y1]==WHITE && x2<x1){
        return 0;
    }

    return 1;
}

// function to check if a player can make any valid moves
int can_make_any_moves(int board[][BOARD_SIZE], int player){
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            if(player==BLACK && (board[i][j]==BLACK || board[i][j]==BLACK|KING)){
                for(int k=-2;k<=2;k++){
                    for(int l=-2;l<=2;l++){
                        if(k!=0 && l!=0 && is_valid_move(board,player,i,j,i+k,j+l)){
                            return 1;
                        }
                    }
                }
            }
            if(player==WHITE && (board[i][j]==WHITE || board[i][j]==WHITE|KING)){
                for(int k=-2;k<=2;k++){
                    for(int l=-2;l<=2;l++){
                        if(k!=0 && l!=0 && is_valid_move(board,player,i,j,i+k,j+l)){
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

// function to make the computer move
void computer_move(int board[][BOARD_SIZE]){
    int x1,y1,x2,y2;
    int valid_move=0;
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            if(board[i][j]==WHITE || board[i][j]==WHITE|KING){
                for(int k=-2;k<=2;k++){
                    for(int l=-2;l<=2;l++){
                        if(k!=0 && l!=0 && is_valid_move(board,WHITE,i,j,i+k,j+l)){
                            x1=i;
                            y1=j;
                            x2=i+k;
                            y2=j+l;
                            valid_move=1;
                            break;
                        }
                    }
                    if(valid_move){
                        break;
                    }
                }
            }
            if(valid_move){
                break;
            }
        }
        if(valid_move){
            break;
        }
    }
    printf("\nComputer makes move: %d,%d to %d,%d\n",x1,y1,x2,y2);
    make_move(board,x1,y1,x2,y2);
}

int main(){
    int board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    display_board(board);
    int moves=0;
    while(1){
        // player's turn
        int x1,y1,x2,y2;
        printf("\nPlayer's turn (black):\n");
        do{
            printf("Enter coordinates of piece to move (row,col): ");
            scanf("%d,%d",&x1,&y1);
            printf("Enter coordinates of destination (row,col): ");
            scanf("%d,%d",&x2,&y2);
        }while(!is_valid_move(board,BLACK,x1,y1,x2,y2));
        make_move(board,x1,y1,x2,y2);
        moves++;
        display_board(board);
        if(can_make_any_moves(board,WHITE)==0){
            printf("\nPlayer wins!\n");
            break;
        }
        // computer's turn
        printf("\nComputer's turn (white):\n");
        computer_move(board);
        moves++;
        display_board(board);
        if(can_make_any_moves(board,BLACK)==0){
            printf("\nComputer wins!\n");
            break;
        }
    }
    printf("\nTotal moves played: %d\n",moves);
    return 0;
}