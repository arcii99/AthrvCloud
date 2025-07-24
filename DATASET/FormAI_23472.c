//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z) {
    if (x <= y && x <= z) {
        return x;
    } else if (y <= x && y <= z) {
        return y;
    } else {
        return z;
    }
}

int levenshtein_distance(char *s1, char *s2) {
    int m = strlen(s1) + 1;
    int n = strlen(s2) + 1;
    int matrix[m][n];
    int i, j, cost;

    // Initialize first row and column
    for (i = 0; i < m; i++) {
        matrix[i][0] = i;
    }
    for (j = 0; j < n; j++) {
        matrix[0][j] = j;
    }

    // Compute the rest of the matrix
    for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            cost = s1[i - 1] == s2[j - 1] ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost);
        }
    }

    // Return the bottom-right element
    return matrix[m - 1][n - 1];
}

int main() {
    char s1[100], s2[100];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);
    printf("The Levenshtein distance between %s and %s is %d\n", s1, s2, levenshtein_distance(s1, s2));
    return 0;
}