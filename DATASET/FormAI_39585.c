//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: rigorous
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int levenshtein_distance(char *s1, char *s2) {

    int m = strlen(s1);
    int n = strlen(s2);
    int distance[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {

            if (i == 0) distance[i][j] = j; // insert j characters
            else if (j == 0) distance[i][j] = i; // delete i characters
            else if (s1[i-1] == s2[j-1]) distance[i][j] = distance[i-1][j-1]; // no operation needed
            else distance[i][j] = 1 + min(distance[i-1][j-1], distance[i][j-1], distance[i-1][j]); // choose the minimum of insert, delete, and substitute
        }
    }

    return distance[m][n];
}

int main() {

    char str1[100], str2[100];

    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);
    printf("The Levenshtein distance between %s and %s is %d", str1, str2, distance);

    return 0;
}