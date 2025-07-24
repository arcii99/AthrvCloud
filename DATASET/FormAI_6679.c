//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Declaration of the Levenshtein Distance function */
int levenshtein_distance(char* s1, char* s2);


int main() {
    char* word1 = "chatbot"; // Define first word
    char* word2 = "chatterbox"; // Define second word

    /* Call the Levenshtein Distance function */
    int distance = levenshtein_distance(word1, word2);

    printf("The Levenshtein Distance between '%s' and '%s' is %d\n", word1, word2, distance);

    return 0;
}


int levenshtein_distance(char* s1, char* s2) {
    int s1_length = strlen(s1);
    int s2_length = strlen(s2);

    /* If one of the strings is empty, return the length of the other string */
    if (s1_length == 0) {
        return s2_length;
    }

    if (s2_length == 0) {
        return s1_length;
    }

    /* A two-dimensional array to store the distance values */
    int distance[s1_length+1][s2_length+1];
    int i, j, sub_cost;

    /* Initialize the values in the first row and column */
    for (i = 0; i <= s1_length; i++) {
        distance[i][0] = i;
    }

    for (j = 0; j <= s2_length; j++) {
        distance[0][j] = j;
    }

    /* Calculate the Levenshtein Distance */
    for (i = 1; i <= s1_length; i++) {
        for (j = 1; j <= s2_length; j++) {
            /* Get the substitution cost */
            if (s1[i-1] == s2[j-1]) {
                sub_cost = 0;
            } else {
                sub_cost = 1;
            }

            /* Calculate the distance value */
            distance[i][j] = fmin(fmin(distance[i-1][j] + 1,
                                        distance[i][j-1] + 1),
                                   distance[i-1][j-1] + sub_cost);
        }
    }

    /* Return the distance value */
    return distance[s1_length][s2_length];
}