//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: intelligent
#include<stdio.h>
#include<string.h>

int minimum(int a, int b, int c) {
    if(a<=b && a<=c) {
        return a;
    } else if(b<=a && b<=c) {
        return b;
    } else {
        return c;
    }
}

int levenshteinDistance(char* str1, char* str2, int len1, int len2) {
    // create a 2D array to store the distances
    int matrix[len1+1][len2+1];
    int i,j,substitutionCost;
    
    for(i=0;i<=len1;i++) {
        for(j=0;j<=len2;j++) {
            matrix[i][j] = 0;
        }
    }
    
    for(i=0;i<=len1;i++) {
        matrix[i][0] = i;
    }
    
    for(j=0;j<=len2;j++) {
        matrix[0][j] = j;
    }
    
    for(j=1;j<=len2;j++) {
        for(i=1;i<=len1;i++) {
            if(str1[i-1] == str2[j-1]) {
                substitutionCost = 0;
            } else {
                substitutionCost = 1;
            }
            matrix[i][j] = minimum(matrix[i-1][j]+1, matrix[i][j-1]+1, matrix[i-1][j-1]+substitutionCost);
        }
    }
    
    return matrix[len1][len2];
}

int main() {
    char* str1 = "intelligent";
    char* str2 = "intelligence";
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    printf("Levenshtein Distance between %s and %s is: %d", str1, str2, levenshteinDistance(str1, str2, len1, len2));
    return 0;
}