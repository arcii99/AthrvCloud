//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to calculate minimum of 3 integers
int min(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    } else if (b < c) {
        return b;
    } else {
        return c;
    }
}

// function to calculate Levenshtein Distance
int levenshtein_distance(char *s1, char *s2, int len1, int len2) {
    int dp[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                dp[i][j] = j; // if s1 is empty, only option is to insert all characters of s2
            } else if (j == 0) {
                dp[i][j] = i; // if s2 is empty, only option is to insert all characters of s1
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // if last characters are same, no operation required
            } else {
                dp[i][j] = 1 + min(dp[i][j - 1], // insert
                                    dp[i - 1][j], // delete
                                    dp[i - 1][j - 1]); // replace
            }
        }
    }
    // return Levenshtein distance between s1 and s2
    return dp[len1][len2];
}

int main() {
    char s1[] = "kitten";
    char s2[] = "sitting";

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int distance = levenshtein_distance(s1, s2, len1, len2);

    printf("Levenshtein distance between %s and %s is %d\n", s1, s2, distance);

    return 0;
}