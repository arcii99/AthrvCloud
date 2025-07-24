//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else
        return c;
}

int calculateLevenshteinDistance(char* str1, char* str2) {
    int m = strlen(str1);
    int n = strlen(str2);
    int distanceArray[m+1][n+1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                distanceArray[i][j] = j;
            else if (j == 0)
                distanceArray[i][j] = i;
            else if (str1[i-1] == str2[j-1])
                distanceArray[i][j] = distanceArray[i-1][j-1];
            else
                distanceArray[i][j] = 1 + min(distanceArray[i-1][j], distanceArray[i][j-1], distanceArray[i-1][j-1]);
        }
    }
    return distanceArray[m][n];
}

int main() {
    char str1[30];
    char str2[30];
    printf("Welcome to the Shape Shifting Levenshtein Distance Calculator!\n");
    printf("Please enter the first string: ");
    fgets(str1, 30, stdin);
    printf("Great! Now enter the second string: ");
    fgets(str2, 30, stdin);
    int distance = calculateLevenshteinDistance(str1, str2);
    printf("The Levenshtein Distance between %s and %s is %d.\n", str1, str2, distance);
    printf("Shape shifting complete. Thanks for using our program!");
    return 0;
}