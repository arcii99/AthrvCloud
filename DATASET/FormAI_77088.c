//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: intelligent
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int levenshtein_distance(char* s1, char* s2, int len1, int len2) {
    // create the matrix
    int matrix[len1+1][len2+1];

    // fill the first row and column
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // fill the rest of the matrix
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i-1] == s2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = min(
                    matrix[i-1][j] + 1, // deletion
                    matrix[i][j-1] + 1, // insertion
                    matrix[i-1][j-1] + 1 // substitution
                );
            }
        }
    }

    return matrix[len1][len2];
}

int main() {
    char* s1 = "kitten";
    char* s2 = "sitting";
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int distance = levenshtein_distance(s1, s2, len1, len2);
    printf("The Levenshtein distance between '%s' and '%s' is %d\n", s1, s2, distance);
    return 0;
}