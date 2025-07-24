//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.67408e-11 //Gravitational Constant
#define MAX_PLANETS 10 //Maximum number of planets
#define MAX_ITERATIONS 100 //Maximum number of iterations
#define DELTA_TIME 1 //Delta time for simulation

typedef struct {
    double x, y; //Position
    double vx, vy; //Velocity
    double ax, ay; //Acceleration
    double mass; //Mass
} Planet;

void calculate_acceleration(Planet p1, Planet p2, double *ax, double *ay) {
    double distance = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    double force = G * p1.mass * p2.mass / pow(distance, 2);
    double angle = atan2(p2.y - p1.y, p2.x - p1.x);
    
    *ax += force * cos(angle) / p1.mass;
    *ay += force * sin(angle) / p1.mass;
}

void simulate_gravity(Planet *planets, int num_planets) {
    int i, j, k;
    double ax, ay;
    
    for (i = 0; i < num_planets; i++) {
        ax = 0;
        ay = 0;
        
        for (j = 0; j < num_planets; j++) {
            if (i != j) {
                calculate_acceleration(planets[i], planets[j], &ax, &ay);
            }
        }
        
        planets[i].ax = ax;
        planets[i].ay = ay;
    }
    
    for (i = 0; i < num_planets; i++) {
        planets[i].vx += planets[i].ax * DELTA_TIME;
        planets[i].vy += planets[i].ay * DELTA_TIME;
        planets[i].x += planets[i].vx * DELTA_TIME;
        planets[i].y += planets[i].vy * DELTA_TIME;
    }
}

int main(void) {
    Planet planets[MAX_PLANETS];
    int num_planets, i, j, k;
    
    //Seed random number generator
    srand(time(NULL));
    
    //Generate random planets
    num_planets = rand() % MAX_PLANETS + 1;
    printf("Number of planets: %d\n", num_planets);
    
    for (i = 0; i < num_planets; i++) {
        planets[i].x = rand() % 1000;
        planets[i].y = rand() % 1000;
        planets[i].vx = rand() % 10 - 5;
        planets[i].vy = rand() % 10 - 5;
        planets[i].mass = rand() % 100 + 1;
    }
    
    //Simulate gravity
    printf("Starting simulation...\n");
    
    for (i = 0; i < MAX_ITERATIONS; i++) {
        printf("Iteration %d:\n", i + 1);
        
        for (j = 0; j < num_planets; j++) {
            printf("Planet %d: x=%f y=%f vx=%f vy=%f mass=%f\n", j + 1, planets[j].x, planets[j].y, planets[j].vx, planets[j].vy, planets[j].mass);
        }
        
        simulate_gravity(planets, num_planets);
    }
    
    return 0;
}