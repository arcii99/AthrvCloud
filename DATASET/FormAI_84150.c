//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: decentralized
#include<stdio.h>
#include<string.h>

// Morse code lookup table
const char* morseTable[36] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---.."};

// Character to Morse code conversion function
char* charToMorse(char c) {
    char* morseCode;
    // Character is in uppercase
    if (c >= 'A' && c <= 'Z') {
        morseCode = morseTable[c-'A'];
    }
    // Character is in digits
    else if (c >= '0' && c <= '9') {
        morseCode = morseTable[c-'0'+26];
    }
    // Character is not in the lookup table
    else {
        morseCode = "";
    }
    return morseCode;
}

int main() {
    char inputString[100];
    printf("Enter a string to convert to Morse code:\n");
    fgets(inputString,100,stdin);

    // Remove newline character from the end of the input
    int len = strlen(inputString);
    if (inputString[len-1] == '\n') {
        inputString[len-1] = '\0';
    }

    // Convert each character to Morse code and print
    for (int i = 0; i < strlen(inputString); i++) {
        char* morseCode = charToMorse(inputString[i]);
        printf("%s ", morseCode);
    }
    printf("\n");
    return 0;
}