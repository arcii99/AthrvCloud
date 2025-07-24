//FormAI DATASET v1.0 Category: Memory Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 4
#define COL 4

void display(int board[][COL], int row){
    int i, j;
    printf(" ");
    for(i=0; i<COL; i++)
        printf(" %2d", i+1);
    printf("\n");
    for(i=0; i<ROW; i++){
        printf("%2d", i+1);
        for(j=0; j<COL; j++){
            if(board[i][j] == 0)
                printf("  *");
            else
                printf(" %2d", board[i][j]);
        }
        printf("\n");
    }
}

void shuffle(int board[][COL], int row){
    int i, j;
    srand((unsigned int)time(NULL));            //seed to generate random number
    for(i=row*COL-1; i>0; i--){
        int j = rand()%(i+1);
        int temp = board[i/COL][i%COL];
        board[i/COL][i%COL] = board[j/COL][j%COL];
        board[j/COL][j%COL] = temp;
    }
}

void start(int board[][COL], int row){
    int i, j;
    for(i=0; i<row; i++){
        for(j=0; j<COL; j++){
            board[i][j] = i*COL+j+1;
        }
    }
    board[row-1][COL-1] = 0;                    //last block should be empty
}

int isFinished(int board[][COL], int row){
    int i, j;
    int count = 1;
    for(i=0; i<row; i++){
        for(j=0; j<COL; j++){
            if(board[i][j] != count++){
                if(i==row-1 && j==COL-1)
                    return 1;
                else
                    return 0;
            }
        }
    }
    return 1;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void move(int board[][COL], int row){
    int i, j, n, x, y;
    do{
        printf("Enter the number of the block (Enter 0 to exit): ");
        scanf("%d", &n);
        if(n==0){
            printf("Game Over!\n");
            exit(0);
        }
        for(i=0; i<row; i++){
            for(j=0; j<COL; j++){
                if(board[i][j] == n){
                    x = i;
                    y = j;
                }
            }
        }
        if(x>0 && board[x-1][y] == 0){                  //swap with upper block
            swap(&board[x][y], &board[x-1][y]);
            return;
        }
        else if(x<row-1 && board[x+1][y] == 0){          //swap with lower block
            swap(&board[x][y], &board[x+1][y]);
            return;
        }
        else if(y>0 && board[x][y-1] == 0){            //swap with left block
            swap(&board[x][y], &board[x][y-1]);
            return;
        }
        else if(y<COL-1 && board[x][y+1] == 0){           //swap with right block
            swap(&board[x][y], &board[x][y+1]);
            return;
        }
        else{
            printf("Invalid Move!\n");
        }
    }while(1);
}

int main(){
    int board[ROW][COL];
    start(board, ROW);
    shuffle(board, ROW);
    while(1){
        display(board, ROW);
        move(board, ROW);
        if(isFinished(board, ROW)){
            display(board, ROW);
            printf("You Won!\n");
            break;
        }
    }
    return 0;
}