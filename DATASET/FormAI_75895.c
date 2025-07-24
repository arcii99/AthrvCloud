//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 1000

// Function to calculate the minimum of three values
int min(int a, int b, int c) {
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else
        return c;
}

// Function to calculate the Levenshtein Distance between two strings
int levenshteinDistance(char* string1, char* string2) {
    int string1Length = strlen(string1);
    int string2Length = strlen(string2);
    
    // Create a table to store intermediate results
    int table[string1Length + 1][string2Length + 1];
    
    // Initialize the first row and column of the table
    for (int i = 0; i <= string1Length; i++) {
        table[i][0] = i;
    }
    for (int j = 0; j <= string2Length; j++) {
        table[0][j] = j;
    }
    
    // Fill in the rest of the table using dynamic programming approach
    for (int i = 1; i <= string1Length; i++) {
        for (int j = 1; j <= string2Length; j++) {
            if (string1[i - 1] == string2[j - 1]) {
                table[i][j] = table[i - 1][j - 1];
            } else {
                table[i][j] = 1 + min(table[i - 1][j - 1], table[i][j - 1], table[i - 1][j]);
            }
        }
    }
    
    // Return the distance between the two strings
    return table[string1Length][string2Length];
}

int main() {
    char string1[MAX_INPUT_LENGTH];
    char string2[MAX_INPUT_LENGTH];
    
    printf("Enter the first string: ");
    fgets(string1, MAX_INPUT_LENGTH, stdin);
    printf("Enter the second string: ");
    fgets(string2, MAX_INPUT_LENGTH, stdin);
    
    // Remove the newline character from the end of the input strings
    string1[strcspn(string1, "\n")] = 0;
    string2[strcspn(string2, "\n")] = 0;
    
    // Calculate the Levenshtein Distance between the two strings
    int distance = levenshteinDistance(string1, string2);
    
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d\n", string1, string2, distance);
    
    return 0;
}