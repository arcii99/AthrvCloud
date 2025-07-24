//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    int m = a;
    if (m > b) m = b;
    if (m > c) m = c;
    return m;
}

int levenshtein(const char* s, const char* t) {
    int n = strlen(s);
    int m = strlen(t);
    int d[n+1][m+1];
    int i, j;

    for (i = 0; i <= n; i++) d[i][0] = i;
    for (j = 0; j <= m; j++) d[0][j] = j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            int cost = (s[i-1] == t[j-1]) ? 0 : 1;
            d[i][j] = min(d[i-1][j] + 1, d[i][j-1] + 1, d[i-1][j-1] + cost);
        }
    }

    return d[n][m];
}

int main() {
    char s[] = "hello";
    char t[] = "world";
    printf("The Levenshtein distance between '%s' and '%s' is: %d\n", s, t, levenshtein(s, t));

    return 0;
}