//FormAI DATASET v1.0 Category: Fractal Generation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <pthread.h>

// Global variables
int imageWidth, imageHeight, maxIterations;
double realMin, realMax, imagMin, imagMax, deltaReal, deltaImag;
int** fractalImage;
int numThreads;

// Function to calculate the color of a given pixel
int pixelColor(double complex c) {
    double complex z = 0;
    int i;
    for (i = 0; i < maxIterations; i++) {
        z = z * z + c;
        if (cabs(z) > 2) {
            return i;
        }
    }
    return maxIterations;
}

// Thread function to calculate a portion of the fractal image
void* calculateFractal(void* threadID) {
    int ID = (int)threadID;
    int startRow = (imageHeight / numThreads) * ID;
    int endRow = (imageHeight / numThreads) * (ID + 1);

    int i, j;
    for (i = startRow; i < endRow; i++) {
        for (j = 0; j < imageWidth; j++) {
            double real = realMin + j * deltaReal;
            double imag = imagMax - i * deltaImag;
            double complex c = real + imag * I;
            fractalImage[i][j] = pixelColor(c);
        }
    }

    pthread_exit(NULL);
}

int main() {
    // Input parameters
    imageWidth = 640;
    imageHeight = 480;
    maxIterations = 1000;
    realMin = -2.0;
    realMax = 2.0;
    imagMin = -2.0;
    imagMax = 2.0;
    deltaReal = (realMax - realMin) / (imageWidth - 1);
    deltaImag = (imagMax - imagMin) / (imageHeight - 1);
    numThreads = 4;

    // Allocate memory for fractal image
    fractalImage = (int**)malloc(imageHeight * sizeof(int*));
    int i;
    for (i = 0; i < imageHeight; i++) {
        fractalImage[i] = (int*)malloc(imageWidth * sizeof(int));
    }

    // Create threads to calculate portions of the fractal image
    pthread_t threads[numThreads];
    int threadID[numThreads];
    for (i = 0; i < numThreads; i++) {
        threadID[i] = i;
        pthread_create(&threads[i], NULL, calculateFractal, (void*)&threadID[i]);
    }

    // Join threads
    for (i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Output fractal image to file
    FILE* outputFile = fopen("fractal.ppm", "wb");
    fprintf(outputFile, "P6\n%d %d\n255\n", imageWidth, imageHeight);
    int x, y;
    for (y = 0; y < imageHeight; y++) {
        for (x = 0; x < imageWidth; x++) {
            static unsigned char color[3];
            color[0] = (fractalImage[y][x] % 8) * 63;  // Red
            color[1] = (fractalImage[y][x] % 64) * 4;  // Green
            color[2] = 255 - (fractalImage[y][x] % 32) * 8;  // Blue
            fwrite(color, 1, 3, outputFile);
        }
    }
    fclose(outputFile);

    // Free memory
    for (i = 0; i < imageHeight; i++) {
        free(fractalImage[i]);
    }
    free(fractalImage);

    return 0;
}