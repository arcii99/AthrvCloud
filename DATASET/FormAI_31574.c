//FormAI DATASET v1.0 Category: Fractal Generation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 100
#define SCALE 0.5
#define MAX_ITERATIONS 1000

void generate_fractal(int iterations, double *real, double *imaginary, int *iterations_count){
    int x, y, n;
    double zr, zi, zr_squared, zi_squared, temp;
    
    for(y = 0; y < HEIGHT; y++){
        for(x = 0; x < WIDTH; x++){
            
            // Starting values for zr and zi
            zr = ((double)x - WIDTH/2) / (WIDTH * SCALE);
            zi = ((double)y - HEIGHT/2) / (HEIGHT * SCALE);
            
            n = 0;
            zr_squared = zr * zr;
            zi_squared = zi * zi;
            
            // Iteration loop
            while(n < iterations && zr_squared + zi_squared < 4){
                temp = zr_squared - zi_squared + real[y * WIDTH + x];
                zi = 2 * zr * zi + imaginary[y * WIDTH + x];
                zr = temp;
                zr_squared = zr * zr;
                zi_squared = zi * zi;
                
                n++;
            }
            
            iterations_count[y * WIDTH + x] = n;
        }
    }
}

int main(){
    double real[WIDTH * HEIGHT];
    double imaginary[WIDTH * HEIGHT];
    int iterations_count[WIDTH * HEIGHT];
    int i;
    
    // Initialize real and imaginary arrays
    for(i = 0; i < WIDTH * HEIGHT; i++){
        real[i] = -2.0 + 4.0 * (double)(i % WIDTH) / (WIDTH - 1);
        imaginary[i] = -2.0 + 4.0 * (double)(i / WIDTH) / (HEIGHT - 1);
    }
    
    // Generate fractal
    generate_fractal(MAX_ITERATIONS, real, imaginary, iterations_count);
    
    // Print out iterations count
    for(i = 0; i < WIDTH * HEIGHT; i++){
        printf("%d ", iterations_count[i]);
        
        if(i % WIDTH == WIDTH - 1){
            printf("\n");
        }
    }
    
    return 0;
}