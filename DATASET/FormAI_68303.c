//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: intelligent
#include <stdio.h>
#include <string.h>

char* convertToMorse(char character) {
    switch(character) {
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
        default: return " ";
    }
}

int main() {
    // Ask user for input string
    char input[100];
    printf("Enter a string:\n");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character from input

    // Convert input string to Morse code
    char output[1000] = "";
    for (int i = 0; i < strlen(input); i++) {
        char* morse = convertToMorse(input[i]);
        strcat(output, morse);
        strcat(output, " "); // Add space between characters
    }

    // Print output Morse code string
    printf("Morse code:\n%s\n", output);

    return 0;
}