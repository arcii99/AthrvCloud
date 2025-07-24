//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

void displayCharacter(char c);

int main(void) {
    char text[100];
    printf("Enter text: ");
    fgets(text, 100, stdin);

    printf("\n");

    for(int i=0; i<strlen(text); i++) {
        displayCharacter(text[i]);
    }

    printf("\n");

    return 0;
}

void displayCharacter(char c) {
    switch(c) {
        case 'A':
        case 'a':
            printf("    /\\");
            printf("\n   /  \\");
            printf("\n  / /\\ \\");
            printf("\n / ____ \\");
            printf("\n/_/    \\_\\");
            break;
        case 'B':
        case 'b':
            printf(" ____   ");
            printf("\n|  _ \\  ");
            printf("\n| |_) | ");
            printf("\n|  __/  ");
            printf("\n|_|     ");
            break;
        case 'C':
        case 'c':
            printf("  _____ ");
            printf("\n / ____|");
            printf("\n| |     ");
            printf("\n| |     ");
            printf("\n| |____ ");
            break;
        // continue with other characters
        default:
            printf("        ");
    }
    printf(" ");
}