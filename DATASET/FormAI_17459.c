//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: recursive
#include <stdio.h>
#include <string.h>

// Define the Morse code table
char *morse_table[] = {
    ".-",   "-...", "-.-.", "-..",
    ".",    "..-.", "--.",  "....",
    "..",   ".---", "-.-",  ".-..",
    "--",   "-.",   "---",  ".--.",
    "--.-", ".-.",  "...",  "-",
    "..-",  "...-", ".--",  "-..-",
    "-.--", "--.."
};

char *text_to_morse(char *text, char *morse) {
    // Make sure the input text is not empty
    if(*text == '\0') {
        return morse;
    }

    // Get the index of the current character
    int index = (*text >= 'a' && *text <= 'z') ? *text - 'a' : *text - 'A';

    // Check if the character is a space
    if(*text == ' ') {
        strcat(morse, "/");
    } else {
        strcat(morse, morse_table[index]);
    }

    // Recurse on the rest of the text
    return text_to_morse(text + 1, morse);
}

int main() {
    char text[100], morse[100] = "";

    // Read input text
    printf("Enter text to convert to Morse code:\n");
    fgets(text, 100, stdin);

    // Convert text to Morse code using recursion
    text_to_morse(text, morse);

    // Print Morse code
    printf("Output: %s\n", morse);

    return 0;
}