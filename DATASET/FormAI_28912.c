//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define NUM_PLANETS 5
#define GRAV_CONST 6.67e-11
#define TIME_STEP 3600

struct planet {
    double mass;
    double x, y;
    double vx, vy;
};

struct planet planets[NUM_PLANETS];
pthread_t threads[NUM_PLANETS];

void *planet_gravity(void *p) {
    struct planet *planet = (struct planet *) p;
    double fx, fy, f, distance;
    int i;
    while (1) {
        fx = fy = 0;
        for (i = 0; i < NUM_PLANETS; i++) {
            if (planet == &planets[i]) continue;
            distance = sqrt(pow(planet->x - planets[i].x, 2) + pow(planet->y - planets[i].y, 2));
            f = (GRAV_CONST * planet->mass * planets[i].mass) / pow(distance, 2);
            fx += f * (planets[i].x - planet->x) / distance;
            fy += f * (planets[i].y - planet->y) / distance;
        }
        planet->vx += fx / planet->mass * TIME_STEP;
        planet->vy += fy / planet->mass * TIME_STEP;
        planet->x += planet->vx * TIME_STEP;
        planet->y += planet->vy * TIME_STEP;
        usleep(5000);
    }
    pthread_exit(NULL);
}

int main() {
    int i;
    for (i = 0; i < NUM_PLANETS; i++) {
        planets[i].mass = rand() % 10 + 1;
        planets[i].x = rand() % 1000;
        planets[i].y = rand() % 500;
        planets[i].vx = rand() % 10 - 5;
        planets[i].vy = rand() % 10 - 5;

        pthread_create(&threads[i], NULL, planet_gravity, (void *) &planets[i]);
    }
    while (1) {
        system("clear");
        for (i = 0; i < NUM_PLANETS; i++) {
            printf("Planet %d\n", i + 1);
            printf("Mass:\t%.2lf kg\n", planets[i].mass);
            printf("Position: (%.2lf, %.2lf)\n", planets[i].x, planets[i].y);
            printf("Velocity: (%.2lf, %.2lf)\n", planets[i].vx, planets[i].vy);
            printf("--------------------------------------\n");
        }
        usleep(20000);
    }
    return 0;
}