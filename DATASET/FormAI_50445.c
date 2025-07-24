//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: grateful
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a < b && a < c)
        return a;
    if (b < a && b < c)
        return b;
    return c;
}

int levenshtein_distance(char* str1, char* str2) {
    int len1 = strlen(str1), len2 = strlen(str2);
    int dist[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++)
        dist[i][0] = i;

    for (int j = 0; j <= len2; j++)
        dist[0][j] = j;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1])
                dist[i][j] = dist[i - 1][j - 1];
            else
                dist[i][j] = min(dist[i - 1][j], dist[i][j - 1], dist[i - 1][j - 1]) + 1;
        }
    }

    return dist[len1][len2];
}

int main() {
    char* str1 = "grateful";
    char* str2 = "greatful";
    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein distance between '%s' and '%s' is: %d\n", str1, str2, distance);
    
    return 0;
}