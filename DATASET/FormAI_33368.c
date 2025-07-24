//FormAI DATASET v1.0 Category: Image Editor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 256
#define HEIGHT 256

int main(void) {
    int img[HEIGHT][WIDTH];

    // Initialize the image with zeros
    memset(img, 0, sizeof(img));

    // Draw a rectangle in the image
    for (int y = 50; y < 120; y++) {
        for (int x = 80; x < 180; x++) {
            img[y][x] = 255;
        }
    }

    // Save the image to a file
    FILE *fp = fopen("output.pgm", "wb");
    fprintf(fp, "P5\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(img, sizeof(img), 1, fp);
    fclose(fp);

    // Load the image from the file
    fp = fopen("output.pgm", "rb");
    char buffer[100];
    fgets(buffer, sizeof(buffer), fp); // Skip the P5 header
    fgets(buffer, sizeof(buffer), fp); // Skip the image size header
    fgets(buffer, sizeof(buffer), fp); // Skip the maximum value header
    fread(img, sizeof(img), 1, fp);
    fclose(fp);

    // Invert the colors of the image
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            img[y][x] = 255 - img[y][x];
        }
    }

    // Save the inverted image to a file
    fp = fopen("output_inverted.pgm", "wb");
    fprintf(fp, "P5\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(img, sizeof(img), 1, fp);
    fclose(fp);

    return 0;
}