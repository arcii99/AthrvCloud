//FormAI DATASET v1.0 Category: Fractal Generation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// define constants
#define SIZE 1920
#define MAX_ITERATIONS 100000

// function to check if a point is in the mandelbrot set
int isInMandelbrot(double x, double y) {
    double real = x;
    double imaginary = y;
    double nextReal, nextImaginary;
    int iterations = 0;
    
    while (real*real + imaginary*imaginary <= 4 && iterations < MAX_ITERATIONS) {
        nextReal = real*real - imaginary*imaginary + x;
        nextImaginary = 2*real*imaginary + y;
        real = nextReal;
        imaginary = nextImaginary;
        iterations++;
    }
    
    if (iterations == MAX_ITERATIONS) {
        return 1;
    }
    
    return 0;
}

// function to print the mandelbrot set
void printMandelbrot() {
    double x, y;
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {            
            x = (double)(i - (double)SIZE/2.0)/(double)(SIZE/4.0);
            y = (double)(j - (double)SIZE/2.0)/(double)(SIZE/4.0);
            
            if (isInMandelbrot(x, y)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    printMandelbrot();
    return 0;
}