//FormAI DATASET v1.0 Category: Image Editor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WIDTH 1000
#define HEIGHT 800

void clear_screen(char img[WIDTH][HEIGHT][3], int width, int height) { // Function to clear the screen
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            img[i][j][0] = 0;
            img[i][j][1] = 0;
            img[i][j][2] = 0;
        }
    }
}

void fill_screen(char img[WIDTH][HEIGHT][3], int width, int height, int r, int g, int b) { // Function to fill the screen with a given color
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            img[i][j][0] = r;
            img[i][j][1] = g;
            img[i][j][2] = b;
        }
    }
}

void draw_rect(char img[WIDTH][HEIGHT][3], int width, int height, int x, int y, int w, int h, int r, int g, int b) { // Function to draw a rectangle
    int i, j;
    for (i = x; i < x + w; i++) {
        for (j = y; j < y + h; j++) {
            img[i][j][0] = r;
            img[i][j][1] = g;
            img[i][j][2] = b;
        }
    }
}

void draw_circle(char img[WIDTH][HEIGHT][3], int width, int height, int x, int y, int radius, int r, int g, int b) { // Function to draw a circle
    int i, j;
    double dist;
    for (i = x - radius; i <= x + radius; i++) {
        for (j = y - radius; j <= y + radius; j++) {
            dist = sqrt((i - x) * (i - x) + (j - y) * (j - y));
            if (dist <= radius) {
                img[i][j][0] = r;
                img[i][j][1] = g;
                img[i][j][2] = b;
            }
        }
    }
}

void draw_line(char img[WIDTH][HEIGHT][3], int width, int height, int x1, int y1, int x2, int y2, int r, int g, int b) { // Function to draw a line using the Bresenham's line algorithm
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;
    while (1) {
        img[x1][y1][0] = r;
        img[x1][y1][1] = g;
        img[x1][y1][2] = b;
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}

int main() {
    char img[WIDTH][HEIGHT][3]; // RGB image
    clear_screen(img, WIDTH, HEIGHT); // Clear the screen
    fill_screen(img, WIDTH, HEIGHT, 255, 255, 255); // Fill the screen with white
    draw_rect(img, WIDTH, HEIGHT, 300, 400, 400, 200, 0, 0, 255); // Draw a blue rectangle
    draw_circle(img, WIDTH, HEIGHT, 600, 600, 100, 255, 0, 0); // Draw a red circle
    draw_line(img, WIDTH, HEIGHT, 150, 200, 700, 650, 0, 255, 0); // Draw a green line
    FILE *fp;
    fp = fopen("surrealist_image.ppm", "w"); // Open the file for writing
    fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT); // Write the header of the PPM image
    int i, j;
    for (i = 0; i < WIDTH; i++) { // Write the RGB values of each pixel
        for (j = 0; j < HEIGHT; j++) {
            fprintf(fp, "%d %d %d ", img[i][j][0], img[i][j][1], img[i][j][2]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp); // Close the file
    printf("Image generated successfully!\n");
    return 0;
}