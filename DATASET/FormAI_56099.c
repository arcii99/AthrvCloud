//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: sophisticated
#include<stdio.h>
#include<string.h>

char* toMorseCode(char c);
void printMorseCode(char *str);

int main() {

    char input[100];

    printf("Enter text to convert to Morse code: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0; //removes newline character from fgets input

    printMorseCode(input);

    return 0;
}

char* toMorseCode(char c) {
    char* morseCode;

    switch(c) {
        case 'a':
        case 'A':
            morseCode = ".-";
            break;
        case 'b':
        case 'B':
            morseCode = "-...";
            break;
        case 'c':
        case 'C':
            morseCode = "-.-.";
            break;
        case 'd':
        case 'D':
            morseCode = "-..";
            break;
        case 'e':
        case 'E':
            morseCode = ".";
            break;
        case 'f':
        case 'F':
            morseCode = "..-.";
            break;
        case 'g':
        case 'G':
            morseCode = "--.";
            break;
        case 'h':
        case 'H':
            morseCode = "....";
            break;
        case 'i':
        case 'I':
            morseCode = "..";
            break;
        case 'j':
        case 'J':
            morseCode = ".---";
            break;
        case 'k':
        case 'K':
            morseCode = "-.-";
            break;
        case 'l':
        case 'L':
            morseCode = ".-..";
            break;
        case 'm':
        case 'M':
            morseCode = "--";
            break;
        case 'n':
        case 'N':
            morseCode = "-.";
            break;
        case 'o':
        case 'O':
            morseCode = "---";
            break;
        case 'p':
        case 'P':
            morseCode = ".--.";
            break;
        case 'q':
        case 'Q':
            morseCode = "--.-";
            break;
        case 'r':
        case 'R':
            morseCode = ".-.";
            break;
        case 's':
        case 'S':
            morseCode = "...";
            break;
        case 't':
        case 'T':
            morseCode = "-";
            break;
        case 'u':
        case 'U':
            morseCode = "..-";
            break;
        case 'v':
        case 'V':
            morseCode = "...-";
            break;
        case 'w':
        case 'W':
            morseCode = ".--";
            break;
        case 'x':
        case 'X':
            morseCode = "-..-";
            break;
        case 'y':
        case 'Y':
            morseCode = "-.--";
            break;
        case 'z':
        case 'Z':
            morseCode = "--..";
            break;
        case ' ':
            morseCode = "/";
            break;
        default:
            morseCode = "";
    }

    return morseCode;
}

void printMorseCode(char *str) {
    int i;

    for(i = 0; i < strlen(str); i++) {
        char *morseCode = toMorseCode(str[i]);

        printf("%s", morseCode);

        if(strcmp(morseCode, "") != 0) {
            printf(" ");
        }
    }
}