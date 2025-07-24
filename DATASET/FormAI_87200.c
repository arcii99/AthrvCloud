//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z) {
    if (x < y && x < z)
        return x;
    else if (y < x && y < z)
        return y;
    else
        return z;
}

int levenshteinDistance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int distance[len1+1][len2+1];

    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            if(i == 0)
                distance[i][j] = j;
            else if(j == 0)
                distance[i][j] = i;
            else if(str1[i-1] == str2[j-1])
                distance[i][j] = distance[i-1][j-1];
            else
                distance[i][j] = 1 + min(distance[i][j-1], distance[i-1][j], distance[i-1][j-1]);
        }
    }

    return distance[len1][len2];
}

int main() {
    char* str1 = "kitten";
    char* str2 = "sitting";

    int distance = levenshteinDistance(str1, str2);

    printf("Levenshtein Distance between '%s' and '%s' is %d.\n", str1, str2, distance);

    return 0;
}