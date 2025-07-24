//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void main() {
    int width = 20;
    int height = 20;
    int pixelArr[20][20][3]; // This array will contain the RGB values for each pixel
    
    // Ask user to input RGB values for each pixel
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            printf("Enter RGB values for pixel %d,%d separated by spaces: ", i, j);
            scanf("%d %d %d", &pixelArr[i][j][0], &pixelArr[i][j][1], &pixelArr[i][j][2]);
        }
    }
    
    // Print out the pixel art using ASCII characters
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int r = pixelArr[i][j][0];
            int g = pixelArr[i][j][1];
            int b = pixelArr[i][j][2];
            if(r > 200 && g < 50 && b < 50) {
                printf("❤️ "); // Red heart
            } else if(r > 200 && g > 200 && b < 50) {
                printf("💛 "); // Yellow heart
            } else if(r < 50 && g > 200 && b < 50) {
                printf("💚 "); // Green heart
            } else if(r < 50 && g < 50 && b > 200) {
                printf("💙 "); // Blue heart
            } else {
                printf("⬜️ "); // White square
            }
        }
        printf("\n");
    }
}