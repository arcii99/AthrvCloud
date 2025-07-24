//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double g = 6.67430e-11; // gravitational constant

typedef struct {
    double x,y,z;
    double vx,vy,vz;
    double ax,ay,az;
    double mass;
} planet;

double distance(planet *a, planet *b) {
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    double dz = b->z - a->z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

void acceleration(planet *a, planet *b) {
    double dist = distance(a,b);
    double force = g * a->mass * b->mass / (dist*dist);
    double ax = force * (b->x - a->x) / dist;
    double ay = force * (b->y - a->y) / dist;
    double az = force * (b->z - a->z) / dist;
    a->ax += ax;
    a->ay += ay;
    a->az += az;
}

void simulate(planet *p, int n, double t, double dt) {
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            acceleration(&p[i], &p[j]);
            acceleration(&p[j], &p[i]);
        }
    }
    for (int i=0; i<n; i++) {
        p[i].x += p[i].vx * dt;
        p[i].y += p[i].vy * dt;
        p[i].z += p[i].vz * dt;
        p[i].vx += p[i].ax * dt;
        p[i].vy += p[i].ay * dt;
        p[i].vz += p[i].az * dt;
        p[i].ax = 0;
        p[i].ay = 0;
        p[i].az = 0;
    }
    usleep(t/dt * 100000);
}

int main() {
    srand(time(NULL));
    planet planets[4];

    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].z = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    planets[0].vz = 0;
    planets[0].ax = 0;
    planets[0].ay = 0;
    planets[0].az = 0;
    planets[0].mass = 5.97e24; // earth

    planets[1].x = rand() % 100 + 50;
    planets[1].y = rand() % 100 + 50;
    planets[1].z = rand() % 100 + 50;
    planets[1].vx = rand() % 10;
    planets[1].vy = rand() % 10;
    planets[1].vz = rand() % 10;
    planets[1].ax = 0;
    planets[1].ay = 0;
    planets[1].az = 0;
    planets[1].mass = 73490000000; // jupiter

    planets[2].x = rand() % 100 + 50;
    planets[2].y = rand() % 100 + 50;
    planets[2].z = rand() % 100 + 50;
    planets[2].vx = rand() % 10;
    planets[2].vy = rand() % 10;
    planets[2].vz = rand() % 10;
    planets[2].ax = 0;
    planets[2].ay = 0;
    planets[2].az = 0;
    planets[2].mass = 102000000000; // saturn

    planets[3].x = rand() % 100 + 50;
    planets[3].y = rand() % 100 + 50;
    planets[3].z = rand() % 100 + 50;
    planets[3].vx = rand() % 10;
    planets[3].vy = rand() % 10;
    planets[3].vz = rand() % 10;
    planets[3].ax = 0;
    planets[3].ay = 0;
    planets[3].az = 0;
    planets[3].mass = 639e21; // pluto

    while (1) {
        simulate(planets, 4, 10, 0.01);
        printf("Earth: %f %f %f\n", planets[0].x, planets[0].y, planets[0].z);
        printf("Jupiter: %f %f %f\n", planets[1].x, planets[1].y, planets[1].z);
        printf("Saturn: %f %f %f\n", planets[2].x, planets[2].y, planets[2].z);
        printf("Pluto: %f %f %f\n", planets[3].x, planets[3].y, planets[3].z);
        printf("\n\n");
    }
    return 0;
}