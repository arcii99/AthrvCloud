//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 16
#define HEIGHT 16
#define MARKER_SIZE 8

unsigned char image[WIDTH][HEIGHT] = {
    { 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51 },
    { 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51 },
    { 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51 },
    { 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51 },
    { 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51 },
    { 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51 },
    { 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51 },
    { 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51 },
    { 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51 },
    { 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51 },
    { 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51 },
    { 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51 },
    { 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51 },
    { 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51 },
    { 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51 },
    { 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51 }
};

unsigned char watermark[MARKER_SIZE] = { 1, 0, 1, 0, 0, 1, 0, 1 };
int watermark_index = 0;

void embed_watermark(unsigned char pixel) {
    int bit_to_embed = watermark[watermark_index % MARKER_SIZE];

    if (bit_to_embed == 1) {
        if (pixel % 2 == 0) {
            pixel++;
        }
    }
    else {
        if (pixel % 2 == 1) {
            pixel--;
        }
    }

    watermark_index++;
}

void embed_watermark_in_image() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            embed_watermark(image[i][j]);
        }
    }
}

int extract_watermark() {
    int sum = 0;

    for (int i = 0; i < MARKER_SIZE; i++) {
        int bit = image[0][i] % 2;
        sum += (bit << i);
    }

    return sum;
}

int main() {
    embed_watermark_in_image();
    printf("Watermark embedded successfully!\n");

    int extracted_watermark = extract_watermark();
    printf("Extracted watermark: %d\n", extracted_watermark);

    return 0;
}