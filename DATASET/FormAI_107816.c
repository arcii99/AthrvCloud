//FormAI DATASET v1.0 Category: Fractal Generation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Constants
#define ITERATIONS 500
#define SCALE 150
#define THRESHOLD 50

typedef struct {
    double x;
    double y;
} Complex;

// Function Prototypes
Complex add(Complex z1, Complex z2);
Complex multiply(Complex z1, Complex z2);

int main() {
    // Set up grid
    bool grid[SCALE][SCALE] = {0};
    
    // Set up initial value
    Complex c = {0.285, 0.01};
    
    // Generate fractal
    for (int i = 0; i < SCALE; i++) {
        for (int j = 0; j < SCALE; j++) {
            
            Complex z;
            z.x = (double)(i - (SCALE / 2)) / SCALE;
            z.y = (double)(j - (SCALE / 2)) / SCALE;
            
            bool belongs = true;
            
            // Check if point belongs to fractal set
            for (int k = 0; k < ITERATIONS; k++) {
                z = add(multiply(z, z), c);
                if (sqrt(z.x * z.x + z.y * z.y) > THRESHOLD) {
                    belongs = false;
                    break;
                }
            }
            
            grid[i][j] = belongs;
            
        }
    }
    
    // Print grid
    for (int i = 0; i < SCALE; i++) {
        for (int j = 0; j < SCALE; j++) {
            if (grid[j][i]) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}

// Function to add two complex numbers
Complex add(Complex z1, Complex z2) {
    Complex result;
    result.x = z1.x + z2.x;
    result.y = z1.y + z2.y;
    return result;
}

// Function to multiply two complex numbers
Complex multiply(Complex z1, Complex z2) {
    Complex result;
    result.x = (z1.x * z2.x) - (z1.y * z2.y);
    result.y = (z1.x * z2.y) + (z1.y * z2.x);
    return result;
}