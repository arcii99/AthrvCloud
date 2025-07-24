//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert text into morse code
char * text_to_morse(char *text) {
    char *morse_codes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "|"};
    char *morse = malloc(sizeof(char) * 500);   // assuming maximum morse code length is 500
    morse[0] = '\0';   // set initial string to empty

    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            strcat(morse, morse_codes[c - 'a']);
        } else if (c >= 'A' && c <= 'Z') {
            strcat(morse, morse_codes[c - 'A']);
        } else if (c == ' ') {
            strcat(morse, morse_codes[26]);   // add space char to morse string
        }
        strcat(morse, " ");   // separate characters with a space
    }

    return morse;
}

int main() {
    char text[100];
    printf("Enter text to convert to Morse code: ");
    scanf("%[^\n]", text);   // read input text with spaces

    char *morse = text_to_morse(text);
    printf("Morse code: %s\n", morse);

    free(morse);   // free dynamically allocated memory
    return 0;
}