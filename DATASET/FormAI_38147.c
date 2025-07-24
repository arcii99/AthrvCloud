//FormAI DATASET v1.0 Category: Fractal Generation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 50

int main()
{
    //Create image buffer
    unsigned char *image = malloc(WIDTH * HEIGHT);

    //Define fractal parameters
    double zoom = 1.0;
    double xshift = -0.5;
    double yshift = 0.0;

    //Calculate coordinates for each pixel
    for(int y = 0; y < HEIGHT; y++)
    {
        for(int x = 0; x < WIDTH; x++)
        {
            double complex z = (x - WIDTH/2 + xshift)/zoom + I*(y - HEIGHT/2 + yshift)/zoom;
            double complex c = -0.4 + 0.6*I;
            int iterations = 0;
            while(cabs(z) < 2 && iterations < MAX_ITERATIONS)
            {
                z = z*z + c;
                iterations++;
            }
            image[y*WIDTH + x] = iterations;
        }
    }

    //Write image data to file
    FILE *fp = fopen("fractal.pgm", "wb");
    fprintf(fp, "P5\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image, 1, WIDTH*HEIGHT, fp);
    fclose(fp);

    //Free memory
    free(image);

    return 0;
}