//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 256

int levenshtein_distance(char *word1, char *word2) {
    int len1 = strlen(word1), len2 = strlen(word2);
 
    // Create a 2D matrix to store the distances
    int dist[len1+1][len2+1];
    // Initialize the distance matrix
    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            if(i == 0) dist[i][j] = j;
            else if(j == 0) dist[i][j] = i;
            else {
                int cost = (word1[i-1] == word2[j-1]) ? 0 : 1;
                dist[i][j] = fmin(dist[i-1][j] + 1, fmin(dist[i][j-1] + 1, dist[i-1][j-1] + cost));
            }
        }
    }
    return dist[len1][len2];
}

int main() {
    char word1[MAX_LEN], word2[MAX_LEN];
    printf("Enter word1: ");
    fgets(word1, MAX_LEN, stdin);
    printf("Enter word2: ");
    fgets(word2, MAX_LEN, stdin);
    // Remove the newline character
    word1[strcspn(word1, "\n")] = '\0';
    word2[strcspn(word2, "\n")] = '\0';
    int distance = levenshtein_distance(word1, word2);
    printf("Levenshtein Distance between %s and %s is: %d\n", word1, word2, distance);
    return 0;
}