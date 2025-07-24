//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void initialize_board(char board[ROWS][COLS])
{
    char letter = 'B';
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (i == 2 && j == 2) // free space in the middle
            {
                board[i][j] = ' ';
            }
            else
            {
                board[i][j] = letter;
                letter++;
            }
        }
    }
}

void print_board(char board[ROWS][COLS])
{
    printf("   B  I  N  G  O\n");
    for (int i = 0; i < ROWS; i++)
    {
        printf("%d", i+1);
        for (int j = 0; j < COLS; j++)
        {
            printf("  %c", board[i][j]);
        }
        printf("\n");
    }
}

int check_bingo(char board[ROWS][COLS])
{
    // check rows
    for (int i = 0; i < ROWS; i++)
    {
        int bingo = 1;
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] != 'X')
            {
                bingo = 0;
            }
        }
        if (bingo) return 1;
    }

    // check columns
    for (int i = 0; i < COLS; i++)
    {
        int bingo = 1;
        for (int j = 0; j < ROWS; j++)
        {
            if (board[j][i] != 'X')
            {
                bingo = 0;
            }
        }
        if (bingo) return 1;
    }

    // check diagonal (top left to bottom right)
    int bingo = 1;
    for (int i = 0; i < ROWS; i++)
    {
        if (board[i][i] != 'X')
        {
            bingo = 0;
        }
    }
    if (bingo) return 1;

    // check diagonal (top right to bottom left)
    bingo = 1;
    for (int i = 0; i < ROWS; i++)
    {
        if (board[i][COLS-i-1] != 'X')
        {
            bingo = 0;
        }
    }
    if (bingo) return 1;

    return 0;
}

int main()
{
    char board[ROWS][COLS];
    initialize_board(board);
    print_board(board);

    // initialize array of integers for used numbers
    int used_numbers[76];
    for (int i = 0; i < 76; i++)
    {
        used_numbers[i] = 0;
    }

    // generate random numbers and mark them on the board
    int count = 0;
    while (!check_bingo(board))
    {
        srand(time(NULL));
        int num = rand() % 75 + 1; // generate a random number between 1 and 75
        if (!used_numbers[num])
        {
            used_numbers[num] = 1;
            printf("The number is: %d\n", num);
            // mark the number on the board
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    if (board[i][j] == num + '0')
                    {
                        board[i][j] = 'X';
                    }
                }
            }
            print_board(board);
        }
        count++;
    }

    printf("Bingo! It took %d numbers to win.\n", count);

    return 0;
}