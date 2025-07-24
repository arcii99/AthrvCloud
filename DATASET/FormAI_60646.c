//FormAI DATASET v1.0 Category: Physics simulation ; Style: minimalist
#include <stdio.h>
#include <math.h>

// Constant definitions
#define G 6.674e-11 // Gravitational constant

// Structure definition for Cartesian coordinates
typedef struct CartesianCoordinates{
    double x;
    double y;
} CartesianCoordinates;

// Structure definition for object
typedef struct Object{
    double mass;
    CartesianCoordinates position;
    CartesianCoordinates velocity;
} Object;

// Function to calculate distance between two points
double distance(CartesianCoordinates point1, CartesianCoordinates point2){
    double dx = point1.x - point2.x;
    double dy = point1.y - point2.y;
    return sqrt(dx*dx + dy*dy);
}

// Function to calculate gravitational force between two objects
CartesianCoordinates gravitationalForce(Object obj1, Object obj2){
    double r = distance(obj1.position, obj2.position);
    double f = (G * obj1.mass * obj2.mass) / (r*r);
    CartesianCoordinates force;

    force.x = f * (obj2.position.x - obj1.position.x) / r;
    force.y = f * (obj2.position.y - obj1.position.y) / r;

    return force;
}

// Function to update object's velocity and position
void updateObject(Object *obj, CartesianCoordinates force, double timeStep){
    double a_x = force.x / obj->mass;
    double a_y = force.y / obj->mass;

    // Update velocity
    obj->velocity.x += a_x * timeStep;
    obj->velocity.y += a_y * timeStep;

    // Update position
    obj->position.x += obj->velocity.x * timeStep;
    obj->position.y += obj->velocity.y * timeStep;
}

int main(){
    // Create two objects
    Object obj1 = {
        .mass = 10,
        .position = {0, 0},
        .velocity = {0, 0}
    };

    Object obj2 = {
        .mass = 5,
        .position = {5, 0},
        .velocity = {0, 10}
    };

    double timeStep = 0.1;
    int numSteps = 100;

    // Simulate motion
    for(int i=0; i<numSteps; i++){
        // Calculate gravitational force on each object
        CartesianCoordinates force1 = gravitationalForce(obj1, obj2);
        CartesianCoordinates force2 = gravitationalForce(obj2, obj1);

        // Update each object's velocity and position
        updateObject(&obj1, force1, timeStep);
        updateObject(&obj2, force2, timeStep);

        // Print current positions
        printf("Object 1 position: (%lf, %lf)\n", obj1.position.x, obj1.position.y);
        printf("Object 2 position: (%lf, %lf)\n", obj2.position.x, obj2.position.y);
    }

    return 0;
}