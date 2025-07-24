//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

typedef struct Image {
    int width;
    int height;
    unsigned char* pixels;
} Image;

Image* loadImage(const char* filename) {
    // Load image using your favorite library
}

void flipHorizontal(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            int leftIdx = (y * img->width + x) * 3;
            int rightIdx = (y * img->width + (img->width - 1 - x)) * 3;
            unsigned char tempR = img->pixels[leftIdx + 0];
            unsigned char tempG = img->pixels[leftIdx + 1];
            unsigned char tempB = img->pixels[leftIdx + 2];
            img->pixels[leftIdx + 0] = img->pixels[rightIdx + 0];
            img->pixels[leftIdx + 1] = img->pixels[rightIdx + 1];
            img->pixels[leftIdx + 2] = img->pixels[rightIdx + 2];
            img->pixels[rightIdx + 0] = tempR;
            img->pixels[rightIdx + 1] = tempG;
            img->pixels[rightIdx + 2] = tempB;
        }
    }
}

void changeBrightness(Image* img, float brightness) {
    for (int i = 0; i < img->width * img->height * 3; i++) {
        int value = img->pixels[i] + brightness * 255;
        img->pixels[i] = value < 0 ? 0 : (value > 255 ? 255 : value);
    }
}

void changeContrast(Image* img, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < img->width * img->height * 3; i++) {
        int value = factor * (img->pixels[i] - 128) + 128;
        img->pixels[i] = value < 0 ? 0 : (value > 255 ? 255 : value);
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    Image* img = loadImage(argv[1]);
    flipHorizontal(img);
    changeBrightness(img, 0.4);
    changeContrast(img, 1.5);
    // Save the modified image using your favorite library
    return 0;
}