//FormAI DATASET v1.0 Category: Image compression ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#define IMAGE_HEIGHT 480
#define IMAGE_WIDTH 640

typedef struct rgb {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb_t;

rgb_t** compress(rgb_t image[][IMAGE_WIDTH], int height, int width, int factor) {
    assert(factor > 0 && factor <= height && factor <= width);
    
    int compressed_height = height/factor;
    int compressed_width = width/factor;

    rgb_t** compressed_image = (rgb_t**)malloc(compressed_height * sizeof(rgb_t*));
    for (int h=0; h<compressed_height; h++) {
        compressed_image[h] = (rgb_t*)malloc(compressed_width * sizeof(rgb_t));
        for (int w=0; w<compressed_width; w++) {
            uint32_t r_sum = 0;
            uint32_t g_sum = 0;
            uint32_t b_sum = 0;
            for (int i=0; i<factor; i++) {
                for (int j=0; j<factor; j++) {
                    r_sum += image[factor*h+i][factor*w+j].r;
                    g_sum += image[factor*h+i][factor*w+j].g;
                    b_sum += image[factor*h+i][factor*w+j].b;
                }
            }
            compressed_image[h][w].r = (uint8_t)(r_sum/(factor*factor));
            compressed_image[h][w].g = (uint8_t)(g_sum/(factor*factor));
            compressed_image[h][w].b = (uint8_t)(b_sum/(factor*factor));
        }
    }

    return compressed_image;
}

int main() {
    rgb_t image[IMAGE_HEIGHT][IMAGE_WIDTH]; // Imagine a huge image here
    // Fill image with random RGB values
    for (int h=0; h<IMAGE_HEIGHT; h++) {
        for (int w=0; w<IMAGE_WIDTH; w++) {
            image[h][w].r = (uint8_t)(rand() % 256);
            image[h][w].g = (uint8_t)(rand() % 256);
            image[h][w].b = (uint8_t)(rand() % 256);
        }
    }

    int factor = 5;
    rgb_t** compressed_image = compress(image, IMAGE_HEIGHT, IMAGE_WIDTH, factor);

    printf("Original image height: %d, width: %d\n", IMAGE_HEIGHT, IMAGE_WIDTH);
    printf("Compressed image height: %d, width: %d, factor: %d\n\n", IMAGE_HEIGHT/factor, IMAGE_WIDTH/factor, factor);

    // Print original and compressed image RGB values
    for (int h=0; h<IMAGE_HEIGHT/factor; h++) {
        for (int w=0; w<IMAGE_WIDTH/factor; w++) {
            printf("Original RGB: (%d, %d, %d)\tCompressed RGB: (%d, %d, %d)\n",
                   image[factor*h][factor*w].r, image[factor*h][factor*w].g, image[factor*h][factor*w].b,
                   compressed_image[h][w].r, compressed_image[h][w].g, compressed_image[h][w].b);
        }
    }

    // Free memory
    for (int h=0; h<IMAGE_HEIGHT/factor; h++) {
        free(compressed_image[h]);
    }
    free(compressed_image);

    return 0;
}