//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WIDTH 80 // Maximum width of ASCII art
#define MAX_HEIGHT 80 // Maximum height of ASCII art

int main(int argc, char *argv[]) {
    char *filename;
    FILE *file;
    int width = 0, height = 0;
    int ch;
    char image[MAX_HEIGHT][MAX_WIDTH + 1];
    char ascii[MAX_HEIGHT][MAX_WIDTH + 1];

    if (argc != 2) {
        printf("Usage: %s image_file\n", argv[0]);
        return 1;
    }

    filename = argv[1];

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: cannot open file %s.\n", filename);
        return 1;
    }

    // Read image file
    while ((ch = fgetc(file)) != EOF) {
        if (width == MAX_WIDTH) {
            continue; // Skip this line
        }

        if (ch == '\n') {
            if (width > 0) {
                height++;
            }
            width = 0;
            continue;
        }

        image[height][width] = (char) ch;
        width++;
    }

    fclose(file);

    // Convert image to ASCII art
    for (int i = 0; i <= height; i++) {
        for (int j = 0; j <= width; j++) {
            char ch = image[i][j];

            if (isupper(ch)) {
                ch = tolower(ch);
            }

            if (ch >= 'a' && ch <= 'z') {
                ascii[i][j] = (char) (((int) ch - 97) * 25 / 26 + 97);
            } else if (ch == '#') {
                ascii[i][j] = '#';
            } else {
                ascii[i][j] = ' ';
            }
        }
    }

    // Print ASCII art
    for (int i = 0; i <= height; i++) {
        printf("%s\n", ascii[i]);
    }

    return 0;
}