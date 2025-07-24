//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: complex
#include <stdio.h>
#include <string.h>

// Function to print ASCII art for each character
void printArt(char character) {
    switch (character) {
        case 'A':
        case 'a':
            printf("  /\\ \n /  \\ \n/____\\");
            break;
        case 'B':
        case 'b':
            printf(" ____  \n|  _ \\ \n| |_) )\n|  __/ \n|_|    ");
            break;
        case 'C':
        case 'c':
            printf("  ___ \n / __)\n( (__ \ \n \\___)");
            break;
        case 'D':
        case 'd':
            printf(" ____  \n|  _ \\ \n| | | |\n| |_| |\n|____/ ");
            break;
        case 'E':
        case 'e':
            printf(" _____\n| ____|\n| |__  \n|___ \\ \n|____/ ");
            break;
        case 'F':
        case 'f':
            printf(" _____\n|  ___|\n| |__  \n|  __| \n|_|    ");
            break;
        case 'G':
        case 'g':
            printf("  ___ \n / __)\n( (__ \n \\___)\n(____/ ");
            break;
        case 'H':
        case 'h':
            printf(" _   _ \n| | | |\n| |_| |\n|  _  |\n|_| |_|");
            break;
        case 'I':
        case 'i':
            printf("  _ \n (_)\n| |\n| |\n|_|");
            break;
        case 'J':
        case 'j':
            printf("     _ \n    (_)\n    | |\n _  | |\n| |_| |\n \\___/ ");
            break;
        case 'K':
        case 'k':
            printf(" _  __\n| |/ /\n| ' / \n| . \\ \n|_|\\_\\");
            break;
        case 'L':
        case 'l':
            printf(" _    \n| |   \n| |   \n| |___\n|_____|");
            break;
        case 'M':
        case 'm':
            printf(" __  __ \n|  \\/  |\n| |\\/| |\n| |  | |\n|_|  |_|");
            break;
        case 'N':
        case 'n':
            printf(" _   _\n| \\ | |\n|  \\| |\n| . ` |\n|_|\\__|");
            break;
        case 'O':
        case 'o':
            printf("  ___ \n / _ \\\n| |_| |\n \\___/");
            break;
        case 'P':
        case 'p':
            printf(" ____  \n|  _ \\ \n| |_) )\n|  __/ \n|_|    ");
            break;
        case 'Q':
        case 'q':
            printf("  __ _ \n / _` |\n| (_| |\n \\__, |\n    |_|");
            break;
        case 'R':
        case 'r':
            printf(" ____  \n|  _ \\ \n| |_) )\n|  _ < \n|_| \\_)");
            break;
        case 'S':
        case 's':
            printf("  ____ \n / ___)\n( (___ \n \\___ \\ \n(____/");
            break;
        case 'T':
        case 't':
            printf(" _____\n|__ __|\n   | |  \n   | |  \n   |_|  ");
            break;
        case 'U':
        case 'u':
            printf(" _   _ \n| | | |\n| | | |\n| |_| |\n \\___/ ");
            break;
        case 'V':
        case 'v':
            printf("__      __\n\\ \\    / /\n \\ \\  / / \n  \\ \\/ /  \n   \\__/   ");
            break;
        case 'W':
        case 'w':
            printf(" _    _ \ \n| |  | |\n| |__| |\n|  __  |\n|_|  |_|");
            break;
        case 'X':
        case 'x':
            printf("__  __\n\\ \\/ /\n \\  / \n /  \\ \n/_/\\_\\");
            break;
        case 'Y':
        case 'y':
            printf("__   __\n\\ \\ / /\n \\ V / \n  | |  \n  |_|  ");
            break;
        case 'Z':
        case 'z':
            printf(" _____\n|__  /\n  / / \n / /_ \n/____|");
            break;
        case ' ':
            printf("   ");
            break;
        default:
            break;
    }
}

// Main function to convert text to ASCII art
int main() {
    char input[50];
    printf("Enter a string: ");
    fgets(input, 50, stdin); // Read user input

    // Remove newline character from input
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    // Loop through each character in input
    for (int i = 0; i < strlen(input); i++) {
        printArt(input[i]); // Print ASCII art for current character
        printf("   "); // Add spacing between characters
    }

    return 0;
}