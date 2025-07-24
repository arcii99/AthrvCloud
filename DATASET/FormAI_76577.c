//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    else if (b <= a && b <= c) return b;
    else return c;
}

// Function to calculate Levenshtein distance between two strings
int levenshteinDistance(char* s, char* t) {
    // Determine length of two strings
    int n = strlen(s);
    int m = strlen(t);

    // Initialize a 2D array to store distances
    int dist[n+1][m+1];
    
    // Initialize array with distances between each character and empty string
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i == 0) {
                dist[i][j] = j;
            } else if(j == 0) {
                dist[i][j] = i;
            } else if(s[i-1] == t[j-1]) {
                dist[i][j] = dist[i-1][j-1];
            } else {
                dist[i][j] = 1 + min(dist[i-1][j], dist[i][j-1], dist[i-1][j-1]);
            }
        }
    }
    
    // Return distance between the strings
    return dist[n][m];
}

int main() {
    // Testing the Levenshtein distance calculator
    char* s1 = "kitten";
    char* s2 = "sitting";
    char* s3 = "leap";
    char* s4 = "beep";
  
    printf("Levenshtein distance between '%s' and '%s': %d\n", s1, s2, levenshteinDistance(s1, s2));
    printf("Levenshtein distance between '%s' and '%s': %d\n", s1, s3, levenshteinDistance(s1, s3));
    printf("Levenshtein distance between '%s' and '%s': %d\n", s3, s4, levenshteinDistance(s3, s4));
  
    return 0;
}