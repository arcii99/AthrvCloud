//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if(a < b && a < c) {
        return a;
    }
    else if(b < a && b < c) {
        return b;
    }
    else {
        return c;
    }
}

int levenshtein_distance(char *s1, int len1, char *s2, int len2) {
    int distance[len1+1][len2+1];
    
    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            if(i == 0) {
                distance[i][j] = j;
            }
            else if(j == 0) {
                distance[i][j] = i;
            }
            else if(s1[i-1] == s2[j-1]) {
                distance[i][j] = distance[i-1][j-1];
            }
            else {
                distance[i][j] = 1 + min(distance[i][j-1], distance[i-1][j], distance[i-1][j-1]);
            }
        }
    }
    
    return distance[len1][len2];
}

int main() {
    char s1[] = "kitten";
    char s2[] = "sitting";
    
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    int distance = levenshtein_distance(s1, len1, s2, len2);
    
    printf("The Levenshtein Distance between '%s' and '%s' is %d", s1, s2, distance);
    
    return 0;
}