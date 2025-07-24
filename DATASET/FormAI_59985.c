//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to print ASCII art based on given character and height
void printArt(char c, int height) {
    int i, j;

    // Top horizontal line
    for(i = 0; i < height; i++) {
        printf(" ");
        for(j = 0; j < height; j++) {
            printf("__");
        }
        printf("\n");
    }

    // Vertical lines
    for(i = 0; i < height; i++) {
        printf(" |");
        for(j = 0; j < height; j++) {
            printf(" %c", c);
        }
        printf(" |\n");
    }

    // Bottom horizontal line
    printf(" ");
    for(i = 0; i < height; i++) {
        printf("~~");
    }
    printf("\n");
}

// Main function
int main() {
    char c;
    int height;

    printf("Enter the character to use for the ASCII art: ");
    scanf("%c", &c);
    printf("Enter the height of the ASCII art: ");
    scanf("%d", &height);

    printArt(c, height);

    return 0;
}