//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int smallest = a;
    if (b < smallest) {
        smallest = b;
    }
    if (c < smallest) {
        smallest = c;
    }
    return smallest;
}

int levenshtein_distance(char *string1, char *string2, int string1_length, int string2_length) {
    int distance_matrix[string1_length + 1][string2_length + 1];
    memset(distance_matrix, 0, sizeof(distance_matrix));
    
    for (int i = 1; i <= string1_length; i++) {
        distance_matrix[i][0] = i;
    }
    for (int j = 1; j <= string2_length; j++) {
        distance_matrix[0][j] = j;
    }
    
    for (int j = 1; j <= string2_length; j++) {
        for (int i = 1; i <= string1_length; i++) {
            if (string1[i - 1] == string2[j - 1]) {
                distance_matrix[i][j] = distance_matrix[i - 1][j - 1];
            }
            else {
                distance_matrix[i][j] = min(distance_matrix[i - 1][j], distance_matrix[i][j - 1], distance_matrix[i - 1][j - 1]) + 1;
            }
        }
    }
    
    return distance_matrix[string1_length][string2_length];
}

int main() {
    char string1[] = "chatbot";
    char string2[] = "chattybot";
    
    int distance = levenshtein_distance(string1, string2, strlen(string1), strlen(string2));
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", string1, string2, distance);
    
    return 0;
}