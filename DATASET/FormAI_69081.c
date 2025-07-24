//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: standalone
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 100
#define MAX_MORSE_SIZE 500

char* charToMorse(char c);
void stringToMorse(char* input, char* output);

int main() {
    char input[MAX_INPUT_SIZE];
    char output[MAX_MORSE_SIZE];
    
    printf("Enter a phrase to convert to Morse code: ");
    fgets(input, MAX_INPUT_SIZE, stdin);  // read input from user
    
    // remove newline character from input
    if (strlen(input) > 0 && input[strlen(input)-1] == '\n') {
        input[strlen(input)-1] = '\0';
    }
    
    // convert input to Morse code
    stringToMorse(input, output);
    
    // print the output
    printf("Morse code: %s\n", output);
    
    return 0;
}

// function to convert a single char to Morse code
char* charToMorse(char c) {
    switch(c) {
        case 'A': return ".-";
        case 'B': return "-...";
        case 'C': return "-.-.";
        case 'D': return "-..";
        case 'E': return ".";
        case 'F': return "..-.";
        case 'G': return "--.";
        case 'H': return "....";
        case 'I': return "..";
        case 'J': return ".---";
        case 'K': return "-.-";
        case 'L': return ".-..";
        case 'M': return "--";
        case 'N': return "-.";
        case 'O': return "---";
        case 'P': return ".--.";
        case 'Q': return "--.-";
        case 'R': return ".-.";
        case 'S': return "...";
        case 'T': return "-";
        case 'U': return "..-";
        case 'V': return "...-";
        case 'W': return ".--";
        case 'X': return "-..-";
        case 'Y': return "-.--";
        case 'Z': return "--..";
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
        case ' ': return "/";    // use '/' as word separator
        
        // if character is not supported, return 'error' code
        default: return "###";
    }
}

// function to convert a string to Morse code
void stringToMorse(char* input, char* output) {
    // set output to empty string so that we can append to it
    output[0] = '\0';
    
    // iterate over each character in the input string
    for (int i = 0; i < strlen(input); i++) {
        char* morse = charToMorse(toupper(input[i]));  // convert to uppercase for simplicity
        
        // concatenate Morse code for the current character to the output string
        strcat(output, morse);
        strcat(output, " ");  // use space as character separator
    }
}