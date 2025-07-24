//FormAI DATASET v1.0 Category: Game of Life ; Style: surrealist
// Surrealist Game of Life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Board size
#define ROWS 20
#define COLS 60

// Define cell states
#define ALIVE '*'
#define DEAD ' '

// Function to generate random initial state
void init(char board[ROWS][COLS])
{
    srand(time(0)); // Seed random number generator
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (rand() % 2 == 0)
            {
                board[i][j] = ALIVE; // Set cell to alive
            }
            else
            {
                board[i][j] = DEAD; // Set cell to dead
            }
        }
    }
}

// Function to print board
void print_board(char board[ROWS][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// Function to update board
void update(char board[ROWS][COLS])
{
    int i, j, count;
    char new_board[ROWS][COLS];
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            count = 0;
            if (i > 0 && j > 0 && board[i - 1][j - 1] == ALIVE) count++;
            if (i > 0 && board[i - 1][j] == ALIVE) count++;
            if (i > 0 && j < COLS - 1 && board[i - 1][j + 1] == ALIVE) count++;
            if (j > 0 && board[i][j - 1] == ALIVE) count++;
            if (j < COLS - 1 && board[i][j + 1] == ALIVE) count++;
            if (i < ROWS - 1 && j > 0 && board[i + 1][j - 1] == ALIVE) count++;
            if (i < ROWS - 1 && board[i + 1][j] == ALIVE) count++;
            if (i < ROWS - 1 && j < COLS - 1 && board[i + 1][j + 1] == ALIVE) count++;
            if (board[i][j] == ALIVE && (count < 2 || count > 3))
            {
                new_board[i][j] = DEAD; // Cell dies
            }
            else if (board[i][j] == DEAD && count == 3)
            {
                new_board[i][j] = ALIVE; // Cell is born
            }
            else
            {
                new_board[i][j] = board[i][j]; // Cell stays the same
            }
        }
    }
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            board[i][j] = new_board[i][j]; // Update board
        }
    }
}

int main()
{
    char board[ROWS][COLS];
    init(board);
    print_board(board);
    while (1)
    {
        getchar();
        update(board);
        print_board(board);
    }
    return 0;
}