//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: realistic
#include <stdio.h>

int main() {
    char text[100];
    printf("Enter some text: ");
    fgets(text, 100, stdin);
    printf("\n");

    // Creating ASCII Art for the input text
    for (int i = 0; text[i] != '\0'; i++) {
        switch (text[i]) {
            case 'a':
            case 'A':
                printf("    /\\  \n");
                printf("   /  \\ \n");
                printf("  /----\\ \n");
                printf(" /      \\ \n");
                printf("/        \\ \n\n");
                break;

            case 'b':
            case 'B':
                printf(" |------\\ \n");
                printf(" |      | \n");
                printf(" |-----< \n");
                printf(" |      | \n");
                printf(" |_____/ \n\n");
                break;

            case 'c':
            case 'C':
                printf("   ______ \n");
                printf(" /       \\\n");
                printf("/         \\\n");
                printf("\\         /\n");
                printf(" \\_______/\n\n");
                break;

            // More cases for each alphabet character can be added here

            default:
                printf("   ___  \n");
                printf("  /   \\ \n");
                printf(" /     \\\n");
                printf("|   X   |\n");
                printf(" \\     /\n");
                printf("  \\___/ \n\n");
        }
    }

    return 0;
}