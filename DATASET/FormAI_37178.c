//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: light-weight
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; i < strlen(input); i++) {
        switch(input[i]) {
            case 'a':
                printf("  __  \n /  \\ \n/__\\_\\\n");
                break;
            case 'b':
                printf(" ____ \n| __ )\n|  _ \\\n| |_) |\n|____/\n");
                break;
            case 'c':
                printf("  ___ \n / __\\ \n/ /   \\\n\\ \\___\n \\____/\n");
                break;
            case 'd':
                printf(" ____  \n|  _ \\ \n| | | |\n| |_| |\n|____/ \n");
                break;
            case 'e':
                printf(" _____\n| ____|\n|  _|  \n| |___ \n|_____|\n");
                break;
            case 'f':
                printf(" _____\n|  ___|\n| |_   \n|  _|  \n|_|    \n");
                break;
            case 'g':
                printf("  ___\n / _ \\ \n| (_) |\n > _ < \n/_/ \\_\\\n");
                break;
            case 'h':
                printf(" _   _ \n| | | |\n| |_| |\n|  _  |\n|_| |_|\n");
                break;
            case 'i':
                printf(" ___ \n|_ _| \n | |  \n | |  \n|___|\n");
                break;
            case 'j':
                printf("    _ \n _ | |\n| || |\n| || |_\n|_/|_|\n");
                break;
            case 'k':
                printf(" _  __\n| |/ /\n| ' / \n| . \\ \n|_|\\_\\\n");
                break;
            case 'l':
                printf(" _     \n| |    \n| |    \n| |___ \n|_____|\n");
                break;
            case 'm':
                printf(" __  __\n|  \\/  |\n| |\\/| |\n| |  | |\n|_|  |_|\n");
                break;
            case 'n':
                printf(" _   _ \n| \\ | |\n|  \\| |\n| |\\  |\n|_| \\_|\n");
                break;
            case 'o':
                printf("  ___ \n / _ \\ \n| | | |\n| |_| |\n \\___/ \n");
                break;
            case 'p':
                printf(" ____ \n|  _ \\ \n| |_) |\n|  _ < \n|_| \\_\\\n");
                break;
            case 'q':
                printf("  ___ \n / _ \\ \n| | | |\n| |/ / \n|___\\_\\\n");
                break;
            case 'r':
                printf(" ____\n|  _ \\\n| |_) |\n|  _ <\n|_| \\_\\\n");
                break;
            case 's':
                printf("  ____\n / ___|\n| |    \n| |___ \n \\____|\n");
                break;
            case 't':
                printf(" _____\n|_   _|\n  | |  \n  | |  \n  |_|  \n");
                break;
            case 'u':
                printf(" _   _ \n| | | |\n| | | |\n| |_| |\n \\___/ \n");
                break;
            case 'v':
                printf(" _    _\n| |  | |\n| |  | |\n| |  | |\n \\__/  \n");
                break;
            case 'w':
                printf(" _    _ \n| |  | |\n| |  | |\n| |/\\| |\n|__/\\__|\n");
                break;
            case 'x':
                printf("__   __\n\\ \\ / /\n \\ V / \n  | |  \n  |_|  \n");
                break;
            case 'y':
                printf(" _   _ \n| | | |\n| |_| |\n|  _  |\n|_| |_|");
                break;
            case 'z':
                printf(" _____\n|__  /\n  / / \n / /_ \n/____|\n");
                break;
            case ' ':
                printf("\n");
                break;
            default:
                printf("  _ \n / | \n|_  |\n | | \n |_| \n");
        }
    }

    return 0;
}