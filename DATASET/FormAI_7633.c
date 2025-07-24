//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

int main()
{
    char user_input[100];
    printf("Enter a string to convert to ASCII art:\n");
    fgets(user_input, 100, stdin);

    int length = strlen(user_input);
    if (user_input[length - 1] == '\n')
    {
        user_input[length - 1] = '\0';
        length--;
    }

    printf("\nASCII art:\n");

    for (int i = 0; i < length; i++)
    {
        switch (user_input[i])
        {
            case 'A':
                printf("  /\\  \n /  \\ \n/    \\\n/------\\\n");
                break;
            case 'B':
                printf("|------\n|___  \n|   \\ \n|___/ \n");
                break;
            case 'C':
                printf("  /----\n /     \n/___   \n\\    \\ \n \\____\\\n");
                break;
            case 'D':
                printf("|------\\\n|     __)\n|      \\ \n|_____/ \n");
                break;
            case 'E':
                printf(" _____\n|  ___|\n| |__  \n|  __| \n| |___ \n|_____|\n");
                break;
            case 'F':
                printf(" _____\n|  ___|\n| |__  \n|  __| \n| |    \n|_|    \n");
                break;
            case 'G':
                printf("  /----\n /     \n/___   \n\\   __/\n \\_____\\\n");
                break;
            case 'H':
                printf("|\\    /\n| \\  / \n|  \\/  \n|      \n|      \n|      \n");
                break;
            case 'I':
                printf(" _____\n|_   _|\n  | |  \n  | |  \n _| |_ \n|_____|\n");
                break;
            case 'J':
                printf("       /_\n      |_|\n      |_|\n   ___/ \n|_|     \n");
                break;
            case 'K':
                printf("|\\    / \n| \\  /  \n| \\/   \n|      \n|      \n|      \n");
                break;
            case 'L':
                printf("|     \n|     \n|     \n|     \n|___  \n|____|\n");
                break;
            case 'M':
                printf("/\\    /\\\n/  \\  /  \\\n\\/    \\/\n|      |\n|      |\n|      |\n");
                break;
            case 'N':
                printf("|\\    |\n| \\   |\n|  \\  |\n|   \\ |\n|    \\|\n");
                break;
            case 'O':
                printf("  /\\  \n /  \\ \n/    \\\n\\    /\n \\__/ \n");
                break;
            case 'P':
                printf(" _____\n|  __ \\\n| |__) |\n|  ___/\n| |\n|_|\n");
                break;
            case 'Q':
                printf("  /\\  \n /  \\ \n/    \\\n\\  /\\\n \\/_/\\_\n");
                break;
            case 'R':
                printf(" _____\n|  __ \\\n| |__) |\n|  _  /\n| | \\ \\ \n|_|  \\_\\\n");
                break;
            case 'S':
                printf("  ____\n / ___|\n/ /___ \n| ___ \\\n| \\_/ |\n\\____/\n");
                break;
            case 'T':
                printf(" _____\n|_   _|\n  | |  \n  | |  \n  |_|  \n       \n");
                break;
            case 'U':
                printf("|      |\n|      |\n|      |\n|      |\n \\____/ \n");
                break;
            case 'V':
                printf("\\      /\n \\    / \n  \\  /  \n   \\/   \n        \n");
                break;
            case 'W':
                printf("|      |\n|      |\n|  /\\  |\n| /  \\ |\n| \\  / |\n|  \\/  |\n");
                break;
            case 'X':
                printf("\\    /\n \\  / \n  \\/  \n  /\\  \n /  \\ \n/    \\\n");
                break;
            case 'Y':
                printf("\\    /\n \\  / \n  \\/  \n  /    \n /     \n/      \n");
                break;
            case 'Z':
                printf(" _____\n|___ / \n  |_ \\ \n ___) |\n|____/ \n");
                break;
            default:
                printf("   \n");
        }
    }

    return 0;
}