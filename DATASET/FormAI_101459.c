//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Global variables
unsigned char *image, *ascii_image;
int image_width = 0, image_height = 0;

void read_image_file(char *file_name) {
    FILE *file;
    int i, j;

    file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Error opening image file!\n");
        exit(1);
    }

    // Read image width and height
    fseek(file, 18, SEEK_SET);
    fread(&image_width, sizeof(int), 1, file);
    fread(&image_height, sizeof(int), 1, file);

    // Read image data
    fseek(file, 54, SEEK_SET);
    image = (unsigned char*) malloc(image_width * image_height * 3);
    fread(image, sizeof(unsigned char), image_width * image_height * 3, file);

    fclose(file);
}

void convert_to_ascii() {
    int i, j, k;
    double intensity;

    ascii_image = (unsigned char*) malloc((image_width / 10) * (image_height / 20));

    // Loop through each pixel of the image
    for (i = 0; i < image_height; i += 20) {
        for (j = 0; j < image_width; j += 10) {
            // Calculate the average intensity of the 20x10 pixel block
            intensity = 0;
            for (k = 0; k < 20; k++) {
                intensity += (double) image[((i + k) * image_width + j) * 3] 
                            + (double) image[((i + k) * image_width + j) * 3 + 1]
                            + (double) image[((i + k) * image_width + j) * 3 + 2];
            }
            intensity /= (double) (20 * 10 * 3);

            // Assign the corresponding ASCII character based on intensity
            if (intensity >= 230) {
                ascii_image[i / 20 * (image_width / 10) + j / 10] = ' ';
            } else if (intensity >= 200) {
                ascii_image[i / 20 * (image_width / 10) + j / 10] = '.';
            } else if (intensity >= 175) {
                ascii_image[i / 20 * (image_width / 10) + j / 10] = '*';
            } else if (intensity >= 150) {
                ascii_image[i / 20 * (image_width / 10) + j / 10] = ':';
            } else if (intensity >= 125) {
                ascii_image[i / 20 * (image_width / 10) + j / 10] = 'o';
            } else if (intensity >= 100) {
                ascii_image[i / 20 * (image_width / 10) + j / 10] = '&';
            } else if (intensity >= 75) {
                ascii_image[i / 20 * (image_width / 10) + j / 10] = '8';
            } else if (intensity >= 50) {
                ascii_image[i / 20 * (image_width / 10) + j / 10] = '#';
            } else {
                ascii_image[i / 20 * (image_width / 10) + j / 10] = '@';
            }
        }
    }
}

void print_ascii_image() {
    int i, j;

    for (i = 0; i < image_height / 20; i++) {
        for (j = 0; j < image_width / 10; j++) {
            printf("%c", ascii_image[i * (image_width / 10) + j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image-file>\n", argv[0]);
        exit(1);
    }

    read_image_file(argv[1]);
    convert_to_ascii();
    print_ascii_image();

    free(image);
    free(ascii_image);

    return 0;
}