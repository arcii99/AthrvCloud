//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// This function creates ASCII art of the input string
void ascii_art_generator(char *input_string) {
    int len = strlen(input_string);
    for (int i = 0; i < len; i++) {
        // Convert each character to uppercase for easier conversion
        char c = toupper(input_string[i]);
        switch (c) {
            case 'A':
                printf("  /\\  \n /  \\ \n/____\\\n");
                break;
            case 'B':
                printf(" ____  \n|    \\ \n|____\\\n|____/\n");
                break;
            case 'C':
                printf("  ___ \n /    \\\n|      \n \\___/ \n");
                break;
            case 'D':
                printf(" ____  \n|    \\ \n|     \\\n|____/\n");
                break;
            case 'E':
                printf(" _____\n|      \n|_____\n|_____|\n");
                break;
            case 'F':
                printf(" _____\n|      \n|_____\n|\n");
                break;
            case 'G':
                printf("  ___ \n /    \\\n|  ___|\n \\___  \n");
                break;
            case 'H':
                printf(" _   _ \n| | | |\n| |_| |\n|     |\n");
                break;
            case 'I':
                printf(" ___ \n|   |\n|___|\n|___|\n");
                break;
            case 'J':
                printf("    _ \n   | |\n   | |\n\\__/ /\n");
                break;
            case 'K':
                printf(" _  __\n| |/ /\n| ' / \n| . \\ \n");
                break;
            case 'L':
                printf("    \n|   \n|___\n|___|\n");
                break;
            case 'M':
                printf(" /\\    /\\ \n|  \\  /  |\n| |\\\\//| |\n| | \\/ | |\n");
                break;
            case 'N':
                printf(" _   _ \n| \\ | |\n|  \\| |\n|     |\n");
                break;
            case 'O':
                printf("  ___ \n /   \\\n|     \\\n \\___/\n");
                break;
            case 'P':
                printf(" ____  \n|    \\ \n|____/\n|\n");
                break;
            case 'Q':
                printf("  ___  \n /   \\ \n|     |\n \\___/\\\n");
                break;
            case 'R':
                printf(" ____  \n|    \\ \n|__\\ \n|   \\\n");
                break;
            case 'S':
                printf(" ____ \n/     \\\n\\______\n      \\\n _____/\n");
                break;
            case 'T':
                printf(" ______ \n|   |  |\n|______|\n|__|__|\n");
                break;
            case 'U':
                printf(" _   _ \n| | | |\n| | | |\n \\___/ \n");
                break;
            case 'V':
                printf(" _   _ \n| | | |\n| \\_/ |\n \\___/ \n");
                break;
            case 'W':
                printf(" _      _ \n| |    | |\n| |/\\| | |\n| '  ` | |\n");
                break;
            case 'X':
                printf(" _   _ \n| \\ / |\n|  X  |\n|_/ \\_|\n");
                break;
            case 'Y':
                printf(" _   _ \n| | | |\n| |_| |\n \\___/ \n");
                break;
            case 'Z':
                printf(" ______\n|______|\n|______|\n|______|\n");
                break;
            case ' ':
                // Print an empty space to separate the letters
                printf("  ");
                break;
            default:
                // If the character is not a letter, skip it
                break;
        }
        // Add a space between each letter
        printf(" ");
    }
    printf("\n");
}

int main() {
    // Test the function with a few examples
    ascii_art_generator("Hello World");
    ascii_art_generator("I love ASCII art");
    ascii_art_generator("This is so cool");
    ascii_art_generator("12345");
    return 0;
}