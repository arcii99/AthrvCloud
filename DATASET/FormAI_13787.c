//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum width and height of the text art
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// function to print the ASCII art
void printArt(char art[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            putchar(art[i][j]);
        }
        putchar('\n');
    }
}

// function to clear the ASCII art
void clearArt(char art[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    memset(art, ' ', height * width * sizeof(char));
}

// function to generate the ASCII art from a text string
void generateArt(char art[MAX_HEIGHT][MAX_WIDTH], int height, int width, char* text) {
    int textLength = strlen(text);
    int x = 0, y = 0;
    for (int i = 0; i < textLength; i++) {
        if (text[i] == '\n') {
            x = 0;
            y++;
        } else if (x < width && y < height) {
            art[y][x] = text[i];
            x++;
        }
    }
}

int main() {
    char art[MAX_HEIGHT][MAX_WIDTH];
    char input[100];
    int height = 10, width = 40;

    // clear the art
    clearArt(art, height, width);

    // get input from user
    printf("Enter text: ");
    fgets(input, 100, stdin);

    // generate the art
    generateArt(art, height, width, input);

    // print the art
    printArt(art, height, width);

    return 0;
}