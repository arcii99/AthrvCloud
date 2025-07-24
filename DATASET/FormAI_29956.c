//FormAI DATASET v1.0 Category: Fractal Generation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 50

void fractal_generation(int x1, int y1, int x2, int y2, int depth, char fractal[HEIGHT][WIDTH]){
    // Base case
    if(depth == 0){
        return;
    }
    
    // Draw line
    int dx = x2 - x1;
    int dy = y2 - y1;
    double distance = sqrt(dx*dx + dy*dy);
    double unit_dx = dx / distance;
    double unit_dy = dy / distance;
    int rand_x = (rand() % 7) - 3;
    int rand_y = (rand() % 7) - 3;
    int new_x = x2 + (unit_dx * distance/3) + rand_x;
    int new_y = y2 + (unit_dy * distance/3) + rand_y;
    fractal_generation(x2, y2, new_x, new_y, depth - 1, fractal);
    fractal_generation(new_x, new_y, x1, y1, depth - 1, fractal);
}

int main(void){
    srand(time(NULL));
    
    // Initialize board
    char fractal[HEIGHT][WIDTH];
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            fractal[i][j] = ' ';
        }
    }
    
    // Generate fractal
    fractal_generation(0, HEIGHT/2, WIDTH - 1, HEIGHT/2, 6, fractal);
    
    // Print board
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            printf("%c", fractal[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}