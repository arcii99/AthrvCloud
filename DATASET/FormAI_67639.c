//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char morseArray[26][6] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", 
    ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", 
    ".--", "-..-", "-.--", "--.."
};

void textToMorse(char* text, char* morse) {
    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            strcat(morse, morseArray[c - 'a']);
        }
        else if (c >= 'A' && c <= 'Z') {
            strcat(morse, morseArray[c - 'A']);
        }
        else if (c == ' ') {
            strcat(morse, "/");
        }
        strcat(morse, " ");
    }
}

int main() {
    char text[100];
    printf("Enter the text to be converted to Morse code: ");
    fgets(text, 100, stdin);
    text[strcspn(text, "\n")] = 0; // remove newline character from input
    
    char morse[500] = "";
    textToMorse(text, morse);
    printf("Morse code: %s\n", morse);
    
    return 0;
}