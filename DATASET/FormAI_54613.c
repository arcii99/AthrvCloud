//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Morse code translation table
char *MORSE_TABLE[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", 
                        "--.", "....", "..", ".---", "-.-", ".-..", 
                        "--", "-.", "---", ".--.", "--.-", ".-.", 
                        "...", "-", "..-", "...-", ".--", "-..-", 
                        "-.--", "--.." };

// Function to convert a character to Morse code
void charToMorse(char c) {
    if (isalpha(c)) {  // If character is an alphabet
        char ch = toupper(c);
        printf("%s ", MORSE_TABLE[ch - 'A']);
    }
    else if (isdigit(c)) {  // If character is a digit
        printf("%s ", MORSE_TABLE[c - '0' + 25]);
    }
    else if (c == ' ') {  // If character is a space character
        printf(" ");
    }
    else {  // If character is not recognized
        printf("?? ");
    }
}

int main() {
    char text[100];

    printf("Enter text to convert to Morse code: ");
    fgets(text, 100, stdin);  // Read input from user

    printf("Morse code: ");
    for (int i = 0; i < strlen(text); i++) {
        charToMorse(text[i]);
    }

    return 0;
}