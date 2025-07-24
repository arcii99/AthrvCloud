//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: expert-level
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    } else if (b < c) {
        return b;
    } else {
        return c;
    }
}

int levenshteinDistance(char* s1, char* s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int dp[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else {
                int ins = dp[i][j - 1] + 1;
                int del = dp[i - 1][j] + 1;
                int rep = dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]);
                dp[i][j] = min(ins, del, rep);
            }
        }
    }
    return dp[len1][len2];
}

int main() {
    char* s1 = "kitten";
    char* s2 = "sitting";
    printf("Levenshtein Distance between %s and %s is %d\n", s1, s2, levenshteinDistance(s1, s2));
    return 0;
}