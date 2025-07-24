//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printCharacter(char c) {
    switch(c) {
        case 'A': printf("/\\"); break;
        case 'B': printf("|B|"); break;
        case 'C': printf("<>"); break;
        case 'D': printf("|D"); break;
        case 'E': printf("|E-"); break;
        case 'F': printf("|F"); break;
        case 'G': printf("[G"); break;
        case 'H': printf("/\\/\\"); break;
        case 'I': printf("|I|"); break;
        case 'J': printf("_|J"); break;
        case 'K': printf("\\/\\"); break;
        case 'L': printf("L|"); break;
        case 'M': printf("/\\/|\\/\\"); break;
        case 'N': printf("|\\|"); break;
        case 'O': printf("(O)"); break;
        case 'P': printf("|P"); break;
        case 'Q': printf("(O)\\_"); break;
        case 'R': printf("|R"); break;
        case 'S': printf("S"); break;
        case 'T': printf("|T"); break;
        case 'U': printf("\\_/"); break;
        case 'V': printf("\\/"); break;
        case 'W': printf("\\/\\/\\/"); break;
        case 'X': printf("\\/\\"); break;
        case 'Y': printf("\\/"); break;
        case 'Z': printf("Z"); break;
        case ' ': printf("  "); break;
        case '.': printf("••"); break;
        case ',': printf(","); break;
        case '!': printf("|!"); break;
        case '?': printf("|?"); break;
        default: printf("??");
    }
}

void printLine(char* string) {
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        printCharacter(string[i]);
        if (i < length - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    printLine("Hello World!");
    printLine("This is an example.");
    printLine("It shows how to create");
    printLine("ASCII art from text.");
    return 0;
}