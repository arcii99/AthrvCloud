//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// function to flip the image horizontally
void flip_horizontal(int image[][3], int width, int height) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width/2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = temp;
        }
    }
}

// function to change the brightness of the image
void change_brightness(int image[][3], int brightness, int width, int height) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            image[i][j] += brightness;
            // ensure pixel values are within the valid range of 0-255
            if(image[i][j] > 255) {
                image[i][j] = 255;
            }
            else if(image[i][j] < 0) {
                image[i][j] = 0;
            }
        }
    }
}

// function to change the contrast of the image
void change_contrast(int image[][3], int contrast, int width, int height) {
    float factor = (259*(contrast+255)) / (255*(259-contrast));
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            image[i][j] = factor*(image[i][j] - 128) + 128;
            // ensure pixel values are within the valid range of 0-255
            if(image[i][j] > 255) {
                image[i][j] = 255;
            }
            else if(image[i][j] < 0) {
                image[i][j] = 0;
            }
        }
    }
}

int main() {
    int image[3][3] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
    int width = 3;
    int height = 3;
    int brightness = 50;
    int contrast = 50;
    
    printf("Original Image:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    flip_horizontal(image, width, height);
    printf("\nImage after horizontal flip:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    change_brightness(image, brightness, width, height);
    printf("\nImage after brightness adjustment:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    change_contrast(image, contrast, width, height);
    printf("\nImage after contrast adjustment:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}