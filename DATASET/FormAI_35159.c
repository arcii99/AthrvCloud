//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convertToMorse(char *text);

int main()
{
    char text[100];
    printf("Enter the text to be converted to Morse code: ");
    fgets(text, 100, stdin);

    char *morseCode = convertToMorse(text);

    printf("\nMorse code of the given text is: %s\n", morseCode);

    free(morseCode);
    return 0;
}

char *convertToMorse(char *text)
{
    char *morseCode = (char *)malloc(sizeof(char) * 10000);
    if (morseCode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    memset(morseCode, '\0', 10000);

    int i = 0;
    while (text[i] != '\n')
    {
        switch (text[i])
        {
        case 'A':
        case 'a':
            strcat(morseCode, ".- ");
            break;
        case 'B':
        case 'b':
            strcat(morseCode, "-... ");
            break;
        case 'C':
        case 'c':
            strcat(morseCode, "-.-. ");
            break;
        case 'D':
        case 'd':
            strcat(morseCode, "-.. ");
            break;
        case 'E':
        case 'e':
            strcat(morseCode, ". ");
            break;
        case 'F':
        case 'f':
            strcat(morseCode, "..-. ");
            break;
        case 'G':
        case 'g':
            strcat(morseCode, "--. ");
            break;
        case 'H':
        case 'h':
            strcat(morseCode, ".... ");
            break;
        case 'I':
        case 'i':
            strcat(morseCode, ".. ");
            break;
        case 'J':
        case 'j':
            strcat(morseCode, ".--- ");
            break;
        case 'K':
        case 'k':
            strcat(morseCode, "-.- ");
            break;
        case 'L':
        case 'l':
            strcat(morseCode, ".-.. ");
            break;
        case 'M':
        case 'm':
            strcat(morseCode, "-- ");
            break;
        case 'N':
        case 'n':
            strcat(morseCode, "-. ");
            break;
        case 'O':
        case 'o':
            strcat(morseCode, "--- ");
            break;
        case 'P':
        case 'p':
            strcat(morseCode, ".--. ");
            break;
        case 'Q':
        case 'q':
            strcat(morseCode, "--.- ");
            break;
        case 'R':
        case 'r':
            strcat(morseCode, ".-. ");
            break;
        case 'S':
        case 's':
            strcat(morseCode, "... ");
            break;
        case 'T':
        case 't':
            strcat(morseCode, "- ");
            break;
        case 'U':
        case 'u':
            strcat(morseCode, "..- ");
            break;
        case 'V':
        case 'v':
            strcat(morseCode, "...- ");
            break;
        case 'W':
        case 'w':
            strcat(morseCode, ".-- ");
            break;
        case 'X':
        case 'x':
            strcat(morseCode, "-..- ");
            break;
        case 'Y':
        case 'y':
            strcat(morseCode, "-.-- ");
            break;
        case 'Z':
        case 'z':
            strcat(morseCode, "--.. ");
            break;
        case ' ':
            strcat(morseCode, "  ");
            break;
        default:
            strcat(morseCode, "");
            break;
        }
        i++;
    }
    return morseCode;
}