//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: automated
#include <stdio.h>
#include <string.h>
 
#define MAX_LEN 1000
 
int min(int a, int b, int c) {
    if (a < b && a < c) return a;
    if (b < a && b < c) return b;
    return c;
}
 
int calculate_distance(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int dp[MAX_LEN + 1][MAX_LEN + 1];

    for (int i = 0; i <= len1; i++) dp[i][0] = i;
    for (int i = 0; i <= len2; i++) dp[0][i] = i;
 
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int substitution_cost = s1[i - 1] != s2[j - 1];
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + substitution_cost);
        }
    }
 
    return dp[len1][len2];
}
 
int main() {
    char s1[MAX_LEN], s2[MAX_LEN];
 
    printf("Enter first string: ");
    scanf("%s", s1);
 
    printf("Enter second string: ");
    scanf("%s", s2);
 
    int distance = calculate_distance(s1, s2);
 
    printf("Levenshtein Distance: %d\n", distance);
 
    return 0;
}