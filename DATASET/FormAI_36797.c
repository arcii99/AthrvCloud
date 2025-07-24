//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

//Function to flip the image horizontally
void flip_horizontal(int *image, int height, int width){
    int *temp = (int*)malloc(sizeof(int)*width);
    int i,j;

    for(i=0; i<height; i++){
        for(j=0; j<width/2; j++){
            temp[j] = image[i*width+j];
            image[i*width+j] = image[i*width+width-1-j];
            image[i*width+width-1-j] = temp[j];
        }
    }

    free(temp);
}

//Function to change brightness of the image
void change_brightness(int *image, int height, int width, int adjustment){
    int i,j;
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            image[i*width+j] += adjustment;
            if(image[i*width+j] > 255) image[i*width+j] = 255;
            if(image[i*width+j] < 0) image[i*width+j] = 0;
        }
    }
}

//Function to change contrast of the image
void change_contrast(int *image, int height, int width, float factor){
    int i,j;
    float avg = 0;

    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            avg += image[i*width+j];
        }
    }
    
    avg = avg/(height*width);

    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            image[i*width+j] = (int)(factor * (image[i*width+j] - avg) + avg + 0.5);
            if(image[i*width+j] > 255) image[i*width+j] = 255;
            if(image[i*width+j] < 0) image[i*width+j] = 0;
        }
    }
}

int main(){
    int height = 5;
    int width = 5;
    int image[25] = {255,255,255,255,255, 255,255,255,255,255, 255,255,255,255,255, 255,255,255,255,255, 255,255,255,255,255};
    int i,j;

    printf("Original Image:\n");
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            printf("%d ", image[i*width+j]);
        }
        printf("\n");
    }

    flip_horizontal(image, height, width);
    printf("\nImage After Horizontal Flip:\n");
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            printf("%d ", image[i*width+j]);
        }
        printf("\n");
    }

    printf("\nImage After Brightness Adjustment:\n");
    change_brightness(image, height, width, -50);
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            printf("%d ", image[i*width+j]);
        }
        printf("\n");
    }

    printf("\nImage After Contrast Adjustment:\n");
    change_contrast(image, height, width, 1.5);
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            printf("%d ", image[i*width+j]);
        }
        printf("\n");
    }

    return 0;
}