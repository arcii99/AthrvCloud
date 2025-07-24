//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Function to generate ASCII art from text
void generateAsciiArt(char text[]) {
    int i, j, k;
    for (i = 0; text[i] != '\0'; i++) {
        // Print top border of each character
        printf(" _");
    }
    printf("\n");
    for (i = 0; text[i] != '\0'; i++) {
        // Print top of character's body
        printf("| ");
        // Print character
        printf("%c", text[i]);
        // Print bottom of character's body
        printf(" |\n");
    }
    for (i = 0; text[i] != '\0'; i++) {
        // Print bottom border of each character
        printf(" -");
    }
    printf("\n");
}

int main() {
    char text[50];
    printf("Enter some text: ");
    scanf("%s", text);
    generateAsciiArt(text);
    return 0;
}