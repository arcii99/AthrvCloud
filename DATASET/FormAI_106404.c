//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A function to return the minimum of three integers
int min(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
 
    if (b <= a && b <= c)
        return b;
 
    else
        return c;
}

// A function to calculate the Levenshtein distance between two strings
int levenshteinDistance(char *s1, char *s2)
{
    // Calculate the lengths of the input strings
    int len1 = strlen(s1);
    int len2 = strlen(s2);
 
    // Create a matrix to store the distance between the substrings
    int mat[len1+1][len2+1];
 
    // Initialize the first row and column of the matrix
    for (int i = 0; i <= len1; i++)
        mat[i][0] = i;
    for (int j = 0; j <= len2; j++)
        mat[0][j] = j;
 
    // Traverse the matrix and calculate the distance between substrings
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i-1] == s2[j-1])
                mat[i][j] = mat[i-1][j-1];
            else
                mat[i][j] = 1 + min(mat[i-1][j], mat[i][j-1], mat[i-1][j-1]);
        }
    }
 
    // Return the Levenshtein distance
    return mat[len1][len2];
}
 
int main()
{
    char s1[100], s2[100];
 
    printf("Enter the first string: ");
    scanf("%s", s1);
 
    printf("Enter the second string: ");
    scanf("%s", s2);
 
    // Call the Levenshtein distance function to calculate the distance between the input strings
    int distance = levenshteinDistance(s1, s2);
 
    printf("\nThe Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);
 
    return 0;
}