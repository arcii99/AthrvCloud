//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: detailed
#include <stdio.h>
#include <string.h>

// Calculates the minimum of three integers
int min(int a, int b, int c)
{
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return min;
}

// Calculates the Levenshtein Distance between two strings
int levenshtein_distance(char* str1, char* str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Create a 2D array to store the distances
    int dist[len1+1][len2+1];

    // Initialize the first row and column
    for (int i = 0; i <= len1; i++)
        dist[i][0] = i;
    for (int j = 0; j <= len2; j++)
        dist[0][j] = j;

    // Fill in the rest of the array
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (str1[i-1] == str2[j-1])
                dist[i][j] = dist[i-1][j-1]; // No operation necessary
            else
                dist[i][j] = min(dist[i-1][j], dist[i][j-1], dist[i-1][j-1]) + 1; // Take the minimum of three operations
        }
    }

    return dist[len1][len2];
}

// Main function to test the program
int main()
{
    char str1[] = "kitten";
    char str2[] = "sitting";
    int distance = levenshtein_distance(str1, str2);
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);
    return 0;
}