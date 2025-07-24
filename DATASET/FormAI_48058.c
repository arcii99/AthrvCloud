//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_IMAGE_SIZE 512

int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
int flipped_image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];

int main() {
    FILE *fp_in, *fp_out;
    char input_file_name[100], output_file_name[100];
    int i, j, k, x, y, width, height, maxval, brightness, contrast;
    unsigned char c;
    double factor, pixel, minval, maxval_f, temp_pixel;

    /* Ask user for the input file */
    printf("Enter the input image filename: ");
    scanf("%s", input_file_name);

    /* Read the input file */
    fp_in = fopen(input_file_name, "rb");
    if (fp_in == NULL) {
        fprintf(stderr, "Unable to open file %s\n", input_file_name);
        exit(1);
    }

    /* Read the magic number */
    fscanf(fp_in, "P5\n");

    /* Read the width, height and maximum value */
    fscanf(fp_in, "%d %d\n", &width, &height);
    fscanf(fp_in, "%d\n", &maxval);

    /* Make sure the image is not too big */
    if (width > MAX_IMAGE_SIZE || height > MAX_IMAGE_SIZE) {
        fprintf(stderr, "Image is too big. The maximum size is %dx%d\n", MAX_IMAGE_SIZE, MAX_IMAGE_SIZE);
        exit(1);
    }

    /* Read the pixels */
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            c = fgetc(fp_in);
            if (c == EOF) {
                fprintf(stderr, "Unexpected end of file\n");
                exit(1);
            }
            image[i][j] = (int) c;
        }
    }

    /* Close the input file */
    fclose(fp_in);

    /* Ask the user to select the operation */
    printf("Select an operation:\n");
    printf("1. Flip the image horizontally\n");
    printf("2. Increase brightness\n");
    printf("3. Decrease brightness\n");
    printf("4. Increase contrast\n");
    printf("5. Decrease contrast\n");
    printf("Enter your choice: ");
    scanf("%d", &k);

    switch (k) {
        case 1:
            /* Flip the image horizontally */
            for (i = 0; i < height; i++) {
                for (j = 0; j < width; j++) {
                    flipped_image[i][j] = image[i][width - j - 1];
                }
            }

            /* Save the flipped image */
            printf("Enter the output image filename: ");
            scanf("%s", output_file_name);
            fp_out = fopen(output_file_name, "wb");
            if (fp_out == NULL) {
                fprintf(stderr, "Unable to create file %s\n", output_file_name);
                exit(1);
            }
            fprintf(fp_out, "P5\n");
            fprintf(fp_out, "%d %d\n", width, height);
            fprintf(fp_out, "%d\n", maxval);
            for (i = 0; i < height; i++) {
                for (j = 0; j < width; j++) {
                    fputc((unsigned char) flipped_image[i][j], fp_out);
                }
            }
            fclose(fp_out);
            printf("Image flipped successfully!\n");
            break;
        case 2:
            /* Increase brightness */
            printf("Enter the brightness value between 0 and 255: ");
            scanf("%d", &brightness);
            if (brightness < 0 || brightness > 255) {
                fprintf(stderr, "Brightness value should be between 0 and 255\n");
                exit(1);
            }
            for (i = 0; i < height; i++) {
                for (j = 0; j < width; j++) {
                    pixel = (double) image[i][j];
                    pixel += brightness;
                    if (pixel > maxval) {
                        pixel = maxval;
                    }
                    image[i][j] = (int) pixel;
                }
            }

            /* Save the modified image */
            printf("Enter the output image filename: ");
            scanf("%s", output_file_name);
            fp_out = fopen(output_file_name, "wb");
            if (fp_out == NULL) {
                fprintf(stderr, "Unable to create file %s\n", output_file_name);
                exit(1);
            }
            fprintf(fp_out, "P5\n");
            fprintf(fp_out, "%d %d\n", width, height);
            fprintf(fp_out, "%d\n", maxval);
            for (i = 0; i < height; i++) {
                for (j = 0; j < width; j++) {
                    fputc((unsigned char) image[i][j], fp_out);
                }
            }
            fclose(fp_out);
            printf("Image brightness increased successfully!\n");
            break;
        case 3:
            /* Decrease brightness */
            printf("Enter the brightness value between 0 and 255: ");
            scanf("%d", &brightness);
            if (brightness < 0 || brightness > 255) {
                fprintf(stderr, "Brightness value should be between 0 and 255\n");
                exit(1);
            }
            for (i = 0; i < height; i++) {
                for (j = 0; j < width; j++) {
                    pixel = (double) image[i][j];
                    pixel -= brightness;
                    if (pixel < 0) {
                        pixel = 0;
                    }
                    image[i][j] = (int) pixel;
                }
            }

            /* Save the modified image */
            printf("Enter the output image filename: ");
            scanf("%s", output_file_name);
            fp_out = fopen(output_file_name, "wb");
            if (fp_out == NULL) {
                fprintf(stderr, "Unable to create file %s\n", output_file_name);
                exit(1);
            }
            fprintf(fp_out, "P5\n");
            fprintf(fp_out, "%d %d\n", width, height);
            fprintf(fp_out, "%d\n", maxval);
            for (i = 0; i < height; i++) {
                for (j = 0; j < width; j++) {
                    fputc((unsigned char) image[i][j], fp_out);
                }
            }
            fclose(fp_out);
            printf("Image brightness decreased successfully!\n");
            break;
        case 4:
            /* Increase contrast */
            printf("Enter the contrast value between 0 and 255: ");
            scanf("%d", &contrast);
            if (contrast < 0 || contrast > 255) {
                fprintf(stderr, "Contrast value should be between 0 and 255\n");
                exit(1);
            }
            minval = 255;
            maxval_f = 0.0;
            for (i = 0; i < height; i++) {
                for (j = 0; j < width; j++) {
                    if ((double) image[i][j] < minval) {
                        minval = (double) image[i][j];
                    }
                    if ((double) image[i][j] > maxval_f) {
                        maxval_f = (double) image[i][j];
                    }
                }
            }
            factor = (255.0 - (double) contrast) / (maxval_f - minval);
            for (i = 0; i < height; i++) {
                for (j = 0; j < width; j++) {
                    temp_pixel = factor * ((double) image[i][j] - minval) + (double) contrast;
                    if (temp_pixel < 0) {
                        image[i][j] = 0;
                    } else if (temp_pixel > 255) {
                        image[i][j] = 255;
                    } else {
                        image[i][j] = (int) temp_pixel;
                    }
                }
            }

            /* Save the modified image */
            printf("Enter the output image filename: ");
            scanf("%s", output_file_name);
            fp_out = fopen(output_file_name, "wb");
            if (fp_out == NULL) {
                fprintf(stderr, "Unable to create file %s\n", output_file_name);
                exit(1);
            }
            fprintf(fp_out, "P5\n");
            fprintf(fp_out, "%d %d\n", width, height);
            fprintf(fp_out, "%d\n", maxval);
            for (i = 0; i < height; i++) {
                for (j = 0; j < width; j++) {
                    fputc((unsigned char) image[i][j], fp_out);
                }
            }
            fclose(fp_out);
            printf("Image contrast increased successfully!\n");
            break;
        case 5:
            /* Decrease contrast */
            printf("Enter the contrast value between 0 and 255: ");
            scanf("%d", &contrast);
            if (contrast < 0 || contrast > 255) {
                fprintf(stderr, "Contrast value should be between 0 and 255\n");
                exit(1);
            }
            minval = 255;
            maxval_f = 0.0;
            for (i = 0; i < height; i++) {
                for (j = 0; j < width; j++) {
                    if ((double) image[i][j] < minval) {
                        minval = (double) image[i][j];
                    }
                    if ((double) image[i][j] > maxval_f) {
                        maxval_f = (double) image[i][j];
                    }
                }
            }
            factor = (255.0 + (double) contrast) / (maxval_f - minval);
            for (i = 0; i < height; i++) {
                for (j = 0; j < width; j++) {
                    temp_pixel = factor * ((double) image[i][j] - minval) - (double) contrast;
                    if (temp_pixel < 0) {
                        image[i][j] = 0;
                    } else if (temp_pixel > 255) {
                        image[i][j] = 255;
                    } else {
                        image[i][j] = (int) temp_pixel;
                    }
                }
            }

            /* Save the modified image */
            printf("Enter the output image filename: ");
            scanf("%s", output_file_name);
            fp_out = fopen(output_file_name, "wb");
            if (fp_out == NULL) {
                fprintf(stderr, "Unable to create file %s\n", output_file_name);
                exit(1);
            }
            fprintf(fp_out, "P5\n");
            fprintf(fp_out, "%d %d\n", width, height);
            fprintf(fp_out, "%d\n", maxval);
            for (i = 0; i < height; i++) {
                for (j = 0; j < width; j++) {
                    fputc((unsigned char) image[i][j], fp_out);
                }
            }
            fclose(fp_out);
            printf("Image contrast decreased successfully!\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}