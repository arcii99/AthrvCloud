//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: brave
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    int min = a;
    if(b < min) {
        min = b;
    }
    if(c < min) {
        min = c;
    }
    return min;
}

int levenshtein_distance(char *s1, char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int matrix[len1+1][len2+1];

    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            if(i == 0) {
                matrix[i][j] = j;
            } else if(j == 0) {
                matrix[i][j] = i;
            } else if(s1[i-1] == s2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = 1 + min(matrix[i][j-1], matrix[i-1][j], matrix[i-1][j-1]);
            }
        }
    }
    return matrix[len1][len2];
}

int main() {
    char input1[100];
    char input2[100];

    printf("Enter first word: ");
    scanf("%s", input1);

    printf("Enter second word: ");
    scanf("%s", input2);

    int distance = levenshtein_distance(input1, input2);

    printf("The Levenshtein distance between %s and %s is %d", input1, input2, distance);
    return 0;
}