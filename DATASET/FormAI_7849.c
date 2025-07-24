//FormAI DATASET v1.0 Category: Game of Life ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLUMNS 20

int board[ROWS][COLUMNS] = {0};
int tmp_board[ROWS][COLUMNS] = {0};

void print_board(int board[][COLUMNS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (board[i][j] == 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int get_num_neighbors(int row, int col)
{
    int num_neighbors = 0;
    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            if (i < 0 || j < 0 || i >= ROWS || j >= COLUMNS)
                continue;
            if (i == row && j == col)
                continue;
            if (board[i][j] == 1)
                num_neighbors++;
        }
    }
    return num_neighbors;
}

void update_board(int board[][COLUMNS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            int num_neighbors = get_num_neighbors(i, j);
            if (board[i][j] == 1)
            {
                if (num_neighbors < 2 || num_neighbors > 3)
                    tmp_board[i][j] = 0;
                else
                    tmp_board[i][j] = 1;
            }
            else
            {
                if (num_neighbors == 3)
                    tmp_board[i][j] = 1;
                else
                    tmp_board[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            board[i][j] = tmp_board[i][j];
        }
    }
}

int main()
{
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    while (1)
    {
        system("clear"); // for linux or "cls" for windows.
        print_board(board);
        update_board(board);
        // You may change the number of delay to make it faster or slower.
        // Delay is in miliseconds here.
        usleep(100000);
    }
    return 0;
}