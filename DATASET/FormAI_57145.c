//FormAI DATASET v1.0 Category: Data mining ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 10
#define NUM_COLS 5

int main()
{
    int data[NUM_ROWS][NUM_COLS] = {{1,2,3,4,5},
                                    {6,7,8,9,10},
                                    {11,12,13,14,15},
                                    {16,17,18,19,20},
                                    {21,22,23,24,25},
                                    {26,27,28,29,30},
                                    {31,32,33,34,35},
                                    {36,37,38,39,40},
                                    {41,42,43,44,45},
                                    {46,47,48,49,50}};

    int mean[NUM_COLS] = {0};
    int std_dev[NUM_COLS] = {0};

    // Calculate the mean values of each column
    for (int c = 0; c < NUM_COLS; c++)
    {
        int sum = 0;
        for (int r = 0; r < NUM_ROWS; r++)
        {
            sum += data[r][c];
        }
        mean[c] = sum / NUM_ROWS;
    }

    // Calculate the standard deviation of each column
    for (int c = 0; c < NUM_COLS; c++)
    {
        int sum = 0;
        for (int r = 0; r < NUM_ROWS; r++)
        {
            sum += (data[r][c] - mean[c]) * (data[r][c] - mean[c]);
        }
        std_dev[c] = sqrt(sum / NUM_ROWS);
    }

    // Print the results
    printf("Mean: ");
    for (int c = 0; c < NUM_COLS; c++)
    {
        printf("%d ", mean[c]);
    }
    printf("\n");

    printf("Standard Deviation: ");
    for (int c = 0; c < NUM_COLS; c++)
    {
        printf("%d ", std_dev[c]);
    }
    printf("\n");

    return 0;
}