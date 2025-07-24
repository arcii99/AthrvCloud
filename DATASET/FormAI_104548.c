//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: distributed
#include <stdio.h>

#define WIDTH 10
#define HEIGHT 10

void fill_pixel(char image[][WIDTH], int row, int col, char color) {
    // fill pixel at row, col with color
    image[row][col] = color;
}

void draw_rectangle(char image[][WIDTH], int x1, int y1, int x2, int y2, char color) {
    // draw a rectangle with color between (x1,y1) and (x2,y2) coordinates
    int x_start = x1 < x2 ? x1 : x2;
    int x_end = x1 > x2 ? x1 : x2;
    int y_start = y1 < y2 ? y1 : y2;
    int y_end = y1 > y2 ? y1 : y2;

    for (int i = x_start; i <= x_end; i++) {
        fill_pixel(image, i, y_start, color);
        fill_pixel(image, i, y_end, color);
    }

    for (int j = y_start; j <= y_end; j++) {
        fill_pixel(image, x_start, j, color);
        fill_pixel(image, x_end, j, color);
    }
}

void draw_line_horizontal(char image[][WIDTH], int row, int col1, int col2, char color) {
    // draw a horizontal line with color from col1 to col2 along row
    int start_col = col1 < col2 ? col1 : col2;
    int end_col = col1 > col2 ? col1 : col2;

    for (int i = start_col; i <= end_col; i++) {
        fill_pixel(image, row, i, color);
    }
}

void generate_pixel_art(char image[][WIDTH], int width, int height) {
    // generate pixel art and print on console
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", image[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char pixel_image[HEIGHT][WIDTH];
    char blank_space = '-';
    char rect_color = 'X';

    // Initialize the pixel art with blank spaces
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixel_image[i][j] = blank_space;
        }
    }

    // draw a rectangle with color
    draw_rectangle(pixel_image, 2, 2, 7, 7, rect_color);

    // draw a horizontal line in middle of image
    draw_line_horizontal(pixel_image, 4, 2, 7, rect_color);

    // generate and print pixel art
    generate_pixel_art(pixel_image, WIDTH, HEIGHT);

    return 0;
}