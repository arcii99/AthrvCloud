//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_MSG_LEN 1000 //Max length of input message
#define MAX_MORSE_LEN 10000 //Max length of Morse code output

//Function to convert the given character to its respective Morse code symbol
char* charToMorse(char c) {
    switch(c) {
        case 'a':
        case 'A':
            return ".-";
        case 'b':
        case 'B':
            return "-...";
        case 'c':
        case 'C':
            return "-.-.";
        case 'd':
        case 'D':
            return "-..";
        case 'e':
        case 'E':
            return ".";
        case 'f':
        case 'F':
            return "..-.";
        case 'g':
        case 'G':
            return "--.";
        case 'h':
        case 'H':
            return "....";
        case 'i':
        case 'I':
            return "..";
        case 'j':
        case 'J':
            return ".---";
        case 'k':
        case 'K':
            return "-.-";
        case 'l':
        case 'L':
            return ".-..";
        case 'm':
        case 'M':
            return "--";
        case 'n':
        case 'N':
            return "-.";
        case 'o':
        case 'O':
            return "---";
        case 'p':
        case 'P':
            return ".--.";
        case 'q':
        case 'Q':
            return "--.-";
        case 'r':
        case 'R':
            return ".-.";
        case 's':
        case 'S':
            return "...";
        case 't':
        case 'T':
            return "-";
        case 'u':
        case 'U':
            return "..-";
        case 'v':
        case 'V':
            return "...-";
        case 'w':
        case 'W':
            return ".--";
        case 'x':
        case 'X':
            return "-..-";
        case 'y':
        case 'Y':
            return "-.--";
        case 'z':
        case 'Z':
            return "--..";
        case ' ':
            return "/";
        default:
            return ""; //Return empty string for unsupported characters
    }
}

int main() {
    char msg[MAX_MSG_LEN];
    char morse[MAX_MORSE_LEN];

    printf("Enter a message to convert to Morse code:\n");
    fgets(msg, MAX_MSG_LEN, stdin);

    //Converting each character of the message to Morse code and storing in morse array
    int i, j, len, morseIndex = 0;
    len = strlen(msg) - 1; //Removing the newline character added by fgets()
    for(i=0; i<len; i++) {
        char *morseSymbol = charToMorse(msg[i]); //Get Morse code symbol for character
        int symbolLen = strlen(morseSymbol);
        for(j=0; j<symbolLen; j++) {
            morse[morseIndex] = morseSymbol[j];
            morseIndex++;
        }
        if(morseSymbol[0] != '/') { //Add space between symbols only if the current symbol is not '/'
            morse[morseIndex] = ' ';
            morseIndex++;
        }
    }
    //Adding null character to the end of the Morse code array
    morse[morseIndex] = '\0';

    printf("\nMorse code:\n%s\n", morse);

    return 0;
}