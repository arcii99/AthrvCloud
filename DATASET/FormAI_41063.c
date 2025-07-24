//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: rigorous
#include <stdio.h>
#include <string.h>

int min(int x, int y, int z) {
    if(x < y && x < z) {
        return x;
    } else if(y < x && y < z) {
        return y;
    } else {
        return z;
    }
}

int levenshtein_distance(char *s1, char *s2) {
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    
    int dp[s1_len + 1][s2_len + 1];
    
    for(int i = 0; i <= s1_len; i++) {
        for(int j = 0; j <= s2_len; j++) {
            if(i == 0) {
                dp[i][j] = j;
            } else if(j == 0) {
                dp[i][j] = i;
            } else {
                int cost = s1[i - 1] == s2[j - 1] ? 0 : 1;
                dp[i][j] = min(dp[i - 1][j] + 1, // deletion 
                               dp[i][j - 1] + 1, // insertion
                               dp[i - 1][j - 1] + cost); // substitution
            }
        }
    }
    
    return dp[s1_len][s2_len];
}

int main() {
    char s1[] = "kitten";
    char s2[] = "sitting";
    
    int distance = levenshtein_distance(s1, s2);
    
    printf("The Levenshtein Distance between %s and %s is %d\n", s1, s2, distance);
    
    return 0;
}