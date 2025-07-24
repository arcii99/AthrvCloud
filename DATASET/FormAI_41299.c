//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 25
#define TOTAL_NUMS 25

void generateNumbers(int *nums, int count);
void fillCard(int (*card)[COLS], int *nums);
void displayCard(int (*card)[COLS]);
int checkRows(int (*card)[COLS]);
int checkCols(int (*card)[COLS]);
int checkDiagonals(int (*card)[COLS]);

int main()
{
    int nums[TOTAL_NUMS];
    int card[ROWS][COLS] = {0};

    printf("Welcome to Bingo Simulator!\n\n");

    generateNumbers(nums, TOTAL_NUMS);

    fillCard(card, nums);

    displayCard(card);

    while (1)
    {
        if (checkRows(card) || checkCols(card) | checkDiagonals(card))
        {
            printf("\nBingo! You won!\n");
            break;
        }

        printf("\nNo match! Generating another number...\n");

        int num = 0;
        while (num == 0)
        {
            num = nums[rand() % TOTAL_NUMS];
        }

        printf("The next number is: %d\n", num);

        for (int i = 0; i < TOTAL_NUMS; ++i)
        {
            if (nums[i] == num)
            {
                nums[i] = 0;
            }
        }

        fillCard(card, nums);

        displayCard(card);
    }

    return 0;
}

void generateNumbers(int *nums, int count)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < count; ++i)
    {
        nums[i] = i + 1;
    }
    for (i = count - 1; i > 0; --i)
    {
        int j = rand() % i;
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

void fillCard(int (*card)[COLS], int *nums)
{
    int i, j, k = 0;
    for (i = 0; i < ROWS; ++i)
    {
        for (j = 0; j < COLS; ++j)
        {
            card[i][j] = nums[k++];
        }
    }
}

void displayCard(int (*card)[COLS])
{
    int i, j;
    printf("\n");
    for (i = 0; i < ROWS; ++i)
    {
        for (j = 0; j < COLS; ++j)
        {
            printf("%2d ", card[i][j]);
        }
        printf("\n");
    }
}

int checkRows(int (*card)[COLS])
{
    int i, j, count;
    for (i = 0; i < ROWS; ++i)
    {
        count = 0;
        for (j = 0; j < COLS; ++j)
        {
            if (card[i][j] == 0)
            {
                ++count;
            }
        }
        if (count == COLS)
        {
            return 1;
        }
    }
    return 0;
}

int checkCols(int (*card)[COLS])
{
    int i, j, count;
    for (j = 0; j < COLS; ++j)
    {
        count = 0;
        for (i = 0; i < ROWS; ++i)
        {
            if (card[i][j] == 0)
            {
                ++count;
            }
        }
        if (count == ROWS)
        {
            return 1;
        }
    }
    return 0;
}

int checkDiagonals(int (*card)[COLS])
{
    int i, count = 0;
    for (i = 0; i < ROWS; ++i)
    {
        if (card[i][i] == 0)
        {
            ++count;
        }
    }
    if (count == ROWS)
    {
        return 1;
    }
    count = 0;
    for (i = 0; i < ROWS; ++i)
    {
        if (card[i][ROWS - i - 1] == 0)
        {
            ++count;
        }
    }
    if (count == ROWS)
    {
        return 1;
    }
    return 0;
}