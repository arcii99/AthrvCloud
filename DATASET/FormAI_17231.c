//FormAI DATASET v1.0 Category: Fractal Generation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_ITERATIONS 10000
#define IMAGE_SIZE 1024

int main(){
    // Seed the random number generator
    srand(time(NULL));
    
    // Allocate memory for the image
    unsigned char *image = calloc(IMAGE_SIZE * IMAGE_SIZE, sizeof(unsigned char));
    
    if(image == NULL){
        printf("Error: Could not allocate memory for the image.\n");
        return 1;
    }
    
    // Set the center of the image to (0, 0)
    double x_center = 0;
    double y_center = 0;
    
    // Set the initial zoom level
    double zoom = 1;
    
    // Loop over all pixels in the image
    for(int y = 0; y < IMAGE_SIZE; y++){
        for(int x = 0; x < IMAGE_SIZE; x++){
            // Map the pixel coordinates to the complex plane
            double real = (x - IMAGE_SIZE / 2) * zoom / IMAGE_SIZE + x_center;
            double imag = (y - IMAGE_SIZE / 2) * zoom / IMAGE_SIZE + y_center;
            
            double c_real = real;
            double c_imag = imag;
            
            // Perform the Mandelbrot set iteration
            int iteration = 0;
            double z_real = 0;
            double z_imag = 0;
            
            while(iteration < MAX_ITERATIONS && z_real * z_real + z_imag * z_imag < 4){
                double temp = z_real * z_real - z_imag * z_imag + c_real;
                z_imag = 2 * z_real * z_imag + c_imag;
                z_real = temp;
                iteration++;
            }
            
            // Set the pixel value based on the number of iterations required
            if(iteration == MAX_ITERATIONS){
                image[y * IMAGE_SIZE + x] = 0;
            } else {
                image[y * IMAGE_SIZE + x] = iteration % 256;
            }
        }
    }
    
    // Write the image to a file
    char filename[100];
    sprintf(filename, "mandelbrot_%f_%f_%f.pgm", x_center, y_center, zoom);
    
    FILE *output_file = fopen(filename, "w");
    fprintf(output_file, "P2\n%d %d\n255\n", IMAGE_SIZE, IMAGE_SIZE);
    
    for(int i = 0; i < IMAGE_SIZE * IMAGE_SIZE; i++){
        fprintf(output_file, "%d ", image[i]);
    }
    
    fclose(output_file);
    
    // Free the memory allocated for the image
    free(image);
    
    return 0;
}