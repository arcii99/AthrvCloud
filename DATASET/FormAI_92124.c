//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

// calculate the minimum of three numbers
int min(int a, int b, int c) {
    int minValue = a;
    if (b < minValue) minValue = b;
    if (c < minValue) minValue = c;
    return minValue;
}

// calculate the Levenshtein Distance
int levenshteinDistance(char* s, char* t) {
    int sLen = strlen(s);
    int tLen = strlen(t);
    int d[MAX_LEN][MAX_LEN];
    int i, j;
    
    // initialize the first row and column of the 2d array
    for(i=0; i<=sLen; i++) d[i][0] = i;
    for(j=0; j<=tLen; j++) d[0][j] = j;
    
    // calculate the remaining values of the 2d array
    for(i=1; i<=sLen; i++) {
        for(j=1; j<=tLen; j++) {
            int substitutionCost = s[i-1] == t[j-1] ? 0 : 1;
            d[i][j] = min(d[i-1][j]+1, d[i][j-1]+1, d[i-1][j-1]+substitutionCost);
        }
    }
    return d[sLen][tLen];
}

int main() {
    char s[MAX_LEN], t[MAX_LEN];
    
    // read in two strings from input
    printf("Enter the first string: ");
    fgets(s, MAX_LEN, stdin);
    s[strcspn(s, "\n")] = '\0';  // remove any trailing newline character
    
    printf("Enter the second string: ");
    fgets(t, MAX_LEN, stdin);
    t[strcspn(t, "\n")] = '\0';  // remove any trailing newline character
    
    // calculate the Levenshtein distance and print the result
    printf("The Levenshtein distance between %s and %s is %d\n", s, t, levenshteinDistance(s, t));
    
    return 0;
}