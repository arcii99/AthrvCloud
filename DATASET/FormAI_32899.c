//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: light-weight
#include<stdio.h>
#include<string.h>

const int MAX_LEN = 100;

int min(int a, int b, int c) {
    int minVal = a;
    if(b < minVal) {
        minVal = b;
    }
    if(c < minVal) {
        minVal = c;
    }
    return minVal;
}

int calculateLevenshteinDistance(char* string1, char* string2) {
    int len1 = strlen(string1);
    int len2 = strlen(string2);

    int matrix[len1+1][len2+1];
    for(int i=0; i<=len1; i++) {
        for(int j=0; j<=len2; j++) {
            if(i == 0) {
                matrix[i][j] = j;
            }
            else if(j == 0) {
                matrix[i][j] = i;
            }
            else if(string1[i-1] == string2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            }
            else {
                matrix[i][j] = 1 + min(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]);
            }
        }
    }
    return matrix[len1][len2];
}

int main() {
    char string1[MAX_LEN], string2[MAX_LEN];
    printf("Enter string1: ");
    fgets(string1, MAX_LEN, stdin); // Taking input using fgets instead of scanf to avoid buffer overflow
    printf("Enter string2: ");
    fgets(string2, MAX_LEN, stdin);

    // Removing newline character at the end of strings
    string1[strcspn(string1, "\n")] = 0;
    string2[strcspn(string2, "\n")] = 0;

    int distance = calculateLevenshteinDistance(string1, string2);
    printf("Levenshtein Distance between %s and %s is %d", string1, string2, distance);
    return 0;
}