//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MIN_NUM 1
#define MAX_NUM 75

// Fill the bingo card with random numbers
void fillBingoCard(int bingoCard[ROWS][COLS])
{
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            bingoCard[i][j] = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
        }
    }
}

// Display the bingo card
void displayBingoCard(int bingoCard[ROWS][COLS])
{
    printf("\n B  I  N  G  O\n");
    for (int i = 0; i < ROWS; i++)
     {
        for (int j = 0; j < COLS; j++)
        {
            if (bingoCard[i][j] < 10)
                printf(" ");
            printf("%d ", bingoCard[i][j]);   
        }
        printf("\n");
     }
}

// Check if there is a winning pattern
int checkForWinningPattern(int bingoCard[ROWS][COLS])
{
    // Check all rows for a winning pattern
    for (int i = 0; i < ROWS; i++)
    {
        if (bingoCard[i][0] == 0 && bingoCard[i][1] == 0 && bingoCard[i][2] == 0 && bingoCard[i][3] == 0 && bingoCard[i][4] == 0)
            return 1;
    }

    // Check all columns for a winning pattern
    for (int i = 0; i < COLS; i++)
    {
        if (bingoCard[0][i] == 0 && bingoCard[1][i] == 0 && bingoCard[2][i] == 0 && bingoCard[3][i] == 0 && bingoCard[4][i] == 0)
            return 1;
    }

    // Check the diagonal for a winning pattern
    if (bingoCard[0][0] == 0 && bingoCard[1][1] == 0 && bingoCard[2][2] == 0 && bingoCard[3][3] == 0 && bingoCard[4][4] == 0)
        return 1;

    // Check the reverse diagonal for a winning pattern
    if (bingoCard[0][4] == 0 && bingoCard[1][3] == 0 && bingoCard[2][2] == 0 && bingoCard[3][1] == 0 && bingoCard[4][0] == 0)
        return 1;

    return 0;
}

int main()
{
    // Initialize the bingo card with zeros
    int bingoCard[ROWS][COLS] = {{0}};

    // Fill the bingo card with random numbers
    fillBingoCard(bingoCard);

    // Display the bingo card
    displayBingoCard(bingoCard);

    // Play the game until there is a winning pattern
    int bingoNumber;
    int isWinner = 0;
    while (!isWinner)
    {
        printf("\nEnter the next bingo number (1-75): ");
        scanf("%d", &bingoNumber);

        // Mark the number on the bingo card
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (bingoCard[i][j] == bingoNumber)
                    bingoCard[i][j] = 0;
            }
        }

        // Display the updated bingo card
        displayBingoCard(bingoCard);

        // Check if there is a winning pattern
        if (checkForWinningPattern(bingoCard))
        {
            printf("\nCongratulations! You have won the game.\n");
            isWinner = 1;
        }
    }

    return 0;
}