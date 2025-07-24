//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: minimalist
#include <stdio.h>
#include <string.h>

int min(int x, int y, int z) {
    if (x <= y && x <= z) {
        return x;
    } else if (y <= x && y <= z) {
        return y;
    } else {
        return z;
    }
}

int levenshtein_distance(char *s, char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);
    int cost, i, j, matrix[len_s + 1][len_t + 1];
    
    for (i = 0; i <= len_s; i++) {
        matrix[i][0] = i;
    }
    
    for (j = 0; j <= len_t; j++) {
        matrix[0][j] = j;
    }
    
    for (i = 1; i <= len_s; i++) {
        for (j = 1; j <= len_t; j++) {
            if (s[i-1] == t[j-1]) {
                cost = 0;
            } else {
                cost = 1;
            }
            
            matrix[i][j] = min(matrix[i-1][j] + 1, 
                               matrix[i][j-1] + 1, 
                               matrix[i-1][j-1] + cost);
        }
    }
    
    return matrix[len_s][len_t];
}

int main() {
    char s[] = "Hello";
    char t[] = "World";
    int distance = levenshtein_distance(s, t);
    
    printf("Levenshtein Distance between %s and %s is %d", s, t, distance);
    
    return 0;
}