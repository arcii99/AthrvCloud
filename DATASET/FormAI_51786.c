//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: realistic
#include <stdio.h>
#include <string.h>

#define MAXLEN 100

int min(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int LevenshteinDistance(char *s1, char *s2) {
    int s1len = strlen(s1);
    int s2len = strlen(s2);
    int matrix[MAXLEN + 1][MAXLEN + 1];

    for (int i = 0; i <= s1len; i++) {
        for (int j = 0; j <= s2len; j++) {
            if (i == 0) {
                matrix[i][j] = j;
            }
            else if (j == 0) {
                matrix[i][j] = i;
            }
            else if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            }
            else {
                matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }
        }
    }

    return matrix[s1len][s2len];
}

int main() {
    char s1[MAXLEN], s2[MAXLEN];

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    int distance = LevenshteinDistance(s1, s2);

    printf("Levenshtein Distance: %d\n", distance);

    return 0;
}