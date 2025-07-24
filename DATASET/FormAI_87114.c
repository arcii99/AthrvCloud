//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int levenshtein_distance(char *str1, char *str2, int len1, int len2)
{
    int dp[len1 + 1][len2 + 1];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= len1; i++)
    {
        for(int j = 1; j <= len2; j++)
        {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;

            dp[i][j] = dp[i - 1][j] + 1;            // Deletion
            if(dp[i][j - 1] + 1 < dp[i][j])          // Insertion
                dp[i][j] = dp[i][j - 1] + 1;
            if(dp[i - 1][j - 1] + cost < dp[i][j])   // Substitution
                dp[i][j] = dp[i - 1][j - 1] + cost;
        }
    }

    return dp[len1][len2];
}

int main()
{
    char str1[1000], str2[1000];

    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Please enter the first string (up to 1000 characters): ");
    fgets(str1, sizeof(str1), stdin);
    printf("Please enter the second string (up to 1000 characters): ");
    fgets(str2, sizeof(str2), stdin);

    int len1 = strlen(str1) - 1;
    int len2 = strlen(str2) - 1;

    int distance = levenshtein_distance(str1, str2, len1, len2);

    printf("\nThe Levenshtein Distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);
    printf("Thank you for using the Levenshtein Distance Calculator! Have a nice day :)\n");

    return 0;
}