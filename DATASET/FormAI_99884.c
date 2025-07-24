//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Morse code table
const char * morse_table[] = {
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--.." // Z
};

int main() {
    char text[256];
    char morse[512] = "";
    int morse_len = 0;

    printf("Enter the text to convert to Morse code:\n");
    fgets(text, 256, stdin);

    // Convert text to upper case
    for (int i = 0; i < strlen(text); i++) {
        text[i] = toupper(text[i]);
    }

    // Convert each character to Morse code and append to result string
    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (isalpha(c)) { // Convert alphabet characters
            int index = c - 'A';
            strcat(morse, morse_table[index]);
        } else if (isdigit(c)) { // Convert numeric characters
            char c2[2] = {c, '\0'};
            strcat(morse, c2);
        } else if (c == ' ') { // Add space between words
            strcat(morse, " ");
        }
        strcat(morse, " "); // Add space between Morse code characters
        morse_len = strlen(morse);
    }

    printf("Morse code: %s\n", morse);

    return 0;
}