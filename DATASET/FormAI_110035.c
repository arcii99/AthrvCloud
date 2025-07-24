//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: introspective
#include <stdio.h>
#include <string.h>

// Function to calculate the minimum of two numbers
int min(int a, int b) {
    return a < b ? a : b;
}

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(char* s1, char* s2) {
    // Get the length of the two strings
    int n = strlen(s1);
    int m = strlen(s2);
    
    // Create a matrix to store the distances between the substrings
    int dp[n+1][m+1];
    
    // Initialize the matrix with base cases
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0) {
                dp[i][j] = j;
            }
            else if (j == 0) {
                dp[i][j] = i;
            }
            else if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
            }
        }
    }
    
    // Return the final element of the matrix, which contains the distance between the two strings
    return dp[n][m];
}

int main() {
    char s1[] = "hello";
    char s2[] = "world";
    
    int distance = levenshtein_distance(s1, s2);
    
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d", s1, s2, distance);
    
    return 0;
}