//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: safe
#include <stdio.h>
#include <string.h>

int minimum(int a, int b, int c) {
    if (a < b && a < c) return a;
    else if (b < a && b < c) return b;
    else return c;
}

int levenshtein_distance(char* s1, char* s2) {
    int n = strlen(s1);
    int m = strlen(s2);
    int d[n+1][m+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0) d[i][j] = j;
            else if (j == 0) d[i][j] = i;
            else if (s1[i-1] == s2[j-1]) d[i][j] = d[i-1][j-1];
            else d[i][j] = 1 + minimum(d[i-1][j-1], d[i][j-1], d[i-1][j]);
        }
    }

    return d[n][m];
}

int main() {
    char s1[100], s2[100];

    printf("Enter string 1: ");
    scanf("%s", s1);

    printf("Enter string 2: ");
    scanf("%s", s2);

    int dist = levenshtein_distance(s1, s2);

    printf("Levenshtein distance between %s and %s is %d\n", s1, s2, dist);

    return 0;
}