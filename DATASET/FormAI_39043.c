//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Cryptic
#include <stdio.h>

// Function to convert text to ASCII art
void textToArt(char *text) {
    int length = strlen(text);
    int asciiArt[length];

    // Cryptic ASCII art code
    for (int i = 0; i < length; i++) {
        asciiArt[i] = (int)text[i] * (length - i) + i;
    }

    // Display the ASCII art
    for (int i = 0; i < length; i++) {
        int num = asciiArt[i] % 94 + 33;
        printf("%c", num);
    }
}

int main() {
    // Example usage of textToArt function
    char text[] = "ASCII art generator";
    textToArt(text);

    return 0;
}