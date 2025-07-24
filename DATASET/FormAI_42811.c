//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complete
#include<stdio.h>
#include<stdlib.h>

// structure for storing pixels
typedef struct {
    int red;
    int green;
    int blue;
} Pixel;

// function to flip the image horizontally
void flipHorizontal(int width, int height, Pixel image[][width]){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width/2; j++){
            // swapping corresponding pixels of both the halves
            Pixel temp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = temp;
        }
    }
}

// function to increase the brightness of the image
void increaseBrightness(int width, int height, Pixel image[][width], int value){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            // adding the value to the red, green and blue values of each pixel
            image[i][j].red += value;
            image[i][j].green += value;
            image[i][j].blue += value;
        }
    }
}

// function to decrease the brightness of the image
void decreaseBrightness(int width, int height, Pixel image[][width], int value){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            // subtracting the value from the red, green and blue values of each pixel
            image[i][j].red -= value;
            image[i][j].green -= value;
            image[i][j].blue -= value;
        }
    }
}

// function to increase the contrast of the image
void increaseContrast(int width, int height, Pixel image[][width], int value){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            // multiplying the red, green and blue values of each pixel by the value
            image[i][j].red *= value;
            image[i][j].green *= value;
            image[i][j].blue *= value;
        }
    }
}

// function to decrease the contrast of the image
void decreaseContrast(int width, int height, Pixel image[][width], int value){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            // dividing the red, green and blue values of each pixel by the value
            image[i][j].red /= value;
            image[i][j].green /= value;
            image[i][j].blue /= value;
        }
    }
}

// function to print the image
void printImage(int width, int height, Pixel image[][width]){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            printf("(%d,%d,%d) ", image[i][j].red, image[i][j].green, image[i][j].blue);
        }
        printf("\n");
    }
}

int main(){
    int width, height;
    printf("Enter the width and height of the image in pixels: ");
    scanf("%d %d", &width, &height);

    // dynamically allocating memory for the image
    Pixel (*image)[width] = malloc(sizeof(Pixel[height][width]));

    // taking input of the pixel values of the image
    printf("Enter the pixel values of the image (in the format: red green blue):\n");
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            scanf("%d %d %d", &image[i][j].red, &image[i][j].green, &image[i][j].blue);
        }
    }

    // performing various image processing operations
    flipHorizontal(width, height, image);
    increaseBrightness(width, height, image, 20);
    increaseContrast(width, height, image, 2);

    // printing the final image
    printf("\nThe final image is:\n");
    printImage(width, height, image);

    // freeing the dynamically allocated memory
    free(image);

    return 0;
}