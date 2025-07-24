//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_board(int *);
int check_win(int *);

void main()
{
    int board[25], i, j, num;
    srand(time(NULL));

    for(i=0;i<25;i++)
        board[i]=-1;

    display_board(board);

    for(i=0; i<25; i++)
    {
        printf("\nPress Enter to play Bingo!");
        getchar();
        num=rand()%90+1;
        printf("\nNumber generated is: %d\n", num);

        for(j=0;j<25;j++)
        {
            if(board[j]==num)
            {
                board[j]=0;
                break;
            }
        }

        display_board(board);

        if(check_win(board))
        {
            printf("\nBingo! You have won!\n");
            break;
        }
    }
}

void display_board(int *board)
{
    int i;
    for(i=0;i<25;i++)
    {
        if(board[i]==-1)
            printf("|  %d  |",i+1);
        else if(board[i]==0)
            printf("|  X  |");
        else
            printf("|  %d  |",board[i]);
        if((i+1)%5==0)
            printf("\n");
    }
}

int check_win(int *board)
{
    int i, j, sum1=0, sum2=0, sum3=0, sum4=0;
    for(i=0;i<25;i+=5)// checking rows
    {
        sum1=0;
        for(j=0;j<5;j++)
            sum1+=board[i+j];
        if(sum1==0)
            return 1;
    }
    for(i=0;i<5;i++)// checking columns
    {
        sum2=0;
        for(j=0;j<25;j+=5)
            sum2+=board[i+j];
        if(sum2==0)
            return 1;
    }
    // checking diagonals
    if((board[0]+board[6]+board[12]+board[18]+board[24])==0)
        return 1;
    if((board[4]+board[8]+board[12]+board[16]+board[20])==0)
        return 1;

    return 0;
}