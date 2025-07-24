//FormAI DATASET v1.0 Category: Fractal Generation ; Style: genious
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

void draw_fractal(int x_min, int x_max, int y_min, int y_max, int depth) 
{
    if (depth == 0) 
    {
        return;
    }

    int x_range = x_max - x_min;
    int y_range = y_max - y_min;

    int mid_x = x_min + (x_range / 2);
    int mid_y = y_min + (y_range / 2);

    int left_x = mid_x - (x_range / 4);
    int right_x = mid_x + (x_range / 4);
    int top_y = mid_y - (y_range / 4);
    int bottom_y = mid_y + (y_range / 4);

    // Draw the square
    printf("draw_line(%d, %d, %d, %d)\n", x_min, y_min, x_max, y_min);
    printf("draw_line(%d, %d, %d, %d)\n", x_min, y_min, x_min, y_max);
    printf("draw_line(%d, %d, %d, %d)\n", x_max, y_min, x_max, y_max);
    printf("draw_line(%d, %d, %d, %d)\n", x_min, y_max, x_max, y_max);

    // Draw the fractal
    draw_fractal(left_x, mid_x, top_y, mid_y, depth - 1);
    draw_fractal(mid_x, right_x, top_y, mid_y, depth - 1);
    draw_fractal(left_x, mid_x, mid_y, bottom_y, depth - 1);
    draw_fractal(mid_x, right_x, mid_y, bottom_y, depth - 1);
}

int main() 
{
    srand(time(NULL));

    // Generate random starting values for the fractal
    int x_min = rand() % 100;
    int x_max = rand() % 100 + 100;
    int y_min = rand() % 100;
    int y_max = rand() % 100 + 100;
    int depth = rand() % 5 + 3;

    draw_fractal(x_min, x_max, y_min, y_max, depth);

    return 0;
}