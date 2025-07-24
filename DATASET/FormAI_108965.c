//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: accurate
#include <stdio.h>

// Function to print the ASCII art of a letter
void printAsciiArt(char letter) {
    switch(letter) {
        case 'A':
            printf("    /\\   \n");
            printf("   /  \\  \n");
            printf("  /    \\ \n");
            printf(" /------\\ \n");
            printf("/        \\\n");
            printf("\n");
            break;
        case 'B':
            printf(" _______  \n");
            printf("|  ___  \\ \n");
            printf("| |   \\ | \n");
            printf("| |___/ / \n");
            printf("|  ___  \\ \n");
            printf("| |   \\ | \n");
            printf("| |___/ / \n");
            printf("|_______/ \n");
            printf("\n");
            break;
        case 'C':
            printf("  ______  \n");
            printf(" /      \\ \n");
            printf("/        \\\n");
            printf("|         \n");
            printf("|         \n");
            printf("\\        /\n");
            printf(" \\______/ \n");
            printf("\n");
            break;
        // Add more letters here
        default:
            printf("Invalid character\n");
            break;
    }
}

int main() {
    char text[50];
    printf("Enter a string (50 characters max): ");
    fgets(text, 50, stdin);

    printf("\n");

    // Loop through each character in the input string
    for (int i = 0; i < 50; i++) {
        if (text[i] == '\0' || text[i] == '\n') {
            break;
        }
        printAsciiArt(text[i]); // Print the ASCII art of the current letter
    }

    return 0;
}