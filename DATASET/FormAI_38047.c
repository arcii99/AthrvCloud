//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language symbols
#define ALIEN_A '!'
#define ALIEN_B '#'
#define ALIEN_C '$'
#define ALIEN_D '%'
#define ALIEN_E '&'
#define ALIEN_F '@'

// Define the translated language symbols
#define TRANSLATED_A 'a'
#define TRANSLATED_B 'b'
#define TRANSLATED_C 'c'
#define TRANSLATED_D 'd'
#define TRANSLATED_E 'e'
#define TRANSLATED_F 'f'

// Converts the given alien language character to a translated language character
char convert_char(char c) {
    char output;

    switch(c) {
        case ALIEN_A:
            output = TRANSLATED_A;
            break;
        case ALIEN_B:
            output = TRANSLATED_B;
            break;
        case ALIEN_C:
            output = TRANSLATED_C;
            break;
        case ALIEN_D:
            output = TRANSLATED_D;
            break;
        case ALIEN_E:
            output = TRANSLATED_E;
            break;
        case ALIEN_F:
            output = TRANSLATED_F;
            break;
        default:
            output = c;
    }

    return output;
}

int main() {
    char input[100];
    char output[100];
    int i, len;

    printf("Please enter the alien language phrase:\n");
    fgets(input, 100, stdin);

    len = strlen(input);

    for(i = 0; i < len; i++) {
        output[i] = convert_char(input[i]);
    }

    printf("Translated phrase: %s", output);

    return 0;
}