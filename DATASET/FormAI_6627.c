//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359
#define G 6.67430 * pow(10, -11)

struct Vector {
    double x;
    double y;
    double z;
};

struct Body {
    char name[50];
    double mass;
    struct Vector position;
    struct Vector velocity;
};

struct Vector calculateForce(struct Body b1, struct Body b2) {
    struct Vector distance;
    distance.x = b1.position.x - b2.position.x;
    distance.y = b1.position.y - b2.position.y;
    distance.z = b1.position.z - b2.position.z;
    double normDistance = sqrt(pow(distance.x, 2) + pow(distance.y, 2) + pow(distance.z, 2));
    double forceMagnitude = G * b1.mass * b2.mass / pow(normDistance, 2);
    struct Vector force;
    force.x = forceMagnitude * distance.x / normDistance;
    force.y = forceMagnitude * distance.y / normDistance;
    force.z = forceMagnitude * distance.z / normDistance;
    return force;
}

void updateVelocity(struct Body *b, struct Vector force, double timeStep) {
    b->velocity.x += force.x * timeStep / b->mass;
    b->velocity.y += force.y * timeStep / b->mass;
    b->velocity.z += force.z * timeStep / b->mass;
}

void updatePosition(struct Body *b, double timeStep) {
    b->position.x += b->velocity.x * timeStep;
    b->position.y += b->velocity.y * timeStep;
    b->position.z += b->velocity.z * timeStep;
}

int main() {
    // Create the bodies
    struct Body sun = {"Sun", 1.989 * pow(10, 30), {0, 0, 0}, {0, 0, 0}};
    struct Body earth = {"Earth", 5.972 * pow(10, 24), {147 * pow(10, 9), 0, 0}, {0, 30300, 0}};
    struct Body mars = {"Mars", 6.39 * pow(10, 23), {-206 * pow(10, 9), 0, 0}, {0, -26500, 0}};

    // Set up the simulation
    double timeStep = 1000; // 1000 seconds (timeStep is the time interval between each calculation)
    double duration = 31536000 * 5; // 5 years (duration is the total time of the simulation)
    int steps = (int)(duration / timeStep); // Number of steps required
    int step;

    // Run the simulation
    for (step = 0; step < steps; step++) {
        // Calculate the forces
        struct Vector force1 = calculateForce(sun, earth);
        struct Vector force2 = calculateForce(sun, mars);

        // Update the velocities
        updateVelocity(&earth, force1, timeStep);
        updateVelocity(&mars, force2, timeStep);

        // Update the positions
        updatePosition(&earth, timeStep);
        updatePosition(&mars, timeStep);

        // Output the positions
        printf("Step %d - Earth position: (%e, %e, %e)\n", step+1, earth.position.x, earth.position.y, earth.position.z);
        printf("Step %d - Mars position: (%e, %e, %e)\n", step+1, mars.position.x, mars.position.y, mars.position.z);
    }

    return 0;
}