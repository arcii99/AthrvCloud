//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: shocked
#include <stdio.h>
#include <string.h>

void print_char(char c, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", c);
    }
}

void text_to_art(char* text) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        switch (text[i]) {
            case 'A':
            case 'a':
                printf("     /\\_\n");
                printf("    /  o \\\n");
                printf("   /   -  \\\n");
                printf("  /        \\\n");
                printf(" /_________\\\n");
                break;
            case 'B':
            case 'b':
                printf(" ____\n");
                printf("|    \\_\n");
                printf("|     _\\\n");
                printf("|    / '|\n");
                printf("|____\\__/ \n");
                break;
            case 'C':
            case 'c':
                printf("  _____ \n");
                printf(" /      \\\n");
                printf("/        \\\n");
                printf("\\        /\n");
                printf(" \\______/\n");
                break;
            case 'D':
            case 'd':
                printf(" ____\n");
                printf("|    \\_\n");
                printf("|     \\\n");
                printf("|     |\n");
                printf("|____/\n");
                break;
            case 'E':
            case 'e':
                printf(" _____\n");
                printf("|      \\\n");
                printf("|------|\n");
                printf("|      /\n");
                printf("|_____/\n");
                break;
            case 'F':
            case 'f':
                printf(" _____\n");
                printf("|      \\\n");
                printf("|------|\n");
                printf("|      \n");
                printf("|      \n");
                break;
            case 'G':
            case 'g':
                printf("  _____ \n");
                printf(" /      \\\n");
                printf("|   ___ \n");
                printf("|      \\\n");
                printf(" \\______\\ \n");
                break;
            case 'H':
            case 'h':
                printf(" __  __\n");
                printf("|__||__|\n");
                printf("|    | \n");
                printf("|    | \n");
                printf("|    |  \n");
                break;
            case 'I':
            case 'i':
                printf(" ____ \n");
                printf("|    |\n");
                printf("|    |\n");
                printf("|    |\n");
                printf("|____|\n");
                break;
            case 'J':
            case 'j':
                printf("   ___ \n");
                printf("  |   |\n");
                printf("  |   |\n");
                printf("  |   |\n");
                printf(" /____|\n");
                break;
            case 'K':
            case 'k':
                printf(" __  ___\n");
                printf("|__||__/\n");
                printf("|   |\\ \n");
                printf("|___| \\ \n");
                printf("|   |__\\\n");
                break;
            case 'L':
            case 'l':
                printf(" |\n");
                printf(" |\n");
                printf(" |\n");
                printf(" |\n");
                printf("|_____\n");
                break;
            case 'M':
            case 'm':
                printf(" /\\   /\\\n");
                printf("|  \\/  |\n");
                printf("|      |\n");
                printf("|      |\n");
                printf("|      |\n");
                break;
            case 'N':
            case 'n':
                printf(" /\\__/\n");
                printf("|     |\n");
                printf("|\\    |\n");
                printf("| \\   |\n");
                printf("|  \\__|\n");
                break;
            case 'O':
            case 'o':
                printf("  _____\n");
                printf(" /     \\\n");
                printf("|       |\n");
                printf("|       |\n");
                printf(" \\_____/\n");
                break;
            case 'P':
            case 'p':
                printf(" _____\n");
                printf("|     |\n");
                printf("|-----/\n");
                printf("|     \n");
                printf("|     \n");
                break;
            case 'Q':
            case 'q':
                printf("  _____ \n");
                printf(" /     \\ \n");
                printf("|       |\n");
                printf("|    __/\n");
                printf(" \\___|_\\ \n");
                break;
            case 'R':
            case 'r':
                printf(" _____\n");
                printf("|     |\n");
                printf("|-----/\n");
                printf("| \\   \n");
                printf("|  \\  \n");
                break;
            case 'S':
            case 's':
                printf("  _____\n");
                printf(" /     \\\n");
                printf("|_____/\n");
                printf("      \\\n");
                printf("\\_____/\n");
                break;
            case 'T':
            case 't':
                printf(" _____\n");
                printf("   |\n");
                printf("   |\n");
                printf("   |\n");
                printf("___|___\n");
                break;
            case 'U':
            case 'u':
                printf(" /\\    /\n");
                printf("|  \\  /\n");
                printf("|   \\/\n");
                printf("|   /\\\n");
                printf("\\__/  \\\n");
                break;
            case 'V':
            case 'v':
                printf(" /\\    /\n");
                printf("|  \\  /\n");
                printf("|   \\/\n");
                printf("|      \n");
                printf("|      \n");
                break;
            case 'W':
            case 'w':
                printf(" /\\    /\\ \n");
                printf("|  \\  /  \\\n");
                printf("|   \\/   |\n");
                printf("|        |\n");
                printf("|        |\n");
                break;
            case 'X':
            case 'x':
                printf("\\     /\n");
                printf(" \\   / \n");
                printf("  \\ /  \n");
                printf("  / \\  \n");
                printf(" /   \\ \n");
                break;
            case 'Y':
            case 'y':
                printf(" \\     /\n");
                printf("  \\   / \n");
                printf("   \\ /  \n");
                printf("    |\n");
                printf("    |\n");
                break;
            case 'Z':
            case 'z':
                printf(" ______\n");
                printf("|     / \n");
                printf("|    /  \n");
                printf("|___/   \n");
                printf("|______/\n");
                break;
            case ' ':
                printf("\n");
                printf("\n");
                printf("\n");
                printf("\n");
                printf("\n");
                break;
            default:
                printf("  _____\n");
                printf(" |     |\n");
                printf(" |  ?  |\n");
                printf(" |_____|\n");
                break;
        }
    }
}

int main() {
    char text[256];
    printf("Enter text: ");
    fgets(text, 256, stdin);
    printf("\n");
    text_to_art(text);
    return 0;
}