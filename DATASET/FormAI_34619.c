//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MORSE 100 // maximum size of Morse code message
#define MAX_TEXT 50 // maximum size of text message
#define DELAY 500 // delay between dots and dashes in milliseconds
#define DOT_LENGTH 1 // length of one Morse code dot
#define DASH_LENGTH 3 // length of one Morse code dash

char *morse[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", 
                   "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
                   "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", 
                   "----.", "-----"}; // Morse code representation of letters and numbers

void textToMorse(char *text, char *morseCode) {
    int i, j;
    char c;
    for (i = 0; i < strlen(text); i++) {
        c = toupper(text[i]);
        if (c >= 'A' && c <= 'Z') { // translate letter to Morse code
            strcat(morseCode, morse[c - 'A']);
            strcat(morseCode, " ");
        } else if (c >= '0' && c <= '9') { // translate number to Morse code
            strcat(morseCode, morse[c - '0' + 26]);
            strcat(morseCode, " ");
        } else if (c == ' ') { // add space between words
            strcat(morseCode, " ");
        }
    }
}

void playMorseCode(char *morseCode) {
    int i, j, len = strlen(morseCode);
    for (i = 0; i < len; i++) {
        if (morseCode[i] == '.') {
            printf("."); // print dot
            usleep(DOT_LENGTH * DELAY);
        } else if (morseCode[i] == '-') {
            printf("-"); // print dash
            usleep(DASH_LENGTH * DELAY);
        } else if (morseCode[i] == ' ') {
            printf(" "); // print space between words
            usleep(3 * DELAY);
        }
    }
}

int main() {
    char text[MAX_TEXT];
    char morseCode[MAX_MORSE] = "";
    
    printf("Enter text: ");
    fgets(text, MAX_TEXT, stdin);
    text[strcspn(text, "\n")] = 0; // replace newline character with null terminator
    
    textToMorse(text, morseCode);
    
    printf("Morse code: %s\n", morseCode);
    
    printf("Playing Morse code...\n");
    playMorseCode(morseCode);
    
    return 0;
}