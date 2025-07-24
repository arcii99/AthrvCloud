//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: interoperable
#include <stdio.h>

// Function to convert character to ASCII art
void charToArt(char ascii_char) {
    // Switch case statement to generate ASCII art
    switch(ascii_char) {
        case 'A':
            printf("  /\\  \n /  \\ \n/    \\\n/\\/\\  \n/    \\ \n");
            break;
        case 'B':
            printf(" ___  \n|__ \\ \n   ) |\n  / / \n / /_ \n|____|\n");
            break;
        case 'C':
            printf("  ___ \n / __|\n| (__ \n \\___|\n");
            break;
        case 'D':
            printf(" ___  \n|__ \\ \n   ) |\n  / / \n / /_ \n|____|\n");
            break;
        case 'E':
            printf(" ____ \n|___ \\\n  __) |\n |__ < \n ___) |\n|____/\n");
            break;

        // Additional cases can be added here for other characters

        default:
            printf("Invalid character!");
            break;
    }
}

int main() {
    char input_char;

    // Prompt user for input character
    printf("Enter a character: ");
    scanf("%c", &input_char);

    // Convert input character to ASCII art
    charToArt(input_char);

    return 0;
}