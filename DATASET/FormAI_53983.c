//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: medieval
#include <stdio.h>
#include <string.h>

#define max(x, y) (x > y ? x : y)
#define min(x, y) (x < y ? x : y)

// function to calculate the levenshtein distance
int levenshteinDistance(char* str1, char* str2) {
    int m = strlen(str1);
    int n = strlen(str2);

    // declaring the dynamic programming table
    int dp[m+1][n+1];

    // filling the first row and column with i (or j) alternatively
    for(int i=0; i<=m; i++) dp[i][0] = i;
    for(int j=0; j<=n; j++) dp[0][j] = j;

    // filling the rest of the table using dynamic programming
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];    // no operation required
            } else {
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
            }
        }
    }

    // returning the levenshtein distance
    return dp[m][n];
}

// main function that takes two strings as input and outputs the levenshtein distance
int main() {
    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    int distance = levenshteinDistance(str1, str2);
    printf("The levenshtein distance between %s and %s is %d\n", str1, str2, distance);
    return 0;
}