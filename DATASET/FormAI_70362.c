//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: protected
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11 // Universal gravitational constant

struct Planet {
    double x, y; // Position
    double vx, vy; // Velocity
    double mass; // Mass
};

void simulate(struct Planet* planets, int num_planets, double dt) {
    for(int i = 0; i < num_planets; i++) {
        // Acceleration due to gravity
        double ax = 0, ay = 0;
        for(int j = 0; j < num_planets; j++) {
            if(i != j) {
                double dx = planets[j].x - planets[i].x;
                double dy = planets[j].y - planets[i].y;
                double dist = sqrt(dx*dx + dy*dy);
                double F = G * planets[i].mass * planets[j].mass / (dist*dist); // Force due to gravity
                ax += F * dx / dist / planets[i].mass; // Acceleration due to gravity
                ay += F * dy / dist / planets[i].mass;
            }
        }
        
        // Update velocity and position
        planets[i].vx += ax * dt;
        planets[i].vy += ay * dt;
        planets[i].x += planets[i].vx * dt;
        planets[i].y += planets[i].vy * dt;
    }
}

int main() {
    // Initialize planets
    struct Planet planets[] = {
        {0, 0, 0, 0, 5.97e24}, // Earth
        {384400e3, 0, 0, 1022, 7.34e22} // Moon
    };
    int num_planets = sizeof(planets) / sizeof(struct Planet);
    double dt = 1e-4; // Timestep in seconds
    
    // Simulate motion for 24 hours
    double t = 0;
    while(t < 24*3600) {
        // Print positions
        printf("Earth: (%f, %f)\n", planets[0].x, planets[0].y);
        printf("Moon: (%f, %f)\n", planets[1].x, planets[1].y);
        
        // Simulate motion for one timestep
        simulate(planets, num_planets, dt);
        t += dt;
    }
    
    return 0;
}