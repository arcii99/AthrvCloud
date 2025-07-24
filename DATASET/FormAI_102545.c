//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int levenshtein_distance(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int cost = 0;

    int *dist = (int *)malloc((len1 + 1) * (len2 + 1) * sizeof(int));

    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            if(i == 0) {
                dist[j] = j;
            } else if(j == 0) {
                dist[i * (len2 + 1)] = i;
            } else if(s1[i - 1] == s2[j - 1]) {
                dist[i * (len2 + 1) + j] = dist[(i - 1) * (len2 + 1) + j - 1];
            } else {
                cost = 1;
                dist[i * (len2 + 1) + j] = min(dist[(i - 1) * (len2 + 1) + j] + 1,
                                              dist[i * (len2 + 1) + j - 1] + 1,
                                              dist[(i - 1) * (len2 + 1) + j - 1] + cost);
            }
        }
    }
    int result = dist[len1 * (len2 + 1) + len2];
    free(dist);
    return result;
}

int main() {
    char *s1 = "kitten";
    char *s2 = "sitting";
    
    printf("Levenshtein Distance between %s and %s is %d\n", s1, s2, levenshtein_distance(s1, s2));

    return 0;
}