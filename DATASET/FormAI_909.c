//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Function to convert character to ASCII art
void toASCII(char c) {
    switch (c) {
        case 'A':
            printf("  /\\  \n");
            printf(" /  \\ \n");
            printf("/____\\\n");
            break;
        case 'B':
            printf(" ____ \n");
            printf("| __ )\n");
            printf("|  _ \\\n");
            printf("|____/\n");
            break;
        case 'C':
            printf("  ___ \n");
            printf(" / __|\n");
            printf("| (__ \n");
            printf(" \\___|\n");
            break;
        // add more character cases as needed
        default:
            printf("Invalid character.\n");
    }
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin); // read input string from user
    printf("ASCII art representation:\n");
    for (int i = 0; input[i] != '\0'; i++) {
        toASCII(input[i]); // call toASCII function for each character in the string
    }
    return 0;
}