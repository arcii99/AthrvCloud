//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: creative
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11 // gravitational constant
#define TIMESTEP 86400 // 1 day in seconds

typedef struct {
    double x; // x coordinate
    double y; // y coordinate
    double z; // z coordinate
} Vector3;

typedef struct {
    Vector3 position; // position vector
    Vector3 velocity; // velocity vector
    Vector3 acceleration; // acceleration vector
    double mass; // mass of planet
} Planet;

int main() {
    // create two planets
    Planet earth = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 5.97e24};
    Planet moon = {{3.84e8, 0, 0}, {0, 1022, 0}, {0, 0, 0}, 7.34e22};

    // simulate GRAVITY_DURATION days
    const int GRAVITY_DURATION = 365;
    for (int i = 0; i < GRAVITY_DURATION; i++) {

        // calculate distance between planets
        double dx = moon.position.x - earth.position.x;
        double dy = moon.position.y - earth.position.y;
        double dz = moon.position.z - earth.position.z;
        double dist = sqrt(dx*dx + dy*dy + dz*dz);

        // calculate gravitational force between planets
        double force = G * earth.mass * moon.mass / (dist*dist);

        // resolve force vector into components
        double fx = force * dx / dist;
        double fy = force * dy / dist;
        double fz = force * dz / dist;

        // update acceleration of each planet
        earth.acceleration.x = fx / earth.mass;
        earth.acceleration.y = fy / earth.mass;
        earth.acceleration.z = fz / earth.mass;

        moon.acceleration.x = -fx / moon.mass;
        moon.acceleration.y = -fy / moon.mass;
        moon.acceleration.z = -fz / moon.mass;

        // update velocity of each planet
        earth.velocity.x += earth.acceleration.x * TIMESTEP;
        earth.velocity.y += earth.acceleration.y * TIMESTEP;
        earth.velocity.z += earth.acceleration.z * TIMESTEP;

        moon.velocity.x += moon.acceleration.x * TIMESTEP;
        moon.velocity.y += moon.acceleration.y * TIMESTEP;
        moon.velocity.z += moon.acceleration.z * TIMESTEP;

        // update position of each planet
        earth.position.x += earth.velocity.x * TIMESTEP;
        earth.position.y += earth.velocity.y * TIMESTEP;
        earth.position.z += earth.velocity.z * TIMESTEP;

        moon.position.x += moon.velocity.x * TIMESTEP;
        moon.position.y += moon.velocity.y * TIMESTEP;
        moon.position.z += moon.velocity.z * TIMESTEP;

        // print out position of the moon on day i
        printf("Day %d: Moon position = (%.2f, %.2f, %.2f)\n", i+1, moon.position.x, moon.position.y, moon.position.z);
    }

    return 0;
}