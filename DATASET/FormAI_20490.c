//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Cyberpunk
#include<stdio.h>
#include<string.h>

int min(int a, int b, int c)
{
    if(a < b && a < c)
        return a;
    else if(b < a && b < c)
        return b;
    else
        return c;
}

int levenshtein(char* s1, char* s2)
{
    int m = strlen(s1);
    int n = strlen(s2);
 
    int dp[m+1][n+1];

    for(int i=0; i<=m; i++)
        dp[i][0] = i;
    for(int j=0; j<=n; j++)
        dp[0][j] = j;

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
        }
    }
    return dp[m][n];
}

int main()
{   
    char input1[20], input2[20];
    printf("Enter a word from the Cyberpunk language: ");
    scanf("%s", input1);
    printf("Enter another word from the Cyberpunk language: ");
    scanf("%s", input2);
    printf("Levenshtein Distance: %d", levenshtein(input1, input2));
    return 0;
}