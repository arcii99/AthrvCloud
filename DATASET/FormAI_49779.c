//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: cheerful
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c){
    int min = a;
    if(b < min){
        min = b;
    }
    if(c < min){
        min = c;
    }
    return min;
}

int calculateLevenshteinDistance(char *word1, int len1, char *word2, int len2){
    int i, j, cost, substitutionCost;
    int dp[len1+1][len2+1];
    for(i=0;i<=len1;i++){
        dp[i][0] = i;
    }
    for(j=0;j<=len2;j++){
        dp[0][j] = j;
    }
    for(i=1;i<=len1;i++){
        for(j=1;j<=len2;j++){
            cost = (word1[i-1] == word2[j-1]) ? 0 : 1;
            substitutionCost = dp[i-1][j-1]+cost;
            dp[i][j] = min(dp[i][j-1]+1, dp[i-1][j]+1, substitutionCost);
        }
    }
    return dp[len1][len2];
}

int main(){
    char word1[] = "chatbot";
    char word2[] = "chatterbox";
    printf("The Levenshtein Distance between %s and %s is %d", word1, word2, calculateLevenshteinDistance(word1, strlen(word1), word2, strlen(word2)));
    return 0;
}