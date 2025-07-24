//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype to convert text to morse code
void textToMorse(char *text);

// Function to convert English alphabet to Morse code
char *convertToMorse(char c);

// Morse code array for each English alphabet
char morse[26][6] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
                      "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
                      "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                      "-.--", "--.." };

// An array to store the converted Morse code
char morseCode[500];

int main() {
    char text[100];

    printf("Enter the text to convert to Morse code: ");
    fgets(text, 100, stdin);

    textToMorse(text);

    printf("The Morse code equivalent is: %s\n", morseCode);

    return 0;
}

void textToMorse(char *text) {
    int i = 0, j = 0;

    while (text[i] != '\0') {
        if (text[i] == ' ') {
            strcat(morseCode, "   ");
        } else {
            char *morseChar = convertToMorse(text[i]);

            while (*morseChar != '\0') {
                morseCode[j++] = *morseChar++;
            }
            strcat(morseCode, " ");
        }
        i++;
    }
}

char *convertToMorse(char c) {
    if (c >= 'a' && c <= 'z') {
        return morse[c - 'a'];
    }

    if (c >= 'A' && c <= 'Z') {
        char lower = tolower(c);
        return morse[lower - 'a'];
    }

    return "";
}