//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c);

int levenshtein(char *s, char *t) {
    int m = strlen(s);
    int n = strlen(t);
    int d[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            d[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        d[i][0] = i;
    }
    for (int j = 1; j <= n; j++) {
        d[0][j] = j;
    }

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            if (s[i-1] == t[j-1]) {
                d[i][j] = d[i-1][j-1];
            } else {
                d[i][j] = min(d[i-1][j] + 1, 
                              d[i][j-1] + 1,
                              d[i-1][j-1] + 1);
            }
        }
    }
    return d[m][n];
}

int min(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    } else if (b < c) {
        return b;
    } else {
        return c;
    }
}

int main() {
    char s[] = "kitten";
    char t[] = "sitting";
    int dist = levenshtein(s, t);
    printf("Levenshtein distance between \"%s\" and \"%s\" is %d\n", s, t, dist);
    return 0;
}