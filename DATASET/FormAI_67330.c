//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: sophisticated
#include <stdio.h>
#include <string.h>

// This function converts a single character to Morse code
void printMorse(char input) {
    char *MorseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
    };
    if (input == ' ') {
        printf(" ");
    }
    else {
        int index = input - 'a';
        printf("%s ", MorseCode[index]);
    }
}

int main() {
    char inputString[100];
    printf("Enter a string to convert to Morse code: ");
    fgets(inputString, 100, stdin);

    int length = strlen(inputString);

    printf("Morse Code:");

    // Loop through each character in the string
    for (int i = 0; i < length; i++) {
        tolower(inputString[i]); // convert to lowercase

        // Print the Morse code representation of the current character
        printMorse(inputString[i]);
    }

    // Print a newline character to improve output readability
    printf("\n");

    return 0;
}