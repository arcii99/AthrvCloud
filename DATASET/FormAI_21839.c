//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 50

char asciiArt[MAX_HEIGHT][MAX_WIDTH];

void generateAsciiArt(char *inputText) {
    int textLength = strlen(inputText);
    int row, col;
    int charIndex = 0;
    for (row = 0; row < MAX_HEIGHT; row++) {
        for (col = 0; col < MAX_WIDTH && charIndex < textLength; col++) {
            asciiArt[row][col] = inputText[charIndex];
            charIndex++;
        }
        if (charIndex >= textLength) {
            break;
        }
    }
}

void printAsciiArt() {
    int row, col;
    for (row = 0; row < MAX_HEIGHT; row++) {
        for (col = 0; col < MAX_WIDTH; col++) {
            if (asciiArt[row][col] == '\0') {
                printf(" ");
            } else {
                printf("%c", asciiArt[row][col]);
            }
        }
        printf("\n");
    }
}

int main() {
    char inputText[100] = "";
    printf("Enter the text to convert to ASCII art:\n");
    fgets(inputText, 100, stdin);
    generateAsciiArt(inputText);
    printAsciiArt();
    return 0;
}