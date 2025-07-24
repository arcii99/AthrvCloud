//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: protected
#include <stdio.h>
#include <stdint.h>

#define IMAGE_WIDTH 150
#define IMAGE_HEIGHT 200
#define IMAGE_SIZE IMAGE_WIDTH * IMAGE_HEIGHT

void embedWatermark(uint8_t* image, uint8_t* watermark);
void extractWatermark(uint8_t* image, uint8_t* watermark);

int main() {
    // Read in image and watermark files
    uint8_t image[IMAGE_SIZE];
    FILE* f1 = fopen("image.raw", "rb");
    fread(image, sizeof(uint8_t), IMAGE_SIZE, f1);
    fclose(f1);

    uint8_t watermark[10] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0};

    // Embed the watermark into the image
    embedWatermark(image, watermark);

    // Extract the watermark from the image
    uint8_t extractedWatermark[10];
    extractWatermark(image, extractedWatermark);

    // Print the extracted watermark
    printf("Extracted Watermark: ");
    for(int i=0; i<10; i++) {
        printf("%d", extractedWatermark[i]);
    }
    printf("\n");

    return 0;
}

void embedWatermark(uint8_t* image, uint8_t* watermark) {
    // Generate random key for embedding
    uint8_t key[10];
    for(int i=0; i<10; i++) {
        key[i] = rand() % 256;
    }

    // Embed the watermark into the image
    for(int i=0; i<10; i++) {
        int pixel = key[i] % IMAGE_SIZE;
        int bit = key[i] % 8;

        uint8_t mask = 0b00000001 << bit;
        if(watermark[i] == 1) {
            image[pixel] |= mask;
        } else {
            image[pixel] &= ~mask;
        }
    }

    // Write the key to a file for later extraction
    FILE* f2 = fopen("key.bin", "wb");
    fwrite(key, sizeof(uint8_t), 10, f2);
    fclose(f2);
}

void extractWatermark(uint8_t* image, uint8_t* watermark) {
    // Read in key used for embedding
    uint8_t key[10];
    FILE* f3 = fopen("key.bin", "rb");
    fread(key, sizeof(uint8_t), 10, f3);
    fclose(f3);

    // Extract the watermark from the image
    for(int i=0; i<10; i++) {
        int pixel = key[i] % IMAGE_SIZE;
        int bit = key[i] % 8;

        uint8_t mask = 0b00000001 << bit;
        if(image[pixel] & mask) {
            watermark[i] = 1;
        } else {
            watermark[i] = 0;
        }
    }
}