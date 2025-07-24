//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* translate(char* phrase) {
    int length = strlen(phrase);
    char* translation = (char*)malloc(length);
    memset(translation, '\0', length);

    // Translate each character
    for (int i = 0; i < length; i++) {
        if (phrase[i] == 'A') {
            translation[i] = '12';
        }
        else if (phrase[i] == 'B') {
            translation[i] = '13';
        }
        else if (phrase[i] == 'C') {
            translation[i] = '14';
        }
        else if (phrase[i] == 'D') {
            translation[i] = '15';
        }
        else if (phrase[i] == 'E') {
            translation[i] = '16';
        }
        else if (phrase[i] == 'F') {
            translation[i] = '17';
        }
        else if (phrase[i] == 'G') {
            translation[i] = '18';
        }
        else if (phrase[i] == 'H') {
            translation[i] = '19';
        }
        else if (phrase[i] == 'I') {
            translation[i] = '20';
        }
        else if (phrase[i] == 'J') {
            translation[i] = '21';
        }
        else if (phrase[i] == 'K') {
            translation[i] = '22';
        }
        else if (phrase[i] == 'L') {
            translation[i] = '23';
        }
        else if (phrase[i] == 'M') {
            translation[i] = '24';
        }
        else if (phrase[i] == 'N') {
            translation[i] = '25';
        }
        else if (phrase[i] == 'O') {
            translation[i] = '26';
        }
        else if (phrase[i] == 'P') {
            translation[i] = '27';
        }
        else if (phrase[i] == 'Q') {
            translation[i] = '28';
        }
        else if (phrase[i] == 'R') {
            translation[i] = '29';
        }
        else if (phrase[i] == 'S') {
            translation[i] = '30';
        }
        else if (phrase[i] == 'T') {
            translation[i] = '31';
        }
        else if (phrase[i] == 'U') {
            translation[i] = '32';
        }
        else if (phrase[i] == 'V') {
            translation[i] = '33';
        }
        else if (phrase[i] == 'W') {
            translation[i] = '34';
        }
        else if (phrase[i] == 'X') {
            translation[i] = '35';
        }
        else if (phrase[i] == 'Y') {
            translation[i] = '36';
        }
        else if (phrase[i] == 'Z') {
            translation[i] = '37';
        }
        else {
            translation[i] = phrase[i];
        }
    }

    return translation;
}

int main() {
    char phrase[100];
    char* translation;

    printf("Enter a phrase to translate to Alien Language: ");
    scanf("%s", phrase);

    translation = translate(phrase);

    printf("Translation: %s\n", translation);

    return 0;
}