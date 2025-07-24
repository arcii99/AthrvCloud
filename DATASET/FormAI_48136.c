//FormAI DATASET v1.0 Category: Fractal Generation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600
#define MAX_ITERATIONS 1000

typedef struct {
    double real;
    double imag;
} complex;

int main(void) {
    srand(time(NULL));
    
    complex c, z;
    int i, j, iterations;
    double x, y, zoom = 1;
    double color;
    
    // allocate memory for the image
    unsigned char *image = (unsigned char*)calloc(WINDOW_WIDTH * WINDOW_HEIGHT * 3, sizeof(unsigned char));
    if (image == NULL) {
        printf("Error: could not allocate memory\n");
        return 1;
    }
    
    // loop over each pixel in the image
    for (j = 0; j < WINDOW_HEIGHT; ++j) {
        for (i = 0; i < WINDOW_WIDTH; ++i) {
            // calculate the complex coordinates of the current pixel
            x = (double)i / WINDOW_WIDTH * 2 - 1;
            y = (double)j / WINDOW_HEIGHT * 2 - 1;
            z.real = x / zoom;
            z.imag = y / zoom;
            
            // iterate the complex function
            iterations = 0;
            while (z.real*z.real + z.imag*z.imag < 4 && iterations < MAX_ITERATIONS) {
                c.real = ((double)rand()/(double)(RAND_MAX)) * 2 - 1;
                c.imag = ((double)rand()/(double)(RAND_MAX)) * 2 - 1;
                z = (complex){z.real*z.real - z.imag*z.imag + c.real, 2 * z.real*z.imag + c.imag};
                ++iterations;
            }
            
            // set the pixel color based on the number of iterations
            color = (double)iterations / MAX_ITERATIONS;
            image[(j * WINDOW_WIDTH + i) * 3 + 0] = color * 255;
            image[(j * WINDOW_WIDTH + i) * 3 + 1] = color * 255;
            image[(j * WINDOW_WIDTH + i) * 3 + 2] = color * 255;
        }
    }
    
    // write the image to a file
    FILE *fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WINDOW_WIDTH, WINDOW_HEIGHT);
    fwrite(image, sizeof(unsigned char), WINDOW_WIDTH * WINDOW_HEIGHT * 3, fp);
    fclose(fp);
    
    // free the memory
    free(image);

    return 0;
}