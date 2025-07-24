//FormAI DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 60

void init_board(int board[][COLS]);
void print_board(int board[][COLS]);
void update_board(int board[][COLS]);

int main()
{
    int board[ROWS][COLS];

    // seed the random number generator
    srand(time(NULL));
    
    // initialize the board
    init_board(board);
    
    // print the initial board
    print_board(board);
    
    // update and print the board 100 times
    for(int i = 0; i < 100; i++)
    {
        update_board(board);
        print_board(board);
    }
    
    return 0;
}

// initialize the board with random live and dead cells
void init_board(int board[][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            // randomly set the cell to be alive or dead
            board[i][j] = rand() % 2;
        }
    }
}

// print the board to the console
void print_board(int board[][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(board[i][j] == 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// update the board based on the rules of the Game of Life
void update_board(int board[][COLS])
{
    // create a new board to hold the updated values
    int new_board[ROWS][COLS];
    
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            // count the number of living neighbors
            int num_neighbors = 0;
            for(int k = i-1; k <= i+1; k++)
            {
                for(int l = j-1; l <= j+1; l++)
                {
                    if(k >= 0 && k < ROWS && l >= 0 && l < COLS && !(k == i && l == j))
                    {
                        num_neighbors += board[k][l];
                    }
                }
            }
            
            // apply the rules of the Game of Life
            if(board[i][j] == 1 && (num_neighbors == 2 || num_neighbors == 3))
            {
                new_board[i][j] = 1;
            }
            else if(board[i][j] == 0 && num_neighbors == 3)
            {
                new_board[i][j] = 1;
            }
            else
            {
                new_board[i][j] = 0;
            }
        }
    }
    
    // copy the updated values to the original board
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            board[i][j] = new_board[i][j];
        }
    }
}