//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int levenshtein_distance(char* s1, char* s2) {
    int m = strlen(s1), n = strlen(s2);
    int** d = malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        d[i] = malloc((n + 1) * sizeof(int));
        d[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        d[0][j] = j;
    }
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            int cost = s1[i - 1] == s2[j - 1] ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,
                           d[i][j - 1] + 1,
                           d[i - 1][j - 1] + cost);
        }
    }
    int distance = d[m][n];
    for (int i = 0; i <= m; i++) {
        free(d[i]);
    }
    free(d);
    return distance;
}

int main() {
    char s1[100] = "kitten";
    char s2[100] = "sitting";
    int distance = levenshtein_distance(s1, s2);
    printf("The Levenshtein distance between '%s' and '%s' is %d.\n", s1, s2, distance);
    return 0;
}