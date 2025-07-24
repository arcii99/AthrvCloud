//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: high level of detail
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int levenshtein_distance(char *s1, char *s2){
    int s1_len = strlen(s1), s2_len = strlen(s2);
    int dp[MAX_LEN][MAX_LEN];

    for(int i = 0; i <= s1_len; i++){
        for(int j = 0; j <= s2_len; j++){
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;

            else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + fmin(fmin(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
        }
    }

    return dp[s1_len][s2_len];
}

int main(){
    char s1[MAX_LEN], s2[MAX_LEN];
    printf("Enter two strings: ");
    scanf("%s%s", s1, s2);

    int distance = levenshtein_distance(s1, s2);
    printf("\nLevenshtein Distance between %s and %s: %d\n", s1, s2, distance);
    return 0;
}