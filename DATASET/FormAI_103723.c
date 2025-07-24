//FormAI DATASET v1.0 Category: Fractal Generation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int width = 320;
    int height = 240;
    int max_iterations = 200;

    // Allocate memory for the image
    int *image = (int *)malloc(sizeof(int) * width * height);
    if (!image) {
        printf("Error: unable to allocate memory!");
        return 1;
    }

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Set the initial values of the corners
    image[0] = (int)(255 * (double)rand() / RAND_MAX);
    image[width - 1] = (int)(255 * (double)rand() / RAND_MAX);
    image[width * (height - 1)] = (int)(255 * (double)rand() / RAND_MAX);
    image[width * height - 1] = (int)(255 * (double)rand() / RAND_MAX);

    // Generate fractal
    for (int i = 0; i < log2(width); i++) {
        int step_size = pow(2, log2(width) - i);
        int half_step = step_size / 2;

        // Diamond step
        for (int y = half_step; y < height; y += step_size) {
            for (int x = half_step; x < width; x += step_size) {
                int sum = 0;
                sum += image[(y - half_step) * width + (x - half_step)];
                sum += image[(y - half_step) * width + (x + half_step)];
                sum += image[(y + half_step) * width + (x - half_step)];
                sum += image[(y + half_step) * width + (x + half_step)];
                image[y * width + x] = (int)(sum / 4.0 + (rand() % 101 - 50) * 255.0 / 100.0);
            }
        }

        // Square step
        for (int y = 0; y < height; y += step_size) {
            for (int x = half_step * ((y + half_step) / step_size % 2 == 0 ? 1 : 0); x < width; x += step_size) {
                int sum = 0;
                int count = 0;
                if (x - half_step >= 0) {
                    sum += image[y * width + (x - half_step)];
                    count++;
                }
                if (y - half_step >= 0) {
                    sum += image[(y - half_step) * width + x];
                    count++;
                }
                if (x + half_step < width) {
                    sum += image[y * width + (x + half_step)];
                    count++;
                }
                if (y + half_step < height) {
                    sum += image[(y + half_step) * width + x];
                    count++;
                }
                image[y * width + x] = (int)(sum / (double)count + (rand() % 101 - 50) * 255.0 / 100.0);
            }
        }
    }

    // Normalize the values to the range [0, 255]
    int min = image[0];
    int max = image[0];
    for (int i = 0; i < width * height; i++) {
        if (image[i] < min) {
            min = image[i];
        }
        if (image[i] > max) {
            max = image[i];
        }
    }
    double scale = 255.0 / (max - min);
    for (int i = 0; i < width * height; i++) {
        image[i] = (int)((image[i] - min) * scale);
    }

    // Write the image to a file
    FILE *fp;
    fp = fopen("fractal.pgm", "wb");
    fprintf(fp, "P5\n%d %d\n255\n", width, height);
    for (int i = 0; i < width * height; i++) {
        fputc(image[i], fp);
    }
    fclose(fp);

    // Free the memory
    free(image);

    return 0;
}