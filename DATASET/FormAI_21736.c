//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: artistic
#include <stdio.h>
#include <math.h>

#define GRAVITY_CONSTANT 6.6743e-11   // Gravitational constant

// Vector structure
typedef struct {
    double x;
    double y;
} Vector;

// Object structure
typedef struct {
    double mass;
    Vector position;
    Vector velocity;
} Object;

// Calculate the distance between two objects
double distance(Object obj1, Object obj2) {
    double dx = obj2.position.x - obj1.position.x;
    double dy = obj2.position.y - obj1.position.y;
    return sqrt(dx*dx + dy*dy);
}

// Calculate the gravitational force between two objects
Vector gravitationalForce(Object obj1, Object obj2) {
    double d = distance(obj1, obj2);
    double f = GRAVITY_CONSTANT * obj1.mass * obj2.mass / (d*d);
    Vector direction = {obj2.position.x - obj1.position.x, obj2.position.y - obj1.position.y};
    double scale = f / d;
    return (Vector) {scale * direction.x, scale * direction.y};
}

// Update the velocity and position of an object
void update(Object *obj, Vector force, double timeStep) {
    Vector acceleration = {force.x / obj->mass, force.y / obj->mass};
    obj->velocity.x += acceleration.x * timeStep;
    obj->velocity.y += acceleration.y * timeStep;
    obj->position.x += obj->velocity.x * timeStep;
    obj->position.y += obj->velocity.y * timeStep;
}

// Main function
int main() {
    Object objects[2];  // Array of two objects

    // Initialize the objects
    objects[0].mass = 5.97e24;  // Mass of Earth
    objects[0].position.x = 0;
    objects[0].position.y = 0;
    objects[0].velocity.x = 0;
    objects[0].velocity.y = 0;

    objects[1].mass = 7.34e22;  // Mass of Moon
    objects[1].position.x = 384400000;  // Distance from Earth
    objects[1].position.y = 0;
    objects[1].velocity.x = 0;
    objects[1].velocity.y = 1022;  // Velocity of Moon

    double timeStep = 1000;  // Time step in seconds
    int steps = 1000;  // Number of simulation steps

    // Run simulation
    for (int i = 0; i < steps; i++) {
        Vector force = gravitationalForce(objects[0], objects[1]);
        update(&objects[0], force, timeStep);
        update(&objects[1], (Vector) {-force.x, -force.y}, timeStep);
    }

    // Print final positions
    printf("Earth: (%.2f, %.2f)\n", objects[0].position.x, objects[0].position.y);
    printf("Moon: (%.2f, %.2f)\n", objects[1].position.x, objects[1].position.y);

    return 0;
}