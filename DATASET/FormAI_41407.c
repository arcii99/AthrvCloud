//FormAI DATASET v1.0 Category: Game of Life ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH    50
#define HEIGHT   25
#define MAX_GEN  100

int board[WIDTH][HEIGHT];
int copy_board[WIDTH][HEIGHT];

void init_board();
void print_board();
void start_game();
void evolve();

int main()
{
    srand(time(NULL));
    init_board();
    start_game();
    return 0;
}

void init_board()
{
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board()
{
    printf("\n");
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            printf("%c ", board[i][j] ? '*' : ' ');
        }
        printf("\n");
    }
}

void start_game()
{
    for (int i = 1; i <= MAX_GEN; i++)
    {
        evolve();
        printf("\nGeneration %d:\n", i);
        print_board();
    }
}

void evolve()
{
    for (int i = 1; i < WIDTH - 1; i++)
    {
        for (int j = 1; j < HEIGHT - 1; j++)
        {
            int sum = 0;
            sum += board[i - 1][j - 1];
            sum += board[i - 1][j];
            sum += board[i - 1][j + 1];
            sum += board[i][j - 1];
            sum += board[i][j + 1];
            sum += board[i + 1][j - 1];
            sum += board[i + 1][j];
            sum += board[i + 1][j + 1];
            if (board[i][j] == 1)
            {
                if (sum == 2 || sum == 3)
                {
                    copy_board[i][j] = 1;
                }
                else
                {
                    copy_board[i][j] = 0;              
                }       
            }
            else
            {
                if (sum == 3)
                {
                    copy_board[i][j] = 1;
                }
                else
                {
                    copy_board[i][j] = 0;
                }
            }
        }
    }
    for (int i = 1; i < WIDTH - 1; i++)
    {
        for (int j = 1; j < HEIGHT - 1; j++)
        {
            board[i][j] = copy_board[i][j];
        }
    }
}