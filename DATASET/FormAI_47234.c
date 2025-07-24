//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: single-threaded
#include <stdio.h>
#include <ctype.h>

/* Function to convert a character to its ASCII art equivalent */
char* toASCII(char c) {
    switch (toupper(c)) {
        case 'A':
            return "      /\\      \n"
                   "     /  \\     \n"
                   "    /    \\    \n"
                   "   /------\\   \n"
                   "  /        \\  \n"
                   " /          \\ \n";

        case 'B':
            return " |------|   \n"
                   " |      |   \n"
                   " |------|   \n"
                   " |      |   \n"
                   " |------|   \n";

        case 'C':
            return "     /-\\    \n"
                   "    /   \\   \n"
                   "   /     \\  \n"
                   "  /       \\ \n"
                   "   \\     /  \n"
                   "    \\   /   \n"
                   "     \\-/    \n";

        // Add more letters and characters here
        
        default:
            return "Invalid Input";
    }
}

/* Main function */
int main() {
    char input;
    printf("Enter a letter or character: ");
    scanf("%c", &input);
    printf("\n");

    char* asciiArt = toASCII(input);
    printf("%s", asciiArt);

    return 0;
}