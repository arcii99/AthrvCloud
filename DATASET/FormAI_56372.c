//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: surrealist
#include <stdio.h>
#include <string.h>

int main() {
    char text[100], morse[100];
    int i, j, len;

    printf("Enter text to be converted to Morse code: ");
    fgets(text, sizeof(text), stdin);
    len = strlen(text);

    for (i = 0, j = 0; i < len; i++) {
        switch (text[i]) {
            case 'a':
                strcpy(morse+j, ".- ");
                j += 2;
                break;
            case 'b':
                strcpy(morse+j, "-... ");
                j += 4;
                break;
            case 'c':
                strcpy(morse+j, "-.-. ");
                j += 4;
                break;
            case 'd':
                strcpy(morse+j, "-.. ");
                j += 3;
                break;
            case 'e':
                strcpy(morse+j, ". ");
                j += 1;
                break;
            case 'f':
                strcpy(morse+j, "..-. ");
                j += 4;
                break;
            case 'g':
                strcpy(morse+j, "--. ");
                j += 3;
                break;
            case 'h':
                strcpy(morse+j, ".... ");
                j += 4;
                break;
            case 'i':
                strcpy(morse+j, ".. ");
                j += 2;
                break;
            case 'j':
                strcpy(morse+j, ".--- ");
                j += 4;
                break;
            case 'k':
                strcpy(morse+j, "-.- ");
                j += 3;
                break;
            case 'l':
                strcpy(morse+j, ".-.. ");
                j += 4;
                break;
            case 'm':
                strcpy(morse+j, "-- ");
                j += 2;
                break;
            case 'n':
                strcpy(morse+j, "-. ");
                j += 2;
                break;
            case 'o':
                strcpy(morse+j, "--- ");
                j += 3;
                break;
            case 'p':
                strcpy(morse+j, ".--. ");
                j += 4;
                break;
            case 'q':
                strcpy(morse+j, "--.- ");
                j += 4;
                break;
            case 'r':
                strcpy(morse+j, ".-. ");
                j += 3;
                break;
            case 's':
                strcpy(morse+j, "... ");
                j += 3;
                break;
            case 't':
                strcpy(morse+j, "- ");
                j += 1;
                break;
            case 'u':
                strcpy(morse+j, "..- ");
                j += 3;
                break;
            case 'v':
                strcpy(morse+j, "...- ");
                j += 4;
                break;
            case 'w':
                strcpy(morse+j, ".-- ");
                j += 3;
                break;
            case 'x':
                strcpy(morse+j, "-..- ");
                j += 4;
                break;
            case 'y':
                strcpy(morse+j, "-.-- ");
                j += 4;
                break;
            case 'z':
                strcpy(morse+j, "--.. ");
                j += 4;
                break;
            case '\0':
                strcpy(morse+j, "\0");
                break;
            default:
                printf("Invalid character encountered: %c\n", text[i]);
        }
    }

    printf("Morse code for the text is: %s\n", morse);
    return 0;
}