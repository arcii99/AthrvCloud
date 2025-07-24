//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void initBoard(int board[][COLS], int keepTrack[])
{
    int i, j;
    
    // Initialize the board with random numbers
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            board[i][j] = rand() % 75 + 1;
        }
    }
    
    // Initialize the keepTrack array with 0's
    for(i = 0; i < 75; i++)
    {
        keepTrack[i] = 0;
    }
}

void printBoard(int board[][COLS])
{
    int i, j;
    
    printf("\nBINGO BOARD:\n\n");
    
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
}

void printKeepTrack(int keepTrack[])
{
    int i;
    
    printf("\nNUMBERS CALLED:\n\n");
    
    for(i = 0; i < 75; i++)
    {
        if(keepTrack[i] == 1)
        {
            printf("%2d ", i + 1);
        }
    }
    
    printf("\n");
}

int checkVertical(int board[][COLS], int keepTrack[], int randNum)
{
    int i, j, count;
    
    for(j = 0; j < COLS; j++)
    {
        count = 0;
        for(i = 0; i < ROWS; i++)
        {
            if(board[i][j] == randNum)
            {
                count++;
                keepTrack[randNum - 1] = 1;
            }
        }
        if(count == ROWS)
        {
            return 1;
        }
    }
    
    return 0;
}

int checkHorizontal(int board[][COLS], int keepTrack[], int randNum)
{
    int i, j, count;
    
    for(i = 0; i < ROWS; i++)
    {
        count = 0;
        for(j = 0; j < COLS; j++)
        {
            if(board[i][j] == randNum)
            {
                count++;
                keepTrack[randNum - 1] = 1;
            }
        }
        if(count == COLS)
        {
            return 1;
        }
    }
    
    return 0;
}

int checkDiagonal(int board[][COLS], int keepTrack[], int randNum)
{
    int i, count;
    
    // Check top-left to bottom-right diagonal
    count = 0;
    for(i = 0; i < ROWS; i++)
    {
        if(board[i][i] == randNum)
        {
            count++;
            keepTrack[randNum - 1] = 1;
        }
    }
    if(count == ROWS)
    {
        return 1;
    }
    
    // Check top-right to bottom-left diagonal
    count = 0;
    for(i = 0; i < ROWS; i++)
    {
        if(board[i][COLS - i - 1] == randNum)
        {
            count++;
            keepTrack[randNum - 1] = 1;
        }
    }
    if(count == ROWS)
    {
        return 1;
    }
    
    return 0;
}

int main()
{
    int board[ROWS][COLS];
    int keepTrack[75];
    int randNum, counter = 0;
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the board and keepTrack array
    initBoard(board, keepTrack);
    
    // Print the initial board
    printBoard(board);
    
    // Keep calling random numbers until someone wins
    while(1)
    {
        printf("Press ENTER to call the next number.\n\n");
        getchar();
        
        // Generate a random number and check for a win
        randNum = rand() % 75 + 1;
        counter++;
        
        if(checkVertical(board, keepTrack, randNum) ||
           checkHorizontal(board, keepTrack, randNum) ||
           checkDiagonal(board, keepTrack, randNum))
        {
            printf("BINGO! Number called: %d\n\n", randNum);
            break;
        }
        else
        {
            printf("Sorry, number called: %d\n\n", randNum);
        }
        
        // Print the updated board and keepTrack array
        printBoard(board);
        printKeepTrack(keepTrack);
    }
    
    printf("Game over. It took %d calls to win.\n\n", counter);
    
    return 0;
}