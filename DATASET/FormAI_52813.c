//FormAI DATASET v1.0 Category: Fractal Generation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define UPSAMPLE_FACTOR 2
#define MAX_ITERATIONS 1000
#define SCALE 0.003
#define CENTER_X -0.7545187583824104
#define CENTER_Y 0.05001842515593775

int main(){

    // Create output file and set header
    FILE* ppm = fopen("fractal.ppm", "wb");
    fprintf(ppm, "P6 %d %d 255\n", WIDTH * UPSAMPLE_FACTOR, HEIGHT * UPSAMPLE_FACTOR);

    // Calculate starting and ending coordinates of image
    double x_min = CENTER_X - (WIDTH / 2) * SCALE;
    double x_max = CENTER_X + (WIDTH / 2) * SCALE;
    double y_min = CENTER_Y - (HEIGHT / 2) * SCALE;
    double y_max = CENTER_Y + (HEIGHT / 2) * SCALE;

    // Iterate over all pixels in the image
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){

            double c_real = x_min + (x * SCALE);
            double c_imaginary = y_min + (y * SCALE);

            double z_real = 0;
            double z_imaginary = 0;

            int iterations = 0;

            // Calculate if the current point is in the fractal
            while(z_real * z_real + z_imaginary * z_imaginary < 4 && iterations < MAX_ITERATIONS){
                double new_real = z_real * z_real - z_imaginary * z_imaginary + c_real;
                double new_imaginary = 2 * z_real * z_imaginary + c_imaginary;
                z_real = new_real;
                z_imaginary = new_imaginary;
                iterations++;
            }

            // Map the number of iterations to a color
            double value = (double)iterations / MAX_ITERATIONS;
            unsigned char red = (int)(value * 255);
            unsigned char green = (int)((1 - value) * 255);
            unsigned char blue = (int)((value * value) * 255);

            // Write the color to the output file, upsampled by UPSAMPLE_FACTOR
            for(int i = 0; i < UPSAMPLE_FACTOR; i++){
                for(int j = 0; j < UPSAMPLE_FACTOR; j++){
                    fwrite(&red, sizeof(unsigned char), 1, ppm);
                    fwrite(&green, sizeof(unsigned char), 1, ppm);
                    fwrite(&blue, sizeof(unsigned char), 1, ppm);
                }
            }
        }
    }

    // Close file and finish
    fclose(ppm);
    return 0;
}