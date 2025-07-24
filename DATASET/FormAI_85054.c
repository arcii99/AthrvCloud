//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: real-life
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int minimum(int a, int b, int c) {
    if(a <= b && a <= c) return a;
    if(b <= a && b <= c) return b;
    return c;
}

int levenshtein_distance(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int cost, i, j, **dist;

    dist = (int **)malloc((len1 + 1) * sizeof(int*));
    for(i = 0; i <= len1; i++)
        dist[i] = (int *)malloc((len2+1)*sizeof(int));

    for(i = 0; i <= len1; i++)
        dist[i][0] = i;

    for(j = 0; j <= len2; j++)
        dist[0][j] = j;

    for(i = 1; i <= len1; i++) {
        for(j = 1; j <= len2; j++) {
            if(s1[i-1] == s2[j-1]) cost = 0;
            else cost = 1;
            dist[i][j] = minimum(dist[i-1][j]+1, dist[i][j-1]+1, dist[i-1][j-1]+cost);
        }
    }
    int result = dist[len1][len2];
    for(i = 0; i <= len1; i++) free(dist[i]);
    free(dist);
    return result;
}

int main() {
    char s1[100], s2[100];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);
    printf("Levenshtein distance between %s and %s is %d\n", s1, s2, levenshtein_distance(s1, s2));
    return 0;
}