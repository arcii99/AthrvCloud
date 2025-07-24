//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculating Levenshtein Distance
int minimum(int a, int b, int c) {
    int min;
    if(a<=b && a<=c) min = a;
    if(b<=a && b<=c) min = b;
    if(c<=a && c<=b) min = c;
    return min;
}

int levenshteinDistance(char *word1, char *word2) {
    // Finding lengths of two words
    int m = strlen(word1);
    int n = strlen(word2);

    // Creating a 2D matrix to store the values
    int matrix[m+1][n+1];

    // Filling the matrix with values
    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i==0) matrix[i][j] = j;
            else if(j==0) matrix[i][j] = i;
            else if(word1[i-1]==word2[j-1]) matrix[i][j] = matrix[i-1][j-1];
            else matrix[i][j] = 1 + minimum(matrix[i][j-1], matrix[i-1][j], matrix[i-1][j-1]);
        }
    }
    return matrix[m][n];
}

int main() {
    printf("LEVENSHTEIN DISTANCE CALCULATOR\n");
    printf("Enter two words to find their levenshtein distance:\n");

    // Getting input from the user
    char word1[100], word2[100];
    scanf("%s%s", word1, word2);

    // Calculating the distance
    int distance = levenshteinDistance(word1, word2);

    // Displaying the result
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", word1, word2, distance);

    return 0;
}