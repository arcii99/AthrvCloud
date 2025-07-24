//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void print_board(int board[ROWS][COLS]);
void get_random_numbers(int arr[], int size);
void populate_board(int board[ROWS][COLS], int arr[], int size);
int check_bingo(int board[ROWS][COLS]);
int check_rows(int board[ROWS][COLS]);
int check_cols(int board[ROWS][COLS]);
int check_diagonals(int board[ROWS][COLS]);

int main()
{
    int board[ROWS][COLS] = {0};
    int numbers[75] = {0};
    int count = 0;
    int winner = 0;

    srand(time(NULL));
    get_random_numbers(numbers, 75);
    populate_board(board, numbers, 75);

    print_board(board);

    while (!winner)
    {
        int number = 0;
        printf("Enter the number: ");
        scanf("%d", &number);

        for (int i = 0; i < 75; i++)
        {
            if (numbers[i] == number)
            {
                numbers[i] = 0;
                count++;
                break;
            }
        }

        populate_board(board, numbers, 75);
        print_board(board);

        winner = check_bingo(board);
        if (winner)
        {
            printf("BINGO!!!");
            break;
        }

        if (count == 75)
        {
            printf("Game Over. No Winner.");
            break;
        }
    }
    return 0;
}

void print_board(int board[ROWS][COLS])
{
    printf("B  I  N  G  O\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] == 0)
            {
                printf("X  ");
            }
            else
            {
                printf("%d  ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void get_random_numbers(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }

    for (int i = 0; i < size; i++)
    {
        int j = rand() % size;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void populate_board(int board[ROWS][COLS], int arr[], int size)
{
    int index = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = arr[index];
            index++;
        }
    }
}

int check_bingo(int board[ROWS][COLS])
{
    int rows = check_rows(board);
    int cols = check_cols(board);
    int diagonals = check_diagonals(board);

    return (rows + cols + diagonals);
}

int check_rows(int board[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        int count = 0;
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] == 0)
            {
                count++;
            }
        }
        if (count == 5)
        {
            return 1;
        }
    }
    return 0;
}

int check_cols(int board[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        int count = 0;
        for (int j = 0; j < COLS; j++)
        {
            if (board[j][i] == 0)
            {
                count++;
            }
        }
        if (count == 5)
        {
            return 1;
        }
    }
    return 0;
}

int check_diagonals(int board[ROWS][COLS])
{
    int count = 0;
    for (int i = 0; i < ROWS; i++)
    {
        if (board[i][i] == 0)
        {
            count++;
        }
        if (board[i][ROWS-i-1] == 0)
        {
            count++;
        }
    }
    if (count == 10)
    {
        return 1;
    }
    return 0;
}