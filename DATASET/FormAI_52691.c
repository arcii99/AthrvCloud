//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: genious
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Morse code array for 0-9 digits, A-Z alphabets and some special characters
const char *morseCode[] = { "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/", ".-.-.-", "--..--", "..--..", "-.-.--", "-....-", "-.--.", "-.--.-"};

// function to convert text to Morse code
void convertToMorseCode(char *text) {
    int i, j;

    for(i = 0; i < strlen(text); i++) {
        // if character is lowercase, convert to uppercase
        if(islower(text[i])) {
            text[i] = toupper(text[i]);
        }
        // if character is a space, print a new line
        if(text[i] == ' ') {
            printf(" ");
        }
        else {
            // find index position of character in Morse code array
            for(j = 0; j < 36; j++) {
                if(text[i] == (char)(j+48) || text[i] == (char)(j+65) || text[i] == (char)(j+22)) {
                    printf("%s ", morseCode[j]);
                    break;
                }
            }
        }
    }
}

int main() {
    char text[100];

    printf("Enter text to convert to Morse code: ");
    fgets(text, 100, stdin);

    convertToMorseCode(text);

    return 0;
}