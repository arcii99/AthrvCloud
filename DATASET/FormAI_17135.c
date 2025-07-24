//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scientific
#include <stdio.h>
#include <string.h>

int minimum(int a, int b, int c) {
    if (a < b && a < c)
        return a;
    else if (b < a && b < c)
        return b;
    else
        return c;
}

int levenshteinDistance(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int matrix[len1 + 1][len2 + 1];
    int i, j, cost;

    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            if (i == 0)
                matrix[i][j] = j;
            else if (j == 0)
                matrix[i][j] = i;
            else if (s1[i - 1] == s2[j - 1])
                matrix[i][j] = matrix[i - 1][j - 1];
            else {
                cost = 1;
                int deletion = matrix[i - 1][j] + 1;
                int insertion = matrix[i][j - 1] + 1;
                int substitution = matrix[i - 1][j - 1] + cost;
                matrix[i][j] = minimum(deletion, insertion, substitution);
            }
        }
    }

    return matrix[len1][len2];
}

int main() {
    char *s1 = "kitten";
    char *s2 = "sitting";
    int distance = levenshteinDistance(s1, s2);
    printf("The Levenshtein distance between '%s' and '%s' is %d\n", s1, s2, distance);
    return 0;
}