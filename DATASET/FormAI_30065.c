//FormAI DATASET v1.0 Category: Image Editor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 512

int main(int argc, char *argv[]) {
    // Load image file and store data in memory
    FILE *image_file = fopen(argv[1], "rb");
    if (image_file == NULL) {
        printf("Error: Cannot open image file!\n");
        exit(1);
    }

    // Parse image file header to get image size, dimensions, and color depth
    int width, height, depth;
    char format[MAX_LINE_LENGTH];
    fscanf(image_file, "%s", format);
    fscanf(image_file, "%d %d", &width, &height);
    fscanf(image_file, "%d", &depth);

    // Allocate memory for storing image pixel values
    unsigned char *pixels = (unsigned char *) malloc(sizeof(unsigned char) * width * height);

    // Read pixel values from image file into memory
    fread(pixels, sizeof(unsigned char), width * height, image_file);

    // Close image file
    fclose(image_file);

    // Image editing options
    int option = 1;
    while (option != 0) {
        printf("Choose an option:\n");
        printf("1. Add brightness\n");
        printf("2. Add contrast\n");
        printf("3. Rotate left\n");
        printf("4. Rotate right\n");
        printf("0. Save and exit\n");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                // Add brightness to image
                for (int i = 0; i < width * height; i++) {
                    pixels[i] += 20;
                }
                break;
            case 2:
                // Add contrast to image
                for (int i = 0; i < width * height; i++) {
                    if (pixels[i] < depth / 2) {
                        pixels[i] -= 20;
                    } else {
                        pixels[i] += 20;
                    }
                }
                break;
            case 3:
                // Rotate image left (90 degrees)
                unsigned char *new_pixels = (unsigned char *) malloc(sizeof(unsigned char) * width * height);
                for (int i = 0; i < height; i++) {
                    for (int j = 0; j < width; j++) {
                        new_pixels[i * width + j] = pixels[j * height + height - i - 1];
                    }
                }
                free(pixels);
                pixels = new_pixels;
                int temp = width;
                width = height;
                height = temp;
                break;
            case 4:
                // Rotate image right (90 degrees)
                new_pixels = (unsigned char *) malloc(sizeof(unsigned char) * width * height);
                for (int i = 0; i < height; i++) {
                    for (int j = 0; j < width; j++) {
                        new_pixels[i * width + j] = pixels[(width - j - 1) * height + i];
                    }
                }
                free(pixels);
                pixels = new_pixels;
                temp = width;
                width = height;
                height = temp;
                break;
            case 0:
                // Save edited image data to file
                image_file = fopen(argv[1], "wb");
                fprintf(image_file, "%s\n", format);
                fprintf(image_file, "%d %d\n", width, height);
                fprintf(image_file, "%d\n", depth);
                fwrite(pixels, sizeof(unsigned char), width * height, image_file);
                fclose(image_file);
                free(pixels);
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    }
    return 0;
}