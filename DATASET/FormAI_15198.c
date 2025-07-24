//FormAI DATASET v1.0 Category: Fractal Generation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 40
#define MAX_ITERATIONS 100

int main()
{
    /* Allocate memory for the output array */
    int *output = (int*) malloc(WIDTH * HEIGHT * sizeof(int));
    
    /* Center point of the fractal */
    double complex center = -0.75 + 0.0*I;
    
    /* Scaling factor and aspect ratio */
    double scale = 3.0 / WIDTH;
    double aspect_ratio = (double)HEIGHT / WIDTH;
    
    /* Iterate over each pixel */
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            /* Determine the complex number associated with this pixel */
            double complex c = center + ((double)x - WIDTH/2)*scale +
                               ((double)y - HEIGHT/2)*scale*I*aspect_ratio;
            
            /* Initialize z */
            double complex z = c;
            
            /* Iterate until the max number of iterations is reached */
            int iterations = 0;
            while (iterations < MAX_ITERATIONS) {
                /* Check if z has escaped the circle of radius 2 */
                if (cabs(z) > 2) {
                    /* Mark this pixel as being "in the set" and break out of the loop */
                    output[y * WIDTH + x] = 1;
                    break;
                }
                
                /* Calculate z_next */
                double complex z_next = z*z + c;
                
                /* Increment the iteration count and update z */
                iterations++;
                z = z_next;
            }
        }
    }
    
    /* Print the output */
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (output[y * WIDTH + x]) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    
    /* Free the memory */
    free(output);
    
    return 0;
}