//FormAI DATASET v1.0 Category: Game of Life ; Style: cheerful
/* Welcome to the Happy Game of Life! */
/* This program is a cheerful version of the famous Game of Life */
/* Created by [Your Name] */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLUMNS 40

/* Function prototypes */
void initialize_board(int board[ROWS][COLUMNS]);
void print_board(int board[ROWS][COLUMNS], int generation);
void update_board(int board[ROWS][COLUMNS]);

int main(void)
{
    int board[ROWS][COLUMNS];
    int generation = 0;

    /* Initializing the board */
    initialize_board(board);

    /* Main game loop */
    while (1)
    {
        system("clear"); /* Clearing the console */

        print_board(board, generation); /* Printing the board */

        update_board(board); /* Updating the board */

        generation++; /* Increasing the generation counter */

        sleep(1); /* Waiting for one second */
    }

    return 0;
}

/* This function initializes the board with random values */
void initialize_board(int board[ROWS][COLUMNS])
{
    int i, j;
    srand(time(NULL)); /* Initializing the random number generator */

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLUMNS; j++)
        {
            board[i][j] = rand() % 2; /* Filling the board with random values (0 or 1) */
        }
    }
}

/* This function prints the board to the console */
void print_board(int board[ROWS][COLUMNS], int generation)
{
    int i, j;
    printf("Welcome to the Happy Game of Life - Generation %d\n\n", generation);

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLUMNS; j++)
        {
            if (board[i][j] == 0)
            {
                /* Cheerful smiley face for dead cells */
                printf(":)");

            }
            else
            {
                /* Also cheerful smiley face for living cells */
                printf(":D");
            }
        }
        printf("\n");
    }
}

/* This function updates the board according to the rules of the game of life */
void update_board(int board[ROWS][COLUMNS])
{
    int i, j;
    int new_board[ROWS][COLUMNS];

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLUMNS; j++)
        {
            int neighbors = 0;
            int k, l;

            /* Counting the number of living neighbors */
            for (k = i - 1; k <= i + 1; k++)
            {
                for (l = j - 1; l <= j + 1; l++)
                {
                    if (k >= 0 && k < ROWS && l >= 0 && l < COLUMNS && !(k == i && l == j))
                    {
                        neighbors += board[k][l];
                    }
                }
            }

            /* Applying the rules of the game */
            if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3))
            {
                new_board[i][j] = 0;
            }
            else if (board[i][j] == 0 && neighbors == 3)
            {
                new_board[i][j] = 1;
            }
            else
            {
                new_board[i][j] = board[i][j];
            }
        }
    }

    /* Copying the new board to the original board */
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLUMNS; j++)
        {
            board[i][j] = new_board[i][j];
        }
    }
}