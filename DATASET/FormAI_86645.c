//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //Declare Variables
    int board[5][5] = {0};
    int calledNumbers[75] = {0};
    int count = 0;
    int randomNumber = 0;

    //Generate Seed for Random Number Generator
    srand(time(NULL));

    //Populate Bingo Board with Random Numbers
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(i == 2 && j == 2)
            {
                board[i][j] = -1;
            }
            else
            {
                board[i][j] = (rand() % 15) + (j * 15) + 1;
            }
        }
    }

    //Print Bingo Board
    printf("B  I  N  G  O\n");
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%02d ", board[i][j]);
        }
        printf("\n");
    }

    //Call Numbers Randomly Until There is a Winner
    while(1)
    {
        //Generate Random Number
        randomNumber = (rand() % 75) + 1;

        //Check If Number Has Already Been Called
        for(int i = 0; i < count; i++)
        {
            if(calledNumbers[i] == randomNumber)
            {
                //Number Has Already Been Called, Generate a New Number
                randomNumber = (rand() % 75) + 1;
                i = -1;
            }
        }

        //Add Random Number to List of Called Numbers
        calledNumbers[count] = randomNumber;
        count++;

        //Print Called Number
        printf("\n\nCalled Number: %d\n\n", randomNumber);

        //Check If Number Appears on Bingo Board
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(board[i][j] == randomNumber)
                {
                    //Number Appears on Bingo Board, Mark Spot as Visited
                    board[i][j] = 0;
                }
            }
        }

        //Check If Any Rows, Columns, or Diagonals Have All Been Marked
        int rowWin = 0;
        int columnWin = 0;
        int diagonalWin = 0;

        //Check Rows
        for(int i = 0; i < 5; i++)
        {
            int sum = 0;
            for(int j = 0; j < 5; j++)
            {
                sum += board[i][j];
            }
            if(sum == 0)
            {
                rowWin = 1;
            }
        }

        //Check Columns
        for(int i = 0; i < 5; i++)
        {
            int sum = 0;
            for(int j = 0; j < 5; j++)
            {
                sum += board[j][i];
            }
            if(sum == 0)
            {
                columnWin = 1;
            }
        }

        //Check Diagonals
        if(board[0][0] == 0 && board[1][1] == 0 && board[3][3] == 0 && board[4][4] == 0)
        {
            diagonalWin = 1;
        }
        else if(board[0][4] == 0 && board[1][3] == 0 && board[3][1] == 0 && board[4][0] == 0)
        {
            diagonalWin = 1;
        }

        //Check If There Is a Winner
        if(rowWin || columnWin || diagonalWin)
        {
            printf("\n\nBINGO! You are the winner!\n\n");
            break;
        }
    }

    return 0;
}