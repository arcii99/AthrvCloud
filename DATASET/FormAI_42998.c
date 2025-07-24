//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUMBER 75

void shuffle(int *deck, size_t n)
{
    if (n > 1) 
    {
      size_t i;
      for (i = 0; i < n - 1; i++) 
      {
        size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
        int t = deck[j];
        deck[j] = deck[i];
        deck[i] = t;
      }
    }
}

void printBoard(int numbers[][COLS])
{
    printf("+----+----+----+----+----+\n");
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("|%2d  ", numbers[i][j]);
        }
        printf("|\n+----+----+----+----+----+\n");
    }
}

void checkNumber(int numbers[][COLS], int n)
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(numbers[i][j] == n)
            {
                numbers[i][j] = 0;
            }
        }
    }
}

int main()
{
    int numbers[ROWS][COLS];
    int bingo = 0;
    srand ( time(NULL) );
    int deck[MAX_NUMBER];
    for(int i = 0; i < MAX_NUMBER; i++)
    {
        deck[i] = i+1;
    }
    shuffle(deck, MAX_NUMBER);
    
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(i == 2 && j == 2) // Free space in the middle
            {
                numbers[i][j] = 0;
            }
            else
            {
                numbers[i][j] = deck[i*ROWS+j];
            }
        }
    }
    
    printf("Welcome to Bingo simulator!\n");
    printf("Hit enter to call the next number\n");
    printBoard(numbers);
    
    while(!bingo)
    {
        getchar();
        int next = deck[ROWS*COLS];
        printf("Next number is %d\n", next);
        checkNumber(numbers, next);
        printBoard(numbers);
        
        //Check rows for bingo
        for(int i = 0; i < ROWS; i++)
        {
            int match = 1;
            for(int j = 0; j < COLS; j++)
            {
                if(numbers[i][j] != 0)
                {
                    match = 0;
                    break;
                }
            }
            if(match)
            {
                printf("BINGO in row %d!\n", i+1);
                bingo = 1;
                break;
            }
        }
        
        //Check columns for bingo
        if(!bingo)
        {
            for(int i = 0; i < COLS; i++)
            {
                int match = 1;
                for(int j = 0; j < ROWS; j++)
                {
                    if(numbers[j][i] != 0)
                    {
                        match = 0;
                        break;
                    }
                }
                if(match)
                {
                    printf("BINGO in column %d!\n", i+1);
                    bingo = 1;
                    break;
                }
            }
        }
        
        //Check diagonals for bingo
        if(!bingo)
        {
            int match = 1;
            for(int i = 0; i < ROWS; i++)
            {
                if(numbers[i][i] != 0)
                {
                    match = 0;
                    break;
                }
            }
            if(match)
            {
                printf("BINGO in diagonal from top left to bottom right!\n");
                bingo = 1;
            }
        }
        if(!bingo)
        {
            int match = 1;
            for(int i = 0; i < ROWS; i++)
            {
                if(numbers[i][COLS-i-1] != 0)
                {
                    match = 0;
                    break;
                }
            }
            if(match)
            {
                printf("BINGO in diagonal from top right to bottom left!\n");
                bingo = 1;
            }
        }
    }
    printf("Thanks for playing!\n");
    return 0;
}