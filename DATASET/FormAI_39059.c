//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: relaxed
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

char* morse_code(char c);

int main() {
    char input[MAX_LENGTH];
    printf("Enter the text you want to convert to Morse code: ");
    fgets(input, MAX_LENGTH, stdin);

    printf("Your text in Morse code:\n");
    for (int i = 0; i < strlen(input); i++) {
        char current = input[i];
        if (current == ' ') {
            printf(" / ");
            continue;
        }
        printf("%s ", morse_code(current));
    }

    return 0;
}

char* morse_code(char c) {
    switch (c) {
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
        default: return "";
    }
}