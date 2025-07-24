//FormAI DATASET v1.0 Category: Image Editor ; Style: medieval
//Medieval Style C Image Editor

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 100
#define HEIGHT 100

//function to update pixel color in the image
void updatePixel(int image[WIDTH][HEIGHT], int x, int y, int color) {
    image[x][y] = color;
}

//function to print the image
void printImage(int image[WIDTH][HEIGHT]) {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            if(image[i][j] == 0) {
                printf(" ");
            }
            else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int main() {
    //initializing the image
    int image[WIDTH][HEIGHT];
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            image[i][j] = 0; //set all pixels to white
        }
    }

    //adding some medieval style images
    updatePixel(image, 10, 10, 1); //castle walls
    updatePixel(image, 10, 11, 1);
    updatePixel(image, 10, 12, 1);
    updatePixel(image, 10, 13, 1);
    updatePixel(image, 10, 14, 1);
    updatePixel(image, 11, 10, 1);
    updatePixel(image, 11, 14, 1);
    updatePixel(image, 12, 10, 1);
    updatePixel(image, 12, 14, 1);
    updatePixel(image, 13, 10, 1);
    updatePixel(image, 13, 14, 1);
    updatePixel(image, 14, 10, 1);
    updatePixel(image, 14, 11, 1);
    updatePixel(image, 14, 12, 1);
    updatePixel(image, 14, 13, 1);
    updatePixel(image, 14, 14, 1);

    updatePixel(image, 20, 10, 2); //tree trunk
    updatePixel(image, 20, 11, 2);
    updatePixel(image, 20, 12, 2);
    updatePixel(image, 21, 11, 2);
    updatePixel(image, 21, 12, 2);
    updatePixel(image, 22, 12, 2);

    updatePixel(image, 17, 20, 3); //sword
    updatePixel(image, 18, 20, 3);
    updatePixel(image, 19, 20, 3);
    updatePixel(image, 20, 20, 3);
    updatePixel(image, 21, 20, 3);
    updatePixel(image, 22, 20, 3);
    updatePixel(image, 23, 20, 3);

    updatePixel(image, 40, 40, 4); //shield
    updatePixel(image, 41, 40, 4);
    updatePixel(image, 42, 40, 4);
    updatePixel(image, 43, 40, 4);
    updatePixel(image, 44, 40, 4);
    updatePixel(image, 45, 40, 4);
    updatePixel(image, 46, 40, 4);
    updatePixel(image, 42, 41, 4);
    updatePixel(image, 44, 41, 4);
    updatePixel(image, 42, 42, 4);
    updatePixel(image, 44, 42, 4);
    updatePixel(image, 42, 43, 4);
    updatePixel(image, 44, 43, 4);
    updatePixel(image, 43, 44, 4);

    //printing the image
    printImage(image);
    
    return 0;
}