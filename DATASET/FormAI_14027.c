//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Linus Torvalds
#include <stdio.h>

// Function to get ascii decimal value for given character
int getAsciiValue(char character) {
    return (int) character;
}

// Function to print ascii art for given character
void printAsciiArt(char character) {
    int asciiDecimal = getAsciiValue(character);

    // Range of ascii decimal values for common characters
    if (asciiDecimal >= 32 && asciiDecimal <= 126) {
        printf("Ascii Art for '%c':\n", character);
        printf(" _ _ _ _ _ _ _ _ _\n");
        printf("|                 |\n");
        printf("|      __%c__      |\n", character);
        printf("|     |     |     |\n");
        printf("|     |     |     |\n");
        printf("|     |_____|\n");
        printf("|                 |\n");
        printf("|                 |\n");
        printf("|                 |\n");
        printf("|                 |\n");
        printf("|_________________|\n");
    }
    else {
        printf("Ascii Art for '%c' is not available.\n", character);
    }
}

int main() {
    char input;
    printf("Enter a character: ");
    scanf("%c", &input);
    printAsciiArt(input);
    return 0;
}