//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: active
#include <stdio.h>
#include <string.h>

char* morseCode(char letter) {
    switch(letter) {
        case 'a': case 'A':
            return ".-";
        case 'b': case 'B':
            return "-...";
        case 'c': case 'C':
            return "-.-.";
        case 'd': case 'D':
            return "-..";
        case 'e': case 'E':
            return ".";
        case 'f': case 'F':
            return "..-.";
        case 'g': case 'G':
            return "--.";
        case 'h': case 'H':
            return "....";
        case 'i': case 'I':
            return "..";
        case 'j': case 'J':
            return ".---";
        case 'k': case 'K':
            return "-.-";
        case 'l': case 'L':
            return ".-..";
        case 'm': case 'M':
            return "--";
        case 'n': case 'N':
            return "-.";
        case 'o': case 'O':
            return "---";
        case 'p': case 'P':
            return ".--.";
        case 'q': case 'Q':
            return "--.-";
        case 'r': case 'R':
            return ".-.";
        case 's': case 'S':
            return "...";
        case 't': case 'T':
            return "-";
        case 'u': case 'U':
            return "..-";
        case 'v': case 'V':
            return "...-";
        case 'w': case 'W':
            return ".--";
        case 'x': case 'X':
            return "-..-";
        case 'y': case 'Y':
            return "-.--";
        case 'z': case 'Z':
            return "--..";
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
        case '0':
            return "-----";
        default:
            return "";
    }
}

void main() {
    char text[100];
    int i=0;
    printf("Please enter the text you want to convert to Morse code: ");
    fgets(text, 100, stdin); // Accept the user input

    printf("The Morse code conversion for the given text is:\n");
    while(text[i] != '\0') { // Iterate over each character in the input string
        printf("%s ", morseCode(text[i]));
        i++;
    }
}