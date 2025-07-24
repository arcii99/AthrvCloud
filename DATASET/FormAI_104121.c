//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: realistic
#include <stdio.h> 

int main() {

    char input[100];
    printf("Enter text: ");
    fgets(input, 100, stdin);
    printf("\n");

    for(int i = 0; i < strlen(input); i++) {
        switch (input[i]) {
            case 'a':
                printf("     /\\     \n");
                printf("    /  \\    \n");
                printf("   /----\\   \n");
                printf("  /      \\  \n");
                printf(" /        \\ \n");
                break;
            case 'b':
                printf(" |--------\\ \n");
                printf(" |         |\n");
                printf(" |-------/ \n");
                printf(" |        \\ \n");
                printf(" |--------\\\n");
                break;
            case 'c':
                printf("   -------  \n");
                printf(" /         \\\n");
                printf("|           \n");
                printf("|           \n");
                printf(" \\         /\n");
                printf("   -------  \n");
                break;
            case 'd':
                printf(" |--------\\ \n");
                printf(" |         |\n");
                printf(" |         |\n");
                printf(" |         |\n");
                printf(" |--------/\n");
                break;
            case 'e':
                printf(" |-------- \n");
                printf(" |         \n");
                printf(" |-------- \n");
                printf(" |         \n");
                printf(" |-------- \n");
                break;
            case 'f':
                printf(" |-------- \n");
                printf(" |         \n");
                printf(" |-------- \n");
                printf(" |         \n");
                printf(" |         \n");
                break;
            case 'g':
                printf("   -------  \n");
                printf(" /         \\\n");
                printf("|    -----\n");
                printf("|        | \n");
                printf(" \\        |\n");
                printf("   ------- \n");
                break;
            case 'h':
                printf(" |         |\n");
                printf(" |         |\n");
                printf(" |-------- \n");
                printf(" |         |\n");
                printf(" |         |\n");
                break;
            case 'i':
                printf("   /\\     \n");
                printf("   ||     \n");
                printf("   ||     \n");
                printf("   ||     \n");
                printf("   ||     \n");
                break;
            case 'j':
                printf("         /\\\n");
                printf("         ||\n");
                printf("         ||\n");
                printf(" |------||\n");
                printf(" |_____//|\\\n");
                break;
            case 'k':
                printf(" |       /\n");
                printf(" |     //  \n");
                printf(" |----'     \n");
                printf(" |     \\\\  \n");
                printf(" |       \\\n");
                break;
            case 'l':
                printf(" |         \n");
                printf(" |         \n");
                printf(" |         \n");
                printf(" |         \n");
                printf(" |-------- \n");
                break;
            case 'm':
                printf(" /\\       /\\ \n");
                printf("/  \\_____/  \\\n");
                printf("|            |\n");
                printf("|            |\n");
                printf("|            |\n");
                break;
            case 'n':
                printf(" /\\        \\\n");
                printf("/  \\        \\\n");
                printf("|   \\        \\\n");
                printf("|    \\        \\\n");
                printf("|       \\     /\n");
                break;
            case 'o':
                printf("   -------  \n");
                printf(" /         \\\n");
                printf("|           |\n");
                printf("|           |\n");
                printf(" \\         /\n");
                printf("   -------  \n");
                break;
            case 'p':
                printf(" |--------\\ \n");
                printf(" |         |\n");
                printf(" |--------/\n");
                printf(" |         \n");
                printf(" |         \n");
                break;
            case 'q':
                printf("   -------  \n");
                printf(" /         \\\n");
                printf("|           |\n");
                printf("|           |\n");
                printf(" \\        / \n");
                printf("   -----\\   \n");
                break;
            case 'r':
                printf(" |------\\  \n");
                printf(" |       |  \n");
                printf(" |------/  \n");
                printf(" | \\\\      \n");
                printf(" |   \\\\    \n");
                break;
            case 's':
                printf("   -------  \n");
                printf(" /         \n");
                printf("  -----|  \n");
                printf("        \\\n");
                printf("\\        \\ \n");
                printf("  -------\n");
                break;
            case 't':
                printf("  ---------\n");
                printf("      |     \n");
                printf("      |     \n");
                printf("      |     \n");
                printf("      |     \n");
                break;
            case 'u':
                printf(" |         |\n");
                printf(" |         |\n");
                printf(" |         |\n");
                printf("  \\        /\n");
                printf("    ------\n");
                break;
            case 'v':
                printf(" \\          /\n");
                printf("   \\      /\n");
                printf("     \\  /\n");
                printf("       |\n");
                printf("       |\n");
                break;
            case 'w':
                printf("/           \\\n");
                printf("\\         /\n");
                printf(" \\       /\n");
                printf("  \\     /\n");
                printf("    ---\n");
                break;
            case 'x':
                printf(" \\       /\n");
                printf("   \\   /\n");
                printf("     \\ \n");
                printf("   /   \\\n");
                printf(" /       \\\n");
                break;
            case 'y':
                printf(" \\       /\n");
                printf("   \\   /\n");
                printf("     \\/\n");
                printf("     |\n");
                printf("     |\n");
                break;
            case 'z':
                printf("  -------\n");
                printf("         /\n");
                printf("        /\n");
                printf("       /\n");
                printf("  ------\n");
                break;
            default:
                printf("  \n");
                printf("  \n");
                printf("  \n");
                printf("  \n");
                printf("  \n");
        }
    }

    return 0;
}