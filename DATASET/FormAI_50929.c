//FormAI DATASET v1.0 Category: Game of Life ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 20
#define COLS 20

//function to print the current state of the board
void print_board(int board[ROWS][COLS]){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            if(board[i][j]==1){
                printf("* ");
            }
            else{
                printf(". ");
            }
        }
        printf("\n");
    }
}

//function to update the board based on the rules of the game
void update_board(int board[ROWS][COLS]){
    int next_board[ROWS][COLS];

    //initialize the next board
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            next_board[i][j]=0;
        }
    }

    //check each cell and update the next board accordingly
    for(int i=1;i<ROWS-1;i++){
        for(int j=1;j<COLS-1;j++){
            int count=0;
            for(int k=-1;k<=1;k++){
                for(int l=-1;l<=1;l++){
                    count+=board[i+k][j+l];
                }
            }
            count-=board[i][j];
            if(board[i][j]==1 && count<2){
                next_board[i][j]=0;
            }
            else if(board[i][j]==1 && (count==2 || count==3)){
                next_board[i][j]=1;
            }
            else if(board[i][j]==1 && count>3){
                next_board[i][j]=0;
            }
            else if(board[i][j]==0 && count==3){
                next_board[i][j]=1;
            }
        }
    }

    //copy the next board to the current board
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            board[i][j]=next_board[i][j];
        }
    }
}

int main(){
    int board[ROWS][COLS];

    //initialize the board with random values
    srand(time(NULL));
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            board[i][j]=rand()%2;
        }
    }

    //run the game for 20 generations
    for(int i=0;i<20;i++){
        printf("Generation %d:\n",i+1);
        print_board(board);
        printf("\n");
        update_board(board);
    }

    return 0;
}