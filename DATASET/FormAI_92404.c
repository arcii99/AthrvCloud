//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: thoughtful
#include <stdio.h>
#include <string.h>

int minimum(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int levenshteinDistance(char *word1, char *word2, int len1, int len2) {
    if (len1 == 0) {
        return len2;
    }
    if (len2 == 0) {
        return len1;
    }
    int matrix[len1 + 1][len2 + 1];
    int i, j, cost;

    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                cost = 0;
            } else {
                cost = 1;
            }

            matrix[i][j] = minimum(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost);
        }
    }
    return matrix[len1][len2];
}

int main() {
    char word1[] = "kitten";
    char word2[] = "sitting";
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int distance = levenshteinDistance(word1, word2, len1, len2);
    printf("Levenshtein Distance between %s and %s is: %d", word1, word2, distance);
    return 0;
}