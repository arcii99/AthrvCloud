//FormAI DATASET v1.0 Category: Fractal Generation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

#define WIDTH 1000
#define HEIGHT 1000
#define MAX_ITER 2000

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point start;
    Point end;
} Range;

// Function to check if a point lies within the Mandelbrot set
int checkPoint(Point c) {
    Point z = {0, 0};
    for(int i = 0; i < MAX_ITER; i++) {
        double zx = z.x*z.x - z.y*z.y + c.x;
        double zy = 2*z.x*z.y + c.y;
        z.x = zx;
        z.y = zy;
        if(z.x*z.x + z.y*z.y > 4) {
            return i;
        }
    }
    return -1;
}

// Function to generate the image for a given range of points
void *generateImage(void *arg) {
    Range *range = (Range*) arg;
    int startX = range->start.x;
    int endX = range->end.x;
    int startY = range->start.y;
    int endY = range->end.y;

    for(int i = startX; i < endX; i++) {
        for(int j = startY; j < endY; j++) {
            Point c = {((double)i - WIDTH/2)*4.0/WIDTH, ((double)j - HEIGHT/2)*4.0/HEIGHT};
            int iterations = checkPoint(c);
            if(iterations == -1) {
                printf("*");
            } else {
                printf("%d", iterations % 10);
            }
        }
        printf("\n");
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[4];
    Range ranges[4];

    // Divide the image into 4 parts and create threads to generate each part
    int startx = 0;
    int starty = 0;
    int width = WIDTH / 2;
    int height = HEIGHT / 2;

    for(int i = 0; i < 4; i++) {
        ranges[i].start.x = startx;
        ranges[i].start.y = starty;
        ranges[i].end.x = startx + width;
        ranges[i].end.y = starty + height;

        pthread_create(&threads[i], NULL, generateImage, &ranges[i]);

        starty += height;
        if(i == 1) {
            startx += width;
            starty = 0;
        }
    }

    // Wait for all threads to finish executing
    for(int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}