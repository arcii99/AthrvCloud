//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: irregular
#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#define minimum(x, y, z) ((x) < (y) ? ((x) < (z) ? (x) : (z)) : ((y) < (z) ? (y) : (z)))

int levenshtein(char* A, char* B, int m, int n){
    if (m == 0) return n;
    if (n == 0) return m;

    if (A[m-1] == B[n-1]) return levenshtein(A, B, m-1, n-1);

    return 1 + minimum(levenshtein(A, B, m, n-1),
                 levenshtein(A, B, m-1, n),           
                 levenshtein(A, B, m-1, n-1));       
}

int main(){
    char stringA[200] = "kitten";
    char stringB[200] = "sitting";
    int result = levenshtein(stringA, stringB, strlen(stringA), strlen(stringB));

    printf("The Levenshtein Distance between '%s' and '%s' is %d.\n", stringA, stringB, result);

    return 0;
}