//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 50

// Function to find minimum of three numbers
int min(int a, int b, int c)
{
    if(a<b && a<c)
        return a;
    else if(b<c)
        return b;
    else
        return c;
}

// Function to calculate Levenshtein distance between two strings
int levenshtein(char *s1, char *s2)
{
    int m = strlen(s1);
    int n = strlen(s2);
    
    // Create a 2D matrix to store distances
    int mat[m+1][n+1];
    
    // Initialize matrix for base case
    for(int i=0; i<=m; i++)
        mat[i][0] = i;
    for(int j=0; j<=n; j++)
        mat[0][j] = j;
    
    // Fill the matrix for each cell using recurrence
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(s1[i-1] == s2[j-1])
                mat[i][j] = mat[i-1][j-1];
            else
                mat[i][j] = 1 + min(mat[i-1][j-1], mat[i][j-1], mat[i-1][j]);
        }
    }
    
    // Return the final distance
    return mat[m][n];
}

int main()
{
    char str1[MAX_STRING_LEN], str2[MAX_STRING_LEN];
    
    printf("Enter first string: ");
    fgets(str1, MAX_STRING_LEN, stdin);
    printf("Enter second string: ");
    fgets(str2, MAX_STRING_LEN, stdin);
    
    // Remove the newline character at the end of each string
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;
    
    // Calculate the Levenshtein distance
    int distance = levenshtein(str1, str2);
    
    // Print the result
    printf("Levenshtein distance between \"%s\" and \"%s\" is %d\n", str1, str2, distance);
    
    return 0;
}