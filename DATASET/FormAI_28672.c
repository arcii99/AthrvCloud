//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.141592653589793
#define G 6.67408e-11

typedef struct {
    double x, y;
} coor; 

typedef struct {
    coor pos;
    coor vel;
    double mass;
} body;

body bodies[] = {
    {{0, 0}, {0, 0}, 1.989e30}, //Sun
    {{-57.9e9, 0}, {0, 47.8e3}, 3.3011e23}, //Mercury
    {{0, -108.2e9}, {35.0e3, 0}, 4.8675e24}, //Venus
    {{149.6e9, 0}, {0, -29.3e3}, 5.972e24}, //Earth
    {{0, 227.9e9}, {-24.1e3, 0}, 6.4171e23}, //Mars
    {{778.5e9, 0}, {0, -13.1e3}, 1.8986e27}, //Jupiter
    {{0, -1433.5e9}, {13.0e3, 0}, 5.6846e26}, //Saturn
    {{2872.5e9, 0}, {0, -9.7e3}, 8.6810e25}, //Uranus
    {{0, 4495.1e9}, {-6.8e3, 0}, 1.0243e26} //Neptune
};

void print_bodies(int n) {
    for (int i = 0; i < n; i++) {
        printf("Body %d: x = %lf, y = %lf\n", i+1, bodies[i].pos.x, bodies[i].pos.y);
    }
}

void update_positions(int n, double dt) {
    for (int i = 0; i < n; i++) {
        bodies[i].pos.x += bodies[i].vel.x * dt;
        bodies[i].pos.y += bodies[i].vel.y * dt;
    }
}

coor acceleration(body b1, body b2) {
    double r = sqrt(pow(b2.pos.x - b1.pos.x, 2) + pow(b2.pos.y - b1.pos.y, 2));
    double a = G * b2.mass / pow(r, 2);
    coor direction = { (b2.pos.x - b1.pos.x) / r, (b2.pos.y - b1.pos.y) / r };
    return (coor) { a * direction.x, a * direction.y };
}

void update_velocities(int n, double dt) {
    coor acc[n];
    for (int i = 0; i < n; i++) {
        acc[i] = (coor) {0, 0};
        for (int j = 0; j < n; j++) {
            if (i != j) {
                coor a = acceleration(bodies[i], bodies[j]);
                acc[i].x += a.x;
                acc[i].y += a.y;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        bodies[i].vel.x += acc[i].x * dt;
        bodies[i].vel.y += acc[i].y * dt;
    }
}

int main() {
    int n = 9;
    double dt = 3600 * 24; //1 day
    int total_time = 365 * 5; //5 years
    srand(time(NULL));
    for (int i = 1; i < n; i++) { //add some random initial velocity to planets
        bodies[i].vel.x = ((double)rand() / RAND_MAX) * 1000 - 500;
        bodies[i].vel.y = ((double)rand() / RAND_MAX) * 1000 - 500;
    }
    for (int i = 0; i < total_time; i++) {
        update_positions(n, dt);
        update_velocities(n, dt);
    }
    print_bodies(n);
    return 0;
}