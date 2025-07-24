//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: surrealist
#include <stdio.h>
#include <string.h>

/*
 * This program generates surrealistic text to ASCII art.
 * It converts text input into ASCII art by using random characters,
 * colors and sizes, resulting in a unique and surreal output every time.
 */

int main() {
    // Define an array to store the input text
    char input[100];

    printf("Enter the text to be converted to ASCII art:\n");
    fgets(input, 100, stdin);

    // Define arrays of characters, colors and sizes for generating the ASCII art
    char chars[] = {'$', '*', '+', '&', '%', '#', '@', '!', '^', '~', '.', ';', ',', ':', '-', '=', '/', '\\', '|', '(', ')', '{', '}', '[', ']', '?', '<', '>'};
    char colors[] = {'r', 'g', 'b', 'c', 'm', 'y', 'w'};
    int sizes[] = {8, 12, 16, 20, 24, 28, 32};

    // Define a variable to store the length of the input text
    int textLength = strlen(input);

    // Generate the ASCII art
    for (int i = 0; i < textLength; i++) {
        char currentChar = input[i];
        int randomCharIndex = rand() % (sizeof(chars) / sizeof(chars[0]));
        char randomChar = chars[randomCharIndex];
        int randomColorIndex = rand() % (sizeof(colors) / sizeof(colors[0]));
        char randomColor = colors[randomColorIndex];
        int randomSizeIndex = rand() % (sizeof(sizes) / sizeof(sizes[0]));
        int randomSize = sizes[randomSizeIndex];

        printf("\x1b[%c;%dm", '0' + randomColor, 30 + randomColor); // Set color
        printf("\x1b[%dm", randomSize); // Set font size
        printf("%c", randomChar); // Print random character
        printf("\x1b[0m"); // Reset color and font size

        if (currentChar == '\n') {
            printf("\n"); // Add new line if the input has new line character
        }
    }

    return 0;
}