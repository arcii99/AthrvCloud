//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// function to calculate the minimum of three values
int min(int a, int b, int c) {
    int smallest = a;
    if (b < smallest) {
        smallest = b;
    }
    if (c < smallest) {
        smallest = c;
    }
    return smallest;
}

// function to calculate the Levenshtein distance between two strings
int levenshtein_distance(char *s1, char *s2) {
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    
    // create a 2D array to hold the distances between each pair of characters
    int distances[s1_len+1][s2_len+1];
    
    // initialize the first row and column of the array with their indices
    for (int i = 0; i <= s1_len; i++) {
        distances[i][0] = i;
    }
    for (int j = 0; j <= s2_len; j++) {
        distances[0][j] = j;
    }
    
    // fill in the remaining entries of the array
    for (int i = 1; i <= s1_len; i++) {
        for (int j = 1; j <= s2_len; j++) {
            // if the characters match, the distance is the same as the diagonal entry
            if (s1[i-1] == s2[j-1]) {
                distances[i][j] = distances[i-1][j-1];
            }
            // otherwise, add 1 to the minimum of the three adjacent entries
            else {
                distances[i][j] = 1 + min(distances[i-1][j], distances[i][j-1], distances[i-1][j-1]);
            }
        }
    }
    
    // the final answer is the entry in the bottom-right corner of the array
    return distances[s1_len][s2_len];
}

// example usage of the Levenshtein distance calculator
int main() {
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];
    
    printf("Enter the first string: ");
    fgets(s1, MAX_LENGTH, stdin);
    s1[strcspn(s1, "\n")] = 0; // remove newline character at the end
    
    printf("Enter the second string: ");
    fgets(s2, MAX_LENGTH, stdin);
    s2[strcspn(s2, "\n")] = 0; // remove newline character at the end
    
    int distance = levenshtein_distance(s1, s2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);
    
    return 0;
}