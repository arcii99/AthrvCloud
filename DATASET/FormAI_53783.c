//FormAI DATASET v1.0 Category: Image Editor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define image size as constant
#define WIDTH 256
#define HEIGHT 256

int main() {
    // create image array of size WIDTH * HEIGHT
    int image[WIDTH][HEIGHT];

    // initialize image array with random grayscale values between 0 to 255
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            image[i][j] = rand() % 256;
        }
    }

    // apply futuristic filter to image
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            // apply edge detection filter
            int gx = abs(image[i+1][j-1] + 2*image[i+1][j] + image[i+1][j+1] - image[i-1][j-1] - 2*image[i-1][j] - image[i-1][j+1]);
            int gy = abs(image[i-1][j-1] + 2*image[i][j-1] + image[i+1][j-1] - image[i-1][j+1] - 2*image[i][j+1] - image[i+1][j+1]);
            int gradient = sqrt(gx*gx + gy*gy);

            // apply color inversion filter
            image[i][j] = 255 - gradient;
        }
    }

    // write image to file
    FILE *fp = fopen("futuristic_image.pgm", "wb");
    fprintf(fp, "P5\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image, sizeof(image), 1, fp);
    fclose(fp);

    return 0;
}