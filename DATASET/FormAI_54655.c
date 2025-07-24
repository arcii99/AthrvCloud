//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: authentic
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int levenshtein_distance(char* str1, char* str2, int len1, int len2) {
    int dp[MAX_LENGTH][MAX_LENGTH];
    memset(dp, 0, sizeof(dp));

    int i, j;
    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
            }
        }
    }

    return dp[len1][len2];
}

int main() {
    char str1[] = "hello";
    char str2[] = "hillo";

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    printf("Levenshtein Distance between %s and %s is %d\n", str1, str2, levenshtein_distance(str1, str2, len1, len2));  

    return 0;
}