//FormAI DATASET v1.0 Category: Image Editor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

//defining a structure that will hold the pixel coordinate and color value 
struct Pixel {
    int x, y;
    int color;
};

//Method to print the full image
void printImage(int image[MAX_SIZE][MAX_SIZE], int w, int h) {
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

//Method to draw a line between two pixels
void drawLine(int image[MAX_SIZE][MAX_SIZE], struct Pixel p1, struct Pixel p2) {
    int dx, dy, steps=1;
    int x,y;

    dx = p2.x - p1.x;
    dy = p2.y - p1.y;

    if(abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    float xIncrement = dx / (float) steps;
    float yIncrement = dy / (float) steps;

    x = p1.x;
    y = p1.y;

    image[y][x] = p1.color;

    for(int i=0;i<steps;i++) {
        x += xIncrement;
        y += yIncrement;
        image[(int)y][(int)x] = p1.color;
    }
}

//Method to fill a rectangle with a color value
void fillRectangle(int image[MAX_SIZE][MAX_SIZE], struct Pixel p1, struct Pixel p2, int color) {
    for(int i=p1.x;i<=p2.x;i++) {
        for(int j=p1.y;j<=p2.y;j++) {
            image[j][i] = color;
        }
    }
}

//Main method to execute the program
int main() {
    int width = 8;
    int height = 8;
    int image[MAX_SIZE][MAX_SIZE]; //initializing a 2D array for image
    //intializing the image with default color 0
    for(int i=0;i<height;i++) {
        for(int j=0;j<width;j++) {
            image[i][j] = 0;
        }
    }

    //creating two pixel types to make a line in the image
    struct Pixel p1 = {1, 1, 1};
    struct Pixel p2 = {6, 6, 1};
    drawLine(image, p1, p2);

    //creating two pixel types to make a rectangle in the image
    struct Pixel p3 = {2, 2, 1}; 
    struct Pixel p4 = {5, 5, 1};
    fillRectangle(image, p3, p4, 2);

    printImage(image, width, height); // printing the image output

    return 0;
}