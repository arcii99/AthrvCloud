//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: irregular
#include <stdio.h>
#include <string.h>

int calculateDistance(char *, char *);

int main()
{
    char firstWord[100], secondWord[100];
    printf("Enter first word: ");
    fgets(firstWord, 100, stdin);
    printf("Enter second word: ");
    fgets(secondWord, 100, stdin);

    int distance = calculateDistance(firstWord, secondWord);

    printf("\nLevenshtein Distance: %d\n", distance);

    return 0;
}

int calculateDistance(char *firstWord, char *secondWord)
{
    int lenFirst = strlen(firstWord);
    int lenSecond = strlen(secondWord);
    int matrix[lenFirst + 1][lenSecond + 1];

    for (int i = 0; i <= lenFirst; i++)
        matrix[i][0] = i;
    for (int j = 0; j <= lenSecond; j++)
        matrix[0][j] = j;

    for (int i = 1; i <= lenFirst; i++)
    {
        for (int j = 1; j <= lenSecond; j++)
        {
            int substitutionCost = firstWord[i - 1] != secondWord[j - 1];
            int deletionCost = matrix[i - 1][j] + 1;
            int insertionCost = matrix[i][j - 1] + 1;
            int substitutionTotal = matrix[i - 1][j - 1] + substitutionCost;
            int minDistance = matrix[i][j] = substitutionTotal <= deletionCost && substitutionTotal <= insertionCost
                                                ? substitutionTotal
                                                : deletionCost <= insertionCost ? deletionCost : insertionCost;
        }
    }

    return matrix[lenFirst][lenSecond];
}