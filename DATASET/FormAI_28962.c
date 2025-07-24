//FormAI DATASET v1.0 Category: Game of Life ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

// Function to initialize the game board with random cells
void init_board(int board[ROWS][COLS])
{
    srand(time(NULL)); // Seed the random number generator with current time
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = rand() % 2; // Randomly assign 0 or 1 to each cell
        }
    }
}

// Function to print the game board
void print_board(int board[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%c ", board[i][j] ? 'X' : '-'); // Print 'X' if cell is alive, '-' if cell is dead
        }
        printf("\n");
    }
}

// Function to get the number of alive neighbors for a given cell
int get_alive_neighbors(int board[ROWS][COLS], int row, int col)
{
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS && (i != row || j != col))
            {
                count += board[i][j];
            }
        }
    }
    return count;
}

// Function to update the game board for the next generation
void update_board(int board[ROWS][COLS])
{
    int next_board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int alive_neighbors = get_alive_neighbors(board, i, j);
            if (board[i][j] == 1 && (alive_neighbors < 2 || alive_neighbors > 3)) // Any live cell with fewer than two live neighbors or more than three live neighbors dies
            {
                next_board[i][j] = 0;
            }
            else if (board[i][j] == 0 && alive_neighbors == 3) // Any dead cell with exactly three live neighbors becomes a live cell
            {
                next_board[i][j] = 1;
            }
            else
            {
                next_board[i][j] = board[i][j]; // Any other cell remains in its current state
            }
        }
    }
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = next_board[i][j];
        }
    }
}

int main()
{
    int board[ROWS][COLS];
    init_board(board);

    for (int i = 0; i < 10; i++) // Run the game for 10 generations
    {
        printf("Generation %d:\n", i);
        print_board(board);
        update_board(board);
        printf("\n");
    }
    
    return 0;
}