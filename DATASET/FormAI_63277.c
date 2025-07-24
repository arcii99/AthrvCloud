//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to calculate the minimum of 3 numbers */
int minimum(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    else if (b <= a && b <= c) return b;
    else return c;
}

/* Function to calculate the Levenshtein Distance */
int levenshteinDistance(char *a, char *b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    
    /* Create a 2D array of distances */
    int matrix[lenA + 1][lenB + 1];
    for (int i = 0; i <= lenA; i++) {
        for (int j = 0; j <= lenB; j++) {
            /* Initialize the first row and column */
            if (i == 0 || j == 0) matrix[i][j] = i + j;
            /* Calculate the distances */
            else if (a[i - 1] == b[j - 1]) matrix[i][j] = matrix[i - 1][j - 1];
            else matrix[i][j] = 1 + minimum(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
        }
    }
    /* Return the distance */
    return matrix[lenA][lenB];
}

int main(void) {
    char *str1 = "cat";
    char *str2 = "hat";
    int distance = levenshteinDistance(str1, str2);
    printf("The Levenshtein Distance between %s and %s is %d", str1, str2, distance);
    return 0;
}