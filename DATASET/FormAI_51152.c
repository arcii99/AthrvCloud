//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_SIZE 1024
#define WATERMARK_SIZE 16

// Helper function to print an array of zeros and ones
void print_array(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

// Helper function to convert a char to an array of ones and zeros
void char_to_binary(char c, int* arr) {
    for (int i = 7; i >= 0; i--) {
        arr[7-i] = (c >> i) & 1;
    }
}

// Helper function to convert an array of ones and zeros to a char
char binary_to_char(int* arr) {
    char c = 0;
    for (int i = 0; i < 8; i++) {
        c += arr[i] << (7-i);
    }
    return c;
}

// Function to embed the watermark into the image
void embed_watermark(int* image, int* watermark) {
    // Embed the watermark into the first row of the image
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        image[i] = (image[i] & ~1) | watermark[i];
    }
}

// Function to extract the watermark from the image
void extract_watermark(int* image, int* watermark) {
    // Extract the watermark from the first row of the image
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        watermark[i] = image[i] & 1;
    }
}

int main() {
    // Initialize the image and watermark as arrays of zeros and ones
    int image[IMAGE_SIZE];
    int watermark[WATERMARK_SIZE];
    memset(image, 0, sizeof(image));
    memset(watermark, 0, sizeof(watermark));

    // Convert the watermark to an array of ones and zeros
    char_to_binary('W', watermark);

    // Embed the watermark into the image
    embed_watermark(image, watermark);

    // Extract the watermark from the image
    int extracted_watermark[WATERMARK_SIZE];
    extract_watermark(image, extracted_watermark);

    // Convert the extracted watermark to a char and print it
    char extracted_char = binary_to_char(extracted_watermark);
    printf("Extracted watermark: %c\n", extracted_char);

    return 0;
}