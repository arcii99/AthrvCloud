//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

// function to calculate minimum of three numbers
int min(int a, int b, int c) {
    if(a < b && a < c) {
        return a;
    } else if(b < a && b < c) {
        return b;
    }
    return c;
}

// function to calculate the Levenshtein Distance between two strings
int levenshteinDistance(char *string1, char *string2) {
    int m = strlen(string1);
    int n = strlen(string2);

    // initialize a matrix of size (m+1)x(n+1) with 0
    int matrix[m+1][n+1];
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            matrix[i][j] = 0;
        }
    }

    // fill the first row and column of the matrix
    for(int i = 0; i <= m; i++) {
        matrix[i][0] = i;
    }
    for(int j = 0; j <= n; j++) {
        matrix[0][j] = j;
    }

    // fill the rest of the matrix
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(string1[i-1] == string2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = 1 + min(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]);
            }
        }
    }

    // return the bottom right element of the matrix
    return matrix[m][n];
}

int main() {
    char string1[] = "kitten";
    char string2[] = "sitting";
    int distance = levenshteinDistance(string1, string2);
    printf("The Levenshtein Distance between '%s' and '%s' is %d.\n", string1, string2, distance);

    return 0;
}