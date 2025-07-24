//FormAI DATASET v1.0 Category: Fractal Generation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum number of iterations for fractal calculations
#define MAX_ITERATIONS 1000

// Define the color RGB values for the fractal
#define RED 255
#define GREEN 0
#define BLUE 0

// Define the complex number structure
typedef struct complex{
    double real;
    double imag;
}complex;

// Initialize complex number
complex initComplex(double real, double imag){
    complex c;
    c.real = real;
    c.imag = imag;
    return c;
}

// Addition of two complex numbers
complex complexAdd(complex num1, complex num2){
    complex result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    return result;
}

// Square of a complex number
complex complexSquare(complex num){
    complex result;
    result.real = (num.real * num.real) - (num.imag * num.imag);
    result.imag = 2 * num.real * num.imag;
    return result;
}

// Calculate the magnitude of a complex number
double magnitude(complex num){
    return sqrt((num.real * num.real) + (num.imag * num.imag));
}

// Calculate the fractal value for a given complex number
int getFractalValue(complex num){

    int iterations = 0;
    complex z = initComplex(0, 0);

    // Iterate until the maximum number of iterations is reached or until the magnitude is greater than the threshold
    while(iterations < MAX_ITERATIONS && magnitude(z) < 2.0){

        // Calculate the value of z for the next iteration
        z = complexAdd(complexSquare(z), num);

        iterations++;
    }

    // Return the RGB value for the fractal based on the number of iterations
    if(iterations == MAX_ITERATIONS){
        return 0;
    }
    else{
        int red = RED * iterations / MAX_ITERATIONS;
        int green = GREEN * iterations / MAX_ITERATIONS;
        int blue = BLUE * iterations / MAX_ITERATIONS;
        return ((red << 16) | (green << 8) | blue);
    }
}

// Generate the fractal image
void generateFractal(int width, int height){

    // Open the output file
    FILE* fp;
    fp = fopen("fractal.ppm", "w");

    // Write the PPM header
    fprintf(fp, "P3\n%d %d\n255\n", width, height);

    // Calculate the fractal value for each pixel and write the RGB value to the output file
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            complex num = initComplex((2.0 * x / width) - 1.5, (2.0 * y / height) - 1.0);
            int fractalValue = getFractalValue(num);
            fprintf(fp, "%d %d %d ", (fractalValue >> 16) & 255, (fractalValue >> 8) & 255, fractalValue & 255);
        }
        fprintf(fp, "\n");
    }

    // Close the output file
    fclose(fp);
}

int main(){

    // Set the width and height of the fractal image
    int width = 800;
    int height = 600;

    // Generate the fractal image
    generateFractal(width, height);

    return 0;
}