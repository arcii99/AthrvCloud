//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number for bingo board
int generateRandomNumber(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a 5x5 bingo board
    int bingoBoard[5][5] = {0};

    // Fill the board with random numbers
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            // Generate a random number for the cell
            int num = generateRandomNumber((row * 15) + 1, ((row + 1) * 15));

            // Check if the number already exists in the board
            int exists = 0;
            for (int i = 0; i < row; i++)
            {
                if (bingoBoard[i][col] == num)
                {
                    exists = 1;
                    break;
                }
            }
            if (exists == 1)
            {
                col--;
                continue;
            }

            // Store the generated number in the board
            bingoBoard[row][col] = num;
        }
    }

    // Print out the board
    printf("B I N G O\n");
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            printf("%d ", bingoBoard[row][col]);
        }
        printf("\n");
    }

    return 0;
}