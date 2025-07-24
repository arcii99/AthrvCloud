//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 640
#define HEIGHT 480

// Define the watermark as a string
const char *WATERMARK = "© MyWatermark";

// Function to embed watermark in the image
void embedWatermark(char *filename) {
    FILE *fp = fopen(filename, "r+b");
    if(fp == NULL) {
        printf("Could not open file %s", filename);
        return;
    }
    // Find the end of file
    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    // Calculate watermark size
    int watermarkSize = strlen(WATERMARK);
    // Check if the file is large enough to hold the watermark
    if(filesize < watermarkSize) {
        printf("File %s is too small for watermark", filename);
        fclose(fp);
        return;
    }
    // Define start and end of watermark
    long start = filesize - watermarkSize;
    long end = filesize;
    // Embed the watermark at the end of the file
    fwrite(WATERMARK, 1, watermarkSize, fp);
    fclose(fp);
    printf("Watermark embedded successfully in file %s", filename);
}

// Function to extract watermark from the image
void extractWatermark(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("Could not open file %s", filename);
        return;
    }
    // Find the end of file
    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    // Calculate watermark size
    int watermarkSize = strlen(WATERMARK);
    // Check if the file is large enough to hold the watermark
    if(filesize < watermarkSize) {
        printf("File %s does not contain watermark", filename);
        fclose(fp);
        return;
    }
    // Define start and end of watermark
    long start = filesize - watermarkSize;
    long end = filesize;
    // Extract the watermark from the file
    char buffer[watermarkSize];
    fseek(fp, start, SEEK_SET);
    fread(buffer, 1, watermarkSize, fp);
    fclose(fp);
    // Check if watermark is present
    if(strcmp(buffer, WATERMARK) == 0)
        printf("Watermark found in file %s", filename);
    else
        printf("Watermark not found in file %s", filename);
}

int main() {
    // Create an example image with black and white pixels
    char filename[] = "example_image.ppm";
    FILE *fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Could not create image file");
        return 0;
    }
    fprintf(fp, "P3\n%i %i\n255\n", WIDTH, HEIGHT);
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            int c = (x + y) % 2 == 0 ? 255 : 0;
            fprintf(fp, "%i %i %i ", c, c, c);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    // Embed the watermark in the image
    embedWatermark(filename);
    // Extract the watermark from the image
    extractWatermark(filename);
    // Remove the example image file
    remove(filename);
    return 0;
}