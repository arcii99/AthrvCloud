//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: creative
#include <stdio.h>

int main() {
    printf("Enter a word or phrase: ");
    char input[50];
    scanf("%s", input);

    int length = strlen(input);
    printf("\n");

    for (int i = 0; i < length; i++) {
        switch (input[i]) {
            case 'a':
            case 'A':
                printf("  /\\  \n /  \\ \n/____\\");
                break;
            case 'b':
            case 'B':
                printf(" _____ \n|  __ \\\n| |__) |\n|  ___/\n| |     \n|_|     ");
                break;
            case 'c':
            case 'C':
                printf(" _____ \n| ____|\n| |    \n| |___ \n|_____|");
                break;
            case 'd':
            case 'D':
                printf(" _____ \n|  __ \\\n| |  | |\n| |__| |\n|_____/ ");
                break;
            case 'e':
            case 'E':
                printf(" _____ \n| ____|\n| |__  \n|  __| \n| |___ \n|_____|");
                break;
            case 'f':
            case 'F':
                printf(" _____ \n|  ___|\n| |_   \n|  _|  \n| |    \n|_|    ");
                break;
            case 'g':
            case 'G':
                printf(" _____ \n|  ___|\n| |__  \n|  __| \n| |__\\ \n|_____/");
                break;
            case 'h':
            case 'H':
                printf("|     |\n|     |\n|_____| \n|     |\n|     |");
                break;
            case 'i':
            case 'I':
                printf(" ____ \n|_   |\n  | | \n  | | \n _| |_ \n|_____|");
                break;
            case 'j':
            case 'J':
                printf("      _ \n     | |\n     | |\n _   | |\n| |__| |\n|_____/ ");
                break;
            case 'k':
            case 'K':
                printf("|    / \n|   /  \n|__/   \n|  \\   \n|   \\  \n|    \\ ");
                break;
            case 'l':
            case 'L':
                printf("|      \n|      \n|      \n|      \n|___   \n|______|");
                break;
            case 'm':
            case 'M':
                printf("|\\    /|\n| \\  / |\n|  \\/  |\n|      |\n|      |");
                break;
            case 'n':
            case 'N':
                printf("|\\    |\n| \\   |\n|  \\  |\n|   \\ |\n|    \\|");
                break;
            case 'o':
            case 'O':
                printf("  ___  \n /   \\ \n|     |\n|     |\n \\___/ ");
                break;
            case 'p':
            case 'P':
                printf(" _____ \n|  __ \\\n| |__) |\n|  ___/\n| |    \n|_|    ");
                break;
            case 'q':
            case 'Q':
                printf("  ____ \n /   |\n|    |\n|    |\n \\___|\n     \\ ");
                break;
            case 'r':
            case 'R':
                printf(" _____ \n|  __ \\\n| |__) |\n|  _  / \n| | \\ \\ \n|_|  \\_\\");
                break;
            case 's':
            case 'S':
                printf(" _____ \n/ ____|\n\\ \\    \n \\ \\   \n  \\ \\_ \n   \\__|");
                break;
            case 't':
            case 'T':
                printf(" _____ \n|_   _|\n  | |  \n  | |  \n _| |_ \n|_____|");
                break;
            case 'u':
            case 'U':
                printf("|     |\n|     |\n|     |\n|     |\n \\___/ ");
                break;
            case 'v':
            case 'V':
                printf("\\     /\n \\   / \n  \\ /  \n   V   \n   |   ");
                break;
            case 'w':
            case 'W':
                printf("|\\    /|\n| \\  / |\n|  \\/  |\n|      |\n|      |\n|______|");
                break;
            case 'x':
            case 'X':
                printf("\\   / \n \\ /  \n  V   \n / \\  \n/   \\ ");
                break;
            case 'y':
            case 'Y':
                printf("\\    /\n \\  / \n  \\/  \n  /   \n /    \n|_____|");
                break;
            case 'z':
            case 'Z':
                printf(" _____ \n|__  /\n  / / \n / /_ \n/____|\n      ");
                break;
            default:
                printf("       \n       \n       \n       ");
                break;
        }
        printf("   ");
    }

    printf("\n");
    return 0;
}