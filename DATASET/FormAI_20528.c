//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Ken Thompson
// Levenshtein Distance Calculator in Ken Thompson style
// By: Your Name

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

// Function to get minimum of three numbers
int min(int a, int b, int c) {
    if(a <= b && a <= c) {
        return a;
    } else if(b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

// Function to calculate Levenshtein Distance
int levenshteinDistance(char *str1, char *str2, int len1, int len2) {
    int edits[len1+1][len2+1];
    int i, j;
    for(i = 0; i <= len1; i++) {
        for(j = 0; j <= len2; j++) {
            // If any one string is empty, edit distance = length of other string
            if(i == 0) {
                edits[i][j] = j;
            } else if(j == 0) {
                edits[i][j] = i;
            } else if(str1[i-1] == str2[j-1]) {
                // If last characters of both strings are equal, then no edits needed
                edits[i][j] = edits[i-1][j-1];
            } else {
                // If last characters of both strings are different, then take minimum of insert, delete and replace operations
                edits[i][j] = 1 + min(edits[i][j-1], edits[i-1][j], edits[i-1][j-1]);
            }
        }
    }
    // Return the minimum number of edits required to convert str1 to str2
    return edits[len1][len2];
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];
    int len1, len2, distance;
    
    printf("Enter the first string: ");
    fgets(str1, MAX_LEN, stdin);
    len1 = strlen(str1);
    if(len1 > 0 && str1[len1-1] == '\n') {
        str1[len1-1] = '\0'; // remove newline character
        len1--;
    }
    
    printf("Enter the second string: ");
    fgets(str2, MAX_LEN, stdin);
    len2 = strlen(str2);
    if(len2 > 0 && str2[len2-1] == '\n') {
        str2[len2-1] = '\0'; // remove newline character
        len2--;
    }
    
    // Calculate Levenshtein Distance
    distance = levenshteinDistance(str1, str2, len1, len2);
    
    // Display the results
    printf("The Levenshtein Distance between '%s' and '%s' is %d\n", str1, str2, distance);
    
    return 0;
}