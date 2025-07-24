//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: energetic
#include <stdio.h>
#include <string.h>

// Define the watermark string
#define WATERMARK "This image is copyrighted"

// Define the image struct
typedef struct {
    int width;
    int height;
    char data[1024];
} Image;

// Define the function for embedding the watermark
void embed_watermark(Image* image) {
    // Calculate the length of the watermark
    int length = strlen(WATERMARK);

    // Embed the watermark into the image data
    for (int i = 0; i < length; i++) {
        image->data[i] ^= WATERMARK[i];
    }
}

// Define the function for extracting the watermark
void extract_watermark(Image* image) {
    // Calculate the length of the watermark
    int length = strlen(WATERMARK);

    // Extract the watermark from the image data
    char extracted_watermark[length + 1];
    for (int i = 0; i < length; i++) {
        extracted_watermark[i] = image->data[i] ^ WATERMARK[i];
    }
    extracted_watermark[length] = '\0';

    // Print the extracted watermark
    printf("Extracted watermark: %s\n", extracted_watermark);
}

int main() {
    // Create an example image
    Image example_image = { .width = 16, .height = 16, .data = "0123456789abcdef" };

    // Embed the watermark into the image
    embed_watermark(&example_image);

    // Print the image data (with watermark embedded)
    printf("Image data (with watermark embedded):\n%s\n", example_image.data);

    // Extract the watermark from the image
    extract_watermark(&example_image);

    return 0;
}