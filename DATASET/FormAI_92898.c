//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 5
#define COL 5

void display_board(int board[][COL]);
void generate_numbers(int board[][COL]);

int main()
{
    int board[ROW][COL];
    srand(time(NULL));
    generate_numbers(board);
    display_board(board);

    return 0;
}

void display_board(int board[][COL])
{
    int i, j;
    printf("\tB   I   N   G   O\n");
    for (i = 0; i < ROW; i++)
    {
        printf("\t==================\n");
        for (j = 0; j < COL; j++)
        {
            printf("\t%d", board[i][j]);
        }
        printf("\n");
    }
    printf("\t==================\n");
}

void generate_numbers(int board[][COL])
{
    int i, j, k;
    int min[COL] = {1, 16, 31, 46, 61};

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            if (j == 0)
            {
                board[i][j] = min[j] + rand() % 15;
            }
            else if (j == 1)
            {
                board[i][j] = min[j] + rand() % 15 + 15;
            }
            else if (j == 2)
            {
                board[i][j] = min[j] + rand() % 15 + 30;
            }
            else if (j == 3)
            {
                board[i][j] = min[j] + rand() % 15 + 45;
            }
            else if (j == 4)
            {
                board[i][j] = min[j] + rand() % 15 + 60;
            }
            for (k = 0; k < j; k++)
            {
                if (board[i][j] == board[i][k])
                {
                    j--;
                }
            }
        }
    }

    board[2][2] = 0;
}