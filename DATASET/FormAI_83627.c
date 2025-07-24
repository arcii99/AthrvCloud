//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Claude Shannon
/* Claude Shannon's Levenshtein Distance Calculator */
/* Written in C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z) {
    return (x < y) ? ((x < z) ? x : z) : ((y < z) ? y : z);
}

int levenshtein_distance(char *s1, char *s2) {
    int m = strlen(s1), n = strlen(s2);
    int d[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0) d[i][j] = j;
            else if (j == 0) d[i][j] = i;
            else if (s1[i - 1] == s2[j - 1]) d[i][j] = d[i - 1][j - 1];
            else d[i][j] = 1 + min(d[i][j - 1], d[i - 1][j], d[i - 1][j - 1]);
        }
    }
    return d[m][n];
}

int main() {
    printf("Enter two strings to find their Levenshtein Distance:\n");
    char s1[100], s2[100];
    scanf("%s %s", s1, s2);
    printf("Levenshtein Distance between %s and %s is %d.\n", s1, s2, levenshtein_distance(s1, s2));
    return 0;
}