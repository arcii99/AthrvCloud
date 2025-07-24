//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

char morseCodeTable[36][6] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
    ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

char* textToMorseCode(char *text) {
    int textLength = strlen(text);
    char* morseCode = (char*) malloc(MAX_LENGTH*sizeof(char));
    int codeLength = 0;

    for (int i = 0; i < textLength; i++) {
        if (isspace(text[i])) {
            strcat(morseCode, "/");
            codeLength++;
            continue;
        } else if (isalnum(text[i])) {
            int index;
            if (isalpha(text[i])) index = tolower(text[i]) - 97;
            else index = 26 + text[i] - 48;

            strcat(morseCode, morseCodeTable[index]);
            codeLength += strlen(morseCodeTable[index]);
            strcat(morseCode, " ");
            codeLength++;
        }
    }
    return morseCode;
}

int main() {
    char text[MAX_LENGTH];
    char* morseCode;

    printf("Enter the text you want to convert to Morse Code:\n");
    fgets(text, MAX_LENGTH, stdin);
    if (text[strlen(text)-1] == '\n') text[strlen(text)-1] = '\0';

    morseCode = textToMorseCode(text);
    printf("\nText: %s\nMorse Code: %s", text, morseCode);

    free(morseCode);
    return 0;
}