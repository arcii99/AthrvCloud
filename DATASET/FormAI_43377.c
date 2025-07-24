//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100 // Maximum Length

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int levenshteinDistance(char *str1, char *str2)
{
    int m = strlen(str1);
    int n = strlen(str2);

    int dp[m+1][n+1];

    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[m][n];
}

int main()
{
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Enter two strings to find their Levenshtein distance:\n");

    char str1[MAX_LEN], str2[MAX_LEN];
    printf("String 1: ");
    fgets(str1, MAX_LEN, stdin);
    str1[strcspn(str1, "\n")] = 0; // remove newline character
    printf("String 2: ");
    fgets(str2, MAX_LEN, stdin);
    str2[strcspn(str2, "\n")] = 0; // remove newline character

    int distance = levenshteinDistance(str1, str2);
    printf("The Levenshtein distance between '%s' and '%s' is: %d", str1, str2, distance);

    return 0;
}