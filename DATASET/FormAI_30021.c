//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to determine if a bit at a particular position is set or not.
bool is_bit_set(int num, int pos) {
    return ((num & (1 << pos)) != 0);
}

// Function to set a bit at a particular position.
int set_bit(int num, int pos) {
    return (num | (1 << pos));
}

// Function to clear a bit at a particular position.
int clear_bit(int num, int pos) {
    return (num & ~(1 << pos));
}

int main() {
    int image_data = 0xABCD1234;
    int watermark_data = 0xFEDCBA98;
    int watermark_length = 8;
    int image_length = 32;
    
    // Print the initial values of the image and watermark data.
    printf("Initial image data: 0x%X\n", image_data);
    printf("Initial watermark data: 0x%X\n", watermark_data);

    // Embed the watermark data into the image data.
    for (int i = 0; i < watermark_length; i++) {
        if (is_bit_set(watermark_data, i)) {
            image_data = set_bit(image_data, i);
        } else {
            image_data = clear_bit(image_data, i);
        }
    }
    
    // Print the final value of the image data with the watermark embedded.
    printf("Image data with watermark embedded: 0x%X\n", image_data);

    // Extract the watermark data from the image data.
    int extracted_watermark_data = 0;
    for (int i = 0; i < watermark_length; i++) {
        if (is_bit_set(image_data, i)) {
            extracted_watermark_data = set_bit(extracted_watermark_data, i);
        } else {
            extracted_watermark_data = clear_bit(extracted_watermark_data, i);
        }
    }
    
    // Print the extracted watermark data.
    printf("Extracted watermark data: 0x%X\n", extracted_watermark_data);

    // Check if the extracted watermark data matches the original watermark data.
    if (extracted_watermark_data == watermark_data) {
        printf("Watermark extraction successful!\n");
    } else {
        printf("Watermark extraction failed!\n");
    }

    return 0;
}