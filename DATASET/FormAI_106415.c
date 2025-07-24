//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random RGB values
void generateColor(int *R, int *G, int *B) {
    *R = rand() % 256;
    *G = rand() % 256;
    *B = rand() % 256;
}

// Function to generate a random pixel art design
void generatePixelArt(int n) {
    // n is the size of the design
    int pixelArt[n][n]; // 2D array to store the design
    srand(time(0)); // Initialize random seed
    
    // Fill the design with random colors
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int R, G, B;
            generateColor(&R, &G, &B);
            pixelArt[i][j] = (R << 16) + (G << 8) + B; // Combine RGB values into a single integer
        }
    }
    
    // Display the design in the console
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("\033[48;2;%d;%d;%dm  \033[0m", (pixelArt[i][j] >> 16) & 0xff, (pixelArt[i][j] >> 8) & 0xff, pixelArt[i][j] & 0xff);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the size of the pixel art design: ");
    scanf("%d", &n);
    generatePixelArt(n);
    return 0;
}