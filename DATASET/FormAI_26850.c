//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: automated
#include <stdio.h>
#include <string.h>

void convertToMorse(const char *text);

int main() {
    char text[100];

    printf("Enter text to convert to Morse code: ");
    fgets(text, 100, stdin);

    //remove newline character
    text[strcspn(text, "\n")] = 0;

    printf("Morse code output:\n");
    convertToMorse(text);

    return 0;
}

void convertToMorse(const char *text) {
    const char* morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                            ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", 
                            ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    //loop through input text
    for(int i = 0; i < strlen(text); i++) {
        char c = text[i];
        if(c == ' ') printf(" ");
        else if(c >= 'a' && c <= 'z') printf("%s ", morse[c-'a']);
        else if(c >= 'A' && c <= 'Z') printf("%s ", morse[c-'A']);
    }
}