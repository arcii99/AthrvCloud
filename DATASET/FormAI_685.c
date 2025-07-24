//FormAI DATASET v1.0 Category: Fractal Generation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 90
#define HEIGHT 30
#define MAX_ITER 200
#define MAX_DISTANCE 2

typedef struct {
    double x;
    double y;
} Complex;

int main() {
    // Initialize the image
    char image[HEIGHT][WIDTH];

    srand(time(NULL));

    // Initialize the complex numbers
    Complex z, c;
    z.x = 0;
    z.y = 0;
    c.x = (((double) rand() / RAND_MAX) * 4) - 2;
    c.y = (((double) rand() / RAND_MAX) * 4) - 2;

    // Fractal Generation
    int i, j, k;
    double distance;
    for (i=0; i<HEIGHT; i++) {
        for (j=0; j<WIDTH; j++) {
            z.x = ((double) j / WIDTH * 4) - 2;
            z.y = ((double) i / HEIGHT * 4) - 2;

            k = 0;
            distance = 0;
            while (distance < MAX_DISTANCE && k < MAX_ITER) {
                // z = z^2 + c
                Complex temp;
                temp.x = z.x * z.x - z.y * z.y + c.x;
                temp.y = 2 * z.x * z.y + c.y;
                z = temp;

                // Calculate the distance from the origin
                distance = sqrt(z.x * z.x + z.y * z.y);

                k++;
            }

            if (k == MAX_ITER) {
                image[i][j] = '.';
            } else {
                image[i][j] = (char) (k % 10 + 48);
            }
        }
    }

    // Print the image
    for (i=0; i<HEIGHT; i++) {
        for (j=0; j<WIDTH; j++) {
            printf("%c", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}