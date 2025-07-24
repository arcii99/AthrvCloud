//FormAI DATASET v1.0 Category: Fractal Generation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate a Mandelbrot fractal
int generateMandelbrotFractal(int px, int py, int maxIterations) {
    double x0 = ((double)px - 400.0)/400.0;
    double y0 = ((double)py - 400.0)/400.0;
    double x = 0.0, y = 0.0;
    int iteration = 0;

    while (x*x + y*y < 4.0 && iteration < maxIterations) {
        double xTemp = x*x - y*y + x0;
        y = 2.0 * x * y + y0;
        x = xTemp;
        iteration++;
    }

    return iteration;
}

int main() {
    // Define size of output file and maximum iteration value
    int size = 800;
    int maxIterations = 50;

    // Allocate memory for output buffer
    unsigned char *buffer = malloc(size*size);

    // Generate fractal and store in buffer
    for (int j = 0; j < 800; j++) {
        for (int i = 0; i < 800; i++) {
            int iteration = generateMandelbrotFractal(i, j, maxIterations);
            buffer[j*800 + i] = 255 - (unsigned char)((double)iteration/(double)maxIterations*255.0);
        }
    }

    // Write buffer to output file
    FILE *fp = fopen("fractal.pgm", "wb");
    fprintf(fp, "P5\n%d %d\n255\n", size, size);
    fwrite(buffer, size*size, 1, fp);
    fclose(fp);

    // Free memory allocated for buffer
    free(buffer);

    return 0;
}