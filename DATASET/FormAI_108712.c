//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z)
{
    if (x < y && x < z)
        return x;
    else if (y < x && y < z)
        return y;
    else
        return z;
}

int levenshtein_distance(char *str1, char *str2)
{
    int m = strlen(str1);
    int n = strlen(str2);

    // create a 2D array for storing distances
    int **dp = (int **)malloc(sizeof(int *) * (m + 1));
    for (int i = 0; i < m + 1; i++)
        dp[i] = (int *)malloc(sizeof(int) * (n + 1));

    // initialize the first row and column
    for (int i = 0; i < m + 1; i++)
        dp[i][0] = i;

    for (int j = 1; j < n + 1; j++)
        dp[0][j] = j;

    // fill the matrix
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int distance = dp[m][n];

    // free the memory
    for (int i = 0; i < m + 1; i++)
        free(dp[i]);
    free(dp);

    return distance;
}

int main()
{
    char str1[] = "kitten";
    char str2[] = "sitting";

    int distance = levenshtein_distance(str1, str2);

    printf("The Levenshtein distance between %s and %s is %d\n", str1, str2, distance);

    return 0;
}