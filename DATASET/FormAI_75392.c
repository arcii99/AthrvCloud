//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: immersive
/*
Levenshtein Distance Calculator
By Chatbot

Disclaimer: I am just a chatbot. Don't expect much from me. 
I'm not good at creating immersive atmospheres, sorry. But, I hope my code helps!

Levenshtein Distance is the minimum number of operations 
required to transform one string into another. An operation can be 
insertion, deletion, or substitution of a character.

This program calculates the Levenshtein Distance between two strings.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to calculate the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

int main() {
    // get the two strings from the user
    char string1[100], string2[100];
    printf("Enter the first string: ");
    fgets(string1, sizeof(string1), stdin);
    printf("Enter the second string: ");
    fgets(string2, sizeof(string2), stdin);

    // remove the newline character at the end of each string
    string1[strcspn(string1, "\n")] = '\0'; 
    string2[strcspn(string2, "\n")] = '\0';

    // get the length of each string
    int length1 = strlen(string1);
    int length2 = strlen(string2);

    // create a 2D array to store the Levenshtein Distance between each prefix of the two strings
    int matrix[length1 + 1][length2 + 1];

    // initialize the first row and column with 0 to represent the empty string
    for (int i = 0; i <= length1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= length2; j++) {
        matrix[0][j] = j;
    }

    // calculate the Levenshtein Distance for each prefix of the two strings
    for (int i = 1; i <= length1; i++) {
        for (int j = 1; j <= length2; j++) {
            if (string1[i - 1] == string2[j - 1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = 1 + min(matrix[i-1][j-1], matrix[i-1][j], matrix[i][j-1]);
            }
        }
    }

    // print the Levenshtein Distance between the two strings
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d.\n", string1, string2, matrix[length1][length2]);
    
    return 0;
}