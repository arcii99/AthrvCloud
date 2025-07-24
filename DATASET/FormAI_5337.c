//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimum(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    } else if (b < c) {
        return b;
    } else {
        return c;
    }
}

int levenshteinDistance(char* s1, char* s2, int m, int n) {
    int distance[m+1][n+1];

    for (int i=0; i<=m; i++) {
        for (int j=0; j<=n; j++) {
            if (i == 0) {
                distance[i][j] = j;
            } else if (j == 0) {
                distance[i][j] = i;
            } else if (s1[i-1] == s2[j-1]) {
                distance[i][j] = distance[i-1][j-1];
            } else {
                distance[i][j] = minimum(distance[i-1][j-1], distance[i-1][j], distance[i][j-1]) + 1;
            }
        }
    }

    return distance[m][n];
}

int main() {
    char* s1 = "levenshtein";
    char* s2 = "meilenstein";
    int m = strlen(s1);
    int n = strlen(s2);

    printf("The levenshtein distance between %s and %s is %d", s1, s2, levenshteinDistance(s1, s2, m, n));

    return 0;
}