//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: minimalist
#include <stdio.h>
#include <math.h>

#define NUM_PLANETS 8
#define G  6.6743e-11  // Gravitational constant
#define SUN_MASS 1.989e30

struct planet {
    char name[10];
    double mass;    // kg
    double x, y;    // position (m)
    double vx, vy;  // velocity (m/s)
};

struct planet planets[NUM_PLANETS] = {
    {"Mercury", 3.303e23, 5.791e10, 0.0, 0.0, 47.87e3},
    {"Venus", 4.869e24, 1.082e11, 0.0, 0.0, 35.02e3},
    {"Earth", 5.976e24, 1.496e11, 0.0, 0.0, 29.78e3},
    {"Mars", 6.421e23, 2.279e11, 0.0, 0.0, 24.08e3},
    {"Jupiter", 1.9e27, 7.786e11, 0.0, 0.0, 13.07e3},
    {"Saturn", 5.688e26, 1.433e12, 0.0, 0.0, 9.69e3},
    {"Uranus", 8.686e25, 2.872e12, 0.0, 0.0, 6.80e3},
    {"Neptune", 1.024e26, 4.495e12, 0.0, 0.0, 5.43e3},
};

void calculate_acceleration(struct planet *a, struct planet *b, double *ax, double *ay) {
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    double distance = sqrt(dx*dx + dy*dy);
    double force = G * a->mass * b->mass / (distance * distance);
    *ax = force / a->mass * dx / distance;
    *ay = force / a->mass * dy / distance;
}

int main() {
    double time_step = 24 * 60 * 60;    // 1 day
    int duration = 365;                 // 1 year
    for (int d = 0; d < duration; d++) {
        for (int i = 0; i < NUM_PLANETS; i++) {
            double ax = 0.0, ay = 0.0;
            for (int j = 0; j < NUM_PLANETS; j++) {
                if (i != j) {
                    calculate_acceleration(&planets[i], &planets[j], &ax, &ay);
                }
            }
            planets[i].vx += ax * time_step;
            planets[i].vy += ay * time_step;
            planets[i].x += planets[i].vx * time_step;
            planets[i].y += planets[i].vy * time_step;
        }
        printf("Day %d:\n", d);
        for (int i = 0; i < NUM_PLANETS; i++) {
            printf("%s: %.2f AU from the sun\n", planets[i].name, sqrt(planets[i].x*planets[i].x + planets[i].y*planets[i].y) / 149.6e9);
        }
    }
    return 0;
}