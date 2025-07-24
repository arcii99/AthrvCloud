//FormAI DATASET v1.0 Category: Game of Life ; Style: light-weight
// C Program to implement Conway's Game of Life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the board size
#define ROW 10
#define COL 10

// Function to print the board
void print_board(int board[][COL])
{
    printf("\n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (board[i][j] == 1)
                printf("* ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

// Function to initialize the board
void initialize_board(int board[][COL])
{
    srand(time(0));
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            board[i][j] = rand() % 2;
        }
    }
}

// Function to check the number of live cells around a particular cell
int count_live_cells(int board[][COL], int x, int y)
{
    int count = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int row = (x + i + ROW) % ROW;
            int col = (y + j + COL) % COL;
            count += board[row][col];
        }
    }
    count -= board[x][y];
    return count;
}

// Function to simulate the next generation of the board
void simulate_next_generation(int board[][COL])
{
    int new_board[ROW][COL];
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            int live_neighbors = count_live_cells(board, i, j);
            if (board[i][j] == 1 && live_neighbors < 2)
                new_board[i][j] = 0;
            else if (board[i][j] == 1 && live_neighbors > 3)
                new_board[i][j] = 0;
            else if (board[i][j] == 0 && live_neighbors == 3)
                new_board[i][j] = 1;
            else
                new_board[i][j] = board[i][j];
        }
    }
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            board[i][j] = new_board[i][j];
        }
    }
}

int main()
{
    int board[ROW][COL];
    initialize_board(board);
    print_board(board);
    int generations = 10;
    for (int i = 1; i <= generations; i++)
    {
        simulate_next_generation(board);
        printf("\n");
        printf("Generation %d:\n", i);
        print_board(board);
    }
    return 0;
}