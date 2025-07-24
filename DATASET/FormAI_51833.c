//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: satisfied
#include <stdio.h>
#include <string.h>

// function to calculate minimum of three integers
int min(int a, int b, int c) {
    if(a<=b && a<=c)
        return a;
    else if(b<=a && b<=c)
        return b;
    else
        return c;
}

// function to calculate the Levenshtein Distance
int levenshteinDistance(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    int distance[m+1][n+1];
    int i, j;

    // initially setting the first row and column with index values
    for(i = 0; i <= m; i++) {
        distance[i][0] = i;
    }

    for(j = 0; j <= n; j++) {
        distance[0][j] = j;
    }

    // traversing through the matrix and checking for the minimum distance
    for(i = 1; i <= m; i++) {
        for(j = 1; j <= n; j++) {
            if(s1[i-1] == s2[j-1]) {
                distance[i][j] = distance[i-1][j-1];
            } else {
                distance[i][j] = min(distance[i-1][j], distance[i][j-1], distance[i-1][j-1]) + 1;
            }
        }
    }
    
    return distance[m][n];
}

// main function to test the program
int main() {
    // test cases
    char s1[] = "kitten";
    char s2[] = "sitting";
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d\n", s1, s2, levenshteinDistance(s1, s2));

    char s3[] = "distance";
    char s4[] = "difference";
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d\n", s3, s4, levenshteinDistance(s3, s4));

    char s5[] = "algorithm";
    char s6[] = "logarithm";
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d\n", s5, s6, levenshteinDistance(s5, s6));

    return 0;
}