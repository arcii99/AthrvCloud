//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 50
#define G 6.6743e-11 //Gravitational Constant

struct vector {
    double x;
    double y;
};

typedef struct planet_t {
    int id;
    double mass;
    double radius;
    double x;
    double y;
    double vx;
    double vy;
    struct vector force;
} planet;

void update_planet(planet *p, double dt) {
    //Update position
    p->x += p->vx*dt;
    p->y += p->vy*dt;
    //Update velocity
    p->vx += (p->force.x/p->mass)*dt;
    p->vy += (p->force.y/p->mass)*dt;
}

void update_force(planet *p, planet *other) {
    double dx = other->x - p->x;
    double dy = other->y - p->y;
    double r = sqrt(dx*dx + dy*dy);
    double f = G*p->mass*other->mass/(r*r);
    double fx = f*dx/r;
    double fy = f*dy/r;
    p->force.x += fx;
    p->force.y += fy;
}

void update_all_planets(planet *planets, int n, double dt) {
    //Clear forces
    for (int i = 0; i < n; ++i) {
        planets[i].force.x = planets[i].force.y = 0;
    }
    //Calculate forces
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            update_force(&planets[i], &planets[j]);
            update_force(&planets[j], &planets[i]);
        }
    }
    //Update planets
    for (int i = 0; i < n; ++i) {
        update_planet(&planets[i], dt);
    }
}

void draw_planet(planet *p, char screen[SCREEN_HEIGHT][SCREEN_WIDTH]) {
    int x = (int)p->x/1e9;
    int y = SCREEN_HEIGHT - (int)(p->y/1e9) - 1;
    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) return;
    int r = (int)(p->radius/1e9);
    for (int i = y-r; i <= y+r; ++i) {
        for (int j = x-r; j <= x+r; ++j) {
            if (i >= 0 && i < SCREEN_HEIGHT && j >= 0 && j < SCREEN_WIDTH) {
                screen[i][j] = '*';
            }
        }
    }
}

void draw_all_planets(planet *planets, int n, char screen[SCREEN_HEIGHT][SCREEN_WIDTH]) {
    //Clear screen
    for (int i = 0; i < SCREEN_HEIGHT; ++i) {
        for (int j = 0; j < SCREEN_WIDTH; ++j) {
            screen[i][j] = ' ';
        }
    }
    //Draw planets
    for (int i = 0; i < n; ++i) {
        draw_planet(&planets[i], screen);
    }
    //Draw border
    for (int j = 0; j < SCREEN_WIDTH; ++j) {
        screen[0][j] = '-';
        screen[SCREEN_HEIGHT-1][j] = '-';
    }
    for (int i = 1; i < SCREEN_HEIGHT-1; ++i) {
        screen[i][0] = '|';
        screen[i][SCREEN_WIDTH-1] = '|';
    }
}

int main() {
    //Seed random number generator
    srand(42);
    //Initialize planets
    planet planets[] = {
        {1, 1.989e30, 696340e3, 0, 0, 0, 0, {0, 0}},
        {2, 5.972e24, 6.371e6, 152.1e9, 0, 0, 30.29e3, {0, 0}},
        {3, 7.342e22, 1.737e6, 0, 384.4e6, -1.022e3, 0, {0, 0}}
    };
    int n = sizeof(planets)/sizeof(planet);
    //Initialize screen
    char screen[SCREEN_HEIGHT][SCREEN_WIDTH];
    //Simulate planets
    double dt = 3600*24; //One day
    for (double t = 0; t < 365*24*3600; t += dt) {
        update_all_planets(planets, n, dt);
        draw_all_planets(planets, n, screen);
        //Print screen
        printf("\033[2J"); //Clear screen
        printf("\033[%d;%dH", 1, 1); //Move cursor to top left corner
        for (int i = 0; i < SCREEN_HEIGHT; ++i) {
            for (int j = 0; j < SCREEN_WIDTH; ++j) {
                putchar(screen[i][j]);
            }
            putchar('\n');
        }
    }
    return 0;
}