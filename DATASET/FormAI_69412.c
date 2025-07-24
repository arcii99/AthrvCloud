//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void generate_board(int board[][COLS]);
void print_board(int board[][COLS]);
int check_bingo(int board[][COLS]);

int main()
{
    int board[ROWS][COLS];
    int num_calls = 0;
    
    // Initialize board and call first number
    generate_board(board);
    printf("First number: B-1\n\n");
    
    // Call numbers until there is a bingo
    while (1)
    {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        int num = (col * 15) + (row + 1); // Generate number based on row and column
        
        // Check if number has already been called
        if (board[row][col] == -1)
            continue;
        
        num_calls++;
        printf("Next number: ");
        switch (col)
        {
            case 0:
                printf("B-%d", row + 1);
                break;
            case 1:
                printf("I-%d", row + 1);
                break;
            case 2:
                printf("N-%d", row + 1);
                break;
            case 3:
                printf("G-%d", row + 1);
                break;
            case 4:
                printf("O-%d", row + 1);
                break;
        }
        printf("\n");
        
        // Mark number as called on board
        board[row][col] = -1;
        
        // Check for bingo
        if (check_bingo(board))
        {
            printf("\nBingo! It took %d calls to win.\n", num_calls);
            break;
        }
    }
    
    return 0;
}

// Function to generate a new board
void generate_board(int board[][COLS])
{
    srand(time(NULL));
    
    // Fill board with -1 to indicate that no numbers have been called
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = -1;
        }
    }
    
    // Generate 24 unique numbers and place them on board
    int num_generated = 0;
    while (num_generated < 24)
    {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        int num = (col * 15) + (row + 1); // Generate number based on row and column
        
        // Check if number has already been generated
        int unique = 1;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (board[i][j] == num)
                {
                    unique = 0;
                    break;
                }
            }
            
            if (!unique)
                break;
        }
        
        if (unique)
        {
            board[row][col] = num;
            num_generated++;
        }
    }
}

// Function to print the current board
void print_board(int board[][COLS])
{
    printf("Current board:\n");
    printf("--------------\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] == -1)
                printf("  ");
            else
                printf("%2d", board[i][j]);
            
            printf(" ");
        }
        
        printf("\n");
    }
}

// Function to check for a bingo
int check_bingo(int board[][COLS])
{
    // Check rows
    for (int i = 0; i < ROWS; i++)
    {
        int bingo = 1;
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] != -1)
                bingo = 0;
        }
        
        if (bingo)
            return 1;
    }
    
    // Check columns
    for (int i = 0; i < COLS; i++)
    {
        int bingo = 1;
        for (int j = 0; j < ROWS; j++)
        {
            if (board[j][i] != -1)
                bingo = 0;
        }
        
        if (bingo)
            return 1;
    }
    
    // Check diagonal from top left to bottom right
    int bingo = 1;
    for (int i = 0; i < ROWS; i++)
    {
        if (board[i][i] != -1)
            bingo = 0;
    }
    
    if (bingo)
        return 1;
    
    // Check diagonal from top right to bottom left
    bingo = 1;
    for (int i = 0; i < ROWS; i++)
    {
        if (board[i][COLS - 1 - i] != -1)
            bingo = 0;
    }
    
    if (bingo)
        return 1;
    
    return 0; // No bingo yet
}