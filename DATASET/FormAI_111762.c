//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z) {
    if (x < y && x < z) {
        return x;
    } else if (y < x && y < z) {
        return y;
    } else {
        return z;
    }
}

int levenshtein(char* s1, char* s2, int len1, int len2) {
    // Create a 2D array to store the Levenshtein Distance calculations
    int dist[len1+1][len2+1];
    
    // Initialize the first row and column of the array
    for (int i = 0; i <= len1; i++) {
        dist[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        dist[0][j] = j;
    }
    
    // Calculate the Levenshtein Distance between the two strings
    for (int j = 1; j <= len2; j++) {
        for (int i = 1; i <= len1; i++) {
            if (s1[i-1] == s2[j-1]) {
                dist[i][j] = dist[i-1][j-1];
            } else {
                dist[i][j] = min(dist[i-1][j], dist[i][j-1], dist[i-1][j-1]) + 1;
            }
        }
    }
    
    return dist[len1][len2];
}

int main() {
    char s1[] = "kitten";
    char s2[] = "sitting";
    
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    int distance = levenshtein(s1, s2, len1, len2);
    
    printf("Levenshtein Distance between %s and %s is: %d", s1, s2, distance);
    
    return 0;
}