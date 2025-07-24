//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 20

void draw(char c, int width, int height) {
    // converts specified character to ASCII code
    int ascii_val = (int)c;

    // limits the width if the character exceeds it
    if (width > MAX_WIDTH) {
        width = MAX_WIDTH;
    }

    // limits the height if the character exceeds it
    if (height > MAX_HEIGHT) {
        height = MAX_HEIGHT;
    }

    // prints the ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii_val);
        }
        printf("\n");
    }
}

int main() {
    char c;
    int width, height;

    printf("Enter a character: ");
    scanf("%c", &c);
    printf("Enter width (max 80): ");
    scanf("%d", &width);
    printf("Enter height (max 20): ");
    scanf("%d", &height);

    // converts the character to uppercase for readability
    c = toupper(c);

    // generates ASCII art based on specified parameters
    draw(c, width, height);

    return 0;
}