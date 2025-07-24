//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

// Structure for pixel information
typedef struct Pixel {
    int red;
    int green;
    int blue;
} Pixel;

// Structure for thread information
typedef struct ThreadInfo {
    int start_index;
    int end_index;
    Pixel pixels[WIDTH][HEIGHT];
} ThreadInfo;

// Function to generate pixel art for a given range of pixels
void* generatePixelArt(void* param) {
    ThreadInfo* threadInfo = (ThreadInfo*)param;
    int i,j;
    for(i = threadInfo->start_index; i < threadInfo->end_index; i++) {
        for(j = 0; j < HEIGHT; j++) {
            // Generate random RGB values for each pixel
            threadInfo->pixels[i][j].red = rand() % 256;
            threadInfo->pixels[i][j].green = rand() % 256;
            threadInfo->pixels[i][j].blue = rand() % 256;
        }
    }
    pthread_exit(0);
}

int main() {
    int NUM_THREADS = 5;
    int ROWS_PER_THREAD = WIDTH / NUM_THREADS;
    pthread_t threads[NUM_THREADS];
    ThreadInfo threadInfo[NUM_THREADS];

    int i,j;
    for(i = 0; i < NUM_THREADS; i++) {
        threadInfo[i].start_index = i * ROWS_PER_THREAD;
        threadInfo[i].end_index = (i + 1) * ROWS_PER_THREAD;
        if(i == NUM_THREADS - 1)
            threadInfo[i].end_index = WIDTH;
        pthread_create(&threads[i], NULL, generatePixelArt, &threadInfo[i]);
    }

    // Wait for the threads to finish
    for(i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);

    // Print the generated pixel art
    for(i = 0; i < WIDTH; i++) {
        for(j = 0; j < HEIGHT; j++) {
            printf("(%d,%d,%d)\t", threadInfo[i/ROWS_PER_THREAD].pixels[i][j].red,
                threadInfo[i/ROWS_PER_THREAD].pixels[i][j].green, 
                threadInfo[i/ROWS_PER_THREAD].pixels[i][j].blue);
        }
        printf("\n");
    }

    return 0;
}