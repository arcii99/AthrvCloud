//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    else return c;
}

int levenshteinDistance(char* s1, char* s2) {
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    
    int matrix[s1_len+1][s2_len+1];
    
    for(int i=0;i<=s1_len;i++) {
        for(int j=0;j<=s2_len;j++) {
            if(i==0) {
                matrix[i][j] = j;
            }
            else if(j==0) {
                matrix[i][j] = i;
            }
            else if(s1[i-1] == s2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            }
            else {
                matrix[i][j] = 1 + min(matrix[i-1][j-1],matrix[i][j-1],matrix[i-1][j]);
            }
        }
    }
    return matrix[s1_len][s2_len];
}

int main() {
    char* s1 = "kitten";
    char* s2 = "sitting";
    
    int distance = levenshteinDistance(s1, s2);
    
    printf("The levenshtein distance between %s and %s is %d.\n", s1, s2, distance);
    
    return 0;
}