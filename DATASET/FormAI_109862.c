//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flip_image(int rows, int cols, unsigned char *input_image, unsigned char *output_image) {
    int i, j, index;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            index = (i * cols) + j;
            output_image[index] = input_image[((rows - 1 - i) * cols) + j];
        }
    }
}

void change_contrast(int rows, int cols, unsigned char *input_image, unsigned char *output_image, float contrast) {
    int i, j, index;
    unsigned char pixel;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            index = (i * cols) + j;
            pixel = *(input_image + index);
            pixel = (pixel - 128) * contrast + 128;
            *(output_image + index) = pixel;
        }
    }
}

void change_brightness(int rows, int cols, unsigned char *input_image, unsigned char *output_image, int brightness) {
    int i, j, index;
    unsigned char pixel;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            index = (i * cols) + j;
            pixel = *(input_image + index);
            pixel += brightness;
            if (pixel > 255) {
                pixel = 255;
            } else if (pixel < 0) {
                pixel = 0;
            }
            *(output_image + index) = pixel;
        }
    }
}

int main() {
    char input_file_name[100];
    char output_file_name[100];
    int operation_choice;
    int i;
    int rows, cols, maxval;
    unsigned char *image_data, *output_image_data;

    printf("Enter input file name (PGM): ");
    scanf("%s", input_file_name);
    printf("Enter output file name (PGM): ");
    scanf("%s", output_file_name);

    FILE *input_file = fopen(input_file_name, "rb");

    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    char format_line[2];

    fscanf(input_file, "%s", format_line);

    if (strcmp(format_line, "P5") != 0) {
        printf("Error: input file format not supported.\n");
        exit(1);
    }

    fscanf(input_file, "%d %d", &cols, &rows);

    fscanf(input_file, "%d", &maxval);

    if (maxval != 255) {
        printf("Error: input file does not use 8-bit color values.\n");
        exit(1);
    }

    image_data = (unsigned char *)malloc(rows * cols * sizeof(unsigned char));

    fread(image_data, 1, rows * cols, input_file);

    fclose(input_file);

    output_image_data = (unsigned char *)malloc(rows * cols * sizeof(unsigned char));

    printf("What operation do you want to perform on the image?\n");
    printf("1. Flip the image\n");
    printf("2. Change the contrast of the image\n");
    printf("3. Change the brightness of the image\n");

    scanf("%d", &operation_choice);

    switch (operation_choice) {
        case 1:
            flip_image(rows, cols, image_data, output_image_data);
            break;
        case 2:
            float contrast_value;
            printf("Enter contrast value: ");
            scanf("%f", &contrast_value);
            change_contrast(rows, cols, image_data, output_image_data, contrast_value);
            break;
        case 3:
            int brightness_value;
            printf("Enter brightness value: ");
            scanf("%d", &brightness_value);
            change_brightness(rows, cols, image_data, output_image_data, brightness_value);
            break;
        default:
            printf("Error: invalid operation choice.\n");
            exit(1);
    }

    FILE *output_file = fopen(output_file_name, "wb");

    fprintf(output_file, "P5\n%d %d\n%d\n", cols, rows, 255);

    fwrite(output_image_data, 1, rows * cols, output_file);

    fclose(output_file);

    free(image_data);
    free(output_image_data);

    printf("Image processing complete!\n");

    return 0;
}