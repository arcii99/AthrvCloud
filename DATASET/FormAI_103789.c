//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int calculateDistance(char s1[], char s2[]) {
    int dp[MAX_LEN][MAX_LEN];
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    for(int i=0; i<=len1; i++) {
        for(int j=0; j<=len2; j++) {
            if(i == 0) {
                dp[i][j] = j;
            } else if(j == 0) {
                dp[i][j] = i;
            } else if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
            }
        }
    }
    return dp[len1][len2];
}

int min(int a, int b, int c) {
    if(a <= b && a <= c) return a;
    else if(b <= a && b <= c) return b;
    else return c;
}

int main() {
    char s1[MAX_LEN], s2[MAX_LEN];
    printf("Enter first string (max length %d): ", MAX_LEN);
    scanf("%s", s1);
    printf("Enter second string (max length %d): ", MAX_LEN);
    scanf("%s", s2);
    int distance = calculateDistance(s1, s2);
    printf("Levenshtein Distance between %s and %s is %d.", s1, s2, distance);
    return 0;
}