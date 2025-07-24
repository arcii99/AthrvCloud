//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100

// Function to calculate the minimum of three integers
int min(int a, int b, int c) {
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return min;
}

// Function to calculate the Levenshtein Distance between two strings
int levenshteinDistance(char *word1, char *word2) {
    int dp[MAX_WORD_LENGTH + 1][MAX_WORD_LENGTH + 1];
    int word1_length = strlen(word1);
    int word2_length = strlen(word2);

    // If any of the input strings are empty, return the length of the other string
    if (word1_length == 0) {
        return word2_length;
    } else if (word2_length == 0) {
        return word1_length;
    }

    // Initialize the first row and column of the DP table
    for (int i = 0; i <= word1_length; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= word2_length; j++) {
        dp[0][j] = j;
    }

    // Fill up the DP table
    for (int i = 1; i <= word1_length; i++) {
        for (int j = 1; j <= word2_length; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
            }
        }
    }

    // Return the final result
    return dp[word1_length][word2_length];
}

int main() {
    char word1[MAX_WORD_LENGTH];
    char word2[MAX_WORD_LENGTH];

    // Get input from user
    printf("Enter the first word: ");
    fgets(word1, MAX_WORD_LENGTH, stdin);
    printf("Enter the second word: ");
    fgets(word2, MAX_WORD_LENGTH, stdin);

    // Remove newline characters from input strings
    word1[strcspn(word1, "\n")] = 0;
    word2[strcspn(word2, "\n")] = 0;

    // Calculate and print the Levenshtein Distance
    int distance = levenshteinDistance(word1, word2);
    printf("The Levenshtein Distance between '%s' and '%s' is %d.\n", word1, word2, distance);

    return 0;
}