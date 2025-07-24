//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

char* text_to_morse_code(char letter) {
    switch(letter) {
        case 'a':
        case 'A':
            return ".-";
        case 'b':
        case 'B':
            return "-...";
        case 'c':
        case 'C':
            return "-.-.";
        case 'd':
        case 'D':
            return "-..";
        case 'e':
        case 'E':
            return ".";
        case 'f':
        case 'F':
            return "..-.";
        case 'g':
        case 'G':
            return "--.";
        case 'h':
        case 'H':
            return "....";
        case 'i':
        case 'I':
            return "..";
        case 'j':
        case 'J':
            return ".---";
        case 'k':
        case 'K':
            return "-.-";
        case 'l':
        case 'L':
            return ".-..";
        case 'm':
        case 'M':
            return "--";
        case 'n':
        case 'N':
            return "-.";
        case 'o':
        case 'O':
            return "---";
        case 'p':
        case 'P':
            return ".--.";
        case 'q':
        case 'Q':
            return "--.-";
        case 'r':
        case 'R':
            return ".-.";
        case 's':
        case 'S':
            return "...";
        case 't':
        case 'T':
            return "-";
        case 'u':
        case 'U':
            return "..-";
        case 'v':
        case 'V':
            return "...-";
        case 'w':
        case 'W':
            return ".--";
        case 'x':
        case 'X':
            return "-..-";
        case 'y':
        case 'Y':
            return "-.--";
        case 'z':
        case 'Z':
            return "--..";
        case ' ':
            return " ";
        default:
            return "*";
    }
}

void convert_to_morse_code(char text[], char morse_code[]) {
    int i, j;
    char* code;
    for (i = 0, j = 0; i < strlen(text); i++) {
        code = text_to_morse_code(text[i]);
        if (*code == '*') {
            morse_code[0] = '\0';
            return;
        }
        strcat(morse_code, code);
        if (text[i] != ' ') {
            strcat(morse_code, " ");
        }
    }
}

int main() {
    char text[100], morse_code[100] = "";
    printf("Enter the text to convert to Morse code: ");
    fgets(text, 100, stdin);
    printf("Converting \"%s\" to Morse code...\n", text);
    convert_to_morse_code(text, morse_code);
    if (strlen(morse_code) == 0) {
        printf("Error: Invalid character detected.\n");
    } else {
        printf("Morse code: %s\n", morse_code);
    }
    return 0;
}