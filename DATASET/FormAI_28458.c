//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: thoughtful
#include <stdio.h>
#include <string.h>

// Define the length of the alphabet
#define ALPHABET_LENGTH 26

// Define the C Alien Language Alphabet
char c_alphabet[ALPHABET_LENGTH] = {'K', 'X', 'D', 'C', 'M', 'I', 'E', 'V', 'F', 'L', 'O', 'P', 'N', 'H', 'U', 'Y', 'A', 'Q', 'R', 'W', 'J', 'S', 'T', 'G', 'Z', 'B'};

/**
* This function takes a message in C Alien Language and translates it into English.
**/
void c_to_english(char message[]) {
    // Iterate through the message
    int i = 0;
    while (message[i] != '\0') {
        // Iterate through the C Alien Language Alphabet to find the corresponding English character
        int j;
        for (j = 0; j < ALPHABET_LENGTH; j++) {
            if (message[i] == c_alphabet[j]) {
                printf("%c", 'a' + j);
                break;
            }
        }
        i++;
    }
    printf("\n");
}

/**
* This function takes a message in English and translates it into C Alien Language.
**/
void english_to_c(char message[]) {
    // Iterate through the message
    int i = 0;
    while (message[i] != '\0') {
        // Iterate through the English alphabet to find the corresponding C Alien Language character
        int j;
        for (j = 0; j < ALPHABET_LENGTH; j++) {
            if (message[i] == 'a' + j) {
                printf("%c", c_alphabet[j]);
                break;
            }
        }
        i++;
    }
    printf("\n");
}

// Entry point of the program
int main(void) {
    // Prompt the user for the message they want to translate
    printf("Please enter a message in C Alien Language:\n");

    // Get user input
    char message[100];
    fgets(message, 100, stdin);

    // Remove the newline character from the input
    message[strcspn(message, "\n")] = 0;

    // Translate message to English
    printf("Translation to English:\n");
    c_to_english(message);

    // Reverse translation back to C Alien Language
    printf("Translation back to C Alien Language:\n");
    english_to_c(message);

    return 0;
}