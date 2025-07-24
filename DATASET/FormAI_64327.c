//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: synchronous
#include <stdio.h>
#include <string.h>

int min(int x, int y, int z)
{
    if(x < y && x < z)
    {
        return x;
    }
    else if(y < x && y < z)
    {
        return y;
    }
    else
    {
        return z;
    }
}

int levenshtein_distance(char* s1, char* s2, int m, int n)
{
    int matrix[m + 1][n + 1];
    int i, j;
    for(i = 0; i <= m; i++)
    {
        for(j = 0; j <= n; j++)
        {
            if(i == 0)
            {
                matrix[i][j] = j;
            }
            else if(j == 0)
            {
                matrix[i][j] = i;
            }
            else if(s1[i - 1] == s2[j - 1])
            {
                matrix[i][j] = matrix[i - 1][j - 1];
            }
            else
            {
                matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }
        }
    }
    return matrix[m][n];
}

int main()
{
    char s1[] = "intention";
    char s2[] = "execution";
    int m = strlen(s1);
    int n = strlen(s2);
    printf("The Levenshtein Distance between '%s' and '%s' is %d.\n", s1, s2, levenshtein_distance(s1, s2, m, n));
    return 0;
}