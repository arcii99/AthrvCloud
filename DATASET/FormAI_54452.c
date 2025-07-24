//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: excited
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if(a < b && a < c)
        return a;
    if(b < a && b < c)
        return b;
    else
        return c;
}

int levenshtein_distance(char s[], char t[]) {
    int len1 = strlen(s);
    int len2 = strlen(t);
    int dp[len1+1][len2+1];
    
    // Initializing the matrix
    for(int i=0; i<=len1; i++) {
        for(int j=0; j<=len2; j++) {
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else
                dp[i][j] = -1;
        }
    }
    
    for(int i=1; i<=len1; i++) {
        for(int j=1; j<=len2; j++) {
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    }
    
    return dp[len1][len2];
}

int main() {
    char s[] = "hello";
    char t[] = "world";
    int dist = levenshtein_distance(s, t);
    printf("The Levenshtein Distance between %s and %s is %d!", s, t, dist);
    return 0;
}