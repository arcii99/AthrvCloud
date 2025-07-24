//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int levenshteinDistance(char* s1, char* s2);

int main(int argc, char** argv) {
    char* word1 = "elementary";
    char* word2 = "mydearwatson";
    int distance = levenshteinDistance(word1, word2);
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d\n", word1, word2, distance);
    return 0;
}

int levenshteinDistance(char* s1, char* s2) {
    int n = strlen(s1);
    int m = strlen(s2);
    
    int** d = calloc(n + 1, sizeof(int*));
    for (int i = 0; i < n + 1; i++) {
        d[i] = calloc(m + 1, sizeof(int));
    }
    
    for (int i = 1; i <= n; i++) {
        d[i][0] = i;
    }
    for (int j = 1; j <= m; j++) {
        d[0][j] = j;
    }
    
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            }
            else {
                int min = d[i - 1][j] + 1;
                if (d[i][j - 1] + 1 < min) {
                    min = d[i][j - 1] + 1;
                }
                if (d[i - 1][j - 1] + 1 < min) {
                    min = d[i - 1][j - 1] + 1;
                }
                d[i][j] = min;
            }
        }
    }
    
    int distance = d[n][m];
    
    for (int i = 0; i < n + 1; i++) {
        free(d[i]);
    }
    free(d);
    
    return distance;
}