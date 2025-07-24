//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimum(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int lev_distance(char *s1, char *s2, int len1, int len2) {
    if (len1 == 0) return len2;
    if (len2 == 0) return len1;
    if (s1[len1 - 1] == s2[len2 - 1]) return lev_distance(s1, s2, len1 - 1, len2 - 1);
    return 1 + minimum(lev_distance(s1, s2, len1, len2 - 1), lev_distance(s1, s2, len1 - 1, len2), lev_distance(s1, s2, len1 - 1, len2 - 1));
}

int lev_distance_dp(char *s1, char *s2, int len1, int len2) {
    int **dist = malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        dist[i] = malloc((len2 + 1) * sizeof(int));
        dist[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        dist[0][j] = j;
    }
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dist[i][j] = dist[i - 1][j - 1];
            } else {
                dist[i][j] = 1 + minimum(dist[i][j - 1], dist[i - 1][j], dist[i - 1][j - 1]);
            }
        }
    }
    int res = dist[len1][len2];
    for (int i = 0; i <= len1; i++) {
        free(dist[i]);
    }
    free(dist);
    return res;
}

int main() {
    char *s1 = "hello";
    char *s2 = "world";
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int dist = lev_distance(s1, s2, len1, len2);
    int dist_dp = lev_distance_dp(s1, s2, len1, len2);
    printf("Levenshtein Distance between %s and %s is %d\n", s1, s2, dist);
    printf("Levenshtein Distance (Dynamic Programming) between %s and %s is %d\n", s1, s2, dist_dp);
    return 0;
}