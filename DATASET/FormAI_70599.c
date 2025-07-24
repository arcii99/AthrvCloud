//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: recursive
#include <stdio.h>
#include <string.h>

// Recursive function to calculate the Levenshtein Distance between two strings
int LevenshteinDistance(char *str1, char *str2, int len1, int len2)
{
    // base case: if any of the strings is empty, return the length of the non-empty string
    if (len1 == 0)
        return len2;
    if (len2 == 0)
        return len1;

    // If the last characters of the two strings match, recur for the remaining string
    if (str1[len1 - 1] == str2[len2 - 1])
        return LevenshteinDistance(str1, str2, len1 - 1, len2 - 1);

    // If the last characters of the two strings don't match, we have three options   

    // Insertion: recur for str1 with the last character of str2 added to it
    int insert = LevenshteinDistance(str1, str2, len1, len2 - 1);

    // Deletion: recur for str1 with the last character removed
    int del = LevenshteinDistance(str1, str2, len1 - 1, len2);

    // Substitution: recur for str1 with the last character replaced by the last character of str2
    int sub = LevenshteinDistance(str1, str2, len1 - 1, len2 - 1);

    // Return the minimum of the above three options plus 1
    return 1 + ((insert > del) ? ((del > sub) ? sub : del) : ((insert > sub) ? sub : insert));
}

int main()
{
    char str1[50], str2[50];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int distance = LevenshteinDistance(str1, str2, len1, len2);
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);
    return 0;
}