//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: complete
#include <stdio.h>

// Define the size of the canvas
#define WIDTH 10
#define HEIGHT 10

// Define the colors
typedef enum {
    BLACK = 0,
    RED = 1,
    GREEN = 2,
    YELLOW = 3,
    BLUE = 4,
    MAGENTA = 5,
    CYAN = 6,
    WHITE = 7
} Color;

// Define the pixel structure
typedef struct {
    Color color;
} Pixel;

// Define the canvas structure
typedef struct {
    Pixel pixels[WIDTH][HEIGHT];
} Canvas;

// Function to generate a random color
Color random_color() {
    return rand() % 8; // Random number between 0 and 7
}

// Function to draw a pixel in the canvas at position (x, y) with color c
void draw_pixel(Canvas *canvas, int x, int y, Color c) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        canvas->pixels[x][y].color = c;
    }
}

// Function to draw a rectangle in the canvas starting at position (x, y) with size (w, h) and color c
void draw_rect(Canvas *canvas, int x, int y, int w, int h, Color c) {
    for (int i = x; i < x + w; i++) {
        for (int j = y; j < y + h; j++) {
            draw_pixel(canvas, i, j, c);
        }
    }
}

// Function to draw a circle in the canvas centered at position (x, y) with radius r and color c
void draw_circle(Canvas *canvas, int x, int y, int r, Color c) {
    for (int i = x - r; i <= x + r; i++) {
        for (int j = y - r; j <= y + r; j++) {
            int dx = i - x;
            int dy = j - y;
            if (dx * dx + dy * dy <= r * r) {
                draw_pixel(canvas, i, j, c);
            }
        }
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a canvas
    Canvas canvas;

    // Fill the canvas with black pixels
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            canvas.pixels[i][j].color = BLACK;
        }
    }

    // Draw some random shapes
    draw_rect(&canvas, 2, 2, 6, 6, random_color());
    draw_circle(&canvas, 5, 5, 3, random_color());

    // Print the canvas
    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {
            switch (canvas.pixels[i][j].color) {
                case BLACK:
                    printf("  ");
                    break;
                case RED:
                    printf("\033[31m##\033[0m");
                    break;
                case GREEN:
                    printf("\033[32m##\033[0m");
                    break;
                case YELLOW:
                    printf("\033[33m##\033[0m");
                    break;
                case BLUE:
                    printf("\033[34m##\033[0m");
                    break;
                case MAGENTA:
                    printf("\033[35m##\033[0m");
                    break;
                case CYAN:
                    printf("\033[36m##\033[0m");
                    break;
                case WHITE:
                    printf("\033[37m##\033[0m");
                    break;
                default:
                    printf("  ");
                    break;
            }
        }
        printf("\n");
    }

    return 0;
}