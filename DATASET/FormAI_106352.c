//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: minimalist
#include <stdio.h>

#define WIDTH 120
#define HEIGHT 60

int main() {
    char ascii[HEIGHT][WIDTH+1];

    char characters[] = {' ', '.', ':', '*', 'o', '&', '8', '#', '@'};
    int numCharacters = sizeof(characters) / sizeof(characters[0]);

    char filename[] = "example_image.bmp";

    FILE *f = fopen(filename, "rb");
    fseek(f, 54, SEEK_SET);

    unsigned char image[WIDTH * HEIGHT * 3];
    fread(image, sizeof(unsigned char), WIDTH * HEIGHT * 3, f);

    int count = 0;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int index = (y * WIDTH + x) * 3;
            int r = image[index];
            int g = image[index+1];
            int b = image[index+2];
            int grayscale = (r + g + b) / 3;
            int charIndex = (int)(grayscale / 25.5);
            if (charIndex >= numCharacters) {
                charIndex = numCharacters - 1;
            }
            ascii[y][x] = characters[charIndex];
            count++;
        }
        ascii[y][WIDTH] = '\0';
    }

    fclose(f);

    for (int y = 0; y < HEIGHT; y++) {
        printf("%s\n", ascii[y]);
    }

    return 0;
}