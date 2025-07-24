//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encode(char c) {
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
        case '1': return ".----";
        case '2': return "..---";
        case '3': return "...--";
        case '4': return "....-";
        case '5': return ".....";
        case '6': return "-....";
        case '7': return "--...";
        case '8': return "---..";
        case '9': return "----.";
        case '0': return "-----";
        case ' ': return "/";
        default: return "";
    }
}

char* convert_to_morse(char* string) {
    int length = strlen(string);
    char* morse_string = (char*) malloc(sizeof(char) * length * 4);
    if (morse_string == NULL) {
        return NULL;
    }
    int ni = 0;
    for (int i = 0; i < length; i++) {
        char c = string[i];
        if (c >= 'A' && c <= 'Z') {
            c = tolower(c);
        }
        char* code = encode(c);
        if (code[0] != '\0') {
            if (ni > 0) {
                morse_string[ni] = ' ';
                ni++;
            }
            int ci = 0;
            while (code[ci] != '\0') {
                morse_string[ni] = code[ci];
                ci++;
                ni++;
            }
        }
    }
    return morse_string;
}

int main() {
    char* input_string = "Hello, World!";
    char* morse_string = convert_to_morse(input_string);
    printf("Input: %s\n", input_string);
    printf("Morse Code: %s\n", morse_string);
    free(morse_string);
    return 0;
}