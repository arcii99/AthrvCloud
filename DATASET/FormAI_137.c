//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * Function to convert a C string to uppercase.
 *
 * @param  str   the input C string
 */
void str_to_upper(char* str) {
    while (*str) {
        *str = toupper((unsigned char) *str);
        str++;
    }
}

/**
 * Function to translate a C string to Alien language.
 *
 * @param  str   the input C string
 */
void translate_to_alien(char* str) {
    str_to_upper(str);

    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];

        switch (c) {
            case 'A':
                printf("alienish ");
                break;
            case 'B':
                printf("bloop ");
                break;
            case 'C':
                printf("clack ");
                break;
            case 'D':
                printf("ding ");
                break;
            case 'E':
                printf("eep ");
                break;
            case 'F':
                printf("flint ");
                break;
            case 'G':
                printf("glorg ");
                break;
            case 'H':
                printf("harp ");
                break;
            case 'I':
                printf("ip ");
                break;
            case 'J':
                printf("jingle ");
                break;
            case 'K':
                printf("klunk ");
                break;
            case 'L':
                printf("loop ");
                break;
            case 'M':
                printf("moo ");
                break;
            case 'N':
                printf("noop ");
                break;
            case 'O':
                printf("oop ");
                break;
            case 'P':
                printf("ping ");
                break;
            case 'Q':
                printf("quack ");
                break;
            case 'R':
                printf("ring ");
                break;
            case 'S':
                printf("squeak ");
                break;
            case 'T':
                printf("tong ");
                break;
            case 'U':
                printf("urrp ");
                break;
            case 'V':
                printf("vroom ");
                break;
            case 'W':
                printf("wham ");
                break;
            case 'X':
                printf("xenon ");
                break;
            case 'Y':
                printf("yip ");
                break;
            case 'Z':
                printf("zoo ");
                break;
            default:
                printf("%c", c);
        }
    }
    printf("\n");
}

/**
 * Main function that gets user input and calls the translation function.
 */
int main() {
    char input[256];

    printf("Enter a string to translate to Alien language: ");
    fgets(input, 256, stdin);

    input[strcspn(input, "\n")] = '\0'; // remove trailing newline character
    printf("Translation: ");
    translate_to_alien(input);

    return 0;
}