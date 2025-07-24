//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: standalone
#include<stdio.h>

void flipImage(int img[], int rows, int cols){
    int temp;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols/2;j++){
            temp = img[i*cols+j];
            img[i*cols+j] = img[i*cols+cols-j-1];
            img[i*cols+cols-j-1] = temp;
        }
    }
}

void changeBrightnessContrast(int img[], int rows, int cols, int brightness, int contrast){
    int pixel_val, new_val;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            pixel_val = img[i*cols+j];
            new_val = contrast*pixel_val+brightness;
            new_val = new_val>255? 255:new_val;
            new_val = new_val<0? 0:new_val;
            img[i*cols+j] = new_val;
        }
    }
}

void printImage(int img[], int rows, int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ",img[i*cols+j]);
        }
        printf("\n");
    }
}

int main(){
    int img[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int rows = 3;
    int cols = 3;
    printf("Original Image:\n");
    printImage(img,rows,cols);

    flipImage(img,rows,cols);
    printf("Flipped Image:\n");
    printImage(img,rows,cols);

    int brightness = 50;
    int contrast = 2;
    changeBrightnessContrast(img,rows,cols,brightness,contrast);
    printf("Brightness and Contrast Adjusted Image:\n");
    printImage(img,rows,cols);

    return 0;
}