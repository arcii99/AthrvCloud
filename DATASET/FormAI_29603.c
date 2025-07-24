//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

char* text_to_morse(char *text);
void encode(char *morse, char c);

int main() {

    char text[MAX_LEN];
    printf("Enter text to convert to Morse code: ");
    fgets(text, MAX_LEN, stdin);

    char *morse = text_to_morse(text);

    printf("Morse code: %s\n", morse);
    free(morse);

    return 0;
}

char* text_to_morse(char *text) {
    char *morse = malloc(MAX_LEN * sizeof(char));
    if (morse == NULL) return NULL;

    int i = 0;
    while (text[i] != '\0') {
        encode(morse, text[i]);
        i++;
    }

    return morse;
}

void encode(char *morse, char c) {
    strcat(morse, " ");
    switch(c) {
        case 'A':
        case 'a':
            strcat(morse, ".-");
            break;
        case 'B':
        case 'b':
            strcat(morse, "-...");
            break;
        case 'C':
        case 'c':
            strcat(morse, "-.-.");
            break;
        case 'D':
        case 'd':
            strcat(morse, "-..");
            break;
        case 'E':
        case 'e':
            strcat(morse, ".");
            break;
        case 'F':
        case 'f':
            strcat(morse, "..-.");
            break;
        case 'G':
        case 'g':
            strcat(morse, "--.");
            break;
        case 'H':
        case 'h':
            strcat(morse, "....");
            break;
        case 'I':
        case 'i':
            strcat(morse, "..");
            break;
        case 'J':
        case 'j':
            strcat(morse, ".---");
            break;
        case 'K':
        case 'k':
            strcat(morse, "-.-");
            break;
        case 'L':
        case 'l':
            strcat(morse, ".-..");
            break;
        case 'M':
        case 'm':
            strcat(morse, "--");
            break;
        case 'N':
        case 'n':
            strcat(morse, "-.");
            break;
        case 'O':
        case 'o':
            strcat(morse, "---");
            break;
        case 'P':
        case 'p':
            strcat(morse, ".--.");
            break;
        case 'Q':
        case 'q':
            strcat(morse, "--.-");
            break;
        case 'R':
        case 'r':
            strcat(morse, ".-.");
            break;
        case 'S':
        case 's':
            strcat(morse, "...");
            break;
        case 'T':
        case 't':
            strcat(morse, "-");
            break;
        case 'U':
        case 'u':
            strcat(morse, "..-");
            break;
        case 'V':
        case 'v':
            strcat(morse, "...-");
            break;
        case 'W':
        case 'w':
            strcat(morse, ".--");
            break;
        case 'X':
        case 'x':
            strcat(morse, "-..-");
            break;
        case 'Y':
        case 'y':
            strcat(morse, "-.--");
            break;
        case 'Z':
        case 'z':
            strcat(morse, "--..");
            break;
        case ' ':
            strcat(morse, "/");
            break;
        default:
            strcat(morse, "");
            break;
    }
}