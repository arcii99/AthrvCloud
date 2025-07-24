//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int random, user;
    int size;
    int count=0;
    int numbers[100];
    srand(time(NULL));
    printf("Enter the size of the bingo card: ");
    scanf("%d",&size);
    int card[size][size];
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            card[i][j]=rand() % 100 + 1;
            for(int k=0;k<j;k++)
                if(card[i][k]==card[i][j])
                {
                    j--;
                    break;
                }
        }
    }
    printf("Your Bingo Card: \n");
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
            printf("%d ",card[i][j]);
        printf("\n");
    }
    printf("Let's play bingo!\n");
    while(count<size*size)
    {
        printf("Enter your number: ");
        scanf("%d",&user);
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                if(user==card[i][j])
                {
                    card[i][j]=0;
                    count++;
                    numbers[count]=user;
                }
            }
        }
        printf("Numbers called: ");
        for(int i=1;i<=count;i++)
            printf("%d ",numbers[i]);
        printf("\n");
        if(count>=5)
        {
            for(int i=0;i<size;i++)
            {
                int win_row=0,win_col=0;
                for(int j=0;j<size;j++)
                {
                    if(card[i][j]==0)
                        win_row++;
                    if(card[j][i]==0)
                        win_col++;
                }
                if(win_row==size)
                {
                    printf("You win!\n");
                    return 0;
                }
                if(win_col==size)
                {
                    printf("You win!\n");
                    return 0;
                }
            }
            int win_diagonal1=0,win_diagonal2=0;
            for(int i=0;i<size;i++)
            {
                if(card[i][i]==0)
                    win_diagonal1++;
                if(card[i][size-i-1]==0)
                    win_diagonal2++;
            }
            if(win_diagonal1==size)
            {
                printf("You win!\n");
                return 0;
            }
            if(win_diagonal2==size)
            {
                printf("You win!\n");
                return 0;
            }
        }
    }
    printf("Card full!\n");
    return 0;
}