//FormAI DATASET v1.0 Category: Image Editor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 256
#define HEIGHT 256

// Function to read image data from file
void read_image(char filename[], unsigned char image[][WIDTH]){
    FILE *file = fopen(filename, "r");
    if(!file) {
        printf("Error opening file\n");
        return;
    }
    fread(image, sizeof(unsigned char), WIDTH * HEIGHT, file);
    fclose(file);
}

// Function to write image data to file
void write_image(char filename[], unsigned char image[][WIDTH]){
    FILE *file = fopen(filename, "w");
    fwrite(image, sizeof(unsigned char), WIDTH * HEIGHT, file);
    fclose(file);
}

// Function to apply a Gaussian blur to the image
void gaussian_blur(unsigned char image[][WIDTH], float sigma) {
    int i, j, k, l;
    int size = (int)(3 * sigma) * 2 + 1;
    float kernel[size][size];
    float sum = 0.0;

    // Generate Gaussian kernel
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            kernel[i][j] = exp(-((i - size/2) * (i - size/2) + (j - size/2) * (j - size/2)) / (2.0 * sigma * sigma));
            sum += kernel[i][j];
        }
    }

    // Normalize kernel
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            kernel[i][j] /= sum;
        }
    }

    // Apply Gaussian blur
    int offset = size / 2;
    unsigned char temp_image[HEIGHT][WIDTH];

    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            float value = 0.0;
            for(k = -offset; k <= offset; k++) {
                for(l = -offset; l <= offset; l++) {
                    int x = i + k;
                    int y = j + l;
                    if(x < 0) x = 0;
                    if(y < 0) y = 0;
                    if(x >= HEIGHT) x = HEIGHT - 1;
                    if(y >= WIDTH) y = WIDTH - 1;
                    value += kernel[k + offset][l + offset] * image[x][y];
                }
            }
            temp_image[i][j] = (unsigned char)value;
        }
    }

    memcpy(image, temp_image, WIDTH * HEIGHT * sizeof(unsigned char));
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <inputfile>\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[1];
    char output_filename[256];
    sprintf(output_filename, "output_%s", input_filename);

    unsigned char image[HEIGHT][WIDTH];

    // Read input image
    read_image(input_filename, image);

    // Apply Gaussian blur
    gaussian_blur(image, 3.0);

    // Write output image
    write_image(output_filename, image);

    return 0;
}