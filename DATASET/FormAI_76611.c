//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

int min(int x, int y, int z) {
    return x < y ? (x < z ? x : z) : (y < z ? y : z);
}

int levenshteinDistance(char *s, int len_s, char *t, int len_t) {
    int d[len_s + 1][len_t + 1];

    for (int i = 0; i <= len_s; i++)
        d[i][0] = i;
    for (int j = 1; j <= len_t; j++)
        d[0][j] = j;

    for (int j = 1; j <= len_t; j++) {
        for (int i = 1; i <= len_s; i++) {
            int cost = s[i - 1] == t[j - 1] ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + cost);
        }
    }

    return d[len_s][len_t];
}

int main() {
    char s[] = "Hello";
    char t[] = "World";
    int distance = levenshteinDistance(s, strlen(s), t, strlen(t));
    printf("The Levenshtein distance between %s and %s is: %d", s, t, distance);
    return 0;
}