//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: multi-threaded
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>

#define WIDTH 20
#define HEIGHT 20
#define PIXEL "X "

char pixelArt[WIDTH][HEIGHT];

void *fillPixels(void *threadId) {
    long tid;
    tid = (long)threadId; // casting void pointer to long integer
    int x, y; // coordinates of pixels
    srand(time(0) * tid); // seeding random number generator with thread ID
    for(int i = 0; i < 100; i++) { // filling 100 pixels with each thread
        x = rand() % WIDTH; // generating random x-coordinate
        y = rand() % HEIGHT; // generating random y-coordinate
        pixelArt[x][y] = PIXEL[0]; // setting pixel value to "X"
    }
    pthread_exit(NULL); // terminating thread
}

int main() {
    pthread_t threads[10];
    int rc;
    long t;
    for(t = 0; t < 10; t++) { // creating 10 threads
        rc = pthread_create(&threads[t], NULL, fillPixels, (void *)t); // creating thread
        if (rc) { // error handling
            printf("ERROR: Return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    for(int i = 0; i < WIDTH; i++) { // printing pixel art
        for(int j = 0; j < HEIGHT; j++) {
            printf("%c ", pixelArt[i][j]);
        }
        printf("\n");
    }
    pthread_exit(NULL); // terminating main thread
    return 0;
}