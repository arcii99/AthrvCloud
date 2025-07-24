//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>

/* Function to calculate complex exponential */
void complexExp(double re, double im, double *resRe, double *resIm)
{
    *resRe = exp(re) * cos(im);
    *resIm = exp(re) * sin(im);
}

/* Function to iterate the fractal equation */
void iterate(double initRe, double initIm, double *resRe, double *resIm, int depth)
{
    double curRe = initRe, curIm = initIm;
    int i;

    for (i = 0; i < depth; i++) {
        /* Calculate the next complex value */
        complexExp(curRe, curIm, &curRe, &curIm);

        /* Add it to the accumulative result */
        *resRe += curRe;
        *resIm += curIm;
    }
}

/* Function to generate the fractal */
void generateFractal(int width, int height, int depth)
{
    double re, im, resRe, resIm, minX = -2.0, minY = -1.0;
    int i, j;

    /* Iterate over all pixels */
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            /* Calculate the corresponding complex value */
            re = minX + (double)j / width * 3.0;
            im = minY + (double)i / height * 2.0;

            /* Iterate the fractal equation */
            resRe = resIm = 0.0;
            iterate(re, im, &resRe, &resIm, depth);

            /* Output the pixel value */
            if (sqrt(resRe * resRe + resIm * resIm) > 2.0) {
                putchar('#');
            } else {
                putchar('.');
            }
        }
        putchar('\n');
    }
}

/* Main function */
int main()
{
    generateFractal(80, 40, 50);
    return 0;
}