//FormAI DATASET v1.0 Category: Image Editor ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 256
#define HEIGHT 256

int main() {
    // Load image data from file
    FILE *file;
    file = fopen("input.raw", "rb");
    unsigned char *image_data = malloc(WIDTH * HEIGHT * sizeof(unsigned char));
    fread(image_data, sizeof(unsigned char), WIDTH * HEIGHT, file);
    fclose(file);

    // Flip image horizontally
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH / 2; x++) {
            unsigned char temp = image_data[y * WIDTH + x];
            image_data[y * WIDTH + x] = image_data[y * WIDTH + (WIDTH - 1 - x)];
            image_data[y * WIDTH + (WIDTH - 1 - x)] = temp;
        }
    }

    // Invert image colors
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image_data[i] = 255 - image_data[i];
    }

    // Save image data to file
    file = fopen("output.raw", "wb");
    fwrite(image_data, sizeof(unsigned char), WIDTH * HEIGHT, file);
    fclose(file);

    free(image_data);

    return 0;
}