//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

void printChar(char c) {
    switch(c) {
        case 'A':
            printf("  /\\  \n /  \\ \n/____\\");
            break;
        case 'B':
            printf(" ____  \n|    \\ \n|____/");
            break;
        case 'C':
            printf("  ___ \n /    \\\n/____/");
            break;
        case 'D':
            printf(" _____\n|     \\\n|____/");
            break;
        // Add more cases for other letters
    }
    printf("\n");
}

int main() {
    char name[50];
    printf("What is your name?\n");
    scanf("%s", name);
    printf("Hello, %s.\n", name);
    printf("Now let's convert your name to ASCII art.\n");
    for (int i = 0; i < strlen(name); i++) {
        printChar(name[i]);
    }
    return 0;
}