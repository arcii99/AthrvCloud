//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: funny
#include <stdio.h>
#include <string.h>

// Function to calculate the minimum of three integers
int min(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    } else if (b < c) {
        return b;
    } else {
        return c;
    }
}

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int distance[len1+1][len2+1];
    
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                distance[i][j] = j;
            } else if (j == 0) {
                distance[i][j] = i;
            } else if (s1[i-1] == s2[j-1]) {
                distance[i][j] = distance[i-1][j-1];
            } else {
                distance[i][j] = 1 + min(distance[i-1][j-1], distance[i-1][j], distance[i][j-1]);
            }
        }
    }

    return distance[len1][len2];
}

int main() {
    char* s1 = "Hello, World!";
    char* s2 = "Helo Wrodl!";

    printf("Calculating the Levenshtein distance between \"%s\" and \"%s\"...\n", s1, s2);
    int distance = levenshtein_distance(s1, s2);
    printf("The Levenshtein distance is %d.\n", distance);
    
    if (distance > 10) {
        printf("Wow! That's quite a Levenshtein distance!\n");
    } else if (distance > 5) {
        printf("Well, that's not too bad, but it's definitely not perfect.\n");
    } else {
        printf("Nice job! You nailed it!\n");
    }
    
    return 0;
}