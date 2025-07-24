//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three numbers
int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

// Levenshtein distance calculator function
int levenshteinDistance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int result[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                result[i][j] = j;
            }
            else if (j == 0) {
                result[i][j] = i;
            }
            else if (str1[i - 1] == str2[j - 1]) {
                result[i][j] = result[i - 1][j - 1];
            }
            else {
                result[i][j] = 1 + min(result[i - 1][j], result[i][j - 1], result[i - 1][j - 1]);
            }
        }
    }
    return result[len1][len2];
}

int main() {
    char* str1 = "happy";
    char* str2 = "happier";
    int distance = levenshteinDistance(str1, str2);
    printf("The Levenshtein distance between %s and %s is %d.\n", str1, str2, distance);
    return 0;
}