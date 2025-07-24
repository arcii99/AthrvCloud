//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: visionary
/* 
   Visionary C Performance-Critical Component Example Program
   
   This program generates a fractal image using the Mandelbrot Set algorithm.
   It takes advantage of the power of parallel processing to compute each pixel
   of the image in separate threads, improving performance significantly.
    
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <pthread.h>

#define MAX_ITER 1000  // maximum number of iterations for Mandelbrot Set

// Image dimensions
#define WIDTH 640
#define HEIGHT 480

// Fractal coordinates
#define X_MIN -2.0
#define X_MAX 2.0
#define Y_MIN -1.5
#define Y_MAX 1.5

typedef struct {
    int x;
    int y;
    uint8_t r;
    uint8_t g;
    uint8_t b;
} pixel_t;

pixel_t image[HEIGHT][WIDTH];  // pointer to the image buffer

// Function to compute the Mandelbrot Set at a given location
int mandelbrot(double x, double y) {
    double re = x;
    double im = y;
    double temp_re, temp_im;
    int i;
    for (i = 0; i < MAX_ITER; i++) {
        temp_re = re*re - im*im + x;
        temp_im = 2*re*im + y;
        if (temp_re*temp_re + temp_im*temp_im > 4) {
            break;
        }
        re = temp_re;
        im = temp_im;
    }
    return i;
}

// Function to compute the color of a pixel
void colorize(int iterations, int x, int y) {
    // Map the number of iterations to a color
    uint8_t r = (uint8_t)(255 * iterations / MAX_ITER);
    uint8_t g = (uint8_t)(255 * iterations / MAX_ITER);
    uint8_t b = (uint8_t)(255 * iterations / MAX_ITER);
    image[y][x] = (pixel_t){.x = x, .y = y, .r = r, .g = g, .b = b};
}

// Function to compute the Mandelbrot Set for a given range of rows
void* compute_rows(void* arg) {
    int start = *((int*)arg);
    int end = start + HEIGHT/4;
    for (int y = start; y < end; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double real = X_MIN + (X_MAX - X_MIN) * x / WIDTH;
            double imag = Y_MIN + (Y_MAX - Y_MIN) * y / HEIGHT;
            int iterations = mandelbrot(real, imag);
            colorize(iterations, x, y);
        }
    }
    return NULL;
}

int main() {
    // Initialize and create 4 threads
    pthread_t threads[4];
    int row_starts[4] = {0, HEIGHT/4, HEIGHT/2, 3*HEIGHT/4};
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, compute_rows, &row_starts[i]);
    }
    // Wait for all threads to finish
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }
    // Write image to file
    FILE* fp = fopen("mandelbrot.ppm", "wb");
    fprintf(fp, "P6 %d %d 255\n", WIDTH, HEIGHT);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fwrite(&image[y][x], 1, 3, fp);
        }
    }
    fclose(fp);
    printf("Image generated and saved to mandelbrot.ppm\n");
    return 0;
}