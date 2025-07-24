//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) ((a)>(b)?(a):(b))

int levenshtein_distance(char *s1, char *s2) {
    int l1 = strlen(s1), l2 = strlen(s2);
    int i, j;
    int **dp = (int**) malloc((l1 + 1) * sizeof(int*));
    for (i = 0; i <= l1; ++i) {
        dp[i] = (int*) malloc((l2 + 1) * sizeof(int));
        memset(dp[i], 0, (l2 + 1) * sizeof(int));
    }
    for (i = 1; i <= l1; ++i) {
        dp[i][0] = i;
    }
    for (j = 1; j <= l2; ++j) {
        dp[0][j] = j;
    }
    for (i = 1; i <= l1; ++i) {
        for (j = 1; j <= l2; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + MAX(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = MAX(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    int ans = dp[l1][l2];
    for (i = 0; i <= l1; ++i) {
        free(dp[i]);
    }
    free(dp);
    return ans;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 0;
    }
    char *s1 = argv[1], *s2 = argv[2];
    printf("Levenshtein distance between \"%s\" and \"%s\": %d\n", s1, s2, levenshtein_distance(s1, s2));
    return 0;
}