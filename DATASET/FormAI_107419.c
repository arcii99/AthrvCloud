//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: retro
#include <stdio.h>

// Function to map characters to their corresponding ASCII art
void mapToArt(char c) {
    switch(c) {
        case 'A':
            printf("    /\\    \n");
            printf("   /  \\   \n");
            printf("  /----\\  \n");
            printf(" /      \\ \n");
            printf("/        \\\n");
            break;
        case 'B':
            printf(" /---/|   \n");
            printf("|___|/    \n");
            printf("|---|\\\\   \n");
            printf("|___|\\\\\\ \n");
            printf("\\\\___|_/ \n");
            break;
        case 'C':
            printf("   _____ \n");
            printf(" /      \\\n");
            printf("|        \n");
            printf("|        \n");
            printf(" \\_____/\n");
            break;
        // Add more cases for other characters
        default:
            printf("\n");
            break;
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    for(int i=0; str[i]!='\0'; i++) {
        mapToArt(str[i]);
    }
    return 0;
}