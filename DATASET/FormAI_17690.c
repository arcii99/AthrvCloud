//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

bool is_number_already_called[MAX_NUM] = { false };

int generate_random_number(void)
{
    int n = rand() % MAX_NUM + 1;
    while (is_number_already_called[n - 1] == true)
    {
        n = rand() % MAX_NUM + 1;
    }
    is_number_already_called[n - 1] = true;
    return n;
}

void display_bingo_board(int bingo_board[][COLS])
{
    printf("------------------------\n");
    for (int i = 0; i < ROWS; i++)
    {
        printf("|");
        for (int j = 0; j < COLS; j++)
        {
            if (bingo_board[i][j] == -1)
            {
                printf("  X ");
            }
            else
            {
                printf(" %2d ", bingo_board[i][j]);
            }
            printf("|");
        }
        printf("\n------------------------\n");
    }
}

void mark_number_on_bingo_board(int bingo_board[][COLS], int n)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (bingo_board[i][j] == n)
            {
                bingo_board[i][j] = -1;
                return;
            }
        }
    }
}

bool check_bingo(int bingo_board[][COLS])
{
    int marked_count = 0;

    // Check rows
    for (int i = 0; i < ROWS; i++)
    {
        marked_count = 0;
        for (int j = 0; j < COLS; j++)
        {
            if (bingo_board[i][j] == -1)
            {
                marked_count++;
            }
        }
        if (marked_count == ROWS)
        {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < COLS; i++)
    {
        marked_count = 0;
        for (int j = 0; j < ROWS; j++)
        {
            if (bingo_board[j][i] == -1)
            {
                marked_count++;
            }
        }
        if (marked_count == COLS)
        {
            return true;
        }
    }

    // Check diagonal from left to right
    marked_count = 0;
    for (int i = 0; i < ROWS; i++)
    {
        if (bingo_board[i][i] == -1)
        {
            marked_count++;
        }
    }
    if (marked_count == ROWS)
    {
        return true;
    }

    // Check diagonal from right to left
    marked_count = 0;
    for (int i = 0, j = COLS-1; i < ROWS && j >= 0; i++, j--)
    {
        if (bingo_board[i][j] == -1)
        {
            marked_count++;
        }
    }
    if (marked_count == ROWS)
    {
        return true;
    }

    return false;
}

int main()
{
    int bingo_board[ROWS][COLS] = { 0 };
    srand(time(NULL));

    // Initialize bingo board
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (i == 2 && j == 2)
            {
                bingo_board[i][j] = -1;
            }
            else
            {
                bingo_board[i][j] = generate_random_number();
            }
        }
    }

    // Play the game
    int num_calls = 0;
    while (1)
    {
        int n = generate_random_number();
        printf("Call: %d\n", n);
        num_calls++;
        mark_number_on_bingo_board(bingo_board, n);
        display_bingo_board(bingo_board);
        if (check_bingo(bingo_board))
        {
            printf("Bingo! You won after %d calls.\n", num_calls);
            break;
        }
    }

    return 0;
}