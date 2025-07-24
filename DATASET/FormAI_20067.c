//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

int levenshteinDistance(char* s1, char* s2) {
    int m = strlen(s1);
    int n = strlen(s2);

    int dist[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dist[i][j] = j;
            } else if (j == 0) {
                dist[i][j] = i;
            } else if (s1[i-1] == s2[j-1]) {
                dist[i][j] = dist[i-1][j-1];
            } else {
                dist[i][j] = 1 + min(dist[i-1][j], dist[i][j-1], dist[i-1][j-1]);
            }
        }
    }

    return dist[m][n];
}

int main() {
    char s1[] = "kitten";
    char s2[] = "sitting";

    int distance = levenshteinDistance(s1, s2);

    printf("Levenshtein Distance between %s and %s is %d\n", s1, s2, distance);

    return 0;
}