//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 1000     // maximum length of strings

/* function to calculate minimum of a, b and c */
int min(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
    if (b <= a && b <= c)
        return b;
    else
        return c;
}

/* function to calculate Levenshtein distance between two strings */
int levenshtein_distance(char *str1, char *str2)
{
    // get length of strings
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // create 2D array of distance values
    int dist[len1 + 1][len2 + 1];
   
    // initialize first row and column
    for (int i = 0; i <= len1; i++)
        dist[i][0] = i;
    for (int j = 0; j <= len2; j++)
        dist[0][j] = j;

    // calculate distance values for each cell in 2D array
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            int cost;
            if (str1[i - 1] == str2[j - 1])
                cost = 0;
            else
                cost = 1;
            
            int deletion = dist[i - 1][j] + 1;
            int insertion = dist[i][j - 1] + 1;
            int substitution = dist[i - 1][j - 1] + cost;
            
            dist[i][j] = min(deletion, insertion, substitution);
        }
    }

    // return minimum distance (value in bottom-right cell)
    return dist[len1][len2];
}

int main()
{
    char str1[MAX_LEN], str2[MAX_LEN];
    printf("Enter first string:\n");
    fgets(str1, MAX_LEN, stdin);
    printf("Enter second string:\n");
    fgets(str2, MAX_LEN, stdin);
    
    // remove newline character at end of string
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    int distance = levenshtein_distance(str1, str2);
    printf("Levenshtein distance between \"%s\" and \"%s\" is %d\n", str1, str2, distance);

    return 0;
}