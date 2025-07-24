//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    /* Returns the minimum value from the given three values */
    int temp = a < b ? a : b;
    return temp < c ? temp : c;
}

int levenshteinDistance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int dp[len1+1][len2+1];

    /* Initializing the 2D array */
    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            if(i == 0) {
                dp[i][j] = j; // Fill the first row 
            } else if(j == 0) {
                dp[i][j] = i; // Fill the first column
            } else if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1]; // If characters are same, no need to update
            } else {
                dp[i][j] = 1 + min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]); // Calculate the minimum distance
            }
        }
    }

    return dp[len1][len2]; // Returns the calculated distance
}

int main() {
    char str1[] = "Hello";
    char str2[] = "World";
    int distance = levenshteinDistance(str1, str2);
    printf("The Levenshtein Distance between %s and %s is: %d\n", str1, str2, distance);
    return 0;
}