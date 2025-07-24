//FormAI DATASET v1.0 Category: Image Editor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMG_WIDTH 640
#define IMG_HEIGHT 480

struct Color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

struct Image {
    struct Color pixels[IMG_HEIGHT][IMG_WIDTH];
};

void applyFilter(struct Image* img, float* kernel, int kernelSize) {
    // Apply the given kernel to every pixel in the image
    struct Image temp;
    for (int row=0; row<IMG_HEIGHT; row++) {
        for (int col=0; col<IMG_WIDTH; col++) {
            float accumulator_r = 0, accumulator_g = 0, accumulator_b = 0;
            for (int i=0; i<kernelSize; i++) {
                for (int j=0; j<kernelSize; j++) {
                    int x = col - kernelSize/2 + i;
                    int y = row - kernelSize/2 + j;
                    if (x < 0 || x >= IMG_WIDTH || y < 0 || y >= IMG_HEIGHT) continue;
                    float weight = kernel[i*kernelSize+j];
                    accumulator_r += img->pixels[y][x].r * weight;
                    accumulator_g += img->pixels[y][x].g * weight;
                    accumulator_b += img->pixels[y][x].b * weight;
                }
            }
            temp.pixels[row][col].r = (unsigned char) fminf(fmaxf(accumulator_r, 0), 255);
            temp.pixels[row][col].g = (unsigned char) fminf(fmaxf(accumulator_g, 0), 255);
            temp.pixels[row][col].b = (unsigned char) fminf(fmaxf(accumulator_b, 0), 255);
        }
    }
    // Copy the result back into the original image
    for (int row=0; row<IMG_HEIGHT; row++) {
        for (int col=0; col<IMG_WIDTH; col++) {
            img->pixels[row][col] = temp.pixels[row][col];
        }
    }
}

int main() {
    printf("Welcome to the C Image Editor!\n");
    printf("This program will apply a blur filter to a sample image.\n");
    printf("Press any key to continue.\n");
    getchar();

    // Create a sample image to work with
    struct Image img;
    for (int row=0; row<IMG_HEIGHT; row++) {
        for (int col=0; col<IMG_WIDTH; col++) {
            img.pixels[row][col].r = 255;
            img.pixels[row][col].g = (unsigned char) (255.0/IMG_HEIGHT*row);
            img.pixels[row][col].b = (unsigned char) (255.0/IMG_WIDTH*col);
        }
    }

    // Define a Gaussian blur kernel and apply it to the image
    float kernel[] = {0.0625, 0.125, 0.0625,
                      0.125, 0.25 , 0.125,
                      0.0625, 0.125, 0.0625};
    applyFilter(&img, kernel, 3);

    // Output the resulting image as a PPM file
    FILE* fp = fopen("output.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", IMG_WIDTH, IMG_HEIGHT);
    for (int row=0; row<IMG_HEIGHT; row++) {
        for (int col=0; col<IMG_WIDTH; col++) {
            fwrite(&img.pixels[row][col].r, 1, 1, fp);
            fwrite(&img.pixels[row][col].g, 1, 1, fp);
            fwrite(&img.pixels[row][col].b, 1, 1, fp);
        }
    }
    fclose(fp);

    printf("Done! Output saved to output.ppm.\n");
    return 0;
}