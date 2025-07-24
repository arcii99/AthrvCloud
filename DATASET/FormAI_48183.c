//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimum(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    } else if (b < c) {
        return b;
    } else {
        return c;
    }
}

int levenshteinDistance(char *s1, char *s2) {
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int i, j;
    int **matrix = (int **)malloc((l1+1)*sizeof(int *));
    for (i = 0; i <= l1; i++) {
        matrix[i] = (int *)malloc((l2+1)*sizeof(int));
        matrix[i][0] = i;
    }
    for (j = 0; j <= l2; j++) {
        matrix[0][j] = j;
    }
    for (i = 1; i <= l1; i++) {
        for (j = 1; j <= l2; j++) {
            int cost;
            if (s1[i-1] == s2[j-1]) {
                cost = 0;
            } else {
                cost = 1;
            }
            matrix[i][j] = minimum(matrix[i-1][j]+1, matrix[i][j-1]+1, matrix[i-1][j-1]+cost);
        }
    }
    return matrix[l1][l2];
}

int main() {
    char s1[50], s2[50];
    printf("Enter two strings: ");
    scanf("%s %s", s1, s2);
    printf("Levenshtein Distance between %s and %s is %d\n", s1, s2, levenshteinDistance(s1, s2));
    return 0;
}