//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: happy
#include <stdio.h>
#include <math.h>

#define G 6.67e-11

// Define struct responsible for the planet
typedef struct {
    char* name;
    double mass;
    double x, y;
    double vx, vy;
} Planet;

// Define function responsible for calculating the gravitational force
void calculateForce(Planet* planet1, Planet* planet2, double* fx, double* fy) {
    double dx = planet2->x - planet1->x;
    double dy = planet2->y - planet1->y;
    double distance = sqrt(dx*dx + dy*dy);
    double force = (G * planet1->mass * planet2->mass) / (distance * distance);
    *fx = force * dx / distance;
    *fy = force * dy / distance;
}

int main() {
    // Define our happy planets!
    Planet sun = {"Sun", 1.989e30, 0, 0, 0, 0};
    Planet earth = {"Earth", 5.97e24, 1.496e11, 0, 0, 29783};

    // Define some constants
    const double deltaT = 60 * 60 * 24;
    const int numTimeSteps = 365;

    // Loop through and calculate planet position and velocity for each time step
    for (int i = 0; i < numTimeSteps; i++) {
        // Print happy message!
        printf("Happy day number %d!\n", i+1);

        // Calculate gravitational force between planets
        double fx, fy;
        calculateForce(&sun, &earth, &fx, &fy);

        // Update earth velocity and position
        earth.vx += fx / earth.mass * deltaT;
        earth.vy += fy / earth.mass * deltaT;
        earth.x += earth.vx * deltaT;
        earth.y += earth.vy * deltaT;

        // Print earth's position
        printf("Earth position: (%e, %e)\n", earth.x, earth.y);
    }

    return 0;
}