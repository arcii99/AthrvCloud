//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: futuristic
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c)
{
    if(a < b && a < c) return a;
    if(b < a && b < c) return b;
    return c;
}

int levenshteinDistance(char *s, char *t)
{
    int m = strlen(s);
    int n = strlen(t);
    int matrix[m+1][n+1];
    for(int i=0; i<=m; i++)
        matrix[i][0] = i;
    for(int j=0; j<=n; j++)
        matrix[0][j] = j;

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(s[i-1] == t[j-1])
                matrix[i][j] = matrix[i-1][j-1];
            else
            {
                int a = matrix[i-1][j-1];
                int b = matrix[i-1][j];
                int c = matrix[i][j-1];
                matrix[i][j] = 1 + min(a, b, c);
            }
        }
    }

    return matrix[m][n];
}

int main()
{
    char s[50], t[50];
    printf("Enter first string: ");
    scanf("%s", s);
    printf("Enter second string: ");
    scanf("%s", t);
    printf("Levenshtein Distance: %d\n", levenshteinDistance(s, t));
    return 0;
}