//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: shocked
#include <stdio.h>

int main() {
    char input[100];
    printf("Enter a word or phrase: ");
    fgets(input, 100, stdin);

    for(int i = 0; i < strlen(input); i++) {
        switch(input[i]) {
            case 'a':
                printf("   /\\ \n");
                printf("  /  \\\n");
                printf(" /____\\ \n");
                break;
            case 'b':
                printf(" ____\n");
                printf("| ___ \\\n");
                printf("| |_/ /\n");
                printf("|  __/\n");
                printf("| |\n");
                printf("|_| ");
                break;
            case 'c':
                printf("  ____ \n");
                printf(" / ___|\n");
                printf("| |\n");
                printf("| |___\n");
                printf(" \\____|\n");
                break;
            case 'd':
                printf(" ____ \n");
                printf("|  _ \\\n");
                printf("| | | |\n");
                printf("| |_| |\n");
                printf("|____/ \n");
                break;
            case 'e':
                printf(" ____\n");
                printf("|  _ \\\n");
                printf("| |_) |\n");
                printf("|  _ <\n");
                printf("|_| \\_\\\n");
                break;
            case 'f':
                printf(" _____\n");
                printf("|  ___|\n");
                printf("| |_   \n");
                printf("|  _|  \n");
                printf("|_|    \n");
                break;
            case 'g':
                printf("  ____\n");
                printf(" / ___|\n");
                printf("| |  _ \n");
                printf("| |_| |\n");
                printf(" \\____|\n");
                break;
            case 'h':
                printf(" _    _\n");
                printf("| |  | |\n");
                printf("| |__| |\n");
                printf("|  __  |\n");
                printf("| |  | |\n");
                printf("|_|  |_|\n");
                break;
            case 'i':
                printf(" _____\n");
                printf("|_   _|\n");
                printf("  | |\n");
                printf("  | |\n");
                printf(" _| |_\n");
                printf("|_____|\n");
                break;
            case 'j':
                printf("     _\n");
                printf("    | |\n");
                printf("    | |\n");
                printf(" _  | |\n");
                printf("| |_| |\n");
                printf(" \\___/ \n");
                break;
            case 'k':
                printf(" _  __\n");
                printf("| |/ /\n");
                printf("| ' / \n");
                printf("| . \\ \n");
                printf("|_|\\_\\\n");
                break;
            case 'l':
                printf(" _\n");
                printf("| |\n");
                printf("| |\n");
                printf("| |\n");
                printf("|_| \n");
                break;
            case 'm':
                printf(" __  __ \n");
                printf("|  \\/  |\n");
                printf("| \\  / |\n");
                printf("| |\\/| |\n");
                printf("| |  | |\n");
                printf("|_|  |_|\n");
                break;
            case 'n':
                printf(" _   _ \n");
                printf("| \\ | |\n");
                printf("|  \\| |\n");
                printf("| . ` |\n");
                printf("|_|\\__|\n");
                break;
            case 'o':
                printf("  ____\n");
                printf(" / ___\\\n");
                printf("| |__  \n");
                printf("| '_ \\ \n");
                printf("| |_) |\n");
                printf(" \\____|\n");
                break;
            case 'p':
                printf(" ____ \n");
                printf("| ___\\\n");
                printf("| |__ \n");
                printf("|  __|\n");
                printf("| |   \n");
                printf("|_|   \n");
                break;
            case 'q':
                printf("  ____ \n");
                printf(" / ___\\\n");
                printf("| |  _ \n");
                printf("| |_| |\n");
                printf(" \\____|\n");
                printf("    (_) \n");
                break;
            case 'r':
                printf(" ____\n");
                printf("| ___\\\n");
                printf("| |___\n");
                printf("|    \\\n");
                printf("| |\\  \\\n");
                printf("|_| \\_|\n");
                break;
            case 's':
                printf(" ____\n");
                printf("/ ___\\\n");
                printf("\\___ \\\n");
                printf(" ___) |\n");
                printf("|____/ \n");
                break;
            case 't':
                printf(" _____\n");
                printf("|_   _|\n");
                printf("  | |  \n");
                printf("  | |  \n");
                printf(" _| |_ \n");
                printf("|_____|\n");
                break;
            case 'u':
                printf(" _   _\n");
                printf("| | | |\n");
                printf("| | | |\n");
                printf("| |_| |\n");
                printf(" \\___/ \n");
                break;
            case 'v':
                printf(" _   _\n");
                printf("| | | |\n");
                printf("| | | |\n");
                printf("| |_| |\n");
                printf(" \\___/ \n");
                printf("       \n");
                break;
            case 'w':
                printf(" _    _\n");
                printf("| |  | |\n");
                printf("| |  | |\n");
                printf("| |/\\| |\n");
                printf("\\  /\\  /\n");
                printf(" \\/  \\/ \n");
                break;
            case 'x':
                printf("__   __\n");
                printf("\\ \\ / /\n");
                printf(" \\ V / \n");
                printf("  | |  \n");
                printf("  |_|  \n");
                break;
            case 'y':
                printf(" _   _\n");
                printf("| | | |\n");
                printf("| |_| |\n");
                printf(" \\__, |\n");
                printf("    |_|\n");
                break;
            case 'z':
                printf(" _____\n");
                printf("|___ / \n");
                printf("  |_ \\\n");
                printf(" ___) |\n");
                printf("|____/ \n");
                break;
            case ' ':
                printf("\n");
                break;
            default:
                printf("Invalid character entered. Please try again.\n");
        }
    }
    return 0;
}