//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int min(int a, int b, int c) {
    if(a < b && a < c) {
        return a;
    } else if(b < a && b < c) {
        return b;
    } else {
        return c;
    }
}

int levenshteinDistance(char *string1, char *string2) {
    int m = strlen(string1);
    int n = strlen(string2);

    int dp[m+1][n+1];
    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i == 0) {
                dp[i][j] = j;
            } else if(j == 0) {
                dp[i][j] = i;
            } else if(string1[i-1] == string2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    char string1[MAX_LEN], string2[MAX_LEN];

    printf("Enter string 1: ");
    fgets(string1, MAX_LEN, stdin);
    printf("Enter string 2: ");
    fgets(string2, MAX_LEN, stdin);

    string1[strcspn(string1, "\n")] = 0; // To remove newline character
    string2[strcspn(string2, "\n")] = 0; // To remove newline character

    int distance = levenshteinDistance(string1, string2);
    printf("Levenshtein distance between %s and %s is %d\n", string1, string2, distance);

    return 0;
}