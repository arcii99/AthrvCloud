//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: ephemeral
#include<stdio.h>
#include<string.h>

#define MAX_LEN 100

int min(int a, int b, int c)
{
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int levenshteinDistance(char* str1, char* str2, int len1, int len2)
{
    int dp[MAX_LEN][MAX_LEN];

    for(int i = 0; i <= len1; i++)
        dp[i][0] = i;

    for(int j = 0; j <= len2; j++)
        dp[0][j] = j;
        
    for(int i = 1; i <= len1; i++)
    {
        for(int j = 1; j <= len2; j++)
        {
            if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
        }
    }
    return dp[len1][len2];
}

int main()
{
    char str1[MAX_LEN], str2[MAX_LEN];
    int len1, len2;

    printf("Enter String 1: ");
    scanf("%s", str1);
    len1 = strlen(str1);

    printf("Enter String 2: ");
    scanf("%s", str2);
    len2 = strlen(str2);

    printf("Levenshtein Distance: %d\n", levenshteinDistance(str1, str2, len1, len2));
    return 0;
}