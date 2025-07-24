//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: retro
#include <stdio.h>
#include <string.h>

void textToMorse(char text[1000]);

int main() {
    char text[1000];
    printf("Enter a text to convert to Morse code: ");
    fgets(text, 1000, stdin); // getting user input
    textToMorse(text); // convert to Morse code
    return 0;
}

void textToMorse(char text[1000]) {
    char *morseCode[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"}; // Morse code array
    int len = strlen(text);
    char morseString[1000] = "";
    for(int i = 0; i < len; i++) {
        if(text[i] == ' ') {
            strcat(morseString, "/"); // symbolizing space with slash
        }
        else if(text[i] >= 'A' && text[i] <= 'Z') {
            strcat(morseString, morseCode[text[i] - 'A']); // converting uppercase letters
        }
        else if(text[i] >= 'a' && text[i] <= 'z') {
            strcat(morseString, morseCode[text[i] - 'a']); // converting lowercase letters
        }
    }
    printf("Morse code: %s\n", morseString);
}