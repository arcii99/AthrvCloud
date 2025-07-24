//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z) {
    return (x < y ? (x < z ? x : z) : (y < z ? y : z));
}

int levenshteinDistance(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    
    int dp[len1 + 1][len2 + 1];
    
    for (int i = 0; i <= len1; i++){
        for (int j = 0; j <= len2; j++){
            if (i == 0){
                dp[i][j] = j;
            }
            else if (j == 0){
                dp[i][j] = i;
            }
            else{
                dp[i][j] = min(
                    dp[i-1][j-1] + (word1[i-1] != word2[j-1]), 
                    dp[i-1][j] + 1, 
                    dp[i][j-1] + 1
                );
            }
        }
    }
    return dp[len1][len2];
}

int main() {
    char* word1 = "kitten";
    char* word2 = "sitting";
    
    int distance = levenshteinDistance(word1, word2);
    
    printf("The Levenshtein distance between %s and %s is %d.\n", word1, word2, distance);
    
    return 0;
}