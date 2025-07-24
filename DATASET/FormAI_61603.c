//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the minimum of three integers
int min(int a, int b, int c)
{
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return min;
}

// Levenshtein Distance Calculator function
int levenshtein(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Create a 2D table to store distances
    int dist[len1 + 1][len2 + 1];

    // Initialize the table
    for (int row = 0; row <= len1; row++)
    {
        for (int col = 0; col <= len2; col++)
        {
            if (row == 0)
                dist[row][col] = col;
            else if (col == 0)
                dist[row][col] = row;
            else if (s1[row - 1] == s2[col - 1])
                dist[row][col] = dist[row - 1][col - 1];
            else
                dist[row][col] = 1 + min(dist[row][col - 1], dist[row - 1][col], dist[row - 1][col - 1]);
        }
    }

    // Return the distance at the bottom right of the table
    return dist[len1][len2];
}

int main()
{
    // Test the function with some example inputs
    char s1[] = "kitten";
    char s2[] = "sitting";
    printf("Levenshtein Distance between %s and %s is %d\n", s1, s2, levenshtein(s1, s2));

    char s3[] = "Sunday";
    char s4[] = "Saturday";
    printf("Levenshtein Distance between %s and %s is %d\n", s3, s4, levenshtein(s3, s4));

    return 0;
}