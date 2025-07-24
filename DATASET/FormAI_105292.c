//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: recursive
#include <stdio.h>
#include <string.h>

// Recursive function to find the minimum of three numbers
int minimum(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

// Recursive function to calculate the Levenshtein distance between two strings
int levDistance(char* str1, char* str2, int len1, int len2) {
    // Base case: If either string is empty, return the length of the other string
    if (len1 == 0) {
        return len2;
    }
    if (len2 == 0) {
        return len1;
    }

    // If the last characters of the strings are the same, no operation is needed
    if (str1[len1 - 1] == str2[len2 - 1]) {
        return levDistance(str1, str2, len1 - 1, len2 - 1);
    }

    // Otherwise, try all three possible operations and choose the minimum
    int insert = levDistance(str1, str2, len1, len2 - 1);
    int delete = levDistance(str1, str2, len1 - 1, len2);
    int replace = levDistance(str1, str2, len1 - 1, len2 - 1);
    int minOps = minimum(insert, delete, replace) + 1;

    return minOps;
}

int main() {
    char str1[] = "kitten";
    char str2[] = "sitting";
    
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int levDist = levDistance(str1, str2, len1, len2);

    printf("The Levenshtein distance between '%s' and '%s' is %d.\n", str1, str2, levDist);

    return 0;
}