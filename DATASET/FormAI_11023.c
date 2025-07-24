//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: light-weight
#include <stdio.h>
#include <string.h>

// Define constants for the alphabet
#define ALPHABET_SIZE 26
#define STARTING_LETTER 'a'

// Define the alien language as a translation matrix
int alienLanguage[ALPHABET_SIZE][ALPHABET_SIZE] = {
    {9, 22, 18, 12, 20, 15, 25, 6, 23, 7, 16, 24, 21, 1, 19, 8, 4, 11, 2, 0, 5, 10, 3, 17, 13, 14},
    {7, 0, 9, 22, 14, 8, 2, 24, 3, 20, 13, 10, 15, 6, 16, 21, 23, 12, 18, 17, 19, 11, 1, 4, 25, 5},
    {5, 16, 20, 22, 15, 0, 6, 13, 12, 25, 3, 1, 21, 4, 18, 8, 9, 24, 2, 14, 17, 19, 7, 10, 23, 11},
    {0, 14, 21, 15, 17, 10, 9, 12, 18, 7, 3, 2, 19, 16, 23, 11, 4, 1, 20, 22, 25, 24, 5, 13, 8, 6},
    {20, 4, 23, 24, 21, 5, 3, 14, 7, 0, 1, 12, 11, 6, 19, 2, 17, 15, 16, 10, 18, 25, 9, 22, 13, 8},
    {11, 25, 13, 23, 12, 8, 20, 0, 22, 15, 18, 21, 7, 6, 5, 14, 2, 10, 1, 19, 4, 9, 3, 17, 16, 24},
    {24, 21, 0, 14, 22, 1, 20, 18, 23, 11, 9, 25, 2, 3, 15, 10, 16, 12, 4, 19, 6, 5, 8, 7, 13, 17},
    {17, 14, 23, 10, 18, 7, 15, 9, 12, 22, 20, 3, 2, 8, 5, 6, 11, 24, 1, 21, 25, 19, 16, 0, 4, 13},
    {10, 5, 3, 13, 18, 20, 19, 21, 2, 16, 24, 17, 12, 1, 0, 6, 14, 22, 7, 25, 9, 11, 8, 15, 23, 4},
    {1, 15, 7, 10, 16, 22, 24, 2, 23, 6, 13, 17, 19, 20, 18, 0, 8, 3, 4, 9, 5, 11, 21, 14, 25, 12},
    {13, 2, 11, 17, 24, 14, 25, 3, 1, 0, 7, 4, 9, 23, 16, 20, 22, 19, 5, 6, 21, 8, 12, 10, 18, 15},
    {4, 12, 1, 6, 9, 11, 15, 13, 24, 18, 17, 25, 3, 22, 21, 7, 19, 8, 0, 2, 14, 23, 16, 10, 5, 20},
    {8, 24, 2, 5, 6, 19, 11, 20, 1, 18, 10, 13, 15, 23, 14, 4, 9, 17, 25, 21, 7, 3, 16, 22, 0, 12},
    {16, 1, 20, 12, 13, 21, 5, 24, 3, 9, 15, 8, 18, 10, 2, 4, 7, 11, 14, 23, 22, 25, 17, 19, 0, 6},
    {25, 11, 22, 9, 19, 14, 10, 16, 20, 23, 2, 7, 0, 18, 3, 5, 8, 17, 4, 13, 1, 12, 6, 21, 24, 15},
    {18, 3, 4, 2, 11, 23, 17, 22, 25, 14, 21, 16, 10, 13, 12, 9, 15, 7, 24, 5, 0, 1, 19, 6, 8, 20},
    {22, 7, 24, 3, 5, 13, 12, 15, 8, 19, 6, 23, 17, 4, 21, 16, 20, 2, 18, 1, 11, 25, 0, 10, 14, 9},
    {14, 12, 5, 19, 3, 2, 23, 1, 4, 17, 8, 22, 24, 11, 7, 25, 13, 20, 0, 6, 9, 15, 10, 18, 21, 16},
    {6, 10, 10, 11, 1, 4, 14, 8, 21, 12, 5, 15, 22, 19, 24, 13, 25, 9, 18, 17, 20, 16, 7, 2, 0, 23},
    {19, 23, 25, 8, 25, 19, 21, 11, 13, 24, 18, 6, 8, 17, 14, 3, 1, 21, 10, 16, 22, 2, 0, 12, 9, 4},
    {2, 20, 19, 18, 23, 7, 18, 7, 6, 2, 12, 11, 5, 24, 8, 22, 3, 16, 15, 0, 23, 21, 4, 1, 14, 17},
    {12, 17, 16, 20, 10, 6, 4, 19, 14, 3, 22, 14, 23, 25, 9, 17, 15, 0, 24, 8, 2, 18, 11, 5, 7, 1},
    {21, 18, 12, 1, 7, 3, 16, 4, 15, 8, 25, 20, 13, 22, 10, 1, 24, 5, 14, 12, 0, 19, 23, 2, 6, 9},
    {15, 19, 14, 16, 2, 9, 8, 23, 10, 10, 4, 18, 20, 2, 22, 12, 1, 18, 23, 15, 24, 4, 3, 25, 21, 0}};

// Translate a given string from Alien language to English
void translateToEnglish(char* alienString) {
    int stringLength = strlen(alienString);
    int i, j;

    for(i = 0; i < stringLength; i++) {
        char letter = alienString[i];

        // Check if the letter is valid
        if(letter >= STARTING_LETTER && letter <= STARTING_LETTER + ALPHABET_SIZE - 1) {
            // Translate the letter to its English equivalent
            int letterIndex = letter - STARTING_LETTER;
            int englishIndex = 0;

            for(j = 0; j < ALPHABET_SIZE; j++) {
                if(alienLanguage[letterIndex][j] == i) {
                    englishIndex = j;
                    break;
                }
            }

            alienString[i] = englishIndex + STARTING_LETTER;
        }
    }
}

int main() {
    // Input an Alien language string
    char alienString[] = "grnxv";

    // Translate the string to English
    translateToEnglish(alienString);

    // Print the translated string
    printf("Translated string: %s", alienString);

    return 0;
}