//FormAI DATASET v1.0 Category: Game of Life ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void print_board(int board[ROWS][COLS]){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(board[i][j] == 0){
                printf(" ");
            }
            else{
                printf("#");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int board[ROWS][COLS],int x,int y){
    int count=0;
    for(int i=x-1;i<=x+1;i++){
        for(int j=y-1;j<=y+1;j++){
            if((i==x && j==y)||i<0||j<0||i==ROWS||j==COLS){
                continue;
            }
            else if(board[i][j]==1){
                count++;
            }
        }
    }
    return count;
}

void simulate(int board[ROWS][COLS]){
    int new_board[ROWS][COLS];
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            int neighbors=count_neighbors(board,i,j);
            if(board[i][j]==1){
                if(neighbors<2 || neighbors>3){
                    new_board[i][j]=0;
                }
                else{
                    new_board[i][j]=1;
                }
            }
            else{
                if(neighbors==3){
                    new_board[i][j]=1;
                }
                else{
                    new_board[i][j]=0;
                }
            }
        }
    }
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            board[i][j]=new_board[i][j];
        }
    }
}

int main(){
    srand(time(NULL));
    int board[ROWS][COLS];
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            board[i][j] = rand()%2;
        }
    }

    while(1){
        system("clear"); // for linux/mac
        // system("cls"); // for windows
        print_board(board);
        simulate(board);
        getchar();
    }

    return 0;
}