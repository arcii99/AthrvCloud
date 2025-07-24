//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: high level of detail
#include <stdio.h>
#include <math.h>
#define G 6.67e-11 

struct planet {
    char name[20];
    double mass, x, y, vx, vy, fx, fy, ax, ay;
};

struct planet planets[] = {
    {"Sun", 1.989e30, 0, 0, 0, 0, 0, 0, 0, 0},
    {"Mercury", 3.301e23, 0, 5.79e10, 47000, 0, 0, 0, 0, 0},
    {"Venus", 4.867e24, 0, 1.082e11, 35000, 0, 0, 0, 0, 0},
    {"Earth", 5.972e24, 0, 1.496e11, 30000, 0, 0, 0, 0, 0},
    {"Mars", 6.417e23, 0, 2.279e11, 24000, 0, 0, 0, 0, 0},
    {"Jupiter", 1.899e27, 0, 7.784e11, 13000, 0, 0, 0, 0, 0},
    {"Saturn", 5.683e26, 0, 1.434e12, 9000, 0, 0, 0, 0, 0},
    {"Uranus", 8.681e25, 0, 2.871e12, 6835, 0, 0, 0, 0, 0},
    {"Neptune", 1.024e26, 0, 4.498e12, 5477, 0, 0, 0, 0, 0},
};

void calculate_forces(struct planet *p1, struct planet *p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double distance = sqrt(dx * dx + dy * dy);
    double force = G * p1->mass * p2->mass / (distance * distance);
    p1->fx += force * dx / distance;
    p1->fy += force * dy / distance;
    p2->fx -= force * dx / distance;
    p2->fy -= force * dy / distance;
}

void update_position(struct planet *p, double dt) {
    p->ax = p->fx / p->mass;
    p->ay = p->fy / p->mass;
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->fx = 0;
    p->fy = 0;
}

int main() {
    double dt = 3600;
    int steps = 365 * 24;

    for (int i = 0; i < 9; i++) {
        printf("%s: mass=%f x=%f y=%f vx=%f vy=%f\n", planets[i].name, 
               planets[i].mass, planets[i].x, planets[i].y, 
               planets[i].vx, planets[i].vy);
    }

    for (int i = 0; i < steps; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                if (j != k) {
                    calculate_forces(&planets[j], &planets[k]);
                }
            }
        }

        for (int j = 0; j < 9; j++) {
            update_position(&planets[j], dt);
        }
    }

    for (int i = 0; i < 9; i++) {
        printf("%s: mass=%f x=%f y=%f vx=%f vy=%f\n", planets[i].name, 
               planets[i].mass, planets[i].x, planets[i].y, 
               planets[i].vx, planets[i].vy);
    }

    return 0;
}