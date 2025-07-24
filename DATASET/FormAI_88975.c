//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

char morse_code[26][5] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A-I
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.","...", // J-S
    "-", "..-", "...-", ".--", "-..-", "-.--", "--.." // T-Z
};

void print_morse(char* message) {
    int length = strlen(message);
    char translated_message[MAX_LENGTH] = "";
    for(int i=0; i<length; i++) {
        if(message[i] == ' ') {
            strcat(translated_message, "   ");
        } else if(message[i] >= 'a' && message[i] <= 'z') {
            strcat(translated_message, morse_code[message[i] - 'a']);
            strcat(translated_message, " ");
        }
    }
    printf("%s", translated_message);
}

int main() {
    char message[MAX_LENGTH];
    printf("Enter a word or phrase in lowercase letters to translate to Morse code:\n");
    fgets(message, MAX_LENGTH, stdin);
    printf("\nMorse code translation: \n");
    print_morse(message);

    return 0;
}