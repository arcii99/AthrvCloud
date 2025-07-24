//FormAI DATASET v1.0 Category: Fractal Generation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define imageWidth 800
#define imageHeight 800
#define maxIterations 1000

unsigned char image[imageHeight][imageWidth][3];

int main(int argc, char **argv) {

    double minX = -2.5;
    double maxX = 1.5;
    double minY = -2.0;
    double maxY = 2.0;

    double pixelWidth = (maxX - minX) / imageWidth;
    double pixelHeight = (maxY - minY) / imageHeight;

#pragma omp parallel for schedule(dynamic, 1)
    for (int row = 0; row < imageHeight; row++) {
        for (int col = 0; col < imageWidth; col++) {

            double x0 = minX + col * pixelWidth;
            double y0 = minY + row * pixelHeight;

            double x = 0.0f;
            double y = 0.0f;
            int iteration = 0;

            while (x*x + y*y < 2*2 && iteration < maxIterations) {
                double xtemp = x*x - y*y + x0;
                y = 2*x*y + y0;
                x = xtemp;
                iteration++;
            }

            if (iteration == maxIterations) {
                image[row][col][0] = 0;
                image[row][col][1] = 0;
                image[row][col][2] = 0;
            } else {
                double log_zn = log(x*x + y*y) / 2;
                double nu = log(log_zn / log(2)) / log(2);
                iteration = iteration + 1 - nu;

                image[row][col][0] = 255 - (int)(iteration * 3) % 255;
                image[row][col][1] = 0;
                image[row][col][2] = (int)(iteration * 7) % 255;
            }
        }
    }

    // Save image to file
    FILE *fp;
    char *filename = "mandelbrot.ppm";
    fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", imageWidth, imageHeight);
    fwrite(image, sizeof(unsigned char), imageHeight * imageWidth * 3, fp);
    fclose(fp);

    printf("Mandelbrot set saved to %s\n", filename);

    return 0;
}