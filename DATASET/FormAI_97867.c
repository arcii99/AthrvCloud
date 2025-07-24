//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int min(int x, int y, int z) { //helper function to calculate minimum of three integers
    if (x <= y && x <= z) return x;
    if (y <= x && y <= z) return y;
    return z;
}

int levenshteinDistance(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int dist[len1+1][len2+1]; //2D Array to store distances between strings
    
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            
            if (i == 0) dist[i][j] = j; //when s1 is empty, we need to perform j additions to make it equal to s2
            else if (j == 0) dist[i][j] = i; //when s2 is empty, we need to perform i deletions to make it equal to s1
            
            else if (s1[i-1] == s2[j-1]) dist[i][j] = dist[i-1][j-1]; //when the last character of both strings is same, we don't need to perform any operation
            else dist[i][j] = 1 + min(dist[i][j-1], dist[i-1][j], dist[i-1][j-1]); //when the last character is different, we will add, delete and replace characters in s1 to make it equal to s2
        }
    }
    
    return dist[len1][len2]; //return the distance between the two strings
}

int main() {
    char s1[100], s2[100];
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);
    int distance = levenshteinDistance(s1, s2);
    printf("The Levenshtein distance between %s and %s is %d\n", s1, s2, distance);
    return 0;
}