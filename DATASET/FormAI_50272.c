//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 1000

/*
 * This program counts the frequency of words starting with the letter 'C' (both uppercase and lowercase)
 * in a given input string.
 */

// Function to check if a character is a delimiter
int isDelimiter(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v' || c == ',' || c == '.' || c == '?' || c == '!';
}

// Function to compare two characters, case-insensitively
int compare(char a, char b) {
    if (tolower(a) == tolower(b)) {
        return 1;
    }
    return 0;
}

// Function to count the frequency of words starting with 'C'
int countWordFrequency(char *str) {
    int frequency = 0;
    int i = 0;
    while (str[i] != '\0') {
        // Skip over any delimiters
        while (isDelimiter(str[i])) {
            i++;
        }

        // Check if the current word starts with 'C'
        if (compare(str[i], 'C')) {
            // Skip over the 'C'
            i++;

            // Check if the next character is a delimiter or the end of the string
            if (isDelimiter(str[i]) || str[i] == '\0') {
                frequency++;
            }
        }

        // Skip to the next word
        while (!isDelimiter(str[i]) && str[i] != '\0') {
            i++;
        }
    }
    return frequency;
}

int main() {
    char inputString[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(inputString, MAX_LENGTH, stdin);
    int frequency = countWordFrequency(inputString);
    printf("The frequency of words starting with 'C' in the input string is %d\n", frequency);
    return 0;
}