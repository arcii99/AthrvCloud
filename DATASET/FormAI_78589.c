//FormAI DATASET v1.0 Category: Image compression ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define RGB_COMPONENT_COLOR 255

// function prototype
unsigned char ***allocate_memory(int height, int width);

int main()
{
    char input_file[100], output_file[100];
    FILE *fp;
    int i, j, k, height, width, rgb_max, option;
    unsigned char ***image_data;

    printf("1. Compress an image\n2. Decompress an image\nEnter option: ");
    scanf("%d", &option);

    if (option == 1) {
        printf("Enter the name of the image file you want to compress: ");
        scanf("%s", input_file);

        // read the ppm image header
        fp = fopen(input_file, "rb");
        if (!fp) {
            printf("Error: File not found\n");
            exit(1);
        }

        char header[50], format[10];
        fgets(header, 50, fp);
        fgets(header, 50, fp);
        sscanf(header, "%d %d", &width, &height);
        fgets(header, 50, fp);
        sscanf(header, "%d", &rgb_max);
        if (rgb_max != RGB_COMPONENT_COLOR) {
            printf("Error: Not a valid PPM image\n");
            exit(1);
        }

        // allocate memory for the ppm image data
        image_data = allocate_memory(height, width);

        // read and store ppm image data
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                for (k = 0; k < 3; k++) {
                    image_data[i][j][k] = fgetc(fp);
                }
            }
        }

        // compress the data by half
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                for (k = 0; k < 3; k++) {
                    image_data[i][j][k] /= 2;
                }
            }
        }

        // save the compressed ppm image data to the output file
        printf("Enter a name for the compressed image file: ");
        scanf("%s", output_file);
        FILE *fpo = fopen(output_file, "wb");
        fprintf(fpo, "P6\n%d %d\n%d\n", width, height, rgb_max);
        for (i = 0; i < height; ++i) {
            for (j = 0; j < width; ++j) {
                for (k = 0; k < 3; ++k) {
                    fputc(image_data[i][j][k], fpo);
                }
            }
        }

        // free dynamically allocated memory
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                free(image_data[i][j]);
            }
            free(image_data[i]);
        }
        free(image_data);

        printf("Image compression completed!\n");
    } else if (option == 2) {
        printf("Enter the name of the compressed image file you want to decompress: ");
        scanf("%s", input_file);

        // read the ppm image header
        fp = fopen(input_file, "rb");
        if (!fp) {
            printf("Error: File not found\n");
            exit(1);
        }

        char header[50], format[10];
        fgets(header, 50, fp);
        fgets(header, 50, fp);
        sscanf(header, "%d %d", &width, &height);
        fgets(header, 50, fp);
        sscanf(header, "%d", &rgb_max);
        if (rgb_max != RGB_COMPONENT_COLOR) {
            printf("Error: Not a valid PPM image\n");
            exit(1);
        }

        // allocate memory for the ppm image data
        image_data = allocate_memory(height, width);

        // read and store ppm image data
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                for (k = 0; k < 3; k++) {
                    image_data[i][j][k] = fgetc(fp);
                }
            }
        }

        // decompress the data by doubling each value
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                for (k = 0; k < 3; k++) {
                    image_data[i][j][k] *= 2;
                }
            }
        }

        // save the decompressed ppm image data to the output file
        printf("Enter a name for the decompressed image file: ");
        scanf("%s", output_file);
        FILE *fpo = fopen(output_file, "wb");
        fprintf(fpo, "P6\n%d %d\n%d\n", width, height, rgb_max);
        for (i = 0; i < height; ++i) {
            for (j = 0; j < width; ++j) {
                for (k = 0; k < 3; ++k) {
                    fputc(image_data[i][j][k], fpo);
                }
            }
        }

        // free dynamically allocated memory
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                free(image_data[i][j]);
            }
            free(image_data[i]);
        }
        free(image_data);

        printf("Image decompression completed!\n");
    } else {
        printf("Invalid option selected.\n");
    }

    return 0;
}

// function to allocate memory for ppm image data
unsigned char ***allocate_memory(int height, int width) {
    unsigned char ***image_data = NULL;
    int i, j;

    image_data = (unsigned char ***)malloc(height * sizeof(unsigned char**));
    for (i = 0; i < height; i++) {
        image_data[i] = (unsigned char **)malloc(width * sizeof(unsigned char*));
        for (j = 0; j < width; j++) {
            image_data[i][j] = (unsigned char *)malloc(3 * sizeof(unsigned char));
        }
    }

    return image_data;
}