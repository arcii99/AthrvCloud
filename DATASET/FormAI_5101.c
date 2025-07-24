//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: optimized
#include <stdio.h>

// Function to generate random pixel art
void generatePixelArt(int n) {
    int pixel[n][n];
    int i, j;
    
    // Generate random pixel art
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // Generate a random number between 0 and 1
            pixel[i][j] = rand() % 2;
        }
    }
    
    // Display the pixel art
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (pixel[i][j] == 0) {
                // If the pixel is 0, display a space
                printf(" ");
            } else {
                // If the pixel is 1, display a block
                printf("▓");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    
    // Prompt the user to enter the size of the pixel art
    printf("Enter the size of the pixel art: ");
    scanf("%d", &n);
    
    // Generate the pixel art
    generatePixelArt(n);
    
    return 0;
}