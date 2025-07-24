//FormAI DATASET v1.0 Category: Fractal Generation ; Style: calm
#include <stdio.h>
#include <math.h> 

#define SIZE 800 // pixel size of image
#define MAX_ITER 1000 // number of iterations
#define ESCAPE_RADIUS 2 // escape radius of points in the set

// Mandelbrot function that returns number
// of iterations before point escapes
int mandelbrot(double x, double y){
    double real, imag, z_real, z_imag;
    real = x;
    imag = y;
    int i;
    for(i = 0; i < MAX_ITER; i++){
        z_real = real*real - imag*imag + x;
        z_imag = 2*real*imag + y;
        real = z_real;
        imag = z_imag;
        if(sqrt(real*real + imag*imag) > ESCAPE_RADIUS){
            break;
        }
    }
    return i;
}

int main(){
    // creating the image
    int i, j, iter;
    double x, y;
    FILE* f = fopen("fractal.ppm", "wb");
    fprintf(f, "P6\n%d %d\n255\n", SIZE, SIZE); // header for PPM file
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            x = (double)(j - SIZE/2) * 4.0/SIZE; // scaling and shifting coordinates
            y = (double)(i - SIZE/2) * 4.0/SIZE;
            iter = mandelbrot(x, y);
            // setting color based on number of iterations
            if(iter == MAX_ITER){
                fputc(0, f); // red 
                fputc(0, f); // green
                fputc(0, f); // blue
            }
            else{
                fputc((iter*7) % 255, f); // red
                fputc((iter*11) % 255, f); // green
                fputc((iter*13) % 255, f); // blue
            }
        }
    }
    fclose(f);
    return 0;
}