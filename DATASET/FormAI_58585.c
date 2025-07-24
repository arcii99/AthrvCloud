//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

// Define the alien language alphabet
char ALPHABET[] = {'z', 'q', 'm', 'f', 'r', 'o', 'b', 'p', 'e', 'k'};
int ALPHABET_SIZE = sizeof(ALPHABET)/sizeof(char);

// Translate a single character from alien language to English
char translate(char c) {
    for(int i=0; i<ALPHABET_SIZE; i++) {
        if(c == ALPHABET[i]) {
            // Return the corresponding English letter
            return (char)('a' + i);
        }
    }
    // If there is no match, return the original character
    return c;
}

// Translate an entire string from alien language to English
void translateString(char* str) {
    int length = strlen(str);
    for(int i=0; i<length; i++) {
        str[i] = translate(str[i]);
    }
}

int main() {
    // Prompt the user to enter an alien language string
    printf("Enter an alien language string: ");
    char input[100];
    fgets(input, 100, stdin);

    // Translate the string and print the result
    printf("\nTranslated: ");
    translateString(input);
    printf("%s", input);

    return 0;
}