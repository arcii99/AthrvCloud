//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>

#define WIDTH 80   //Width of screen
#define HEIGHT 40  //Height of screen

void draw_pixel(int x, int y) {
    printf("\033[%d;%dH*", y, x); //Move cursor to position and print "*"
}

void draw_fractal(int x, int y, int size, int level) {
    int half_size = size / 2;

    if (level == 0) {
        return;
    }

    //Draw diamond shape
    draw_pixel(x, y);
    draw_pixel(x + size, y);
    draw_pixel(x, y + size);
    draw_pixel(x + size, y + size);

    //Recursively draw the four smaller diamonds
    draw_fractal(x - half_size, y, half_size, level - 1); //Top left
    draw_fractal(x + size, y, half_size, level - 1);     //Top right
    draw_fractal(x, y + size, half_size, level - 1);     //Bottom left
    draw_fractal(x + size, y + size, half_size, level - 1);//Bottom right
}

int main() {
    int level;

    printf("\033[2J"); //Clear screen
    printf("\033[?25l"); //Hide cursor

    do {
        printf("Enter the level of the fractal (1-6): ");
        scanf("%d", &level);
    } while (level < 1 || level > 6);

    draw_fractal(WIDTH/2, HEIGHT/2, pow(2, level) - 1, level);

    printf("\033[%d;%dH", HEIGHT + 1, 0); //Move cursor to bottom of screen
    printf("\033[?25h"); //Show cursor

    return 0;
}