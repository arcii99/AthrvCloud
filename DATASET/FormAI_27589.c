//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a < b && a < c) return a;
    if (b < a && b < c) return b;
    return c;
}

int levenshtein_distance(char* a, char* b, int alen, int blen) {
    int **d = (int **) malloc((alen + 1) * sizeof(int *));
    for (int i = 0; i <= alen; i++) d[i] = (int *) malloc((blen + 1) * sizeof(int));
    for (int i = 0; i <= alen; i++) d[i][0] = i;
    for (int j = 0; j <= blen; j++) d[0][j] = j;

    for (int j = 1; j <= blen; j++) {
        for (int i = 1; i <= alen; i++) {
            int diff = (a[i - 1] != b[j - 1]) ? 1 : 0;
            d[i][j] = min(d[i-1][j]+1, d[i][j-1]+1, d[i-1][j-1]+diff);
        }
    }
    return d[alen][blen];
}

int main() {
    char* a = "kitten";
    char* b = "sitting";
    int alen = strlen(a);
    int blen = strlen(b);

    int distance = levenshtein_distance(a, b, alen, blen);
    printf("Levenshtein distance between %s and %s is %d\n", a, b, distance);

    return 0;
}