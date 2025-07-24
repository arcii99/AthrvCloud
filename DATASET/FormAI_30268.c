//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate random numbers for the Bingo board
int generateNumber()
{
    int num = (rand() % 75) + 1;
    return num;
}

//Function to display the Bingo board
void displayBoard(int board[][5])
{
    printf("\n\nB I N G O\n\n");

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}

//Function to check if the Bingo board has a winning combination
int winCheck(int board[][5])
{
    //Checking for horizontal wins
    for(int i=0; i<5; i++)
    {
        if(board[i][0]!=0 && board[i][1]!=0 && board[i][2]!=0 && board[i][3]!=0 && board[i][4]!=0)
            return 1;
    }

    //Checking for vertical wins
    for(int i=0; i<5; i++)
    {
        if(board[0][i]!=0 && board[1][i]!=0 && board[2][i]!=0 && board[3][i]!=0 && board[4][i]!=0)
            return 1;
    }

    //Checking for diagonal wins
    if(board[0][0]!=0 && board[1][1]!=0 && board[2][2]!=0 && board[3][3]!=0 && board[4][4]!=0)
        return 1;

    if(board[0][4]!=0 && board[1][3]!=0 && board[2][2]!=0 && board[3][1]!=0 && board[4][0]!=0)
        return 1;

    return 0;
}

int main()
{
    int board[5][5];
    int num;
    int count = 0;

    //Seed the random number generator
    srand(time(NULL));

    //Generate random numbers for the Bingo board
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            board[i][j] = generateNumber();
        }
    }

    //Display the Bingo board
    displayBoard(board);

    //Loop to continue the game until a winning combination is found
    while(winCheck(board)==0)
    {
        printf("\n\nEnter the next number (1-75): ");
        scanf("%d", &num);

        //If the entered number is already in the Bingo board, replace it with a 0
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                if(board[i][j]==num)
                {
                    board[i][j] = 0;
                    count++;
                }
            }
        }

        //Check if the game is tied
        if(count==25)
        {
            printf("\n\nThe game is tied!");
            break;
        }

        //Display the updated Bingo board
        displayBoard(board);
    }

    //Display the winning message
    printf("\n\nBINGO! You have a winning combination!");

    return 0;
}