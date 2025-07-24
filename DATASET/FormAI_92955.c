//FormAI DATASET v1.0 Category: Fractal Generation ; Style: minimalist
#include <stdio.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 40

char image[HEIGHT][WIDTH];

void clear_image() {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            image[i][j] = ' ';
        }
    }
}

void plot(int x, int y) {
    if(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        image[y][x] = '#';  
    }    
}

void draw_line(int x1, int y1, int x2, int y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    
    for(double t = 0; t <= 1; t += 0.01) {
        int x = round(x1 + t*dx);
        int y = round(y1 + t*dy);
        plot(x, y);
    }
}

void fractal(int x1, int y1, int x2, int y2, int n) {
    if(n == 0) {
        draw_line(x1, y1, x2, y2);
    } else {
        int dx = x2 - x1;
        int dy = y2 - y1;
        int x3 = x1 + dx/3;
        int y3 = y1 + dy/3;
        int x4 = x2 - dx/3;
        int y4 = y2 - dy/3;
        int x5 = x3 + (int)(dx*cos(M_PI/3) + dy*sin(M_PI/3))/3;
        int y5 = y3 + (int)(-dx*sin(M_PI/3) + dy*cos(M_PI/3))/3;
        
        fractal(x1, y1, x3, y3, n-1);
        fractal(x3, y3, x5, y5, n-1);
        fractal(x5, y5, x4, y4, n-1);
        fractal(x4, y4, x2, y2, n-1);
    }
}

int main() {
    clear_image();
    fractal(0, HEIGHT/2, WIDTH-1, HEIGHT/2, 5);
    
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            putchar(image[i][j]);
        }
        putchar('\n');
    }
    
    return 0;
}