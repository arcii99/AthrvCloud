//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: random
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int dp[MAX_LEN+1][MAX_LEN+1];

int min(int a, int b, int c) {
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int getLevenshteinDistance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    for(int i=0; i<=len1; i++) {
        dp[i][0] = i;
    }
    
    for(int j=0; j<=len2; j++) {
        dp[0][j] = j;
    }
    
    for(int i=1; i<=len1; i++) {
        for(int j=1; j<=len2; j++) {
            int cost = (str1[i-1] == str2[j-1]) ? 0 : 1;

            dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+cost);
        }
    }
    
    return dp[len1][len2];
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];
    
    printf("Enter first string: ");
    scanf("%s", str1);
    
    printf("Enter second string: ");
    scanf("%s", str2);
    
    int dist = getLevenshteinDistance(str1, str2);
    
    printf("The Levenshtein Distance between '%s' and '%s' is %d\n", str1, str2, dist);
    
    return 0;
}