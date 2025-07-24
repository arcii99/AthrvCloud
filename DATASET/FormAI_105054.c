//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: relaxed
#include <stdio.h>
#include <string.h>

// Function to find the minimum of three numbers
int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

// Function to calculate Levenshtein Distance
int levenshtein_distance(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);

    // Create a 2D matrix to store the edit distances
    int matrix[m + 1][n + 1];

    // Initialize the first row and column of the matrix
    for (int i = 0; i <= m; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        matrix[0][j] = j;
    }

    // Fill in the rest of the matrix
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]) + 1;
            }
        }
    }

    // Return the final edit distance
    return matrix[m][n];
}

int main() {
    char s1[] = "kitten";
    char s2[] = "sitting";

    int result = levenshtein_distance(s1, s2);

    printf("The Levenshtein Distance between '%s' and '%s' is %d.\n", s1, s2, result);

    return 0;
}