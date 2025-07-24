//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int board[5][5], i, j, x, temp, count=0;
    char ans;
    srand(time(0));

    // Generate Random Numbers and Fill the Board
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            x = (rand()%15) + (15*i) + 1;
            board[i][j] = x;
        }
    }
    // Replace Middle Cell value with 0
    board[2][2] = 0;

    // Display the Board
    printf("\t\t***** Welcome to Bingo Game *****\n");
    printf("\t\t--------------------------------\n\n");
    printf("\t\t  B\t  I\t  N\t  G\t  O\n");
    printf("\t\t--------------------------------\n");
    for(i=0;i<5;i++)
    {
        printf("\t\t");
        for(j=0;j<5;j++)
        {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
    // Game Loop
    while(1)
    {
        count++;
        printf("\nEnter 'Y' to Generate Next Random Number, 'N' to Exit: ");
        scanf(" %c", &ans);
        if(ans=='N' || ans=='n')
        {
            break;
        }
        // Generate Random Number and Check If it is Present in Board
        x = (rand()%75) + 1;
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(x == board[i][j])
                {
                    board[i][j] = 0;
                    break;
                }
            }
        }
        // Display Updated Board after each Number
        printf("\n\t\t***** Updated Board *****\n");
        printf("\t\t---------------------------\n\n");
        printf("\t\t  B\t  I\t  N\t  G\t  O\n");
        printf("\t\t---------------------------\n");
        for(i=0;i<5;i++)
        {
            printf("\t\t");
            for(j=0;j<5;j++)
            {
                printf("%d\t", board[i][j]);
            }
            printf("\n");
        }
        // Check for Bingo and Exit if Bingo
        if((board[0][0] ==0 && board[0][1] ==0 && board[0][2] ==0 && board[0][3] ==0 && board[0][4] ==0) ||
        (board[1][0] ==0 && board[1][1] ==0 && board[1][2] ==0 && board[1][3] ==0 && board[1][4] ==0) ||
        (board[2][0] ==0 && board[2][1] ==0 && board[2][3] ==0 && board[2][4] ==0 && board[2][2] ==0) ||
        (board[3][0] ==0 && board[3][1] ==0 && board[3][2] ==0 && board[3][3] ==0 && board[3][4] ==0) ||
        (board[4][0] ==0 && board[4][1] ==0 && board[4][2] ==0 && board[4][3] ==0 && board[4][4] ==0) ||
        (board[0][0] ==0 && board[1][0] ==0 && board[2][0] ==0 && board[3][0] ==0 && board[4][0] ==0) ||
        (board[0][1] ==0 && board[1][1] ==0 && board[2][1] ==0 && board[3][1] ==0 && board[4][1] ==0) ||
        (board[0][2] ==0 && board[1][2] ==0 && board[3][2] ==0 && board[4][2] ==0 && board[2][2] ==0) ||
        (board[0][3] ==0 && board[1][3] ==0 && board[3][3] ==0 && board[4][3] ==0 && board[2][3] ==0) ||
        (board[0][4] ==0 && board[1][4] ==0 && board[2][4] ==0 && board[3][4] ==0 && board[4][4] ==0) ||
        (board[0][4] ==0 && board[1][3] ==0 && board[2][2] ==0 && board[3][1] ==0 && board[4][0] ==0) ||
        (board[0][0] ==0 && board[1][1] ==0 && board[3][3] ==0 && board[4][4] ==0 && board[2][2] ==0))
        {
            printf("\n\t\t***** Congratulations, You Won! *****\n");
            printf("\t\t-------------------------------------\n");
            printf("\nTotal Number of times Number Generated: %d", count);
            break;
        }
    }
    return 0;
}