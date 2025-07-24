//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: peaceful
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

int levenshtein_distance(char *string1, int string1_length, char *string2, int string2_length) {
    int matrix[string1_length + 1][string2_length + 1];
 
    for (int i = 0; i <= string1_length; i++) {
        matrix[i][0] = i;
    }
 
    for (int j = 0; j <= string2_length; j++) {
        matrix[0][j] = j;
    }
 
    for (int i = 1; i <= string1_length; i++) {
        for (int j = 1; j <= string2_length; j++) {
            int cost = (string1[i - 1] == string2[j - 1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost);
        }
    }
 
    return matrix[string1_length][string2_length];
}

int main() {
    char string1[100], string2[100];
    printf("Enter the first string: ");
    scanf("%s", string1);
    printf("Enter the second string: ");
    scanf("%s", string2);

    int distance = levenshtein_distance(string1, strlen(string1), string2, strlen(string2));
    printf("The Levenshtein Distance between '%s' and '%s' is %d\n", string1, string2, distance);

    return 0;
}