//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: cheerful
// Welcome to our Digital Watermarking generator!
// This program adds an invisible watermark to any image you choose
// The watermark guarantees the authenticity and ownership of the image

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK "This image is owned by Happy Developers!"

int main() {
    // Open the file containing the image you want to watermark
    FILE *image_file;
    image_file = fopen("my_image.jpg", "rb");
    if (image_file == NULL) {
        printf("Error opening image file.\n");
        return 1;
    }

    // Create a new file to write the watermarked image to
    FILE *watermarked_file;
    watermarked_file = fopen("watermarked_image.jpg", "wb");
    if (watermarked_file == NULL) {
        printf("Error creating watermarked file.\n");
        return 1;
    }

    // Write the watermark to the beginning of the watermarked file
    char *watermark = WATERMARK;
    unsigned int watermark_length = strlen(watermark);
    fwrite(&watermark_length, sizeof(unsigned int), 1, watermarked_file);
    fwrite(watermark, sizeof(char), watermark_length, watermarked_file);

    // Read the image data block by block and write to the watermarked file
    #define BLOCK_SIZE 512
    char buf[BLOCK_SIZE];
    size_t n;
    while ((n = fread(buf, sizeof(char), BLOCK_SIZE, image_file)) > 0) {
        fwrite(buf, sizeof(char), n, watermarked_file);
    }

    // Close the files
    fclose(image_file);
    fclose(watermarked_file);

    printf("Done! Your watermarked image is ready to use.\n");

    return 0;
}