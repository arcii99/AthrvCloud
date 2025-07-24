//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define PI 3.14159265359
#define G 6.6743E-11

typedef struct planet {
    char name[20];
    double mass, radius;
    double x, y, z;
    double vx, vy, vz;
    double fx, fy, fz;
} Planet;

void force(Planet *p1, Planet *p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double dist = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * p1->mass * p2->mass / (dist*dist);

    p1->fx += f * dx / dist;
    p1->fy += f * dy / dist;
    p1->fz += f * dz / dist;

    p2->fx -= f * dx / dist;
    p2->fy -= f * dy / dist;
    p2->fz -= f * dz / dist;
}

void update(Planet *p, double dt) {
    p->vx += p->fx / p->mass * dt;
    p->vy += p->fy / p->mass * dt;
    p->vz += p->fz / p->mass * dt;

    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;

    p->fx = 0;
    p->fy = 0;
    p->fz = 0;
}

int main() {

    srand(time(NULL));

    // create the sun
    Planet sun = {"Sun", 1.9891E30, 696340000, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // create the planets
    Planet mercury = {"Mercury", 0.330E24, 2439700, 57909000000, 0, 0, 0, 48000, 0, 0, 0, 0};
    Planet venus = {"Venus", 4.87E24, 6051800, 108200000000, 0, 0, 0, 35000, 0, 0, 0, 0};
    Planet earth = {"Earth", 5.97E24, 6371000, 149600000000, 0, 0, 0, 30000, 0, 0, 0, 0};
    Planet mars = {"Mars", 0.642E24, 3396000, 227940000000, 0, 0, 0, 24000, 0, 0, 0, 0};
    Planet jupiter = {"Jupiter", 1.898E27, 71492000, 778330000000, 0, 0, 0, 13000, 0, 0, 0, 0};
    Planet saturn = {"Saturn", 5.683E26, 60268000, 1424600000000, 0, 0, 0, 9000, 0, 0, 0, 0};
    Planet uranus = {"Uranus", 8.681E25, 25559000, 2873550000000, 0, 0, 0, 6834, 0, 0, 0, 0};
    Planet neptune = {"Neptune", 1.024E26, 24764000, 4501000000000, 0, 0, 0, 5477, 0, 0, 0, 0};

    Planet planets[8] = {mercury, venus, earth, mars, jupiter, saturn, uranus, neptune};

    double dt = 3600;
    int time_step = 0;

    while (1) {

        // calculate forces on each planet
        for (int i = 0; i < 8; i++) {
            for (int j = i+1; j < 8; j++) {
                force(&planets[i], &planets[j]);
            }
            force(&sun, &planets[i]);
        }

        // update positions and velocities
        for (int i = 0; i < 8; i++)
            update(&planets[i], dt);
        update(&sun, dt);

        // print current state of the solar system
        if (time_step % 100 == 0) {
            printf("Time step: %d\n", time_step);
            printf("Sun\t\tX: %g\tY: %g\tZ: %g\n", sun.x, sun.y, sun.z);
            for (int i = 0; i < 8; i++) {
                printf("%s\tX: %g\tY: %g\tZ: %g\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
            }
            printf("\n");
        }

        time_step++;
    }

    return 0;
}