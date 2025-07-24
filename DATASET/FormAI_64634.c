//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: complete
#include<stdio.h>
#include<string.h>

// Function to convert a character to ASCII art
void toASCII(char c) {
    switch(c) {
        case 'A':
            printf("  /\\ \n /  \\ \n/____\\");
            break;
        case 'B':
            printf(" ____ \n|    \\\n|____/");
            break;
        case 'C':
            printf("  ___\n /   \\\n/_____\\");
            break;
        case 'D':
            printf(" ____ \n|    \\\n|____/");
            break;
        case 'E':
            printf(" ____\n|    \n|____");
            break;
        case 'F':
            printf(" ____\n|    \n|    ");
            break;
        case 'G':
            printf("  ___\n /   \\\n/___,\\\n  ___/\\\n /   \\\n/_____\\");
            break;
        case 'H':
            printf("__/\\__\n\\    /\n/____\\\n\\    /\n \\__/");
            break;
        case 'I':
            printf(" ___\n|_  \\\n _|_|_");
            break;
        case 'J':
            printf("   __\n  |_ \\\n  |  |\n\\_|_/ \n  |__\\");
            break;
        case 'K':
            printf("\\   /\n \\ /\n  x\n / \\\n/   \\\n");
            break;
        case 'L':
            printf("     \n     \n ____");
            break;
        case 'M':
            printf("\\   /\\\n \\ /  \\\n  x    x\n / \\  /\n/   \\/");
            break;
        case 'N':
            printf("\\   /\n \\  \\ \n  \\  \\ \n   \\  \\\n    \\_\\");
            break;
        case 'O':
            printf("  ___\n /   \\\n|     |\n \\___/");
            break;
        case 'P':
            printf(" ____ \n|    \\\n|____/");
            break;
        case 'Q':
            printf("  ___\n /   \\\n|     |\n \\___/\n  \\\n   \\\\__|\n    \\__\\");
            break;
        case 'R':
            printf(" ____ \n|    \\\n|____/\n| \\");
            break;
        case 'S':
            printf("  ___ \n /    \\\n'_____/ ");
            break;
        case 'T':
            printf(" _____ \n|_  _|\n  ||  ");
            break;
        case 'U':
            printf("\\     /\n \\   /\n  \\ /\n   X\n  / \\\n /   \\\n");
            break;
        case 'V':
            printf("\\     /\n \\   /\n  \\ /\n   ' \n     ");
            break;
        case 'W':
            printf("\\    /\\\n \\  /  \\\n  X    X\n / \\  / \\\n/   \\/   \\\n");
            break;
        case 'X':
            printf("\\    /\n \\\\  //\n  xx\n //  \\\\\n/    \\\n");
            break;
        case 'Y':
            printf("\\     /\n \\   /\n  X\n  |  |\n  |  |");
            break;
        case 'Z':
            printf(" _____\n    / \n   /___\n  / \n /_____\n");
            break;
        case ' ':
            printf("     \n     \n     \n     \n     \n     \n");
            break;
        default:
            printf("Invalid character\n");
    }
}

// Main function
int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);
    int len = strlen(str);

    // Loop to print ASCII art for each character in the string
    for(int i = 0; i < len; i++) {
        toASCII(str[i]);
        printf("\n\n");
    }

    return 0;
}