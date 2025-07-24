//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100 // maximum length of input string

// function to convert a character to Morse code
char* charToMorse(char c){

    char* morseCode = malloc(sizeof(char) * 6); // allocate memory for Morse code string

    // switch-case to assign Morse code for each character
    switch(c){
        case 'a':
        case 'A':
            strcpy(morseCode, ".-");
            break;
        case 'b':
        case 'B':
            strcpy(morseCode, "-...");
            break;
        case 'c':
        case 'C':
            strcpy(morseCode, "-.-.");
            break;
        case 'd':
        case 'D':
            strcpy(morseCode, "-..");
            break;
        case 'e':
        case 'E':
            strcpy(morseCode, ".");
            break;
        case 'f':
        case 'F':
            strcpy(morseCode, "..-.");
            break;
        case 'g':
        case 'G':
            strcpy(morseCode, "--.");
            break;
        case 'h':
        case 'H':
            strcpy(morseCode, "....");
            break;
        case 'i':
        case 'I':
            strcpy(morseCode, "..");
            break;
        case 'j':
        case 'J':
            strcpy(morseCode, ".---");
            break;
        case 'k':
        case 'K':
            strcpy(morseCode, "-.-");
            break;
        case 'l':
        case 'L':
            strcpy(morseCode, ".-..");
            break;
        case 'm':
        case 'M':
            strcpy(morseCode, "--");
            break;
        case 'n':
        case 'N':
            strcpy(morseCode, "-.");
            break;
        case 'o':
        case 'O':
            strcpy(morseCode, "---");
            break;
        case 'p':
        case 'P':
            strcpy(morseCode, ".--.");
            break;
        case 'q':
        case 'Q':
            strcpy(morseCode, "--.-");
            break;
        case 'r':
        case 'R':
            strcpy(morseCode, ".-.");
            break;
        case 's':
        case 'S':
            strcpy(morseCode, "...");
            break;
        case 't':
        case 'T':
            strcpy(morseCode, "-");
            break;
        case 'u':
        case 'U':
            strcpy(morseCode, "..-");
            break;
        case 'v':
        case 'V':
            strcpy(morseCode, "...-");
            break;
        case 'w':
        case 'W':
            strcpy(morseCode, ".--");
            break;
        case 'x':
        case 'X':
            strcpy(morseCode, "-..-");
            break;
        case 'y':
        case 'Y':
            strcpy(morseCode, "-.--");
            break;
        case 'z':
        case 'Z':
            strcpy(morseCode, "--..");
            break;
        case '0':
            strcpy(morseCode, "-----");
            break;
        case '1':
            strcpy(morseCode, ".----");
            break;
        case '2':
            strcpy(morseCode, "..---");
            break;
        case '3':
            strcpy(morseCode, "...--");
            break;
        case '4':
            strcpy(morseCode, "....-");
            break;
        case '5':
            strcpy(morseCode, ".....");
            break;
        case '6':
            strcpy(morseCode, "-....");
            break;
        case '7':
            strcpy(morseCode, "--...");
            break;
        case '8':
            strcpy(morseCode, "---..");
            break;
        case '9':
            strcpy(morseCode, "----.");
            break;
        case ' ':
            strcpy(morseCode, "/");
            break;
        default:
            strcpy(morseCode, ""); // return empty string for unknown character
            break;
    }

    return morseCode; // return Morse code of a character
}

// function to convert a string to Morse code
char* textToMorse(char* text){

    int length = strlen(text); // length of input string
    char* morseCode = malloc(sizeof(char) * MAX_LENGTH * 6); // allocate memory for Morse code string

    // loop through each character of input string and assign Morse code
    for(int i=0; i<length; i++){
        char c = text[i]; // current character
        char* charMorseCode = charToMorse(c); // Morse code of current character
        strcat(morseCode, charMorseCode); // append Morse code of current character to Morse code string
        strcat(morseCode, " "); // append space to separate Morse codes of different characters
    }

    return morseCode; // return Morse code of input string
}

int main(){

    char text[MAX_LENGTH]; // input string
    printf("Enter text to convert to Morse code: ");
    fgets(text, MAX_LENGTH, stdin); // read input string
    text[strcspn(text, "\n")] = 0; // remove trailing newline character

    char* morseCode = textToMorse(text); // convert input string to Morse code
    printf("Morse code: %s\n", morseCode); // print Morse code of input string

    free(morseCode); // free memory allocated to Morse code string

    return 0;
}