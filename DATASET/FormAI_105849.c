//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: unmistakable
#include <stdio.h>

// Function to flip image horizontally
void flipHorizontal(int image[][3], int rows, int cols) {
    int temp;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols/2; j++) {
            temp = image[i][j];
            image[i][j] = image[i][cols-j-1];
            image[i][cols-j-1] = temp;
        }
    }
}

// Function to increase contrast of image
void increaseContrast(int image[][3], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(image[i][j] < 128) {
                image[i][j] *= 0.8;
            } else {
                image[i][j] *= 1.2;
            }
        }
    }
}

int main() {
    int image[3][3] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};

    // Original Image
    printf("Original Image:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%4d ", image[i][j]);
        }
        printf("\n");
    }

    // Flip Image Horizontally
    flipHorizontal(image, 3, 3);
    printf("Flipped Horizontally Image:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%4d ", image[i][j]);
        }
        printf("\n");
    }

    // Increase Contrast of Image
    increaseContrast(image, 3, 3);
    printf("Image with increased contrast:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%4d ", image[i][j]);
        }
        printf("\n");
    }
    return 0;
}