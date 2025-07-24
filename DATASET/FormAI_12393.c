//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Function to print pixels in a matrix format
void display_pixels(int matrix[][10], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 1) {
                printf("*");
            }
            else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    // Set the size of the canvas
    int N = 10;

    // Initialize the pixel matrix
    int pixels[N][N];

    // Initialize the random number generator
    srand(time(NULL));

    // Generate random pixels in the matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int r = rand() % 2;
            pixels[i][j] = r;
        }
    }

    // Display the generated matrix of pixels
    display_pixels(pixels, N);

    return 0;
}