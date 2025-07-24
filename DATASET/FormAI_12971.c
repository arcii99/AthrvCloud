//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //generate random numbers
    srand(time(NULL));
    
    //initialize variables
    int bingoBoard[5][5] = {0};
    int usedNumbers[25] = {0};
    int currentNumber = 0;
    int playerCount = 0;
    int winner = 0;
    
    //populate board with random numbers
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            //make sure each number is unique
            do
            {
                currentNumber = rand() % 25 + 1;
            } while(usedNumbers[currentNumber - 1] == 1);
            
            bingoBoard[i][j] = currentNumber;
            usedNumbers[currentNumber - 1] = 1;
        }
    }
    
    //print initial board
    printf("Welcome to Bingo!\n");
    printf("Here is your board:\n");
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%d\t", bingoBoard[i][j]);
        }
        printf("\n");
    }
    
    //start game
    while(winner == 0)
    {
        playerCount++;
        printf("\nPlayer %d's turn\n", playerCount);
        
        //generate random number and check if it's on the board
        do
        {
            currentNumber = rand() % 25 + 1;
        } while(usedNumbers[currentNumber - 1] == 1);
        
        usedNumbers[currentNumber - 1] = 1;
        
        //check if number is on board and mark it
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(bingoBoard[i][j] == currentNumber)
                {
                    bingoBoard[i][j] = 0;
                }
            }
        }
        
        //print updated board
        printf("The number is: %d\n\n", currentNumber);
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                printf("%d\t", bingoBoard[i][j]);
            }
            printf("\n");
        }
        
        //check for winner horizontally
        for(int i = 0; i < 5; i++)
        {
            if(bingoBoard[i][0] == 0 && bingoBoard[i][1] == 0 && bingoBoard[i][2] == 0 && bingoBoard[i][3] == 0 && bingoBoard[i][4] == 0)
            {
                winner = playerCount;
                break;
            }
        }
        
        //check for winner vertically
        for(int j = 0; j < 5; j++)
        {
            if(bingoBoard[0][j] == 0 && bingoBoard[1][j] == 0 && bingoBoard[2][j] == 0 && bingoBoard[3][j] == 0 && bingoBoard[4][j] == 0)
            {
                winner = playerCount;
                break;
            }
        }
        
        //check for winner diagonally
        if(bingoBoard[0][0] == 0 && bingoBoard[1][1] == 0 && bingoBoard[2][2] == 0 && bingoBoard[3][3] == 0 && bingoBoard[4][4] == 0)
        {
            winner = playerCount;
        }
        
        if(bingoBoard[0][4] == 0 && bingoBoard[1][3] == 0 && bingoBoard[2][2] == 0 && bingoBoard[3][1] == 0 && bingoBoard[4][0] == 0)
        {
            winner = playerCount;
        }
    }
    
    //print winner
    printf("\n\nBingo! Congratulations Player %d, you have won!\n", winner);
    
    return 0;
}