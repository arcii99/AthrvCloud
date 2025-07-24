//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b, int c) {
    if(a <= b && a <= c) return a;
    if(b <= a && b <= c) return b;
    else return c;
}

int levenshtein_distance(char* s1, char* s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int d[len1 + 1][len2 + 1];
    for(int i = 0; i <= len1; i++) d[i][0] = i;
    for(int j = 0; j <= len2; j++) d[0][j] = j;

    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            int substitutionCost = (s1[i-1] != s2[j-1]);
            d[i][j] = min(d[i-1][j] + 1, d[i][j-1] + 1, d[i-1][j-1] + substitutionCost);
        }
    }
    return d[len1][len2];
}

int main() {
    char s1[100], s2[100];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);

    int dist = levenshtein_distance(s1, s2);
    printf("Levenshtein distance between %s and %s is %d\n", s1, s2, dist);
    return 0;
}