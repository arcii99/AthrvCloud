//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char text[100];
    printf("Enter some text to convert to ASCII art:\n");
    scanf("%[^\n]", text);

    for (int i = 0; text[i] != '\0'; i++)
    {
        switch(text[i])
        {
            case 'a':
                printf("     /\\_/\\\n    / o o \\\n   /   -   \\\n  /   / \\   \\\n /___/___\\___\\\n");
                break;
            case 'b':
                printf("---------\n|        \\\n|         |\n|        /\n---------\n");
                break;
            case 'c':
                printf("   /\\_/\\  \n  / o o \\ \n (   \"   )\n  \\~(*)~/ \n   / ^ \\  \n");
                break;
            case 'd':
                printf("---------\n\\        |\n |        |\n/        |\n---------\n");
                break;
            case 'e':
                printf(" /\\_/\\  \n( o o ) \n > ^ <  \n/  -  \\ \n\\_/ \\_/\n");
                break;
            case 'f':
                printf(" /\\_/\\  \n( o o ) \n > ^ <  \n/       \n\\       \n");
                break;
            case 'g':
                printf("     /\\_/\\\n    / o o \\\n   (   -   )\n  |   v   | \n  \\|     | / \n   | \\ | /\n   | | | |\n");
                break;
            case 'h':
                printf("|         |\n|         |\n| ------- |\n|         |\n|         |\n");
                break;
            case 'i':
                printf("-------\n   |   \n   |   \n   |   \n-------\n");
                break;
            case 'j':
                printf("       /|\n      / |\n     /  |\n|   /   |\n \\_/____|\n");
                break;
            case 'k':
                printf("| /        \\\n|/  /\\__/\\  \\\n  \\ / o o \\ /\n   |   >   |\n   |__/ \\__|\n");
                break;
            case 'l':
                printf("|       \n|      \n|      \n|      \n|______\n");
                break;
            case 'm':
                printf("|\\     /|\n| \\   / |\n|  \\ /  |\n|   -   |\n|       |\n");
                break;
            case 'n':
                printf("|\\      |\n| \\     |\n|  \\    |\n|   \\   |\n|    \\__|\n");
                break;
            case 'o':
                printf("   /\\_/\\  \n  / o o \\ \n (   \"   )\n (       )\n  \\~(*)~/ \n   / ^ \\  \n");
                break;
            case 'p':
                printf("---------\n|        \\\n|         |\n|        /\n|       / \n");
                break;
            case 'q':
                printf("   /\\_/\\  \n  / o o \\ \n (   \"   )\n  (     ) \n   \\_/ \\_/\\\n        |  o\n        |__/ \n");
                break;
            case 'r':
                printf("---------\n|        \\\n|         |\n|        /\n|      /   \n");
                break;
            case 's':
                printf("   /\\_/\\\n  ( o   )\n   > ^ < \n /  _  \\\n \\/ \\_ \\/\n");
                break;
            case 't':
                printf("-------\n   |   \n   |   \n   |   \n   |___\n");
                break;
            case 'u':
                printf("|       |\n|       |\n|       |\n|       |\n \\_____/\n");
                break;
            case 'v':
                printf("\\       /\n \\     / \n  \\   /  \n   \\ /   \n    V    \n");
                break;
            case 'w':
                printf("|       |\n|   -   |\n|       |\n|       |\n \\     / \n  \\   /  \n   \\ /   \n    V    \n");
                break;
            case 'x':
                printf("\\      /\n \\___/\n /   \\\n|     |\n \\___/\n");
                break;
            case 'y':
                printf("\\       /\n \\     / \n  \\ _ /  \n   | |   \n  /   \\  \n |     |\n \\___ / \n");
                break;
            case 'z':
                printf(" ______\n|    / \n|   /  \n|  /__ \n|______|\n");
                break;
            default:
                printf("\n");
        }
    }

    return 0;
}