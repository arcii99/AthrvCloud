//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a word or phrase to generate ASCII art: ");
    scanf("%s", input);
    printf("\n");

    for(int i = 0; i < strlen(input); i++) {
        switch(input[i]) {
            case 'a':
                printf("  /\\ \n /  \\ \n/____\\ \n|____| \n|    | \n");
                break;
            case 'b':
                printf(" ____  \n|    \\ \n|___  | \n|   | | \n|___/  \n");
                break;
            case 'c':
                printf("  ___  \n / __| \n| (__  \n \\___| \n       \n");
                break;
            case 'd':
                printf(" ____  \n|    \\ \n|   | | \n|___/  \n|      \n");
                break;
            case 'e':
                printf(" _____ \n| ___ \\\n| |_/ /\n|  __/ \n|_|    \n");
                break;
            case 'f':
                printf(" _____ \n|  ___|\n| |___ \n|___  |\n    |_| \n");
                break;
            case 'g':
                printf("  ___  \n / __| \n| (_ | \n \\___| \n|____| \n");
                break;
            case 'h':
                printf(" _   _ \n| | | |\n| |_| |\n|  _  |\n|_| |_|\n");
                break;
            case 'i':
                printf(" _____ \n|_   _|\n  | |  \n  | |  \n  |_|  \n");
                break;
            case 'j':
                printf("     _ \n    | |\n _  | |\n| |_| |\n \\___/ \n");
                break;
            case 'k':
                printf(" _  __\n| |/ /\n| ' / \n| . \\ \n|_|\\_\\\n");
                break;
            case 'l':
                printf(" _     \n| |    \n| |    \n| |___ \n|_____| \n");
                break;
            case 'm':
                printf(" __  __ \n|  \\/  |\n| |\\/| |\n| |  | |\n|_|  |_|\n");
                break;
            case 'n':
                printf(" _   _ \n| \\ | |\n|  \\| |\n| |\\  |\n|_| \\_|\n");
                break;
            case 'o':
                printf("  ___  \n / _ \\ \n| | | |\n| |_| |\n \\___/ \n");
                break;
            case 'p':
                printf(" ____  \n|    \\ \n| |_) |\n|     / \n|_|\\_\\ \n");
                break;
            case 'q':
                printf("  ___  \n / _ \\ \n| | | |\n| |_| |\n \\__\\_\\\n");
                break;
            case 'r':
                printf(" ____  \n|    \\ \n| |_) |\n|  _ < \n|_| \\_\\\n");
                break;
            case 's':
                printf("  ___  \n / __| \n \\__ \\ \n|___/ \n       \n");
                break;
            case 't':
                printf(" _____ \n|_   _|\n  | |  \n  | |  \n  |_|  \n");
                break;
            case 'u':
                printf(" _   _ \n| | | |\n| | | |\n| |_| |\n \\___/ \n");
                break;
            case 'v':
                printf(" _   _ \n| | | |\n| | | |\n| |_| |\n \\___/ \n");
                break;
            case 'w':
                printf(" _    _ \n| |  | |\n| |  | |\n| |/\\| |\n\\  /\\  /\n \\/  \\/ \n");
                break;
            case 'x':
                printf(" _   _ \n| \\ | |\n|  \\| |\n| |\\  |\n|_| \\_|\n");
                break;
            case 'y':
                printf(" _   _ \n| | | |\n| |_| |\n|  _  |\n|_| |_|\n");
                break;
            case 'z':
                printf(" _____ \n|__  / \n  / /  \n / /_  \n/____| \n");
                break;
            case ' ':
                printf(" \n \n \n \n \n");
                break;
            default:
                printf("Error: Invalid character '%c'\n", input[i]);
                break;
        }
    }

    return 0;
}