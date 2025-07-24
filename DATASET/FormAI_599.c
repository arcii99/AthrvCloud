//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: detailed
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int levenshteinDistance(char s[], char t[]) {
    int len_s = strlen(s);
    int len_t = strlen(t);
    int dp[MAX_LENGTH][MAX_LENGTH];

    for (int i = 0; i <= len_s; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= len_t; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= len_s; i++) {
        for (int j = 1; j <= len_t; j++) {
            int cost = (s[i-1] == t[j-1]) ? 0 : 1;

            dp[i][j] = dp[i-1][j] + 1;
            if (dp[i][j-1] + 1 < dp[i][j]) {
                dp[i][j] = dp[i][j-1] + 1;
            }
            if (dp[i-1][j-1] + cost < dp[i][j]) {
                dp[i][j] = dp[i-1][j-1] + cost;
            }
        }
    }

    return dp[len_s][len_t];
}

int main() {
    char s[MAX_LENGTH], t[MAX_LENGTH];

    printf("Enter the first string: ");
    fgets(s, MAX_LENGTH, stdin);
    s[strcspn(s, "\n")] = 0; // remove newline character from input

    printf("Enter the second string: ");
    fgets(t, MAX_LENGTH, stdin);
    t[strcspn(t, "\n")] = 0; // remove newline character from input

    int distance = levenshteinDistance(s, t);

    printf("The Levenshtein distance between '%s' and '%s' is: %d\n", s, t, distance);

    return 0;
}