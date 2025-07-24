//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LevenshteinDistance(char *s, char *t) {
    int n = strlen(s);
    int m = strlen(t);
    int len = n + m;
    int d[2][len+1];
    memset(d, 0, sizeof(d));

    int i, j;
    for (i = 0; i <= n; i++) d[0][i] = i;

    for (i = 1; i <= m; i++) {
        int cur = i & 1;
        int prev = cur ^ 1;
        d[cur][0] = i;

        for (j = 1; j <= n; j++) {
            if (s[j-1] == t[i-1]) {
                d[cur][j] = d[prev][j-1];
            } else {
                int del = d[cur][j-1] + 1;
                int ins = d[prev][j] + 1;
                int sub = d[prev][j-1] + 1;
                d[cur][j] = del < ins ? del : ins;
                d[cur][j] = d[cur][j] < sub ? d[cur][j] : sub;
            }
        }
    }
    return d[m & 1][n];
}

int main(void) {
    char a[100], b[100];
    printf("Enter string a: ");
    scanf("%s", a);
    printf("Enter string b: ");
    scanf("%s", b);
    int distance = LevenshteinDistance(a, b);
    printf("Levenshtein Distance: %d\n", distance);
    return 0;
}