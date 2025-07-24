//FormAI DATASET v1.0 Category: Game of Life ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// array dimensions
#define ROWS 30
#define COLS 60

// game of life rules
#define ALIVE 1
#define DEAD 0

// maximum number of generations
#define MAX_GEN 100

// function prototypes
void initialize_board(int board[][COLS]);
void print_board(int board[][COLS]);
void next_generation(int board[][COLS]);

int main()
{
    int board[ROWS][COLS]; // the game board
    int generation = 0; // current generation

    srand(time(NULL)); // seed the random number generator

    initialize_board(board); // initialize the game board

    while (generation < MAX_GEN)
    {
        printf("\nGeneration %d:\n", generation);
        print_board(board); // print the current game board
        next_generation(board); // calculate the next generation
        generation++; // increment the generation counter
    }

    return 0;
}

// initialize the game board
void initialize_board(int board[][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            // randomly assign cells to be alive or dead
            board[i][j] = rand() % 2;
        }
    }
}

// print the game board
void print_board(int board[][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (board[i][j] == ALIVE)
            {
                printf("*");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
}

// calculate the next generation of the game board
void next_generation(int board[][COLS])
{
    int i, j;
    int neighbors;
    int next_board[ROWS][COLS]; // temporary board for calculating next generation

    // initialize the temporary board to be all dead
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            next_board[i][j] = DEAD;
        }
    }

    // loop through each cell in the game board
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            neighbors = 0;

            // count the number of alive neighbors
            if (i > 0 && j > 0 && board[i-1][j-1] == ALIVE)
            {
                neighbors++;
            }
            if (i > 0 && board[i-1][j] == ALIVE)
            {
                neighbors++;
            }
            if (i > 0 && j < COLS-1 && board[i-1][j+1] == ALIVE)
            {
                neighbors++;
            }
            if (j > 0 && board[i][j-1] == ALIVE)
            {
                neighbors++;
            }
            if (j < COLS-1 && board[i][j+1] == ALIVE)
            {
                neighbors++;
            }
            if (i < ROWS-1 && j > 0 && board[i+1][j-1] == ALIVE)
            {
                neighbors++;
            }
            if (i < ROWS-1 && board[i+1][j] == ALIVE)
            {
                neighbors++;
            }
            if (i < ROWS-1 && j < COLS-1 && board[i+1][j+1] == ALIVE)
            {
                neighbors++;
            }

            // apply the game of life rules
            if (board[i][j] == ALIVE && neighbors < 2)
            {
                next_board[i][j] = DEAD; // underpopulation
            }
            else if (board[i][j] == ALIVE && neighbors > 3)
            {
                next_board[i][j] = DEAD; // overpopulation
            }
            else if (board[i][j] == DEAD && neighbors == 3)
            {
                next_board[i][j] = ALIVE; // reproduction
            }
            else
            {
                next_board[i][j] = board[i][j]; // no change
            }
        }
    }

    // copy the temporary board to the game board
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            board[i][j] = next_board[i][j];
        }
    }
}