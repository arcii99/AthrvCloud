//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: innovative
#include <stdio.h>

// Define the Alien Language dictionary
typedef enum { UNKNOWN, A, B, C, D, E } AlienLanguage;

AlienLanguage charToAlienLanguage(char input) {
    switch (input) {
        case 'a': return A;
        case 'b': return B;
        case 'c': return C;
        case 'd': return D;
        case 'e': return E;
        default: return UNKNOWN;
    }
}

char alienLanguageToChar(AlienLanguage input) {
    switch (input) {
        case A: return 'a';
        case B: return 'b';
        case C: return 'c';
        case D: return 'd';
        case E: return 'e';
        default: return '?';
    }
}

int main() {
    char input[50];
    printf("Enter Alien Language Text: ");
    fgets(input, 50, stdin);

    int i = 0;
    AlienLanguage current = UNKNOWN;
    AlienLanguage prev = UNKNOWN;
    AlienLanguage prevPrev = UNKNOWN;

    while (input[i] != '\n' && input[i] != '\0') {
        prevPrev = prev;
        prev = current;
        current = charToAlienLanguage(input[i]);

        if (current == UNKNOWN) {
            printf("%c", input[i]);
            i++;
            continue;
        }

        if (prev == prevPrev && current == prev) {
            printf(" ");
        }

        printf("%c", alienLanguageToChar(current));
        i++;
    }

    return 0;
}