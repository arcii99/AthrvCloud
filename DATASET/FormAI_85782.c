//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: light-weight
#include <stdio.h>
#include <math.h>

#define ROWS 10
#define COLS 20

char ascii_art[ROWS][COLS];

void gen_ascii_art(float x_min, float x_max, float y_min, float y_max) {
    float x_step = (x_max - x_min) / (float)COLS;
    float y_step = (y_max - y_min) / (float)ROWS;

    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {            
            float x = x_min + (float)c * x_step;
            float y = y_max - (float)r * y_step;
            
            float z = x * sin(sqrt(fabs(x))) + y * cos(sqrt(fabs(y)));
            
            if(z > 0.8) {
                ascii_art[r][c] = '$';
            } else if(z > 0.5) {
                ascii_art[r][c] = '@';
            } else if(z > 0.2) {
                ascii_art[r][c] = '#';
            } else {
                ascii_art[r][c] = '.';
            }
        }
    }
}

void print_ascii_art() {
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            printf("%c ", ascii_art[r][c]);
        }
        printf("\n");
    }
}

int main() {
    gen_ascii_art(-10.0, 10.0, -5.0, 5.0);
    print_ascii_art();
    return 0;
}