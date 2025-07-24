//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char input[100], morse_code[500] = "";
    int i, j, length;

    printf("Enter text to convert to Morse code:\n");
    fgets(input, 100, stdin);

    length = strlen(input);

    for (i = 0, j = 0; i < length; i++) {
        switch (input[i]) {
            case 'a':
            case 'A':
                strcat(morse_code, ".- ");
                break;
            case 'b':
            case 'B':
                strcat(morse_code, "-... ");
                break;
            case 'c':
            case 'C':
                strcat(morse_code, "-.-. ");
                break;
            case 'd':
            case 'D':
                strcat(morse_code, "-.. ");
                break;
            case 'e':
            case 'E':
                strcat(morse_code, ". ");
                break;
            case 'f':
            case 'F':
                strcat(morse_code, "..-. ");
                break;
            case 'g':
            case 'G':
                strcat(morse_code, "--. ");
                break;
            case 'h':
            case 'H':
                strcat(morse_code, ".... ");
                break;
            case 'i':
            case 'I':
                strcat(morse_code, ".. ");
                break;
            case 'j':
            case 'J':
                strcat(morse_code, ".--- ");
                break;
            case 'k':
            case 'K':
                strcat(morse_code, "-.- ");
                break;
            case 'l':
            case 'L':
                strcat(morse_code, ".-.. ");
                break;
            case 'm':
            case 'M':
                strcat(morse_code, "-- ");
                break;
            case 'n':
            case 'N':
                strcat(morse_code, "-. ");
                break;
            case 'o':
            case 'O':
                strcat(morse_code, "--- ");
                break;
            case 'p':
            case 'P':
                strcat(morse_code, ".--. ");
                break;
            case 'q':
            case 'Q':
                strcat(morse_code, "--.- ");
                break;
            case 'r':
            case 'R':
                strcat(morse_code, ".-. ");
                break;
            case 's':
            case 'S':
                strcat(morse_code, "... ");
                break;
            case 't':
            case 'T':
                strcat(morse_code, "- ");
                break;
            case 'u':
            case 'U':
                strcat(morse_code, "..- ");
                break;
            case 'v':
            case 'V':
                strcat(morse_code, "...- ");
                break;
            case 'w':
            case 'W':
                strcat(morse_code, ".-- ");
                break;
            case 'x':
            case 'X':
                strcat(morse_code, "-..- ");
                break;
            case 'y':
            case 'Y':
                strcat(morse_code, "-.-- ");
                break;
            case 'z':
            case 'Z':
                strcat(morse_code, "--.. ");
                break;
            case ' ':
                strcat(morse_code, "/ ");
                break;
            case '\n':
                break;
            default:
                printf("\nInvalid character '%c' found in input!", input[i]);
                printf("\nThis message cannot be translated to Morse code. Please try again!");
                exit(1);
        }
    }

    printf("\nOriginal text: %s", input);
    printf("Morse code: %s", morse_code);

    return 0;
}