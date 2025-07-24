//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mind-bending
#include<stdio.h>
#include<string.h>
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
    char s1[50];
    char s2[50];
    printf("Enter string 1: ");
    scanf("%s", s1);
    printf("Enter string 2: ");
    scanf("%s", s2);

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int dp[len2+1][len1+1];

    for(int i = 0; i<=len1; i++) {
        dp[0][i] = i;
    }

    for(int i = 1; i<=len2; i++) {
        dp[i][0] = i;
    }

    for(int i = 1; i<=len2; i++) {
        for(int j = 1; j<=len1; j++) {
            if(s1[j-1] == s2[i-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]));
            }
        }
    }

    printf("Levenshtein Distance: %d", dp[len2][len1]);
    return 0;
}