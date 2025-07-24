//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: realistic
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int levenshtein_distance(char* s1, char* s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);

    int dist[len_s1 + 1][len_s2 + 1];

    for (int i = 0; i <= len_s1; i++) {
        for (int j = 0; j <= len_s2; j++) {
            if (i == 0) {
                dist[i][j] = j;
            } else if (j == 0) {
                dist[i][j] = i;
            } else if (s1[i - 1] == s2[j - 1]) {
                dist[i][j] = dist[i-1][j-1];
            } else {
                dist[i][j] = 1 + min(dist[i][j-1],  // Insert
                                     dist[i-1][j],  // Delete 
                                     dist[i-1][j-1] // Replace
                                    );
            }
        }
    }
    return dist[len_s1][len_s2];
}

int main() {
    char str1[MAX_LEN];
    char str2[MAX_LEN];
    printf("Enter String 1: ");
    fgets(str1, MAX_LEN, stdin);
    printf("Enter String 2: ");
    fgets(str2, MAX_LEN, stdin);

    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    int dist = levenshtein_distance(str1, str2);

    printf("Levenshtein Distance between \"%s\" and \"%s\" is %d\n", str1, str2, dist);

    return 0;
}