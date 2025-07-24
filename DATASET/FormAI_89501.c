//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: systematic
#include <stdio.h>
#include <string.h>

// Function to convert a single C alien character to English
char convertChar(char c) {
    switch(c) {
        case 'A':
            return 'z';
        case 'B':
            return 'x';
        case 'C':
            return 'c';
        case 'D':
            return 'v';
        case 'E':
            return 'b';
        case 'F':
            return 'n';
        case 'G':
            return 'm';
        case 'H':
            return 'a';
        case 'I':
            return 's';
        case 'J':
            return 'd';
        case 'K':
            return 'f';
        case 'L':
            return 'g';
        case 'M':
            return 'h';
    }
}

// Function to convert a C alien sentence to English
void convertSentence(char sentence[]) {
    int length = strlen(sentence);

    for (int i = 0; i < length; i++) {
        sentence[i] = convertChar(sentence[i]);
    }
}

// Main function to demonstrate the use of the C Alien Language Translator
int main() {
    char sentence[100];

    printf("Enter a sentence in C alien language: ");
    fgets(sentence, 100, stdin);

    // Remove the newline character from the end of the input
    sentence[strcspn(sentence, "\n")] = 0;

    convertSentence(sentence);

    printf("In English, the sentence is: %s\n", sentence);

    return 0;
}