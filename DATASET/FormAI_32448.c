//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: unmistakable
#include <stdio.h>
#include <string.h>

// Function to calculate the minimum of three numbers
int minimum(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else
        return c;
}

// Function to calculate Levenshtein distance
int levenshtein_distance(char *s1, char *s2)
{
    int n1 = strlen(s1);
    int n2 = strlen(s2);

    int dp[n1+1][n2+1];

    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + minimum(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    }

    return dp[n1][n2];
}

int main()
{
    char str1[100], str2[100];
    printf("Enter the two strings: ");
    scanf("%s %s", str1, str2);
    int distance = levenshtein_distance(str1, str2);
    printf("The Levenshtein distance between %s and %s is %d.\n", str1, str2, distance);
    return 0;
}