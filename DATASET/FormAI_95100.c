//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b, int c) {
    return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}

int levenshteinDistanceCalculator(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int dp[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }
    }

    return dp[len1][len2];
}

int main() {
    char* str1 = "mathematics";
    char* str2 = "physiscs";

    int distance = levenshteinDistanceCalculator(str1, str2);

    printf("Levenshtein distance between %s and %s is %d", str1, str2, distance);

    return 0;
}