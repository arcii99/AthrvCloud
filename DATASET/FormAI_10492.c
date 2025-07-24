//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

//function to flip an image
void flipImage(int image[], int width, int height) {
    int temp;

    //loop through each row of the image
    for(int i=0; i<height; i++) {
        //loop through each column of the image
        for(int j=0; j<width/2; j++) {
            //swap left and right pixels
            temp = image[i*width+j];
            image[i*width+j] = image[i*width+width-j-1];
            image[i*width+width-j-1] = temp;
        }
    }
}

//function to change brightness and contrast
void changeBrightnessContrast(int image[], int width, int height, float brightness, float contrast) {
    //loop through each pixel of the image
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            //apply brightness
            image[i*width+j] = (int)(image[i*width+j] * brightness);

            //apply contrast
            image[i*width+j] = (int)(((image[i*width+j] / 255.0) - 0.5) * contrast + 0.5) * 255;
            
            //check for overflow
            if(image[i*width+j] > 255) {
                image[i*width+j] = 255;
            } else if(image[i*width+j] < 0) {
                image[i*width+j] = 0;
            }
        }
    }
}

int main() {
    //create a sample image
    int width = 3;
    int height = 2;
    int sampleImage[6] = {255, 128, 0, 0, 128, 255};

    //print original image
    printf("Original Image:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", sampleImage[i*width+j]);
        }
        printf("\n");
    }
    printf("\n");

    //flip image
    flipImage(sampleImage, width, height);

    //print flipped image
    printf("Flipped Image:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", sampleImage[i*width+j]);
        }
        printf("\n");
    }
    printf("\n");

    //change brightness and contrast
    float brightness = 1.2;
    float contrast = 1.5;
    changeBrightnessContrast(sampleImage, width, height, brightness, contrast);

    //print modified image
    printf("Modified Image:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", sampleImage[i*width+j]);
        }
        printf("\n");
    }

    return 0;
}