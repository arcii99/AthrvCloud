//FormAI DATASET v1.0 Category: Game of Life ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 20
#define COLS 60

void initializeBoard(int board[ROWS][COLS]){
    int i,j;
    srand(time(NULL));
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            board[i][j]=rand()%2;
        }
    }
}

void display(int board[ROWS][COLS]){
    int i,j;
    printf("\033[2J"); //clears the screen
    printf("\033[%d;%dH", 0, 0); //sets the cursor to (0,0)
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            if(board[i][j]==0)
                printf(".");
            else
                printf("*");
        }
        printf("\n");
    }
}

int numNeighbors(int board[ROWS][COLS], int i, int j){
    int count = 0;
    int rowUp = (i-1+ROWS) % ROWS;
    int rowDown = (i+1) % ROWS;
    int colLeft = (j-1+COLS) % COLS;
    int colRight = (j+1) % COLS;
    count += board[rowUp][colLeft] + board[rowUp][j] + board[rowUp][colRight];
    count += board[i][colLeft] + board[i][colRight];
    count += board[rowDown][colLeft] + board[rowDown][j] + board[rowDown][colRight];
    return count;
}

void update(int board[ROWS][COLS]){
    int newBoard[ROWS][COLS];
    int i,j,neighbors;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            neighbors=numNeighbors(board, i, j);
            if(board[i][j]==1){
                if(neighbors < 2 || neighbors > 3)
                    newBoard[i][j] = 0;
                else
                    newBoard[i][j] = 1;
            }
            else{
                if(neighbors==3)
                    newBoard[i][j] = 1;
                else
                    newBoard[i][j] = 0;
            }
        }
    }
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            board[i][j]=newBoard[i][j];
        }
    }
}

int main(){
    int board[ROWS][COLS];
    initializeBoard(board);
    while(1){
        display(board);
        update(board);
    }
    return 0;
}