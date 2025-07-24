//FormAI DATASET v1.0 Category: Image Editor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 640
#define HEIGHT 480
#define MAX_PIXEL_VALUE 255

unsigned char image[WIDTH * HEIGHT * 3];

void readImage(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    fread(image, sizeof(unsigned char), WIDTH * HEIGHT * 3, fp);
    fclose(fp);
}

void writeImage(char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    fwrite(image, sizeof(unsigned char), WIDTH * HEIGHT * 3, fp);
    fclose(fp);
}

void invertColors() {
    for (int i = 0; i < WIDTH * HEIGHT * 3; i++) {
        image[i] = MAX_PIXEL_VALUE - image[i];
    }
}

void addNoise() {
    for (int i = 0; i < WIDTH * HEIGHT * 3; i++) {
        int noise = rand() % 21 - 10;
        if (image[i] + noise > MAX_PIXEL_VALUE) {
            image[i] = MAX_PIXEL_VALUE;
        } else if (image[i] + noise < 0) {
            image[i] = 0;
        } else {
            image[i] += noise;
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: ./imageeditor <input_filename> <output_filename>\n");
        return 0;
    }

    char* input_filename = argv[1];
    char* output_filename = argv[2];

    readImage(input_filename);

    // Paranoid Style:
    // Invert colors twice to ensure they are back to the original values
    invertColors();
    invertColors();

    // Add noise to the image
    addNoise();

    writeImage(output_filename);

    return 0;
}