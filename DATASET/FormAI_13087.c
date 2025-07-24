//FormAI DATASET v1.0 Category: Chess AI ; Style: Romeo and Juliet
#include<stdio.h>

int board[8][8] = {
    {-1,-2,-3,-4,-5,-3,-2,-1},
    {-6,-6,-6,-6,-6,-6,-6,-6},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {6,6,6,6,6,6,6,6},
    {1,2,3,4,5,3,2,1}
};

void print_board(){
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}

void move(int sx,int sy,int dx,int dy){
    board[dx][dy] = board[sx][sy];
    board[sx][sy] = 0;
}

int main(){
    print_board();
    move(0,1,2,2);
    print_board();
    return 0;
}