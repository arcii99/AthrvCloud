//FormAI DATASET v1.0 Category: Fractal Generation ; Style: active
#include <stdio.h>
#include <math.h>

// function to generate fractals
void generateFractal(int iterations, double zoom) {
    // define constants
    const int width = 1000;
    const int height = 1000;
    
    // initialize variables
    double x, y, xtemp, ytemp, zx, zy;
    int i, j, k;
    
    // allocate memory for image
    int image[width][height];
    
    // initialize image array to 0
    for(i=0; i<width; i++) {
        for(j=0; j<height; j++) {
            image[i][j] = 0;
        }
    }
    
    // loop through each pixel
    for(i=0; i<width; i++) {
        for(j=0; j<height; j++) {
            // map pixel coordinate to complex plane
            x = (double) i / zoom - 1.5;
            y = (double) j / zoom - 1.5;
            
            // initialize complex number
            zx = 0.0;
            zy = 0.0;
            
            // iterate through mandelbrot algorithm
            for(k=0; k<iterations && zx*zx+zy*zy<4.0; k++) {
                xtemp = zx*zx - zy*zy + x;
                ytemp = 2*zx*zy + y;
                zx = xtemp;
                zy = ytemp;
            }
            
            // set color of pixel based on number of iterations
            if(k == iterations) {
                image[i][j] = 0;
            } else {
                image[i][j] = k;
            }
        }
    }
    
    // print out image
    for(j=0; j<height; j++) {
        for(i=0; i<width; i++) {
            if(image[i][j] == 0) {
                printf(" ");
            } else if(image[i][j] < 10) {
                printf(".");
            } else if(image[i][j] < 20) {
                printf(":");
            } else if(image[i][j] < 30) {
                printf("%c", 176);
            } else if(image[i][j] < 40) {
                printf("%c", 177);
            } else if(image[i][j] < 50) {
                printf("%c", 178);
            } else {
                printf("%c", 219);
            }
        }
        printf("\n");
    }
}

int main() {
    int iterations = 50;
    double zoom = 1.0;
    
    generateFractal(iterations, zoom);
    
    return 0;
}