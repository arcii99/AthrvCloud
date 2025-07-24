//FormAI DATASET v1.0 Category: Fractal Generation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_ITERATIONS 500
#define SIZE 2400
#define SCALE 0.006

float getRandom() {
    return ((float)rand()/(float)RAND_MAX); // returns a random float between 0 and 1
}

void generateFractal(float *fractal, float x, float y, float size) {
    float r = getRandom() * SCALE;
    float angle = getRandom() * 2 * M_PI; // angle is in radians
    float x1 = x + size/2 + r * cos(angle);
    float y1 = y + size/2 + r * sin(angle);
    
    if(size > 2) { // recursive case
        generateFractal(fractal, x, y, size/2);
        generateFractal(fractal, x + size/2, y, size/2);
        generateFractal(fractal, x, y + size/2, size/2);
        generateFractal(fractal, x + size/2, y + size/2, size/2);
    } else { // base case
        fractal[(int)x + (int)y*SIZE] = 1; // paint the pixel white
    }
}

int main() {
    float *fractal = (float*) calloc(SIZE * SIZE, sizeof(float)); // allocate memory for the fractal
    srand(time(0)); // use current time as seed for random generator
    
    generateFractal(fractal, 0, 0, SIZE); // generate the fractal
    
    // print the fractal to a ppm file
    printf("P3\n%d %d\n255\n", SIZE, SIZE);
    for(int i=0; i<SIZE*SIZE; i++) {
        int color = (int)(fractal[i] * 255);
        printf("%d %d %d ", color, color, color);
    }
    
    free(fractal); // free the memory allocated for the fractal
    return 0;
}