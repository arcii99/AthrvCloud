//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: unmistakable
#include <stdio.h>
#include <string.h>

int min(int x, int y, int z) {
    if (x <= y && x <= z) return x;
    if (y <= x && y <= z) return y;
    return z;
}

int levenshtein_dist(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int dp[len1+1][len2+1];
    int i, j;

    memset(dp, 0, sizeof(dp));

    for (i = 0; i <= len1; i++)
        dp[i][0] = i;
    for (j = 0; j <= len2; j++)
        dp[0][j] = j;

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
            }
        }
    }

    return dp[len1][len2];
}

int main() {
    char s1[] = "kitten";
    char s2[] = "sitting";
    int dist = levenshtein_dist(s1, s2);
    printf("Levenshtein distance between %s and %s is %d\n", s1, s2, dist);
    return 0;
}