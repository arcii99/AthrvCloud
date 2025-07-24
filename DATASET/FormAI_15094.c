//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimum(int a, int b, int c)
{
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int levenshteinDistance(char* word1, char* word2)
{
    int len1 = strlen(word1), len2 = strlen(word2);
    int** matrix = (int**) malloc((len1 + 1) * sizeof(int*));
    for (int i = 0; i <= len1; i++)
    {
        matrix[i] = (int*) malloc((len2 + 1) * sizeof(int));
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) matrix[0][j] = j;

    for (int j = 1; j <= len2; j++)
    {
        for (int i = 1; i <= len1; i++)
        {
            if (word1[i-1] == word2[j-1]) matrix[i][j] = matrix[i-1][j-1];
            else matrix[i][j] = minimum(matrix[i-1][j]+1, matrix[i][j-1]+1, matrix[i-1][j-1]+1);
        }
    }
    int distance = matrix[len1][len2];

    for (int i = 0; i <= len1; i++) free(matrix[i]);
    free(matrix);
    return distance;
}

int main()
{
    char str1[50], str2[50];
    printf("Enter first word: ");
    scanf("%s", str1);
    printf("Enter second word: ");
    scanf("%s", str2);
    printf("Levenshtein Distance between %s and %s is %d\n", str1, str2, levenshteinDistance(str1, str2));
    return 0;
}