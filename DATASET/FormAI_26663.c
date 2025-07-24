//FormAI DATASET v1.0 Category: Fractal Generation ; Style: sophisticated
#include <stdio.h>

//Functions to compute the complex operations
struct Complex {
    double real, imag;
};

struct Complex add(struct Complex a, struct Complex b) {
    struct Complex res;
    res.real = a.real + b.real;
    res.imag = a.imag + b.imag;
    return res;
}

struct Complex multiply(struct Complex a, struct Complex b) {
    struct Complex res;
    res.real = a.real * b.real - a.imag * b.imag;
    res.imag = a.real * b.imag + a.imag * b.real;
    return res;
}

//Function to check if the point is within the Mandelbrot set
int isWithinMandelbrot(struct Complex c) {
    struct Complex z = {0, 0};
    int iterations = 0;
    while(iterations < 100) {
        z = add(multiply(z, z), c);
        if(z.real * z.real + z.imag * z.imag > 4) return 0;
        iterations++;
    }
    return 1;
}

//Main function to generate the fractal
int main() {

    //Generate the fractal of size (height x width)
    int height = 60;
    int width = 120;
    int fractal[height][width];
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            double real = (j - width/2.0)*4.0/width;
            double imag = (i - height/2.0)*4.0/width;
            struct Complex c = {real, imag};
            fractal[i][j] = isWithinMandelbrot(c);
        }
    }

    //Print the fractal
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(fractal[i][j]) printf("*");
            else printf(" ");
        }
        printf("\n");
    }

    return 0;
}