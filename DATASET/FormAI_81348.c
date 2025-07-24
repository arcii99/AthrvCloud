//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    printf("Enter a message to convert to ASCII art:\n");
    fgets(input, 100, stdin);

    int i, j;
    for (i = 0; input[i] != '\0'; ++i) {
        for (j = 0; j < 5; ++j) {
            switch(input[i]) {
                case 'A':
                    printf("   /\\   \n");
                    printf("  /  \\  \n");
                    printf(" /    \\ \n");
                    printf("/------\\\n");
                    printf("/        \n");
                    break;
                case 'B':
                    printf("------\\\n");
                    printf("|      \n");
                    printf("------\\\n");
                    printf("|      \\\n");
                    printf("------/\n");
                    break;
                case 'C':
                    printf("  /----\n");
                    printf(" /     \n");
                    printf("/      \n");
                    printf("\\      \n");
                    printf(" \\----\n");
                    break;
                case 'D':
                    printf("------\\\n");
                    printf("|     \\ \n");
                    printf("|      \\\n");
                    printf("|     / \n");
                    printf("------/\n");
                    break;
                case 'E':
                    printf("------\n");
                    printf("|     \n");
                    printf("------\n");
                    printf("|     \n");
                    printf("------\n");
                    break;
                case 'F':
                    printf("------\n");
                    printf("|     \n");
                    printf("------\n");
                    printf("|     \n");
                    printf("|     \n");
                    break;
                case 'G':
                    printf("  /----\n");
                    printf(" |      \n");
                    printf(" |  ---\\\n");
                    printf(" |     |\n");
                    printf("  \\---/\n");
                    break;
                case 'H':
                    printf("|      |\n");
                    printf("|------|\n");
                    printf("|      |\n");
                    printf("|      |\n");
                    printf("|      |\n");
                    break;
                case 'I':
                    printf("------\n");
                    printf("  |   \n");
                    printf("  |   \n");
                    printf("  |   \n");
                    printf("------\n");
                    break;
                case 'J':
                    printf("  ------\n");
                    printf("      | \n");
                    printf("      | \n");
                    printf("\\     | \n");
                    printf(" \\---/  \n");
                    break;
                case 'K':
                    printf("|     /\n");
                    printf("|  _/  \n");
                    printf("| /    \n");
                    printf("| \\    \n");
                    printf("|  \\_  \n");
                    break;
                case 'L':
                    printf("|     \n");
                    printf("|     \n");
                    printf("|     \n");
                    printf("|     \n");
                    printf("------\n");
                    break;
                case 'M':
                    printf("\\      / \n");
                    printf(" \\    /  \n");
                    printf("  \\  /   \n");
                    printf("   \\/    \n");
                    printf("   /\\    \n");
                    break;
                case 'N':
                    printf("|\\     |\n");
                    printf("| \\    |\n");
                    printf("|  \\   |\n");
                    printf("|   \\  |\n");
                    printf("|    \\ |\n");
                    break;
                case 'O':
                    printf("  /---\\\n");
                    printf(" /     \\\n");
                    printf("/       \\\n");
                    printf("\\       /\n");
                    printf(" \\     /\n");
                    printf("  \\---/\n");
                    break;
                case 'P':
                    printf("------\\\n");
                    printf("|      \\\n");
                    printf("------/\n");
                    printf("|      \n");
                    printf("|      \n");
                    break;
                case 'Q':
                    printf("  /---\\\n");
                    printf(" /     \\\n");
                    printf("/       \\\n");
                    printf("\\       /\n");
                    printf(" \\  /\\ \n");
                    printf("  \\/  \\\n");
                    break;
                case 'R':
                    printf("------\\\n");
                    printf("|      \\\n");
                    printf("------/\n");
                    printf("| \\    \n");
                    printf("|  \\_  \n");
                    break;
                case 'S':
                    printf("  /----\n");
                    printf(" /     \n");
                    printf(" \\-----\\\n");
                    printf("       |\n");
                    printf("\\----/  \n");
                    break;
                case 'T':
                    printf("------\n");
                    printf("  |   \n");
                    printf("  |   \n");
                    printf("  |   \n");
                    printf("  |   \n");
                    break;
                case 'U':
                    printf("|      |\n");
                    printf("|      |\n");
                    printf("|      |\n");
                    printf("\\      /\n");
                    printf(" \\----/ \n");
                    break;
                case 'V':
                    printf("\\      /\n");
                    printf(" \\    / \n");
                    printf("  \\  /  \n");
                    printf("   \\/   \n");
                    printf("    |   \n");
                    break;
                case 'W':
                    printf("\\      / \n");
                    printf(" \\    /  \n");
                    printf("  \\  /   \n");
                    printf("   \\/    \n");
                    printf("   /\\    \n");
                    printf("  /  \\   \n");
                    printf(" /    \\  \n");
                    break;
                case 'X':
                    printf("\\     /\n");
                    printf(" \\   / \n");
                    printf("  \\ /  \n");
                    printf("  / \\  \n");
                    printf(" /   \\ \n");
                    break;
                case 'Y':
                    printf("\\     /\n");
                    printf(" \\   / \n");
                    printf("  \\ /  \n");
                    printf("   |   \n");
                    printf("   |   \n");
                    break;
                case 'Z':
                    printf("------\n");
                    printf("    / \n");
                    printf("   /  \n");
                    printf("  /   \n");
                    printf("------\n");
                    break;
                case ' ':
                    printf("     \n");
                    printf("     \n");
                    printf("     \n");
                    printf("     \n");
                    printf("     \n");
                    break;
                default:
                    printf("Error: Invalid character in input.");
                    return 1;
            }
        }
        printf("\n");
    }

    return 0;
}