//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 25

int main(void)
{
    srand(time(NULL)); // Initializing random number generator

    // Creating a 5x5 matrix to represent the bingo card
    int bingo[ROWS][COLS] = {0};

    // Populating the matrix with random numbers from 1 to 25
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int num = (rand() % MAX_NUM) + 1;
            bingo[i][j] = num;

            // Ensuring that there are no duplicate numbers in the same column
            for (int k = 0; k < i; k++)
            {
                if (bingo[k][j] == num)
                {
                    j--;
                    break;
                }
            }
        }
    }

    // Printing out the bingo card
    printf("B\tI\tN\tG\tO\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d\t", bingo[i][j]);
        }
        printf("\n");
    }

    // Simulating the game
    int nums[MAX_NUM] = {0}; // Array to keep track of the called numbers
    int num_of_calls = 0;

    printf("Starting the game, good luck!\n");

    while (1)
    {
        int num = (rand() % MAX_NUM) + 1;
        nums[num - 1] = 1; // Marking the number as called
        num_of_calls++;

        printf("The number called is: %d\n", num);

        // Checking if the called number appears on the bingo card
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (bingo[i][j] == num)
                {
                    bingo[i][j] = 0; // Marking the number as checked off the card
                }
            }
        }

        // Checking if any row has all zeroes (i.e. all numbers checked off)
        int winning_row = -1;
        for (int i = 0; i < ROWS; i++)
        {
            int zeroes_in_row = 0;
            for (int j = 0; j < COLS; j++)
            {
                if (bingo[i][j] == 0)
                {
                    zeroes_in_row++;
                }
            }
            if (zeroes_in_row == COLS)
            {
                winning_row = i;
                break;
            }
        }

        if (winning_row != -1)
        {
            printf("Congratulations, you have a bingo! You won after %d calls.\n", num_of_calls);
            printf("The winning row is: ");
            for (int j = 0; j < COLS; j++)
            {
                printf("%d ", bingo[winning_row][j]);
            }
            printf("\n");
            break;
        }

        // Checking if any column has all zeroes (i.e. all numbers checked off)
        int winning_col = -1;
        for (int j = 0; j < COLS; j++)
        {
            int zeroes_in_col = 0;
            for (int i = 0; i < ROWS; i++)
            {
                if (bingo[i][j] == 0)
                {
                    zeroes_in_col++;
                }
            }
            if (zeroes_in_col == ROWS)
            {
                winning_col = j;
                break;
            }
        }

        if (winning_col != -1)
        {
            printf("Congratulations, you have a bingo! You won after %d calls.\n", num_of_calls);
            printf("The winning column is: ");
            for (int i = 0; i < ROWS; i++)
            {
                printf("%d\n", bingo[i][winning_col]);
            }
            printf("\n");
            break;
        }
    }

    printf("Thanks for playing!\n");

    return 0;
}