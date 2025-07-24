//FormAI DATASET v1.0 Category: Fractal Generation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#define WIDTH 90    /* width of screen in column */
#define ASPECT 2    /* ratio of vertical to horizontal size */
#define HEIGHT ((int)(WIDTH*ASPECT))
#define SCALE 3.14159265358979323846/HEIGHT
#define HUE_SCALE 255.0
 
/* Function to calculate hue value based on number of iterations */
unsigned char calc_hue(int num_iterations)
{
    if (num_iterations == -1) {
        return 0;  // Black pixel
    } else {
        float hue = fmod(HUE_SCALE*num_iterations/15.0, HUE_SCALE);
        hue = hue < 0 ? hue + HUE_SCALE : hue;
        return (unsigned char)hue;
    }
}
 
/* Function to print the generated image */
void print_image(unsigned char image[WIDTH][HEIGHT], int max_iterations)
{
    for (int j=HEIGHT-1; j>=0; j--) {
        for (int i=0; i<WIDTH; i++) {
            if (max_iterations == -1) {
                printf("# ");
            } else {
                printf("%c ", 30 + calc_hue(image[i][j]));
            }
        }
        printf("\n");
    }
}
 
/* Main function to generate mandelbrot fractal */
int main()
{
    unsigned char image[WIDTH][HEIGHT];
    double x, x_inc, y, y_inc, x_new;
    double x1 = -2.0, x2 = 2.0, y1 = -2.0, y2 = 2.0;
    int max_iterations = 15;
 
    x_inc = (x2 - x1)/WIDTH;
    y_inc = (y2 - y1)/HEIGHT;
 
    for (int j=0; j<HEIGHT; j++) {
        y = y1 + j*y_inc;
        for (int i=0; i<WIDTH; i++) {
            x = x1 + i*x_inc;
            double a = x, b = y, temp;
            int num_iterations = -1;
            while (a*a + b*b <= 4.0 && num_iterations < max_iterations) {
                num_iterations++;
                temp = a*a - b*b + x;
                b = 2*a*b + y;
                a = temp;
            }
            image[i][j] = num_iterations;
        }
    }
 
    print_image(image, max_iterations);
    return 0;
}