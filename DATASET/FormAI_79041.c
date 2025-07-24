//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

void apply_watermark(pixel *image, int width, int height) {
    // Define the watermark pattern
    unsigned char watermark[] = { 0, 1, 0, 1, 1, 0, 1, 0 };
    int watermark_len = sizeof(watermark) / sizeof(watermark[0]);
    int watermark_index = 0;

    // Iterate over each pixel in the image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;

            // Check if the pixel color is odd or even
            if (image[index].r % 2 == 0) {
                // If the color is even, flip the least significant bit
                image[index].r |= 1;
            } else {
                // If the color is odd, leave it as is
            }

            // Apply the watermark bit to the pixel color
            if (watermark[watermark_index % watermark_len]) {
                // If the watermark bit is 1, add 1 to one of the color components
                if (watermark_index % 3 == 0) {
                    image[index].r += 1;
                } else if (watermark_index % 3 == 1) {
                    image[index].g += 1;
                } else {
                    image[index].b += 1;
                }
            }

            // Move to the next watermark bit
            watermark_index++;
        }
    }
}

int main(int argc, char *argv[]) {
    // Load the image file into memory
    FILE *file = fopen("image.bin", "rb");
    if (!file) {
        printf("Error: Could not open image file.\n");
        return EXIT_FAILURE;
    }
    int width = 256;
    int height = 256;
    size_t result = 0;
    pixel *image = malloc(width * height * sizeof(pixel));
    if (!image) {
        printf("Error: Could not allocate memory for image.\n");
        fclose(file);
        return EXIT_FAILURE;
    }
    result = fread(image, sizeof(pixel), width * height, file);
    if (!result) {
        printf("Error: Could not read image file.\n");
        free(image);
        fclose(file);
        return EXIT_FAILURE;
    }
    fclose(file);

    // Apply the digital watermark to the image
    apply_watermark(image, width, height);

    // Save the watermarked image to disk
    file = fopen("watermarked.bin", "wb");
    if (!file) {
        printf("Error: Could not create watermarked image file.\n");
        free(image);
        return EXIT_FAILURE;
    }
    result = fwrite(image, sizeof(pixel), width * height, file);
    if (!result) {
        printf("Error: Could not write watermarked image file.\n");
        free(image);
        fclose(file);
        return EXIT_FAILURE;
    }
    fclose(file);
    
    free(image);
    printf("Watermark applied successfully!\n");

    return EXIT_SUCCESS;
}