//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {
    char text[1000];
    printf("Enter text: ");
    fgets(text, 1000, stdin);
    text[strcspn(text, "\n")] = 0; // remove newline character

    int length = strlen(text);

    int i, j;
    for (i = 0; i < length; i++) {
        switch (text[i]) {
            case 'A':
                printf("         /\\     \n");
                printf("        /  \\    \n");
                printf("       / /\\ \\   \n");
                printf("      / /\\ \\ \\  \n");
                printf("     / /--\\ \\ \\ \n");
                printf("    / /    \\ \\_\\\n");
                printf("   /_/      \\/_/ \n");
                break;
            case 'B':
                printf("   _______     \n");
                printf("  |  ___  \\    \n");
                printf("  | |___| |    \n");
                printf("  |  ___  |    \n");
                printf("  | |   | |    \n");
                printf("  |_|   |_|    \n");
                break;
            case 'C':
                printf("     ____     \n");
                printf("   / ___ \\   \n");
                printf("  / /   \\ \\  \n");
                printf("  \\ \\___/ /  \n");
                printf("   \\_____/   \n");
                break;
            case 'D':
                printf("  _______     \n");
                printf(" |  ___  \\    \n");
                printf(" | |   | |    \n");
                printf(" | |   | |    \n");
                printf(" | |___| |    \n");
                printf(" |_______|    \n");
                break;
            case 'E':
                printf("  _______ \n");
                printf(" |  ____ \\\n");
                printf(" | |___| /\n");
                printf(" |  ___  \\\n");
                printf(" | |   \\  \\\n");
                printf(" |_|    \\__\\\n");
                break;
            case 'F':
                printf("  _______ \n");
                printf(" |  ____ \\\n");
                printf(" | |___| /\n");
                printf(" |  ___  \\\n");
                printf(" | |      \n");
                printf(" |_|      \n");
                break;
            case 'G':
                printf("     __      \n");
                printf("   / ___\\    \n");
                printf("  / /   ____ \n");
                printf("  | |   |___| \n");
                printf("  \\ \\___ ___/ \n");
                printf("   \\____|     \n");
                break;
            case 'H':
                printf("  __      __ \n");
                printf(" |  \\    /  |\n");
                printf(" |   \\  /   |\n");
                printf(" | |\\ \\/ /| |\n");
                printf(" | | \\  / | |\n");
                printf(" |_|  \\/  |_| \n");
                break;
            case 'I':
                printf("  _______ \n");
                printf(" |_   __ \\ \n");
                printf("   | |__) |\n");
                printf("   |  ___/\n");
                printf("  _| |_   \n");
                printf(" |_____|  \n");
                break;
            case 'J':
                printf("       __ \n");
                printf("      /  |\n");
                printf("      | |\n");
                printf("  _   | |\n");
                printf(" | |__| |\n");
                printf("  \\____/ \n");
                break;
            case 'K':
                printf("  __      __\n");
                printf(" |  \\    /  |\n");
                printf(" |   \\  /   |\n");
                printf(" | |\\ \\/ /| |\n");
                printf(" | | \\  / | |\n");
                printf(" |_|  \\/  |_| \n");
                break;
            case 'L':
                printf("  __       \n");
                printf(" |  |      \n");
                printf(" | |       \n");
                printf(" | |       \n");
                printf(" | |___    \n");
                printf(" |_____|  \n");
                break;
            case 'M':
                printf("  __  __ \n");
                printf(" |  \\/  |\n");
                printf(" | \\  / |\n");
                printf(" | |\\/| |\n");
                printf(" | |  | |\n");
                printf(" |_|  |_| \n");
                break;
            case 'N':
                printf("  _   __ \n");
                printf(" | \\ |  |\n");
                printf(" |  \\|  |\n");
                printf(" | |\\   |\n");
                printf(" | | \\  |\n");
                printf(" |_|  \\_| \n");
                break;
            case 'O':
                printf("     __      \n");
                printf("   / ___\\    \n");
                printf("  / /   \\ \\  \n");
                printf("  | |   | |  \n");
                printf("  \\ \\___/ /  \n");
                printf("   \\_____/   \n");
                break;
            case 'P':
                printf("  _______ \n");
                printf(" |  ____ \\\n");
                printf(" | |___| /\n");
                printf(" |  ___  \n");
                printf(" | |      \n");
                printf(" |_|      \n");
                break;
            case 'Q':
                printf("     __      \n");
                printf("   / ___\\    \n");
                printf("  / /   \\ \\  \n");
                printf("  | |   | |  \n");
                printf("  \\ \\___/ /  \n");
                printf("   \\_____\\_\\ \n");
                break;
            case 'R':
                printf("  _______ \n");
                printf(" |  ____ \\\n");
                printf(" | |___| /\n");
                printf(" |  ___  \\\n");
                printf(" | |   | |\n");
                printf(" |_|   |_| \n");
                break;
            case 'S':
                printf("    _____ \n");
                printf("  / ____|\n");
                printf(" | |__    \n");
                printf("  \\__\\   \n");
                printf("      | | \n");
                printf("       |_| \n");
                break;
            case 'T':
                printf("  _______ \n");
                printf(" |_   __ \\\n");
                printf("   | |__) |\n");
                printf("   |  ___/\n");
                printf("   _| |    \n");
                printf("  |_____|  \n");
                break;
            case 'U':
                printf("  __    __ \n");
                printf(" |  |  |  |\n");
                printf(" |  |__|  |\n");
                printf(" |   __   |\n");
                printf(" |  |  |  |\n");
                printf(" |_|  |_| \n");
                break;
            case 'V':
                printf("  __      __ \n");
                printf(" |  \\    /  |\n");
                printf(" |   \\  /   |\n");
                printf(" |    \\/    |\n");
                printf(" | |\\  /|  |\n");
                printf(" |_| \\/ |_| \n");
                break;
            case 'W':
                printf("  __      __      \n");
                printf(" |  \\    /  | \n");
                printf(" |   \\  /   | \n");
                printf(" | |\\ \\/ /| | \n");
                printf(" | | \\  / | | \n");
                printf(" |_|  \\/  |_| \n");
                break;
            case 'X':
                printf("  __      __ \n");
                printf(" \\  \\    /  /\n");
                printf("  \\  \\  /  / \n");
                printf("   \\  \\/  /  \n");
                printf("   /  /\\  \\  \n");
                printf("  /__/  \\__\\ \n");
                break;
            case 'Y':
                printf("  __      __ \n");
                printf(" |  \\    /  |\n");
                printf("  \\  \\  /  / \n");
                printf("   \\  \\/  /  \n");
                printf("    \\   /   \n");
                printf("     \\_/    \n");
                break;
            case 'Z':
                printf("  ________ \n");
                printf(" |_   __  |\n");
                printf("   | |__) |\n");
                printf("   |  ___/\n");
                printf("  _| |    \n");
                printf(" |_____|    \n");
                break;
            case ' ':
                printf("   \n");
                break;
            default:
                printf("Letter not supported!\n");
                return 0;
        }
    }

    return 0;
}