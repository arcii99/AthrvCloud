//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int levenshtein_distance(char *first_string, char *second_string);

int main(void) {
    char *string1 = "cyberpunk";
    char *string2 = "cyborg";

    int distance = levenshtein_distance(string1, string2);

    printf("Levenshtein distance between \"%s\" and \"%s\" is %d\n", string1, string2, distance);

    return 0;
}

int levenshtein_distance(char *first_string, char *second_string) {
    int m = strlen(first_string), n = strlen(second_string);

    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (first_string[i - 1] == second_string[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + fmin(dp[i - 1][j - 1], fmin(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }

    return dp[m][n];
}