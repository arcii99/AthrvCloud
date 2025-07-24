//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimum(int a, int b, int c) {
    if (a < b && a < c) return a;
    if (b < a && b < c) return b;
    return c;
}

int levenshteinDistance(char *s, char *t) {
    int n = strlen(s), m = strlen(t);
    int res[n+1][m+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0) res[i][j] = j;
            else if (j == 0) res[i][j] = i;
            else if (s[i - 1] == t[j - 1]) res[i][j] = res[i - 1][j - 1];
            else res[i][j] = 1 + minimum(res[i - 1][j - 1], res[i][j - 1], res[i - 1][j]);
        }
    }
    return res[n][m];
}

int main() {
    char s[100], t[100];
    printf("Enter string 1: ");
    scanf("%s", s);
    printf("Enter string 2: ");
    scanf("%s", t);
    int dist = levenshteinDistance(s, t);
    printf("Levenshtein Distance: %d\n", dist);
    return 0;
}