//FormAI DATASET v1.0 Category: Benchmarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Happy Benchmarking program!\n");
    printf("This program will run some image processing code and measure its performance.\n");

    // allocate memory for image
    int height = 1080;
    int width = 1920;
    printf("Allocating memory for image of size %d x %d...\n", height, width);
    int *image = (int*) malloc(height * width * sizeof(int));
    if (image == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return 1;
    }

    // initialize random image
    printf("Initializing image with random values...\n");
    srand(time(0));
    for (int i = 0; i < height * width; i++) {
        image[i] = rand();
    }

    // apply filter to image
    printf("Applying filter to image...\n");
    clock_t start_time = clock(); // start timer
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int val = 0;
            if (i > 0)     val += image[(i-1)*width+j];
            if (j > 0)     val += image[i*width+(j-1)];
            if (i < height-1)   val += image[(i+1)*width+j];
            if (j < width-1)    val += image[i*width+(j+1)];
            val /= 4;
            image[i*width+j] = val;
        }
    }
    clock_t end_time = clock(); // end timer
    double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    // display results
    printf("Elapsed time: %f seconds.\n", elapsed_time);
    printf("Image processed successfully!\n");

    // free memory
    free(image);
    return 0;
}