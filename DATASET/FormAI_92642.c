//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int rows,cols;
    printf("Enter number of rows and columns: ");
    scanf("%d%d",&rows,&cols);
    if(rows!=cols){
        printf("Bingo requires a square board.\n");
        return 1;
    }
    int board[rows][cols];
    srand(time(NULL));
    int numCount = 1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            board[i][j] = numCount++;
        }
    }
    printf("\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf(" %d\t",board[j][i]);
        }
        printf("\n\n");
    }
    printf("\nLet the game begin!\n");
    printf("The first number is: ");
    int num,chances=0;
    scanf("%d",&num);
    while(num!=0){
        int flag = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(num == board[i][j]){
                    board[i][j] = 0;
                    flag = 1;
                    break;
                }
            }
            if(flag==1) break;
        }
        chances++;
        printf("\n");
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(board[i][j]==0) printf("[X]\t");
                else printf(" %d\t",board[i][j]);
            }
            printf("\n\n");
        }
        int rowVal=0,colVal=0,diagVal1=0,diagVal2=0;
        for(int i=0;i<rows;i++){
            rowVal=0;
            colVal=0;
            for(int j=0;j<cols;j++){
                rowVal += board[i][j];
                colVal += board[j][i];
                if(i==j) diagVal1 += board[i][j];
                if(i+j==rows-1) diagVal2 += board[i][j]; 
            }
            if(rowVal==0 || colVal==0 || diagVal1==0 || diagVal2==0){
                printf("\n\nBINGO!!\nYou won in %d chances.",chances);
                return 0;
            }   
        }
        printf("\nThe next number is: ");
        scanf("%d",&num);   
    }
    return 0;
}