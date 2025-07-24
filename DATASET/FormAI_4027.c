//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants for game board
#define ROWS 10
#define COLUMNS 20

// function prototype definitions
void printBoard(char board[ROWS][COLUMNS]);
void generateBoard(char board[ROWS][COLUMNS]);

// main function
int main(void)
{
    // initialize random seed
    srand(time(NULL));

    // declare game board array
    char board[ROWS][COLUMNS];

    // generate game board
    generateBoard(board);

    // print game board
    printBoard(board);

    return 0;
}

// function to print game board
void printBoard(char board[ROWS][COLUMNS])
{
    // loop through rows of board
    for (int i = 0; i < ROWS; i++)
    {
        // loop through columns of board
        for (int j = 0; j < COLUMNS; j++)
        {
            // print character at current position
            printf("%c", board[i][j]);
        }

        // print newline character at end of row
        printf("\n");
    }
}

// function to generate game board
void generateBoard(char board[ROWS][COLUMNS])
{
    // loop through rows of board
    for (int i = 0; i < ROWS; i++)
    {
        // loop through columns of board
        for (int j = 0; j < COLUMNS; j++)
        {
            // generate random number between 0 and 99
            int random = rand() % 100;

            // set character at current position based on random number
            if (random < 5)
            {
                board[i][j] = '*'; // 5% chance of treasure
            }
            else if (random < 10)
            {
                board[i][j] = '^'; // 5% chance of trap
            }
            else if (random < 50)
            {
                board[i][j] = '.'; // 40% chance of empty space
            }
            else
            {
                board[i][j] = '#'; // 50% chance of wall
            }
        }
    }
}