//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: random
#include <stdio.h>
#include <string.h>

void printAsciiArt(char* inputString);

int main()
{
    char inputString[100];
    printf("Enter a string to convert into ASCII art: ");
    fgets(inputString, 100, stdin);
    printAsciiArt(inputString);
    return 0;
}

void printAsciiArt(char* inputString)
{
    int length = strlen(inputString);
    int i, j;
    for (i = 0; i < length; i++) {
        for (j = 0; j < 5; j++) {
            switch (toupper(inputString[i])) {
                case 'A':
                    printf("   /\\   \n  /  \\  \n /____\\ \n/      \\\n");
                    break;
                case 'B':
                    printf(" ____  \n|    \\ \n|____/ \n|    \\ \n|____/ \n");
                    break;
                case 'C':
                    printf("  ____ \n /     \\\n/       \n\\       \n \\_____/ \n");
                    break;
                case 'D':
                    printf(" ____  \n|    \\ \n|     \\\n|     /\n|____/ \n");
                    break;
                case 'E':
                    printf(" _____ \n|  ___|\n| |___ \n|  ___|\n| |____\n|______|\n");
                    break;
                case 'F':
                    printf(" ______\n|  ____|\n| |__   \n|  __|  \n| |     \n|_|     \n");
                    break;
                case 'G':
                    printf("  ____ \n /     \\\n/ __   \n\\  __\\ \n \\____\\\n");
                    break;
                case 'H':
                    printf(" _    _\n| |  | |\n| |__| |\n|  __  |\n| |  | |\n|_|  |_|\n");
                    break;
                case 'I':
                    printf(" _____ \n|_   _|\n  | |  \n  | |  \n _| |_ \n|_____|\n");
                    break;
                case 'J':
                    printf("      _\n     | |\n     | |\n  _  | |\n | |_| |\n \\____/ \n");
                    break;
                case 'K':
                    printf(" _   __\n| | / /\n| |/ / \n|   <  \n| |\\ \\ \n|_| \\_\\\n");
                    break;
                case 'L':
                    printf(" _     \n| |    \n| |    \n| |    \n| |____\n|______|\n");
                    break;
                case 'M':
                    printf(" /\\     /\\\n|  \\   /  |\n| |\\\\_//| |\n| | \\_/ | |\n|_|     |_|\n");
                    break;
                case 'N':
                    printf(" _   _\n| \\ | |\n|  \\| |\n| . ` |\n| |\\  |\n|_| \\_|\n");
                    break;
                case 'O':
                    printf("  ___  \n /   \\ \n|     |\n|     |\n \\___/ \n");
                    break;
                case 'P':
                    printf(" ____  \n|    \\ \n|____/ \n| |    \n| |    \n|_|    \n");
                    break;
                case 'Q':
                    printf("  ___  \n /   \\ \n|     |\n| | | |\n \\___\\|\n");
                    break;
                case 'R':
                    printf(" ____  \n|    \\ \n|____/ \n| |\\ \\ \n| | \\ \\\n|_|  \\_\\\n");
                    break;
                case 'S':
                    printf("  ____ \n / ___\\\n| \\___ \\\n \\___  |\n ___/ /\n/____/ \n");
                    break;
                case 'T':
                    printf(" _____ \n|_   _|\n  | |  \n  | |  \n  | |  \n  |_|  \n");
                    break;
                case 'U':
                    printf(" _     \n| |    \n| |    \n| |    \n| |___ \n|_____|");
                    break;
                case 'V':
                    printf(" _    _\n| |  | |\n| |__| |\n|  __  |\n| |  | |\n|_|  |_|\n");
                    break;
                case 'W':
                    printf(" _        _\n| |      | |\n| |      | |\n| | /\\ | | |\n| \\/  \\/ | |\n|_|      |_|\n");
                    break;
                case 'X':
                    printf("\\ \\   / /\n  \\ \\ / / \n   \\ V /  \n   /   \\  \n/_/\\___\\\n");
                    break;
                case 'Y':
                    printf(" _    _\n| |  | |\n| |  | |\n| |  | |\n| |__| |\n|______|\n");
                    break;
                case 'Z':
                    printf(" ______\n|___   /\n   /  / \n  /  /  \n /  /   \n/__/    \n");
                    break;
                case ' ':
                    printf("    \n    \n    \n    \n    \n    \n");
                    break;
                default:
                    printf("      \n      \n      \n      \n      \n      \n");
                    break;
            }
        }
        printf("\n");
    }
}