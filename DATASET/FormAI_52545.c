//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b, int c);

int levenshtein_distance(char *s, char *t) {
    int m = strlen(s);
    int n = strlen(t);
    int d[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                d[i][j] = j;
            } else if (j == 0) {
                d[i][j] = i;
            } else if (s[i - 1] == t[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = min(d[i - 1][j] + 1,   // Deletion
                              d[i][j - 1] + 1,   // Insertion
                              d[i - 1][j - 1] + 1 // Substitution
                            );
            }
        }
    }
    return d[m][n];
}

int min(int a, int b, int c) {
    int m = a < b ? a : b;
    return m < c ? m : c;
}

int main() {
    char *s = "kitten";
    char *t = "sitting";
    printf("Levenshtein Distance between %s and %s is %d\n", s, t, levenshtein_distance(s, t));
    return 0;
}