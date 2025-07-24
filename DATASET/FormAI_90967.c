//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* convertToMorse(char c);

int main() {
    char input[100];
    printf("Please enter the text you want to convert to Morse code: ");
    fgets(input, sizeof(input), stdin); // get input from user
    
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        if (isspace(input[i])) { // if it's a space, print a new line
            printf("\n");
            continue; // skip to next iteration of loop
        }
        printf("%s ", convertToMorse(tolower(input[i]))); // print morse code equivalent
    }
    return 0;
}

char* convertToMorse(char c) {
    switch(c) {
        case 'a':
            return ".-";
        case 'b':
            return "-...";
        case 'c':
            return "-.-.";
        case 'd':
            return "-..";
        case 'e':
            return ".";
        case 'f':
            return "..-.";
        case 'g':
            return "--.";
        case 'h':
            return "....";
        case 'i':
            return "..";
        case 'j':
            return ".---";
        case 'k':
            return "-.-";
        case 'l':
            return ".-..";
        case 'm':
            return "--";
        case 'n':
            return "-.";
        case 'o':
            return "---";
        case 'p':
            return ".--.";
        case 'q':
            return "--.-";
        case 'r':
            return ".-.";
        case 's':
            return "...";
        case 't':
            return "-";
        case 'u':
            return "..-";
        case 'v':
            return "...-";
        case 'w':
            return ".--";
        case 'x':
            return "-..-";
        case 'y':
            return "-.--";
        case 'z':
            return "--..";
        default:
            return ""; // if character isn't in alphabet, return empty string
    }
}