//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int levenshtein_distance(char *str1, char *str2, int m, int n)
{
    int matrix[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                matrix[i][j] = j;
            else if (j == 0)
                matrix[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                matrix[i][j] = matrix[i - 1][j - 1];
            else
            {
                matrix[i][j] = 1 + 
                    (matrix[i][j - 1] > matrix[i - 1][j]
                    ? matrix[i - 1][j] : matrix[i][j - 1]);
            }
        }
    }

    return matrix[m][n];
}

int main()
{
    char str1[100], str2[100];
    printf("Enter String 1: ");
    fgets(str1, 99, stdin);
    printf("Enter String 2: ");
    fgets(str2, 99, stdin);
    int m = strlen(str1) - 1;
    int n = strlen(str2) - 1;

    int dist = levenshtein_distance(str1, str2, m, n);

    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d\n", str1, str2, dist);

    return 0;
}