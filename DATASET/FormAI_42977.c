//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Romeo and Juliet
#include <stdio.h>

#define WIDTH 20
#define HEIGHT 10
#define RED 1
#define GREEN 2
#define BLUE 3
#define BLACK 4

void init_grid(int grid[][WIDTH]);
void draw_line(int grid[][WIDTH], int x1, int y1, int x2, int y2, int color);
void draw_balcony(int grid[][WIDTH]);

int main(void) {
    int grid[HEIGHT][WIDTH];
    
    init_grid(grid);
    draw_balcony(grid);
    
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (grid[i][j] == RED) {
                printf("R");
            } else if (grid[i][j] == GREEN) {
                printf("G");
            } else if (grid[i][j] == BLUE) {
                printf("B");
            } else if (grid[i][j] == BLACK) {
                printf("-");
            }
        }
        printf("\n");
    }
    
    return 0;
}

void init_grid(int grid[][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = BLACK;
        }
    }
}

void draw_line(int grid[][WIDTH], int x1, int y1, int x2, int y2, int color) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int increment_x = (dx > 0) ? 1 : -1;
    int increment_y = (dy > 0) ? 1 : -1;
    int abs_dx = (dx > 0) ? dx : -dx;
    int abs_dy = (dy > 0) ? dy : -dy;
    int x = x1;
    int y = y1;
    
    if (abs_dx > abs_dy) {
        int error = abs_dx / 2;
        while (x != x2) {
            grid[y][x] = color;
            error -= abs_dy;
            if (error < 0) {
                y += increment_y;
                error += abs_dx;
            }
            x += increment_x;
        }
    } else {
        int error = abs_dy / 2;
        while (y != y2) {
            grid[y][x] = color;
            error -= abs_dx;
            if (error < 0) {
                x += increment_x;
                error += abs_dy;
            }
            y += increment_y;
        }
    }
    grid[y2][x2] = color;
}

void draw_balcony(int grid[][WIDTH]) {
    draw_line(grid, 4, 3, 5, 4, RED);
    draw_line(grid, 5, 4, 6, 3, RED);
    draw_line(grid, 3, 3, 4, 4, RED);
    draw_line(grid, 2, 3, 3, 4, RED);
    draw_line(grid, 1, 3, 2, 4, RED);
    draw_line(grid, 6, 3, 7, 4, RED);
    draw_line(grid, 7, 3, 8, 4, RED);
    draw_line(grid, 4, 4, 7, 4, GREEN);
    draw_line(grid, 7, 4, 10, 4, BLUE);
}