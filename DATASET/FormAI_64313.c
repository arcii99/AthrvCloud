//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *CHARS= " .:-=+*#%@";
const int CHARS_LENGTH= 10;

void print_ascii_art(int *image, int width, int height) {

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel = image[y * width + x];
            int index = pixel * CHARS_LENGTH / 255;
            printf("%c%c", CHARS[index], CHARS[index]);
        }
        printf("\n");
    }
}

int main() {
    int image[] = {
        85, 85, 85, 85, 85, 85, 85, 0, 255, 255, 116, 0, 255, 255, 116, 0, 85, 85, 85, 85, 85, 85, 85, 0,
        255, 255, 116, 0, 255, 255, 116, 0, 85, 85, 85, 85, 85, 85, 85, 0, 255, 255, 116, 0, 255, 255, 116, 0,
        85, 85, 85, 85, 85, 85, 85, 0, 255, 255, 116, 0, 255, 255, 116, 0, 85, 85, 85, 85, 85, 85, 85, 0,
        255, 255, 116, 0, 255, 255, 116, 0, 85, 85, 85, 85, 85, 85, 85, 0, 255, 255, 116, 0, 255, 255, 116, 0,
        85, 85, 85, 85, 85, 85, 85, 0, 255, 255, 116, 0, 255, 255, 116, 0, 85, 85, 85, 85, 85, 85, 85, 0,
        255, 255, 116, 0, 255, 255, 116, 0, 85, 85, 85, 85, 85, 85, 85, 0, 255, 255, 116, 0, 255, 255, 116, 0,
        85, 85, 85, 85, 85, 85, 85, 0, 255, 255, 116, 0, 255, 255, 116, 0, 85, 85, 85, 85, 85, 85, 85, 0,
        255, 255, 116, 0, 255, 255, 116, 0, 85, 85, 85, 85, 85, 85, 85, 0, 255, 255, 116, 0, 255, 255, 116, 0
    };
    int width = 8;
    int height = 8;

    print_ascii_art(image, width, height);
    return 0;
}