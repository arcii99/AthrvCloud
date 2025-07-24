//FormAI DATASET v1.0 Category: Fractal Generation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#define WIDTH 50
#define HEIGHT 50
#define ITERATIONS 100

int main() {
    int x, y, i;
    double complex z, c;
    char output[WIDTH * HEIGHT + HEIGHT + 1]; // add one for null terminator
    
    // iterate over the complex plane
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            z = 0; // starting value of z is 0
            
            // map pixel coordinate to complex coordinate
            c = (((double) x / WIDTH) - 0.5) * 4.0 + (((double) y / HEIGHT) - 0.5) * 4.0 * I;
            
            // iterate z up to ITERATIONS times
            for (i = 0; i < ITERATIONS; i++) {
                z = z * z + c; // calculate next z value based on previous
                
                // check if z has escaped the circle with radius 2
                if (cabs(z) > 2.0)
                    break;
            }
            
            // set output character based on how quickly z diverged
            if (i == ITERATIONS) {
                output[y * (WIDTH + 1) + x] = ' '; // black space
            } else {
                output[y * (WIDTH + 1) + x] = '.' + (i % 4); // add a little color
            }
        }
        output[y * (WIDTH + 1) + WIDTH] = '\n'; // terminate line
    }
    output[WIDTH * HEIGHT + HEIGHT] = '\0'; // terminate string
    
    // display result
    printf("%s", output);
    
    return 0;
}