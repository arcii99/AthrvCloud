//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

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

int levenshtein_distance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int distances[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        distances[i][0] = i;
    }
    
    for (int j = 0; j <= len2; j++) {
        distances[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            
            distances[i][j] = min(distances[i - 1][j] + 1, 
                                   distances[i][j - 1] + 1, 
                                   distances[i - 1][j - 1] + cost);
        }
    }

    return distances[len1][len2];
}

int main() {
    char* str1 = "kitten";
    char* str2 = "sitting";
    int distance = levenshtein_distance(str1, str2);

    printf("The Levenshtein Distance between '%s' and '%s' is %d.", str1, str2, distance);
    
    return 0;
}