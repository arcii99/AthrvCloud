//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c);

int main() {
    char str1[100], str2[100];
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    
    int m = strlen(str1) - 1;
    int n = strlen(str2) - 1;
    int distance[m+1][n+1];
    
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0) {
                distance[i][j] = j;
            } else if(j == 0) {
                distance[i][j] = i;
            } else if(str1[i-1] == str2[j-1]) {
                distance[i][j] = distance[i-1][j-1];
            } else {
                distance[i][j] = 1 + min(distance[i][j-1], distance[i-1][j], distance[i-1][j-1]);
            }
        }
    }
    
    printf("Levenshtein distance is: %d\n", distance[m][n]);

    return 0;
}

int min(int a, int b, int c) {
    int min = a;
    
    if(b < min) {
        min = b;
    }
    
    if(c < min) {
        min = c;
    }
    
    return min;
}