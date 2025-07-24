//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

void convertToMorseCode(char character) {
    switch (character) {
        case 'a':
            printf(".- ");
            break;
        case 'b':
            printf("-... ");
            break;
        case 'c':
            printf("-.-. ");
            break;
        case 'd':
            printf("-.. ");
            break;
        case 'e':
            printf(". ");
            break;
        case 'f':
            printf("..-. ");
            break;
        case 'g':
            printf("--. ");
            break;
        case 'h':
            printf(".... ");
            break;
        case 'i':
            printf(".. ");
            break;
        case 'j':
            printf(".--- ");
            break;
        case 'k':
            printf("-.- ");
            break;
        case 'l':
            printf(".-.. ");
            break;
        case 'm':
            printf("-- ");
            break;
        case 'n':
            printf("-. ");
            break;
        case 'o':
            printf("--- ");
            break;
        case 'p':
            printf(".--. ");
            break;
        case 'q':
            printf("--.- ");
            break;
        case 'r':
            printf(".-. ");
            break;
        case 's':
            printf("... ");
            break;
        case 't':
            printf("- ");
            break;
        case 'u':
            printf("..- ");
            break;
        case 'v':
            printf("...- ");
            break;
        case 'w':
            printf(".-- ");
            break;
        case 'x':
            printf("-..- ");
            break;
        case 'y':
            printf("-.-- ");
            break;
        case 'z':
            printf("--.. ");
            break;
        case ' ':
            printf("/ ");
            break;
        default:
            printf("%c is not a valid character.\n", character);
            break;
    }
}

int main() {
    char text[100];
    int i;

    printf("Enter text to convert to Morse code: ");
    fgets(text, 100, stdin);

    for (i = 0; i < strlen(text); i++) {
        convertToMorseCode(text[i]);
    }

    return 0;
}