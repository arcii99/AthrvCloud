//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z)
{
    if (x <= y && x <= z)
        return x;
    if (y <= x && y <= z)
        return y;
    else
        return z;
}

int levenshteinDistance(char *s, char *t)
{
    int n = strlen(s);
    int m = strlen(t);
    int distance[n+1][m+1];

    for (int i=0; i<=n; i++)
    {
        for (int j=0; j<=m; j++)
        {
            if (i == 0)
                distance[i][j] = j;
            else if (j == 0)
                distance[i][j] = i;
            else if (s[i-1] == t[j-1])
                distance[i][j] = distance[i-1][j-1];
            else
                distance[i][j] = 1 + min(distance[i][j-1], distance[i-1][j], distance[i-1][j-1]);
        }
    }

    return distance[n][m];
}

void clearInput()
{
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    char input1[100];
    char input2[100];
    int result;

    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Please enter the first word: ");
    fgets(input1, 100, stdin);

    printf("Please enter the second word: ");
    fgets(input2, 100, stdin);

    result = levenshteinDistance(input1, input2);

    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d!\n", input1, input2, result);

    printf("\nThank you for using the Levenshtein Distance Calculator!\n");

    return 0;
}