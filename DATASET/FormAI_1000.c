//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: intelligent
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
    
    int distance[len_s + 1][len_t + 1];
    
    for (int i = 0; i <= len_s; i++) {
        for (int j = 0; j <= len_t; j++) {
            if (i == 0) {
                distance[i][j] = j;
            } else if (j == 0) {
                distance[i][j] = i;
            } else if (s[i - 1] == t[j - 1]) {
                distance[i][j] = distance[i - 1][j - 1];
            } else {
                distance[i][j] = 1 + min(distance[i - 1][j], distance[i][j - 1], distance[i - 1][j - 1]);
            }
        }
    }
    
    return distance[len_s][len_t];
}

int main() {
    char s1[] = "Hello, World!";
    char s2[] = "Hllo, Wrd!";
    
    int distance = levenshtein_distance(s1, s2);
    
    printf("Levenshtein Distance: %d\n", distance);
    
    return 0;
}