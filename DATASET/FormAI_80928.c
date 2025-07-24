//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: real-life
#include <stdio.h>
#include <string.h>

char* textToMorse(char c) {
    // Convert a single character to its Morse code equivalent
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
        default: return "";
    }
}

char* textToMorsePhrase(char* str) {
    // Convert a string phrase to its Morse code equivalent
    char *morse = malloc(sizeof(char) * strlen(str) * 8); // Allocate enough space for all morse code characters
    int i;
    for(i = 0; i < strlen(str); i++) {
        char* code = textToMorse(str[i]);
        strcat(morse, code);
        if(i+1 < strlen(str) && str[i+1] != ' ') {
            strcat(morse, " ");
        }
    }
    return morse;
}

int main() {
    printf("Enter a phrase to convert to Morse code: ");
    char phrase[100];
    scanf("%[^\n]", phrase);
    getchar(); // Clear buffer

    char* morse = textToMorsePhrase(phrase);
    printf("\nMorse Code:\n%s", morse);

    free(morse); // Free allocated memory
    return 0;
}