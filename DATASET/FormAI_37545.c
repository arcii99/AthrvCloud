//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Ada Lovelace
#include <stdio.h>

int main() {

    char letter;
    printf("Enter a letter: ");
    scanf("%c", &letter);

    switch(letter) {
        case 'A':
            printf("     /\\     \n");
            printf("    /  \\    \n");
            printf("   /    \\   \n");
            printf("  /------\\  \n");
            printf(" /        \\ \n");
            printf("/          \\\n");
            break;
        case 'B':
            printf(" _______  \n");
            printf("|   ___ \\ \n");
            printf("|  |   \\ \\\n");
            printf("|  |___/ /\n");
            printf("|   ___ \\ \n");
            printf("|  |   \\ \\\n");
            printf("|__|    \\_\\\n");
            break;
        case 'C':
            printf("   ______ \n");
            printf(" /  _____\\\n");
            printf("|  /     \n");
            printf("|  \\_____ \n");
            printf("\\________\\\n");
            break;
        // add more cases for other letters
        default:
            printf("Sorry, that letter is not supported.\n");
    }

    return 0;
}