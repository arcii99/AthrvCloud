//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: shocked
#include <stdio.h>
#include <string.h>

int min(int x, int y, int z) {
    if(x < y && x < z) return x;
    else if(y < x && y < z) return y;
    else return z;
}

int levenshtein_dist(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int dp[len1+1][len2+1];

    for(int i=0; i<=len1; i++) {
        for(int j=0; j<=len2; j++) {
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1;
        }
    }

    return dp[len1][len2];
}

int main() {
    char s1[100], s2[100];

    printf("Enter the first string: ");
    scanf("%s", s1);

    printf("Enter the second string: ");
    scanf("%s", s2);

    int dist = levenshtein_dist(s1, s2);

    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d\n", s1, s2, dist);

    return 0;
}