//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Defining variables
    int rows, cols, i, j;
    unsigned char data[512][512], new_data[512][512];
    double alpha, beta;

    // Reading the image file
    FILE *fp = fopen("input_image.raw", "rb");
    fread(data, sizeof(unsigned char), 512*512, fp);
    fclose(fp);

    // Task 1: Flipping the image horizontally
    for (i = 0; i < 512; i++) {
        for (j = 0; j < 512; j++) {
            new_data[i][j] = data[i][511-j];
        }
    }

    // Writing the flipped image to a new file
    fp = fopen("output_image_flip.raw", "wb");
    fwrite(new_data, sizeof(unsigned char), 512*512, fp);
    fclose(fp);

    // Task 2: Increasing the brightness of the image by 50%
    alpha = 1.5; // brightness adjustment parameter
    beta = 0; // bias parameter
    for (i = 0; i < 512; i++) {
        for (j = 0; j < 512; j++) {
            new_data[i][j] = (unsigned char) fmin(alpha * data[i][j] + beta, 255.0);
        }
    }

    // Writing the brightness-adjusted image to a new file
    fp = fopen("output_image_bright.raw", "wb");
    fwrite(new_data, sizeof(unsigned char), 512*512, fp);
    fclose(fp);

    // Task 3: Increasing the contrast of the image by 50%
    double mean, std_dev, sum = 0, sum_squares = 0;
    for (i = 0; i < 512; i++) {
        for (j = 0; j < 512; j++) {
            sum += data[i][j];
            sum_squares += pow(data[i][j], 2);
        }
    }
    mean = sum / (512.0 * 512.0);
    std_dev = sqrt(sum_squares / (512.0 * 512.0) - pow(mean, 2));
    for (i = 0; i < 512; i++) {
        for (j = 0; j < 512; j++) {
            new_data[i][j] = (unsigned char) fmax(fmin(128 + 0.5 * (data[i][j] - mean) / std_dev, 255.0), 0.0);
        }
    }

    // Writing the contrast-adjusted image to a new file
    fp = fopen("output_image_contrast.raw", "wb");
    fwrite(new_data, sizeof(unsigned char), 512*512, fp);
    fclose(fp);

    printf("Image processing tasks completed successfully!\n");

    return 0;
}