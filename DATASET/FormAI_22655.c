//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: peaceful
#include <stdio.h>
#include <string.h>

// This function prints a peace symbol in ASCII art
void printSymbol() {
    printf("        ____\n");
    printf("    ___/    \\___\n");
    printf("   /   \\\\~~//  \\\n");
    printf("  |   (@)  (@)  |\n");
    printf("  |             |\n");
    printf("  |  *   \\_/   * |\n");
    printf("  \\     / \\     /\n");
    printf("   \\_  /   \\  _/\n");
    printf("     \\/     \\/\n\n");
}

// This function converts a character to ASCII art
void convertCharToAscii(char c) {
    int index = (int)c;
    switch (index) {
        case 32:
            printf("    \n");
            printf("    \n");
            printf("    \n");
            printf("    \n");
            break;
        case 65 ... 90:
            printf("   Y  \n");
            printf("  / \\ \n");
            printf(" /___\\\n");
            printf("/     \\\n");
            break;
        case 97 ... 122:
            printf("   y  \n");
            printf("  / \\ \n");
            printf(" /   \\\n");
            printf("/_____\\\n");
            break;
        case 48 ... 57:
            printf("  ___ \n");
            printf(" /   \\ \n");
            printf("|  o  |\n");
            printf(" \\___/ \n");
            break;
        default:
            printf("       \n");
            printf("       \n");
            printf("       \n");
            printf("       \n");
            break;
    }
}

int main() {
    char text[100];
    printf("Enter some text: ");
    fgets(text, 100, stdin);
    printf("\n");
    printSymbol();
    printf("Your text in ASCII art:\n");
    for (int i = 0; i < strlen(text); i++) {
        convertCharToAscii(text[i]);
    }
    return 0;
}