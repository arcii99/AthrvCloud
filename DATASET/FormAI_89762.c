//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WATERMARK_SIZE 25 // size of the watermark
#define IMAGE_SIZE 1024 // size of the image

// function to generate a random binary string of length n
char* generate_random_binary_string(int n) {
    char* str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        if (rand() % 2 == 0) {
            str[i] = '0';
        } else {
            str[i] = '1';
        }
    }
    str[n] = '\0';
    return str;
}

// function to add the watermark to the image
void add_watermark(unsigned char* image, char* watermark) {
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        for (int j = 0; j < 8; j++) {
            if (watermark[i] & (1 << j)) {
                // set LSB to 1
                image[i * 8 + j] |= 1;
            } else {
                // set LSB to 0
                image[i * 8 + j] &= ~(1);
            }
        }
    }
}

// function to extract the watermark from the image
char* extract_watermark(unsigned char* image) {
    char* watermark = malloc(WATERMARK_SIZE + 1);
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        watermark[i] = 0;
        for (int j = 0; j < 8; j++) {
            if (image[i * 8 + j] & 1) {
                watermark[i] |= (1 << j);
            }
        }
    }
    watermark[WATERMARK_SIZE] = '\0';
    return watermark;
}

int main() {
    srand(time(NULL)); // seed the random number generator

    unsigned char image[IMAGE_SIZE]; // create image buffer
    memset(image, 0, IMAGE_SIZE);

    char* watermark = generate_random_binary_string(WATERMARK_SIZE);

    printf("Original watermark: %s\n", watermark);

    add_watermark(image, watermark);

    char* extracted_watermark = extract_watermark(image);

    printf("Extracted watermark: %s\n", extracted_watermark);

    if (strcmp(watermark, extracted_watermark) == 0) {
        printf("Watermark successfully extracted!\n");
    } else {
        printf("Failed to extract watermark.\n");
    }

    free(watermark);
    free(extracted_watermark);

    return 0;
}