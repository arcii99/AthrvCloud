//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: lively
#include <stdio.h>
#include <math.h>
#define G 6.67e-11

struct planet {
    double mass;
    double x, y;
    double vx, vy;
    double fx, fy;
};

struct planet PLANETS[] = {
    {5.97e24, 0, 0, 0, 0, 0, 0},
    {7.34e22, 3.84e8, 0, 0, 1022, 0, 0}
};

#define NUM_PLANETS (sizeof(PLANETS)/sizeof(struct planet))

double distance(int i, int j)
{
    double dx = PLANETS[j].x - PLANETS[i].x;
    double dy = PLANETS[j].y - PLANETS[i].y;
    return sqrt(dx*dx + dy*dy);
}

double force(int i, int j)
{
    double r = distance(i,j);
    double f = G * PLANETS[i].mass * PLANETS[j].mass / (r*r);
    return f;
}

void update(void)
{
    int i, j;
    for (i = 0; i < NUM_PLANETS; i++) {
        PLANETS[i].fx = PLANETS[i].fy = 0;
        for (j = 0; j < NUM_PLANETS; j++) {
            if (i == j) continue;
            double f = force(i,j);
            double dx = PLANETS[j].x - PLANETS[i].x;
            double dy = PLANETS[j].y - PLANETS[i].y;
            PLANETS[i].fx += f * dx / distance(i,j);
            PLANETS[i].fy += f * dy / distance(i,j);
        }
    }
    for (i = 0; i < NUM_PLANETS; i++) {
        PLANETS[i].vx += PLANETS[i].fx / PLANETS[i].mass;
        PLANETS[i].vy += PLANETS[i].fy / PLANETS[i].mass;
        PLANETS[i].x += PLANETS[i].vx;
        PLANETS[i].y += PLANETS[i].vy;
    }
}

int main(void)
{
    int i;
    for (i = 0; i < 365*24*60*60; i++) {
        printf("%d %g %g\n", i, PLANETS[0].x, PLANETS[0].y);
        update();
    }
    return 0;
}