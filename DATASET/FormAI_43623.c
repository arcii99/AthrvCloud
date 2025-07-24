//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void generateBingoCard(int card[][COLS])
{
    // initialize the card
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            card[i][j] = 0;
        }
    }
    
    // generate random numbers on the card
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(i == 2 && j == 2) // center square is free
            {
                continue;
            }
            int num;
            do {
                num = rand() % 15 + 15*j + 1;
            } while(numExists(card, num));
            card[i][j] = num;
        }
    }
}

int numExists(int card[][COLS], int num)
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(card[i][j] == num)
            {
                return 1;
            }
        }
    }
    return 0;
}

void printCard(int card[][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(i == 2 && j == 2) // free square
            {
                printf("  ");
            }
            else
            {
                printf("%2d ", card[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int card[ROWS][COLS];
    srand(time(NULL)); // seed the random number generator
    
    generateBingoCard(card);
    printCard(card);
    
    return 0;
}