//FormAI DATASET v1.0 Category: Fractal Generation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void fractal(int level, int width, int height, int x_offset, int y_offset, char fractal_char){
    if(level == 0){
        return;
    }

    // Calculate new width and height for next level
    int new_width = width / 3;
    int new_height = height / 3;

    // Recursive calls for each part of the fractal
    fractal(level-1, new_width, new_height, x_offset, y_offset, fractal_char); // Top left
    fractal(level-1, new_width, new_height, x_offset+new_width, y_offset, fractal_char); // Top middle
    fractal(level-1, new_width, new_height, x_offset+2*new_width, y_offset, fractal_char); // Top right

    fractal(level-1, new_width, new_height, x_offset, y_offset+new_height, fractal_char); // Middle left
    printf("%c", fractal_char); // Middle middle
    fractal(level-1, new_width, new_height, x_offset+2*new_width, y_offset+new_height, fractal_char); // Middle right

    fractal(level-1, new_width, new_height, x_offset, y_offset+2*new_height, fractal_char); // Bottom left
    fractal(level-1, new_width, new_height, x_offset+new_width, y_offset+2*new_height, fractal_char); // Bottom middle
    fractal(level-1, new_width, new_height, x_offset+2*new_width, y_offset+2*new_height, fractal_char); // Bottom right
}

int main(){
    int level = 4;
    int width = 27;
    int height = 27;
    int x_offset = 0;
    int y_offset = 0;
    char fractal_char = '*';

    fractal(level, width, height, x_offset, y_offset, fractal_char);

    return 0;
}