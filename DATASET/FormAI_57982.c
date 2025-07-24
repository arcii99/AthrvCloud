//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: scientific
#include <stdio.h>
#include <string.h>

void alienTranslator(char code[]) {
    int length = strlen(code);
    int i;
    char translation[length];

    for (i = 0; i < length; i++) {

        switch (code[i]) {
            case '1':
                translation[i] = 'A';
                break;

            case '2':
                translation[i] = 'B';
                break;

            case '3':
                translation[i] = 'C';
                break;

            case '4':
                translation[i] = 'D';
                break;

            case '5':
                translation[i] = 'E';
                break;

            case '6':
                translation[i] = 'F';
                break;

            case '7':
                translation[i] = 'G';
                break;

            case '8':
                translation[i] = 'H';
                break;

            case '9':
                translation[i] = 'I';
                break;

            case '0':
                translation[i] = 'J';
                break;

            default:
                translation[i] = ' ';
                break;
        }
    }

    printf("The code '%s' translates to '%s'.", code, translation);
}

int main() {
    char code[] = "94513620";
    alienTranslator(code);
    return 0;
}