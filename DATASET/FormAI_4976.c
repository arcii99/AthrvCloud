//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c)
{
    if (a < b && a < c)
        return a;
    if (b < a && b < c)
        return b;
    return c;
}

int ShapeShiftingLevenshteinDistance(char *s, char *t)
{
    int m = strlen(s);
    int n = strlen(t);
    int d[m + 1][n + 1];
    int i, j, cost;

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0)
                d[i][j] = j;

            else if (j == 0)
                d[i][j] = i;

            else if (s[i - 1] == t[j - 1])
                d[i][j] = d[i - 1][j - 1];

            else
            {
                cost = 1;

                if (i > 2 && s[i - 3] == t[j - 1])
                    cost = 0;

                if (j > 2 && s[i - 1] == t[j - 3])
                    cost = 0;

                if (i > 2 && j > 2 && s[i - 3] == t[j - 3])
                {
                    if (s[i - 2] == t[j - 1] || s[i - 1] == t[j - 2])
                        cost = 0;
                }

                d[i][j] = min(d[i - 1][j] + 1, // deletion
                              d[i][j - 1] + 1, // insertion
                              d[i - 1][j - 1] + cost); // substitution
            }
        }
    }

    return d[m][n];
}

int main()
{
    char str1[] = "Hello World!";
    char str2[] = "Holla Warld!";
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, ShapeShiftingLevenshteinDistance(str1, str2));
    return 0;
}