//FormAI DATASET v1.0 Category: Image Editor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 300  // Width of the image
#define HEIGHT 200 // Height of the image

// Function to generate random pixel values
int generateColor() {
    return rand() % 256;
}

// Function to draw a line between two points
void drawLine(int x1, int y1, int x2, int y2, int image[WIDTH][HEIGHT], int red, int green, int blue) {
    float m = (y2 - y1) / (float)(x2 - x1);
    float c = y1 - m * x1;

    for (int x = x1; x <= x2; x++) {
        int y = round(m * x + c);
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
            image[x][y] = (red << 16) | (green << 8) | blue;
        }
    }
}

// Function to draw a rectangle
void drawRectangle(int x1, int y1, int x2, int y2, int image[WIDTH][HEIGHT], int red, int green, int blue) {
    drawLine(x1, y1, x2, y1, image, red, green, blue); // Top line
    drawLine(x1, y2, x2, y2, image, red, green, blue); // Bottom line
    drawLine(x1, y1, x1, y2, image, red, green, blue); // Left line
    drawLine(x2, y1, x2, y2, image, red, green, blue); // Right line
}

// Function to draw a circle
void drawCircle(int x, int y, int radius, int image[WIDTH][HEIGHT], int red, int green, int blue) {
    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {
            if (i * i + j * j <= radius * radius) {
                int px = x + i;
                int py = y + j;
                if (px >= 0 && px < WIDTH && py >= 0 && py < HEIGHT) {
                    image[px][py] = (red << 16) | (green << 8) | blue;
                }
            }
        }
    }
}

int main() {
    int image[WIDTH][HEIGHT];

    // Initialize image to black
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            image[i][j] = 0; // Black
        }
    }

    // Draw castle shape
    drawRectangle(50, 100, 250, 150, image, 0xCC, 0x99, 0x33); // Sand-colored rectangle
    drawRectangle(50, 80, 100, 100, image, 0xCC, 0, 0); // Red rectangle
    drawLine(50, 80, 75, 70, image, 0xCC, 0, 0); // Left roof triangle
    drawLine(100, 80, 75, 70, image, 0xCC, 0, 0); // Right roof triangle
    drawRectangle(125, 80, 175, 100, image, 0x33, 0x33, 0x33); // Gray rectangle
    drawLine(125, 80, 150, 50, image, 0x33, 0x33, 0x33); // Left peak
    drawLine(175, 80, 150, 50, image, 0x33, 0x33, 0x33); // Right peak
    drawRectangle(180, 80, 220, 100, image, 0xCC, 0xCC, 0); // Yellow rectangle
    drawLine(180, 80, 200, 40, image, 0xCC, 0xCC, 0); // Left peak
    drawLine(220, 80, 200, 40, image, 0xCC, 0xCC, 0); // Right peak

    // Draw trees
    drawCircle(80, 140, 20, image, 0, 0x99, 0); // Green circle for top of tree
    drawRectangle(70, 140, 90, 170, image, 0x99, 0x66, 0); // Brown rectangle for trunk
    drawCircle(220, 120, 25, image, 0, 0x99, 0); // Green circle for top of tree
    drawRectangle(210, 120, 230, 150, image, 0x99, 0x66, 0); // Brown rectangle for trunk

    // Output image as PPM file
    FILE* fp = fopen("medieval_image.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int j = 0; j < HEIGHT; ++j) {
        for (int i = 0; i < WIDTH; ++i) {
            fputc((image[i][j] >> 16) & 0xFF, fp); // Red
            fputc((image[i][j] >> 8) & 0xFF, fp);  // Green
            fputc(image[i][j] & 0xFF, fp);         // Blue
        }
    }
    fclose(fp);

    return 0;
}