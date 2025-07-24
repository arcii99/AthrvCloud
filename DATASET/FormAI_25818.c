//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: lively
#include <stdio.h>
#include <string.h>

int levenshtein_distance(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int table[len1+1][len2+1];
    
    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            if(i == 0) {
                table[i][j] = j;
            } else if(j == 0) {
                table[i][j] = i;
            } else {
                int cost = 0;
                if(s1[i-1] != s2[j-1]) {
                    cost = 1;
                }
                int minimum = table[i-1][j] + 1;
                if(table[i][j-1] + 1 < minimum) {
                    minimum = table[i][j-1] + 1;
                }
                if(table[i-1][j-1] + cost < minimum) {
                    minimum = table[i-1][j-1] + cost;
                }
                table[i][j] = minimum;
            }
        }
    }

    return table[len1][len2];
}

int main() {
    char s1[100], s2[100];
    printf("Enter first string: ");
    fgets(s1, sizeof(s1), stdin);
    printf("Enter second string: ");
    fgets(s2, sizeof(s2), stdin);
    s1[strcspn(s1, "\n")] = 0;
    s2[strcspn(s2, "\n")] = 0;

    int distance = levenshtein_distance(s1, s2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", s1, s2, distance);

    return 0;
}