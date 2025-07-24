//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: recursive
#include <stdio.h>
#include <string.h>

// Recursive function to calculate Levenshtein Distance
int levenshteinDistance(char *str1, char *str2, int m, int n) {
    // Base case
    if (m == 0) 
        return n;
    if (n == 0)
        return m;
    
    // Check if the last characters of the two strings match
    if (str1[m-1] == str2[n-1])
        return levenshteinDistance(str1, str2, m-1, n-1);
    
    // Calculate the minimum of three operations: deletion, insertion, and substitution
    return 1 + min(levenshteinDistance(str1, str2, m, n-1),        // Insert
                   levenshteinDistance(str1, str2, m-1, n),        // Delete
                   levenshteinDistance(str1, str2, m-1, n-1)      // Substitute
    );
}

// Helper function to find the minimum of three integers
int min(int x, int y, int z) {
    if (x <= y && x <= z)
        return x;
    if (y <= x && y <= z)
        return y;
    return z;
}

int main() {
    char str1[100], str2[100];
    
    printf("Enter first string: ");
    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = '\0';        // Removing newline character
    
    printf("Enter second string: ");
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = '\0';        // Removing newline character
    
    int m = strlen(str1);
    int n = strlen(str2);
    
    printf("Levenshtein Distance between \"%s\" and \"%s\" is %d\n", str1, str2, levenshteinDistance(str1, str2, m, n));
    
    return 0;
}