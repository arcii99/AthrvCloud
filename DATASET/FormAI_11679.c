//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define PIXEL_WIDTH 5
#define PIXEL_HEIGHT 5
#define IMAGE_WIDTH 10
#define IMAGE_HEIGHT 10

struct RGB {
    int r;
    int g;
    int b;
};

const struct RGB colors[8] = {
    {255, 255, 255}, // White
    {0, 0, 0},       // Black
    {255, 0, 0},     // Red
    {0, 255, 0},     // Green
    {0, 0, 255},     // Blue
    {255, 255, 0},   // Yellow
    {255, 0, 255},   // Magenta
    {0, 255, 255}    // Cyan
};

int main() {
    // Open output file
    FILE *fp;
    fp = fopen("output.ppm", "w");

    // Write PPM header
    fprintf(fp, "P3\n");
    fprintf(fp, "%d %d\n", IMAGE_WIDTH * PIXEL_WIDTH, IMAGE_HEIGHT * PIXEL_HEIGHT);
    fprintf(fp, "255\n");

    // Generate and write pixel art
    for (int y = 0; y < IMAGE_HEIGHT; y++) {
        for (int py = 0; py < PIXEL_HEIGHT; py++) {
            for (int x = 0; x < IMAGE_WIDTH; x++) {
                for (int px = 0; px < PIXEL_WIDTH; px++) {
                    // Generate random pixel color
                    int randIndex = rand() % 8;
                    const struct RGB *randColor = &colors[randIndex];

                    // Write pixel color to file
                    fprintf(fp, "%d %d %d ", randColor->r, randColor->g, randColor->b);
                }
            }
            // End of row
            fprintf(fp, "\n");
        }
    }

    // Close output file
    fclose(fp);

    return 0;
}