//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: surprised
#include <stdio.h>
#include <string.h>

// Function to convert English characters to Morse code
void convertToMorse(char englishChar) {
    switch (englishChar) {
        case 'a':
        case 'A':
            printf(".- "); break;
        case 'b':
        case 'B':
            printf("-... "); break;
        case 'c':
        case 'C':
            printf("-.-. "); break;
        case 'd':
        case 'D':
            printf("-.. "); break;
        case 'e':
        case 'E':
            printf(". "); break;
        case 'f':
        case 'F':
            printf("..-. "); break;
        case 'g':
        case 'G':
            printf("--. "); break;
        case 'h':
        case 'H':
            printf(".... "); break;
        case 'i':
        case 'I':
            printf(".. "); break;
        case 'j':
        case 'J':
            printf(".--- "); break;
        case 'k':
        case 'K':
            printf("-.- "); break;
        case 'l':
        case 'L':
            printf(".-.. "); break;
        case 'm':
        case 'M':
            printf("-- "); break;
        case 'n':
        case 'N':
            printf("-. "); break;
        case 'o':
        case 'O':
            printf("--- "); break;
        case 'p':
        case 'P':
            printf(".--. "); break;
        case 'q':
        case 'Q':
            printf("--.- "); break;
        case 'r':
        case 'R':
            printf(".-. "); break;
        case 's':
        case 'S':
            printf("... "); break;
        case 't':
        case 'T':
            printf("- "); break;
        case 'u':
        case 'U':
            printf("..- "); break;
        case 'v':
        case 'V':
            printf("...- "); break;
        case 'w':
        case 'W':
            printf(".-- "); break;
        case 'x':
        case 'X':
            printf("-..- "); break;
        case 'y':
        case 'Y':
            printf("-.-- "); break;
        case 'z':
        case 'Z':
            printf("--.. "); break;
        case ' ':
            printf("/ "); break;
        default:
            printf("%c ", englishChar);
    }
}

int main() {
    char englishString[100];
    printf("Enter the sentence to be converted to Morse code: ");
    fgets(englishString, 100, stdin);
    printf("Your sentence in Morse code is:\n");
    for (int i = 0; i < strlen(englishString); i++) {
        convertToMorse(englishString[i]);
    }
    printf("\nSurprised to see how easy it is to convert English to Morse code with just a few lines of code, aren't you?");
    return 0;
}