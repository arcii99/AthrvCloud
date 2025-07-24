//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, n;
    printf("Please enter size of pixel art (width and height): ");
    scanf("%d", &n);

    char pixel_art[n][n];

    // initialize pixel_art with lowercase alphabet
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            pixel_art[i][j] = rand() % 26 + 'a';
        }
    }

    // print pixel_art
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%c ", pixel_art[i][j]);
        }
        printf("\n");
    }

    // modify pixel_art with random capital letters
    srand(time(NULL));
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(rand()%2 == 0) {
                pixel_art[i][j] -= 32;
            }
        }
    }

    // print modified pixel_art
    printf("\nPixel art after modification: \n\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%c ", pixel_art[i][j]);
        }
        printf("\n");
    }

    return 0;
}