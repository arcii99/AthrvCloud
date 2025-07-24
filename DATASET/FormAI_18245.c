//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

// Function to print the Bingo board
void print_board(int board[][SIZE])
{
    printf("B      I      N      G      O\n");
    printf("-----------------------------\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == -1)
            {
                printf("|   X   ");
            }
            else
            {
                printf("|  %2d   ", board[i][j]);
            }
        }
        printf("|\n");
        printf("-----------------------------\n");
    }
}

int main()
{
    int board[SIZE][SIZE] = {0};
    int caller[75] = {0};

    // Generating all possible random numbers for caller
    for (int i = 0; i < 75; i++)
    {
        caller[i] = i + 1;
    }

    // Shuffling the caller array
    srand(time(NULL));
    for (int i = 0; i < 75; i++)
    {
        int rand_index = rand() % 75;
        int temp = caller[i];
        caller[i] = caller[rand_index];
        caller[rand_index] = temp;
    }

    // Placing the numbers on the board
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            int index = i * SIZE + j;
            board[i][j] = caller[index];
        }
    }

    // Marking the center square as already called
    board[SIZE / 2][SIZE / 2] = -1;

    // Printing the Bingo board
    print_board(board);

    printf("\n\n");

    // Calling out random numbers
    for (int i = 0; i < 75; i++)
    {
        printf("Number called: %d\n", caller[i]);
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < SIZE; k++)
            {
                if (board[j][k] == caller[i])
                {
                    board[j][k] = -1;
                }
            }
        }

        // Printing the updated Bingo board
        print_board(board);

        printf("\n\n");

        // Checking for a Bingo
        int bingo = 0;
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < SIZE; k++)
            {
                if (board[j][k] != -1)
                {
                    bingo = 1;
                    break;
                }
            }
            if (bingo == 1)
            {
                break;
            }
        }
        if (bingo == 0)
        {
            printf("Bingo! You have won at %dth call.\n", i+1);
            break;
        }

        // Pausing the program for dramatic effect
        printf("Press ENTER to continue.\n");
        while (getchar() != '\n');
    }

    return 0;
}