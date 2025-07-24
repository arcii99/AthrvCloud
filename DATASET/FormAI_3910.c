//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

void generate_board(int arr[3][3]);
bool check_bingo(int arr[3][3]);

int main()
{
    int board[3][3];
    generate_board(board);
    printf("Your bingo board:\n\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==-1){
                printf("  \t");
            }
            else{
                printf("%d\t",board[i][j]);
            }
        }
        printf("\n\n");
    }

    printf("Press Enter to start the game!\n");
    getchar();

    srand(time(NULL));
    int num;
    bool bingo=false;
    while(!bingo){
        num=rand()%9+1;
        printf("\n\nThe number is: %d\n\n",num);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==num){
                    board[i][j]=-1;
                }
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]!=-1){
                    printf("%d\t",board[i][j]);
                }
                else{
                    printf(" \t");
                }
            }
            printf("\n\n");
        }
        if(check_bingo(board)){
            bingo=true;
        }
    }
    printf("Bingo!!! You won the game!\n");
}

void generate_board(int arr[3][3])
{
    int nums[9];
    for(int i=0;i<9;i++){
        nums[i]=rand()%9+1;
        for(int j=0;j<i;j++){
            if(nums[j]==nums[i]){
                i--;
                break;
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            arr[i][j]=nums[i*3+j];
        }
    }
    arr[1][1]=-1;
}

bool check_bingo(int arr[3][3])
{
    bool bingo=false;
    for(int i=0;i<3;i++){
        if(arr[i][0]==-1 && arr[i][1]==-1 && arr[i][2]==-1){
            bingo=true;
        }
    }
    for(int i=0;i<3;i++){
        if(arr[0][i]==-1 && arr[1][i]==-1 && arr[2][i]==-1){
            bingo=true;
        }
    }
    if(arr[0][0]==-1 && arr[1][1]==-1 && arr[2][2]==-1){
        bingo=true;
    }
    if(arr[0][2]==-1 && arr[1][1]==-1 && arr[2][0]==-1){
        bingo=true;
    }
    return bingo;
}