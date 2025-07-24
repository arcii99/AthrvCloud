//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 40
#define MAX_PLANETS 10
#define GRAV_CONST 100

typedef struct {
    double x, y;
    double mass;
    double vx, vy;
} planet;

void draw_planet(planet p) {
    int x = WIDTH / 2 + (int)(p.x);
    int y = HEIGHT / 2 + (int)(p.y);
    int r = (int)pow(p.mass, 1.0 / 3.0);
    printf("\033[%d;%dH", y, x);
    printf("@");
    printf("\033[%d;%dH", y, x - r);
    printf("\\");
    printf("\033[%d;%dH", y, x + r);
    printf("/");
}

void erase_planet(planet p) {
    int x = WIDTH / 2 + (int)(p.x);
    int y = HEIGHT / 2 + (int)(p.y);
    int r = (int)pow(p.mass, 1.0 / 3.0);
    printf("\033[%d;%dH", y, x);
    printf(" ");
    printf("\033[%d;%dH", y, x - r);
    printf(" ");
    printf("\033[%d;%dH", y, x + r);
    printf(" ");
}

double calc_distance(planet p1, planet p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

double calc_force(planet p1, planet p2) {
    double distance = calc_distance(p1, p2);
    return GRAV_CONST * p1.mass * p2.mass / (distance * distance);
}

void update_planet(planet p, planet *planets, int n) {
    double fx = 0, fy = 0;
    for (int i = 0; i < n; i++) {
        if (p.x == planets[i].x && p.y == planets[i].y) continue;
        double force = calc_force(p, planets[i]);
        double angle = atan2(planets[i].y - p.y, planets[i].x - p.x);
        fx += force * cos(angle);
        fy += force * sin(angle);
    }
    p.vx += fx / p.mass;
    p.vy += fy / p.mass;
    p.x += p.vx;
    p.y += p.vy;
}

void init_planet(planet *p, double x, double y) {
    p->x = x;
    p->y = y;
    p->mass = (double)(rand() % 10000) / 100;
    p->vx = (double)(rand() % 1000) - 500;
    p->vy = (double)(rand() % 1000) - 500;
}

int main() {
    srand(time(0));
    planet planets[MAX_PLANETS];
    int n = rand() % MAX_PLANETS + 1;
    for (int i = 0; i < n; i++) {
        init_planet(&planets[i], (double)(rand() % WIDTH) - WIDTH / 2, (double)(rand() % HEIGHT) - HEIGHT / 2);
    }
    printf("\033[2J");
    while (1) {
        for (int i = 0; i < n; i++) {
            erase_planet(planets[i]);
        }
        for (int i = 0; i < n; i++) {
            update_planet(planets[i], planets, n);
        }
        for (int i = 0; i < n; i++) {
            draw_planet(planets[i]);
        }
        fflush(stdout);
        usleep(100000);
    }
    return 0;
}