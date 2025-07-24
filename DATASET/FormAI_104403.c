//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Sherlock Holmes
/* It is a truth universally acknowledged, that a programmer in possession of a good challenge, must be in want of a solution.
   And thus, our protagonist Mr. Sherlock Holmes set out to solve the Levenshtein Distance problem.

   For those unfamiliar with the mystery, the Levenshtein Distance is a mathematical calculation of the differences between two strings.
   Mr. Holmes has taken it upon himself to craft a C program to calculate this distance, and he has no time for errors.*/

#include <stdio.h>
#include <string.h>

int LevenshteinDistance(char *string1, char *string2)
{
    int length1 = strlen(string1);
    int length2 = strlen(string2);
    int matrix[length1+1][length2+1];
    
    for(int i=0;i<=length1;i++)
    {
        for(int j=0;j<=length2;j++)
        {
            if(i==0)
            {
                matrix[i][j]=j;
            }
            else if(j==0)
            {
                matrix[i][j]=i;
            }
            else if(string1[i-1]==string2[j-1])
            {
                matrix[i][j]=matrix[i-1][j-1];
            }
            else
            {
                matrix[i][j] = 1 + fmin(matrix[i][j-1], fmin(matrix[i-1][j], matrix[i-1][j-1]));
            }
        }
    }
    
    return matrix[length1][length2];
}

int main()
{
    char str1[] = "Sherlock Holmes";
    char str2[] = "Sherlock Holme";
    int distance = LevenshteinDistance(str1, str2);
    printf("\nThe Levenshtein Distance between '%s' and '%s' is %d.\n", str1, str2, distance);
    return 0;
}
/* Mr. Holmes' program works like a charm, and he may continue to use it in his investigations. */