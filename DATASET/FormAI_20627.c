//FormAI DATASET v1.0 Category: Fractal Generation ; Style: ultraprecise
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ITERATIONS 1000
#define SCREEN_WIDTH 120
#define SCREEN_HEIGHT 40
#define SCALE 0.03

int world[SCREEN_WIDTH][SCREEN_HEIGHT];

int rand_range(int min, int max){
    int range = max - min + 1;
    return min + rand() % range;
}

int get_color(int value){
    if(value == -1) return ' ';
    else if(value == 0) return '.';
    else if(value == 1) return '-';
    else if(value == 2) return '|';
    else if(value == 3) return '/';
    else if(value == 4) return '\\';
    else if(value == 5) return '*';
    else return ' ';
}

void print_world(){
    for(int y = 0; y < SCREEN_HEIGHT; y++){
        for(int x = 0; x < SCREEN_WIDTH; x++){
            printf("%c", get_color(world[x][y]));
        }
        printf("\n");
    }
}

void set_value(int x, int y, int value){
    if(x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT || x < 0 || y < 0) return;
    world[x][y] = value;
}

void draw_line(int x1, int y1, int x2, int y2){
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;
    int e2;

    while(1){
        set_value(x1, y1, 5);

        if(x1 == x2 && y1 == y2) break;

        e2 = 2 * err;
        if(e2 > -dy){
            err -= dy;
            x1 += sx;
        }
        if(e2 < dx){
            err += dx;
            y1 += sy;
        }
    }
}

void draw_fractal(int x1, int y1, int x2, int y2){
    int dx = x2 - x1;
    int dy = y2 - y1;

    if(sqrt(dx*dx + dy*dy) < SCALE){
        draw_line(x1, y1, x2, y2);
        return;
    }

    int x3 = x1 + dx/3;
    int y3 = y1 + dy/3;
    int x4 = x2 - dx/3;
    int y4 = y2 - dy/3;

    float angle = atan2((float)dy, (float)dx) + 3.14159265358979323846/3;
    int length = sqrt(dx*dx + dy*dy)/3;

    int x5 = x3 + length*cos(angle);
    int y5 = y3 + length*sin(angle);

    draw_fractal(x1, y1, x3, y3);
    draw_fractal(x3, y3, x5, y5);
    draw_fractal(x5, y5, x4, y4);
    draw_fractal(x4, y4, x2, y2);
}

int main(){
    srand(time(NULL));

    memset(world, -1, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(int));

    int mid_x = rand_range(SCREEN_WIDTH/4, 3*SCREEN_WIDTH/4);
    int mid_y = rand_range(SCREEN_HEIGHT/4, 3*SCREEN_HEIGHT/4);

    draw_fractal(SCREEN_WIDTH/2, 0, mid_x, mid_y);
    draw_fractal(mid_x, mid_y, SCREEN_WIDTH/2, SCREEN_HEIGHT);
    draw_fractal(SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT);

    print_world();

    return 0;
}