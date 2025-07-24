//FormAI DATASET v1.0 Category: Image Editor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 500
#define HEIGHT 500

int main() {

    // Allocate space for the image buffer
    int* image = (int*) malloc(WIDTH * HEIGHT * sizeof(int));

    // Generate image
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            // Fill the image with a gradient
            int r = x * 255 / WIDTH;
            int g = y * 255 / HEIGHT;
            int b = (x + y) * 255 / (WIDTH + HEIGHT);
            image[y * WIDTH + x] = (r << 16) | (g << 8) | b;
        }
    }

    // Save image to file
    FILE* fp = fopen("image.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    for(int i = 0; i < WIDTH * HEIGHT; i++) {
        fputc((image[i] >> 16) & 0xFF, fp);
        fputc((image[i] >> 8) & 0xFF, fp);
        fputc(image[i] & 0xFF, fp);
    }

    // Free image buffer and close file pointer
    free(image);
    fclose(fp);

    return 0;
}