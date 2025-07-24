//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int board[5][5];//2D array for 5x5 Bingo board
    int rowsum[5]={0,0,0,0,0};//array to keep track of sum of each row
    int columnsum[5]={0,0,0,0,0};//array to keep track of sum of each column
    int leftdiagonal=0;//variable to keep track of left diagonal sum
    int rightdiagonal=0;//variable to keep track of right diagonal sum
    
    srand(time(0));//seed random number generator with current time
    
    printf("Welcome to the Bingo Simulator!\n\n");
    
    //initialize board with random numbers from 1 to 25
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            board[i][j]=rand()%25+1;
        }
    }
    
    //print board
    printf("B\tI\tN\tG\tO\n");
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(j==2 && i==2){//free space at center of board
                printf("FS\t");
            }else{
                printf("%d\t",board[i][j]);
            }
            rowsum[i]+=board[i][j];//calculate sum of each row
            columnsum[j]+=board[i][j];//calculate sum of each column
            if(i==j){//calculate sum of left diagonal
                leftdiagonal+=board[i][j];
            }
            if(i+j==4){//calculate sum of right diagonal
                rightdiagonal+=board[i][j];
            }
        }
        printf("\n");
    }
    printf("\n");
    
    //check if any row, column or diagonal has a sum of 125 (5*25)
    int winner=0;
    for(int i=0;i<5;i++){
        if(rowsum[i]==125){
            printf("Row %d is a winner!\n",i+1);
            winner=1;
        }
        if(columnsum[i]==125){
            printf("Column %d is a winner!\n",i+1);
            winner=1;
        }
    }
    if(leftdiagonal==125){
        printf("Left diagonal is a winner!\n");
        winner=1;
    }
    if(rightdiagonal==125){
        printf("Right diagonal is a winner!\n");
        winner=1;
    }
    
    if(winner==0){
        printf("No winners yet.\n");
    }
    
    return 0;//end program
}