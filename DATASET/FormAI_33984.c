//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c)
{
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int LevenshteinDistance(char *s1, char *s2)
{
    int m = strlen(s1)+1;
    int n = strlen(s2)+1;
    int d[m][n];
    int i, j, cost;

    for(i = 0; i < m; i++)
        d[i][0] = i;

    for(j = 0; j < n; j++)
        d[0][j] = j;

    for(i = 1; i < m; i++)
        for(j = 1; j < n; j++)
        {
            if(s1[i-1] == s2[j-1])
                cost = 0;
            else
                cost = 1;

            d[i][j] = min(d[i-1][j] + 1, d[i][j-1] + 1, d[i-1][j-1] + cost);
        }

    return d[m-1][n-1];
}

int main()
{
    char s1[100], s2[100];
    printf("Please enter the first word: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = 0;

    printf("Please enter the second word: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = 0;

    printf("\nLevenshtein Distance between %s and %s is %d\n", s1, s2, LevenshteinDistance(s1, s2));
    return 0;
}