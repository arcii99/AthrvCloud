//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: lively
#include <stdio.h>

void printArt(char character) {
    switch (character) {
        case 'a':
            printf("  \n");
            printf(" /\\\n");
            printf("/__\\\n");
            printf("/   \\   \n");
            printf("|     |\n");
            printf("|     |\n");
            break;

        case 'b':
            printf("  \n");
            printf("|\n");
            printf("|-----\\\n");
            printf("|      |\n");
            printf("|-----/\n");
            printf("|     |\n");
            printf("|-----/\n");
            break;

        case 'c':
            printf("  \n");
            printf(" /\\\n");
            printf("/__\\\n");
            printf("|  \n");
            printf("|  \n");
            printf("\\___\\\n");
            break;

        default:
            printf("Sorry, that character is not supported.\n");
            break;
    }
}

int main() {
    char character;

    printf("Enter a character to generate ASCII art: ");
    scanf("%c", &character);

    printArt(character);

    return 0;
}