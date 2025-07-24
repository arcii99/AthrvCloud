//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: standalone
#include <stdio.h>
#include <math.h>

#define G 6.674E-11    // gravitational constant

typedef struct {
    double x, y;   // position
    double vx, vy; // velocity
    double mass;
} planet;

planet planets[] = {
    {0.0, 0.0, 0.0, 0.0, 5.98E24}, // Earth
    {0.0, 384400000.0, 1022.0, 0.0, 7.34E22} // Moon
};

#define NUM_PLANETS (sizeof(planets) / sizeof(planet))

double distance(planet p1, planet p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

double force(planet p1, planet p2) {
    double r = distance(p1, p2);
    return G * p1.mass * p2.mass / (r * r);
}

void update_velocities() {
    int i, j;
    double fx, fy, f;
    for (i = 0; i < NUM_PLANETS; i++) {
        fx = fy = 0.0;
        for (j = 0; j < NUM_PLANETS; j++) {
            if (i == j)
                continue;
            f = force(planets[i], planets[j]);
            fx += f * (planets[j].x - planets[i].x) / distance(planets[i], planets[j]);
            fy += f * (planets[j].y - planets[i].y) / distance(planets[i], planets[j]);
        }
        planets[i].vx += fx / planets[i].mass;
        planets[i].vy += fy / planets[i].mass;
    }    
}

void update_positions(double dt) {
    int i;
    for (i = 0; i < NUM_PLANETS; i++) {
        planets[i].x += planets[i].vx * dt;
        planets[i].y += planets[i].vy * dt;
    }
}

void print_status() {
    int i;
    for (i = 0; i < NUM_PLANETS; i++) {
        printf("Planet %d: x=%.2f y=%.2f vx=%.2f vy=%.2f\n",
               i, planets[i].x, planets[i].y, planets[i].vx, planets[i].vy);
    }
}

int main() {
    int i;
    double dt = 3600.0; // one hour
    for (i = 0; i < 1000; i++) {
        printf("Time step %d:\n", i);
        update_velocities();
        update_positions(dt);
        print_status();
    }
    return 0;
}