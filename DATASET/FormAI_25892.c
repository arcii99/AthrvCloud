//FormAI DATASET v1.0 Category: Fractal Generation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#define WIDTH 1000
#define HEIGHT 1000
#define MAX_ITER 1000

int main() {

    double complex z, c;
    int i, j, k;
    int iter;
    int colorValue;
    int pixelValues[WIDTH][HEIGHT];

    //initialize all pixel values to 0
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            pixelValues[i][j] = 0;
        }
    }

    //iterate through every pixel
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {

            //map the pixel coordinates onto the complex plane
            z = ((double)i - WIDTH/2)/((double)WIDTH/4) + (((double)j - HEIGHT/2)/((double)HEIGHT/4))*I;

            //initialize the value of c to be the same as z
            c = z;

            //iterate through the function
            for (k = 0; k < MAX_ITER; k++) {

                //apply the recursion formula
                z = z*z + c;

                //if the value is diverging, stop iterating
                if (cabs(z) > 2) break;
            }

            //assign a color value based on the number of iterations it took to diverge
            if (k == MAX_ITER) {
                colorValue = 0; //black
            } else if (k < 10) {
                colorValue = 1; //blue
            } else if (k < 20) {
                colorValue = 2; //green
            } else if (k < 30) {
                colorValue = 3; //yellow
            } else {
                colorValue = 4; //red
            }

            //assign the color value to the pixel
            pixelValues[i][j] = colorValue;
        }
    }

    //print the fractal to a ppm image
    FILE *fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            static unsigned char color[3];
            if (pixelValues[i][j] == 0) {
                color[0] = 0;
                color[1] = 0;
                color[2] = 0;
            } else if (pixelValues[i][j] == 1) {
                color[0] = 0;
                color[1] = 0;
                color[2] = 255;
            } else if (pixelValues[i][j] == 2) {
                color[0] = 0;
                color[1] = 255;
                color[2] = 0;
            } else if (pixelValues[i][j] == 3) {
                color[0] = 255;
                color[1] = 255;
                color[2] = 0;
            } else {
                color[0] = 255;
                color[1] = 0;
                color[2] = 0;
            }
            fwrite(color, 1, 3, fp);
        }
    }
    fclose(fp);

    return 0;
}