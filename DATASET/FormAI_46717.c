//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z) {
    return x < y ? (x < z ? x : z) : (y < z ? y : z);
}

int levenshtein(char *s, char *t) {
    int m = strlen(s);
    int n = strlen(t);
    int d[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) d[i][j] = j;
            else if (j == 0) d[i][j] = i;
            else if (s[i-1] == t[j-1]) d[i][j] = d[i-1][j-1];
            else d[i][j] = min(d[i-1][j] + 1, d[i][j-1] + 1, d[i-1][j-1] + 1);
        }
    }

    return d[m][n];
}

int main() {
    char s[] = "kitten";
    char t[] = "sitting";
    int distance = levenshtein(s, t);
    printf("The Levenshtein distance between '%s' and '%s' is %d\n", s, t, distance);
    return 0;
}