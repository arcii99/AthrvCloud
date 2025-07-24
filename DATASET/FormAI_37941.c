//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

int min(int x, int y, int z) {
    if (x <= y && x <= z) {
        return x;
    }
    if (y <= x && y <= z) {
        return y;
    }
    return z;
}

int LevenshteinDistance(char *s, char *t, int m, int n) {
    int i, j, cost;
    int d[m+1][n+1];
    for (i = 0; i <= m; i++) {
        d[i][0] = i;
    }
    for (j = 0; j <= n; j++) {
        d[0][j] = j;
    }
    for (j = 1; j <= n; j++) {
        for (i = 1; i <= m; i++) {
            if (s[i-1] == t[j-1]) {
                cost = 0;
            } else {
                cost = 1;
            }
            d[i][j] = min(d[i-1][j]+1, d[i][j-1]+1, d[i-1][j-1]+cost);
        }
    }
    return d[m][n];
}

int main() {
    char s[100], t[100];
    printf("Enter the first string: ");
    scanf("%s", s);
    printf("Enter the second string: ");
    scanf("%s", t);
    int m = strlen(s);
    int n = strlen(t);
    int dist = LevenshteinDistance(s, t, m, n);
    printf("The Levenshtein Distance between %s and %s is %d.\n", s, t, dist);
    return 0;
}