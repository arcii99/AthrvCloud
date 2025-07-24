//FormAI DATASET v1.0 Category: Game of Life ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50

void initialize_board(int board[][COLS]);
void print_board(int board[][COLS]);

int count_alive_neighbors(int board[][COLS], int row, int col);
void update_board(int board[][COLS]);

int main(void)
{
    int board[ROWS][COLS];
    
    initialize_board(board);

    while (1)
    {
        system("clear");
        print_board(board);
        update_board(board);
        sleep(1);
    }

    return 0;
}

void initialize_board(int board[][COLS])
{
    srand(time(NULL));
    
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board(int board[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%c", board[i][j] ? '#' : ' ');
        }

        printf("\n");
    }
}

int count_alive_neighbors(int board[][COLS], int row, int col)
{
    int count = 0;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int neighbor_row = row + i;
            int neighbor_col = col + j;

            if (neighbor_row < 0 || neighbor_col < 0 || neighbor_row >= ROWS || neighbor_col >= COLS)
            {
                continue;
            }

            if (i == 0 && j == 0)
            {
                continue;
            }

            if (board[neighbor_row][neighbor_col])
            {
                count++;
            }
        }
    }

    return count;
}

void update_board(int board[][COLS])
{
    int new_board[ROWS][COLS];

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int alive_neighbors = count_alive_neighbors(board, i, j);

            if (board[i][j])
            {
                if (alive_neighbors == 2 || alive_neighbors == 3)
                {
                    new_board[i][j] = 1;
                }
                else
                {
                    new_board[i][j] = 0;
                }
            }
            else
            {
                if (alive_neighbors == 3)
                {
                    new_board[i][j] = 1;
                }
                else
                {
                    new_board[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = new_board[i][j];
        }
    }
}