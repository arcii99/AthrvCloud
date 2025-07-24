//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function to generate random numbers for each cell on the bingo card
void generateCard(int card[][COLS])
{
    int nums[75] = {0}; // Array to keep track of generated numbers
    int row, col, num;

    // Generate random numbers for each cell of the card
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            // Generate a unique random number between 1-75 for each cell
            do {
                num = rand() % 75 + 1;
            } while (nums[num-1] == 1);
            nums[num-1] = 1;
            card[row][col] = num;
        }
    }
}

// Function to mark called numbers on the card and check for a bingo
int checkForBingo(int card[][COLS], int calledNums[])
{
    int row, col, i, j, cnt;

    // Mark called numbers on the card
    for (i = 0; i < 75; i++)
    {
        for (row = 0; row < ROWS; row++)
        {
            for (col = 0; col < COLS; col++)
            {
                if (card[row][col] == calledNums[i])
                {
                    card[row][col] = 0; // Mark called number as 0 on the card
                }
            }
        }

        // Check for a bingo
        cnt = 0;
        // Check rows
        for (row = 0; row < ROWS; row++)
        {
            for (col = 0; col < COLS; col++)
            {
                if (card[row][col] == 0)
                {
                    cnt++;
                }
            }
            if (cnt == 5)
            {
                return 1; // Bingo!
            }
            cnt = 0;
        }
        // Check columns
        for (col = 0; col < COLS; col++)
        {
            for (row = 0; row < ROWS; row++)
            {
                if (card[row][col] == 0)
                {
                    cnt++;
                }
            }
            if (cnt == 5)
            {
                return 1; // Bingo!
            }
            cnt = 0;
        }
        // Check diagonals
        if (card[0][0] == 0 && card[1][1] == 0 && card[2][2] == 0 && card[3][3] == 0 && card[4][4] == 0)
        {
            return 1; // Bingo!
        }
        if (card[0][4] == 0 && card[1][3] == 0 && card[2][2] == 0 && card[3][1] == 0 && card[4][0] == 0)
        {
            return 1; // Bingo!
        }
    }

    return 0; // No bingo yet
}

// Main function to play the game
int main()
{
    int card[ROWS][COLS] = {0}; // Bingo card
    int calledNums[75] = {0}; // Array to keep track of called numbers
    int num, i, bingo;

    // Initialize random number generator
    srand(time(NULL));

    // Generate bingo card
    generateCard(card);

    // Print bingo card
    printf("Bingo Card:\n");
    for (i = 0; i < ROWS; i++)
    {
        printf("| %2d | %2d | %2d | %2d | %2d |\n", card[i][0], card[i][1], card[i][2], card[i][3], card[i][4]);
    }
    printf("\n");

    // Play the game
    i = 0;
    bingo = 0;
    while (!bingo)
    {
        // Generate a unique random number between 1-75
        do {
            num = rand() % 75 + 1;
        } while (calledNums[num-1] == 1);
        calledNums[num-1] = 1;

        // Print called number
        printf("Called number: %d\n", num);

        // Check for a bingo
        bingo = checkForBingo(card, calledNums);
        i++;
    }

    // Print number of calls it took to get a bingo
    printf("Bingo! It took %d calls to get a bingo.\n", i);

    return 0;
}