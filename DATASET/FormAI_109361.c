//FormAI DATASET v1.0 Category: Game of Life ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLUMNS 40

void init_board(int board[][COLUMNS])
{
    // Initialize the board randomly using the srand() and rand() functions from the time.h library.
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board(int board[][COLUMNS])
{
    // Print the board to the console, where 1 represents a live cell and 0 represents a dead cell.
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            printf("%c ", board[i][j] ? 'X' : '-');
        }
        printf("\n");
    }
}

int count_neighbors(int board[][COLUMNS], int row, int column)
{
    // Count the number of live neighbors surrounding a given cell on the board.
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = column - 1; j <= column + 1; j++)
        {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLUMNS && (i != row || j != column))
            {
                count += board[i][j];
            }
        }
    }
    return count;
}

void update_board(int board[][COLUMNS])
{
    // Apply the rules of the Game of Life to update the board for the next generation.
    int new_board[ROWS][COLUMNS] = {0};
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            int neighbors = count_neighbors(board, i, j);
            if (board[i][j])
            {
                if (neighbors == 2 || neighbors == 3)
                {
                    new_board[i][j] = 1;
                }
            }
            else
            {
                if (neighbors == 3)
                {
                    new_board[i][j] = 1;
                }
            }
        }
    }
    // Copy the new state of the board back to the original array.
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            board[i][j] = new_board[i][j];
        }
    }
}

int main()
{
    int board[ROWS][COLUMNS];
    init_board(board);
    for (int i = 0; i < 100; i++)
    {
        printf("Generation %d:\n", i);
        print_board(board);
        update_board(board);
        printf("\n");
    }
    return 0;
}