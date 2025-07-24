//FormAI DATASET v1.0 Category: Fractal Generation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

int main() {
    // dimensions of the image
    int width = 1280;
    int height = 720;
    
    // create the image buffer
    unsigned char *buffer = (unsigned char *)malloc(width * height * 3);
    
    // complex plane parameters
    double xmin = -2.0;
    double xmax = 2.0;
    double ymin = -1.5;
    double ymax = 1.5;
    
    // iterate over each pixel
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // map pixel coordinates to the complex plane
            double real = xmin + x * (xmax - xmin) / width;
            double imag = ymin + y * (ymax - ymin) / height;
            double complex z = real + imag * I;
            
            // iterate the Mandelbrot function
            int iter = 0;
            double complex c = z;
            while (cabs(z) < 2.0 && iter < 256) {
                z = z * z + c;
                iter++;
            }
            
            // calculate the color of the pixel based on the number of iterations
            double t = (double)iter / (double)256;
            unsigned char r = (unsigned char)(9 * (1 - t) * t * t * t * 255);
            unsigned char g = (unsigned char)(15 * (1 - t) * (1 - t) * t * t * 255);
            unsigned char b = (unsigned char)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
            
            // write the color values to the buffer
            buffer[y * width * 3 + x * 3 + 0] = r;
            buffer[y * width * 3 + x * 3 + 1] = g;
            buffer[y * width * 3 + x * 3 + 2] = b;
        }
    }
    
    // write the buffer to a PPM image file
    FILE *fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", width, height);
    fwrite(buffer, width * height * 3, 1, fp);
    fclose(fp);
    
    // free the image buffer
    free(buffer);
    
    return 0;
}