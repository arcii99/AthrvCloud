//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Structure to hold pixel data
typedef struct {
    int r;
    int g;
    int b;
} Pixel;

// Function to add watermark to an image
void add_watermark(Pixel* img, int size, int key, int strength) {
    srand(key); // Seed the random number generator
    for (int i=0; i<size; i++) {
        int rand_num = rand() % 100; // Generate random number between 0 and 99
        if (rand_num < strength) { // If below strength threshold, add watermark
            img[i].r = img[i].r + 50;
            img[i].g = img[i].g + 50;
            img[i].b = img[i].b + 50;
        }
    }
}

int main() {
    // Generate image data
    Pixel img[10] = {{255, 255, 255}, {0, 0, 0}, {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 0}, {255, 0, 255}, {0, 255, 255}, {128, 128, 128}, {64, 64, 64}};
    
    // Add watermark to image with key=123 and strength=50
    add_watermark(img, 10, 123, 50);
    
    // Print out new image data
    printf("New image data:\n");
    for (int i=0; i<10; i++) {
        printf("%d %d %d\n", img[i].r, img[i].g, img[i].b);
    }
    
    return 0;
}