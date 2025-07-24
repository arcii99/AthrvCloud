//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: detailed
#include <stdio.h>
#include <string.h>

void printAsciiArt(char* text) {
    int len = strlen(text);

    // Loop through each character of the input text
    for (int i = 0; i < len; i++) {
        switch (text[i]) {
            case 'a':
            case 'A':
                printf("    AA     \n");
                printf("  A    A   \n");
                printf(" AAAAAAAA  \n");
                printf("A        A \n");
                printf("           \n");
                break;
            case 'b':
            case 'B':
                printf("BBBBBBB    \n");
                printf("B      B   \n");
                printf("BBBBBBB    \n");
                printf("B      B   \n");
                printf("BBBBBBB    \n");
                break;
            case 'c':
            case 'C':
                printf("  CCCCCC   \n");
                printf(" C         \n");
                printf("C          \n");
                printf(" C         \n");
                printf("  CCCCCC   \n");
                break;
            // Add more cases for each letter of the alphabet
            // or any additional characters you want to support
            default:
                printf("           \n");
                printf("           \n");
                printf("           \n");
                printf("           \n");
                printf("           \n");
                break;
        }
    }
}

int main() {
    char input[100];

    printf("Enter text to convert to ASCII art:\n");
    fgets(input, 100, stdin);

    printAsciiArt(input);

    return 0;
}