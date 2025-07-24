//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10
#define COLORS 5

int main() {
    int i, j, c;
    int pixel[HEIGHT][WIDTH];

    // Initialize random seed
    srand(42);

    // Generate random pixel values between 0 and COLORS-1
    for(i=0; i<HEIGHT; i++) {
        for(j=0; j<WIDTH; j++) {
            pixel[i][j] = rand() % COLORS;
        }
    }

    // Print generated pixel art
    printf("+");
    for(j=0; j<WIDTH; j++)
        printf("-");
    printf("+\n");
    for(i=0; i<HEIGHT; i++) {
        printf("|");
        for(j=0; j<WIDTH; j++) {
            c = pixel[i][j];
            switch(c) {
                case 0: printf(" "); break;
                case 1: printf("."); break;
                case 2: printf(":"); break;
                case 3: printf("*"); break;
                case 4: printf("#"); break;
                default: printf("?"); break;
            }
        }
        printf("|\n");
    }
    printf("+");
    for(j=0; j<WIDTH; j++)
        printf("-");
    printf("+\n");

    return 0;
}