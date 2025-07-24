//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: peaceful
#include<stdio.h>
#include<string.h>

int min(int x, int y, int z) {
    if (x <= y && x <= z) return x;
    if (y <= x && y <= z) return y;
    else return z;
}

int lev_distance(char *str1, char *str2, int len1, int len2) {
    int dist[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; ++i) {
        for (int j = 0; j <= len2; ++j) {
            if (i == 0) dist[i][j] = j;
            else if (j == 0) dist[i][j] = i;
            else if (str1[i - 1] == str2[j - 1]) dist[i][j] = dist[i - 1][j - 1];
            else dist[i][j] = 1 + min(dist[i][j - 1], dist[i - 1][j], dist[i - 1][j - 1]);
        }
    }
    return dist[len1][len2];
}

int main() {
    char str1[100], str2[100];
    printf("Enter the first string: ");
    
    // reading the first string
    fgets(str1, 100, stdin);
    
    printf("Enter the second string: ");
    
    // reading the second string
    fgets(str2, 100, stdin);
    
    int len1 = strlen(str1) - 1; // to remove '\n' from fgets()
    int len2 = strlen(str2) - 1; // to remove '\n' from fgets()
    
    // calling lev_distance() function to calculate Levenshtein Distance
    int distance = lev_distance(str1, str2, len1, len2);
    
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);

    return 0;
}