//FormAI DATASET v1.0 Category: Physics simulation ; Style: protected
#include <stdio.h>
#include <math.h>

// Constants
#define G 9.81
#define PI 3.14159265359

// Structs
typedef struct {
    double x, y;
} Vector2;

typedef struct {
    Vector2 position, velocity, acceleration;
    double mass;
} PhysicsObject;

// Function prototypes
void updateObject(PhysicsObject* object, double deltaTime);
Vector2 calculateGravitationalForce(PhysicsObject object1, PhysicsObject object2);

// Main function
int main() {
    // Create two physics objects
    PhysicsObject object1 = {
        {0.0, 0.0},   // position
        {0.0, 0.0},   // velocity
        {0.0, 0.0},   // acceleration
        1.0           // mass
    };
    PhysicsObject object2 = {
        {5.0, 10.0},  // position
        {0.0, 0.0},   // velocity
        {0.0, 0.0},   // acceleration
        2.0           // mass
    };

    // Simulate for 10 seconds
    double time = 0.0;
    const double endTime = 10.0;
    const double timeStep = 0.01;
    while (time < endTime) {
        // Calculate gravitational force between objects
        Vector2 force = calculateGravitationalForce(object1, object2);

        // Apply force to objects
        object1.acceleration.x = force.x / object1.mass;
        object1.acceleration.y = force.y / object1.mass;
        object2.acceleration.x = -force.x / object2.mass;
        object2.acceleration.y = -force.y / object2.mass;

        // Update objects
        updateObject(&object1, timeStep);
        updateObject(&object2, timeStep);

        // Print object positions
        printf("Object 1: (%f, %f)\n", object1.position.x, object1.position.y);
        printf("Object 2: (%f, %f)\n", object2.position.x, object2.position.y);

        // Increment time
        time += timeStep;
    }

    return 0;
}

// Updates a physics object's position and velocity based on its acceleration and the time step
void updateObject(PhysicsObject* object, double deltaTime) {
    object->velocity.x += object->acceleration.x * deltaTime;
    object->velocity.y += object->acceleration.y * deltaTime;
    object->position.x += object->velocity.x * deltaTime + 0.5 * object->acceleration.x * deltaTime * deltaTime;
    object->position.y += object->velocity.y * deltaTime + 0.5 * object->acceleration.y * deltaTime * deltaTime;
}

// Calculates the gravitational force between two physics objects
Vector2 calculateGravitationalForce(PhysicsObject object1, PhysicsObject object2) {
    // Calculate distance between objects
    double dx = object2.position.x - object1.position.x;
    double dy = object2.position.y - object1.position.y;
    double dist = sqrt(dx*dx + dy*dy);

    // Calculate force magnitude
    double forceMag = (G * object1.mass * object2.mass) / (dist*dist);

    // Calculate force direction
    double angle = atan2(dy, dx);
    Vector2 force = {forceMag * cos(angle), forceMag * sin(angle)};
    return force;
}