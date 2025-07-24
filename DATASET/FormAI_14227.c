//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: decentralized
#include <stdio.h>

void generateArt(char input) {
    switch (input) {
        case 'A':
            printf("    /\\    \n");
            printf("   /  \\   \n");
            printf("  /____\\  \n");
            printf(" /      \\ \n");
            printf("/        \\\n");
            break;
        case 'B':
            printf(" _____   \n");
            printf("|  _  \\   \n");
            printf("| |_) /  \n");
            printf("|  _ <    \n");
            printf("| |_)  \\  \n");
            printf("|____/  \n");
            break;
        case 'C':
            printf("  ______ \n");
            printf(" /      \\ \n");
            printf("/        \\\n");
            printf("|   ____|\n");
            printf("| |____  \n");
            printf("\\______| \n");
            break;
        // add more cases for other letters
        default:
            printf("Invalid input.");
    }
}

int main() {
    char input;
    printf("Enter a letter to generate ASCII art: ");
    scanf("%c", &input);
    generateArt(input);
    return 0;
}