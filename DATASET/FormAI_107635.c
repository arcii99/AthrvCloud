//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: recursive
#include <stdio.h>

// recursive function to draw each pixel
void drawPixel(int x, int y, char pixel) {
    printf("%c ", pixel); // print pixel at position (x,y)
    if(x == 0) { // if we are at the left edge of the screen, move to the next line
        printf("\n");
        if(y > 0) { // if there are more lines to draw, move one line up and start at the right edge
            drawPixel(9, y-1, pixel);
        }
    }
    else { // if we are not at the left edge of the screen, move one pixel to the left
        drawPixel(x-1, y, pixel);
    }
}

// function to generate random pixel art
void generatePixelArt(int width, int height) {
    if(height == 0) { // base case: stop the recursion when we reach the bottom of the screen
        return;
    }
    char pixels[] = {'O','X','-','*','+','=','@','#','$','&'}; // array of pixel characters to choose from
    int randomIndex = rand() % 10; // pick a random index between 0 and 9
    char pixel = pixels[randomIndex]; // get the pixel character at the random index
    drawPixel(width-1, height-1, pixel); // start drawing the pixel at the bottom-right corner of the screen
    generatePixelArt(width, height-1); // make a recursive call with one less row to draw the rest of the screen
}

int main() {
    srand(time(NULL)); // seed the random number generator with the current time
    int width = 10;
    int height = 10;
    generatePixelArt(width, height);
    return 0;
}