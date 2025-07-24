//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char text[100];
    printf("Enter text to convert to Morse code: ");
    fgets(text, 100, stdin);

    char morse[1000] = "";
    for (int i = 0; i < strlen(text); i++) {
        switch (tolower(text[i])) {
            case 'a':
                strcat(morse, ".- ");
                break;
            case 'b':
                strcat(morse, "-... ");
                break;
            case 'c':
                strcat(morse, "-.-. ");
                break;
            case 'd':
                strcat(morse, "-.. ");
                break;
            case 'e':
                strcat(morse, ". ");
                break;
            case 'f':
                strcat(morse, "..-. ");
                break;
            case 'g':
                strcat(morse, "--. ");
                break;
            case 'h':
                strcat(morse, ".... ");
                break;
            case 'i':
                strcat(morse, ".. ");
                break;
            case 'j':
                strcat(morse, ".--- ");
                break;
            case 'k':
                strcat(morse, "-.- ");
                break;
            case 'l':
                strcat(morse, ".-.. ");
                break;
            case 'm':
                strcat(morse, "-- ");
                break;
            case 'n':
                strcat(morse, "-. ");
                break;
            case 'o':
                strcat(morse, "--- ");
                break;
            case 'p':
                strcat(morse, ".--. ");
                break;
            case 'q':
                strcat(morse, "--.- ");
                break;
            case 'r':
                strcat(morse, ".-. ");
                break;
            case 's':
                strcat(morse, "... ");
                break;
            case 't':
                strcat(morse, "- ");
                break;
            case 'u':
                strcat(morse, "..- ");
                break;
            case 'v':
                strcat(morse, "...- ");
                break;
            case 'w':
                strcat(morse, ".-- ");
                break;
            case 'x':
                strcat(morse, "-..- ");
                break;
            case 'y':
                strcat(morse, "-.-- ");
                break;
            case 'z':
                strcat(morse, "--.. ");
                break;
            case ' ':
                strcat(morse, "/ ");
                break;
            default:
                printf("I am sorry, I cannot convert that character to Morse code.\n");
        }
    }

    printf("Morse code: %s\n", morse);

    return 0;
}