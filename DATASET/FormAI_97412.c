//FormAI DATASET v1.0 Category: Data mining ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 5

int main()
{
    int dataset[MAX_ROWS][MAX_COLS] = {{1, 2, 3, 4, 5},
                                        {6, 7, 8, 9, 10},
                                        {11, 12, 13, 14, 15},
                                        {16, 17, 18, 19, 20},
                                        {21, 22, 23, 24, 25},
                                        {26, 27, 28, 29, 30},
                                        {31, 32, 33, 34, 35},
                                        {36, 37, 38, 39, 40},
                                        {41, 42, 43, 44, 45},
                                        {46, 47, 48, 49, 50}};

    int min_value = dataset[0][0];
    int max_value = dataset[0][0];
    int row_sum[MAX_ROWS] = {0};
    int col_sum[MAX_COLS] = {0};

    // Find the minimum and maximum value
    for (int i = 0; i < MAX_ROWS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            if (dataset[i][j] < min_value)
                min_value = dataset[i][j];
            if (dataset[i][j] > max_value)
                max_value = dataset[i][j];

            row_sum[i] += dataset[i][j];
            col_sum[j] += dataset[i][j];
        }
    }

    printf("Minimum value in dataset: %d\n", min_value);
    printf("Maximum value in dataset: %d\n", max_value);

    // Print the row and column sums
    printf("Row sums:\n");
    for (int i = 0; i < MAX_ROWS; i++)
    {
        printf("%d ", row_sum[i]);
    }
    printf("\n");

    printf("Column sums:\n");
    for (int j = 0; j < MAX_COLS; j++)
    {
        printf("%d ", col_sum[j]);
    }
    printf("\n");

    return 0;
}