//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a,b) ((a < b) ? a : b)

/* Function to calculate Levenshtein Distance */
int levenshtein_distance(char *str1, char *str2, int m, int n) {
    int cost = 0;
    int i, j, k, **matrix;
    matrix = (int **)malloc((m + 1) * sizeof(int *));
    for (i = 0; i <= m; i++)
        matrix[i] = (int *)malloc((n + 1) * sizeof(int));
    for (i = 0; i <= m; i++)
        matrix[i][0] = i;
    for (j = 0; j <= n; j++)
        matrix[0][j] = j;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                cost = 0;
            } else {
                cost = 1;
            }
            matrix[i][j] = min(matrix[i - 1][j] + 1,
                             min(matrix[i][j - 1] + 1,
                                 matrix[i - 1][j - 1] + cost));
        }
    }
    return matrix[m][n];
}

int main() {
    char str1[20], str2[20];
    printf("Enter string 1: ");
    fgets(str1, 20, stdin);
    printf("Enter string 2: ");
    fgets(str2, 20, stdin);
    int m = strlen(str1) - 1;
    int n = strlen(str2) - 1;
    int distance = levenshtein_distance(str1, str2, m, n);
    printf("\nThe Levenshtein Distance between %s and %s is: %d\n", str1, str2, distance);
    return 0;
}