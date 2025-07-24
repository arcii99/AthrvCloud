//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mind-bending
#include <stdio.h>
#include <string.h>

int min(int x, int y, int z) {
    return x < y ? (x < z ? x : z) : (y < z ? y : z);
}

int levenshtein_distance(char *s, char *t) {
    int n = strlen(s);
    int m = strlen(t);
    int d[n+1][m+1];

    for (int i = 0; i <= n; i++)
        d[i][0] = i;

    for (int j = 1; j <= m; j++)
        d[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int c = (s[i-1] == t[j-1]) ? 0 : 1;
            d[i][j] = min(d[i-1][j] + 1, d[i][j-1] + 1, d[i-1][j-1] + c);
        }
    }

    return d[n][m];
}

int main() {
    char *s1 = "kitten";
    char *s2 = "sitting";

    printf("Levenshtein Distance between %s and %s is %d\n", s1, s2, levenshtein_distance(s1, s2));

    return 0;
}