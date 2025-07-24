//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: authentic
#include <stdio.h>

int main() {
    int width, height;
    printf("Enter the width of the pixel art: ");
    scanf("%d", &width);
    printf("Enter the height of the pixel art: ");
    scanf("%d", &height);

    int pixels[height][width]; // 2D array to store pixel values

    // Get pixel values from user input
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("Enter the pixel value for row %d, column %d: ", i+1,j+1);
            scanf("%d", &pixels[i][j]);
        }
    }

    // Print the pixel art
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            if(pixels[i][j] == 0) {
                printf(" "); // print space for black pixel
            } else {
                printf("*"); // print asterisk for non-black pixel
            }
        }
        printf("\n"); // move to next line
    }

    return 0;
}