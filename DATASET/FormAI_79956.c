//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: visionary
#include <stdio.h>
#include <string.h>

void morseCode(char letter) {
    switch (letter) {
        case 'A':
            printf(".-");
            break;
        case 'B':
            printf("-...");
            break;
        case 'C':
            printf("-.-.");
            break;
        case 'D':
            printf("-..");
            break;
        case 'E':
            printf(".");
            break;
        case 'F':
            printf("..-.");
            break;
        case 'G':
            printf("--.");
            break;
        case 'H':
            printf("....");
            break;
        case 'I':
            printf("..");
            break;
        case 'J':
            printf(".---");
            break;
        case 'K':
            printf("-.-");
            break;
        case 'L':
            printf(".-..");
            break;
        case 'M':
            printf("--");
            break;
        case 'N':
            printf("-.");
            break;
        case 'O':
            printf("---");
            break;
        case 'P':
            printf(".--.");
            break;
        case 'Q':
            printf("--.-");
            break;
        case 'R':
            printf(".-.");
            break;
        case 'S':
            printf("...");
            break;
        case 'T':
            printf("-");
            break;
        case 'U':
            printf("..-");
            break;
        case 'V':
            printf("...-");
            break;
        case 'W':
            printf(".--");
            break;
        case 'X':
            printf("-..-");
            break;
        case 'Y':
            printf("-.--");
            break;
        case 'Z':
            printf("--..");
            break;
        case ' ':
            printf("/");
            break;
    }
}

int main() {
    char text[100];
    printf("Enter text to convert to Morse code: ");
    fgets(text, 100, stdin);

    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        morseCode(toupper(text[i]));
        printf(" ");
    }

    return 0;
}