//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: energetic
#include <stdio.h>
#include <string.h>

int levenshteinDistance(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int dp[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                dp[i][j] = j; 
            }
            else if (j == 0) {
                dp[i][j] = i; 
            }
            else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1 + (dp[i - 1][j] < dp[i][j - 1] ? 
                (dp[i - 1][j] < dp[i - 1][j - 1] ? dp[i - 1][j] : 
                dp[i - 1][j - 1]) : (dp[i][j - 1] < dp[i - 1][j - 1] ? 
                dp[i][j - 1] : dp[i - 1][j - 1]));
            }
        }
    }
    return dp[len1][len2];
}

int main() {
    char s1[100], s2[100];
    printf("Hello there! Let's calculate the Levenshtein Distance between two strings.\n");
    printf("Enter the first string: ");
    fgets(s1, 100, stdin);
    printf("Enter the second string: ");
    fgets(s2, 100, stdin);

    s1[strcspn(s1, "\n")] = 0; // Removing newline character from input
    s2[strcspn(s2, "\n")] = 0;

    int distance = levenshteinDistance(s1, s2);
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);
    printf("Awesome! That was easy, right?\n");
    
    return 0;
}