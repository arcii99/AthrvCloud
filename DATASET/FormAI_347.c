//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define BINGO_NUMS 25

int isBingo(int bingoCard[ROWS][COLS]);
void printCard(int bingoCard[ROWS][COLS]);
void genRandNums(int randNums[BINGO_NUMS]);

int main()
{
    int bingoCard[ROWS][COLS] = {0};
    int randNums[BINGO_NUMS];

    srand(time(NULL));
    genRandNums(randNums);

    // Populate Bingo Card
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (i == 2 && j == 2)
            {
                continue; // Free Space
            }
            bingoCard[i][j] = randNums[i * COLS + j];
        }
    }

    // printf("Generated Bingo Card:\n");
    // printCard(bingoCard);

    int numCalled = 0;
    while(!isBingo(bingoCard))
    {
        numCalled++;
        int calledNum = randNums[BINGO_NUMS - numCalled];
        //printf("Called Number: %d\n", calledNum);

        // Mark Number on Card
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (bingoCard[i][j] == calledNum)
                {
                    bingoCard[i][j] = -1;
                    break;
                }
            }
        }
        // printf("Updated Bingo Card:\n");
        // printCard(bingoCard);
    }

    printf("BINGO! Number of balls called: %d\n", numCalled);

    return 0;
}

void genRandNums(int randNums[BINGO_NUMS])
{
    int numsLeft = BINGO_NUMS;
    for(int i = 0; i < BINGO_NUMS; i++)
    {
        randNums[i] = i + 1;
    }

    // Shuffle Array
    for(int i = 0; i < BINGO_NUMS; i++)
    {
        int j = i + rand() % (numsLeft--);
        int temp = randNums[i];
        randNums[i] = randNums[j];
        randNums[j] = temp;
    }
}

int isBingo(int bingoCard[ROWS][COLS])
{
    // Check Rows
    for (int i = 0; i < ROWS; i++)
    {
        int sum = 0;
        for (int j = 0; j < COLS; j++)
        {
            sum += bingoCard[i][j];
        }
        if (sum == -COLS) return 1; // Bingo!
    }

    // Check Columns
    for (int i = 0; i < COLS; i++)
    {
        int sum = 0;
        for (int j = 0; j < ROWS; j++)
        {
            sum += bingoCard[j][i];
        }
        if (sum == -ROWS) return 1; // Bingo!
    }

    // Check Diagonals
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < ROWS; i++)
    {
        sum1 += bingoCard[i][i];
        sum2 += bingoCard[i][ROWS - 1 - i];
    }
    if (sum1 == -COLS || sum2 == -ROWS) return 1; // Bingo!

    return 0; // No Bingo yet
}

void printCard(int bingoCard[ROWS][COLS])
{
    printf("---------------------------\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (bingoCard[i][j] == -1)
            {
                printf("|  F ");
            }
            else
            {
                printf("| %2d ", bingoCard[i][j]);
            }
        }
        printf("|\n---------------------------\n");
    }
}