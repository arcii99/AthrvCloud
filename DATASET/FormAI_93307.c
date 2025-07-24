//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main() {
    // Morse code characters and their respective symbols
    char *morseChars[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
                          "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
                          "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                          "-.--", "--..", "/", " "};

    char *morseSymbols[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K",
                            "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V",
                            "W", "X", "Y", "Z", "/", " "};

    char c, message[500] = {0}, morse[1000] = {0};
    int i, j, messageLength;

    // Get input message from user
    printf("Enter a message to convert to Morse code: ");
    fgets(message, sizeof(message), stdin);

    messageLength = strlen(message);

    // Remove newline character from message
    if (message[messageLength - 1] == '\n')
        message[messageLength - 1] = '\0';

    // Convert each character to its Morse code equivalent
    for (i = 0; i < messageLength; i++) {
        // Ensure uppercase letter
        c = toupper(message[i]);

        // Find the Morse code symbol for the given character
        for (j = 0; j < 28; j++) {
            if (strcmp(morseSymbols[j], &c) == 0) {
                strcat(morse, morseChars[j]);
                strcat(morse, " ");
                break;
            }
        }
    }

    // Print the resulting Morse code message
    printf("Morse Code: %s\n", morse);

    return 0;
}