//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_MORSE_LENGTH 6
#define MAX_OUTPUT_LENGTH (MAX_INPUT_LENGTH * MAX_MORSE_LENGTH)

char *convert_char_to_morse(char c);
void convert_text_to_morse(const char *input, char *output);

int main(void) {
    char input[MAX_INPUT_LENGTH];
    char morse[MAX_OUTPUT_LENGTH];
    
    printf("Enter text to convert to Morse code:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove trailing newline from fgets
    
    convert_text_to_morse(input, morse);
    printf("Morse Code: %s\n", morse);
    
    return 0;
}

char *convert_char_to_morse(char c) {
    switch (c) {
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
        default: return "";
    }
}

void convert_text_to_morse(const char *input, char *output) {
    for (int i = 0; i < strlen(input); i++) {
        char c = tolower(input[i]); // convert to lowercase
        
        char *morse = convert_char_to_morse(c);
        if (strlen(morse) > 0) {
            strcat(output, morse); // concatenate Morse code to output string
            strcat(output, " ");   // add space between letters
        } else {
            strcat(output, " "); // add space between words
        }
    }
}