//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mathematical
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if(a <= b && a <= c)
        return a;
    if(b <= a && b <= c)
        return b;
    else
        return c;
}

int getLevenshteinDistance(char str1[], char str2[], int len1, int len2) {
    int distance[len1 + 1][len2 + 1];

    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            if(i == 0)
                distance[i][j] = j;
            else if(j == 0)
                distance[i][j] = i;
            else if(str1[i - 1] == str2[j - 1])
                distance[i][j] = distance[i - 1][j - 1];
            else
                distance[i][j] = 1 + min(distance[i][j - 1], distance[i - 1][j], distance[i - 1][j - 1]);
        }
    }

    return distance[len1][len2];
}

int main() {
    char str1[] = "mathematics";
    char str2[] = "mathematical";

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int LevenshteinDistance = getLevenshteinDistance(str1, str2, len1, len2);

    printf("Levenshtein Distance between %s and %s is %d \n", str1, str2, LevenshteinDistance);

    return 0;
}