//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: visionary
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum size of input string

// function to convert English character to Morse Code
char* englishToMorse(char c) {
    switch(c) {
        case 'a': return ".-";
        case 'b': return "-...";
        case 'c': return "-.-.";
        case 'd': return "-..";
        case 'e': return ".";
        case 'f': return "..-.";
        case 'g': return "--.";
        case 'h': return "....";
        case 'i': return "..";
        case 'j': return ".---";
        case 'k': return "-.-";
        case 'l': return ".-..";
        case 'm': return "--";
        case 'n': return "-.";
        case 'o': return "---";
        case 'p': return ".--.";
        case 'q': return "--.-";
        case 'r': return ".-.";
        case 's': return "...";
        case 't': return "-";
        case 'u': return "..-";
        case 'v': return "...-";
        case 'w': return ".--";
        case 'x': return "-..-";
        case 'y': return "-.--";
        case 'z': return "--..";
        case '0': return "-----";
        case '1': return ".----";
        case '2': return "..---";
        case '3': return "...--";
        case '4': return "....-";
        case '5': return ".....";
        case '6': return "-....";
        case '7': return "--...";
        case '8': return "---..";
        case '9': return "----.";
        default: return ""; // return empty string if character not found in Morse Code table
    }
}

// function to convert English string to Morse Code string
void englishToMorseString(char* english, char* morse) {
    int i;
    for(i = 0; i < strlen(english); i++) {
        char* morseChar = englishToMorse(english[i]); // get Morse Code for each character
        strcat(morse, morseChar); // concatenate Morse Code for each character to form Morse Code string
        strcat(morse, " "); // add space between each Morse Code character
    }
}

int main() {
    char english[MAX_SIZE], morse[MAX_SIZE * 5]; // max length of Morse Code string is 5 times max length of English string

    printf("Enter an English string: ");
    scanf("%[^\n]s", english); // read input string with spaces

    englishToMorseString(english, morse);

    printf("Morse Code: %s", morse);

    return 0;
}