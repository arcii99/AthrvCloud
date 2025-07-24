//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: brave
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// This function will translate the given input string to the alien language
void alienLanguageTranslator(char* input) {

    // Looping through each character of the input string
    for (int i = 0; i < strlen(input); i++) {

        // Converting each character to uppercase
        char c = toupper(input[i]);

        // Translating the character based on the alien language rules
        switch (c) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                printf("ZOINK ");
                break;
            case 'B':
                printf("BLORK ");
                break;
            case 'C':
                printf("CLANG ");
                break;
            case 'D':
                printf("DEXTER ");
                break;
            case 'F':
                printf("FLIK ");
                break;
            case 'G':
                printf("GLOM ");
                break;
            case 'H':
                printf("HULK ");
                break;
            case 'J':
                printf("JINK ");
                break;
            case 'K':
                printf("KLANK ");
                break;
            case 'L':
                printf("LUGG ");
                break;
            case 'M':
                printf("MUNG ");
                break;
            case 'N':
                printf("NIMB ");
                break;
            case 'P':
                printf("POCK ");
                break;
            case 'Q':
                printf("QUICK ");
                break;
            case 'R':
                printf("RASH ");
                break;
            case 'S':
                printf("SLIK ");
                break;
            case 'T':
                printf("TOCK ");
                break;
            case 'V':
                printf("VINK ");
                break;
            case 'W':
                printf("WACK ");
                break;
            case 'X':
                printf("XERX ");
                break;
            case 'Y':
                printf("YAKK ");
                break;
            case 'Z':
                printf("ZARK ");
                break;
            default:
                // If character is not a letter, just print it as it is
                printf("%c", input[i]);
        }
    }
}

int main() {
    // Getting the user input
    char input[100];
    printf("Enter a string to translate to alien language: ");
    fgets(input, sizeof(input), stdin);

    // Calling the alienLanguageTranslator function and passing input as argument
    alienLanguageTranslator(input);

    return 0;
}