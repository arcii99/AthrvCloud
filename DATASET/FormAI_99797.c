//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

#define IMAGE_SIZE 256

int image[IMAGE_SIZE][IMAGE_SIZE]; 

//Function to flip the image horizontally
void flipHorizontally() {
    int temp;
    for(int i=0;i<IMAGE_SIZE;i++){
        for(int j=0;j<IMAGE_SIZE/2;j++){
            temp = image[i][j];
	        image[i][j] = image[i][IMAGE_SIZE-j-1];
	        image[i][IMAGE_SIZE-j-1] = temp;
        }
    }
}

//Function to change the brightness of the image
void changeBrightness(float factor) {
    int temp;
    for(int i=0;i<IMAGE_SIZE;i++) {
        for(int j=0;j<IMAGE_SIZE;j++) {
            temp = (int) (image[i][j] * factor);
            if(temp > 255) {
                //clip overflow values
                image[i][j] = 255;
            } else {
                image[i][j] = temp;
            }
        }
    }
}

//Function to change contrast of the image
void changeContrast(float factor) {
    int temp;
    float c = (factor + 255.0) / 255.0;

    for(int i=0;i<IMAGE_SIZE;i++) {
        for(int j=0;j<IMAGE_SIZE;j++) {
            temp = (int) (c * (image[i][j] - 128) + 128);
            if(temp > 255) {
                //clip overflow values
                image[i][j] = 255;
            } else if(temp < 0) {
                //clip underflow values
                image[i][j] = 0;
            } else {
                image[i][j] = temp;
            }
        }
    }
}

int main() {
    //initialize the image with random values
    for(int i=0;i<IMAGE_SIZE;i++){
	    for(int j=0;j<IMAGE_SIZE;j++){
	        image[i][j] = rand() % 256;
	    }
    }
    
    //flip the image horizontally
    flipHorizontally();

    //change brightness by a factor of 1.5
    changeBrightness(1.5);

    //change contrast by a factor of 1.2
    changeContrast(1.2);

    //display the modified image
    for(int i=0;i<IMAGE_SIZE;i++){
	    for(int j=0;j<IMAGE_SIZE;j++){
	        printf("%d ", image[i][j]);
	    }
        printf("\n");
    }

    return 0;
}