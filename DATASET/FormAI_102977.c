//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a character to morse code
char* toMorse(char c) {
    switch(c) {
        case 'a':
        case 'A': return ".-";
        case 'b':
        case 'B': return "-...";
        case 'c':
        case 'C': return "-.-.";
        case 'd':
        case 'D': return "-..";
        case 'e':
        case 'E': return ".";
        case 'f':
        case 'F': return "..-.";
        case 'g':
        case 'G': return "--.";
        case 'h':
        case 'H': return "....";
        case 'i':
        case 'I': return "..";
        case 'j':
        case 'J': return ".---";
        case 'k':
        case 'K': return "-.-";
        case 'l':
        case 'L': return ".-..";
        case 'm':
        case 'M': return "--";
        case 'n':
        case 'N': return "-.";
        case 'o':
        case 'O': return "---";
        case 'p':
        case 'P': return ".--.";
        case 'q':
        case 'Q': return "--.-";
        case 'r':
        case 'R': return ".-.";
        case 's':
        case 'S': return "...";
        case 't':
        case 'T': return "-";
        case 'u':
        case 'U': return "..-";
        case 'v':
        case 'V': return "...-";
        case 'w':
        case 'W': return ".--";
        case 'x':
        case 'X': return "-..-";
        case 'y':
        case 'Y': return "-.--";
        case 'z':
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
        default: return "";
    }
}

// Recursive function to convert a string to morse code
void recursiveToMorse(char* str, int index) {
    // Base case: If end of string is reached, return
    if (str[index] == '\0') {
        return;
    }
    
    // Recursive case: Get the morse code for the current character
    char* morse = toMorse(str[index]);
    printf("%s ", morse);
    free(morse);
    
    // Recursively call the function with the next character in the string
    recursiveToMorse(str, index + 1);
}

int main() {
    // Input string
    char str[100];
    printf("Enter a sentence to convert to Morse code: ");
    fgets(str, 100, stdin);
    
    // Convert the string to morse code
    printf("Morse code: ");
    recursiveToMorse(str, 0);
    printf("\n");
    
    return 0;
}