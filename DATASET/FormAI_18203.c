//FormAI DATASET v1.0 Category: Fractal Generation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SCREEN_WIDTH  80
#define SCREEN_HEIGHT 40

typedef struct {
    double x;
    double y;
} point_t;

static void move_to(point_t *p, double x, double y)
{
    p->x = x;
    p->y = y;
}

static void line_to(point_t *p, double x, double y)
{
    printf("%c[%d;%df", 0x1B, round(SCREEN_HEIGHT - p->y), round(p->x));
    p->x = x;
    p->y = y;
    printf("%c[38;5;%dm%c", 0x1B, rand()%256, '#');
    printf("%c[%d;%df", 0x1B, round(SCREEN_HEIGHT - y), round(x));
}

static void draw_koch_curve(point_t *p, double x, double y, int n)
{
    if (n == 0) {
        line_to(p, x, y);
    } else {
        double dx = (x - p->x)/3.0;
        double dy = (y - p->y)/3.0;
        double mx = p->x + dx;
        double my = p->y + dy;
        double nx = mx + dx*cos(M_PI/3) - dy*sin(M_PI/3);
        double ny = my + dx*sin(M_PI/3) + dy*cos(M_PI/3);
        draw_koch_curve(p, mx, my, n-1);
        draw_koch_curve(p, nx, ny, n-1);
        draw_koch_curve(p, x, y, n-1);
    }
}

int main(void)
{
    point_t p;
    int i, j;
    for (i = 1; i <= SCREEN_HEIGHT; i++) {
        printf("\n");
    }
    for (i = 0; i < SCREEN_WIDTH; i++) {
        printf("#");
    }
    printf("\n");
    srand((unsigned)time(NULL));
    for (i = 0; i < SCREEN_WIDTH; i++) {
        move_to(&p, i, SCREEN_HEIGHT-1);
        draw_koch_curve(&p, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 4);
    }
    printf("%c[%d;%df", 0x1B, SCREEN_HEIGHT, 0);
    for (i = 0; i < SCREEN_WIDTH; i++) {
        printf("#");
    }
    printf("\n");
    return 0;
}