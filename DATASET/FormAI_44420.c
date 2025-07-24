//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: multiplayer
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Function to print a character in ASCII art
void printChar(char c) {
    //ASCII art for each letter
    switch(c) {
        case 'A':
            printf("  /\\   \n /  \\  \n/    \\ \n/------\\\n/        \\\n/          \\\n");
            break;
        case 'B':
            printf(" ------\n |     \n |___  \n |   \\ \n |___/ \n |     \n |_____ \n");
            break;
        case 'C':
            printf("   _____\n /      \n/        \n|        \n|        \n\\        \n  \\_____ \n");
            break;
        case 'D':
            printf(" _____  \n|     \\ \n|      \\\n|      | \n|      /\n|_____/ \n");
            break;
        case 'E':
            printf(" -------\n |      \n |_ _ _ \n |      \n |      \n |      \n |_____ \n");
            break;
        case 'F':
            printf(" -------\n |      \n |_ _ _ \n |      \n |      \n |      \n/       \n");
            break;
        case 'G':
            printf("   _____\n /      \n/   ___ \n|      |\n\\     / \n  ---/   \n");
            break;
        case 'H':
            printf(" /     \\ \n/       \\\n|   -   |\n|       |\n|       |\n|       |\n \\_____/\n");
            break;
        case 'I':
            printf(" ------ \n   |    \n   |    \n   |    \n   |    \n   |    \n ------ \n");
            break;
        case 'J':
            printf("   ---\\\n     | \n     | \n     | \n/    / \n \\__/  \n");
            break;
        case 'K':
            printf(" /     \\\n/       \\\n|    /  \n|   /   \n|  /    \n| /     \n|/      \n");
            break;
        case 'L':
            printf(" /       \n/        \n|        \n|        \n|        \n|        \n --------\n");
            break;
        case 'M':
            printf(" /\\    /\\ \n/  \\  /  \\\n|    \\/   |\n|         |\n|         |\n|         |\n|         |\n");
            break;
        case 'N':
            printf(" /\\    | \n/  \\   | \n|    \\  | \n|     \\ | \n|      \\|\n|       |\n|       |\n");
            break;
        case 'O':
            printf("  _____ \n /     \\\n/       \\\n|       |\n|       |\n\\       /\n \\_____/ \n");
            break;
        case 'P':
            printf(" ------ \n/     \\ \n|     | \n|-----/ \n|       \n|       \n|       \n");
            break;
        case 'Q':
            printf("  _____  \n /     \\ \n/       \\\n|       |\n|       |\n\\     / \n \\___/\\_\\\n");
            break;
        case 'R':
            printf(" ------ \n/     \\ \n|     | \n|-----/ \n| \\     \n|  \\    \n|   \\   \n");
            break;
        case 'S':
            printf("  _____ \n /      \n|        \n\\_____  \n       \\\n       |\n \\_____/\n");
            break;
        case 'T':
            printf(" -------\n   |    \n   |    \n   |    \n   |    \n   |    \n   |    \n");
            break;
        case 'U':
            printf(" /     \\ \n/       \\\n|       |\n|       |\n|       |\n\\       /\n \\_____/\n");
            break;
        case 'V':
            printf(" /     \\ \n/       \\\n|       |\n \\     / \n  \\   /  \n   \\ /   \n    V    \n");
            break;
        case 'W':
            printf(" /     \\ \n/       \\\n|  / \\  |\n| /   \\ |\n|/     \\|\n|       |\n|       |\n");
            break;
        case 'X':
            printf(" /     \\ \n/       \\\n \\     / \n  \\   /  \n   | |   \n  /   \\  \n/       \\\n");
            break;
        case 'Y':
            printf(" /     \\ \n/       \\\n \\     / \n  \\   /  \n   | |   \n   | |   \n   |_|   \n");
            break;
        case 'Z':
            printf(" ______\n       / \n      /  \n  /--   \n /      \n/       \n _______\n");
            break;
        case ' ':
            printf("\n\n\n\n\n\n\n");
            break;
        default:
            printf("Invalid character.\n");
            break;
    }
}

int main()
{
    int i, j, length;
    char str[100];
    printf("Enter a word or phrase to convert to ASCII art: ");
    scanf("%[^\n]%*c", str);
    length = strlen(str);

    //Print the ASCII art
    for (i=0; i<7; i++) {
        for (j=0; j<length; j++) {
            printChar(str[j]);
        }
        printf("\n");
    }
    return 0;
}