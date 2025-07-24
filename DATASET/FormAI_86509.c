//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

// Function to generate ASCII art from text
void generateAsciiArt(char *text) {
    int len = strlen(text);

    // Print the ASCII art based on the given text
    printf("\n        .-. \t         .-.\n");
    printf("       /   \\ \t        /   \\\n");
    printf("      /     \\ \t       /     \\\n");
    printf("     /       \\ \t      /       \\\n");
    printf("    /         \\ \t     /         \\\n");
    printf("   /-----------\\ \t    /-----------\\\n");
    printf("  /             \\ \t   /             \\\n");
    printf(" /               \\ \t  /               \\\n");

    for (int i = 0; i < len; i++) {
        switch(text[i]) {
            case 'a':
            case 'A':
                printf("|  /\\     /\\  |\t |      /\\      |\n");
                printf("| /  \\   /  \\ |\t |     /  \\     |\n");
                printf("|/    \\_/    \\|\t|    /    \\    |   \n");
                break;
            case 'b':
            case 'B':
                printf("|--------\\   |\t|---\\  |----\\  |\n");
                printf("|         \\  |\t|    \\ |     | |\n");
                printf("|--------/   |\t|     ||----/  |\n");
                break;
            case 'c':
            case 'C':
                printf("|\\         | |\t |\\           |\n");
                printf("| \\        | |\t | \\          |\n");
                printf("|  \\       | |\t |  \\         |\n");
                printf("|   -------  |\t |   ---------|\n");
                break;
            case 'd':
            case 'D':
                printf("|--------\\   |\t|---\\  |-----\\ |\n");
                printf("|         |   |\t|    | |      ||\n");
                printf("|--------/   |\t|    | |------/\n");
                break;
            case 'e':
            case 'E':
                printf("|----------| |\t|----------|\n");
                printf("|          | |\t|          |\n");
                printf("|          |-|\t|------\\   |\n");
                printf("|----------| |\t|-------\\  |\n");
                break;
            case 'f':
            case 'F':
                printf("|----------| |\t|----------|\n");
                printf("|          | |\t|          |\n");
                printf("|          |-|\t|------\\   |\n");
                printf("|          | |\t|       \\  |\n");
                break;
            case 'g':
            case 'G':
                printf("|\\          | |\t |\\           |\n");
                printf("| \\         | |\t | \\          |\n");
                printf("|  \\    ----| |\t |  \\    ----|\n");
                printf("|   ------- | |\t |   ------- |\n");
                break;
            case 'h':
            case 'H':
                printf("|      /\\   | |\t|    /\\     |\n");
                printf("|     /  \\  | |\t|   /  \\    |\n");
                printf("|-----/----\\-| |\t|  /----\\---|\n");
                printf("|     \\    / | |\t| /      \\  |\n");
                printf("|      \\  /  | |\t|/        \\ |\n");
                break;
            case 'i':
            case 'I':
                printf("   /\\       |\t    /\\      |\n");
                printf("  /  \\      |\t   /  \\     |\n");
                printf(" /----\\     |\t  /    \\    |\n");
                printf("|      |    |\t |      |   |\n");
                printf("|      |    |\t |      |   |\n");
                break;
            case 'j':
            case 'J':
                printf("     /\\     |\t     /\\    |\n");
                printf("    /  \\    |\t    /  \\   |\n");
                printf("   /----\\   |\t   /    \\  |\n");
                printf("  |      |  |\t  |      |  |\n");
                printf("  |-----/   |\t  |-----/|  |\n");
                break;
            case 'k':
            case 'K':
                printf("|     /\\    | |\t|    / /    |\n");
                printf("|   /   \\   | |\t|   / /     |\n");
                printf("|----\\----\\-|-|\t|  / /      |\n");
                printf("|    /\\    \\ | |\t| / /       |\n");
                printf("|   /  \\    \\| |\t|/ /        |\n");
                break;
            case 'l':
            case 'L':
                printf("|            |\t|            |\n");
                printf("|            |\t|            |\n");
                printf("|            |\t|            |\n");
                printf("|            |\t|     -----  |\n");
                break;
            case 'm':
            case 'M':
                printf("|\\        /\\ |\t|\\   /\\   /\\ |\n");
                printf("| \\      /  \\|\t| \\ /  \\ /  \\|\n");
                printf("|  \\----/----\\\t|  /----X----\\\n");
                printf("|  /    \\    /|\t| / \\  / \\  /|\n");
                printf("| /      \\  / | |\t|/   \\/   \\/ |\n");
                break;
            case 'n':
            case 'N':
                printf("|\\      |   | |\t|\\     |   /|\n");
                printf("| \\     |\\  | |\t| \\    |  / |\n");
                printf("|  \\    | \\ | |\t|  \\   | /  |\n");
                printf("|   \\   |  \\| |\t|   \\  |/   |\n");
                printf("|    \\  |   | |\t|    \\ |    |\n");
                break;
            case 'o':
            case 'O':
                printf("|-----------| |\t|-----------|\n");
                printf("|           | |\t|           |\n");
                printf("|           | |\t|           |\n");
                printf("|           | |\t|           |\n");
                printf("|-----------| |\t|-----------|\n");
                break;
            case 'p':
            case 'P':
                printf("|--------\\   |\t|----\\  |----|\n");
                printf("|         \\  |\t|     | |    |\n");
                printf("|--------/   |\t|----/  |----|\n");
                printf("|            |\t|           |\n");
                break;
            case 'q':
            case 'Q':
                printf("|-----------| |\t|-----------|\n");
                printf("|           | |\t|           |\n");
                printf("|           | |\t|           |\n");
                printf("|--\\    /---| |\t|---\\    /---|\n");
                printf("   \\    /    | |\t   \\    /    |\n");
                break;
            case 'r':
            case 'R':
                printf("|--------\\   |\t|----\\  |----|\n");
                printf("|         \\  |\t|     | |    |\n");
                printf("|--------/   |\t|----/  |\\   |\n");
                printf("|\\           |\t|       |/   |\n");
                break;
            case 's':
            case 'S':
                printf("  /----|-----|-\t |-----------|\n");
                printf(" |     |-----|-\t|-----------/ \n");
                printf("  \\----|-----|-\t|-----------\\ \n");
                break;
            case 't':
            case 'T':
                printf("|----------| |\t|----------|\n");
                printf("|          | |\t|          |\n");
                printf("|          |-|\t|------\\   |\n");
                printf("|          | |\t|       |  |\n");
                break;
            case 'u':
            case 'U':
                printf("|      /\\   | |\t|    /\\     |\n");
                printf("|     /  \\  | |\t|   /  \\    |\n");
                printf("|    /    \\ | |\t|  /    \\   |\n");
                printf("| |\\/      \\|-|\t| /      \\  |\n");
                printf("|/          \\ |\t|/        \\ |\n");
                break;
            case 'v':
            case 'V':
                printf("\\        /   /|\t \\  /\\  /\\  /\n");
                printf(" \\      /   / |\t   \\/  \\/  \\/\n");
                printf("  \\----/   /  |\t    \\  /\\  /\n");
                printf("         /   / | \t     \\/  \\/\n");
                printf("        /___/  |_|\n");
                break;
            case 'w':
            case 'W':
                printf("\\        /   /|\t \\ /   /\\   /\\ / \n");
                printf(" \\      /   / |\t  /   /  \\ /  \\  \n");
                printf("  \\    /   /  /|\t /___/ /\\ /\\   \\ \n");
                printf("   \\--/   /   / |\t|   |/   Y   \\  \n");
                printf("        /___/  /  | |   |    |   | \n");
                printf("       |   | \\_/-~   |   |   /    |\n");
                printf("       |   |        |   |  /     |\n");
                printf("       |   |        |  | /    \\/\n");
                printf("       |  |         |  |/\\    /\\\n");
                printf("       \\__/         /__/  \\__/\\\n");
                break;
            case 'x':
            case 'X':
                printf("\\          / |\t \\       /\n");
                printf(" \\       /  / |\t   \\   /\n");
                printf("   \\   /  /  / |\t    \\ /\n");
                printf("    \\ /  /  /  |\t    / \\\n");
                printf("     /  /  /   |_/ \t   /   \\\n");
                printf("    /  /  /   /    \t  /     \\ \n");
                break;
            case 'y':
            case 'Y':
                printf("\\          / |\t \\       /\n");
                printf(" \\       /  / |\t   \\   /\n");
                printf("   \\   /  /  / |\t    \\ /\n");
                printf("    \\ /  /  /  |\t    ||\n");
                printf("     /  / |||    \t   || \n");
                printf("    /  /   \\     \t  //   \n");
                printf("            \\    \t |/ \n");
                printf("             o   \t o  \n");
                break;
            case 'z':
            case 'Z':
                printf("--------|--- \t|--------/ \n");
                printf("         |    \t|  -----/   \n");
                printf("        /     \t| /----/     \n");
                printf("  -----/      \t|/____/      \n");
                break;
            case ' ':
                printf("               \t              \n");
                printf("               \t              \n");
                printf("               \t              \n");
                break;
            default:
                printf("Error: Invalid character '%c'\n", text[i]);
                break;
        }
    }
}

int main() {
    char text[] = "Romeo and Juliet"; // The text to be converted into ASCII art

    generateAsciiArt(text); // Call the ASCII art generator function

    return 0;
}