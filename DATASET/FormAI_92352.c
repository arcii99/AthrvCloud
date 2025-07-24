//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: innovative
#include <stdio.h>
#include <string.h>

void morseCode(char letter) {
    switch(letter) {
        case 'A':
        case 'a':
            printf(".- ");
            break;
        case 'B':
        case 'b':
            printf("-... ");
            break;
        case 'C':
        case 'c':
            printf("-.-. ");
            break;
        case 'D':
        case 'd':
            printf("-.. ");
            break;
        case 'E':
        case 'e':
            printf(". ");
            break;
        case 'F':
        case 'f':
            printf("..-. ");
            break;
        case 'G':
        case 'g':
            printf("--. ");
            break;
        case 'H':
        case 'h':
            printf(".... ");
            break;
        case 'I':
        case 'i':
            printf(".. ");
            break;
        case 'J':
        case 'j':
            printf(".--- ");
            break;
        case 'K':
        case 'k':
            printf("-.- ");
            break;
        case 'L':
        case 'l':
            printf(".-.. ");
            break;
        case 'M':
        case 'm':
            printf("-- ");
            break;
        case 'N':
        case 'n':
            printf("-. ");
            break;
        case 'O':
        case 'o':
            printf("--- ");
            break;
        case 'P':
        case 'p':
            printf(".--. ");
            break;
        case 'Q':
        case 'q':
            printf("--.- ");
            break;
        case 'R':
        case 'r':
            printf(".-. ");
            break;
        case 'S':
        case 's':
            printf("... ");
            break;
        case 'T':
        case 't':
            printf("- ");
            break;
        case 'U':
        case 'u':
            printf("..- ");
            break;
        case 'V':
        case 'v':
            printf("...- ");
            break;
        case 'W':
        case 'w':
            printf(".-- ");
            break;
        case 'X':
        case 'x':
            printf("-..- ");
            break;
        case 'Y':
        case 'y':
            printf("-.-- ");
            break;
        case 'Z':
        case 'z':
            printf("--.. ");
            break;
        case ' ':
            printf(" ");
            break;
        default:
            printf("%c is not a valid letter.", letter);
    }
}

int main() {
    char input[1000];
    printf("Enter the text to convert to Morse code: ");
    fgets(input, 1000, stdin);
    printf("\nMorse code of the entered text is: ");

    for(int i = 0; i < strlen(input); i++) {
        morseCode(input[i]);
    }

    return 0;
}