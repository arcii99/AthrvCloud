//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int minimum(int a, int b, int c) {
    int min = a;
    if (b < min) { min = b; }
    if (c < min) { min = c; }
    return min;
}

int distance(char s1[], char s2[]) {
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int matrix[n1+1][n2+1];
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            if (i == 0) {
                matrix[i][j] = j;
            } else if (j == 0) {
                matrix[i][j] = i;
            } else if (s1[i-1] == s2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = 1 + minimum(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]);
            }
        }
    }
    return matrix[n1][n2];
}

int main() {
    char string1[100], string2[100];
    printf("Enter first string: ");
    fgets(string1, 100, stdin);
    printf("Enter second string: ");
    fgets(string2, 100, stdin);
    int result = distance(string1, string2);
    printf("The Levenshtein Distance between '%s' and '%s' is %d.\n", string1, string2, result);
    return 0;
}