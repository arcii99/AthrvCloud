//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: expert-level
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to print ASCII art for each character
void printAsciiArt(char character) {
    switch(character) {
        case 'A':
            printf("    /\\ \n");
            printf("   /  \\ \n");
            printf("  /    \\ \n");
            printf(" /------\\ \n");
            printf("/        \\\n");
            break;
        case 'B':
            printf(" -------\n");
            printf("|         \\\n");
            printf(" -------\n");
            printf("|         \\\n");
            printf(" -------\n");
            break;
        case 'C':
            printf("  /----\\ \n");
            printf("/        \\\n");
            printf("|         \n");
            printf("\\        /\n");
            printf("  ----/\n");
            break;
        case 'D':
            printf(" ------\\\n");
            printf("|        \\\n");
            printf("|        /\n");
            printf(" ------/\n");
            break;
        case 'E':
            printf(" -------\n");
            printf("|         \n");
            printf(" ------\n");
            printf("|         \n");
            printf(" -------\n");
            break;
        case 'F':
            printf(" -------\n");
            printf("|         \n");
            printf(" ------\n");
            printf("|         \n");
            printf("|         \n");
            break;
        case 'G':
            printf("  /----\\ \n");
            printf("/        \\\n");
            printf("|     ---\n");
            printf("\\       /\n");
            printf("  ----/\n");
            break;
        case 'H':
            printf("|        |\n");
            printf("|--------|\n");
            printf("|        |\n");
            printf("|        |\n");
            break;
        case 'I':
            printf(" -------\n");
            printf("    |    \n");
            printf("    |    \n");
            printf("    |    \n");
            printf(" -------\n");
            break;
        case 'J':
            printf("     -------\n");
            printf("         |    \n");
            printf("         |    \n");
            printf("\\        |    \n");
            printf("  ------/    \n");
            break;
        case 'K':
            printf("|       /\n");
            printf("|      /\n");
            printf("|-----/\n");
            printf("|      \\\n");
            printf("|       \\\n");
            break;
        case 'L':
            printf("|         \n");
            printf("|         \n");
            printf("|         \n");
            printf("|         \n");
            printf(" -------\n");
            break;
        case 'M':
            printf("|\\      /|\n");
            printf("| \\    / |\n");
            printf("|  \\  /  |\n");
            printf("|   \\/   |\n");
            break;
        case 'N':
            printf("|\\      |\n");
            printf("| \\     |\n");
            printf("|  \\    |\n");
            printf("|   \\   |\n");
            printf("|    \\  |\n");
            printf("|     \\ |\n");
            printf("|      \\\n");
            break;
        case 'O':
            printf("  /----\\ \n");
            printf("/        \\\n");
            printf("|        |\n");
            printf("\\        /\n");
            printf("  ----/\n");
            break;
        case 'P':
            printf(" -------\n");
            printf("|        |\n");
            printf(" -------\n");
            printf("|         \n");
            printf("|         \n");
            break;
        case 'Q':
            printf("  /----\\ \n");
            printf("/        \\\n");
            printf("|        |\n");
            printf("\\       / \n");
            printf("  ----/  -\n");
            break;
        case 'R':
            printf(" -------\n");
            printf("|        |\n");
            printf(" -------\n");
            printf("|       \\ \n");
            printf("|        -\\\n");
            break;
        case 'S':
            printf(" -------\n");
            printf("|         \n");
            printf(" -------\n");
            printf("         |\n");
            printf(" -------\n");
            break;
        case 'T':
            printf(" -------\n");
            printf("    |    \n");
            printf("    |    \n");
            printf("    |    \n");
            printf("    |    \n");
            break;
        case 'U':
            printf("|        |\n");
            printf("|        |\n");
            printf("|        |\n");
            printf("\\       /\n");
            printf("  ----/\n");
            break;
        case 'V':
            printf("|        |\n");
            printf("\\        /\n");
            printf(" \\      /\n");
            printf("  \\    /\n");
            printf("   \\  /\n");
            printf("    \\/\n");
            break;
        case 'W':
            printf("|        |\n");
            printf("|        |\n");
            printf("|   /\\   |\n");
            printf("|  /  \\  |\n");
            printf("| /    \\ |\n");
            printf("|/      \\|\n");
            break;
        case 'X':
            printf("\\       /\n");
            printf(" \\     /\n");
            printf("  \\   /\n");
            printf("   \\ /\n");
            printf("  / \\ \n");
            printf(" /   \\\n");
            printf("/     \\\n");
            break;
        case 'Y':
            printf("\\       /\n");
            printf(" \\     /\n");
            printf("  \\   /\n");
            printf("   | |\n");
            printf("   | |\n");
            break;
        case 'Z':
            printf(" -------\n");
            printf("      / \n");
            printf("    /   \n");
            printf("  /     \n");
            printf(" -------\n");
            break;
        default:
            printf("Invalid character!\n");
    }
}

int main() {
    char input[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    for(int i=0; i<strlen(input); i++) {
        printAsciiArt(input[i]);
    }

    return 0;
}