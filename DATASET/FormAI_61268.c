//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multivariable
#include <stdio.h>
#include <string.h>

#define MAXLEN 50

int dp[MAXLEN][MAXLEN];

int min(int a, int b, int c) {
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int levenshtein_distance(char *s1, char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int i, j;

    if (len1 == 0) return len2;
    if (len2 == 0) return len1;

    for (i = 0; i <= len1; i++) dp[i][0] = i;
    for (j = 0; j <= len2; j++) dp[0][j] = j;

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
        }
    }

    return dp[len1][len2];
}

int main() {
    char s1[MAXLEN], s2[MAXLEN];
    int distance;

    printf("Enter first string: ");
    fgets(s1, MAXLEN, stdin);
    s1[strcspn(s1, "\n")] = 0; // remove trailing newline

    printf("Enter second string: ");
    fgets(s2, MAXLEN, stdin);
    s2[strcspn(s2, "\n")] = 0;

    distance = levenshtein_distance(s1, s2);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);

    return 0;
}