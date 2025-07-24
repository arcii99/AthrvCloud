//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: genious
#include <stdio.h>

// Structure to hold planet data
typedef struct {
    double mass;
    double x;
    double y;
    double vx;
    double vy;
} Planet;

// Function to calculate distance between two planets
double getDistance(Planet p1, Planet p2){
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

// Function to calculate the gravitational force between two planets
double getForce(Planet p1, Planet p2){
    double r = getDistance(p1, p2);
    double f = (p1.mass * p2.mass) / (r*r);
    return f;
}

int main(){

    // Initialize planets
    Planet earth = {5.97e24, 0, 0, 0, 0};
    Planet moon = {7.35e22, 384400, 0, 0, 1022};
    
    double time = 0; // Initialize time
    double dt = 3600; // Time step = 1 hour

    while(time <= 86400*365){ // Run for 1 year

        double force = getForce(earth, moon); // Calculate force between earth and moon
        
        // Calculate acceleration
        double ax = force / earth.mass;
        double ay = force / earth.mass;

        // Update velocity
        earth.vx += ax * dt;
        earth.vy += ay * dt;

        // Update position
        earth.x += earth.vx * dt;
        earth.y += earth.vy * dt;

        // Output position of earth and moon
        printf("Time: %lf, Earth position: (%lf,%lf), Moon position: (%lf,%lf)\n", time, earth.x, earth.y, moon.x, moon.y);

        // Update time
        time += dt;
    }

    return 0;
}