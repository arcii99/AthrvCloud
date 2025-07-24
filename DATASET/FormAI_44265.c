//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: irregular
#include <stdio.h>
#include <string.h>
#define MAXLEN 20

int levenshtein_distance(char *s, char *t)
{
    int n = strlen(s), m = strlen(t);
    int dp[MAXLEN][MAXLEN];
    memset(dp, 0, sizeof(dp));

    // fill first row and column
    for (int i=0; i<=n; i++)
        dp[i][0] = i;
    for (int j=0; j<=m; j++)
        dp[0][j] = j;

    // fill rest of the table
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + (dp[i-1][j] < dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]);
        }
    }

    return dp[n][m];
}

int main()
{
    char s[MAXLEN], t[MAXLEN];
    printf("Enter two strings: ");
    scanf("%s %s", s, t);
    int distance = levenshtein_distance(s, t);
    printf("The Levenshtein distance between %s and %s is %d", s, t, distance);
    return 0;
}