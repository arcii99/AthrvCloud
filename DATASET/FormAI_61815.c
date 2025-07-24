//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: statistical
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void draw(char character, int length);

int main()
{
    char input[50];

    printf("Enter a message to convert to ASCII art: ");
    fgets(input, 50, stdin);

    for (int i = 0; i < strlen(input); i++)
    {
        char currentChar = toupper(input[i]);

        switch (currentChar)
        {
            case 'A':
                draw(currentChar, 3);
                break;
            case 'B':
                draw(currentChar, 4);
                break;
            case 'C':
                draw(currentChar, 6);
                break;
            case 'D':
                draw(currentChar, 4);
                break;
            case 'E':
                draw(currentChar, 4);
                break;
            case 'F':
                draw(currentChar, 4);
                break;
            case 'G':
                draw(currentChar, 6);
                break;
            case 'H':
                draw(currentChar, 4);
                break;
            case 'I':
                draw(currentChar, 3);
                break;
            case 'J':
                draw(currentChar, 5);
                break;
            case 'K':
                draw(currentChar, 4);
                break;
            case 'L':
                draw(currentChar, 4);
                break;
            case 'M':
                draw(currentChar, 5);
                break;
            case 'N':
                draw(currentChar, 5);
                break;
            case 'O':
                draw(currentChar, 6);
                break;
            case 'P':
                draw(currentChar, 4);
                break;
            case 'Q':
                draw(currentChar, 7);
                break;
            case 'R':
                draw(currentChar, 4);
                break;
            case 'S':
                draw(currentChar, 5);
                break;
            case 'T':
                draw(currentChar, 3);
                break;
            case 'U':
                draw(currentChar, 5);
                break;
            case 'V':
                draw(currentChar, 5);
                break;
            case 'W':
                draw(currentChar, 5);
                break;
            case 'X':
                draw(currentChar, 5);
                break;
            case 'Y':
                draw(currentChar, 5);
                break;
            case 'Z':
                draw(currentChar, 5);
                break;
            case ' ':
                printf("\n");
                break;
            default:
                printf("Invalid character: %c\n", currentChar);
                break;
        }
    }

    return 0;
}

void draw(char character, int length)
{
    for (int i = 0; i < length; i++)
    {
        switch (character)
        {
            case 'A':
                printf("  /\\  \n /  \\ \n/____\\\n");
                break;
            case 'B':
                printf(" ____ \n| __ )\n|  _ \\\n| |_) |\n|____/\n");
                break;
            case 'C':
                printf("  ___ \n / __\\\n/ /   \n\\ \\___\n \\____\\\n");
                break;
            case 'D':
                printf(" ____ \n|  _ \\ \n| |_) |\n|  _ < \n|____/\n");
                break;
            case 'E':
                printf(" _____\n| ____|\n|  _|  \n| |___ \n|_____|\n");
                break;
            case 'F':
                printf(" _____\n|  ___|\n| |_   \n|  _|  \n|_|    \n");
                break;
            case 'G':
                printf("  ___ \n / __\\\n/ /   \n\\ \\__-\n \\____\\\n");
                break;
            case 'H':
                printf(" _   _ \n| | | |\n| |_| |\n|  _  |\n|_| |_|\n");
                break;
            case 'I':
                printf(" _____\n|_   _|\n  | |   \n  | |   \n  |_|  \n");
                break;
            case 'J':
                printf("     _ \n    | |\n _  | |\n| |_| |\n \\___/\n");
                break;
            case 'K':
                printf(" _  __\n| |/ /\n| ' / \n| . \\ \n|_|\\_\\\n");
                break;
            case 'L':
                printf(" _    \n| |_  \n| __| \n| |_  \n \\__|\n");
                break;
            case 'M':
                printf(" __  __ \n|  \\/  |\n| |\\/| |\n| |  | |\n|_|  |_|\n");
                break;
            case 'N':
                printf(" _   _ \n| \\ | |\n|  \\| |\n| |\\  |\n|_| \\_|\n");
                break;
            case 'O':
                printf("  ___  \n / _ \\ \n| | | |\n| |_| |\n \\___/ \n");
                break;
            case 'P':
                printf(" ____ \n|  _ \\ \n| |_) |\n|  _ < \n|_| \\_\\\n");
                break;
            case 'Q':
                printf("  ___  \n / _ \\ \n| | | |\n| |_| |\n \\__\\_\\\n");
                break;
            case 'R':
                printf(" ____ \n|  _ \\\n| |_) |\n|  _ < \n|_| \\_\\\n");
                break;
            case 'S':
                printf("  ___ \n / __|\n| (__ \n \\___|\n");
                break;
            case 'T':
                printf(" _____ \n|_   _|\n  | |  \n  | |  \n  |_|  \n");
                break;
            case 'U':
                printf(" _   _ \n| | | |\n| | | |\n| |_| |\n \\___/ \n");
                break;
            case 'V':
                printf("__     __\n\\ \\   / /\n \\ \\ / / \n  \\ V /  \n   \\_/  \n");
                break;
            case 'W':
                printf(" _    _\n| |  | |\n| |  | |\n| |/\\| |\n|__/\\__|\n");
                break;
            case 'X':
                printf("__  __\n\\ \\/ /\n \\  / \n /  \\\n/_/\\_\\\n");
                break;
            case 'Y':
                printf("__   __\n\\ \\ / /\n \\ V / \n  | |  \n  |_|  \n");
                break;
            case 'Z':
                printf(" _____\n|__  /\n  / / \n / /_ \n/____\\\n");
                break;
            default:
                break;
        }
    }
}