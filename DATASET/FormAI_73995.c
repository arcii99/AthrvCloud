//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printChar(char c, int repeat) {
    for (int i = 0; i < repeat; i++) {
        putchar(c);
    }
}

int main() {
    char input[100];
    int length;
    printf("Enter the text you want to convert to ASCII art:\n");
    fgets(input, 100, stdin);

    length = strlen(input) - 1;

    printf("\n\n");
    printChar('*', length+4);
    printf("\n");

    printf("*");
    printChar(' ', length+2);
    printf("*\n");

    printf("* ");
    printf("%s", input);
    printf(" *\n");

    printf("*");
    printChar(' ', length+2);
    printf("*\n");

    printChar('*', length+4);

    return 0;
}