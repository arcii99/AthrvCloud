//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Alan Touring
// Welcome to the Bingo Simulator in C!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function to display the Bingo card
void displayCard(int card[ROWS][COLS])
{
    printf("B\tI\tN\tG\tO\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d\t", card[i][j]);
        }
        printf("\n");
    }
}

// Function to generate random numbers for the Bingo card
void generateNumbers(int card[ROWS][COLS])
{
    int nums[5][15] = {{0}};
    for (int i = 0, j = 0; i < 5; i++)
    {
        j = i == 2 ? j : 1;
        for (; j < 15;)
        {
            int num = (rand() % 15) + ((i * 15) + 1);
            if (!nums[i][num - ((i * 15) + 1)])
            {
                nums[i][num - ((i * 15) + 1)] = 1;
                card[i][j++] = num;
            }
        }
    }
}

// Function to get user input for the Bingo call
void getUserInput(int *row, int *col)
{
    printf("Enter the row and column of the number called (ex: '3 2'): ");
    scanf("%d %d", row, col);
}

// Function to check if there is a Bingo
int checkBingo(int card[ROWS][COLS])
{
    int bingo = 0;
    // Check rows
    for (int i = 0; i < ROWS; i++)
    {
        int sum = 0;
        for (int j = 0; j < COLS; j++)
        {
            sum += card[i][j];
        }
        if (sum == 0)
        {
            bingo = 1;
            break;
        }
    }
    // Check columns
    if (!bingo)
    {
        for (int i = 0; i < COLS; i++)
        {
            int sum = 0;
            for (int j = 0; j < ROWS; j++)
            {
                sum += card[j][i];
            }
            if (sum == 0)
            {
                bingo = 1;
                break;
            }
        }
    }
    // Check diagonals
    if (!bingo)
    {
        int sum = 0;
        for (int i = 0; i < ROWS; i++)
        {
            sum += card[i][i];
        }
        if (sum == 0)
        {
            bingo = 1;
        }
    }
    if (!bingo)
    {
        int sum = 0;
        for (int i = 0; i < ROWS; i++)
        {
            sum += card[i][(ROWS - 1) - i];
        }
        if (sum == 0)
        {
            bingo = 1;
        }
    }
    return bingo;
}

int main()
{
    // Initialize the Bingo card
    int card[ROWS][COLS] = {{0}};
    generateNumbers(card);
    displayCard(card);
    printf("\n");
    int turns = 0;

    // Start the game
    while (1)
    {
        int row, col;
        getUserInput(&row, &col);
        if (card[row - 1][col - 1] == 0)
        {
            printf("Number already called, try again.\n");
            continue;
        }
        card[row - 1][col - 1] = 0;
        turns++;
        displayCard(card);
        printf("\n");
        if (checkBingo(card))
        {
            printf("Bingo! It took you %d turns.\n", turns);
            break;
        }
    }
    return 0;
}