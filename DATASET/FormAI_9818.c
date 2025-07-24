//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* morseCode(char c);

int main() {
    char input[100];
    printf("Enter text message: ");
    fgets(input, 100, stdin);

    for(int i = 0; i < strlen(input); i++) {
        char c = input[i];
        char *morse = morseCode(c);
        printf("%s ", morse);
        free(morse);
    }
    printf("\n");

    return 0;
}

char* morseCode(char c) {
    char *morse;
    switch(c) {
        case 'a': 
            morse = strdup(".-");
            break;
        case 'b':
            morse = strdup("-...");
            break;
        case 'c':
            morse = strdup("-.-.");
            break;
        case 'd':
            morse = strdup("-..");
            break;
        case 'e':
            morse = strdup(".");
            break;
        case 'f':
            morse = strdup("..-.");
            break;
        case 'g':
            morse = strdup("--.");
            break;
        case 'h':
            morse = strdup("....");
            break;
        case 'i':
            morse = strdup("..");
            break;
        case 'j':
            morse = strdup(".---");
            break;
        case 'k':
            morse = strdup("-.-");
            break;
        case 'l':
            morse = strdup(".-..");
            break;
        case 'm':
            morse = strdup("--");
            break;
        case 'n':
            morse = strdup("-.");
            break;
        case 'o':
            morse = strdup("---");
            break;
        case 'p':
            morse = strdup(".--.");
            break;
        case 'q':
            morse = strdup("--.-");
            break;
        case 'r':
            morse = strdup(".-.");
            break;
        case 's':
            morse = strdup("...");
            break;
        case 't':
            morse = strdup("-");
            break;
        case 'u':
            morse = strdup("..-");
            break;
        case 'v':
            morse = strdup("...-");
            break;
        case 'w':
            morse = strdup(".--");
            break;
        case 'x':
            morse = strdup("-..-");
            break;
        case 'y':
            morse = strdup("-.--");
            break;
        case 'z':
            morse = strdup("--..");
            break;
        case ' ':
            morse = strdup(" ");
            break;
        default:
            morse = strdup("");
            break;
    }
    return morse;
}