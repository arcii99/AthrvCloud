//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToMorseCode(char* message) {
    // Morse Code dictionary
    char *morseCodes[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/", " " };
    char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ/";
    
    char* morseMessage = malloc(sizeof(char)*100);
    strcpy(morseMessage, "");
    
    // Loop through each character of the message
    for (int i = 0; i < strlen(message); i++) {
        // Loop through the Morse Code dictionary to find the corresponding code
        for (int j = 0; j < 27; j++) {
            if (toupper(message[i]) == alpha[j])
                strcat(morseMessage, morseCodes[j]);
        }
        if (message[i] == ' ')
            strcat(morseMessage, " ");
    }
    printf("Morse Code: %s\n", morseMessage);
}

int main() {
    char* message = "HELLO WORLD";
    convertToMorseCode(message);
    return 0;
}