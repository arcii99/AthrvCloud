//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main() {

    char input[100];
    int asciiArt[8][8];
    int i, j, k;

    // Prompt user for input string
    printf("Enter a string to convert to ASCII art:\n");
    scanf("%s", &input);

    // Convert each character to ASCII art
    for (i = 0; input[i] != '\0'; i++) {
        for (j = 0; j < 8; j++) {
            for (k = 0; k < 8; k++) {
                if ((input[i] >> (8*(j%2) + k)) & 0x01) {
                    asciiArt[j][k] = 1;
                } else {
                    asciiArt[j][k] = 0;
                }
            }
        }

        // Print the ASCII art
        for (j = 0; j < 8; j++) {
            for (k = 0; k < 8; k++) {
                if (asciiArt[j][k]) {
                    printf("* ");
                } else {
                    printf("  ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}