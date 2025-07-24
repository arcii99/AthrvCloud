//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

int min(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int levenshtein_distance(char *s, char *t, int s_length, int t_length) {
    int dp[s_length + 1][t_length + 1];
    for(int i = 0; i <= s_length;i++) {
        for(int j = 0; j <= t_length; j++) {
            if(i == 0) {
                dp[i][j] = j;
            } else if(j == 0) {
                dp[i][j] = i;
            } else if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) + 1;
            }
        }
    }
    return dp[s_length][t_length];
}

int main() {
    char s[MAX_SIZE], t[MAX_SIZE];
    int s_length, t_length;
    printf("Welcome to Levenshtein Distance Calculator!\n");
    printf("Enter the first string: ");
    fgets(s, MAX_SIZE, stdin);
    s_length = strlen(s)-1;
    printf("Enter the second string: ");
    fgets(t, MAX_SIZE, stdin);
    t_length = strlen(t)-1;
    int dist = levenshtein_distance(s, t, s_length, t_length);
    printf("\nThe Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s, t, dist);
    return 0;
}