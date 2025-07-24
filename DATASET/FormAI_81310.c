//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to find minimum of three numbers
int min(int a, int b, int c) {
    if(a <= b && a <= c) return a;
    if(b <= a && b <= c) return b;
    return c;
}

// function to calculate Levenshtein Distance
int levenshtein_distance(char *s1, char *s2) {

    int m = strlen(s1);
    int n = strlen(s2);

    // initialize 2-D array
    int dp[m + 1][n + 1];

    // initialize first row and column of dp[][] array
    for(int i = 0; i <= m; i++) dp[i][0] = i;
    for(int j = 0; j <= n; j++) dp[0][j] = j;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            // if characters are equal 
            // then no operation is needed
            if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1]; 
            else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
        }
    }

    return dp[m][n]; // return Levenshtein Distance
}

int main() {

    char s1[100], s2[100];
    printf("Enter string 1: ");
    fgets(s1, 100, stdin);
    s1[strcspn(s1, "\n")] = 0; // remove newline character from s1
    printf("Enter string 2: ");
    fgets(s2, 100, stdin);
    s2[strcspn(s2, "\n")] = 0; // remove newline character from s2

    // calculate Levenshtein Distance
    int distance = levenshtein_distance(s1, s2);

    printf("\nLevenshtein Distance between %s and %s is %d\n", s1, s2, distance);

    return 0;
}