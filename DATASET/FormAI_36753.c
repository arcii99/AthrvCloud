//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: accurate
#include <stdio.h>
#include <string.h>

char* morseCode(char c);

int main() {
    char text[100];
    printf("Enter text to convert to Morse code:\n");
    fgets(text, 100, stdin);

    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        char c = text[i];
        if (c == ' ' || c == '\n') {
            printf(" ");
        } else {
            printf("%s ", morseCode(c));
        }
    }

    return 0;
}

char* morseCode(char c) {
    switch (c) {
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
            printf("Invalid character: %c\n", c);
            return "";
    }
}