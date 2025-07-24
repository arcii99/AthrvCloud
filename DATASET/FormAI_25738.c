//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int levenshtein_distance(char *a, char *b) {
    int la = strlen(a), lb = strlen(b);
    int *dp = (int *) malloc(sizeof(int) * (la + 1) * (lb + 1));
    memset(dp, 0, sizeof(int) * (la + 1) * (lb + 1));

    for (int i = 1; i <= lb; i++) {
        dp[i] = i;
    }
    for (int j = 1; j <= la; j++) {
        dp[j * (lb + 1)] = j;
    }

    for (int i = 1; i <= la; i++) {
        for (int j = 1; j <= lb; j++) {
            dp[i * (lb + 1) + j] = min(dp[(i - 1) * (lb + 1) + j] + 1, dp[i * (lb + 1) + j - 1] + 1);
            dp[i * (lb + 1) + j] = min(dp[i * (lb + 1) + j], dp[(i - 1) * (lb + 1) + j - 1] + (a[i - 1] == b[j - 1] ? 0 : 1));
        }
    }

    int result = dp[la * (lb + 1) + lb];
    free(dp);
    return result;
}

int main(int argc, char **argv) {
    char *s1 = "Hello";
    char *s2 = "World";
    int distance = levenshtein_distance(s1, s2);
    printf("Distance between '%s' and '%s' is %d.\n", s1, s2, distance);
    return 0;
}