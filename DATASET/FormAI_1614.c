//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: genious
#include <stdio.h>
#include <string.h>

char* textToMorseCode(char c);

int main() {
    char text[100];
    printf("Enter text: ");
    fgets(text, 100, stdin);
    printf("\nMorse Code of Text:\n");

    for (int i = 0; i < strlen(text); i++) {
        printf("%s ", textToMorseCode(text[i]));
    }
    
    printf("\n");
    return 0;
}

char* textToMorseCode(char c) {
    switch (toupper(c)) {
        case 'A':
            return ".-";
        case 'B':
            return "-...";
        case 'C':
            return "-.-.";
        case 'D':
            return "-..";
        case 'E':
            return ".";
        case 'F':
            return "..-.";
        case 'G':
            return "--.";
        case 'H':
            return "....";
        case 'I':
            return "..";
        case 'J':
            return ".---";
        case 'K':
            return "-.-";
        case 'L':
            return ".-..";
        case 'M':
            return "--";
        case 'N':
            return "-.";
        case 'O':
            return "---";
        case 'P':
            return ".--.";
        case 'Q':
            return "--.-";
        case 'R':
            return ".-.";
        case 'S':
            return "...";
        case 'T':
            return "-";
        case 'U':
            return "..-";
        case 'V':
            return "...-";
        case 'W':
            return ".--";
        case 'X':
            return "-..-";
        case 'Y':
            return "-.--";
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
        case ' ':
            return "/";
        default:
            return "";
    }
}