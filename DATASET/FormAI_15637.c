//FormAI DATASET v1.0 Category: Game of Life ; Style: calm
#include <stdio.h>

// Define board dimensions
#define ROWS 10
#define COLS 10

// Function to print the board
void print_board(int board[ROWS][COLS])
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            if(board[i][j] == 1)
                printf("* ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to update the board
void update_board(int board[ROWS][COLS])
{
    // Create a temporary board to store updated values
    int temp_board[ROWS][COLS];

    // Loop through each cell in the board
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            // Count how many neighbors are alive
            int alive_neighbors = 0;
            for(int k=-1; k<=1; k++)
            {
                for(int l=-1; l<=1; l++)
                {
                    int x = i+k;
                    int y = j+l;
                    if(x >= 0 && x < ROWS && y >= 0 && y < COLS && !(k == 0 && l == 0))
                    {
                        if(board[x][y] == 1)
                            alive_neighbors++;
                    }
                }
            }

            // Determine if the cell should be alive or dead
            if(board[i][j] == 1)
            {
                if(alive_neighbors < 2 || alive_neighbors > 3)
                    temp_board[i][j] = 0;
                else
                    temp_board[i][j] = 1;
            }
            else
            {
                if(alive_neighbors == 3)
                    temp_board[i][j] = 1;
                else
                    temp_board[i][j] = 0;
            }
        }
    }

    // Copy updated values from temporary board to original board
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            board[i][j] = temp_board[i][j];
        }
    }
}

int main()
{
    // Set up the board with initial values
    int board[ROWS][COLS] =
    {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,1,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };

    // Loop through the generations
    for(int i=1; i<=10; i++)
    {
        printf("Generation: %d\n", i);
        print_board(board);
        update_board(board);
    }

    return 0;
}