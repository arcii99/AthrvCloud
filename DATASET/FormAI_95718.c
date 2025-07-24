//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: sophisticated
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    int m = a;
    if (m > b) m = b;
    if (m > c) m = c;
    return m;
}

int LevenshteinDistance(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    int D[m+1][n+1];
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) D[i][j] = j;
            else if (j == 0) D[i][j] = i;
            else if (s1[i-1] == s2[j-1]) D[i][j] = D[i-1][j-1];
            else D[i][j] = 1 + min(D[i-1][j], D[i][j-1], D[i-1][j-1]);
        }
    }
    
    return D[m][n];
}

int main() {
    char s1[100],s2[100];
    printf("Enter string 1: ");
    scanf("%s",s1);
    printf("Enter string 2: ");
    scanf("%s",s2);
    
    int distance = LevenshteinDistance(s1,s2);
    printf("Levenshtein Distance between \"%s\" and \"%s\" is %d.\n",s1,s2,distance);
    
    return 0;
}