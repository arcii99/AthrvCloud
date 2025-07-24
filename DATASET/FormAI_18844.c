//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int min(int x, int y, int z) {
    if(x < y && x < z) return x;
    else if(y < x && y < z) return y;
    else return z;
}

int levenshteinDistance(char * s1, char * s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int memo[len1+1][len2+1];
    for(int i = 0; i < len1+1; i++) memo[i][0] = i;
    for(int i = 0; i < len2+1; i++) memo[0][i] = i;
    for(int i = 1; i < len1+1; i++) {
        for(int j = 1; j < len2+1; j++) {
            if(s1[i-1] == s2[j-1]) memo[i][j] = memo[i-1][j-1];
            else memo[i][j] = min(memo[i-1][j-1], memo[i][j-1], memo[i-1][j]) + 1;
        }
    }
    return memo[len1][len2];
}

int main() {
    char s1[MAX_STRING_LENGTH], s2[MAX_STRING_LENGTH];
    
    printf("Welcome to the exciting Levenshtein Distance Calculator!\n");
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);
    
    int distance = levenshteinDistance(s1, s2);
    
    printf("The Levenshtein Distance between %s and %s is: %d\n", s1, s2, distance);
    
    printf("Thank you for using the exciting Levenshtein Distance Calculator! Goodbye!\n");
    
    return 0;
}