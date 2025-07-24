//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} pixel;

void embed_watermark(pixel* image, char* watermark_text);
void extract_watermark(pixel* image);

int main() {
    // Seed RNG
    srand(time(NULL));

    // Allocate memory for image
    pixel* image = malloc(sizeof(pixel) * IMAGE_WIDTH * IMAGE_HEIGHT);
    if (image == NULL) {
        printf("Error: Unable to allocate memory for image.\n");
        return 0;
    }

    // Fill image with random pixel values
    for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT; i++) {
        image[i].r = rand() % 256;
        image[i].g = rand() % 256;
        image[i].b = rand() % 256;
        image[i].a = 255;
    }

    // Embed watermark into image
    char* watermark_text = "After the apocalypse, all that remained were memories of what once was.";
    embed_watermark(image, watermark_text);

    // Extract watermark from image and print to console
    extract_watermark(image);

    // Free dynamically allocated memory
    free(image);

    return 0;
}

void embed_watermark(pixel* image, char* watermark_text) {
    // Find length of watermark text
    int watermark_length = strlen(watermark_text);

    // Make sure watermark can fit into the image
    if (watermark_length > IMAGE_WIDTH * IMAGE_HEIGHT) {
        printf("Error: Watermark text too long.\n");
        return;
    }

    // Embed watermark into image
    for (int i = 0; i < watermark_length; i++) {
        int pixel_index = i * i % (IMAGE_WIDTH * IMAGE_HEIGHT);
        image[pixel_index].r = watermark_text[i];
        image[pixel_index].g = watermark_text[i];
        image[pixel_index].b = watermark_text[i];
    }
}

void extract_watermark(pixel* image) {
    // Allocate memory for extracted watermark
    char* extracted_watermark = malloc(sizeof(char) * IMAGE_WIDTH * IMAGE_HEIGHT);
    if (extracted_watermark == NULL) {
        printf("Error: Unable to allocate memory for extracted watermark.\n");
        return;
    }

    // Extract watermark from image
    for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT; i++) {
        int watermark_index = i * i % (IMAGE_WIDTH * IMAGE_HEIGHT);
        extracted_watermark[watermark_index] = image[i].r;
    }

    // Print extracted watermark to console
    printf("Extracted Watermark: %s\n", extracted_watermark);

    // Free dynamically allocated memory
    free(extracted_watermark);
}