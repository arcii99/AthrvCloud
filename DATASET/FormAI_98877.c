//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants
#define ROWS 5
#define COLS 5
#define FREE_SPACE_ROW 2
#define FREE_SPACE_COL 2

// function prototypes
void init_board(int board[ROWS][COLS]);
void print_board(int board[ROWS][COLS]);
int call_number(int numbers_called[], int *num_called_count);
int check_bingo(int board[ROWS][COLS]);

// main function
int main()
{
    // seed random number generator
    srand(time(NULL));

    // initialize board and variables
    int board[ROWS][COLS];
    int numbers_called[ROWS * COLS];
    int num_called_count = 0;
    int bingo = 0;

    // initialize board and print starting board
    init_board(board);
    printf("-------------- BINGO --------------\n");
    printf("   B   I   N   G   O\n");
    print_board(board);

    // play the game
    while (!bingo)
    {
        // call a number
        int number = call_number(numbers_called, &num_called_count);
        printf("Called number: %d\n", number);

        // mark the number on the board
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (board[i][j] == number)
                {
                    board[i][j] = 0;
                }
            }
        }

        // print updated board
        printf("   B   I   N   G   O\n");
        print_board(board);

        // check for bingo
        bingo = check_bingo(board);
        if (bingo)
        {
            printf("BINGO!\n");
        }
    }

    return 0;
}

// initialize the board
void init_board(int board[ROWS][COLS])
{
    // fill board with random numbers
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (i == FREE_SPACE_ROW && j == FREE_SPACE_COL)
            {
                board[i][j] = 0;
            }
            else
            {
                board[i][j] = rand() % 15 + 15 * j + 1;
            }
        }
    }
}

// print the board
void print_board(int board[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        printf("-----------------------\n");
        for (int j = 0; j < COLS; j++)
        {
            printf("| %2d ", board[i][j]);
        }
        printf("|\n");
    }
    printf("-----------------------\n");
}

// call a number
int call_number(int numbers_called[], int *num_called_count)
{
    // generate random number
    int number;
    do
    {
        number = rand() % 75 + 1;
    } while (numbers_called[number] != 0);

    // mark number as called
    numbers_called[number] = 1;
    (*num_called_count)++;

    return number;
}

// check for bingo
int check_bingo(int board[ROWS][COLS])
{
    // check rows and columns
    for (int i = 0; i < ROWS; i++)
    {
        int row_sum = 0;
        int col_sum = 0;
        for (int j = 0; j < COLS; j++)
        {
            row_sum += board[i][j];
            col_sum += board[j][i];
        }
        if (row_sum == 0 || col_sum == 0)
        {
            return 1;
        }
    }

    // check diagonals
    if ((board[0][0] == 0 && board[1][1] == 0 && board[2][2] == 0 && board[3][3] == 0 && board[4][4] == 0) ||
        (board[0][4] == 0 && board[1][3] == 0 && board[2][2] == 0 && board[3][1] == 0 && board[4][0] == 0))
    {
        return 1;
    }

    return 0;
}