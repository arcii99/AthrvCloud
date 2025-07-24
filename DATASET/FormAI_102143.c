//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: relaxed
/*
Levenshtein Distance Calculator
Author: [Your Name]
Language: C
*/

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int min(int x, int y, int z) {
    if (x <= y && x <= z) {
        return x;
    } else if (y <= x && y <= z) {
        return y;
    }
    return z;
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];
    printf("Enter string 1: ");
    scanf("%s", str1);
    printf("Enter string 2: ");
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int distance[len1+1][len2+1];
    
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                distance[i][j] = j;
            } else if (j == 0) {
                distance[i][j] = i;
            } else if (str1[i-1] == str2[j-1]) {
                distance[i][j] = distance[i-1][j-1];
            } else {
                distance[i][j] = min(distance[i][j-1], distance[i-1][j], distance[i-1][j-1]) + 1;
            }
        }
    }

    printf("Levenshtein distance between '%s' and '%s' is %d\n", str1, str2, distance[len1][len2]);
    return 0;
}