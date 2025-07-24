//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int min(int a, int b, int c) {
    int min_value = a;
    
    if (b < min_value) {
        min_value = b;
    }
    if (c < min_value) {
        min_value = c;
    }
    
    return min_value;
}

// Asynchronous function for Levenshtein Distance calculation
void levenshtein_distance_async(char *word_1, char *word_2, int len_1, int len_2, int *result, int *status) {
    // Allocate memory for 2D array to store distances
    int **distances = (int **)malloc((len_1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_1; i++) {
        distances[i] = (int *)malloc((len_2 + 1) * sizeof(int));
    }
    
    // Initialize first row and column
    for (int i = 0; i <= len_1; i++) {
        distances[i][0] = i;
    }
    for (int j = 0; j <= len_2; j++) {
        distances[0][j] = j;
    }
    
    // Calculate distances for all substrings
    for (int i = 1; i <= len_1; i++) {
        for (int j = 1; j <= len_2; j++) {
            int cost = (word_1[i-1] == word_2[j-1]) ? 0 : 1;
            distances[i][j] = min(distances[i-1][j] + 1, distances[i][j-1] + 1, distances[i-1][j-1] + cost);
        }
    }
    
    // Save result and set status
    *result = distances[len_1][len_2];
    *status = 1;
    
    // Free memory
    for (int i = 0; i <= len_1; i++) {
        free(distances[i]);
    }
    free(distances);
}

int main() {
    char word_1[MAX_LENGTH], word_2[MAX_LENGTH];
    int len_1, len_2, result = 0, status = 0;
    
    printf("Enter first word: ");
    scanf("%s", word_1);
    printf("Enter second word: ");
    scanf("%s", word_2);
    
    len_1 = strlen(word_1);
    len_2 = strlen(word_2);
    
    // Call asynchronous function
    levenshtein_distance_async(word_1, word_2, len_1, len_2, &result, &status);
    
    // Wait for asynchronous function to complete
    while (status != 1) {
        // Do nothing
    }
    
    printf("Levenshtein Distance: %d\n", result);
    
    return 0;
}