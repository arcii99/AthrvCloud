//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5

// Function to generate random number
int generate_num(int *nums)
{
    int num;
    srand (time(NULL));
    do
    {
        num = rand() % 75 + 1;
    } while (nums[num] != 0);
    nums[num] = 1;
    return num;
}

// Function to print the bingo board
void print_board(int board[][COLUMNS])
{
    printf("\n*************************\n");
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLUMNS;j++)
        {
            if(board[i][j]<10)
                printf("  %d|",board[i][j]);
            else
                printf(" %d|",board[i][j]);
        }
        printf("\n");
        printf("-------------------------\n");
    }
    printf("\n*************************\n");
}

int main()
{
    // Initialising the board with unique numbers ranging from 1 to 75
    int board[ROWS][COLUMNS]={{0,0,0,0,0},
                              {0,0,0,0,0},
                              {0,0,0,0,0},
                              {0,0,0,0,0},
                              {0,0,0,0,0}};
    
    int nums[76]={0};
    
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLUMNS;j++)
        {
            board[i][j] = generate_num(nums);
        }
    }
    
    // Printing the board
    print_board(board);
    
    // Starting the game
    int bingo_flag=0;
    int num_drawn;
    int nums_drawn[76]={0};
    int count=0;
    
    while(!bingo_flag)
    {
        // Getting a random number
        num_drawn = generate_num(nums_drawn);
        count++;
        
        printf("Number drawn: %d\n",num_drawn);
        
        // Checking if the number is present on the board and replacing it with 0 if it is present
        for(int i=0;i<ROWS;i++)
        {
            for(int j=0;j<COLUMNS;j++)
            {
                if(board[i][j]==num_drawn)
                    board[i][j] = 0;
            }
        }
        
        // Printing the updated board
        print_board(board);
        
        // Checking for bingo
        int row_check, column_check, diagonal_check1=1, diagonal_check2=1;
        for(int i=0;i<ROWS;i++)
        {
            row_check=1;
            column_check=1;
            for(int j=0;j<COLUMNS;j++)
            {
                // Checking row
                row_check *= board[i][j];
                
                // Checking column
                column_check *= board[j][i];
            }
            if(row_check==0 || column_check==0)
            {
                bingo_flag=1;
                printf("BINGO!\n");
                break;
            }
            // Checking diagonals
            diagonal_check1 *= board[i][i];
            diagonal_check2 *= board[i][ROWS-i-1];
        }
        if(diagonal_check1==0 || diagonal_check2==0)
        {
            bingo_flag=1;
            printf("BINGO!\n");
        }   
    } 
    
    printf("Total number of draws: %d\n",count);
    
    return 0;
}