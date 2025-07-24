//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scientific
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    } else if (b < a && b < c) {
        return b;
    } else {
        return c;
    }
}

int levenshteinDistance(char *s1, int n, char *s2, int m) {
    int i, j;
    int d[n+1][m+1];
    for (i = 0; i <= n; i++) {
        d[i][0] = i;
    }
    for (j = 0; j <= m; j++) {
        d[0][j] = j;
    }
    for (j = 1; j <= m; j++) {
        for (i = 1; i <= n; i++) {
            if (s1[i-1] == s2[j-1]) {
                d[i][j] = d[i-1][j-1];
            } else {
                d[i][j] = min(d[i-1][j], d[i][j-1], d[i-1][j-1]) + 1;
            }
        }
    }
    return d[n][m];
}

int main() {
    char s1[100], s2[100];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);
    int n = strlen(s1);
    int m = strlen(s2);
    printf("Levenshtein Distance between %s and %s is: %d\n", s1, s2, levenshteinDistance(s1, n, s2, m));
    return 0;
}