//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: dynamic
#include <stdio.h>
#include <string.h>

// Morse code lookup table
char *morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
                     "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
                     ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

// Function to convert a single character to morse code
void charToMorse(char ch) {
    if (ch == ' ') {
        printf(" / ");
    } else if (ch >= 'a' && ch <= 'z') {
        printf("%s ", morseCode[ch - 'a']);
    } else if (ch >= 'A' && ch <= 'Z') {
        printf("%s ", morseCode[ch - 'A']);
    } else if (ch >= '0' && ch <= '9') {
        printf("%s ", morseCode[ch - '0' + 24]);
    }
}

// Function to convert a string to morse code
void stringToMorse(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        charToMorse(str[i]);
    }
}

int main(void) {
    char str[100];
    printf("Enter a string to convert to morse code: ");
    fgets(str, sizeof(str), stdin);

    printf("Morse code: ");
    stringToMorse(str);

    return 0;
}