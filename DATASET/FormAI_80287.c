//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int temp = (a < b) ? a : b;
    return (temp < c) ? temp : c;
}

int levenshtein_distance(char* s1, char* s2, int len1, int len2) {
    int distances[len1+1][len2+1];
    int i, j;
    
    for (i = 0; i <= len1; i++) {
        distances[i][0] = i;
    }
    
    for (j = 0; j <= len2; j++) {
        distances[0][j] = j;
    }
    
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            int cost = (s1[i-1] == s2[j-1]) ? 0 : 1;
            distances[i][j] = min(distances[i-1][j] + 1, // Deletion
                                   distances[i][j-1] + 1, // Insertion
                                   distances[i-1][j-1] + cost); // Substitute
        }
    }
    return distances[len1][len2];
}

int main() {
    char str1[50], str2[50];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    
    int distance = levenshtein_distance(str1, str2, strlen(str1), strlen(str2));
    printf("Levenshtein distance between %s and %s is %d", str1, str2, distance);
    return 0;
}