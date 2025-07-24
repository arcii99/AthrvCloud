//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: distributed
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int min(int a, int b, int c) {
    if(a<=b && a<=c)  return a;
    if(b<=a && b<=c)  return b;
    return c;
}

int edit_distance(char a[], char b[], int m, int n) {
    int dist[m+1][n+1];
    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i==0)    dist[i][j] = j;
            else if(j==0)   dist[i][j] = i;
            else if(a[i-1]==b[j-1]) dist[i][j] = dist[i-1][j-1];
            else dist[i][j] = 1 + min(dist[i][j-1], dist[i-1][j], dist[i-1][j-1]);
        }
    }
    return dist[m][n];
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];
    printf("Enter the first string: ");
    fgets(str1, MAX_LEN, stdin);
    printf("Enter the second string: ");
    fgets(str2, MAX_LEN, stdin);
    int m = strlen(str1)-1, n = strlen(str2)-1;
    int result = edit_distance(str1, str2, m, n);
    printf("\nLevenshtein Distance between the strings: %d\n", result);
    return 0;
}