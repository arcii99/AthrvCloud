//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <math.h>
#define GRAV_CONST 6.67408e-11 //Gravitational constant

typedef struct {
    double x, y; //Position
    double vx, vy; //Velocity
    double mass; //Mass of planet
} Planet;

void update_velocity(Planet *p, double fx, double fy, double dt) {
    double ax = fx / p->mass;
    double ay = fy / p->mass;
    p->vx += ax * dt;
    p->vy += ay * dt;
}

void update_position(Planet *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

double distance(Planet *p1, Planet *p2) {
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    return sqrt(dx*dx + dy*dy);
}

double gravitational_force(Planet *p1, Planet *p2) {
    double r = distance(p1, p2);
    return GRAV_CONST * p1->mass * p2->mass / (r*r);
}

void calculate_force(Planet *p1, Planet *p2, double *fx, double *fy) {
    double force = gravitational_force(p1, p2);
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double angle = atan2(dy, dx);
    *fx = force * cos(angle);
    *fy = force * sin(angle);
}

int main() {
    Planet planets[] = {
        {0, 0, 0, 0, 1.989e30}, //Sun
        {57.9e9, 0, 0, 47.36e3, 3.301e23}, //Mercury
        {108.2e9, 0, 0, 35.02e3, 4.869e24}, //Venus
        {149.6e9, 0, 0, 29.78e3, 5.972e24}, //Earth
        {227.9e9, 0, 0, 24.077e3, 6.421e23}, //Mars
        {778.5e9, 0, 0, 13.07e3, 1.899e27}, //Jupiter
        {1433.5e9, 0, 0, 9.68e3, 5.685e26}, //Saturn
        {2872.5e9, 0, 0, 6.81e3, 8.683e25}, //Uranus
        {4504.0e9, 0, 0, 5.43e3, 1.0247e26}, //Neptune
    };
    int num_planets = sizeof(planets) / sizeof(Planet);
    double dt = 3600 * 24; //Time step is one day
    double fx, fy;
    
    //Simulation loop
    for (int t = 0; t < 365*10; t++) { //Simulate 10 earth years
        //Calculate forces on each planet
        for (int i = 0; i < num_planets; i++) {
            fx = fy = 0;
            for (int j = 0; j < num_planets; j++) {
                if (i == j) continue;
                calculate_force(&planets[i], &planets[j], &fx, &fy);
            }
            update_velocity(&planets[i], fx, fy, dt);
        }
        
        //Update planet positions
        for (int i = 0; i < num_planets; i++) {
            update_position(&planets[i], dt);
        }
        
        //Print planet positions
        printf("%d\t", t);
        for (int i = 0; i < num_planets; i++) {
            printf("%.3f, %.3f\t", planets[i].x, planets[i].y);
        }
        printf("\n");
    }
    
    return 0;
}