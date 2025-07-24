//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define NUM_CELLS 25
#define MAX_CALLS 75

int main(void)
{
    srand(time(NULL)); // Initialize random number generator
    
    // Initialize bingo board with zeros
    int board[ROWS][COLS] = {0};
    
    // Fill bingo board with random numbers from 1 to 25
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int num;
            do
            {
                num = rand() % NUM_CELLS + 1;
            } while (board[i][j] == num);
            
            board[i][j] = num;
        }
    }
    
    // Print bingo board
    printf("BINGO BOARD:\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Initialize array of called numbers with zeros
    int called[MAX_CALLS] = {0};
    
    // Play bingo
    printf("BINGO GAME:\n");
    int num_calls = 0;
    while (num_calls < MAX_CALLS)
    {
        // Generate random number from 1 to 75
        int num;
        do
        {
            num = rand() % MAX_CALLS + 1;
        } while (called[num] != 0);
        
        called[num] = 1; // Mark number as called
        num_calls++; // Increment number of calls
        
        // Check if number is in bingo board and mark it if it is
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (board[i][j] == num)
                {
                    board[i][j] = 0;
                }
            }
        }
        
        // Print called number and updated bingo board
        printf("%2d   ", num);
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                printf("%2d ", board[i][j]);
            }
            printf("\n      ");
        }
        printf("\n");
        
        // Check for bingo
        int bingo = 0;
        for (int i = 0; i < ROWS; i++)
        {
            int sum = 0;
            for (int j = 0; j < COLS; j++)
            {
                sum += board[i][j];
            }
            if (sum == 0)
            {
                bingo = 1;
                break;
            }
        }
        for (int j = 0; j < COLS; j++)
        {
            int sum = 0;
            for (int i = 0; i < ROWS; i++)
            {
                sum += board[i][j];
            }
            if (sum == 0)
            {
                bingo = 1;
                break;
            }
        }
        int sum = 0;
        for (int i = 0; i < ROWS; i++)
        {
            sum += board[i][i];
        }
        if (sum == 0)
        {
            bingo = 1;
        }
        sum = 0;
        for (int i = 0; i < ROWS; i++)
        {
            sum += board[i][ROWS-1-i];
        }
        if (sum == 0)
        {
            bingo = 1;
        }
        if (bingo == 1)
        {
            printf("BINGO!\n");
            break;
        }
    }
    
    return 0;
}