//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define IMAGE_WIDTH 10
#define IMAGE_HEIGHT 10

typedef unsigned char pixel;

pixel image[IMAGE_WIDTH][IMAGE_HEIGHT];

void flip_image(pixel image[][IMAGE_HEIGHT]){
    pixel temp;
    for(int i=0; i<IMAGE_WIDTH; i++){
        for(int j=0; j<IMAGE_HEIGHT/2; j++){
            temp = image[i][j];
            image[i][j] = image[i][IMAGE_HEIGHT-j-1];
            image[i][IMAGE_HEIGHT-j-1] = temp;
        }
    }
}

void change_brightness(pixel image[][IMAGE_HEIGHT], int amount){
    for(int i=0; i<IMAGE_WIDTH; i++){
        for(int j=0; j<IMAGE_HEIGHT; j++){
            if((int)image[i][j]+amount > 255) image[i][j] = 255;
            else if((int)image[i][j]+amount < 0) image[i][j] = 0;
            else image[i][j] += amount;
        }
    }
}

void change_contrast(pixel image[][IMAGE_HEIGHT], float factor){
    for(int i=0; i<IMAGE_WIDTH; i++){
        for(int j=0; j<IMAGE_HEIGHT; j++){
            float pixel_value = (float)image[i][j]/255.0;
            pixel_value = (((pixel_value - 0.5) * factor) + 0.5) * 255.0;
            if(pixel_value > 255.0) pixel_value = 255.0;
            else if(pixel_value < 0.0) pixel_value = 0.0;
            image[i][j] = (pixel)pixel_value;
        }
    }
}

int main(){
    //Generate image
    for(int i=0; i < IMAGE_WIDTH; i++){
        for(int j=0; j < IMAGE_HEIGHT; j++){
            image[i][j] = i+j;
        }
    }
    //Print original image
    printf("Original Image:\n");
    for(int i=0; i < IMAGE_WIDTH; i++){
        for(int j=0; j < IMAGE_HEIGHT; j++){
            printf("%d ",image[i][j]);
        }
        printf("\n");
    }
    //Flip image horizontally
    flip_image(image);
    //Print flipped image
    printf("\nFlipped Image:\n");
    for(int i=0; i < IMAGE_WIDTH; i++){
        for(int j=0; j < IMAGE_HEIGHT; j++){
            printf("%d ",image[i][j]);
        }
        printf("\n");
    }
    //Change brightness
    int brightness_amount = 50;
    change_brightness(image, brightness_amount);
    //Print adjusted brightness image
    printf("\nAdjusted Brightness Image (by %d):\n", brightness_amount);
    for(int i=0; i < IMAGE_WIDTH; i++){
        for(int j=0; j < IMAGE_HEIGHT; j++){
            printf("%d ",image[i][j]);
        }
        printf("\n");
    }
    //Change contrast
    float contrast_factor = 1.5;
    change_contrast(image, contrast_factor);
    //Print adjusted contrast image
    printf("\nAdjusted Contrast Image (by factor of %.1f):\n", contrast_factor);
    for(int i=0; i < IMAGE_WIDTH; i++){
        for(int j=0; j < IMAGE_HEIGHT; j++){
            printf("%d ",image[i][j]);
        }
        printf("\n");
    }
    return 0;
}