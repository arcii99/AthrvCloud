//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimum(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int LevenshteinDistance(char *str1, char *str2, int len1, int len2) {
    int **matrix = malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = malloc((len2 + 1) * sizeof(int));
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++)
        matrix[0][j] = j;

    for (int i = 0; i < len1; i++)
        for (int j = 0; j < len2; j++)
            matrix[i + 1][j + 1] = minimum(matrix[i][j + 1] + 1, matrix[i + 1][j] + 1, matrix[i][j] + (str1[i] != str2[j]));

    int distance = matrix[len1][len2];

    for (int i = 0; i <= len1; i++)
        free(matrix[i]);
    free(matrix);

    return distance;
}

int main() {
    char str1[] = "kitten";
    char str2[] = "sitting";
    int distance = LevenshteinDistance(str1, str2, strlen(str1), strlen(str2));
    printf("Levenshtein Distance between \"%s\" and \"%s\" is %d", str1, str2, distance);
    return 0;
}