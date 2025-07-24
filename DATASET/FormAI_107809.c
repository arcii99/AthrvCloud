//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void print_board(int board[ROWS][COLS])
{
    printf("\n\n\tB\tI\tN\tG\tO\n\n");
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            printf("\t%d", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(int board[ROWS][COLS])
{
    int win_flag = 0;
    
    // Check for Horizontal Wins
    for(int i=0; i<ROWS; i++)
    {
        int count = 0;
        for(int j=0; j<COLS; j++)
        {
            if(board[i][j] == -1)
            {
                count++;
            }
        }
        if(count == COLS)
        {
            win_flag = 1;
            break;
        }
    }
    
    // Check for Vertical Wins
    for(int i=0; i<COLS; i++)
    {
        int count = 0;
        for(int j=0; j<ROWS; j++)
        {
            if(board[j][i] == -1)
            {
                count++;
            }
        }
        if(count == ROWS)
        {
            win_flag = 1;
            break;
        }
    }
    
    // Check for Diagonal Wins
    int count = 0;
    for(int i=0; i<ROWS; i++)
    {
        if(board[i][i] == -1)
        {
            count++;
        }
    }
    if(count == ROWS)
    {
        win_flag = 1;
    }
    count = 0;
    for(int i=0; i<ROWS; i++)
    {
        if(board[i][COLS-1-i] == -1)
        {
            count++;
        }
    }
    if(count == ROWS)
    {
        win_flag = 1;
    }
    
    return win_flag;
}

int main()
{
    int board[ROWS][COLS];
    int num_called[ROWS*COLS];
    int num_called_count = 0;
    int win_flag = 0;
    
    // Initialize board and num_called
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            board[i][j] = -1;
        }
    }
    for(int i=0; i<ROWS*COLS; i++)
    {
        num_called[i] = -1;
    }
    
    // Seed random number generator
    srand(time(NULL));
    
    // Game loop
    while(!win_flag)
    {
        // Generate random number and check if already called
        int num = rand() % 25 + 1;
        int already_called = 0;
        for(int i=0; i<num_called_count; i++)
        {
            if(num_called[i] == num)
            {
                already_called = 1;
                break;
            }
        }
        
        // Add number to board and num_called
        if(!already_called)
        {
            num_called[num_called_count] = num;
            num_called_count++;
            for(int i=0; i<ROWS; i++)
            {
                for(int j=0; j<COLS; j++)
                {
                    if(board[i][j] == num)
                    {
                        board[i][j] = -1;
                    }
                }
            }
            board[(num-1)/5][(num-1)%5] = num;
        }
        
        // Print board and check for win
        print_board(board);
        win_flag = check_win(board);
    }
    
    printf("\n\n\tBINGO! You Win!\n");
    
    return 0;
}