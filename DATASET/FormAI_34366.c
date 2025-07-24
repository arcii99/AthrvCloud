//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: safe
#include <stdio.h>
#include <string.h>

#define ASCII_WIDTH 128  // width of ASCII table
#define MAX_TEXT_LENGTH 1000  // maximum length of input text

void displayAsciiArt(char *text) {
    int textLength = strlen(text);
    char asciiArt[MAX_TEXT_LENGTH][ASCII_WIDTH];  // initialize 2D array for ASCII art

    // loop through each character in the input text
    for (int i = 0; i < textLength; i++) {
        char c = text[i];

        // loop through each ASCII character and set corresponding pattern in ASCII art
        for (int j = 0; j < ASCII_WIDTH; j++) {
            if (c == j) {
                // set pattern for specific ASCII character
                if (j == 'A') {
                    strcpy(asciiArt[i], "    /\\    \n   /  \\   \n  /----\\  \n /      \\ \n/        \\\n");
                } else if (j == 'B') {
                    strcpy(asciiArt[i], "-------  \n|      \\ \n|      | \n|      / \n-------  \n");
                } else if (j == 'C') {
                    strcpy(asciiArt[i], "  ------ \n /       \n|        \n|        \n \\------ \n");
                }
                // continue adding patterns for other characters...
            }
        }
    }

    // display ASCII art
    for (int i = 0; i < MAX_TEXT_LENGTH; i++) {
        if (strlen(asciiArt[i]) == 0) {
            break;
        }
        printf("%s", asciiArt[i]);
    }

}

int main() {
    char inputText[MAX_TEXT_LENGTH];

    printf("Enter some text: ");
    fgets(inputText, MAX_TEXT_LENGTH, stdin);
    displayAsciiArt(inputText);

    return 0;
}