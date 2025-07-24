//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 5

void printBingo(int bingoCard[SIZE][SIZE])
{
    printf("\n-------------------------------\n");
    printf("|  B  |  I  |  N  |  G  |  O  |\n");
    printf("-------------------------------\n");

    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            printf("|  %2d ", bingoCard[i][j]);
        }
        printf("|\n-------------------------------\n");
    }
    printf("\n");
}

int checkBingo(int bingoCard[SIZE][SIZE])
{
    int counter;

    //Checking Rows
    for(int i=0; i<SIZE; i++)    
    {
        counter = 0;
        for(int j=0; j<SIZE; j++)
        {
            if(bingoCard[i][j] == -1)
                counter++;
        }

        if(counter == SIZE)
            return 1;
    }

    //Checking Columns
    for(int i=0; i<SIZE; i++)    
    {
        counter = 0;
        for(int j=0; j<SIZE; j++)
        {
            if(bingoCard[j][i] == -1)
                counter++;
        }

        if(counter == SIZE)
            return 1;
    }

    //Checking Diagonal Top-Left to Bottom-Right
    counter = 0;
    for(int i=0; i<SIZE; i++)    
    {
        if(bingoCard[i][i] == -1)
            counter++;
    }

    if(counter == SIZE)
        return 1;

    //Checking Diagonal Bottom-Left to Top-Right
    counter = 0;
    for(int i=0; i<SIZE; i++)    
    {
        if(bingoCard[SIZE-i-1][i] == -1)
            counter++;
    }

    if(counter == SIZE)
        return 1;

    return 0;
}

int main()
{
    int bingoCard[SIZE][SIZE] = { {-1,-1,-1,-1,-1},
                                  {-1,-1,-1,-1,-1},
                                  {-1,-1,-1,-1,-1},
                                  {-1,-1,-1,-1,-1},
                                  {-1,-1,-1,-1,-1} };

    srand(time(0));

    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            if(j==0)
                bingoCard[i][j] = rand()%15 + 1 + (15*i);
            else if(j==1)
                bingoCard[i][j] = rand()%15 + 16 + (15*i);
            else if(j==2 && i!=2)
                bingoCard[i][j] = rand()%15 + 31 + (15*i);
            else if(j==2 && i==2)
                bingoCard[i][j] = -1;
            else if(j==3)
                bingoCard[i][j] = rand()%15 + 46 + (15*i);
            else if(j==4)
                bingoCard[i][j] = rand()%15 + 61 + (15*i);
        }
    }

    int randomNumber;
    int counter = 0;

    printf("Welcome to Bingo Simulator!\n\n");
    printf("Your Bingo Card:\n");
    printBingo(bingoCard);

    while(1)
    {
        randomNumber = rand()%75 + 1;
        printf("Next Number is: %d\n", randomNumber);

        for(int i=0; i<SIZE; i++)
        {
            for(int j=0; j<SIZE; j++)
            {
                if(bingoCard[i][j] == randomNumber)
                {
                    bingoCard[i][j] = -1;
                    counter++;
                }
            }
        }

        if(checkBingo(bingoCard) == 1)
        {
            printf("Congratulations! You have completed the BINGO Simulator!\n");
            printf("It took you %d turns to complete your bingo card.\n\n", counter);
            break;
        }

        printf("Your Updated Bingo Card:\n");
        printBingo(bingoCard);
    }

    return 0;
}