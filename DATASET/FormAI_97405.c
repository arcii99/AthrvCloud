//FormAI DATASET v1.0 Category: Image Editor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

//Define width and height of image
#define WIDTH 10
#define HEIGHT 10

//Define image data structure as an array of integers
//Each integer represents the color of a pixel (0=black, 255=white)
//Pixel order: top-left to bottom-right
int image[WIDTH * HEIGHT];

//Function to initialize image to white (255)
void initialize_image() {
    for (int i=0; i<WIDTH*HEIGHT; i++) {
        image[i] = 255;
    }
}

//Function to display image
void display_image() {
    printf("\n");

    for (int y=0; y<HEIGHT; y++) {
        for (int x=0; x<WIDTH; x++) {
            printf("%d ", image[y*WIDTH + x]);
        }

        printf("\n");
    }

    printf("\n");
}

//Function to draw a line (horizontal, vertical, or diagonal)
void draw_line(int x1, int y1, int x2, int y2) {
    //Calculate change in x and y
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    //Determine direction of line
    int x_dir, y_dir;

    if (x2 > x1) {
        x_dir = 1;
    } else {
        x_dir = -1;
    }

    if (y2 > y1) {
        y_dir = 1;
    } else {
        y_dir = -1;
    }

    //Initialize error values
    int error = dx - dy;
    int x = x1;
    int y = y1;

    //Draw line pixel by pixel
    while (x != x2 || y != y2) {
        //Set pixel at current position to black (0)
        image[y*WIDTH + x] = 0;

        //Calculate error term
        int error2 = error * 2;

        //If error term is negative, move in x direction
        if (error2 > -dy) {
            error -= dy;
            x += x_dir;
        }

        //If error term is positive, move in y direction
        if (error2 < dx) {
            error += dx;
            y += y_dir;
        }
    }
}

int main() {
    //Initialize image to white
    initialize_image();

    //Draw vertical line
    draw_line(5, 0, 5, 9);

    //Draw horizontal line
    draw_line(0, 5, 9, 5);

    //Draw diagonal line
    draw_line(0, 0, 9, 9);

    //Display image
    display_image();

    return 0;
}