//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int width = 16;
    int height = 16;
    int pixels[width][height];

    srand(time(0)); // seed the random number generator

    // Generate random pixels
    for(int i=0; i<width; i++) {
        for(int j=0; j<height; j++) {
            pixels[i][j] = rand() % 2; // 0 or 1
        }
    }

    // Print out pixels in a multivariable style
    printf("int pixels[%d][%d] = {\n", height, width);
    for(int i=0; i<height; i++) {
        printf("    { ");
        for(int j=0; j<width; j++) {
            printf("%d", pixels[i][j]);
            if (j != width-1) {
                printf(", ");
            }
        }
        printf(" }");
        if (i != height-1) {
            printf(",");
        }
        printf("\n");
    }
    printf("};\n");

    return 0;
}