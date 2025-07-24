//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Function to display image matrix
void displayImage(char image[][10]){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            printf("%c", image[i][j]);
        }
        printf("\n");
    }
}

// Function to flip image horizontally
void flipImage(char image[][10]){
    char temp;
    for(int i=0; i<10; i++){
        for(int j=0; j<5; j++){
            temp = image[i][j];
            image[i][j] = image[i][9-j];
            image[i][9-j] = temp;
        }
    }
}

// Function to adjust brightness
void adjustBrightness(char image[][10], int value){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if((int)image[i][j] + value < 0){
                image[i][j] = (char)0;
            }
            else if((int)image[i][j] + value > 255){
                image[i][j] = (char)255;
            }
            else{
                image[i][j] = (char)((int)image[i][j] + value);
            }
        }
    }
}

// Function to adjust contrast
void adjustContrast(char image[][10], float value){
    float factor = (259 * (value + 255)) / (255 * (259 - value));
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            int pixel = (int)image[i][j] * factor - 128 * factor + 128;
            if(pixel < 0){
                pixel = 0;
            }
            else if(pixel > 255){
                pixel = 255;
            }
            image[i][j] = (char)pixel;
        }
    }
}

int main(){
    char image[10][10] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    printf("Original Image: \n\n");
    displayImage(image);

    printf("\n\nFlipped Image: \n\n");
    flipImage(image);
    displayImage(image);

    printf("\n\nBrightened Image: \n\n");
    adjustBrightness(image, 50);
    displayImage(image);

    printf("\n\nContrasted Image: \n\n");
    adjustContrast(image, 40.0);
    displayImage(image);

    return 0;
}