//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void flipImage(int rows, int cols, int image[][cols]){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols/2;j++){
            int temp = image[i][j];
            image[i][j] = image[i][cols-j-1];
            image[i][cols-j-1] = temp;
        }
    }
}

void changeBrightness(int rows, int cols, int image[][cols], int brightness){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            int temp = image[i][j] + brightness;
            temp = fmax(0,fmin(255,temp));
            image[i][j] = temp;
        }
    }
}

void changeContrast(int rows, int cols, int image[][cols], float contrast){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            int temp = (int) ((image[i][j]-128)*contrast)+128;
            temp = fmax(0,fmin(255,temp));
            image[i][j] = temp;
        }
    }
}

int main(){
    int rows = 5;
    int cols = 5;
    int image[5][5] = {{120,234,12,0,199},
                       {10,50,200,100,255},
                       {60,80,90,20,140},
                       {100,150,220,175,25},
                       {255,128,63,37,206}};
    
    printf("Original Image:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    printf("\nFlipped Image:\n");
    flipImage(rows, cols, image);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    printf("\nBrightness Increased By 50:\n");
    changeBrightness(rows, cols, image, 50);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    printf("\nContrast Increased By 1.5:\n");
    changeContrast(rows, cols, image, 1.5);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}