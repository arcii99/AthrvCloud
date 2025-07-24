//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100 // Maximum length of the input string

char* convertToMorse(char c) {
    switch (c) {
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
        case '0':
            return "-----";
        case '1':
            return ".----";
        case '2':
            return "..---";
        case '3':
            return "...--";
        case '4':
            return "....-";
        case '5':
            return ".....";
        case '6':
            return "-....";
        case '7':
            return "--...";
        case '8':
            return "---..";
        case '9':
            return "----.";
        default:
            return ""; // return empty string if character is not supported
    }
}

int main() {
    char input[MAXLEN]; // input string
    char *morse[MAXLEN]; // output string in morse code
    int i, len;

    printf("Enter a string: ");
    fgets(input, MAXLEN, stdin);

    len = strlen(input) - 1; // eliminate newline character from input

    // Convert the input string to morse code
    for (i = 0; i < len; i++) {
        morse[i] = convertToMorse(input[i]);
    }

    // Print the output string in morse code
    printf("Morse code: ");
    for (i = 0; i < len; i++) {
        printf("%s ", morse[i]);
    }
    printf("\n");

    return 0;
}