//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Define the Morse code representation of all English letters and digits */
const char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..",
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...",
    "---..", "----."
};

/**
 * Convert an ASCII character to Morse code representation.
 * @param ch the ASCII character to convert
 * @param morse the string buffer to store the Morse code 
 * @param size the maximum size of the string buffer
 * @return the length of the Morse code representation or -1 if the character is invalid
 */
int ascii_to_morse(char ch, char *morse, int size) {
    if (isalpha(ch)) {
        /* Convert upper case letters to their Morse code representation */
        *morse = morse_code[toupper(ch) - 'A'][0];
        return snprintf(morse + 1, size - 1, "%s", morse_code[toupper(ch) - 'A'] + 1) + 1;
    } else if (isdigit(ch)) {
        /* Convert digits to their Morse code representation */
        return snprintf(morse, size, "%s", morse_code[ch - '0']) + 1;
    } else if (ch == ' ') {
        /* Space is represented as / in Morse code */
        return snprintf(morse, size, "/") + 1;
    } else {
        /* Invalid character */
        return -1;
    }
}

/**
 * Convert a text string to Morse code representation.
 * @param text the text string to convert
 * @param morse the string buffer to store the Morse code 
 * @param size the maximum size of the string buffer
 * @return the length of the Morse code representation
 */
int text_to_morse(const char *text, char *morse, int size) {
    int len = 0;
    for (size_t i = 0; i < strlen(text); i++) {
        int code_len = ascii_to_morse(text[i], morse + len, size - len);
        if (code_len < 0) {
            /* Error occurred, abort conversion */
            return -1;
        }
        len += code_len;
    }
    /* Add null terminator to the Morse code string */
    morse[len] = '\0';
    return len;
}

/* A sample main function that prompts the user for input */
int main(void) {
    char text[256], morse[512];
    printf("Enter text to convert to Morse code: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\r\n")] = '\0'; /* Remove newline at end of input */
    int len = text_to_morse(text, morse, sizeof(morse));
    if (len < 0) {
        printf("Invalid character detected, conversion failed.\n");
        return 1;
    }
    printf("Morse code: %s\n", morse);
    return 0;
}