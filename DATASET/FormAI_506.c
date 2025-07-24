//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int levenshtein(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i, j, cost, **d;

    d = (int **)calloc(len1 + 1, sizeof(int *));
    for (i = 0; i <= len1; i++) {
        d[i] = (int *)calloc(len2 + 1, sizeof(int));
        d[i][0] = i;
    }

    for (j = 0; j <= len2; j++) {
        d[0][j] = j;
    }

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            cost = s1[i-1] == s2[j-1] ? 0 : 1;
            d[i][j] = min(d[i-1][j]+1, d[i][j-1]+1, d[i-1][j-1]+cost);
        }
    }

    int result = d[len1][len2];
    
    for (i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);
    
    return result;
}

int main() {
    char *s1 = "kitten";
    char *s2 = "sitting";
    int distance = levenshtein(s1, s2);
    printf("%d\n", distance);
    return 0;
}