//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z) { 
    return (x < y) ? ((x < z) ? x : z) : ((y < z) ? y : z); 
} 

int findLevenshteinDistance(char *word1, char *word2) { 
    int m = strlen(word1); 
    int n = strlen(word2); 
    int cost[m + 1][n + 1]; 

    for (int i = 0; i <= m; i++) { 
        for (int j = 0; j <= n; j++) { 
            if (i == 0) 
                cost[i][j] = j; 
            else if (j == 0) 
                cost[i][j] = i; 
            else if (word1[i - 1] == word2[j - 1]) 
                cost[i][j] = cost[i - 1][j - 1]; 
            else
                cost[i][j] = 1 + min(cost[i][j - 1], cost[i - 1][j], cost[i - 1][j - 1]); 
        } 
    } 

    return cost[m][n]; 
} 

int main() {
    char word1[100], word2[100];
    printf("Enter word 1: ");
    scanf("%s", word1);
    printf("Enter word 2: ");
    scanf("%s", word2);

    int result = findLevenshteinDistance(word1, word2);
    printf("The Levenshtein distance between %s and %s is: %d\n", word1, word2, result);

    return 0;
}